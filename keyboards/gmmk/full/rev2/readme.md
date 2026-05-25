# Original GMMK Full-Size Rev2

Description of the LED matrix and I2C Driver addressing code.

## VS12L03A / SLED1734X I2C LED Drivers (Rev2)

Each SLED1734X operates in Type 3 (common-anode matrix, 16 scan lines x 8 PWM channels = 128 channels per frame).  
Each LED uses 3 consecutive virtual PWM channels: R = base, G = base + 0x10, B = base + 0x20.  
Bit 7 selects the page frame (0x00–0x7F = Frame 1, 0x80–0xFF = Frame 2).  
The physical PWM register written is `(virtual_channel & 0x7F) + 0x20` on the selected frame.

`Combined` is the `g_led_pos[]` base index. R = `Combined`, G = `Combined + 0x10`, B = `Combined + 0x20`.

Two chips drive 105 RGB LEDs total:

### Chip 0 (I2C addr 0xE8, ADDR=GND) — 42 LEDs

Right-side function keys, nav cluster, numpad, bottom row (mods + arrows + space).

| LED# | Key         | [row,col]  | Combined | R addr/frame | G addr/frame | B addr/frame |
|------|-------------|------------|----------|--------------|--------------|--------------|
| 0    | F11         | [0,11]     | 0xC0     | 0x60/F2      | 0x70/F2      | 0x80/F2      |
| 1    | F12         | [0,12]     | 0xC1     | 0x61/F2      | 0x71/F2      | 0x81/F2      |
| 2    | PrtSc       | [6,3]      | 0xC2     | 0x62/F2      | 0x72/F2      | 0x82/F2      |
| 3    | ScrLk       | [6,4]      | 0xC3     | 0x63/F2      | 0x73/F2      | 0x83/F2      |
| 4    | Pause       | [6,5]      | 0xC4     | 0x64/F2      | 0x74/F2      | 0x84/F2      |
| 5    | BkSpc       | [5,12]     | 0xCA     | 0x6A/F2      | 0x7A/F2      | 0x8A/F2      |
| 6    | Ins         | [6,7]      | 0x90     | 0x30/F2      | 0x40/F2      | 0x50/F2      |
| 7    | Home        | [6,8]      | 0x91     | 0x31/F2      | 0x41/F2      | 0x51/F2      |
| 8    | PgUp        | [6,9]      | 0x92     | 0x32/F2      | 0x42/F2      | 0x52/F2      |
| 9    | NumLk       | [1,13]     | 0x93     | 0x33/F2      | 0x43/F2      | 0x53/F2      |
| 10   | KP/         | [1,14]     | 0x94     | 0x34/F2      | 0x44/F2      | 0x54/F2      |
| 11   | KP*         | [1,15]     | 0x95     | 0x35/F2      | 0x45/F2      | 0x55/F2      |
| 12   | KP-         | [6,13]     | 0x96     | 0x36/F2      | 0x46/F2      | 0x56/F2      |
| 13   | Del         | [6,10]     | 0x98     | 0x38/F2      | 0x48/F2      | 0x58/F2      |
| 14   | End         | [6,11]     | 0x60     | 0x80/F1      | 0x90/F1      | 0x20/F2      |
| 15   | PgDn        | [6,12]     | 0x61     | 0x81/F1      | 0x91/F1      | 0x21/F2      |
| 16   | KP7         | [2,13]     | 0x62     | 0x82/F1      | 0x92/F1      | 0x22/F2      |
| 17   | KP8         | [2,14]     | 0x63     | 0x83/F1      | 0x93/F1      | 0x23/F2      |
| 18   | KP9         | [2,15]     | 0x64     | 0x84/F1      | 0x94/F1      | 0x24/F2      |
| 19   | KP+         | [6,14]     | 0x65     | 0x85/F1      | 0x95/F1      | 0x25/F2      |
| 20   | \ (ANSI) # (ISO)     | [3,12]     | 0x97     | 0x37/F2      | 0x47/F2      | 0x57/F2      |
| 21   | KP4         | [3,13]     | 0x30     | 0x50/F1      | 0x60/F1      | 0x70/F1      |
| 22   | KP5         | [3,14]     | 0x31     | 0x51/F1      | 0x61/F1      | 0x71/F1      |
| 23   | KP6         | [3,15]     | 0x32     | 0x52/F1      | 0x62/F1      | 0x72/F1      |
| 24   | Up          | [5,10]     | 0x36     | 0x56/F1      | 0x66/F1      | 0x76/F1      |
| 25   | KP1         | [4,13]     | 0x37     | 0x57/F1      | 0x67/F1      | 0x77/F1      |
| 26   | KP2         | [4,14]     | 0x38     | 0x58/F1      | 0x68/F1      | 0x78/F1      |
| 27   | KP3         | [4,15]     | 0x39     | 0x59/F1      | 0x69/F1      | 0x79/F1      |
| 28   | KP Enter    | [5,15]     | 0x3A     | 0x5A/F1      | 0x6A/F1      | 0x7A/F1      |
| 29   | LCtrl       | [5,0]      | 0x03     | 0x23/F1      | 0x33/F1      | 0x43/F1      |
| 30   | Win         | [5,1]      | 0x04     | 0x24/F1      | 0x34/F1      | 0x44/F1      |
| 31   | LAlt        | [5,2]      | 0x05     | 0x25/F1      | 0x35/F1      | 0x45/F1      |
| 32   | Space       | [5,3]      | 0x07     | 0x27/F1      | 0x37/F1      | 0x47/F1      |
| 33   | RAlt        | [5,4]      | 0x09     | 0x29/F1      | 0x39/F1      | 0x49/F1      |
| 34   | FN          | [5,5]      | 0x0A     | 0x2A/F1      | 0x3A/F1      | 0x4A/F1      |
| 35   | Menu        | [5,6]      | 0x0B     | 0x2B/F1      | 0x3B/F1      | 0x4B/F1      |
| 36   | RCtrl       | [5,7]      | 0x0D     | 0x2D/F1      | 0x3D/F1      | 0x4D/F1      |
| 37   | Left        | [5,8]      | 0x0E     | 0x2E/F1      | 0x3E/F1      | 0x4E/F1      |
| 38   | Down        | [5,9]      | 0x0F     | 0x2F/F1      | 0x3F/F1      | 0x4F/F1      |
| 39   | Right       | [5,11]     | 0x3B     | 0x5B/F1      | 0x6B/F1      | 0x7B/F1      |
| 40   | KP0         | [5,13]     | 0x3C     | 0x5C/F1      | 0x6C/F1      | 0x7C/F1      |
| 41   | KP.         | [5,14]     | 0x3D     | 0x5D/F1      | 0x6D/F1      | 0x7D/F1      |

