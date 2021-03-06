#!/usr/bin/env bash

echo "setting build environment for MQX411 with gcc-arm-none-eabi-4_9-2015q1"

# copy from AOSP
function cgrep()
{
	find . -name .repo -prune -o -name .git -prune -o -type f \( -name '*.c' -o -name '*.cc' -o -name '*.cpp' -o -name '*.h' -o -name '*.mk' -o -name 'Makefile' \) -print0 | xargs -0 grep --color -n "$@"
}

function elf2bin()
{
	arm-none-eabi-objcopy -O binary $@.elf $@.bin
}

function cp2med()
{
	cp $@.bin /media/MBED
}

export MQX_ROOTDIR=/home/kunyi/MQX411
export GCC_REV=4.9.3
export TOOLCHAIN_ROOTDIR=/home/kunyi/emgcc/gcc-arm-none-eabi-4_9-2015q1
export PATH=${TOOLCHAIN_ROOTDIR}/bin:$PATH

