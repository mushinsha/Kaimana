//  Carnage.cpp
//
//  Created:  August 2026 by Hunter "Mushinsha" Nelson
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
bool Carnage::testForCharacterCombos() const
{
  
//MOVELIST BELOW

//OVERDRIVES
  //Living Legend                           [236 + M+H]
  //Sentinel of Liberty                     [632146 + M+H]
  

//SPECIAL MOVES
  //Shield Strike                           [236 + L/M/H] (In Air Possible)
  //Soaring Justice                         [623 + L/M/H] (In Air Possible)
  //Freedom Charge                          [214 + L/M/H] (In Air Possible)
  //Shield Shock                            [22 + L/M/H]
  
  return false;
} 
