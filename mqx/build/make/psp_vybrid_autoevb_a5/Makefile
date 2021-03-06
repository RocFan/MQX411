#----------------------------------------------------------
# setup variables
#----------------------------------------------------------
MQX_ROOTDIR             = $(abspath ../../../..)
TYPE                    = library
NAME                    = psp
BOARD                   = vybrid_autoevb_a5
LIBRARY_ROOTDIR         = $(MQX_ROOTDIR)/lib/$(BOARD).$(TOOL)
LIBRARY_DIR             = $(LIBRARY_ROOTDIR)/$(CONFIG)/psp
LIBRARY_FILE            = $(LIBRARY_DIR)/psp.$(LIBRARY_EXT)
POSTBUILD_CMD           = $(if $(findstring $(HOSTENV),WINDOWS),$(MQX_ROOTDIR)/mqx/build/bat/psp_vybrid_autoevb_a5.bat $(MQX_ROOTDIR) $(LIBRARY_DIR) $(TOOL),$(MQX_ROOTDIR)/mqx/build/bat/psp_vybrid_autoevb_a5.sh $(MQX_ROOTDIR) $(LIBRARY_DIR) $(TOOL))


#-----------------------------------------------------------
# load tool settings
#-----------------------------------------------------------
-include tools/$(TOOL).mak


