// Customize Kaimana settings here

#ifndef __kaimana_local_h__
#define __kaimana_local_h__

#define __PROG_TYPES_COMPAT__
#include <avr/io.h>
#include <avr/pgmspace.h>
#include "Arduino.h"
#include "kaimana.h"



#define  _LED_ORDER_FULL





///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// START COMMON USER VARS THAT NEED SETTING ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////





// Use this for J4's on your buttons
//#define LED_PER_BUTTON 4
// Use this for J2's on your buttons
#define LED_PER_BUTTON 2

//Use this if using J2's for leverless buttons
#define LED_PER_JOYSTICK_DIRECTION 2
//Use this if using J4's for leverless buttons or the new Arcade Paradise 16 LED stick controller
//#define LED_PER_JOYSTICK_DIRECTION 4

//If this is true then when you press a diagonal on the joystick it will light 4 lights in the diagonal instead of lighting both cardinal directions (for a total of 8 leds)
#define USING_JOYSTICK_LED_PCB_AND_WANT_PROPER_DIAGONALS false

//Set Led order here. The gap between each button/direction should match the numbers you just set above.


//LEVERLESS BUTTON ORDER
#ifdef _LED_ORDER_FULL
#define  LED_LEFT       0
#define  LED_DOWN       2
#define  LED_RIGHT      4
#define  LED_P1         6
#define  LED_P2         8 
#define  LED_P3         10
#define  LED_P4         12
#define  LED_K4         14
#define  LED_K3         16
#define  LED_K2         18
#define  LED_K1         20
#define  LED_UP         22

#define  LED_COUNT      24
#endif

#define  LED_ENTRIES         24 // should match the unique entries above (i.e the ones that arent 0xFF) (and thus array size below)
//List all buttons that have LED's on them here. NOTE: Order here specifies the idle type "Circle pulse" order. If you have leverless and a jump button where your thumb is then you should swap the positions of up and down. you may also want to move Left to the beginning of the list
const unsigned char ledList[LED_ENTRIES] = { LED_LEFT, LED_DOWN, LED_RIGHT, LED_P1, LED_P2, LED_P3, LED_P4, LED_K4, LED_K3, LED_K2, LED_K1, LED_UP };


/*   //J4UPDATE START
//LEVERLESS BUTTON ORDER (J4's)
#ifdef _LED_ORDER_FULL
#define  LED_LEFT       0
#define  LED_DOWN       4
#define  LED_RIGHT      8
#define  LED_P1         12
#define  LED_P2         16 
#define  LED_P3         20
#define  LED_P4         24
#define  LED_K4         28
#define  LED_K3         32
#define  LED_K2         36
#define  LED_K1         40
#define  LED_UP         44

#define  LED_COUNT      44
#endif

#define  LED_ENTRIES         44 // should match the unique entries above (i.e the ones that arent 0xFF) (and thus array size below)
//List all buttons that have LED's on them here. NOTE: Order here specifies the idle type "Circle pulse" order. If you have leverless and a jump button where your thumb is then you should swap the positions of up and down. you may also want to move Left to the beginning of the list
const unsigned char ledList[LED_ENTRIES] = { LED_LEFT, LED_DOWN, LED_RIGHT, LED_P1, LED_P2, LED_P3, LED_P4, LED_K4 LED_K3, LED_K2, LED_K1, LED_UP };
*/  //J4UPDATE END




//Which button to hold to enter tourney mode (turns off all lights and effects). The commented out version is an example where I dont have a home button so I want to use k4 but since thats already in ledList directly above then I set the led to shine here as 0xFF so its ignored.
#define PIN_TO_SWITCH_TO_TOURNEY_MODE PIN_HOME
#define PIN_TO_SWITCH_TO_TOURNEY_MODE_LED PIN_HOME
//#define PIN_TO_SWITCH_TO_TOURNEY_MODE PIN_K4
//#define PIN_TO_SWITCH_TO_TOURNEY_MODE_LED 0xFF




///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// END COMMON USER VARS THAT NEED SETTING /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////





///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// START RARE USER VARS THAT NEED SETTING /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////