### Chip 1 (I2C addr 0xEE, ADDR=VDDIO) — 63 LEDs

F1–F10, main alpha block, mods, arrows.

The first 104 LEDs (indices 0–103) are identical between ISO and ANSI variants.  
LED\# 104 is ISO-only (`\` at [6,2]), absent in ANSI.

| LED# | Key         | [row,col]  | Combined | R addr/frame | G addr/frame | B addr/frame |
|------|-------------|------------|----------|--------------|--------------|--------------|
| 42   | Esc         | [0,0]      | 0xC0     | 0x60/F2      | 0x70/F2      | 0x80/F2      |
| 43   | F1          | [0,1]      | 0xC1     | 0x61/F2      | 0x71/F2      | 0x81/F2      |
| 44   | F2          | [0,2]      | 0xC2     | 0x62/F2      | 0x72/F2      | 0x82/F2      |
| 45   | F3          | [0,3]      | 0xC3     | 0x63/F2      | 0x73/F2      | 0x83/F2      |
| 46   | F4          | [0,4]      | 0xC4     | 0x64/F2      | 0x74/F2      | 0x84/F2      |
| 47   | F5          | [0,5]      | 0xC5     | 0x65/F2      | 0x75/F2      | 0x85/F2      |
| 48   | F6          | [0,6]      | 0xC6     | 0x66/F2      | 0x76/F2      | 0x86/F2      |
| 49   | F7          | [0,7]      | 0xC7     | 0x67/F2      | 0x77/F2      | 0x87/F2      |
| 50   | F8          | [0,8]      | 0xC8     | 0x68/F2      | 0x78/F2      | 0x88/F2      |
| 51   | F9          | [0,9]      | 0xC9     | 0x69/F2      | 0x79/F2      | 0x89/F2      |
| 52   | F10         | [0,10]     | 0xCA     | 0x6A/F2      | 0x7A/F2      | 0x8A/F2      |
| 53   | `           | [1,0]      | 0x90     | 0x30/F2      | 0x40/F2      | 0x50/F2      |
| 54   | 1           | [1,1]      | 0x91     | 0x31/F2      | 0x41/F2      | 0x51/F2      |
| 55   | 2           | [1,2]      | 0x92     | 0x32/F2      | 0x42/F2      | 0x52/F2      |
| 56   | 3           | [1,3]      | 0x93     | 0x33/F2      | 0x43/F2      | 0x53/F2      |
| 57   | 4           | [1,4]      | 0x94     | 0x34/F2      | 0x44/F2      | 0x54/F2      |
| 58   | 5           | [1,5]      | 0x95     | 0x35/F2      | 0x45/F2      | 0x55/F2      |
| 59   | 6           | [1,6]      | 0x96     | 0x36/F2      | 0x46/F2      | 0x56/F2      |
| 60   | 7           | [1,7]      | 0x97     | 0x37/F2      | 0x47/F2      | 0x57/F2      |
| 61   | 8           | [1,8]      | 0x98     | 0x38/F2      | 0x48/F2      | 0x58/F2      |
| 62   | 9           | [1,9]      | 0x9C     | 0x3C/F2      | 0x4C/F2      | 0x5C/F2      |
| 63   | 0           | [1,10]     | 0x9D     | 0x3D/F2      | 0x4D/F2      | 0x5D/F2      |
| 64   | -           | [1,11]     | 0x9E     | 0x3E/F2      | 0x4E/F2      | 0x5E/F2      |
| 65   | =           | [1,12]     | 0x9F     | 0x3F/F2      | 0x4F/F2      | 0x5F/F2      |
| 66   | Tab         | [2,0]      | 0x60     | 0x80/F1      | 0x90/F1      | 0x20/F2      |
| 67   | Q           | [2,1]      | 0x61     | 0x81/F1      | 0x91/F1      | 0x21/F2      |
| 68   | W           | [2,2]      | 0x62     | 0x82/F1      | 0x92/F1      | 0x22/F2      |
| 69   | E           | [2,3]      | 0x63     | 0x83/F1      | 0x93/F1      | 0x23/F2      |
| 70   | R           | [2,4]      | 0x64     | 0x84/F1      | 0x94/F1      | 0x24/F2      |
| 71   | T           | [2,5]      | 0x65     | 0x85/F1      | 0x95/F1      | 0x25/F2      |
| 72   | Y           | [2,6]      | 0x69     | 0x89/F1      | 0x99/F1      | 0x29/F2      |
| 73   | U           | [2,7]      | 0x6A     | 0x8A/F1      | 0x9A/F1      | 0x2A/F2      |
| 74   | I           | [2,8]      | 0x6B     | 0x8B/F1      | 0x9B/F1      | 0x2B/F2      |
| 75   | O           | [2,9]      | 0x6C     | 0x8C/F1      | 0x9C/F1      | 0x2C/F2      |
| 76   | P           | [2,10]     | 0x6D     | 0x8D/F1      | 0x9D/F1      | 0x2D/F2      |
| 77   | [           | [2,11]     | 0x6E     | 0x8E/F1      | 0x9E/F1      | 0x2E/F2      |
| 78   | ]           | [2,12]     | 0x6F     | 0x8F/F1      | 0x9F/F1      | 0x2F/F2      |
| 79   | Enter       | [4,12]     | 0x3F     | 0x5F/F1      | 0x6F/F1      | 0x7F/F1      |
| 80   | Caps        | [3,0]      | 0x30     | 0x50/F1      | 0x60/F1      | 0x70/F1      |
| 81   | A           | [3,1]      | 0x31     | 0x51/F1      | 0x61/F1      | 0x71/F1      |
| 82   | S           | [3,2]      | 0x32     | 0x52/F1      | 0x62/F1      | 0x72/F1      |
| 83   | D           | [3,3]      | 0x36     | 0x56/F1      | 0x66/F1      | 0x76/F1      |
| 84   | F           | [3,4]      | 0x37     | 0x57/F1      | 0x67/F1      | 0x77/F1      |
| 85   | G           | [3,5]      | 0x38     | 0x58/F1      | 0x68/F1      | 0x78/F1      |
| 86   | H           | [3,6]      | 0x39     | 0x59/F1      | 0x69/F1      | 0x79/F1      |
| 87   | J           | [3,7]      | 0x3A     | 0x5A/F1      | 0x6A/F1      | 0x7A/F1      |
| 88   | K           | [3,8]      | 0x3B     | 0x5B/F1      | 0x6B/F1      | 0x7B/F1      |
| 89   | L           | [3,9]      | 0x3C     | 0x5C/F1      | 0x6C/F1      | 0x7C/F1      |
| 90   | ;           | [3,10]     | 0x3D     | 0x5D/F1      | 0x6D/F1      | 0x7D/F1      |
| 91   | '           | [3,11]     | 0x3E     | 0x5E/F1      | 0x6E/F1      | 0x7E/F1      |
| 92   | LShift      | [4,0]      | 0x03     | 0x23/F1      | 0x33/F1      | 0x43/F1      |
| 93   | Z           | [4,1]      | 0x05     | 0x25/F1      | 0x35/F1      | 0x45/F1      |
| 94   | X           | [4,2]      | 0x06     | 0x26/F1      | 0x36/F1      | 0x46/F1      |
| 95   | C           | [4,3]      | 0x07     | 0x27/F1      | 0x37/F1      | 0x47/F1      |
| 96   | V           | [4,4]      | 0x08     | 0x28/F1      | 0x38/F1      | 0x48/F1      |
| 97   | B           | [4,5]      | 0x09     | 0x29/F1      | 0x39/F1      | 0x49/F1      |
| 98   | N           | [4,6]      | 0x0A     | 0x2A/F1      | 0x3A/F1      | 0x4A/F1      |
| 99   | M           | [4,7]      | 0x0B     | 0x2B/F1      | 0x3B/F1      | 0x4B/F1      |
| 100  | ,           | [4,8]      | 0x0C     | 0x2C/F1      | 0x3C/F1      | 0x4C/F1      |
| 101  | .           | [4,9]      | 0x0D     | 0x2D/F1      | 0x3D/F1      | 0x4D/F1      |
| 102  | /           | [4,10]     | 0x0E     | 0x2E/F1      | 0x3E/F1      | 0x4E/F1      |
| 103  | RShift      | [4,11]     | 0x0F     | 0x2F/F1      | 0x3F/F1      | 0x4F/F1      |
| 104  | \ (ISO)     | [6,2]      | 0x04     | 0x24/F1      | 0x34/F1      | 0x44/F1      |
