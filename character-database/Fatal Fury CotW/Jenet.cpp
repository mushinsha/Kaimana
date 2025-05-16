//  Jenet.cpp
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
//  Kaimana Jenet character combo checks and animation calls. First released by ParadiseArcadeShop.com November, 2023
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
bool Jenet::testForCharacterCombos() const
{

  //Special Moves
    //Baffles (right)                       [236 + P]
    //Baffles (left)                        [214 + P]
    //Crazy Ivan (right)                    [214 + P]
    //Crazy Ivan (left)                     [236 + P]
    //Gulf Tomahawk (right)                 [214 + K]
    //Gulf Tomahawk (left)                  [236 + K]
    //The Hind (right)                      [236 + K]
    //The Hind (left)                       [214 + K]
    //Secret Mademoiselle (right)           [623 + P]
    //Secret Mademoiselle (left)            [421 + P]

  //Ignition Gears
    //Many Many Torpedoes (right)           [236236 + A or (RL[C])
    //Many Many Torpedoes (left)            [214214 + A or (RL[C])
    //Aurora (right)                        [236236 + B or (RL[D])
    //Aurora (left)                         [214214 + B or (RL[D])

  //Hidden Gear
    //JB-14 (right)                         [236236 + R1]
    //JB-14 (left)                          [214214 + R1]
  
  return false;
} 
