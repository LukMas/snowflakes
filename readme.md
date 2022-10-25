# Introduction
Layout built over my previous keyboard, *icekeys*.
Kyria has almost the same layout except 2 extra thumb keys. The position of some keys in the lower row is a bit different, but overall it remembers my keyboard.
So, instead of starting again the whole process, I took the kyria. 

I've planned to use:
- rotary encoder: at first I've thought it would be really useful for scrolling, but reading around I've found the it scrolls where the mouse is. That means, I've anyway to take the mouse and move it around if I've left it in a different point of where I'm scrolling. 
- RBG leds: this is another extra. Being not a led matrix I can change the colors according to the layers, or something else, but not in relation to the single keypresses. 

---

## Layers
- **QWERTY:** The default layout
- **NUMBERS:** To access numbers and symbols.
- **FUNCTION:** To access function keys.
- **MEDIA&NAVI:** Media and navigation keys (maybe also led controls)


## Usage of extra features
### OLEDs
I've took 2 OLED displays. They are a kind of extra, it is just to have them and show some information over.
### Left one 
It would be nice to have a kind of anymation of the snowflakes, just to try. 
And, maybe under, a wpm counter, or something like this.
### Right one
Information about the current active layer. 
### LEDs
Default nothing, but with the option to activate some of the animations.
### Opportunities
- They could blink for a moment when the layers changes
- They could light up in different colors when a mod keys is pushed 
- I could activate an animatiion when is christmas time 



# Current Layers
- Base1: qwerty

Layer: BASE

