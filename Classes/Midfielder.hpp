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
    Info* generalInfo;
public:
    Midfielder(string name, Date birthdate, unsigned char height, unsigned int id = 0);
	Midfielder(string &newMF);
    ~Midfielder();
    unsigned int getID() const;
    Info* getInfo() const;
    void addInfo(Info* moreInfo);
    
};

#endif /* Midfielder_hpp */
