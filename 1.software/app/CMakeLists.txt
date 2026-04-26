# Copyright (c) 2021 HPMicro
# SPDX-License-Identifier: BSD-3-Clause

cmake_minimum_required(VERSION 3.13)

# set(CUSTOM_GCC_LINKER_FILE ${CMAKE_CURRENT_SOURCE_DIR}/linkers/gcc/flash_xip.ld)
#set(CUSTOM_SES_LINKER_FILE ${CMAKE_CURRENT_SOURCE_DIR}/linkers/segger/flash_xip.icf)
# set(CUSTOM_IAR_LINKER_FILE ${CMAKE_CURRENT_SOURCE_DIR}/linkers/iar/flash_xip.icf)

set(CONFIG_HPM_SPI 1)
set(CONFIG_DMA_MGR 1)
set(CONFIG_CHERRYRB 1)

set(CONFIG_ECLIPSE_THREADX 1)
#set(CONFIG_ECLIPSE_THREADX_TIMER_RESOURCE_MTIMER 1) to use mchtmr as system's tick source
set(CONFIG_ECLIPSE_THREADX_TIMER_RESOURCE_MTIMER 1)

set(CONFIG_USB_DEVICE 1)

find_package(hpm-sdk REQUIRED HINTS $ENV{HPM_SDK_BASE})

project(hpm_awtrix)

sdk_app_inc(.)
sdk_app_src(main.c)
sdk_app_src(led.c)
sdk_app_src(shell.c)
sdk_app_src(winusb20.c)

add_subdirectory(3rd-party)

sdk_compile_definitions(-DBOARD_SHOW_BANNER=0)

generate_ide_projects()
