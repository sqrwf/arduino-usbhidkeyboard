# arduino-usbhidkeyboard

Simple keyboard library for Arduino, with support for _all_ possible USB HID keycodes. Defines keys using their Linux constant names if possible.

**WARNING: This is a code dump for now, it is not run-tested or compile-tested at the moment.**


## Raison d'être

This library is modeled in part after the Arduino _Keyboard_ library which only allows to press keys identified by their lower-ASCII output string and as such can not transmit more exotic keycodes found on some keyboards. This library foregoes the internal translation from a (single-character) string to keycodes and directly accepts keycodes as defined by the USB HUT, either using the numeric keycode value or by using the `KEY_*` constants defined in the optional `usbhidkeycodes.h`.

Originally it was written to be used in an Nintendo Family Basic keyboard to USB adapter using an Arduino Pro Micro, after the Arduino Keyboard library proved insufficient to transmit keycodes for special Japanese keys (e.g., the カナ key). Another use I can imagine is to transmit exotic keycodes from a custom keypad to be received by an application or script on the host system (e.g., F13 to F24 keys).


## Usage

```
#include "usbhidkeyboard.h"
#include "usbhidkeynames.h" /* optional to use defined constant names for keys (KEY_*) */

USBHIDKeyboard kbd;

void your_function() {

	/* Press a key (see usbhidkeynames.h for constant names) */
	kbd.press(KEY_A);

	/* Press a rather exotic key */
	kbd.press(KEY_MUHENKAN);

	/* If you insist, press a key using its USB HID keycode */
	kbd.press(0x4a); /* 0x4a = home key */

	/* Press a modifier key */
	kbd.press(KEY_LEFTCTRL);

	/* Release a key */
	kbd.release(KEY_A);

	/* Release all keys */
	kbd.releaseAll();

}

```