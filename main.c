#include "ch.h"
#include "hal.h"

static THD_WORKING_AREA(waThread1, 128);
static THD_FUNCTION(Thread1, arg) {
	(void)arg;

	chRegSetThreadName("blinker");
	while (true) {
		palClearPad(GPIOC, 13U);
		chThdSleepMilliseconds(500);
		palSetPad(GPIOC, 13U);
		chThdSleepMilliseconds(500);
	}
}

int main(void) {
	halInit();
	chSysInit();

	// palSetPadMode(GPIOC, 13, PAL_MODE_ALTERNATE(1));

	chThdCreateStatic(waThread1, sizeof(waThread1), NORMALPRIO + 1, Thread1, NULL);

	while (true) {
		chThdSleepMilliseconds(500);
	}
}
