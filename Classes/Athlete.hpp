//
//  Athlete.hpp
//  DragonForceAcadamy
//
//  Created by Joao Furriel on 12/10/16.
//  Copyright © 2016 João Furriel Pinheiro. All rights reserved.
//

#ifndef Athlete_hpp
#define Athlete_hpp

#include <stdio.h>
#include <iostream>
#include "Worker.hpp"

class Athlete : public Worker {
    
private:
    unsigned char height;

public:
    Athlete(string name, Date birthdate, unsigned char height);
    virtual Position getPosition() const = 0;
};

#endif /* Athlete_hpp */