//These are the 4 buttons you need to hold down to access character select. Probably only worth changing these if you dont have p4/k4 for some reason
#define PIN_TO_SWITCH_CHARACTER_1 PIN_P1 
#define PIN_TO_SWITCH_CHARACTER_2 PIN_P4 
#define PIN_TO_SWITCH_CHARACTER_3 PIN_K1 
#define PIN_TO_SWITCH_CHARACTER_4 PIN_K4 


#define IDLE_PULSE_SPEED   0.002  // how fast Static pulse should be (lower = slower)
#define IDLE_CIRCLEPULSE_SPEED   4  // how fast circle pulse should Travel (lower = slower). This must be a factor of 256 (so 1,2,4,8,16,32,64,128). I dont recommend going over 32


#define  IDLE_TIMEOUT_SECONDS       3    // value in seconds before the idle animation kicks in - normally 60 or 30 seconds but set very short for testing



///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// END RARE USER VARS THAT NEED SETTING ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



// general definitions for delays and other customizable features
// specific to ParadiseArcadeShop.com Kaimana board (PS360+LED)
#define  BOOT_COLOR_DELAY         200    // value in miliseconds
#define  FAST_COLOR_DELAY         150    // value in miliseconds
#define  BOOT_COMPLETE_DELAY      500    // value in miliseconds
#define  MIN_LED_UPDATE_DELAY       5    // value in miliseconds - Gives kaimana/leds time to update correctly - Recommended you dont go below 5 or kaimana/leds cant update fast enough and will glitch
#define  T_DELAY      			  250    

// definitions of RGB values use by random color generator: setLEDRandomColor(int)
#define  COLOR_RANDOM_1    127,220,000    // lime green
#define  COLOR_RANDOM_2    127,000,220    // purple
#define  COLOR_RANDOM_3    000,220,220    // blue
#define  COLOR_RANDOM_4    000,255,127    // cyan
#define  COLOR_RANDOM_5    000,127,255    // cobalt blue
#define  COLOR_RANDOM_6    255,000,000    // red
#define  COLOR_RANDOM_7    220,127,000    // orange
#define  COLOR_RANDOM_8    220,000,127    // magenta
#define  COLOR_RANDOM_9	   177,037,075	
#define  NUM_RANDOM_COLORS 9
const RGB_t randomColors[NUM_RANDOM_COLORS] = { COLOR_RANDOM_1, COLOR_RANDOM_2, COLOR_RANDOM_3, COLOR_RANDOM_4, COLOR_RANDOM_5, COLOR_RANDOM_6, COLOR_RANDOM_7, COLOR_RANDOM_8, COLOR_RANDOM_9 };

// definitions for combo switch patterns
//
// These are some of the most common special move inputs. Feel free to add your own. Or add new shortcut versions as required.
// To add special moves to a character see Ryu.cpp as an example

#define COMBO_INPUT_TIME_WINDOW 200 //Maximum time between combo movements that arent a charge
#define COMBO_TRIGGER_INPUT_TIME_WINDOW 125 //Maximum time between combined button inputs eg PP, PPP, KK or PK etc
#define CHARGE_COMBO_INPUT_TIME_WINDOW 750 //How long the first direction of a charge move needs to be held - sf6 is mostly 40-45 frames = 670-750ms
#define COMBO_INPUT_COUNT_FOR_ONE_OUT_OF_TWO 7 //if the combo input is 7 or more moves then the input system will allow you to succeed if you dont miss 2 in a row window. eg LDRU would be fine for a SPD

#define QUARTERCIRCLE_INPUT_COUNT 3
const EInputTypes COMBO_QUARTERCIRCLE_RIGHT[QUARTERCIRCLE_INPUT_COUNT] PROGMEM = { EIT_Input_Down, EIT_Input_DownRight, EIT_Input_Right };
const EInputTypes COMBO_QUARTERCIRCLE_LEFT[QUARTERCIRCLE_INPUT_COUNT] PROGMEM = { EIT_Input_Down, EIT_Input_DownLeft, EIT_Input_Left };

