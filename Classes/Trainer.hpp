#pragma once

/*#include <stdio.h>
#include <iostream>*/
#include "Worker.hpp"

class Trainer : public Worker {

private:
	Position trainerPosition;

public:
	Trainer(string name, Date birthdate, Position trainerPosition);
	Position getPosition();
	unsigned int getID() const;
};
