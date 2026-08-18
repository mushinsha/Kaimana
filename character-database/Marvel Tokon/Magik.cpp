//  Magik.cpp
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
bool Magik::testForCharacterCombos() const
{
  
//MOVELIST BELOW

//OVERDRIVES
  //Zansei Rouga                            [632146 + HS] (In Air Possible)
  //Banki Messai                            [236236 + P]
  

//SPECIAL MOVES
  //Alpha Blade (Horizontal)                [236 + P] (In Air Possible)
  //Alpha Blade (Diagonal)                  [236 + K] (In Air Possible)
  //Beta Blade                              [623 + S] (In Air Possible)
  //Gamma Blade                             [236 + HS]
  //Resshou                                 [236 + S]
  //Rokusai (while in Resshou)              [236 + S]
  //Senshuu (while in Resshou or Rokusai)   [236 + K]
  //Genrouzan                               [63214 + S]
  //Shuriken                                [214 + P] (In Air Only)
  
  return false;
} 