#define HALFCIRCLE_INPUT_COUNT 5
const EInputTypes COMBO_HALFCIRCLE_RIGHT[HALFCIRCLE_INPUT_COUNT] PROGMEM = { EIT_Input_Left, EIT_Input_DownLeft, EIT_Input_Down, EIT_Input_DownRight, EIT_Input_Right };
const EInputTypes COMBO_HALFCIRCLE_LEFT[HALFCIRCLE_INPUT_COUNT] PROGMEM = { EIT_Input_Right, EIT_Input_DownRight, EIT_Input_Down, EIT_Input_DownLeft, EIT_Input_Left };

#define DP_INPUT_COUNT 3
const EInputTypes COMBO_DP_RIGHT[DP_INPUT_COUNT] PROGMEM = { EIT_Input_Right, EIT_Input_Down, EIT_Input_DownRight };
const EInputTypes COMBO_DP_LEFT[DP_INPUT_COUNT] PROGMEM = { EIT_Input_Left, EIT_Input_Down, EIT_Input_DownLeft };

#define DOUBLE_QUARTERCIRCLE_INPUT_COUNT 6
const EInputTypes COMBO_DOUBLE_QUARTERCIRCLE_RIGHT[DOUBLE_QUARTERCIRCLE_INPUT_COUNT] PROGMEM = { EIT_Input_Down, EIT_Input_DownRight, EIT_Input_Right, EIT_Input_Down, EIT_Input_DownRight, EIT_Input_Right };
const EInputTypes COMBO_DOUBLE_QUARTERCIRCLE_LEFT[DOUBLE_QUARTERCIRCLE_INPUT_COUNT] PROGMEM = { EIT_Input_Down, EIT_Input_DownLeft, EIT_Input_Left, EIT_Input_Down, EIT_Input_DownLeft, EIT_Input_Left };

#define DOUBLE_DOWN_INPUT_COUNT 2
const EInputTypes COMBO_DOUBLE_DOWN[DOUBLE_DOWN_INPUT_COUNT] PROGMEM = { EIT_Input_Down, EIT_Input_Down };

#define CHARGE_INPUT_COUNT 2
const EInputTypes COMBO_CHARGE_RIGHT_LEFT[CHARGE_INPUT_COUNT] PROGMEM = { EIT_Input_Right, EIT_Input_Left };
const EInputTypes COMBO_CHARGE_LEFT_RIGHT[CHARGE_INPUT_COUNT] PROGMEM = { EIT_Input_Left, EIT_Input_Right };

const EInputTypes COMBO_CHARGE_DOWN_UP[CHARGE_INPUT_COUNT] PROGMEM = { EIT_Input_Down, EIT_Input_Up };

#define CHARGE_SUPER_INPUT_COUNT 4
const EInputTypes COMBO_CHARGE_SUPER_RIGHT_LEFT[CHARGE_SUPER_INPUT_COUNT] PROGMEM = { EIT_Input_Right, EIT_Input_Left, EIT_Input_Right, EIT_Input_Left };
const EInputTypes COMBO_CHARGE_SUPER_LEFT_RIGHT[CHARGE_SUPER_INPUT_COUNT] PROGMEM = { EIT_Input_Left, EIT_Input_Right, EIT_Input_Left, EIT_Input_Right };

