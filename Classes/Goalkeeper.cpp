//
//  Goalkeeper.cpp
//  DragonForceAcadamy
//
//  Created by Joao Furriel on 13/10/16.
//  Copyright © 2016 João Furriel Pinheiro. All rights reserved.
//

#include "Goalkeeper.hpp"

Goalkeeper::Goalkeeper(string name, Date birthdate, unsigned char height, unsigned int id) : Athlete(name, birthdate, height, id) {

    if (id != 0) {
        this->id = id;
    }
    
    this->position = GoalkeeperPos;
    this->generalInfo = new InfoGK();
    
}

Goalkeeper::Goalkeeper(string &newGK) : Athlete(newGK, GoalkeeperPos){
    
    this->generalInfo = new InfoGK();
    
}

Goalkeeper::~Goalkeeper() {
    
    delete this->generalInfo;
    cout << "Goalkeeper destroyed\n" << endl;
}


/*Position Goalkeeper::getPosition() const {
    
    return GoalkeeperPos;
    
}*/

unsigned int Goalkeeper::getID() const {
    
    return this->id;

}

Info* Goalkeeper::getInfo() const {
    
    return this->generalInfo;
    
}

void Goalkeeper::addInfo(Info* moreInfo) {
    
    *(this->generalInfo) += moreInfo;
    
}
