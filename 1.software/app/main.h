#ifndef MAIN_H__
#define MAIN_H__

#include "tx_api.h"

#ifdef __cplusplus
extern "C" {
#endif

extern TX_QUEUE queue_led;

int thread_led_init(void);



#ifdef __cplusplus
}
#endif

#endif