#define TWOSEVENTY_INPUT_COUNT 7 //triggers a 360 in street fighter
const EInputTypes COMBO_270_LEFT_CLOCKWISE[TWOSEVENTY_INPUT_COUNT] PROGMEM =      { EIT_Input_Left, EIT_Input_UpLeft, EIT_Input_Up, EIT_Input_UpRight, EIT_Input_Right, EIT_Input_DownRight, EIT_Input_Down };
const EInputTypes COMBO_270_UP_CLOCKWISE[TWOSEVENTY_INPUT_COUNT] PROGMEM =        { EIT_Input_Up, EIT_Input_UpRight, EIT_Input_Right, EIT_Input_DownRight, EIT_Input_Down, EIT_Input_DownLeft, EIT_Input_Left };
const EInputTypes COMBO_270_RIGHT_CLOCKWISE[TWOSEVENTY_INPUT_COUNT] PROGMEM =     { EIT_Input_Right, EIT_Input_DownRight, EIT_Input_Down, EIT_Input_DownLeft, EIT_Input_Left, EIT_Input_UpLeft, EIT_Input_Up };
const EInputTypes COMBO_270_DOWN_CLOCKWISE[TWOSEVENTY_INPUT_COUNT] PROGMEM =      { EIT_Input_Down, EIT_Input_DownLeft, EIT_Input_Left, EIT_Input_UpLeft, EIT_Input_Up, EIT_Input_UpRight, EIT_Input_Right };
const EInputTypes COMBO_270_LEFT_ANTICLOCKWISE[TWOSEVENTY_INPUT_COUNT] PROGMEM =  { EIT_Input_Left, EIT_Input_DownLeft, EIT_Input_Down, EIT_Input_DownRight, EIT_Input_Right, EIT_Input_UpRight, EIT_Input_Up };
const EInputTypes COMBO_270_UP_ANTICLOCKWISE[TWOSEVENTY_INPUT_COUNT] PROGMEM =    { EIT_Input_Up, EIT_Input_UpLeft, EIT_Input_Left, EIT_Input_DownLeft, EIT_Input_Down, EIT_Input_DownRight, EIT_Input_Right };
const EInputTypes COMBO_270_RIGHT_ANTICLOCKWISE[TWOSEVENTY_INPUT_COUNT] PROGMEM = { EIT_Input_Right, EIT_Input_UpRight, EIT_Input_Up, EIT_Input_UpLeft, EIT_Input_Left, EIT_Input_DownLeft, EIT_Input_Down };
const EInputTypes COMBO_270_DOWN_ANTICLOCKWISE[TWOSEVENTY_INPUT_COUNT] PROGMEM =  { EIT_Input_Down, EIT_Input_DownRight, EIT_Input_Right, EIT_Input_UpRight, EIT_Input_Up, EIT_Input_UpLeft, EIT_Input_Left };

#define SIXTHIRTY_INPUT_COUNT 15 //triggers a 720 in street fighter
const EInputTypes COMBO_630_LEFT_CLOCKWISE[SIXTHIRTY_INPUT_COUNT] PROGMEM =      { EIT_Input_Left, EIT_Input_UpLeft, EIT_Input_Up, EIT_Input_UpRight, EIT_Input_Right, EIT_Input_DownRight, EIT_Input_Down, EIT_Input_DownLeft, EIT_Input_Left, EIT_Input_UpLeft, EIT_Input_Up, EIT_Input_UpRight, EIT_Input_Right, EIT_Input_DownRight, EIT_Input_Down };
const EInputTypes COMBO_630_UP_CLOCKWISE[SIXTHIRTY_INPUT_COUNT] PROGMEM =        { EIT_Input_Up, EIT_Input_UpRight, EIT_Input_Right, EIT_Input_DownRight, EIT_Input_Down, EIT_Input_DownLeft, EIT_Input_Left, EIT_Input_UpLeft, EIT_Input_Up, EIT_Input_UpRight, EIT_Input_Right, EIT_Input_DownRight, EIT_Input_Down, EIT_Input_DownLeft, EIT_Input_Left };
const EInputTypes COMBO_630_RIGHT_CLOCKWISE[SIXTHIRTY_INPUT_COUNT] PROGMEM =     { EIT_Input_Right, EIT_Input_DownRight, EIT_Input_Down, EIT_Input_DownLeft, EIT_Input_Left, EIT_Input_UpLeft, EIT_Input_Up, EIT_Input_UpRight, EIT_Input_Right, EIT_Input_DownRight, EIT_Input_Down, EIT_Input_DownLeft, EIT_Input_Left, EIT_Input_UpLeft, EIT_Input_Up };
const EInputTypes COMBO_630_DOWN_CLOCKWISE[SIXTHIRTY_INPUT_COUNT] PROGMEM =      { EIT_Input_Down, EIT_Input_DownLeft, EIT_Input_Left, EIT_Input_UpLeft, EIT_Input_Up, EIT_Input_UpRight, EIT_Input_Right, EIT_Input_DownRight, EIT_Input_Down, EIT_Input_DownLeft, EIT_Input_Left, EIT_Input_UpLeft, EIT_Input_Up, EIT_Input_UpRight, EIT_Input_Right };
const EInputTypes COMBO_630_LEFT_ANTICLOCKWISE[SIXTHIRTY_INPUT_COUNT] PROGMEM =  { EIT_Input_Left, EIT_Input_DownLeft, EIT_Input_Down, EIT_Input_DownRight, EIT_Input_Right, EIT_Input_UpRight, EIT_Input_Up, EIT_Input_UpLeft, EIT_Input_Left, EIT_Input_DownLeft, EIT_Input_Down, EIT_Input_DownRight, EIT_Input_Right, EIT_Input_UpRight, EIT_Input_Up };
const EInputTypes COMBO_630_UP_ANTICLOCKWISE[SIXTHIRTY_INPUT_COUNT] PROGMEM =    { EIT_Input_Up, EIT_Input_UpLeft, EIT_Input_Left, EIT_Input_DownLeft, EIT_Input_Down, EIT_Input_DownRight, EIT_Input_Right, EIT_Input_UpRight, EIT_Input_Up, EIT_Input_UpLeft, EIT_Input_Left, EIT_Input_DownLeft, EIT_Input_Down, EIT_Input_DownRight, EIT_Input_Right };
const EInputTypes COMBO_630_RIGHT_ANTICLOCKWISE[SIXTHIRTY_INPUT_COUNT] PROGMEM = { EIT_Input_Right, EIT_Input_UpRight, EIT_Input_Up, EIT_Input_UpLeft, EIT_Input_Left, EIT_Input_DownLeft, EIT_Input_Down, EIT_Input_DownRight, EIT_Input_Right, EIT_Input_UpRight, EIT_Input_Up, EIT_Input_UpLeft, EIT_Input_Left, EIT_Input_DownLeft, EIT_Input_Down };
const EInputTypes COMBO_630_DOWN_ANTICLOCKWISE[SIXTHIRTY_INPUT_COUNT] PROGMEM =  { EIT_Input_Down, EIT_Input_DownRight, EIT_Input_Right, EIT_Input_UpRight, EIT_Input_Up, EIT_Input_UpLeft, EIT_Input_Left, EIT_Input_DownLeft, EIT_Input_Down, EIT_Input_DownRight, EIT_Input_Right, EIT_Input_UpRight, EIT_Input_Up, EIT_Input_UpLeft, EIT_Input_Left };

