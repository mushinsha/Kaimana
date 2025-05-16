//  Akuma_3S.cpp
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
//  Kaimana Akuma_3S character combo checks and animation calls. First released by ParadiseArcadeShop.com November, 2023
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
bool Akuma_3S::testForCharacterCombos() const
{
  
//MOVELIST BELOW

//SUPER ARTS
  //Messatsu Gou Hadou          [236236 + P] (SA1)
  //Tenma Gou Zankuu            [632146 + P] (SA1)
  //Messatsu Gou Shoryu         [236236 + P] (SA2)
  //Messatsu-Gouransen          [236236 + K] (SA3)
  //Messatsu-Gou Senpuu         [236236 + K] (SA3) (AIR ONLY)
  //Shungokusatsu               [LP, LP, 6LK + HP] (USES 2 BARS)
  //Kongou Kokuretsuzan         [222 + PP] (USES 2 BARS)
  
//SPECIAL MOVES
  //Go Hadouken                 [236 + P]
  //Zankuu Hadouken             [236 + P] (AIR ONLY)
  //Shakunetsu-Hadouken         [63214 + P]
  //Go Shoryuken                [623 + P]
  //Tatsumaki Zankuukyaku       [214 + K] (In Air Possible)
  //Ashura Senku                [623 or 421 + PP or KK]
  //Hyakkishu                   [623 + K]

  return false;
} 
