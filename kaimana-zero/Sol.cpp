//  Sol.cpp
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
bool Sol::testForCharacterCombos() const
{
  
  //OVERDRIVES
  //Tyrant Rave right (Overdrive) [632146H]
  if( kaimana.switchHistoryTest( COMBO_TYRANTRAVE_RIGHT, TYRANTRAVE_INPUT_COUNT, K2Array, 1, false ) )
  {
    WaveEffect_Combo_Animation(EFT_DownToUp, EFS_Medium, 0, YELLOW);
    WaveEffect_Combo_Animation(EFT_DownToUp, EFS_Fast, 0, RED);
    WaveEffect_Combo_Animation(EFT_LeftToRight, EFS_Medium, 0, ORANGE);
    WaveEffect_Combo_Animation(EFT_LeftToRight, EFS_Fast, 0, RED); 
    FlashAllSpeedIncreasing_Combo_Animation(RED); 
    return true;
  }
    
  //Tyrant Rave left (Overdrive) [412364H]
  if( kaimana.switchHistoryTest( COMBO_TYRANTRAVE_LEFT, TYRANTRAVE_INPUT_COUNT, K2Array, 1, false ) )
  {
    WaveEffect_Combo_Animation(EFT_DownToUp, EFS_Medium, 0, YELLOW);
    WaveEffect_Combo_Animation(EFT_DownToUp, EFS_Fast, 0, RED);
    WaveEffect_Combo_Animation(EFT_RightToLeft, EFS_Medium, 0, ORANGE);
    WaveEffect_Combo_Animation(EFT_RightToLeft, EFS_Fast, 0, RED);
    FlashAllSpeedIncreasing_Combo_Animation(RED);  
    return true;
  }


  //SPECIAL MOVES
  //Heavy Mob Cemetery left (Overdrive) [236236H]
  if( kaimana.switchHistoryTest( COMBO_DOUBLE_QUARTERCIRCLE_RIGHT, DOUBLE_QUARTERCIRCLE_INPUT_COUNT, K2Array, 1, false ) )
  {
    WaveEffect_Combo_Animation(EFT_RightToLeft, EFS_Medium, 0, RED);
    WaveEffect_Combo_Animation(EFT_DownToUp, EFS_Slow, 0, RED);
    WaveEffect_Combo_Animation(EFT_DownToUp, EFS_Fast, 0, YELLOW);  
    FlashAllSpeedIncreasing_Combo_Animation(RED);
    return true;
  }
    
  //Heavy Mob Cemetery right (Overdrive) [214214H]
  if( kaimana.switchHistoryTest( COMBO_DOUBLE_QUARTERCIRCLE_LEFT, DOUBLE_QUARTERCIRCLE_INPUT_COUNT, K2Array, 1, false ) )
  {
    WaveEffect_Combo_Animation(EFT_LeftToRight, EFS_Medium, 0, RED); 
    WaveEffect_Combo_Animation(EFT_DownToUp, EFS_Slow, 0, RED);
    WaveEffect_Combo_Animation(EFT_DownToUp, EFS_Fast, 0, YELLOW);   
    FlashAllSpeedIncreasing_Combo_Animation(RED);  
    return true;
  }


  //Volcanic Viper right [623S or 623H]
  if( kaimana.switchHistoryTest( COMBO_DP_RIGHT, DP_INPUT_COUNT, P2Array, 1, false ) )
  {
    WaveEffect_Combo_Animation(EFT_DownToUp, EFS_Medium, 0, ORANGE);
    WaveEffect_Combo_Animation(EFT_DownToUp, EFS_Fast, 1, RED);
    return true;
  }
  if( kaimana.switchHistoryTest( COMBO_DP_RIGHT, DP_INPUT_COUNT, K2Array, 1, false ) )
  {
    WaveEffect_Combo_Animation(EFT_DownToUp, EFS_Medium, 0, ORANGE);
    WaveEffect_Combo_Animation(EFT_DownToUp, EFS_Slow, 1, RED);
    return true;
  }

  //Volcanic Viper left [421S or 421H]
  if( kaimana.switchHistoryTest( COMBO_DP_LEFT, DP_INPUT_COUNT, P2Array, 1, false ) )
  {
    WaveEffect_Combo_Animation(EFT_DownToUp, EFS_Medium, 0, ORANGE);
    WaveEffect_Combo_Animation(EFT_DownToUp, EFS_Fast, 1, RED);
    return true;
  }
  if( kaimana.switchHistoryTest( COMBO_DP_LEFT, DP_INPUT_COUNT, K2Array, 1, false ) )
  {
    WaveEffect_Combo_Animation(EFT_DownToUp, EFS_Medium, 0, ORANGE);
    WaveEffect_Combo_Animation(EFT_DownToUp, EFS_Slow, 1, RED);
    return true;
  }


  //Fafnir right [41236H]
  if( kaimana.switchHistoryTest( COMBO_HALFCIRCLE_RIGHT, HALFCIRCLE_INPUT_COUNT, K2Array, 1, false ) )
  {
    WaveEffect_Combo_Animation(EFT_LeftToRight, EFS_Fast, 0, GOLD);
    WaveEffect_Combo_Animation(EFT_LeftToRight, EFS_Slow, 0, RED);  
    return true;
  }

  //Fafnir left [63214H]
  if( kaimana.switchHistoryTest( COMBO_HALFCIRCLE_LEFT, HALFCIRCLE_INPUT_COUNT, K2Array, 1, false ) )
  {
    WaveEffect_Combo_Animation(EFT_RightToLeft, EFS_Fast, 0, GOLD);
    WaveEffect_Combo_Animation(EFT_RightToLeft, EFS_Slow, 0, RED); 
    return true;
  }


  //Bandit Revolver right (Bandit Revolver left) [236K]
  if( kaimana.switchHistoryTest( COMBO_QUARTERCIRCLE_RIGHT, QUARTERCIRCLE_INPUT_COUNT, K1Array, 1, false ) )
  {
    WaveEffect_Combo_Animation(EFT_LeftToRight, EFS_Medium, 1, ORANGE);
    WaveEffect_Combo_Animation(EFT_LeftToRight, EFS_Fast, 0, RED);
    return true;
  }
  
  //Bandit Revolver left (Bandit Bringer right) [214K]
  if( kaimana.switchHistoryTest( COMBO_QUARTERCIRCLE_LEFT, QUARTERCIRCLE_INPUT_COUNT, K1Array, 1, false ) )
  {
    WaveEffect_Combo_Animation(EFT_RightToLeft, EFS_Medium, 1, ORANGE);
    WaveEffect_Combo_Animation(EFT_RightToLeft, EFS_Fast, 0, RED);    
    return true;
  }


  //Wild Throw (both directions) [623K or 421K]
  if( kaimana.switchHistoryTest( COMBO_DP_RIGHT, DP_INPUT_COUNT, K1Array, 1, false ) ||
      kaimana.switchHistoryTest( COMBO_DP_LEFT, DP_INPUT_COUNT, K1Array, 1, false ) )
  {
    WaveEffect_Combo_Animation(EFT_DownToUp, EFS_Slow, 0, GOLD);
    WaveEffect_Combo_Animation(EFT_UpToDown, EFS_Slow, 0, RED);
    FlashAllSpeedIncreasing_Combo_Animation(GOLD);
    return true;
  }


  //Night Raid Vortex right [214S]
  if( kaimana.switchHistoryTest( COMBO_QUARTERCIRCLE_LEFT, QUARTERCIRCLE_INPUT_COUNT, P2Array, 1, false ) )
  {
    WaveEffect_Combo_Animation(EFT_RightToLeft, EFS_Fast, 0, BEIGE);
    WaveEffect_Combo_Animation(EFT_RightToLeft, EFS_Fast, 0, ORANGE);
    WaveEffect_Combo_Animation(EFT_DownToUp, EFS_Slow, 0, RED);
    return true;
  }


  //Night Raid Vortex left [236S]
  if( kaimana.switchHistoryTest( COMBO_QUARTERCIRCLE_RIGHT, QUARTERCIRCLE_INPUT_COUNT, P2Array, 1, false ) )
  {
    WaveEffect_Combo_Animation(EFT_LeftToRight, EFS_Fast, 0, BEIGE);
    WaveEffect_Combo_Animation(EFT_LeftToRight, EFS_Fast, 0, ORANGE);
    WaveEffect_Combo_Animation(EFT_DownToUp, EFS_Slow, 0, RED);
    return true;
  }


  return false;
} 
