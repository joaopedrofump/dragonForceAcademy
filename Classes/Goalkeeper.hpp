//
//  Goalkeeper.hpp
//  DragonForceAcadamy
//
//  Created by Joao Furriel on 13/10/16.
//  Copyright © 2016 João Furriel Pinheiro. All rights reserved.
//

#ifndef Goalkeeper_hpp
#define Goalkeeper_hpp

#include <stdio.h>
#include <iostream>
#include "Athlete.hpp"

class Goalkeeper : public Athlete {
private:
    unsigned int goalsConceded;
    unsigned int saves;
        
public:
    Goalkeeper(string name, Date birthdate, unsigned char height);
    Position getPosition() const;
    unsigned int getID() const;

};

#endif /* Goalkeeper_hpp */
