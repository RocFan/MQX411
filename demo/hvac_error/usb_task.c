/*HEADER**********************************************************************
*
* Copyright 2008 Freescale Semiconductor, Inc.
* Copyright 2004-2008 Embedded Access Inc.
*
* This software is owned or controlled by Freescale Semiconductor.
* Use of this software is governed by the Freescale MQX RTOS License
* distributed with this Material.
* See the MQX_RTOS_LICENSE file distributed for more details.
*
* Brief License Summary:
* This software is provided in source form for you to use free of charge,
* but it is not open source software. You are allowed to use this software
* but you cannot redistribute it or derivative works of it in source form.
* The software may be used only in connection with a product containing
* a Freescale microprocessor, microcontroller, or digital signal processor.
* See license agreement file for full license terms including other
* restrictions.
*****************************************************************************
*
* Comments:
*
*   This file is the main file for filesystem demo. Note that this example
*   is a multi tasking example and needs an operating system to run. This 
*   means that customers who are not using MQX should change the operating system
*   dependent code. An attempt has been made to comment out the code
*   however, a programmer must review all lines of code to ensure that
*   it correctly compiles with their libraries of operating system and
*   targetcompiler. This program has been compiled and tested for ARC AA3
*   processor with MQX real time operating system.
*
*
*END************************************************************************/

#include "hvac.h"

#if DEMOCFG_ENABLE_USB_FILESYSTEM

#include <string.h>
#include <lwmsgq.h>

#include <hostapi.h>
#include <mqx_host.h>
#include <host_dev_list.h>
#include <usb_host_msd_bo.h>
#include <usb_host_hub_sm.h>


#include "usb_task.h"
#include "usb_file.h"

#define USB_EVENT_ATTACH    (1)
#define USB_EVENT_DETACH    (2)
#define USB_EVENT_INTF      (3)

typedef struct {
    CLASS_CALL_STRUCT_PTR ccs;     /* class call struct of MSD instance */
    uint8_t                body;    /* message body one of USB_EVENT_xxx as defined above */
} usb_msg_t;

LWSEM_STRUCT   USB_Stick;

/* The granularity of message queue is one message. Its size is the multiplier of _mqx_max_type. Get that multiplier */
#define USB_TASKQ_GRANM ((sizeof(usb_msg_t) - 1) / sizeof(_mqx_max_type) + 1)
_mqx_max_type  usb_taskq[20 * USB_TASKQ_GRANM * sizeof(_mqx_max_type)]; /* prepare message queue for 20 events */

/* Table of driver capabilities this application want to use */
static const USB_HOST_DRIVER_INFO ClassDriverInfoTable[] =
{  
   /* Vendor ID Product ID Class Sub-Class Protocol Reserved Application call back */
   /* Floppy drive */
   {{0x00,0x00}, {0x00,0x00}, USB_CLASS_MASS_STORAGE, USB_SUBCLASS_MASS_UFI, USB_PROTOCOL_MASS_BULK, 0, usb_host_mass_device_event },

   /* USB 2.0 hard drive */
   {{0x00,0x00}, {0x00,0x00}, USB_CLASS_MASS_STORAGE, USB_SUBCLASS_MASS_SCSI, USB_PROTOCOL_MASS_BULK, 0, usb_host_mass_device_event},

   /* USB hub */
   {{0x00,0x00}, {0x00,0x00}, USB_CLASS_HUB, USB_SUBCLASS_HUB_NONE, USB_PROTOCOL_HUB_ALL, 0, usb_host_hub_device_event},

   /* End of list */
   {{0x00,0x00}, {0x00,0x00}, 0,0,0,0, NULL}
};

/*FUNCTION*----------------------------------------------------------------
*
* Function Name  : usb_host_mass_device_event
* Returned Value : None
* Comments       :
*     called when a mass storage device has been attached, detached, etc.
*END*--------------------------------------------------------------------*/

