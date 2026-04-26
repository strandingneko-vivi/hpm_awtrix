/*
 * Copyright (c) 2021 HPMicro
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "tx_api.h"
#include <stdio.h>
#include "board.h"
#include "shell.h"
#include "usb_config.h"
#include "hpm_dma_mgr.h"
#include "main.h"

extern void winusbv2_init(uint8_t busid, uint32_t reg_base);

int main(void)
{
    board_init();
    board_init_led_pins();
    board_init_usb((USB_Type *)CONFIG_HPM_USBD_BASE);

    intc_set_irq_priority(CONFIG_HPM_USBD_IRQn, 1);

    winusbv2_init(0, CONFIG_HPM_USBD_BASE);

    dma_mgr_init();

    tx_kernel_enter();

    for (;;);

    return 0;
}

void tx_application_define(void *first_unused_memory)
{
    (void)first_unused_memory;

    csh_init();
    thread_led_init();
}
