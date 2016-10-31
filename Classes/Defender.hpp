//
//  Defender.hpp
//  DragonForceAcadamy
//
//  Created by Joao Furriel on 19/10/16.
//  Copyright © 2016 João Furriel Pinheiro. All rights reserved.
//
#pragma once

#ifndef Defender_hpp
#define Defender_hpp

#include "Midfielder.hpp"

class Defender : public Athlete {
private:
    unsigned int goalsScored;
    //DefenderPosition detailedPosition;
public:
    Defender(string name, Date birthdate, unsigned char height, unsigned int = 0);
    ~Defender();
    Position getPosition() const;
    unsigned int getID() const;
    
};
    

#endif /* Defender_hpp */
