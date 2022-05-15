/*
	This file is part of the USBHIDKeyboard library
	https://github.com/sqrwf/arduino-usbhidkeyboard/
*/


/*

Constant names for keycodes, reverse-matched from the Linux source code (where applicable)

Reference:
	"Input event codes"
	https://github.com/torvalds/linux/blob/master/include/uapi/linux/input-event-codes.h

Comments for keycodes are taken from
	"Universal Serial Bus (USB) HID Usage Tables" ("USB HUT") 1.12
	Chapter 10 "Keyboard/Keypad Page (0x07)":
	http://www.usb.org/developers/hidpage

Keys without defined constant names are either not "real keys" or functionally deprecated.

Modifier keys are not mapped to their actual key codes (0xe0-0xe7) but mapped to double-byte values for use with the
USBHIDKeyboard library (the high byte contains the bitmap for the modifier key).

Comment legend:
[1] No Linux constant name is available for this key, given constant name is a best effort based on the label/function.
[2] Linux internally maps multiple HID keycodes to the same constant name. To differentiate the keys, a different
	constant name has been chosen for the less common key, again in a best effort.
[3] Key's function is unclear and, even in the USB HUT, insufficiently documented.

*/


#ifndef USBHIDKEYNAMES_h
#define USBHIDKEYNAMES_h


// Not physical keys - reserved for typical keyboard status or keyboard errors, sent as a member of the keyboard array
//                           0x00 //        Reserved (no event indicated)
//                           0x01 //        Keyboard ErrorRollOver
//                           0x02 //        Keyboard POST fail
//                           0x03 //        Keyboard error undefined

#define KEY_A                0x04 //        Keyboard a and A
#define KEY_B                0x05 //        Keyboard b and B
#define KEY_C                0x06 //        Keyboard c and C
#define KEY_D                0x07 //        Keyboard d and D
#define KEY_E                0x08 //        Keyboard e and E
#define KEY_F                0x09 //        Keyboard f and F
#define KEY_G                0x0a //        Keyboard g and G
#define KEY_H                0x0b //        Keyboard h and H
#define KEY_I                0x0c //        Keyboard i and I
#define KEY_J                0x0d //        Keyboard j and J
#define KEY_K                0x0e //        Keyboard k and K
#define KEY_L                0x0f //        Keyboard l and L
#define KEY_M                0x10 //        Keyboard m and M
#define KEY_N                0x11 //        Keyboard n and N
#define KEY_O                0x12 //        Keyboard o and O
#define KEY_P                0x13 //        Keyboard p and P
#define KEY_Q                0x14 //        Keyboard q and Q
#define KEY_R                0x15 //        Keyboard r and R
#define KEY_S                0x16 //        Keyboard s and S
#define KEY_T                0x17 //        Keyboard t and T
#define KEY_U                0x18 //        Keyboard u and U
#define KEY_V                0x19 //        Keyboard v and V
#define KEY_W                0x1a //        Keyboard w and W
#define KEY_X                0x1b //        Keyboard x and X
#define KEY_Y                0x1c //        Keyboard y and Y
#define KEY_Z                0x1d //        Keyboard z and Z
#define KEY_1                0x1e //        Keyboard 1 and !
#define KEY_2                0x1f //        Keyboard 2 and @
#define KEY_3                0x20 //        Keyboard 3 and #
#define KEY_4                0x21 //        Keyboard 4 and $
#define KEY_5                0x22 //        Keyboard 5 and %
#define KEY_6                0x23 //        Keyboard 6 and ^
#define KEY_7                0x24 //        Keyboard 7 and &
#define KEY_8                0x25 //        Keyboard 8 and *
#define KEY_9                0x26 //        Keyboard 9 and (
#define KEY_0                0x27 //        Keyboard 0 and )

