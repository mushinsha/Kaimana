//  Ino.cpp
//
//  Copyright 2023 Paradise Arcade Shop, ParadiseArcadeShop.com  
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
//  Kaimana Ino character combo checks and animation calls. First released by ParadiseArcadeShop.com November, 2023
//  Characters are added into the character selection array in the main ino file. See that for info on how characters are selected
//
//  Created:  April 2025 by Hunter "Mushinsha" Nelson
//

#define __PROG_TYPES_COMPAT__
#include <avr/io.h>
#include <avr/pgmspace.h>
#include <util/delay.h>
#include "kaimana.h"
#include "kaimana_custom.h"
#include "animations.h"
#include "Characters.h"

// Define combo sequences here and corresponding animations. Most complex moves should go first (eg, supers, ultras)
bool Ino::testForCharacterCombos() const
{
  
  //This is needed for PPP inputs
  EInputTypes P1P2Array[] = {EIT_Input_P1, EIT_Input_P2};
  EInputTypes P1P3Array[] = {EIT_Input_P1, EIT_Input_P3};
  EInputTypes P2P3Array[] = {EIT_Input_P2, EIT_Input_P3};

  //This is needed for KKK inputs
  EInputTypes K1K2Array[] = {EIT_Input_K1, EIT_Input_K2};
  EInputTypes K1K3Array[] = {EIT_Input_K1, EIT_Input_K3};
  EInputTypes K2K3Array[] = {EIT_Input_K2, EIT_Input_K3};

  //This is needed for Teleport inputs
  EInputTypes LeftArray[] = {EIT_Input_Left};
  EInputTypes RightArray[] = {EIT_Input_Right};

  //This is needed for Raging Demon
  EInputTypes P3K1Array[] = {EIT_Input_P3, EIT_Input_K1};

  
  //SUPERS
  //Double Quarter Circle Right [236236 + ATTACK]
  if( kaimana.switchHistoryTest( COMBO_DOUBLE_QUARTERCIRCLE_RIGHT, DOUBLE_QUARTERCIRCLE_INPUT_COUNT, P1Array, 1, false ) )
  {
    FlashAllSpeedIncreasing_Combo_Animation(WHITE);  
    return true;
  }
    
  //Double Quarter Circle Left [214214 + ATTACK]
  if( kaimana.switchHistoryTest( COMBO_DOUBLE_QUARTERCIRCLE_LEFT, DOUBLE_QUARTERCIRCLE_INPUT_COUNT, P1Array, 1, false ) )
  { 
    FlashAllSpeedIncreasing_Combo_Animation(WHITE);  
    return true;
  }


  //Guilty Gear Overdrive Input Right [632146 + ATTACK]
  if( kaimana.switchHistoryTest( COMBO_TYRANTRAVE_RIGHT, TYRANTRAVE_INPUT_COUNT, P1Array, 1, false ) )
  {
    FlashAllSpeedIncreasing_Combo_Animation(RED);
    FlashAllSpeedIncreasing_Combo_Animation(WHITE);
    FlashAllSpeedIncreasing_Combo_Animation(BLUE);   
    return true;
  }

  //Guilty Gear Overdrive Input Left [412364 + ATTACK]
  if( kaimana.switchHistoryTest( COMBO_TYRANTRAVE_LEFT, TYRANTRAVE_INPUT_COUNT, P1Array, 1, false ) )
  {
    FlashAllSpeedIncreasing_Combo_Animation(RED);
    FlashAllSpeedIncreasing_Combo_Animation(WHITE);
    FlashAllSpeedIncreasing_Combo_Animation(BLUE); 
    return true;
  }

  
  //King of Fighters Super Right [2363214 + ATTACK]
  if( kaimana.switchHistoryTest( COMBO_DEADLYRAVE_RIGHT, DEADLYRAVE_INPUT_COUNT, P1Array, 1, false ) )
  {
    FlashAllSpeedIncreasing_Combo_Animation(GOLD);
    return true;
  }

  //King of Fighters Super Left [2141236 + ATTACK]
  if( kaimana.switchHistoryTest( COMBO_DEADLYRAVE_LEFT, DEADLYRAVE_INPUT_COUNT, P1Array, 1, false ) )
  {
    FlashAllSpeedIncreasing_Combo_Animation(GOLD);
    return true;
  }

  
  //Geese Howard (Pretzel) Super Right [1632143 + ATTACK]
  if( kaimana.switchHistoryTest( COMBO_RAGINGSTORM_RIGHT, RAGINGSTORM_INPUT_COUNT, P1Array, 1, false ) )
  {
    WaveEffect_Combo_Animation(EFT_DownToUp, EFS_Medium, 0, PURPLE);
    FlashAllSpeedIncreasing_Combo_Animation(PURPLE);
    return true;
  }

  //Geese Howard (Pretzel) Super Left [3412361 + ATTACK]
  if( kaimana.switchHistoryTest( COMBO_RAGINGSTORM_LEFT, RAGINGSTORM_INPUT_COUNT, P1Array, 1, false ) )
  {
    WaveEffect_Combo_Animation(EFT_DownToUp, EFS_Medium, 0, PURPLE);
    FlashAllSpeedIncreasing_Combo_Animation(PURPLE);
    return true;
  }

  
  //Double Circle Super (Both Directions and All Starting Positions)
  for(int index = 0; index < 3; ++index)
  {
    if( kaimana.switchHistoryTest( COMBO_630_LEFT_CLOCKWISE, SIXTHIRTY_INPUT_COUNT, index == 0 ? P1Array : (index == 1 ? P2Array : P3Array), 1, false ) ||
        kaimana.switchHistoryTest( COMBO_630_UP_CLOCKWISE, SIXTHIRTY_INPUT_COUNT, index == 0 ? P1Array : (index == 1 ? P2Array : P3Array), 1, false ) ||
        kaimana.switchHistoryTest( COMBO_630_RIGHT_CLOCKWISE, SIXTHIRTY_INPUT_COUNT, index == 0 ? P1Array : (index == 1 ? P2Array : P3Array), 1, false ) ||
        kaimana.switchHistoryTest( COMBO_630_DOWN_CLOCKWISE, SIXTHIRTY_INPUT_COUNT, index == 0 ? P1Array : (index == 1 ? P2Array : P3Array), 1, false ) ||
        kaimana.switchHistoryTest( COMBO_630_LEFT_ANTICLOCKWISE, SIXTHIRTY_INPUT_COUNT, index == 0 ? P1Array : (index == 1 ? P2Array : P3Array), 1, false ) ||
        kaimana.switchHistoryTest( COMBO_630_UP_ANTICLOCKWISE, SIXTHIRTY_INPUT_COUNT, index == 0 ? P1Array : (index == 1 ? P2Array : P3Array), 1, false ) ||
        kaimana.switchHistoryTest( COMBO_630_RIGHT_ANTICLOCKWISE, SIXTHIRTY_INPUT_COUNT, index == 0 ? P1Array : (index == 1 ? P2Array : P3Array), 1, false ) ||
        kaimana.switchHistoryTest( COMBO_630_DOWN_ANTICLOCKWISE, SIXTHIRTY_INPUT_COUNT, index == 0 ? P1Array : (index == 1 ? P2Array : P3Array), 1, false ) )
    {
      CircleRGB_Combo_Animation(1);  
      FlashAllSpeedIncreasing_Combo_Animation(RED);
      FlashAllSpeedIncreasing_Combo_Animation(GOLD);
      return true;
    }
  }


  //Charge Super Left to Right [(4)646 + ATTACK]
  if( kaimana.switchHistoryTest( COMBO_CHARGE_SUPER_LEFT_RIGHT, CHARGE_SUPER_INPUT_COUNT, P1Array, 1, true ) )
  {
    WaveEffect_Combo_Animation(EFT_DownToUp, EFS_Medium, 0, GREEN);  
    WaveEffect_Combo_Animation(EFT_DownToUp, EFS_Medium, 0, RED); 
    WaveEffect_Combo_Animation(EFT_DownToUp, EFS_Medium, 0, GREEN); 
    return true;
  }

  //Charge Super Right to Left [(6)464+ ATTACK]
  if( kaimana.switchHistoryTest( COMBO_CHARGE_SUPER_RIGHT_LEFT, CHARGE_SUPER_INPUT_COUNT, P1Array, 1, true ) )
  {
    WaveEffect_Combo_Animation(EFT_DownToUp, EFS_Medium, 0, GREEN);  
    WaveEffect_Combo_Animation(EFT_DownToUp, EFS_Medium, 0, RED); 
    WaveEffect_Combo_Animation(EFT_DownToUp, EFS_Medium, 0, GREEN); 
    return true;
  }


  //Raging Demon Right
  if( kaimana.switchHistoryTest( HELL_MURDER_INPUT_RIGHT, HELL_MURDER_INPUT_COUNT, P3K1Array, 2, false ))
  {
    WaveEffect_Combo_Animation(EFT_LeftToRight, EFS_Medium, 0, DARKGREY);  
    Randomise_Combo_Animation(6, 120, 60, RED);
    Randomise_Combo_Animation(12, 70, 45, RED);
    Randomise_Combo_Animation(24, 30, 30, RED);
    FlashColour_Combo_Animation(RED, 750);
    return true;
  }


  //Raging Demon Left
  if( kaimana.switchHistoryTest( HELL_MURDER_INPUT_LEFT, HELL_MURDER_INPUT_COUNT, P3K1Array, 2, false ))
  {
    WaveEffect_Combo_Animation(EFT_RightToLeft, EFS_Medium, 0, DARKGREY);  
    Randomise_Combo_Animation(6, 120, 60, RED);
    Randomise_Combo_Animation(12, 70, 45, RED);
    Randomise_Combo_Animation(24, 30, 30, RED);
    FlashColour_Combo_Animation(RED, 750);
    return true;
  }
 
  
  //SPECIAL MOVES
  //Quarter Circle Right [236 + ATTACK]
  if( kaimana.switchHistoryTest( COMBO_QUARTERCIRCLE_RIGHT, QUARTERCIRCLE_INPUT_COUNT, K1Array, 1, false ) )
  {
    WaveEffect_Combo_Animation(EFT_RightToLeft, EFS_Slow, 3, MAGENTA);    
    return true;
  }

  //Quarter Circle Left [214 + ATTACK]
  if( kaimana.switchHistoryTest( COMBO_QUARTERCIRCLE_LEFT, QUARTERCIRCLE_INPUT_COUNT, K1Array, 1, false ) )
  {
    WaveEffect_Combo_Animation(EFT_LeftToRight, EFS_Slow, 3, MAGENTA);    
    return true;
  }


  //Half Circle Right [41236 + ATTACK]
  if( kaimana.switchHistoryTest( COMBO_HALFCIRCLE_RIGHT, HALFCIRCLE_INPUT_COUNT, K1Array, 1, false ) )
  {
    WaveEffect_Combo_Animation(EFT_LeftToRight, EFS_Fast, 0, GOLD); 
    WaveEffect_Combo_Animation(EFT_LeftToRight, EFS_Fast, 0, WHITE); 
    return true;
  }

 //Half Circle Left [63214 + ATTACK]
  if( kaimana.switchHistoryTest( COMBO_HALFCIRCLE_LEFT, HALFCIRCLE_INPUT_COUNT, K1Array, 1, false ) )
  {
    WaveEffect_Combo_Animation(EFT_RightToLeft, EFS_Fast, 0, GOLD); 
    WaveEffect_Combo_Animation(EFT_RightToLeft, EFS_Fast, 0, WHITE);
    return true;
  }


  

  
  //Dragon Punch Right [623 + ATTACK]
  if( kaimana.switchHistoryTest( COMBO_DP_RIGHT, DP_INPUT_COUNT, K1Array, 1, false ) )
  {
    FlashColour_Combo_Animation(GOLD, 250);
    return true;
  }

  //Dragon Punch Left [421 + ATTACK]
  if( kaimana.switchHistoryTest( COMBO_DP_LEFT, DP_INPUT_COUNT, K1Array, 1, false ) )
  {
    FlashColour_Combo_Animation(GOLD, 250);
    return true;
  }

  
  //Charge Left to Right [(4)6 + ATTACK]
  if( kaimana.switchHistoryTest( COMBO_CHARGE_LEFT_RIGHT, CHARGE_INPUT_COUNT, K1Array, 1, true ) )
  {
    WaveEffect_Combo_Animation(EFT_LeftToRight, EFS_Slow, 0, GREEN);  
    return true;
  }

  //Charge Right to Left [(6)4 + ATTACK]
  if( kaimana.switchHistoryTest( COMBO_CHARGE_RIGHT_LEFT, CHARGE_INPUT_COUNT, K1Array, 1, true ) )
  {
    WaveEffect_Combo_Animation(EFT_RightToLeft, EFS_Slow, 0, GREEN);  
    return true;
  }

  //Charge Down to Up [(2)8 + ATTACK]
  if( kaimana.switchHistoryTest( COMBO_CHARGE_DOWN_UP, CHARGE_INPUT_COUNT, K1Array, 1, true ) )
  {
    WaveEffect_Combo_Animation(EFT_DownToUp, EFS_Slow, 0, YELLOW);  
    return true;
  }

  
  //Down Down Specials [22 + ATTACK]
  if( kaimana.switchHistoryTest( COMBO_DOUBLE_DOWN, DOUBLE_DOWN_INPUT_COUNT, K1Array, 1, false ) )
  {
    WaveEffect_Combo_Animation(EFT_DownToUp, EFS_Slow, 0, BLUE);  
    return true;
  }


  //Triple Punch Button Special [PPP simultaneously]
  if( kaimana.switchHistoryTest( LeftArray, 1, TRIGGER_PPP, TRIPLEATTACK_TRIGGER_COUNT, false ) ||
      kaimana.switchHistoryTest( RightArray, 1, TRIGGER_PPP, TRIPLEATTACK_TRIGGER_COUNT, false ) )
  {
    KnightRider_Combo_Animation(1, true, RED);  
    return true;
  }

  //Triple Kick Button Special [KKK simultaneously]
  if( kaimana.switchHistoryTest( LeftArray, 1, TRIGGER_KKK, TRIPLEATTACK_TRIGGER_COUNT, false ) ||
      kaimana.switchHistoryTest( RightArray, 1, TRIGGER_KKK, TRIPLEATTACK_TRIGGER_COUNT, false ) )
  {
    KnightRider_Combo_Animation(1, false, RED);  
    return true;
  }

  
  //Full Circle Special Move (Both Directions and All Starting Positions)
  for(int index = 0; index < 3; ++index)
  {
    if( kaimana.switchHistoryTest( COMBO_270_LEFT_CLOCKWISE, TWOSEVENTY_INPUT_COUNT, index == 0 ? P1Array : (index == 1 ? P2Array : P3Array), 1, false ) ||
        kaimana.switchHistoryTest( COMBO_270_UP_CLOCKWISE, TWOSEVENTY_INPUT_COUNT, index == 0 ? P1Array : (index == 1 ? P2Array : P3Array), 1, false ) ||
        kaimana.switchHistoryTest( COMBO_270_RIGHT_CLOCKWISE, TWOSEVENTY_INPUT_COUNT, index == 0 ? P1Array : (index == 1 ? P2Array : P3Array), 1, false ) ||
        kaimana.switchHistoryTest( COMBO_270_DOWN_CLOCKWISE, TWOSEVENTY_INPUT_COUNT, index == 0 ? P1Array : (index == 1 ? P2Array : P3Array), 1, false ) ||
        kaimana.switchHistoryTest( COMBO_270_LEFT_ANTICLOCKWISE, TWOSEVENTY_INPUT_COUNT, index == 0 ? P1Array : (index == 1 ? P2Array : P3Array), 1, false ) ||
        kaimana.switchHistoryTest( COMBO_270_UP_ANTICLOCKWISE, TWOSEVENTY_INPUT_COUNT, index == 0 ? P1Array : (index == 1 ? P2Array : P3Array), 1, false ) ||
        kaimana.switchHistoryTest( COMBO_270_RIGHT_ANTICLOCKWISE, TWOSEVENTY_INPUT_COUNT, index == 0 ? P1Array : (index == 1 ? P2Array : P3Array), 1, false ) ||
        kaimana.switchHistoryTest( COMBO_270_DOWN_ANTICLOCKWISE, TWOSEVENTY_INPUT_COUNT, index == 0 ? P1Array : (index == 1 ? P2Array : P3Array), 1, false ) )
    {
      Circle_OneColour_Combo_Animation(2, RED);  
      return true;
    }
  }

  
  
  
  return false;
} 
