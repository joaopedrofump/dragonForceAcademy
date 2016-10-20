//
//  Midfielder.hpp
//  DragonForceAcadamy
//
//  Created by Joao Furriel on 20/10/16.
//  Copyright © 2016 João Furriel Pinheiro. All rights reserved.
//

#ifndef Midfielder_hpp
#define Midfielder_hpp

#include <stdio.h>
#include "Athlete.hpp"

class Midfielder : public Athlete {
private:
    unsigned int goalsScored;
    MidfielderPosition detailedPosition;
    
public:
    Midfielder(string name, Date birthdate, unsigned char height, MidfielderPosition detailedPosition);
    ~Midfielder();
    Position getPosition() const;
    unsigned int getID() const;
    
};

#endif /* Midfielder_hpp */