//  Jamie.cpp
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
//  Kaimana Jamie character combo checks and animation calls. First released by ParadiseArcadeShop.com November, 2023
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
bool Jamie::testForCharacterCombos() const
{
  
//MOVELIST BELOW

  //SUPER ARTS
  //Breakin'                      [236236 + K] (1 BAR)
  //The Devil's Song              [214214 + P] (2 BAR)
  //Getsuga Saiho                 [236236 + P] (3 BAR)


  //SPECIAL MOVES
  //The Devil Inside              [22 + P]
  //Freeflow Strikes              [236 + P, 6P, 6P]
  //Freeflow Kicks                [236 + P, 6K, 6K]
  //Swagger Step                  [214 + P]
  //Arrow Kick                    [623 + K]
  //Luminous Dive Kick            [214 + K]
  //Bakkai                        [236 + K]
  //Tenshin                       [63214 + K]
  //Swagger Hermit Punch          [214 + P, 6P]
  

  return false;
} 
