/*
	USBHIDKeyboard library
	https://github.com/sqrwf/arduino-usbhidkeyboard/
*/


#include "usbhidkeyboard.h"

#if defined(_USING_HID)

// HID report descriptor
static const uint8_t _hidReportDescriptor[] PROGMEM = {
	0x05, 0x01, // USAGE_PAGE          (Generic Desktop)  // 47
	0x09, 0x06, // USAGE               (Keyboard)
	0xa1, 0x01, // COLLECTION          (Application)
	0x85, 0x02, //   REPORT_ID         (2)
	0x05, 0x07, //   USAGE_PAGE        (Keyboard)
	0x19, 0xe0, //   USAGE_MINIMUM     (Keyboard LeftControl)
	0x29, 0xe7, //   USAGE_MAXIMUM     (Keyboard Right GUI)
	0x15, 0x00, //   LOGICAL_MINIMUM   (0)
	0x25, 0x01, //   LOGICAL_MAXIMUM   (1)
	0x75, 0x01, //   REPORT_SIZE       (1)
	0x95, 0x08, //   REPORT_COUNT      (8)
	0x81, 0x02, //   INPUT             (Data,Var,Abs)
	0x95, 0x01, //   REPORT_COUNT      (1)
	0x75, 0x08, //   REPORT_SIZE       (8)
	0x81, 0x03, //   INPUT             (Cnst,Var,Abs)
	0x95, 0x06, //   REPORT_COUNT      (6)
	0x75, 0x08, //   REPORT_SIZE       (8)
	0x15, 0x00, //   LOGICAL_MINIMUM   (0)
	0x25, 0xff, //   LOGICAL_MAXIMUM   (255 - all possible keycodes)
	0x05, 0x07, //   USAGE_PAGE        (Keyboard)
	0x19, 0x00, //   USAGE_MINIMUM     (0 - "Reserved (no event indicated)")
	0x29, 0xff, //   USAGE_MAXIMUM     (255 - all possible keycodes)
	0x81, 0x00, //   INPUT             (Data,Ary,Abs)
	0xc0        // END_COLLECTION
}; 

USBHIDKeyboard::USBHIDKeyboard(void)
{
	static HIDSubDescriptor node(_hidReportDescriptor, sizeof(_hidReportDescriptor));
	HID().AppendDescriptor(&node);
}

void USBHIDKeyboard::sendReport(KeyReport* keys)
{
	HID().SendReport(2,keys,sizeof(KeyReport));
}

void USBHIDKeyboard::press(unsigned int keycode)
{
	if (keycode>=0xff) {;
		_keyReport.modifiers |= (keycode>>8);
	}
	addKeyToKeyreport(lowByte(keycode));
	sendReport(&_keyReport);
}

void USBHIDKeyboard::release(unsigned int keycode)
{
	if (keycode>=0xff) {
		_keyReport.modifiers &= ~(keycode>>8);
	}
	removeKeyFromKeyreport(lowByte(keycode));
	sendReport(&_keyReport);
}

void USBHIDKeyboard::addKeyToKeyreport(byte keycode)
{
	if (keycode == 0) {
		/* not a key */
		return;
	}
	for (uint8_t i=0; i<6; i++) {
		if ( _keyReport.keys[i] == keycode ) {
			/* key is already present, no need to add it */
			return;
		}
	}
	for (uint8_t i=0; i<6; i++) {
		if ( _keyReport.keys[i] == 0 ) {
			/* found an empty slot, add keycode */
			_keyReport.keys[i] = keycode;
			return;
		}
	}
	/*
		If code reaches this point, the keys array is full with other keys.
		By spec this would prompt an error report.
		We just ignore the additional key, effectively imposing a hard limit to 6 simultaneous keys + modifiers.
	*/
}

void USBHIDKeyboard::removeKeyFromKeyreport(byte keycode)
{
	if (keycode == 0) {
		/* not a key */
		return;
	}
	for (uint8_t i=0; i<6; i++) {
		if (_keyReport.keys[i] == keycode) {
			/* found keycode in slot, remove */
			_keyReport.keys[i] = 0;
			return;
		}
	}
}

void USBHIDKeyboard::releaseAll(void)
{
	_keyReport.modifiers = 0;
	for (uint8_t i=0; i<6; i++) {
		_keyReport.keys[i] = 0;
	}
	sendReport(&_keyReport);
}

void USBHIDKeyboard::debugOutput(void)
{
	Serial.print("* Debug: _keyReport.modifiers: ");
	Serial.println(_keyReport.modifiers);
	Serial.print("*        _keyReport.keys:      ");
	for (uint8_t i=0; i<6; i++) {
		Serial.print(_keyReport.keys[i]);
		Serial.print(" ");
	}
	Serial.println("");
	Serial.println("");
}

#endif