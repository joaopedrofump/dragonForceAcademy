//
//  Defender.cpp
//  DragonForceAcadamy
//
//  Created by Joao Furriel on 19/10/16.
//  Copyright © 2016 João Furriel Pinheiro. All rights reserved.
//

#include "Defender.hpp"

Defender::Defender(string name, Date birthdate, unsigned char height, unsigned int id) : Athlete(name, birthdate, height, id) {
    
    if (id != 0) {
        this->id = id;
    }
    
    this->position = DefenderPos;
    this->generalInfo = new InfoDF();
}


Defender::~Defender() {
    cout << "Defender destroyed" << endl;
}

Position Defender::getPosition() const {
    
    return DefenderPos;
    
}

unsigned int Defender::getID() const{
    
    return this->id;
    
}

Info* Defender::getInfo() const {
    return this->generalInfo;
}

void Defender::addInfo(Info* moreInfo) {
    
    *(this->generalInfo) += moreInfo;
    
}
