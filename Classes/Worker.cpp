//
//  Worker.cpp
//  DragonForceAcadamy
//
//  Created by Joao Furriel on 13/10/16.
//  Copyright © 2016 João Furriel Pinheiro. All rights reserved.
//

#include "Worker.hpp"

unsigned int Worker::workersCounter = 0;

Worker::Worker(string name, Date birthdate) {
    
    this->name = name;
    this->birthdate = birthdate;
    
}
