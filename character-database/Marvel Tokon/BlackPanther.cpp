//  BlackPanther.cpp
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
bool BlackPanther::testForCharacterCombos() const
{
  
//MOVELIST BELOW

//OVERDRIVES
  //Warrior Queen                           [236 + M+H] (In Air Possible)
  //Heart-Shaped Herb                       [632146 + M+H]
  

//SPECIAL MOVES
  //Spear of Bashenga                       [236 + L/M/H] (In Air Possible)
  //Wild Hunt                               [623 + L/M/H] 
  //Predator Arts                           [214 + L/M/H] (In Air Possible)
  //Vibranium Daggers                       [22 + L/M/H] (In Air Possible)
  
  return false;
} 