,---------------------------------------------.                              ,---------------------------------------------.
|   Tab   |   -  |   -  |   -   |   -  |   -  |                              |   -  |   -  |   -   |   -  |   -  | Esc/Gui |
|---------+------+------+-------+------+------|                              |------+------+-------+------+------+---------|
| Ctrl/(  |   -  |   -  |   -   |   -  |   -  |                              |   -  |   -  |   -   |   -  |   -  | Ctrl/)  |
|---------+------+------+-------+------+------+-------------.  ,-------------+------+------+-------+------+------+---------|
| Shift/{ |   -  |   -  |   -   |   -  |   -  |KC_EQL| App  |  | Ins  |KC_MIN|   -  |   -  |   -   |   -  |   -  | Shift/} |
`-----------------------+-------+------+------+------+------|  |------+------+------+------+-------+-----------------------'
                        | LAlt/ | NUMB | Space| DEL  |MEDIA |  |MOUSE | Bcksp| Enter| FUNC | RAlt/ |
                        |   [   |      |      |      |      |  |      |      |      |      |   ]   |
                         -----------------------------------    -----------------------------------
                           
Layer: NUMB

,---------------------------------------------.                              ,---------------------------------------------.
|  Tab    |   -  |   -  |   -   |  `/~ |  |   |                              |  &   | '/"  |   -   |   -  |   -  |   Esc   |
|---------+------+------+-------+------+------|                              |------+------+-------+------+------+---------|
| Ctrl/(  | 1/!  | 2/@  |  3/#  | 4/$  | 5/%  |                              | 6/^  | 7/&  |  8/*  | 9/(  | 0/)  | Ctrl/)  |
|---------+------+------+-------+------+------+-------------.  ,-------------+------+------+-------+------+------+---------|
| Shift/{ |   -  |   -  |   -   |   -  |   -  |  NO  |  NO  |  |  NO  |  NO  |   -  |   -  |   -   |   -  |   -  | Shift/} |
`-----------------------+-------+------+------+------+------|  |------+------+------+------+-------+-----------------------'
                        | LAlt  |Shift | Ctrl | RAlt |         |  NO  |  NO  |  NO  | ---- |  NO   |
                        |       |      |      |      |      |  |      |      |      |      |       |
                         -----------------------------------    -----------------------------------
                           
Layer: FUNC

,---------------------------------------------.                              ,---------------------------------------------.
|  Tab    |  NO  |  F9  |  F10  |  F12 | APP  |                              | GUI  |  F4  |  F5   |  F6  |  NO  |  Esc    |
|---------+------+------+-------+------+------|                              |------+------+-------+------+------+---------|
|  Ctrl   |  NO  |  F7  |  F8   |  F9  | PgUp |                              | HOME |  F1  |  F2   |  F3  |  NO  |  Ctrl   |
|---------+------+------+-------+------+------+-------------.  ,-------------+------+------+-------+------+------+---------|
|  Shift  |  NO  |  UP  |  NO   |  DW  | PgDw |  NO  |  NO  |  |  NO  |  NO  | END  | LEFT |  NO   |RIGHT |  NO  |  Shift  |
`-----------------------+-------+------+------+------+------|  |------+------+------+------+-------+-----------------------'
                        |  NO   | ---- |  NO  |  NO  |  NO  |  |  NO  | LAlt | Ctrl |Shift | RAlt  |
                        |       |      |      |      |      |  |      |      |      |      |       |
                         -----------------------------------    -----------------------------------
                           
Layer: MEDIA

,---------------------------------------------.                              ,---------------------------------------------.
|  Tab    |  NO  |  NO  | VOLU  |  NO  |  NO  |                              |  NO  |  H_I |  S_I  |  B_I |  NO  |  Esc    |
|---------+------+------+-------+------+------|                              |------+------+-------+------+------+---------|
|  Ctrl   |  NO  | PREV | VOLD  | NEXT |  NO  |                              |  NO  |  H_D |  S_D  |  B_D |  NO  |  Ctrl   |
|---------+------+------+-------+------+------+-------------.  ,-------------+------+------+-------+------+------+---------|
|  Shift  |  NO  |  NO  | MUTE  |  NO  |  NO  |  NO  |  NO  |  |  NO  |  NO  |  NO  |  NO  |  NO   |  NO  |  NO  |  Shift  |
`-----------------------+-------+------+------+------+------|  |------+------+------+------+-------+-----------------------'
                        |  NO   |  NO  |  NO  |  NO  | ---- |  |  NO  |RGB_T |RBG_F |RGB_R |  NO   |
                        |       |      |      |      |      |  |      |      |      |      |       |
                         -----------------------------------    -----------------------------------
                           
Layer: MOUSE

,---------------------------------------------.                              ,---------------------------------------------.
|   Tab   |  NO  |  NO  | MS_UP |  NO  |ACC_1 |                              |  NO  |  NO  | WH_UP |  NO  |  NO  |  Esc    |
|---------+------+------+-------+------+------|                              |------+------+-------+------+------+---------|
| Ctrl    |  NO  |MS_LF | MS_DW |MS_RG |ACC_2 |                              |  NO  |WH_LF | WH_DW |WH_RG |  NO  | Ctrl    |
|---------+------+------+-------+------+------+-------------.  ,-------------+------+------+-------+------+------+---------|
| Shift   |  NO  |  NO  |  NO   |  NO  |ACC_3 |  NO  |  NO  |  |  NO  |  NO  |  NO  |  NO  |  NO   |  NO  |  NO  | Shift   |
`-----------------------+-------+------+------+------+------|  |------+------+------+------+-------+-----------------------'
                        |  NO   |LF_CK |MD_CK |RG_CK |  NO  |  | ---- | Ctrl |Shift | LAlt | RAlt |
                        |       |      |      |      |      |  |      |      |      |      |       |
                         -----------------------------------    -----------------------------------
                                                      

\


# Helpful Links

- QMK Docs https://docs.qmk.fm/#/
- [Keymap diagram editor for the Kyria](http://www.keyboard-layout-editor.com/##@_name=Kyria%3B&@_y:0.25&x:3&a:7%3B&=&_x:9%3B&=%3B&@_y:-0.75&x:2%3B&=&_x:1%3B&=&_x:7%3B&=&_x:1%3B&=%3B&@_y:-0.875&x:5%3B&=&_x:5%3B&=%3B&@_y:-0.625%3B&=&=&_x:13%3B&=&=%3B&@_y:-0.75&x:3%3B&=&_x:9%3B&=%3B&@_y:-0.75&x:2%3B&=&_x:1%3B&=&_x:7%3B&=&_x:1%3B&=%3B&@_y:-0.875&x:5%3B&=&_x:5%3B&=%3B&@_y:-0.625%3B&=&=&_x:13%3B&=&=%3B&@_y:-0.75&x:3%3B&=&_x:9%3B&=%3B&@_y:-0.75&x:2%3B&=&_x:1%3B&=&_x:7%3B&=&_x:1%3B&=%3B&@_y:-0.875&x:5%3B&=&_x:5%3B&=%3B&@_y:-0.625%3B&=&=&_x:13%3B&=&=%3B&@_y:-0.5&x:2.5%3B&=&_x:10%3B&=%3B&@_rx:4&ry:8.175&y:-4.675000000000001&x:-0.5%3B&=%3B&@_rx:13&y:-4.675000000000001&x:-0.5%3B&=%3B&@_r:15&rx:4&y:-4.675000000000001&x:-0.5%3B&=%3B&@_r:30&y:-2&x:-0.5%3B&=%3B&@_x:-0.5%3B&=%3B&@_r:45&y:-2&x:-0.5%3B&=%3B&@_x:-0.5%3B&=%3B&@_r:-45&rx:13&y:-5.675000000000001&x:-0.5%3B&=%3B&@_x:-0.5%3B&=%3B&@_r:-30&y:-2&x:-0.5%3B&=%3B&@_x:-0.5%3B&=%3B&@_r:-15&y:-1&x:-0.5%3B&=)
- [Thomas' Guide for creating OLED images](https://docs.splitkb.com/hc/en-us/articles/360013811280)
- [Image converter](https://javl.github.io/image2cpp/)

---

## Useful notes
Various useful info for setting up your own keyboard layout.


---
### Layer template
```
//  * ,-------------------------------------------.                              ,-------------------------------------------.
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
//  * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        `----------------------------------'  `----------------------------------'
//  */
//     [_LAYERINDEX] = LAYOUT(
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
//                                  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
//     ),
```

