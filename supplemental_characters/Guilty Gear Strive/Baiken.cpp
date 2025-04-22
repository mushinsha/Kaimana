//  Baiken.cpp
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
//  Kaimana Ryu character combo checks and animation calls. First released by ParadiseArcadeShop.com November, 2023
//  Characters are added into the character selection array in the main ino file. See that for info on how characters are selected
//
//  Created:  November, 2023    Paul 'pod' Denning
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
bool Baiken::testForCharacterCombos() const
{

  //OVERDRIVES
  //Tsurane Sanzu-watashi (Slash Overdrive) right [236236S]
  if( kaimana.switchHistoryTest( COMBO_DOUBLE_QUARTERCIRCLE_RIGHT, DOUBLE_QUARTERCIRCLE_INPUT_COUNT, P2Array, 1, false ) )
  {
    WaveEffect_Combo_Animation(EFT_LeftToRight, EFS_Slow, 2, MAGENTA);
    FlashAllSpeedIncreasing_Combo_Animation(MAGENTA); 
    FlashAllSpeedIncreasing_Combo_Animation(PURPLE);  
    return true;
  }
    
  //Tsurane Sanzu-watashi (Slash Overdrive) left [214214S]
  if( kaimana.switchHistoryTest( COMBO_DOUBLE_QUARTERCIRCLE_LEFT, DOUBLE_QUARTERCIRCLE_INPUT_COUNT, P2Array, 1, false ) )
  {
    WaveEffect_Combo_Animation(EFT_RightToLeft, EFS_Slow, 2, MAGENTA);
    FlashAllSpeedIncreasing_Combo_Animation(MAGENTA); 
    FlashAllSpeedIncreasing_Combo_Animation(PURPLE);  
    return true;
  }

  //SPECIAL MOVES
  //Kenjyu (Pistol Overdrive) right [214214P] 
  if( kaimana.switchHistoryTest( COMBO_DOUBLE_QUARTERCIRCLE_LEFT, DOUBLE_QUARTERCIRCLE_INPUT_COUNT, P1Array, 1, false ) )
  {
    WaveEffect_Combo_Animation(EFT_LeftToRight, EFS_Slow, 0, WHITE);
    WaveEffect_Combo_Animation(EFT_RightToLeft, EFS_Fast, 0, ORANGE);
    WaveEffect_Combo_Animation(EFT_RightToLeft, EFS_Fast, 0, RED);  
    return true;
  }
    
  //Kenjyu (Pistol Overdrive) left [236236P] 
  if( kaimana.switchHistoryTest( COMBO_DOUBLE_QUARTERCIRCLE_RIGHT, DOUBLE_QUARTERCIRCLE_INPUT_COUNT, P1Array, 1, false ) )
  {
    WaveEffect_Combo_Animation(EFT_RightToLeft, EFS_Slow, 0, WHITE);  
    WaveEffect_Combo_Animation(EFT_LeftToRight, EFS_Fast, 0, ORANGE);
    WaveEffect_Combo_Animation(EFT_LeftToRight, EFS_Fast, 0, RED);
    return true;
  }


  //Kabari right [41236S or 41236H] (63214S input overlaps with Youzansen)
  if( kaimana.switchHistoryTest( COMBO_HALFCIRCLE_RIGHT, HALFCIRCLE_INPUT_COUNT, K2Array, 1, false ) )
  {
    WaveEffect_Combo_Animation(EFT_LeftToRight, EFS_Medium, 0, RED);
    WaveEffect_Combo_Animation(EFT_RightToLeft, EFS_Fast, 0, GOLD);
    return true;
  }

 //Kabari left [63214H] (63214S input overlaps with Youzansen)
  if( kaimana.switchHistoryTest( COMBO_HALFCIRCLE_LEFT, HALFCIRCLE_INPUT_COUNT, K2Array, 1, false ) )
  {
    WaveEffect_Combo_Animation(EFT_RightToLeft, EFS_Medium, 0, RED);
    WaveEffect_Combo_Animation(EFT_LeftToRight, EFS_Fast, 0, GOLD);
    return true;
  }


  //Tatami Gaeshi both directions [236K or 214K]
  if( kaimana.switchHistoryTest( COMBO_QUARTERCIRCLE_RIGHT, QUARTERCIRCLE_INPUT_COUNT, K1Array, 1, false ) ||
      kaimana.switchHistoryTest( COMBO_QUARTERCIRCLE_LEFT, QUARTERCIRCLE_INPUT_COUNT, K1Array, 1, false ) )
  {
    WaveEffect_Combo_Animation(EFT_DownToUp, EFS_Medium, 0, GREEN);
    WaveEffect_Combo_Animation(EFT_DownToUp, EFS_Fast, 0, PURPLE);    
    return true;
  }


  //Youzansen both directions [236S or 214S in the air]
  if( kaimana.switchHistoryTest( COMBO_QUARTERCIRCLE_RIGHT, QUARTERCIRCLE_INPUT_COUNT, P2Array, 1, false ) ||
      kaimana.switchHistoryTest( COMBO_QUARTERCIRCLE_LEFT, QUARTERCIRCLE_INPUT_COUNT, P2Array, 1, false ) )
  {
    WaveEffect_Combo_Animation(EFT_DownToUp, EFS_Medium, 0, PURPLE);
    WaveEffect_Combo_Animation(EFT_DownToUp, EFS_Fast, 1, PURPLE);
    
    return true;
  }

  /*
    //Hiiragi both directions [236P] PARRY
  if( kaimana.switchHistoryTest( COMBO_QUARTERCIRCLE_RIGHT, QUARTERCIRCLE_INPUT_COUNT, P1Array, 1, false ) ||
      kaimana.switchHistoryTest( COMBO_QUARTERCIRCLE_LEFT, QUARTERCIRCLE_INPUT_COUNT, P1Array, 1, false ) )
  {  
    WaveEffect_Combo_Animation(EFT_RightToLeft, EFS_Medium, 0, DARKGREY);  
    Randomise_Combo_Animation(6, 120, 60, RED);
    Randomise_Combo_Animation(12, 70, 45, RED);
    Randomise_Combo_Animation(24, 30, 30, RED);
    FlashColour_Combo_Animation(RED, 750);
    return true;
  }
  */

  return false;
} 
