# Original GMMK Full-Size

A Full-Sized Mechanical keyboard with RGB-Matrix key illumination.\
Keyboard is available in ANSI and ISO layouts. ANSI LAYOUT IS UNTESTED!\
Brought to you by: https://github.com/SonixQMK/qmk_firmware

There are 3 Hardware Revisions of this Keyboard:
 - Rev 1 supposedly was an early model with single-color LEDs and is unsupported.
 - Rev 2 is supported. It has an VS11K16A (SN32F268F) MCU and VS12L03A (SLED1734X) I2C LED driver.
 - Rev 3 starts at Serial Number SNSS12116xxxxx and has a VS12L17A SPI LED driver. It is currently unsupported.

Make example for this keyboard (after setting up your build environment):\
`make gmmk/full/rev2/iso:default`\
or\
`qmk compile -kb gmmk/full/rev2/iso --keymap default`

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

KLE Layout here: [http://www.keyboard-layout-editor.com](https://www.keyboard-layout-editor.com/##@_name=GMMK%20Full-Size%20ISO&author=reklrekl&notes=Center%20right%20is%20LED%20chip%2F:address%0ABottom%20Right%20is%20matrix%20%5Brow,%20col%5D%3B&@_fa@:0&:0&:0&:1&:0&:0&:0&:1%3B%3B&=Esc%0A%0A%0A%5B0,0%5D%0A%0A%0A%0A1%2F:C0&_x:1%3B&=F1%0A%0A%0A%5B0,1%5D%0A%0A%0A%0A1%2F:C1&=F2%0A%0A%0A%5B0,2%5D%0A%0A%0A%0A1%2F:C2&=F3%0A%0A%0A%5B0,3%5D%0A%0A%0A%0A1%2F:C3&=F4%0A%0A%0A%5B0,4%5D%0A%0A%0A%0A1%2F:C4&_x:0.5%3B&=F5%0A%0A%0A%5B0,5%5D%0A%0A%0A%0A1%2F:C5&=F6%0A%0A%0A%5B0,6%5D%0A%0A%0A%0A1%2F:C6&=F7%0A%0A%0A%5B0,7%5D%0A%0A%0A%0A1%2F:C7&=F8%0A%0A%0A%5B0,8%5D%0A%0A%0A%0A1%2F:C8&_x:0.5%3B&=F9%0A%0A%0A%5B0,9%5D%0A%0A%0A%0A1%2F:C9&=F10%0A%0A%0A%5B0,10%5D%0A%0A%0A%0A1%2F:CA&=F11%0A%0A%0A%5B0,11%5D%0A%0A%0A%0A0%2F:C0&=F12%0A%0A%0A%5B0,12%5D%0A%0A%0A%0A0%2F:C1&_x:0.25%3B&=PrtSc%0A%0A%0A%5B6,3%5D%0A%0A%0A%0A0%2F:C2&_fa@:1&:0&:0&:1&:0&:0&:0&:1%3B%3B&=Scroll%20Lock%0A%0A%0A%5B6,4%5D%0A%0A%0A%0A0%2F:C3&_fa@:0&:0&:0&:1&:0&:0&:0&:1%3B%3B&=Pause%0A%0A%0A%5B6,5%5D%0A%0A%0A%0A0%2F:C4%3B&@_y:0.5%3B&=%C2%AC%0A%60%0A%0A%5B1,0%5D%0A%0A%0A%0A1%2F:90&=!%0A1%0A%0A%5B1,1%5D%0A%0A%0A%0A1%2F:91&=%22%0A2%0A%0A%5B1,2%5D%0A%0A%0A%0A1%2F:92&=%C2%A3%0A3%0A%0A%5B1,3%5D%0A%0A%0A%0A1%2F:93&=$%0A4%0A%0A%5B1,4%5D%0A%0A%0A%0A1%2F:94&=%25%0A5%0A%0A%5B1,5%5D%0A%0A%0A%0A1%2F:95&=%5E%0A6%0A%0A%5B1,6%5D%0A%0A%0A%0A1%2F:96&=%2F&%0A7%0A%0A%5B1,7%5D%0A%0A%0A%0A1%2F:97&=*%0A8%0A%0A%5B1,8%5D%0A%0A%0A%0A1%2F:98&=(%0A9%0A%0A%5B1,9%5D%0A%0A%0A%0A1%2F:9C&=)%0A0%0A%0A%5B1,10%5D%0A%0A%0A%0A1%2F:9D&=%2F_%0A-%0A%0A%5B1,11%5D%0A%0A%0A%0A1%2F:9E&=+%0A%2F=%0A%0A%5B1,12%5D%0A%0A%0A%0A1%2F:9F&_w:2%3B&=Backspace%0A%0A%0A%5B5,12%5D%0A%0A%0A%0A0%2F:CA&_x:0.25%3B&=Insert%0A%0A%0A%5B6,7%5D%0A%0A%0A%0A0%2F:90&=Home%0A%0A%0A%5B6,8%5D%0A%0A%0A%0A0%2F:91&=PgUp%0A%0A%0A%5B6,9%5D%0A%0A%0A%0A0%2F:92&_x:0.25&fa@:1&:0&:0&:1&:0&:0&:0&:1%3B%3B&=Num%20Lock%0A%0A%0A%5B1,13%5D%0A%0A%0A%0A0%2F:93&_fa@:0&:0&:0&:1&:0&:0&:0&:1%3B%3B&=%2F%2F%0A%0A%0A%5B1,14%5D%0A%0A%0A%0A0%2F:94&=*%0A%0A%0A%5B1,15%5D%0A%0A%0A%0A0%2F:95&=-%0A%0A%0A%5B6,13%5D%0A%0A%0A%0A0%2F:96%3B&@_w:1.5%3B&=Tab%0A%0A%0A%5B2,0%5D%0A%0A%0A%0A1%2F:60&=Q%0A%0A%0A%5B2,1%5D%0A%0A%0A%0A1%2F:61&=W%0A%0A%0A%5B2,2%5D%0A%0A%0A%0A1%2F:62&=E%0A%0A%0A%5B2,3%5D%0A%0A%0A%0A1%2F:63&=R%0A%0A%0A%5B2,4%5D%0A%0A%0A%0A1%2F:64&=T%0A%0A%0A%5B2,5%5D%0A%0A%0A%0A1%2F:65&=Y%0A%0A%0A%5B2,6%5D%0A%0A%0A%0A1%2F:69&=U%0A%0A%0A%5B2,7%5D%0A%0A%0A%0A1%2F:6A&=I%0A%0A%0A%5B2,8%5D%0A%0A%0A%0A1%2F:6B&=O%0A%0A%0A%5B2,9%5D%0A%0A%0A%0A1%2F:6C&=P%0A%0A%0A%5B2,10%5D%0A%0A%0A%0A1%2F:6D&=%7B%0A%5B%0A%0A%5B2,11%5D%0A%0A%0A%0A1%2F:6E&=%7D%0A%5D%0A%0A%5B2,12%5D%0A%0A%0A%0A1%2F:6F&_x:0.25&w:1.25&h:2&w2:1.5&h2:1&x2:-0.25%3B&=Enter%0A%0A%0A%5B4,12%5D%0A%0A%0A%0A1%2F:3F&_x:0.25%3B&=Delete%0A%0A%0A%5B6,10%5D%0A%0A%0A%0A0%2F:98&=End%0A%0A%0A%5B6,11%5D%0A%0A%0A%0A0%2F:60&=PgDn%0A%0A%0A%5B6,12%5D%0A%0A%0A%0A0%2F:61&_x:0.25&fa@:0&:1&:0&:1&:0&:0&:0&:1%3B%3B&=7%0AHome%0A%0A%5B2,13%5D%0A%0A%0A%0A0%2F:62&=8%0A%E2%86%91%0A%0A%5B2,14%5D%0A%0A%0A%0A0%2F:63&=9%0APgUp%0A%0A%5B2,15%5D%0A%0A%0A%0A0%2F:64&_h:2%3B&=+%0A%0A%0A%5B6,14%5D%0A%0A%0A%0A0%2F:65%3B&@_w:1.75%3B&=Caps%20Lock%0A%0A%0A%5B3,0%5D%0A%0A%0A%0A1%2F:30&=A%0A%0A%0A%5B3,1%5D%0A%0A%0A%0A1%2F:31&=S%0A%0A%0A%5B3,2%5D%0A%0A%0A%0A1%2F:32&=D%0A%0A%0A%5B3,3%5D%0A%0A%0A%0A1%2F:36&=F%0A%0A%0A%5B3,4%5D%0A%0A%0A%0A1%2F:37&=G%0A%0A%0A%5B3,5%5D%0A%0A%0A%0A1%2F:38&=H%0A%0A%0A%5B3,6%5D%0A%0A%0A%0A1%2F:39&=J%0A%0A%0A%5B3,7%5D%0A%0A%0A%0A1%2F:3A&=K%0A%0A%0A%5B3,8%5D%0A%0A%0A%0A1%2F:3B&=L%0A%0A%0A%5B3,9%5D%0A%0A%0A%0A1%2F:3C&_fa@:0&:0&:0&:1&:0&:0&:0&:1%3B%3B&=%2F:%0A%2F%3B%0A%0A%5B3,10%5D%0A%0A%0A%0A1%2F:3D&=%2F@%0A'%0A%0A%5B3,11%5D%0A%0A%0A%0A1%2F:3E&=~%0A%23%0A%0A%5B3,12%5D%0A%0A%0A%0A0%2F:97&_x:4.75&fa@:0&:1&:0&:1&:0&:0&:0&:1%3B%3B&=4%0A%E2%86%90%0A%0A%5B3,13%5D%0A%0A%0A%0A0%2F:30&=5%0A%0A%0A%5B3,14%5D%0A%0A%0A%0A0%2F:31&=6%0A%E2%86%92%0A%0A%5B3,15%5D%0A%0A%0A%0A0%2F:32%3B&@_w:1.25%3B&=Shift%0A%0A%0A%5B4,0%5D%0A%0A%0A%0A1%2F:03&_fa@:0&:0&:0&:1&:0&:0&:0&:1%3B%3B&=%7C%0A%5C%0A%0A%5B6,2%5D%0A%0A%0A%0A1%2F:04&=Z%0A%0A%0A%5B4,1%5D%0A%0A%0A%0A1%2F:05&=X%0A%0A%0A%5B4,2%5D%0A%0A%0A%0A1%2F:06&=C%0A%0A%0A%5B4,3%5D%0A%0A%0A%0A1%2F:07&=V%0A%0A%0A%5B4,4%5D%0A%0A%0A%0A1%2F:08&=B%0A%0A%0A%5B4,5%5D%0A%0A%0A%0A1%2F:09&=N%0A%0A%0A%5B4,6%5D%0A%0A%0A%0A1%2F:0A&=M%0A%0A%0A%5B4,7%5D%0A%0A%0A%0A1%2F:0B&=%3C%0A,%0A%0A%5B4,8%5D%0A%0A%0A%0A1%2F:0C&=%3E%0A.%0A%0A%5B4,9%5D%0A%0A%0A%0A1%2F:0D&=%3F%0A%2F%2F%0A%0A%5B4,10%5D%0A%0A%0A%0A1%2F:0E&_w:2.75%3B&=Shift%0A%0A%0A%5B4,11%5D%0A%0A%0A%0A1%2F:0F&_x:1.25%3B&=%E2%86%91%0A%0A%0A%5B5,10%5D%0A%0A%0A%0A0%2F:36&_x:1.25&fa@:0&:1&:0&:1&:0&:0&:0&:1%3B%3B&=1%0AEnd%0A%0A%5B4,13%5D%0A%0A%0A%0A0%2F:37&=2%0A%E2%86%93%0A%0A%5B4,14%5D%0A%0A%0A%0A0%2F:38&=3%0APgDn%0A%0A%5B4,15%5D%0A%0A%0A%0A0%2F:39&_h:2%3B&=Enter%0A%0A%0A%5B5,15%5D%0A%0A%0A%0A0%2F:3A%3B&@_w:1.25%3B&=Ctrl%0A%0A%0A%5B5,0%5D%0A%0A%0A%0A0%2F:03&_w:1.25%3B&=Win%0A%0A%0A%5B5,1%5D%0A%0A%0A%0A0%2F:04&_w:1.25%3B&=Alt%0A%0A%0A%5B5,2%5D%0A%0A%0A%0A0%2F:05&_w:6.25%3B&=%0A%0A%0A%5B5,3%5D%0A%0A%0A%0A0%2F:07&_w:1.25%3B&=AltGr%0A%0A%0A%5B5,4%5D%0A%0A%0A%0A0%2F:09&_w:1.25%3B&=Win%0A%0A%0A%5B5,5%5D%0A%0A%0A%0A0%2F:0A&_w:1.25%3B&=Menu%0A%0A%0A%5B5,6%5D%0A%0A%0A%0A0%2F:0B&_w:1.25%3B&=Ctrl%0A%0A%0A%5B5,7%5D%0A%0A%0A%0A0%2F:0D&_x:0.25%3B&=%E2%86%90%0A%0A%0A%5B5,8%5D%0A%0A%0A%0A0%2F:0E&=%E2%86%93%0A%0A%0A%5B5,9%5D%0A%0A%0A%0A0%2F:0F&=%E2%86%92%0A%0A%0A%5B5,11%5D%0A%0A%0A%0A0%2F:3B&_x:0.25&w:2%3B&=0%0AIns%0A%0A%5B5,13%5D%0A%0A%0A%0A0%2F:3C&=.%0ADel%0A%0A%5B5,14%5D%0A%0A%0A%0A0%2F:3D)

### How to get QMK working on the GMMK Full-Size:
1. Check if you have the correct revision 1 of the board by checking the serial number of the Keyboard. It has to be lower than SNSS12116xxxxx!
2. Download the Sonix Flasher from here: https://github.com/SonixQMK/sonix-flasher
3. Start the flasher and click "Reboot to Bootloader". Wait for the board to be in the Bootloader.
4.  Flash the correct jumploader for the Glorious GMMK Full. You can get a precompiled binary here: https://github.com/SonixQMK/sonix-keyboard-bootloader
5.  When the board is in Jumploader flash QMK (which you built before using the command above)

### How to get back to stock firmware (ONLY STOCK FW FOR ANSI KEYBOARDS AVAILABLE!)
1. Download the GMMK Full-Size Stock fimrware from here: https://github.com/SonixQMK/Mechanical-Keyboard-Database
2. Put the board into the Jumploader by holding Enter while plugging it in (or rebooting with QMK Key-Combo).
3. Use the Sonix Flasher "Revert to Stock Firmware" button and flash the stock firmware





## QMK implementation notes
<details>
  <summary>More info</summary>
    
  This Keyboard was originally implemented in an old branch of the SonixQMK firmware by dexter93.  
  I've just updated this to the lastest SonixQMK version.  
  Both the GMMK Compact and the GMMK TKL keyboards use very similar hardware, but as I don't have any means of testing these, as well as the ANSI-Layout, I won't implement these.  
  I'm happy to help anyone still using one of these keyboards porting QMK though.  
  
    
  The SN32F268F MCU has a tiny RAM, just 2kB.  
  To save RAM the custom LED driver is unbuffered. Every LED color command gets written directly to the LED driver via I2C.     
  This saves ~315b of memory, but makes full 24-bit color depth possible.   
  Two different I2C Drivers are available for Rev2:  
   - a Hardware based Driver using the MCU's internal I2C registers (but no interrupts)
   - a Bit-Banging software driver  
      
   Both drivers run on the main thread, as memory is limited.   
   Also, the legacy EEPROM driver is used, to make EEPROM work without too much RAM usage.  
</details>


## Keyboard Matrix and MCU details
<details>
  <summary>More info</summary>

## VS11K16A / SN32F268F MCU
### Pin Descriptions

| PIN | P (A0-D8) | KEY matrix                  | Comment / Other                                     |
| --- | --------- | --------------------------- | ----------------------------------------------------|
| 1   | P2.0      |                             |                                                     |
| 2   | P2.1      | col 0                       | ESC, `, TAB, CAPS, LSHFT, LCTL,                     |
| 3   | P2.2      | col 1                       | F1, 1, Q, A, Z, WIN,                                |
| 4   | P0.0      | col 2                       | F2, 2, W, S, X, LALT, \\ (ISO)                      |
| 5   | P0.1      | col 3                       | F3, 3, E, D, C, SPC, PRINT                          |
| 6   | P0.2      | col 4                       | F4, 4, R, F, V, RALT, SCRL                          |
| 7   | P0.3      | col 5                       | F5, 5, T, G, B, FN, PAUSE                           |
| 8   | P0.4      |                             | I2C SCL (Rev2)                                      |
| 9   | P0.5      |                             | I2C SDA (Rev2)                                      |
| 10  | P0.6      | col 6                       | F6, 6, Y, H, N, MENU,                               |
| 11  | P0.7      | col 7                       | F7, 7, U, J, M, RCTL, INS                           |
| 12  | P0.8      | col 8                       | F8, 8, I, K, ,, LEFT, HOME                          |
| 13  | P0.9      | col 9                       | F9, 9, O, L, ., DOWN, PGUP                          |
| 14  | P0.10     | col 10                      | F10, 0, P, ;, /, UP, DEL                            |
| 15  | P0.11     | col 11                      | F11, -, \[, ', RSFT, RIGHT, END                     |
| 16  | P0.12     | col 12                      | F12, =, \], \\ (ANSI) # (ISO), ENTER; BKSPC, PGDN   |
| 17  | P0.13     | col 13                      | ,NUMLOCK, KP7, KP4, KP1, KP0, KP-                   |
| 18  | P0.14     | col 14                      | ,KP/, KP8, KP5, KP2, KP., KP+                       |
| 19  | P0.15     | col 15                      | ,KP*, KP9, KP6, KP3, KPENTER,                       |
| 20  | P3.0      | row 0                       |                                                     |
| 21  | P3.1      | row 1                       |                                                     |
| 22  | P3.2      | row 2                       |                                                     |
| 23  | P3.3      | row 3                       |                                                     |
| 24  | P3.4      | row 4                       |                                                     |
| 25  | P3.5      | row 5                       |                                                     |
| 26  | P3.6      | row 6                       |                                                     |
| 27  | P3.7      |                             |                                                     |
| 28  | P3.8      |                             |                                                     |
| 29  | P2.3      |                             |                                                     |
| 30  | P2.4      |                             |                                                     |
| 31  | P2.5      |                             |                                                     |
| 32  | P2.6      |                             | NumLock indicator                                   |
| 33  | P2.7      |                             | CapsLock indicator                                  |
| 34  | P2.8      |                             | ScrollLock indicator                                |
| 35  | P2.9      |                             |                                                     |
| 36  | P2.10     |                             |                                                     |
| 37  | P1.5      |                             |                                                     |
| 38  | P1.4      |                             |                                                     |
| 39  | P1.3      |                             |                                                     |
| 40  | P1.2      |                             |                                                     |
| 41  | P1.1      |                             |                                                     |
| 42  | P1.0      |                             | I2C SDB (Rev2)                                      |
| 43  |           |                             | 5V USB                                              |
| 44  |           |                             | 5V USB                                              |
| 45  |           |                             |                                                     |
| 46  |           |                             | USB Data                                            |
| 47  |           |                             | USB Data                                            |
| 48  |           |                             | Ground                                              | 
</details>