#-----------------------------------------------------------
# search paths
#-----------------------------------------------------------
ifeq ($(CONFIG),debug)
INCLUDE += $(MQX_ROOTDIR)/mqx/source/psp/cortex_a/cpu
INCLUDE += $(MQX_ROOTDIR)/mqx/source/psp/cortex_a
INCLUDE += $(MQX_ROOTDIR)/config/vybrid_autoevb_a5
INCLUDE += $(MQX_ROOTDIR)/config/common
INCLUDE += $(MQX_ROOTDIR)/mqx/source/include
INCLUDE += $(MQX_ROOTDIR)/mqx/source/tad
INCLUDE += $(MQX_ROOTDIR)/mqx/source/io/asrc
INCLUDE += $(MQX_ROOTDIR)/mqx/source/io/cm
INCLUDE += $(MQX_ROOTDIR)/mqx/source/io/cm/vybrid
INCLUDE += $(MQX_ROOTDIR)/mqx/source/io/core_mutex
INCLUDE += $(MQX_ROOTDIR)/mqx/source/io/dcu4
INCLUDE += $(MQX_ROOTDIR)/mqx/source/io/dma
INCLUDE += $(MQX_ROOTDIR)/mqx/source/io/enet/macnet
INCLUDE += $(MQX_ROOTDIR)/mqx/source/io/enet/phy
INCLUDE += $(MQX_ROOTDIR)/mqx/source/io/enet
INCLUDE += $(MQX_ROOTDIR)/mqx/source/io/esai
INCLUDE += $(MQX_ROOTDIR)/mqx/source/io/esai/esai_fifo
INCLUDE += $(MQX_ROOTDIR)/mqx/source/io/esai/esai_vport
INCLUDE += $(MQX_ROOTDIR)/mqx/source/io/esdhc
INCLUDE += $(MQX_ROOTDIR)/mqx/source/io/fbdev
INCLUDE += $(MQX_ROOTDIR)/mqx/source/io/flashx/freescale
INCLUDE += $(MQX_ROOTDIR)/mqx/source/io/flashx
INCLUDE += $(MQX_ROOTDIR)/mqx/source/io/ftm
INCLUDE += $(MQX_ROOTDIR)/mqx/source/io/ftm/quaddec
INCLUDE += $(MQX_ROOTDIR)/mqx/source/io/hwtimer
INCLUDE += $(MQX_ROOTDIR)/mqx/source/io/i2c
INCLUDE += $(MQX_ROOTDIR)/mqx/source/io/i2c/polled
INCLUDE += $(MQX_ROOTDIR)/mqx/source/io/i2c/int
INCLUDE += $(MQX_ROOTDIR)/mqx/source/bsp/vybrid_autoevb_a5
INCLUDE += $(MQX_ROOTDIR)/mqx/source/io/io_expander
INCLUDE += $(MQX_ROOTDIR)/mqx/source/io/io_mem
INCLUDE += $(MQX_ROOTDIR)/mqx/source/io/io_null
INCLUDE += $(MQX_ROOTDIR)/mqx/source/io/pipe
INCLUDE += $(MQX_ROOTDIR)/mqx/source/io/lpm/vybrid
INCLUDE += $(MQX_ROOTDIR)/mqx/source/io/lpm
INCLUDE += $(MQX_ROOTDIR)/mqx/source/io/lwadc
INCLUDE += $(MQX_ROOTDIR)/mqx/source/io/lwgpio
INCLUDE += $(MQX_ROOTDIR)/mqx/source/io/pcb/shmem
INCLUDE += $(MQX_ROOTDIR)/mqx/source/io/pcb
INCLUDE += $(MQX_ROOTDIR)/mqx/source/io/pcb/mqxa
INCLUDE += $(MQX_ROOTDIR)/mqx/source/io/qspi
INCLUDE += $(MQX_ROOTDIR)/mqx/source/io/rtc
INCLUDE += $(MQX_ROOTDIR)/mqx/source/io/sai
INCLUDE += $(MQX_ROOTDIR)/mqx/source/io/sai/int
INCLUDE += $(MQX_ROOTDIR)/mqx/source/io/sdcard/sdcard_esdhc
INCLUDE += $(MQX_ROOTDIR)/mqx/source/io/sdcard
INCLUDE += $(MQX_ROOTDIR)/mqx/source/io/serial
INCLUDE += $(MQX_ROOTDIR)/mqx/source/io/spi
INCLUDE += $(MQX_ROOTDIR)/mqx/source/io/tfs
INCLUDE += $(MQX_ROOTDIR)/mqx/source/io/usb
endif
ifeq ($(CONFIG),release)
INCLUDE += $(MQX_ROOTDIR)/mqx/source/psp/cortex_a/cpu
INCLUDE += $(MQX_ROOTDIR)/mqx/source/psp/cortex_a
INCLUDE += $(MQX_ROOTDIR)/config/vybrid_autoevb_a5
INCLUDE += $(MQX_ROOTDIR)/config/common
INCLUDE += $(MQX_ROOTDIR)/mqx/source/include
INCLUDE += $(MQX_ROOTDIR)/mqx/source/tad
INCLUDE += $(MQX_ROOTDIR)/mqx/source/io/asrc
INCLUDE += $(MQX_ROOTDIR)/mqx/source/io/cm
INCLUDE += $(MQX_ROOTDIR)/mqx/source/io/cm/vybrid
INCLUDE += $(MQX_ROOTDIR)/mqx/source/io/core_mutex
INCLUDE += $(MQX_ROOTDIR)/mqx/source/io/dcu4
INCLUDE += $(MQX_ROOTDIR)/mqx/source/io/dma
INCLUDE += $(MQX_ROOTDIR)/mqx/source/io/enet/macnet
INCLUDE += $(MQX_ROOTDIR)/mqx/source/io/enet/phy
INCLUDE += $(MQX_ROOTDIR)/mqx/source/io/enet
INCLUDE += $(MQX_ROOTDIR)/mqx/source/io/esai
INCLUDE += $(MQX_ROOTDIR)/mqx/source/io/esai/esai_fifo
INCLUDE += $(MQX_ROOTDIR)/mqx/source/io/esai/esai_vport
INCLUDE += $(MQX_ROOTDIR)/mqx/source/io/esdhc
INCLUDE += $(MQX_ROOTDIR)/mqx/source/io/fbdev
INCLUDE += $(MQX_ROOTDIR)/mqx/source/io/flashx/freescale
INCLUDE += $(MQX_ROOTDIR)/mqx/source/io/flashx
INCLUDE += $(MQX_ROOTDIR)/mqx/source/io/ftm
INCLUDE += $(MQX_ROOTDIR)/mqx/source/io/ftm/quaddec
INCLUDE += $(MQX_ROOTDIR)/mqx/source/io/hwtimer
INCLUDE += $(MQX_ROOTDIR)/mqx/source/io/i2c
INCLUDE += $(MQX_ROOTDIR)/mqx/source/io/i2c/polled
INCLUDE += $(MQX_ROOTDIR)/mqx/source/io/i2c/int
INCLUDE += $(MQX_ROOTDIR)/mqx/source/bsp/vybrid_autoevb_a5
INCLUDE += $(MQX_ROOTDIR)/mqx/source/io/io_expander
INCLUDE += $(MQX_ROOTDIR)/mqx/source/io/io_mem
INCLUDE += $(MQX_ROOTDIR)/mqx/source/io/io_null
INCLUDE += $(MQX_ROOTDIR)/mqx/source/io/pipe
INCLUDE += $(MQX_ROOTDIR)/mqx/source/io/lpm/vybrid
INCLUDE += $(MQX_ROOTDIR)/mqx/source/io/lpm
INCLUDE += $(MQX_ROOTDIR)/mqx/source/io/lwadc
INCLUDE += $(MQX_ROOTDIR)/mqx/source/io/lwgpio
INCLUDE += $(MQX_ROOTDIR)/mqx/source/io/pcb/shmem
INCLUDE += $(MQX_ROOTDIR)/mqx/source/io/pcb
INCLUDE += $(MQX_ROOTDIR)/mqx/source/io/pcb/mqxa
INCLUDE += $(MQX_ROOTDIR)/mqx/source/io/qspi
INCLUDE += $(MQX_ROOTDIR)/mqx/source/io/rtc
INCLUDE += $(MQX_ROOTDIR)/mqx/source/io/sai
INCLUDE += $(MQX_ROOTDIR)/mqx/source/io/sai/int
INCLUDE += $(MQX_ROOTDIR)/mqx/source/io/sdcard/sdcard_esdhc
INCLUDE += $(MQX_ROOTDIR)/mqx/source/io/sdcard
INCLUDE += $(MQX_ROOTDIR)/mqx/source/io/serial
INCLUDE += $(MQX_ROOTDIR)/mqx/source/io/spi
INCLUDE += $(MQX_ROOTDIR)/mqx/source/io/tfs
INCLUDE += $(MQX_ROOTDIR)/mqx/source/io/usb
endif



