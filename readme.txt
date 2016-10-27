built against u-boot-xlnx tagged version "xilinx-v2015.2"

make zynq_rc_config

compile with

export CROSS_COMPILE=arm-xilinx-linux-gnueabi-

-----------------------------------------------------------------------------
Last build was against Xilinx commit 879358544f7aee5d94c37d2a78622a4b783b8198
on dec 19 2014

IMPORTANT NOTES:

Don't forget to set CONFIG_ENV_INTERNAL or CONFIG_ENV_EXTERNAL in zynq-common.h. This will build the correct u-boot for use on an internal or external SD card

Don't forget that if the uboot.env file exists on the boot partition, u-boot will use that for definitions of things like rdms_init and sdboot, etc. Your changes in zynq-common.h WILL not execute until you delete the uboot.env file. If you want them to be permenant, delete that file, run and stop at u-boot, add any additional variables you want, saveenv. Then use the new uboot.env



---

1/14/2015 : removed mmcinfo and loadenv (uEnv.txt) from qspiboot because the access was causing u-boot to report "Card did not respond to voltage select" and stop. At some point we should figure out why it was doing that.


env_fat.c -- added disable check of CRC on environment import based on zynq-common.h define CONFIG_ENV_DISABLE_CRC_CHECK