#define KEY_ENTER            0x28 //        Keyboard Return (ENTER)
#define KEY_ESC              0x29 //        Keyboard ESCAPE
#define KEY_BACKSPACE        0x2a //        Keyboard DELETE (Backspace)
#define KEY_TAB              0x2b //        Keyboard Tab
#define KEY_SPACE            0x2c //        Keyboard Spacebar
#define KEY_MINUS            0x2d //        Keyboard - and _
#define KEY_EQUAL            0x2e //        Keyboard = and +
#define KEY_LEFTBRACE        0x2f //        Keyboard [ and {
#define KEY_RIGHTBRACE       0x30 //        Keyboard ] and }
#define KEY_BACKSLASH        0x31 //        Keyboard \ and |
#define KEY_HASHTILDE        0x32 // [1][2] Keyboard Non-US # and ~ (mapped to KEY_BACKSLASH in Linux)
#define KEY_SEMICOLON        0x33 //        Keyboard ; and :
#define KEY_APOSTROPHE       0x34 //        Keyboard ' and "
#define KEY_GRAVE            0x35 //        Keyboard ` and ~
#define KEY_COMMA            0x36 //        Keyboard , and <
#define KEY_DOT              0x37 //        Keyboard . and >
#define KEY_SLASH            0x38 //        Keyboard / and ?
#define KEY_CAPSLOCK         0x39 //        Keyboard Caps Lock (non-locking version, comp. keycode 0x82)

#define KEY_F1               0x3a //        Keyboard F1
#define KEY_F2               0x3b //        Keyboard F2
#define KEY_F3               0x3c //        Keyboard F3
#define KEY_F4               0x3d //        Keyboard F4
#define KEY_F5               0x3e //        Keyboard F5
#define KEY_F6               0x3f //        Keyboard F6
#define KEY_F7               0x40 //        Keyboard F7
#define KEY_F8               0x41 //        Keyboard F8
#define KEY_F9               0x42 //        Keyboard F9
#define KEY_F10              0x43 //        Keyboard F10
#define KEY_F11              0x44 //        Keyboard F11
#define KEY_F12              0x45 //        Keyboard F12

#define KEY_SYSRQ            0x46 //        Keyboard Print Screen
#define KEY_SCROLLLOCK       0x47 //        Keyboard Scroll Lock (non-locking version, comp. keycode 0x84)
#define KEY_PAUSE            0x48 //        Keyboard Pause
#define KEY_INSERT           0x49 //        Keyboard Insert
#define KEY_HOME             0x4a //        Keyboard Home
#define KEY_PAGEUP           0x4b //        Keyboard Page Up
#define KEY_DELETE           0x4c //        Keyboard Delete Forward
#define KEY_END              0x4d //        Keyboard End
#define KEY_PAGEDOWN         0x4e //        Keyboard Page Down
#define KEY_RIGHT            0x4f //        Keyboard Right Arrow
#define KEY_LEFT             0x50 //        Keyboard Left Arrow
#define KEY_DOWN             0x51 //        Keyboard Down Arrow
#define KEY_UP               0x52 //        Keyboard Up Arrow
#define KEY_NUMLOCK          0x53 //        Keyboard Num Lock and Clear (non-locking version, comp. keycode 0x83)
#define KEY_KPSLASH          0x54 //        Keypad /
#define KEY_KPASTERISK       0x55 //        Keypad *
#define KEY_KPMINUS          0x56 //        Keypad -
#define KEY_KPPLUS           0x57 //        Keypad +
#define KEY_KPENTER          0x58 //        Keypad ENTER
#define KEY_KP1              0x59 //        Keypad 1 and End
#define KEY_KP2              0x5a //        Keypad 2 and Down Arrow
#define KEY_KP3              0x5b //        Keypad 3 and PageDn
#define KEY_KP4              0x5c //        Keypad 4 and Left Arrow
#define KEY_KP5              0x5d //        Keypad 5
#define KEY_KP6              0x5e //        Keypad 6 and Right Arrow
#define KEY_KP7              0x5f //        Keypad 7 and Home
#define KEY_KP8              0x60 //        Keypad 8 and Up Arrow
#define KEY_KP9              0x61 //        Keypad 9 and Page Up
#define KEY_KP0              0x62 //        Keypad 0 and Insert
#define KEY_KPDOT            0x63 //        Keypad . and Delete
#define KEY_102ND            0x64 //        Keyboard Non-US \ and | (typically near the Left-Shift key in AT-102 implementations)

#define KEY_COMPOSE          0x65 //        Keyboard Application ("Windows key for Windows 95, and 'Compose.'")
//                           0x66 //        Keyboard Power ("Reserved for typical keyboard status or keyboard errors. Sent as a member of the keyboard array. Not a physical key.")

#define KEY_KPEQUAL          0x67 //        Keypad =

