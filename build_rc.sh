#!/bin/bash

export CROSS_COMPILE=arm-xilinx-linux-gnueabi-

source ~/tools/Xilinx/SDK/2017.2/settings64.sh

make distclean
make zynq_rc_config
make
