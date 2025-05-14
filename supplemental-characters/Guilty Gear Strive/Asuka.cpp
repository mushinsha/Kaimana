//  Asuka.cpp
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
//  Kaimana Asuka character combo checks and animation calls. First released by ParadiseArcadeShop.com November, 2023
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
bool Asuka::testForCharacterCombos() const
{
  
  //MOVELIST BELOW

  //OVERDRIVES
  //High Compression Submicron Particle Sphere    [632146 + P or K]
  //Bookmark (Full Order)                         [632146 + S]

  //SPECIAL MOVES
  //Chant                                         [236 + Any] (In Air Possible)
  //Bookmark                                      [214 + Any] (In Air Possible)
  //Recover Mana                                  [22 + P or K or S] (Can be held)
  //Change Test Case                              [22 + HS, P or K or S] (In Air Possible)
  
  
  return false;
} 
