#include <usbhidkeyboard.h>
#include <usbhidkeynames.h> // optional to include Linux constant names for keys

USBHIDKeyboard kbd;

void setup() {
}

void loop() {

	// press A key
	kbd.press(KEY_A);

	delay(50);

	// release A key
	kbd.release(KEY_A);

	delay(50);

	// press modifier key
	kbd.press(KEY_SHIFT);
	// and a key
	kbd.press(KEY_B);

	delay(50);

	// release all keys
	kbd.releaseAll();

	delay(2000);

}