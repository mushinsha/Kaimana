//  Zato.cpp
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
//  Kaimana Zato character combo checks and animation calls. First released by ParadiseArcadeShop.com November, 2023
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
bool Zato::testForCharacterCombos() const
{
  
//MOVELIST BELOW

//OVERDRIVES
  //Amorphous                [632146 + HS]
  //Sun Void                 [632146 + S] (In Air Possible)
  

//SPECIAL MOVES
  //Summon Eddie             [214 + HS]
  //"Pierce"                 [236 + P]
  //"That's A Lot!"          [236 + K]
  //"Leap"                   [236 + S]
  //"Oppose"                 [236 + HS]
  //Invite Hell              [22 + HS]
  //Break the Law            [214 + K] (Can be held)
  //Damned Fang              [623 + S]
  //Drunkard Shade           [214 + S]
  
  return false;
} 