void usb_host_mass_device_event
   (
      /* [IN] pointer to device instance */
      _usb_device_instance_handle      dev_handle,

      /* [IN] pointer to interface descriptor */
      _usb_interface_descriptor_handle intf_handle,

      /* [IN] code number for event causing callback */
      uint32_t           event_code
   )
{
   DEVICE_STRUCT_PTR          device;
   usb_msg_t                  msg;

   switch (event_code) {
      case USB_CONFIG_EVENT:
         /* Drop through into attach, same processing */
      case USB_ATTACH_EVENT:
         /* Here, the device starts its lifetime */
         device = (DEVICE_STRUCT_PTR) _mem_alloc_zero(sizeof(DEVICE_STRUCT));
         if (device == NULL)
            break;

         if (USB_OK != _usb_hostdev_select_interface(dev_handle, intf_handle, &device->ccs))
            break;
         msg.ccs = &device->ccs;
         msg.body = USB_EVENT_ATTACH;
         if (LWMSGQ_FULL == _lwmsgq_send(usb_taskq, (uint32_t *) &msg, 0)) {
            printf("Could not inform USB task about device attached\n");
         }
         break;

      case USB_INTF_EVENT:
         if (USB_OK != usb_class_mass_get_app(dev_handle, intf_handle, (CLASS_CALL_STRUCT_PTR *) &device))
            break;
         msg.ccs = &device->ccs;
         msg.body = USB_EVENT_INTF;
         if (LWMSGQ_FULL == _lwmsgq_send(usb_taskq, (uint32_t *) &msg, 0)) {
            printf("Could not inform USB task about device interfaced\n");
         }
         break;

      case USB_DETACH_EVENT:
         if (USB_OK != usb_class_mass_get_app(dev_handle, intf_handle, (CLASS_CALL_STRUCT_PTR *) &device))
            break;
         msg.ccs = &device->ccs;
         msg.body = USB_EVENT_DETACH;
         if (LWMSGQ_FULL == _lwmsgq_send(usb_taskq, (uint32_t *) &msg, 0)) {
            printf("Could not inform USB task about device detached\n");
         }
         _mem_free(device);
         break;

      default:
         break;
   } 
} 

/*FUNCTION*----------------------------------------------------------------
*
* Function Name  : USB_task
* Returned Value : None
* Comments       :
*     First function called. This rouine just transfers control to host main
*END*--------------------------------------------------------------------*/

void USB_task(uint32_t param)
{ 
    _usb_host_handle     host_handle;
    USB_STATUS           error;
    void                *usb_fs_handle = NULL;
    usb_msg_t            msg;
    /* Store mounting point used. A: is the first one, bit #0 assigned, Z: is the last one, bit #25 assigned */
    uint32_t              fs_mountp = 0;
   
#if DEMOCFG_USE_POOLS && defined(DEMOCFG_MFS_POOL_ADDR) && defined(DEMOCFG_MFS_POOL_SIZE)
    _MFS_pool_id = _mem_create_pool((void *)DEMOCFG_MFS_POOL_ADDR, DEMOCFG_MFS_POOL_SIZE);
#endif

    /* This event will inform other tasks that the filesystem on USB was successfully installed */
    _lwsem_create(&USB_Stick, 0);
    
    if (MQX_OK != _lwmsgq_init(usb_taskq, 20, USB_TASKQ_GRANM)) {
        // lwmsgq_init failed
        _task_block();
    }

    USB_lock();
    _int_install_unexpected_isr();
   if (MQX_OK != _usb_host_driver_install(USBCFG_DEFAULT_HOST_CONTROLLER)) {
      printf("\n Driver installation failed");
      _task_block();
   }

    error = _usb_host_init(USBCFG_DEFAULT_HOST_CONTROLLER, &host_handle);
    if (error == USB_OK) {
        error = _usb_host_driver_info_register(host_handle, (void *)ClassDriverInfoTable);
        if (error == USB_OK) {
            error = _usb_host_register_service(host_handle, USB_SERVICE_HOST_RESUME,NULL);
        }
    }

    USB_unlock();

    if (error != USB_OK) {
        _task_block();
    }
      
    for (;;) {
        /* Wait for event sent as a message */
        _lwmsgq_receive(&usb_taskq, (_mqx_max_type *) &msg, LWMSGQ_RECEIVE_BLOCK_ON_EMPTY, 0, 0);
         
        //if (device.STATE == USB_DEVICE_ATTACHED) {
        if (msg.body == USB_EVENT_ATTACH) {
          /* This event is not so important, because it does not inform about successfull USB stack enumeration */
        } else if (msg.body == USB_EVENT_INTF && fs_mountp != 0x3FFC)  { /* if mountpoints c: to z: are already used */

            // Install the file system, use device->ccs as a handle
            usb_fs_handle = usb_filesystem_install( (void *) msg.ccs, "USB:", "PM_C1:", "c:");
                  
            if (usb_fs_handle) {
                DEVICE_STRUCT_PTR dsp = (DEVICE_STRUCT_PTR) msg.ccs;
                dsp->mount = 'c';

                // Mark file system as mounted
                fs_mountp |= 1 << (dsp->mount - 'a');
                // Unlock the USB_Stick = signal to the application as available
                _lwsem_post(&USB_Stick);
            }
        } else if (msg.body == USB_EVENT_DETACH) {
            DEVICE_STRUCT_PTR dsp = (DEVICE_STRUCT_PTR) msg.ccs;

            if (dsp->mount >= 'a' && dsp->mount <= 'z') {
                // Lock the USB_Stick = mark as unavailable
                _lwsem_wait(&USB_Stick);

                // Remove the file system 
                usb_filesystem_uninstall(usb_fs_handle);
                // Mark file system as unmounted
                fs_mountp &= ~(1 << (dsp->mount - 'a'));
            }

            /* Here, the device finishes its lifetime */            
            _mem_free(dsp);
        }
    }
}


#endif

/* EOF */
