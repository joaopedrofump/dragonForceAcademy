//
//  Midfielder.cpp
//  DragonForceAcadamy
//
//  Created by Joao Furriel on 20/10/16.
//  Copyright © 2016 João Furriel Pinheiro. All rights reserved.
//

#include "Midfielder.hpp"

Midfielder::Midfielder(string name, Date birthdate, unsigned char height, unsigned int id) : Athlete(name, birthdate, height, id) {

    if (id != 0) {
        this->id = id;
    }
    
    this->position = MidfielderPos;
    this->generalInfo = new InfoMF();
}

Midfielder::Midfielder(string &newMF) : Athlete(newMF, MidfielderPos) {}

Midfielder::~Midfielder() {
    
    cout << "Midfielder destroyed\n" << endl;
    
}

/*Position Midfielder::getPosition() const {
    return MidfielderPos;
    
}*/

unsigned int Midfielder::getID() const {
    
    return this->id;
    
}

Info* Midfielder::getInfo() const {
    return this->generalInfo;
}

void Midfielder::addInfo(Info* moreInfo) {
    
    *(this->generalInfo) += moreInfo;
    
}
