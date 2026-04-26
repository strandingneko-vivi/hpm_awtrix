# used for cherrysh
set(CHERRYSH_PATH "${CMAKE_CURRENT_SOURCE_DIR}/CherrySH")

sdk_inc(${CHERRYSH_PATH})
sdk_src(${CHERRYSH_PATH}/chry_shell.c)
sdk_src(${CHERRYSH_PATH}/builtin/help.c)
sdk_src(${CHERRYSH_PATH}/builtin/shsize.c)
sdk_src(${CHERRYSH_PATH}/builtin/login.c)
sdk_src(${CHERRYSH_PATH}/cherryrl/chry_readline.c)

# used for HPM_WS2812
add_subdirectory(HPM_WS2812)

# used for cherryusb
set(CHERRYUSB_PATH "${CMAKE_CURRENT_SOURCE_DIR}/CherryUSB")

sdk_inc(${CHERRYUSB_PATH}/common)
sdk_inc(${CHERRYUSB_PATH}/osal)
sdk_inc(${CHERRYUSB_PATH}/core)
sdk_inc(${CHERRYUSB_PATH}/class/cdc)
sdk_inc(${CHERRYUSB_PATH}/class/hid)
sdk_inc(${CHERRYUSB_PATH}/class/midi)
sdk_inc(${CHERRYUSB_PATH}/class/msc)
sdk_inc(${CHERRYUSB_PATH}/class/audio)
sdk_inc(${CHERRYUSB_PATH}/class/video)
sdk_inc(${CHERRYUSB_PATH}/class/hub)
sdk_inc(${CHERRYUSB_PATH}/class/wireless)
sdk_inc(${CHERRYUSB_PATH}/port/ehci)
sdk_inc(${CHERRYUSB_PATH}/port/hpmicro)

sdk_src(${CHERRYUSB_PATH}/port/hpmicro/usb_glue_hpm.c)

sdk_src(${CHERRYUSB_PATH}/core/usbd_core.c)
sdk_src(${CHERRYUSB_PATH}/port/hpmicro/usb_dc_hpm.c)
sdk_src(${CHERRYUSB_PATH}/class/cdc/usbd_cdc_acm.c)