#-----------------------------------------------------------
# 'architecture' sources
#-----------------------------------------------------------
SOURCES += $(MQX_ROOTDIR)/mqx/source/psp/cortex_a/core/A5/dispatch_gic.S
SOURCES += $(MQX_ROOTDIR)/mqx/source/psp/cortex_a/core/A5/dispatch_sch.S
SOURCES += $(MQX_ROOTDIR)/mqx/source/psp/cortex_a/core/A5/boot.S
SOURCES += $(MQX_ROOTDIR)/mqx/source/psp/cortex_a/cache_a5.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/psp/cortex_a/cache_l2c310.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/psp/cortex_a/cache.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/psp/cortex_a/cortexa5.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/psp/cortex_a/gic.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/psp/cortex_a/irouter_vybrid.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/psp/cortex_a/int_gkis.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/psp/cortex_a/int_inst.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/psp/cortex_a/int_kisr.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/psp/cortex_a/int_pc.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/psp/cortex_a/int_pvta.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/psp/cortex_a/int_unx.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/psp/cortex_a/int_vtab.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/psp/cortex_a/int_xcpt.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/psp/cortex_a/ipsum.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/psp/cortex_a/mem_copy.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/psp/cortex_a/mem_zero.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/psp/cortex_a/mmu_cortexa5.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/psp/cortex_a/psp_dati.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/psp/cortex_a/psp_gelms.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/psp/cortex_a/psp_hoti.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/psp/cortex_a/psp_iinit.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/psp/cortex_a/psp_mat1.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/psp/cortex_a/psp_mat2.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/psp/cortex_a/psp_mat3.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/psp/cortex_a/psp_miti.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/psp/cortex_a/psp_msti.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/psp/cortex_a/psp_mstiq.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/psp/cortex_a/psp_nsti.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/psp/cortex_a/psp_psti.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/psp/cortex_a/psp_seti.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/psp/cortex_a/psp_supp.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/psp/cortex_a/psp_tiad.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/psp/cortex_a/psp_tida.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/psp/cortex_a/psp_tihr.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/psp/cortex_a/psp_timn.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/psp/cortex_a/psp_tims.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/psp/cortex_a/psp_tinm.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/psp/cortex_a/psp_tins.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/psp/cortex_a/psp_tiol.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/psp/cortex_a/psp_tipr.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/psp/cortex_a/psp_tips.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/psp/cortex_a/psp_tise.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/psp/cortex_a/psp_tisu.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/psp/cortex_a/psp_tius.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/psp/cortex_a/psp_tkti.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/psp/cortex_a/psp_usti.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/psp/cortex_a/sc_irdyq.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/psp/cortex_a/stack_bu.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/psp/cortex_a/stack_de.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/psp/cortex_a/stack_st.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/psp/cortex_a/core/A5/support.S

#-----------------------------------------------------------
# 'event' sources
#-----------------------------------------------------------
SOURCES += $(MQX_ROOTDIR)/mqx/source/kernel/event.c

#-----------------------------------------------------------
# 'fio' sources
#-----------------------------------------------------------
SOURCES += $(MQX_ROOTDIR)/mqx/source/fio/io_clre.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/fio/io_dopr.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/fio/io_fclos.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/fio/io_feof.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/fio/io_ferr.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/fio/io_fflsh.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/fio/io_fgetc.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/fio/io_fgetl.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/fio/io_fgets.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/fio/io_fopen.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/fio/io_fp.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/fio/io_fprt.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/fio/io_fputc.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/fio/io_fputs.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/fio/io_fscan.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/fio/io_fseek.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/fio/io_fstat.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/fio/io_ftell.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/fio/io_fung.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/fio/io_ioctl.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/fio/io_misc.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/fio/io_pntf.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/fio/io_read.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/fio/io_scanf.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/fio/io_scanl.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/fio/io_spr.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/fio/io_sscan.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/fio/io_util.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/fio/io_vpr.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/fio/io_write.c

