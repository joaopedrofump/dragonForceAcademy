//
//  Athlete.hpp
//  DragonForceAcadamy
//
//  Created by Joao Furriel on 12/10/16.
//  Copyright © 2016 João Furriel Pinheiro. All rights reserved.
//
#pragma once

#ifndef Athlete_hpp
#define Athlete_hpp

#include "Coach.hpp"
#include "ECG.hpp"

class Athlete : public Worker {
    
protected:
    unsigned char height;
    ECG* ecg; //apontador para ECG quando houver classe
	Position position;

public:
    Athlete(string name, Date birthdate, unsigned char height, Position position, unsigned int id = 0);

	Athlete(string &newAthlete, Position position);

    ~Athlete();

    unsigned int getPosition() const;

	unsigned int getHeight() const;

    void addECG(bool resultado);

	bool isAthlete() const;
};

#endif /* Athlete_hpp */
