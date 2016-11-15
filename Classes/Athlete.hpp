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

class Athlete : public Worker {
    
protected:
    unsigned char height;
    ECG* ecg; //apontador para ECG quando houver classe
	Position position;

public:
    Athlete(string name, Date birthdate, unsigned int civilID, unsigned char height, unsigned int id = 0);

	Athlete(string &newAthlete, Position position);

    ~Athlete();

    unsigned int getPosition() const;

	unsigned int getHeight() const;

	ECG* getECG() const;
    
    void updateECG(bool resultado, Date expirationDate);

	bool isAthlete() const;
    
    string generateInfo() const;
    
    vector<string> showInScreen() const;
    
    void setBirthDate(Date newBirthdate);
    
    void setHeight(unsigned int newHeight);
};

#endif /* Athlete_hpp */
