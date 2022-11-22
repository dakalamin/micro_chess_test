#include <Arduino.h>

char a = 'a';
char b = 'b';
char* a_p = &a;
char* b_p = &b;

#ifdef DEBUG
    #include "avr8-stub.h"
    #include "app_api.h" // only needed with flash breakpoints

	#define DEBUG_INIT debug_init()
    #define BREAKPOINT breakpoint()
#else
	#define DEBUG_INIT
    #define BREAKPOINT
#endif

void setup() {
	DEBUG_INIT;
	pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
	digitalWrite(LED_BUILTIN, HIGH);
	#ifdef DEBUG
		delay(250);
	#else
		delay(2000);
	#endif
	
	BREAKPOINT;
	b++;
	digitalWrite(LED_BUILTIN, LOW);
	#ifdef DEBUG
		delay(250);
	#else
		delay(2000);
	#endif
}