#define HELL_MURDER_INPUT_COUNT 3
const EInputTypes HELL_MURDER_INPUT_LEFT[HELL_MURDER_INPUT_COUNT] PROGMEM = { EIT_Input_P1, EIT_Input_P1, EIT_Input_Right };
const EInputTypes HELL_MURDER_INPUT_RIGHT[HELL_MURDER_INPUT_COUNT] PROGMEM = { EIT_Input_P1, EIT_Input_P1, EIT_Input_Left };

//Most trigger arrays are generated locally in the character but these are worth having global for ease of use
#define TRIPLEATTACK_TRIGGER_COUNT 3
const EInputTypes TRIGGER_PPP[TRIPLEATTACK_TRIGGER_COUNT] = { EIT_Input_P3, EIT_Input_P2, EIT_Input_P1 };
const EInputTypes TRIGGER_KKK[TRIPLEATTACK_TRIGGER_COUNT] = { EIT_Input_K3, EIT_Input_K2, EIT_Input_K1 };

//MUSHINSHA ADDITIONS
//Guilty Gear Overdrive Input
#define TYRANTRAVE_INPUT_COUNT 6  
const EInputTypes COMBO_TYRANTRAVE_RIGHT[TYRANTRAVE_INPUT_COUNT] PROGMEM = { EIT_Input_Left, EIT_Input_DownLeft, EIT_Input_Down, EIT_Input_DownRight, EIT_Input_Right, EIT_Input_Left };
const EInputTypes COMBO_TYRANTRAVE_LEFT[TYRANTRAVE_INPUT_COUNT] PROGMEM = { EIT_Input_Right, EIT_Input_DownRight, EIT_Input_Down, EIT_Input_DownLeft, EIT_Input_Left, EIT_Input_Right };

