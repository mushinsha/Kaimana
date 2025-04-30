//  Potemkin.cpp
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
//  Kaimana Potemkin character combo checks and animation calls. First released by ParadiseArcadeShop.com November, 2023
//  Characters are added into the character selection array in the main ino file. See that for info on how characters are selected
//
//  Created:  April 21st, 2025 by Hunter "Mushinsha" Nelson
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
bool Potemkin::testForCharacterCombos() const
{

  //OVERDRIVES
  //Heavenly Potemkin Buster [641236 or 412364 + S]
  if( kaimana.switchHistoryTest( COMBO_TYRANTRAVE_RIGHT, TYRANTRAVE_INPUT_COUNT, P2Array, 1, false ) ||
    ( kaimana.switchHistoryTest( COMBO_TYRANTRAVE_LEFT, TYRANTRAVE_INPUT_COUNT, P2Array, 1, false ) )
  {
    FlashAllSpeedIncreasing_Combo_Animation(RED);
    FlashAllSpeedIncreasing_Combo_Animation(WHITE);
    FlashAllSpeedIncreasing_Combo_Animation(BLUE);   
    return true;
  }

  //Gaiganter Kai [641236 or 412364 + HS]
  if( kaimana.switchHistoryTest( COMBO_TYRANTRAVE_RIGHT, TYRANTRAVE_INPUT_COUNT, K2Array, 1, false ) ||
    ( kaimana.switchHistoryTest( COMBO_TYRANTRAVE_LEFT, TYRANTRAVE_INPUT_COUNT, K2Array, 1, false ) )
  {
    FlashAllSpeedIncreasing_Combo_Animation(GREEN);
    FlashAllSpeedIncreasing_Combo_Animation(GOLD);
    FlashAllSpeedIncreasing_Combo_Animation(GREEN);
    return true;
  }

  
  //SPECIAL MOVES
  //Potemkin Buster [641236 or 412364 + P]
  if( kaimana.switchHistoryTest( COMBO_TYRANTRAVE_RIGHT, TYRANTRAVE_INPUT_COUNT, P1Array, 1, false ) ||
    ( kaimana.switchHistoryTest( COMBO_TYRANTRAVE_LEFT, TYRANTRAVE_INPUT_COUNT, P1Array, 1, false ) )
  {
    FlashAllSpeedIncreasing_Combo_Animation(WHITE);
    FlashAllSpeedIncreasing_Combo_Animation(ORANGE);
    FlashAllSpeedIncreasing_Combo_Animation(BLUE);   
    return true;
  }
  
  
  //Mega Fist (both directions) [236 + P]
  if( kaimana.switchHistoryTest( COMBO_QUARTERCIRCLE_RIGHT, QUARTERCIRCLE_INPUT_COUNT, P1Array, 1, false ) ||
    ( kaimana.switchHistoryTest( COMBO_QUARTERCIRCLE_LEFT, QUARTERCIRCLE_INPUT_COUNT, P1Array, 1, false ) )
  {
    WaveEffect_Combo_Animation(EFT_DownToUp, EFS_Medium, 2, RED);    
    return true;
  }
  
  
  //Slide Head (both directions) [236 + S]
  if( kaimana.switchHistoryTest( COMBO_QUARTERCIRCLE_RIGHT, QUARTERCIRCLE_INPUT_COUNT, P2Array, 1, false ) ||
    ( kaimana.switchHistoryTest( COMBO_QUARTERCIRCLE_LEFT, QUARTERCIRCLE_INPUT_COUNT, P2Array, 1, false ) )
  {
    WaveEffect_Combo_Animation(EFT_UpToDown, EFS_Slow, 0, GREEN);    
    return true;
  }
  
  
  //Heat Knuckle (both directions) [623 or 421 + HS]
  if( kaimana.switchHistoryTest( COMBO_DP_RIGHT, DP_INPUT_COUNT, K2Array, 1, false ) ||
      kaimana.switchHistoryTest( COMBO_DP_LEFT, DP_INPUT_COUNT, K2Array, 1, false ) )
  {
    FlashColour_Combo_Animation(RED, 250);
    return true;
  }


  //Heat Tackle (both directions) [623 or 421 + K]
  if( kaimana.switchHistoryTest( COMBO_DP_RIGHT, DP_INPUT_COUNT, K1Array, 1, false ) ||
      kaimana.switchHistoryTest( COMBO_DP_LEFT, DP_INPUT_COUNT, K1Array, 1, false ) )
  {
    WaveEffect_Combo_Animation(EFT_DownToUp, EFS_Fast, 0, WHITE);
    WaveEffect_Combo_Animation(EFT_DownToUp, EFS_Medium, 0, RED);
    return true;
  }

  
  //Hammer Fall (right) [(4)6 + HS]
  if( kaimana.switchHistoryTest( COMBO_CHARGE_LEFT_RIGHT, CHARGE_INPUT_COUNT, K2Array, 1, true ) )
  {
    WaveEffect_Combo_Animation(EFT_LeftToRight, EFS_Medium, 0, ORANGE);
    WaveEffect_Combo_Animation(EFT_RightToLeft, EFS_Fast, 0, WHITE);
    return true;
  }

  //Hammer Fall (left) [(6)4 + HS]
  if( kaimana.switchHistoryTest( COMBO_CHARGE_RIGHT_LEFT, CHARGE_INPUT_COUNT, K1Array, 1, true ) )
  {
    WaveEffect_Combo_Animation(EFT_RightToLeft, EFS_Medium, 0, ORANGE);
      WaveEffect_Combo_Animation(EFT_LeftToRight, EFS_Fast, 0, WHITE);
    return true;
  }

    
  //Garuda Impact (right) [214 + HS]
  if( kaimana.switchHistoryTest( COMBO_QUARTERCIRCLE_LEFT, QUARTERCIRCLE_INPUT_COUNT, K2Array, 1, false ) )
  {
    WaveEffect_Combo_Animation(EFT_LeftToRight, EFS_Medium, 0, ORANGE);
    WaveEffect_Combo_Animation(EFT_LeftToRight, EFS_Fast, 0, RED);
    return true;
  }

  //Garuda Impact (left) [236 + HS]
  if( kaimana.switchHistoryTest( COMBO_QUARTERCIRCLE_RIGHT, QUARTERCIRCLE_INPUT_COUNT, K2Array, 1, false ) )
  {
    WaveEffect_Combo_Animation(EFT_RightToLeft, EFS_Medium, 0, ORANGE);
    WaveEffect_Combo_Animation(EFT_RightToLeft, EFS_Fast, 0, RED);
    return true;
  }


  //FDB (right) [214 + K]
  if( kaimana.switchHistoryTest( COMBO_QUARTERCIRCLE_LEFT, QUARTERCIRCLE_INPUT_COUNT, K1Array, 1, false ) )
  {
    WaveEffect_Combo_Animation(EFT_LeftToRight, EFS_Medium, 0, ORANGE);
    WaveEffect_Combo_Animation(EFT_LeftToRight, EFS_Fast, 0, WHITE);
    return true;
  }

  //FDB (left) [236 + K]
  if( kaimana.switchHistoryTest( COMBO_QUARTERCIRCLE_RIGHT, QUARTERCIRCLE_INPUT_COUNT, K1Array, 1, false ) )
  {
    WaveEffect_Combo_Animation(EFT_RightToLeft, EFS_Medium, 0, ORANGE);
    WaveEffect_Combo_Animation(EFT_RightToLeft, EFS_Fast, 0, WHITE);
    return true;
  }

  
  return false;
} 
