/*
	This file is part of the USBHIDKeyboard library
	https://github.com/sqrwf/arduino-usbhidkeyboard/
*/


#ifndef USBHIDKEYBOARD_h
#define USBHIDKEYBOARD_h

#include "Arduino.h"
#include "HID.h"

typedef struct
{
	uint8_t modifiers;
	uint8_t reserved;
	uint8_t keys[6];
} KeyReport;

class USBHIDKeyboard
{
	public:
		USBHIDKeyboard(void);
		void press(unsigned int keycode);
		void release(unsigned int keycode);
		void releaseAll(void);
	private:
		KeyReport _keyReport;
		void sendReport(KeyReport* keys);
		void debugOutput(void);
		void addKeyToKeyreport(byte keycode);
		void removeKeyFromKeyreport(byte keycode);
};

#endif