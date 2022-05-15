# Arduino USBHIDKeyboard

Simple keyboard library for Arduino, with support for _all_ possible USB HID keycodes. Defines keys using their Linux constant names if possible.

**Status:** compiles and works as intended ... but may not satisfy "beautiful code" standards.


## Raison d'être

This library originated from a very specific need: I wrote it be used in an Nintendo Family Basic keyboard to USB adapter using an Arduino Pro Micro (using a little logic to poll the ICs and a custom key matrix table.)

However, the quasi-standard Arduino _Keyboard_ library proved insufficient to send all keystrokes: internally it is written to translate lower-ASCII -- and _only_ lower-ASCII characters -- into keycodes, which is not sufficient to generate all the keypresses on a Japanese keyboard. I am aware that other keyboard libraries do not have that limitation, but I find them either not very straightforward to use or way overblown in their feature set and size.

This library is able to send _all_ possible keycodes defined in the USB HUT, either using its numeric value or, more readable, using a `KEY_...` constant defined in the supplied `usbhidkeynames.h` which maps virtually all keycodes to the corresponding Linux constant name. Just like the Arduino _Keyboard_ library it is built upon the default _HID_ library.

It does serve its original purpose perfectly: press and release keys. Because it is able to send _any_ key, it may also be useful to create custom keypanels, e.g. for media keys or even otherwise unused exotic keys to be picked up by an application or a script on the host system (F17 key anyone?)


## Improvements

* I am not intimately familiar with creating Arduino libraries. It _seems_ to satisfy formal requirements but it may not satisfy "beautiful code" standards. Please tell me what I could improve, issues are open.

* If I get really bored someday, I may add `write()` and `print()` functions, making it a direct drop-in replacement for the Arduino _Keyboard_ library.

* I have yet to pick a suitable license, suggestions are very welcome.


## Usage

See included `example.ino`