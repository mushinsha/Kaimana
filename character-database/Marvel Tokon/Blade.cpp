//  Blade.cpp
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
bool Blade::testForCharacterCombos() const
{
  
//MOVELIST BELOW

//OVERDRIVES
  //Bloodlust                               [236 + M+H]
  //Muramasa Moon                           [632146 + M+H]
  

//SPECIAL MOVES
  //Bullet Barrage                          [236 + L/M/H] (In Air Possible)
  //Vampire Slayer                          [623 + L/M/H] 
  //Vampire Cleave                          [214 + L/M/H] (In Air Possible)
  //Glaive Strike                           [22 + L/M/H]
  
  return false;
} 
