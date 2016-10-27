#!/bin/bash

export CROSS_COMPILE=arm-xilinx-linux-gnueabi-

make distclean
make zynq_rc_config
make
