//  Kain.cpp
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
//  Kaimana Kain character combo checks and animation calls. First released by ParadiseArcadeShop.com November, 2023
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
bool Kain::testForCharacterCombos() const
{

  //Special Moves
    //Schwarze Flamme (right)                 [236 + P]
    //Schwarze Flamme (left)                  [214 + P]
    //Schwarzer Panzer (right)                [236 + K]
    //Schwarzer Panzer (left)                 [214 + K]
    //Schwarze Lanze                          [(2)8 + K]
    //Schwarzes Rondo (right)                 [214 + P]
    //Schwarzes Rondo (left)                  [236 + P]

  //Ignition Gears
    //Himmlischer Atem Neo (right)            [236236 + A or (RL[C])
    //Himmlischer Atem Neo (left)             [214214 + A or (RL[C])
    //Himmlische Seele (right)                [236236 + B or (RL[D])
    //Himmlische Seele (left)                 [214214 + B or (RL[D])

  //Hidden Gear
    //Himmlischer Edelstein (right)           [236236 + R1]
    //Himmlischer Edelstein (left)            [214214 + R1]
  
  return false;
} 
