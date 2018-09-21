#!/bin/bash

export CROSS_COMPILE=arm-xilinx-linux-gnueabi-

make distclean
make zynq_nc_config
make
