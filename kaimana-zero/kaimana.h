//  kaimana.h
//
//  Copyright 2013 Paradise Arcade Shop, ParadiseArcadeShop.com
//  All rights reserved.  Use is subject to license terms.
//
//  Code is provided for entertainment purposes and use with the Kaimana controller.
//  Code may be copied, modified, resused with this Copyright notice.
//  No commercial use without written permission from Paradise Arcade Shop.
//
//  Paradise Arcade Shop Kaimana LED Driver Board
//  Initial Release October 15, 2013
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
//  THE SOFTWARE.
//
//  Kaimana class based on original source released by ParadiseArcadeShop.com October 15, 2013
//
//  Created:  October 24, 2013    zonbipanda // gmail.com  -- Arduino 1.0.5 Support
//  Revised:  October 29, 2013    zonbipanda // gmail.com
//  Revised:  April   11, 2015    zonbipanda // gmail.com  -- Arduino 1.6.3 Support
//  Revised:  Nov     15, 2023    Paul 'pod' Denning -- Bug fixes, New j4/joystick pcb support, code cleanup, improved combo detection
//  Revised:  Mar     07, 2024    Paul 'pod' Denning -- Added static colour option for idle mode. Added fixed colour option for pressed mode. Added hold Idle colour instead of instant black for non-pressed. Can be tailored to be different for each character.
//  Revised:  Oct     25, 2024    Paul 'pod' Denning -- Fixed 2 overflow errors, fixed incorrect idle exit when not using leds on all buttons. Added Terry and Akuma characters
//

#ifndef __kaimana_h__
#define __kaimana_h__

#define __PROG_TYPES_COMPAT__
#include <avr/io.h>
#include <avr/pgmspace.h>
#include "Arduino.h"

// Map function names to arduino leonardo atmega32u4 digital pin numbers
// specific to ParadiseArcadeShop.com Kaimana board (PS360+LED)
#define  PIN_DOWN    11
#define  PIN_UP      18
#define  PIN_LEFT    19
#define  PIN_RIGHT   20
#define  PIN_HOME    8
#define  PIN_GUIDE   8
#define  PIN_SELECT  9
#define  PIN_BACK    9
#define  PIN_START   10
#define  PIN_P1      3
#define  PIN_P2      2
#define  PIN_P3      0
#define  PIN_P4      1
#define  PIN_K1      4
#define  PIN_K2      21
#define  PIN_K3      12
#define  PIN_K4      6
//
#define  PIN_LED     23

#define BUTTON_READ_CHECK LOW

//possible input types for gameplay and combo matching
//combo detection requires attack buttons be grouped together
enum EInputTypes:uint8_t
{
  EIT_INPUT_NONE,
  EIT_Input_Up,
  EIT_Input_UpLeft,
  EIT_Input_Left,
  EIT_Input_DownLeft,
  EIT_Input_Down,
  EIT_Input_DownRight,
  EIT_Input_Right,
  EIT_Input_UpRight,
  EIT_Input_FirstAttackButton,
  EIT_Input_P1 = EIT_Input_FirstAttackButton,
  EIT_Input_P2,
  EIT_Input_P3,
  EIT_Input_P4,
  EIT_Input_K1,
  EIT_Input_K2,
  EIT_Input_K3,
  EIT_Input_K4,
  EIT_Input_LastAttackButton = EIT_Input_K4,
  EIT_INPUT_MAX,
};

//shared input arrays
const EInputTypes P1Array[1] = {EIT_Input_P1};
const EInputTypes P2Array[1] = {EIT_Input_P2};
const EInputTypes P3Array[1] = {EIT_Input_P3};
const EInputTypes K1Array[1] = {EIT_Input_K1};
const EInputTypes K2Array[1] = {EIT_Input_K2};
const EInputTypes K3Array[1] = {EIT_Input_K3};

enum EIdleType:uint8_t
{
  EIT_RainbowCircling,
  EIT_RainbowPulsing,
  EIT_StaticColour,
  EIT_StaticColourPulsing,
  EIT_StaticColourCirclePulse,
  EIT_StaticColourCircleDualPulse,
  EIT_StaticColourPingPongPulse,
  EIT_Disabled,
};

