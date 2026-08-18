//  Yamcha.cpp
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
bool Yamcha::testForCharacterCombos() const
{
  
//MOVELIST BELOW

//OVERDRIVES
  //Level 1 Super                           [236 + L+M]
  //Level 2 Super                           [236 + H+S]
  //Level 3 Super                           [236 + L+M or H+S]
  

//SPECIAL MOVES
  //Shield Strike                           [236 + L/M/H]
  //Soaring Justice                         [623 + L/M/H]
  //Shield Shock                            [22 + L/M/H]
  
  return false;
} 
