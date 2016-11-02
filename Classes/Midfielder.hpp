//
//  Midfielder.hpp
//  DragonForceAcadamy
//
//  Created by Joao Furriel on 20/10/16.
//  Copyright © 2016 João Furriel Pinheiro. All rights reserved.
//
#pragma once

#ifndef Midfielder_hpp
#define Midfielder_hpp

#include "Forward.hpp"

class Midfielder : public Athlete {
private:
    unsigned int goalsScored;
	//MidfielderPosition detailedPosition;
    
public:
    Midfielder(string name, Date birthdate, unsigned char height, unsigned int id = 0);
    ~Midfielder();
    Position getPosition() const;
    unsigned int getID() const;
    
};

#endif /* Midfielder_hpp */