#define KEY_F13              0x68 //        Keyboard F13
#define KEY_F14              0x69 //        Keyboard F14
#define KEY_F15              0x6a //        Keyboard F15
#define KEY_F16              0x6b //        Keyboard F16
#define KEY_F17              0x6c //        Keyboard F17
#define KEY_F18              0x6d //        Keyboard F18
#define KEY_F19              0x6e //        Keyboard F19
#define KEY_F20              0x6f //        Keyboard F20
#define KEY_F21              0x70 //        Keyboard F21
#define KEY_F22              0x71 //        Keyboard F22
#define KEY_F23              0x72 //        Keyboard F23
#define KEY_F24              0x73 //        Keyboard F24

#define KEY_OPEN             0x74 //        Keyboard Execute
#define KEY_HELP             0x75 //        Keyboard Help
#define KEY_PROPS            0x76 //        Keyboard Menu
#define KEY_FRONT            0x77 //        Keyboard Select
#define KEY_STOP             0x78 //        Keyboard Stop
#define KEY_AGAIN            0x79 //        Keyboard Again
#define KEY_UNDO             0x7a //        Keyboard Undo
#define KEY_CUT              0x7b //        Keyboard Cut
#define KEY_COPY             0x7c //        Keyboard Copy
#define KEY_PASTE            0x7d //        Keyboard Paste
#define KEY_FIND             0x7e //        Keyboard Find
#define KEY_MUTE             0x7f //        Keyboard Mute
#define KEY_VOLUMEUP         0x80 //        Keyboard Volume Up
#define KEY_VOLUMEDOWN       0x81 //        Keyboard Volume Down

// As per USB HUT, keys 0x82, 0x83, 0x84 are "implemented as locking keys, sent as a toggle button. Available for legacy support, most systems should use the non-locking version"
//                           0x82 //        Keyboard Locking Caps Lock
//                           0x83 //        Keyboard Locking Num Lock
//                           0x84 //        Keyboard Locking Scroll Lock

#define KEY_KPCOMMA          0x85 //        Keypad Comma ("appropriate usage for the Brazilian keypad period (.) key")
//                           0x86 //        Keypad Equal Sign (Used on AS/400 keyboards)

#define KEY_RO               0x87 //        Keyboard International1 (Japanese backslash/ro/fullwidth whitespace and Brazilian forward-slash/question-mark key)
#define KEY_KATAKANAHIRAGANA 0x88 //        Keyboard International2 (Japanese Katakana/Hiragana key)
#define KEY_KANA             0x88 // [1]      (aka "Kana key")
#define KEY_YEN              0x89 //        Keyboard International3 (Japanese Yen/underscore/vertical line key)
#define KEY_HENKAN           0x8a //        Keyboard International4
#define KEY_MUHENKAN         0x8b //        Keyboard International5
#define KEY_KPJPCOMMA        0x8c //        Keyboard International6 (Japanese comma key)
#define KEY_BYTEMODE         0x8d // [1]    Keyboard International7 (toggle double-byte/single-byte mode)
//                           0x8e //        Keyboard International8 (undefined, "available for other Front End Language Processors")
//                           0x8f //        Keyboard International9 (undefined, "available for other Front End Language Processors")
#define KEY_HANGEUL          0x90 //        Keyboard LANG1 (Korean Hangeul/English toggle key)
#define KEY_HANGUEL          0x90 //           (alternate Linux constant name ... to catch spelling errors?)
#define KEY_HANJA            0x91 //        Keyboard LANG2 (Korean Hanja Conversion key)
#define KEY_KATAKANA         0x92 //        Keyboard LANG3 (Japanese Katakana key)
#define KEY_HIRAGANA         0x93 //        Keyboard LANG4 (Japanese Hiragana key)
//                           0x94 //        Keyboard LANG5 (Zenkaku/Hankaku key on Japanese language keyboards)
#define KEY_ZENKAKUHANKAKU   0x35 //           (Noteworthy exception: the keycode should be 0x94 as per USB HUT, but in practice 0x35 is used, which corresponds to the
//                                             physical key position. Some OSes, e.g. Windows, will actually not recognize 0x94 as the Zenkaku/Hankaku key.)
//                           0x95 //        Keyboard LANG6 ("Reserved for language-specific functions, such as Front End Processors and Input Method Editors")
//                           0x96 //        Keyboard LANG7 ("Reserved for language-specific functions, such as Front End Processors and Input Method Editors")
//                           0x97 //        Keyboard LANG8 ("Reserved for language-specific functions, such as Front End Processors and Input Method Editors")
//                           0x98 //        Keyboard LANG9 ("Reserved for language-specific functions, such as Front End Processors and Input Method Editors")