// number of switch inputs on kaimana
#define  SWITCH_COUNT         15

// This should be plenty. double 360 would need 17. So double that for safety
#define SWITCH_HISTORY_MAX  24

// basic color definitions with various R,G,B values
// generic (may  want to prefix with COLOR_* to localize further)
#define  BLACK     000,000,000
#define  RED       255,000,000
#define  MAROON    128,0,0
#define  FIREBRICK 178,34,34
#define  MAGENTA   255,000,255
#define  GREEN     000,255,000
#define  NEONGREEN 57,255,20
#define  YELLOW    255,255,000
#define  BLUE      000,000,255
#define  DARKBLUE  000,000,100
#define  PURPLE    255,000,255
#define  CYAN      000,255,255
#define  WHITE     255,255,255
#define  ORANGE    220,127,0
#define  GOLD      255,150,0
#define  BROWN     240,230,140
#define  GREY      127,127,127
#define  DARKGREY  60,60,60
#define  BEIGE     245,245,220




// RGB value structure.
typedef struct __attribute__ ((__packed__)) {
    uint8_t r;
    uint8_t g;
    uint8_t b;
} RGB_t;

// Input History structure.
typedef struct __attribute__ ((__packed__)) {
    EInputTypes Input;
    unsigned long TimeSet;
    unsigned long TimeReleased;
    bool bIsHeld;
} InputHistory;

// Input Blend structure.
typedef struct __attribute__ ((__packed__)) {
    unsigned long TimeSet = 0;
    int TimeToHold = 0;
    int TimeToBlend = 0;
    uint8_t LEDPin;
    RGB_t SourceCol;
    RGB_t DestCol;
} LEDBlend;

// table of switch pin numbers
const unsigned char switchPins[SWITCH_COUNT] = { PIN_DOWN, PIN_UP, PIN_LEFT, PIN_RIGHT, PIN_HOME, PIN_SELECT, PIN_START, PIN_P1, PIN_P2, PIN_P3, PIN_P4, PIN_K1, PIN_K2, PIN_K3, PIN_K4 };

//Inlcude this here so that all the above can be used in the custom.h. We only need it for the LED_COUNT define anyway
#include "kaimana_custom.h"

// define the Kaimana class
//
class Kaimana
{
  private:
    // declare RGB array for 15 buttons --> 12 LEDs
    // specific to ParadiseArcadeShop.com Kaimana board (PS360+LED)
    RGB_t    _led[LED_COUNT];
    InputHistory _switchHistory[SWITCH_HISTORY_MAX];
    bool _InputsThisFrame[EIT_INPUT_MAX];
    bool _switchClearAwaitingAllRelease = false;
    unsigned long _timeAtBeginningOfFrame = 0;
    LEDBlend _ledBlend[LED_ENTRIES];

    //Helper functions
    void switchHistoryCreateNew(EInputTypes newValue);
 
 public:
    Kaimana(void);
    bool    blendLEDs(bool bForceEnd = false);
    void    setLED(int index, int iR, int iG, int iB, bool bIsBlend = false, int holdTime = 0, int fadeTime = 0);
    void    setIndividualLED(int index, int iR, int iG, int iB);
    void    setALL(int iR, int iG, int iB);
    void    updateALL(void);
    void    switchHistoryClear(void);
    void    switchHistoryBeginFrame(void);
    void    switchHistorySet(EInputTypes latestValue);
    void    switchHistoryEndFrame(void);
    boolean switchHistoryTest(const EInputTypes* moveArray, int moveLength, const EInputTypes* triggerArray, int triggerLength, bool bIsChargeCombo);
};


// prototypes for Kaimana functions
// specific to ParadiseArcadeShop.com Kaimana board (PS360+LED)
void 	setLED(int index, int iR, int iG, int iB);
void 	setALL(int iR, int iG, int iB);
void 	updateALL(void);
void 	switchHistoryClear(void);
void 	switchHistorySet(uint16_t latestValue);
boolean switchHistoryTest( EInputTypes* comboArray, int comboLength, bool bIsChargeCombo);

#endif
