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
    Info* generalInfo;
    
public:
    Defender(string name, Date birthdate, unsigned char height, unsigned int = 0);
	Defender(string &newDF);
    ~Defender();
    unsigned int getID() const;
    Info* getInfo() const;
    void addInfo(Info* moreInfo);
    
};
    

#endif /* Defender_hpp */