#define KEY_ALTERASE         0x99 // [1]    Keyboard Alternate Erase (e.g., "Erase-Eaze key")
#define KEY_SYSRQ            0x9a // [1]    Keyboard SysReq/Attention
#define KEY_CANCEL           0x9b // [1]    Keyboard Cancel
#define KEY_CLEAR            0x9c // [1][2] Keyboard Clear (mapped to KEY_DELETE in Linux)
#define KEY_PRIOR            0x9d // [1]    Keyboard Prior
#define KEY_RETURN           0x9e // [1]    Keyboard Return
#define KEY_SEPARATOR        0x9f // [1]    Keyboard Separator
#define KEY_OUT              0xa0 // [1]    Keyboard Out
#define KEY_OPER             0xa1 // [1]    Keyboard Oper
#define KEY_CLEARAGAIN       0xa2 // [1]    Keyboard Clear/Again
#define KEY_CRSEL            0xa3 // [1]    Keyboard CrSel/Props
#define KEY_EXSEL            0xa4 // [1]    Keyboard ExSel

#define KEY_KP00             0xb0 // [1]    Keypad 00
#define KEY_KP000            0xb1 // [1]    Keypad 000
#define KEY_KPTHOUSANDS      0xb2 // [1]    Thousands Separator (symbol displayed will depend on the current locale settings of the operating system)
#define KEY_KPDECIMAL        0xb3 // [1]    Decimal Separator (symbol displayed will depend on the current locale settings of the operating system)
#define KEY_KPCURRENCY       0xb4 // [1]    Currency Unit
#define KEY_KPCURRENCYSUB    0xb5 // [1]    Currency Sub-unit
#define KEY_KPLEFTPAREN      0xb6 //        Keypad (
#define KEY_KPRIGHTPAREN     0xb7 //        Keypad )
#define KEY_KPLEFTBRACE      0xb8 // [1]    Keypad {
#define KEY_KPRIGHTBRACE     0xb9 // [1]    Keypad }
#define KEY_KPTAB            0xba // [1]    Keypad Tab
#define KEY_KPBACKSPACE      0xbb // [1]    Keypad Backspace
#define KEY_KPA              0xbc // [1]    Keypad A
#define KEY_KPB              0xbd // [1]    Keypad B
#define KEY_KPC              0xbe // [1]    Keypad C
#define KEY_KPD              0xbf // [1]    Keypad D
#define KEY_KPE              0xc0 // [1]    Keypad E
#define KEY_KPF              0xc1 // [1]    Keypad F
#define KEY_KPXOR            0xc2 // [1]    Keypad XOR
#define KEY_KPCARET          0xc3 // [1][3] Keypad ^
#define KEY_KPPERCENT        0xc4 // [1]    Keypad %
#define KEY_KPLESSTHAN       0xc5 // [1][3] Keypad <
#define KEY_KPMORETHAN       0xc6 // [1][3] Keypad >
#define KEY_KPAND            0xc7 // [1][3] Keypad &
//      KEY_KPAMPERSAND
#define KEY_KPANDAND         0xc8 // [1][3] Keypad &&
//      KEY_KPDBLAMPERSAND
#define KEY_KPOR             0xc9 // [1][3] Keypad |
//      KEY_KPVERTLINE
#define KEY_KPOROR           0xca // [1][3] Keypad ||
//      KEY_KPDBLVERTLINE
#define KEY_KPCOLON          0xcb // [1][3] Keypad :
#define KEY_KPHASH           0xcc // [1][3] Keypad #
#define KEY_KPSPACE          0xcd // [1]    Keypad Space
#define KEY_KPAT             0xce // [1][3] Keypad @
#define KEY_KPEXCLAMATION    0xcf // [1][3] Keypad !
#define KEY_KPMEMORYSTORE    0xd0 // [1]    Keypad Memory Store
#define KEY_KPMEMORYRECALL   0xd1 // [1]    Keypad Memory Recall
#define KEY_KPMEMORYCLEAR    0xd2 // [1]    Keypad Memory Clear
#define KEY_KPMEMORYADD      0xd3 // [1]    Keypad Memory Add
#define KEY_KPMEMORYSUBTRACT 0xd4 // [1]    Keypad Memory Subtract
#define KEY_KPMEMORYMULTIPLY 0xd5 // [1]    Keypad Memory Multiply
#define KEY_KPMEMORYDIVIDE   0xd6 // [1]    Keypad Memory Divide
#define KEY_KPPLUSMINUS      0xd7 // [1]    Keypad +/-
#define KEY_KPCLEAR          0xd8 // [1][2] Keypad Clear (mapped to KEY_DELETE in Linux)
#define KEY_KPCLEARENTRY     0xd9 // [1]    Keypad Clear Entry
#define KEY_KPBINARY         0xda // [1]    Keypad Binary
#define KEY_KPOCTAL          0xdb // [1]    Keypad Octal
#define KEY_KPDECIMAL        0xdc // [1]    Keypad Decimal
#define KEY_KPHEXADECIMAL    0xdd // [1]    Keypad Hexadecimal