#-----------------------------------------------------------
# 'io' sources
#-----------------------------------------------------------
SOURCES += $(MQX_ROOTDIR)/mqx/source/io/io_init.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/io/io_inst.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/io/io_instx.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/io/io_ghand.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/io/io_shand.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/io/io_uinst.c

#-----------------------------------------------------------
# 'ipc' sources
#-----------------------------------------------------------
SOURCES += $(MQX_ROOTDIR)/mqx/source/kernel/ipc.c

#-----------------------------------------------------------
# 'kernel' sources
#-----------------------------------------------------------
SOURCES += $(MQX_ROOTDIR)/mqx/source/kernel/idletask.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/kernel/inittask.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/kernel/int.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/kernel/lwsem.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/kernel/mem.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/kernel/mqx.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/kernel/sched.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/kernel/task.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/kernel/time.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/kernel/taskq.c

#-----------------------------------------------------------
# 'klog' sources
#-----------------------------------------------------------
SOURCES += $(MQX_ROOTDIR)/mqx/source/kernel/klog.c

#-----------------------------------------------------------
# 'log' sources
#-----------------------------------------------------------
SOURCES += $(MQX_ROOTDIR)/mqx/source/kernel/log.c

#-----------------------------------------------------------
# 'lwevent' sources
#-----------------------------------------------------------
SOURCES += $(MQX_ROOTDIR)/mqx/source/kernel/lwevent.c

#-----------------------------------------------------------
# 'lwlog' sources
#-----------------------------------------------------------
SOURCES += $(MQX_ROOTDIR)/mqx/source/kernel/lwlog.c

#-----------------------------------------------------------
# 'lwmem' sources
#-----------------------------------------------------------
SOURCES += $(MQX_ROOTDIR)/mqx/source/kernel/lwmem.c

#-----------------------------------------------------------
# 'lwmsg' sources
#-----------------------------------------------------------
SOURCES += $(MQX_ROOTDIR)/mqx/source/kernel/lwmsgq.c

#-----------------------------------------------------------
# 'lwtimer' sources
#-----------------------------------------------------------
SOURCES += $(MQX_ROOTDIR)/mqx/source/kernel/lwtimer.c

#-----------------------------------------------------------
# 'message' sources
#-----------------------------------------------------------
SOURCES += $(MQX_ROOTDIR)/mqx/source/kernel/msg.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/kernel/msgq.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/kernel/msgpool.c

#-----------------------------------------------------------
# 'mutex' sources
#-----------------------------------------------------------
SOURCES += $(MQX_ROOTDIR)/mqx/source/kernel/mutex.c

#-----------------------------------------------------------
# 'name' sources
#-----------------------------------------------------------
SOURCES += $(MQX_ROOTDIR)/mqx/source/kernel/name.c

#-----------------------------------------------------------
# 'part' sources
#-----------------------------------------------------------
SOURCES += $(MQX_ROOTDIR)/mqx/source/kernel/partition.c

#-----------------------------------------------------------
# 'queue' sources
#-----------------------------------------------------------
SOURCES += $(MQX_ROOTDIR)/mqx/source/kernel/queue.c

#-----------------------------------------------------------
# 'sem' sources
#-----------------------------------------------------------
SOURCES += $(MQX_ROOTDIR)/mqx/source/kernel/sem.c

#-----------------------------------------------------------
# 'string' sources
#-----------------------------------------------------------
SOURCES += $(MQX_ROOTDIR)/mqx/source/string/strnlen.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/string/str_utos.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/string/unicode.c

#-----------------------------------------------------------
# 'tad' sources
#-----------------------------------------------------------
SOURCES += $(MQX_ROOTDIR)/mqx/source/tad/tad.c

#-----------------------------------------------------------
# 'timer' sources
#-----------------------------------------------------------
SOURCES += $(MQX_ROOTDIR)/mqx/source/kernel/timer.c

#-----------------------------------------------------------
# 'watchdog' sources
#-----------------------------------------------------------
SOURCES += $(MQX_ROOTDIR)/mqx/source/kernel/watchdog.c


#----------------------------------------------------------
# load global settings
#----------------------------------------------------------
include $(MQX_ROOTDIR)/build/common/make/global.mak
-include $(MQX_ROOTDIR)/build/$(BOARD)/make/tools/$(TOOL).mak
include $(MQX_ROOTDIR)/build/common/make/verify.mak
include $(MQX_ROOTDIR)/build/common/make/lib-process.mak

