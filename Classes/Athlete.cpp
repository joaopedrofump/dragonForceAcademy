//
//  Athlete.cpp
//  DragonForceAcadamy
//
//  Created by Joao Furriel on 12/10/16.
//  Copyright © 2016 João Furriel Pinheiro. All rights reserved.
//

#include "Athlete.hpp"

Athlete::Athlete(string name, Date birthdate, unsigned char height) : Worker(name, birthdate) {
    
    this->height = height;
    this->ecg = NULL;
    
}

Athlete::~Athlete() {
    
    if(this->ecg) {
        delete this->ecg;
    }
    cout << "Athlete Destroyed\n";
    
}

void Athlete::addECG(bool resultado) {
    
    this->ecg = new ECG(resultado);
}