// The following keys are defined as modifier keys further below, for use with the usbhidkeyboard library
//                           0xe0 //        Keyboard Left Control
//                           0xe1 //        Keyboard Left Shift
//                           0xe2 //        Keyboard Left Alt
//                           0xe3 //        Keyboard Left GUI (left windowing environment key, e.g., Windows key, Apple key, Sun Meta key)
//                           0xe4 //        Keyboard Right Control
//                           0xe5 //        Keyboard Right Shift
//                           0xe6 //        Keyboard Right Alt
//                           0xe7 //        Keyboard Right GUI (right windowing environment key, e.g., Windows key, Apple key, Sun Meta key)

#define KEY_PLAYPAUSE        0xe8 //        Media keys
#define KEY_STOPCD           0xe9 //
#define KEY_PREVIOUSSONG     0xea //
#define KEY_NEXTSONG         0xeb //
#define KEY_EJECTCD          0xec //
#define KEY_VOLUMEUP         0xed //
#define KEY_VOLUMEDOWN       0xee //
#define KEY_MUTE             0xef //
#define KEY_WWW              0xf0 //
#define KEY_BACK             0xf1 //
#define KEY_FORWARD          0xf2 //
#define KEY_STOP             0xf3 //
#define KEY_FIND             0xf4 //
#define KEY_SCROLLUP         0xf5 //
#define KEY_SCROLLDOWN       0xf6 //
#define KEY_EDIT             0xf7 //
#define KEY_SLEEP            0xf8 //
#define KEY_COFFEE           0xf9 //        (screen lock key)
#define KEY_SCREENLOCK       0xf9 //        (alternate Linux constant name, ostensibly for programmers who don't like coffee)
#define KEY_REFRESH          0xfa //
#define KEY_CALC             0xfb //


// Modifier keys (upper byte contains the bitmask for the key report)

#define KEY_LEFTCTRL         0x0100 //        Keyboard Left Control
#define KEY_CTRL             0x0100 //           (use left modifier key if position does not matter)
#define KEY_LEFTSHIFT        0x0200 //        Keyboard Left Shift
#define KEY_SHIFT            0x0200 //           (use left modifier key if position does not matter)
#define KEY_LEFTALT          0x0400 //        Keyboard Left Alt
#define KEY_ALT              0x0400 //           (use left modifier key if position does not matter)
#define KEY_LEFTMETA         0x0800 //        Keyboard Left Meta/GUI (left windowing environment key, e.g., Windows key, Apple key, Sun Meta key)
#define KEY_META             0x0800 //           (use left modifier key if position does not matter)
#define KEY_LEFTGUI          0x0800 //           (aka "GUI key")
#define KEY_GUI              0x0800 //           (use left modifier key if position does not matter)
#define KEY_RIGHTCTRL        0x1000 //        Keyboard Right Control
#define KEY_RIGHTSHIFT       0x2000 //        Keyboard Right Shift
#define KEY_RIGHTALT         0x4000 //        Keyboard Right Alt
#define KEY_RIGHTMETA        0x8000 //        Keyboard Right Meta/GUI (right windowing environment key, e.g., Windows key, Apple key, Sun Meta key)
#define KEY_RIGHTGUI         0x8000 //           (aka "GUI key")
#define KEY_ALTGR            0x4000 // [1]    Keyboard AltGr (on respective keyboard layouts this is the right Alt key)


#endif // USBHIDKEYNAMES