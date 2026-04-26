#include "WS2812.h"
#include "tx_api.h"
#include "main.h"

#define THREAD_LED_PRIORITY 5

static uint32_t thread_led_stack[1024] = {0};
static TX_THREAD thread_led_hdl = {0};

#define QUEUE_LED_MSG_SIZE  1
static uint32_t queue_led_msg_buf[16] = {0};
TX_QUEUE queue_led = {0};

static void thread_led_entry(ULONG param)
{
    (void)param;

    uint32_t rec_msg = 0;

    while (1)
    {
        tx_queue_receive(&queue_led, &rec_msg, TX_WAIT_FOREVER);

        //for (int j = 0; j < 256; j++)
        //{
        //    WS2812_SetPixel(0, j, j, j);
        //    WS2812_Update(true);
        //    tx_thread_sleep(100);
        //}
    }
}

int thread_led_init(void)
{
    WS2812_Init();

    if(TX_SUCCESS != tx_queue_create(&queue_led, 
                        "queue_led", 
                        QUEUE_LED_MSG_SIZE, 
                        queue_led_msg_buf, 
                        sizeof(queue_led_msg_buf)))
    {
        return -1;
    }

    if (TX_SUCCESS != tx_thread_create(
                          &thread_led_hdl,
                          "tled",
                          thread_led_entry,
                          0, /* param */
                          thread_led_stack,
                          sizeof(thread_led_stack),
                          THREAD_LED_PRIORITY,
                          THREAD_LED_PRIORITY,
                          TX_NO_TIME_SLICE,
                          TX_AUTO_START)) {
        return -1;
    }

    return 0;
}