//  Mai_cotw.cpp
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
//  Kaimana Mai_cotw character combo checks and animation calls. First released by ParadiseArcadeShop.com November, 2023
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
bool Mai_cotw::testForCharacterCombos() const
{

  //Special Moves
    //Kachousen (right)                       [236 + P]
    //Kachousen (left)                        [214 + P]
    //Ryuuenbu (right)                        [214 + P]
    //Ryuuenbu (left)                         [236 + P]
    //Hissatsu Shinobi Bachi (right)          [236 + B or D]
    //Hissatsu Shinobi Bachi (left)           [214 + B or D]
    //Sayo Chidori (right)                    [214 + K]
    //Sayo Chidori (left)                     [236 + K]
    //Hana Arashi (right)                     [623 + B or D]
    //Hana Arashi (left)                      [421 + B or D]
    //Musasabi no Mai                         [(2)8 + P]
    //Air Musasabi no Mai (right)             [214 + P]
    //Air Musasabi no Mai (left)              [236 + P]

  //Ignition Gears
    //Kagerou no Mai (right)                  [236236 + A or (RL[C])
    //Kagerou no Mai (left)                   [214214 + A or (RL[C])
    //Chou Hissatsu Shinobi Bachi (right)     [236236 + B or (RL[D])
    //Chou Hissatsu Shinobi Bachi (left)      [214214 + B or (RL[D])

  //Hidden Gear
    //Ouran no Mai: Akasuzumi (right)         [236236 + R1]
    //Ouran no Mai: Akasuzumi (left)          [214214 + R1]
  
  return false;
} 
