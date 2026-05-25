# include <hal.h>
#include "wait.h"
#include "usb_descriptor.h"

/* disable SWD as matrix is connected to SDWIO pin */
void early_hardware_init_post(void) {
	SN_SYS0->SWDCTRL_b.SWDDIS = 1; // Disable SWD
}

/*
 * must override sleep functions without idle thread
 */
#if CH_CFG_NO_IDLE_THREAD == TRUE

#define CYCLES_PER_LOOP 9
#define LOOP_TIMES (48000000 / (CH_CFG_ST_FREQUENCY) / (CYCLES_PER_LOOP))

void chThdSleep(sysinterval_t time) {
    uint32_t loops = time * LOOP_TIMES;

    for (uint32_t i = 0; i < loops; i++) __NOP();
}

/* suspend thread used in usb_main.c */
msg_t chThdSuspendTimeoutS(thread_reference_t *trp, sysinterval_t timeout) {
    osalSysUnlock();
    wait_ms(5);
    // while (usbGetTransmitStatusI(&USBD1, KEYBOARD_IN_EPNUM));
    // #if defined(SHARED_EP_ENABLE) && !defined(KEYBOARD_SHARED_EP)
    // while (usbGetTransmitStatusI(&USBD1, SHARED_IN_EPNUM));
    // #endif
    osalSysLock();

    return MSG_OK;
}

// workaround to prevent crash on rapid/simultaneous keystrokes
// above function is seemingly not enough
msg_t chThdEnqueueTimeoutS(threads_queue_t *tqp, sysinterval_t timeout) {
    (void)tqp; (void)timeout;
    return MSG_TIMEOUT;
}

#endif /* CH_CFG_NO_IDLE_THREAD */



/* very small rand function but takes 4 bytes of RAM */
int rand(void) {
    static uint32_t seed = 134775813U;
    seed                 = seed * 1664525U + 1013904223U;
    return seed;
}
