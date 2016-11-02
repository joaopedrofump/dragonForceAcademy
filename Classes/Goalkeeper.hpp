//
//  Goalkeeper.hpp
//  DragonForceAcadamy
//
//  Created by Joao Furriel on 13/10/16.
//  Copyright © 2016 João Furriel Pinheiro. All rights reserved.
//
#pragma once

#ifndef Goalkeeper_hpp
#define Goalkeeper_hpp

#include "Defender.hpp"

class Goalkeeper : public Athlete {
private:
    Info* generalInfo;
        
public:
    Goalkeeper(string name, Date birthdate, unsigned char height, unsigned int = 0);
	Goalkeeper(string &newGK);
    ~Goalkeeper();
    unsigned int getID() const;
    Info* getInfo() const;
    void addInfo(Info* moreInfo);

};

#endif /* Goalkeeper_hpp */
