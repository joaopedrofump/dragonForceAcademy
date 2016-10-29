//
//  Athlete.cpp
//  DragonForceAcadamy
//
//  Created by Joao Furriel on 12/10/16.
//  Copyright © 2016 João Furriel Pinheiro. All rights reserved.
//

#include "Athlete.hpp"

Athlete::Athlete(string name, Date birthdate, unsigned char height, unsigned int id) : Worker(name, birthdate, id) {
    
    this->height = height;
    this->ecg = NULL;
    
}

/*Athlete::Athlete(ifstream &in) {

	string tmpString;
	getline(in, tmpString);

	this->id = atoi( tmpString.substr(0, tmpString.find(';', 0)).c_str() );

	tmpString = tmpString.substr(tmpString.find(';', 0) + 1);

	this->name = tmpString.substr(0, tmpString.find(';', 0));

	tmpString = tmpString.substr(tmpString.find(';', 0) + 1);

	this->birthdate = Date(tmpString.substr(0, tmpString.find(';', 0)));

	tmpString = tmpString.substr(tmpString.find(';', 0) + 1);

	this->height = atoi(tmpString.substr(0, tmpString.find(';', 0)).c_str());

	tmpString = tmpString.substr(tmpString.find(';', 0) + 1);

	this->position = positionsMap.at(tmpString);


}*/

Athlete::~Athlete() {
    
    if(this->ecg) {
        delete this->ecg;
    }
    cout << "Athlete Destroyed\n";
    
}

void Athlete::addECG(bool resultado) {
    
    this->ecg = new ECG(resultado);
}