//King of Fighters/SNK Super Input
#define DEADLYRAVE_INPUT_COUNT 7
const EInputTypes COMBO_DEADLYRAVE_RIGHT[DEADLYRAVE_INPUT_COUNT] PROGMEM = { EIT_Input_Down, EIT_Input_DownRight, EIT_Input_Right, EIT_Input_DownRight, EIT_Input_Down, EIT_Input_DownLeft, EIT_Input_Left };
const EInputTypes COMBO_DEADLYRAVE_LEFT[DEADLYRAVE_INPUT_COUNT] PROGMEM = { EIT_Input_Down, EIT_Input_DownLeft, EIT_Input_Left, EIT_Input_DownLeft, EIT_Input_Down, EIT_Input_DownRight, EIT_Input_Right };

//The Famous Geese Howard "Pretzel"
#define RAGINGSTORM_INPUT_COUNT 7
const EInputTypes COMBO_RAGINGSTORM_RIGHT[RAGINGSTORM_INPUT_COUNT] PROGMEM = { EIT_Input_DownLeft, EIT_Input_Right, EIT_Input_DownRight, EIT_Input_Down, EIT_Input_DownLeft, EIT_Input_Left, EIT_Input_DownRight };
const EInputTypes COMBO_RAGINGSTORM_LEFT[RAGINGSTORM_INPUT_COUNT] PROGMEM = { EIT_Input_DownRight, EIT_Input_Left, EIT_Input_DownLeft, EIT_Input_Down, EIT_Input_DownRight, EIT_Input_Right, EIT_Input_DownLeft };

//Behemoth Typhoon (Goldlewis Dickenson special from Guilty Gear Strive)
#define BEHEMOTHTYPHOON_INPUT_COUNT 5
const EInputTypes COMBO_BEHEMOTHTYPHOON_CLOCKWISE_DOWN_TO_UP[BEHEMOTHTYPHOON_INPUT_COUNT] PROGMEM = { EIT_Input_Down, EIT_Input_DownLeft, EIT_Input_Left, EIT_Input_UpLeft, EIT_Input_Up};
const EInputTypes COMBO_BEHEMOTHTYPHOON_ANTICLOCKWISE_DOWN_TO_UP[BEHEMOTHTYPHOON_INPUT_COUNT] PROGMEM = { EIT_Input_Down, EIT_Input_DownRight, EIT_Input_Right, EIT_Input_UpRight, EIT_Input_Up};
const EInputTypes COMBO_BEHEMOTHTYPHOON_CLOCKWISE_UP_TO_DOWN[BEHEMOTHTYPHOON_INPUT_COUNT] PROGMEM = { EIT_Input_Up, EIT_Input_UpRight, EIT_Input_Right, EIT_Input_DownRight, EIT_Input_Down};
const EInputTypes COMBO_BEHEMOTHTYPHOON_ANTICLOCKWISE_UP_TO_DOWN[BEHEMOTHTYPHOON_INPUT_COUNT] PROGMEM = { EIT_Input_Up, EIT_Input_UpLeft, EIT_Input_Left, EIT_Input_DownLeft, EIT_Input_Down};

// data points for color cycling
//
const uint8_t colorCycleData[] PROGMEM = {
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,

    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,

    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,

    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,

    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,

    0,   2,   4,   6,   8,  10,  12,  14,  16,  18,  20,  22,  24,  26,  28,  30,
   32,  35,  38,  41,  44,  47,  50,  53,  56,  59,  62,  65,  68,  71,  74,  77,
   81,  85,  89,  93,  97, 101, 105, 109, 113, 117, 121, 125, 129, 133, 137, 141,
  148, 155, 162, 169, 176, 183, 190, 197, 204, 211, 218, 225, 232, 239, 246, 253,

  255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
  255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
  255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
  255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,

  255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
  255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
  255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
  255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,

  255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
  255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
  255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
  255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,

  255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
  255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
  255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
  255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,

  255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
  255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
  255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
  255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,

  253, 246, 239, 232, 225, 218, 211, 204, 197, 190, 183, 176, 169, 162, 155, 148,
  141, 137, 133, 129, 125, 121, 117, 113, 109, 105, 101,  97,  93,  89,  85,  81,
   77,  74,  71,  68,  65,  62,  59,  56,  53,  50,  47,  44,  41,  38,  35,  32,
   30,  28,  26,  24,  22,  20,  18,  16,  14,  12,  10,   8,   6,   4,   2,   0
};



#endif
