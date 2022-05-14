# arduino-usbhidkeyboard

Simple keyboard library for Arduino, with support for _all_ possible USB HID keycodes. Defines keys using their Linux constant names if possible.

*WARNING:* This is a code dump for now, the library is not finalized and may not even work as-is at the moment.


## Raison d'être

This library is modeled in part on the Arduino _Keyboard_ library which only allows to press keys identified by their lower-ASCII output string. This library foregoes this internal translation and directly accepts keycodes as defined by the USB HUT.


## Usage

```
#include "usbhidkeyboard.h"
#include "usbhidkeynames.h"

USBHIDKeyboard kbd;

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

```