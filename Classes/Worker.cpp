//
//  Worker.cpp
//  DragonForceAcadamy
//
//  Created by Joao Furriel on 13/10/16.
//  Copyright © 2016 João Furriel Pinheiro. All rights reserved.
//

#include "Worker.hpp"

unsigned int Worker::workersCounter = 0;

Worker::Worker(string name, Date birthdate, unsigned int id) {
    
    this->name = name;
    this->birthdate = birthdate;

	if (id == 0) {
		this->id = ++workersCounter;
	}
	else {
		this->id = id;
	}
	//Fazer id com o static wrkersCounter
    
}

Worker::~Worker() {
    
    cout << "Worker Destroyed\n" << endl;
}

unsigned int Worker::getID() const{
	return this->id;
}

bool Worker::operator==(Worker* worker) const {

	if (this->getID() == worker->getID())
		return true;
	return false;
}


void Worker::setStatus(bool newStatus) {

	this->status = newStatus;
}

unsigned int Worker::getIdade() const {
	Date currentDate(true);


	if (birthdate.getMonth() > currentDate.getMonth())
	{
		return (currentDate.getYear() - birthdate.getYear() - 1);
	}

	if (birthdate.getMonth() == currentDate.getMonth())
	{
		if (birthdate.getDay() > currentDate.getDay())
		{
			return (currentDate.getYear() - birthdate.getYear() - 1);
		}
		else
		{
			return (currentDate.getYear() - birthdate.getYear());
		}
	}
}