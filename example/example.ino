#include <usbhidkeyboard.h>
#include <usbhidkeynames.h> // optional to include Linux constant names for keys

USBHIDKeyboard kbd;

void setup() {
}

void loop() {

	// press a key
	kbd.press(KEY_A);

	delay(50);

	// release a key
	kbd.release(KEY_A);

	delay(200);

	// press a modifier key
	kbd.press(KEY_SHIFT);
	// ... and then a key
	kbd.press(KEY_B);

	delay(50);

	// release all keys
	kbd.releaseAll();

	delay(200);

	// press a key using its numeric keycode
	kbd.press(0x06); // 0x06 = "c" key

	delay(50);

	kbd.releaseAll();

	delay(200);

	// combine modifier(s) with a key in one keypress
	kbd.press(KEY_SHIFT|KEY_D);

	delay(50);

	kbd.releaseAll();

	delay(1000);

	// let's clean up and delete the four letters we just wrote
	kbd.press(KEY_BACKSPACE); delay(50); kbd.release(KEY_BACKSPACE); delay(50);
	kbd.press(KEY_BACKSPACE); delay(50); kbd.release(KEY_BACKSPACE); delay(50);
	kbd.press(KEY_BACKSPACE); delay(50); kbd.release(KEY_BACKSPACE); delay(50);
	kbd.press(KEY_BACKSPACE); delay(50); kbd.release(KEY_BACKSPACE); delay(50);

	delay(2000);

}