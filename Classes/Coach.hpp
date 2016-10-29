#pragma once

/*#include <stdio.h>
#include <iostream>*/
#include "Worker.hpp"

class Coach : public Worker {

private:
	CoachType trainerPosition;

public:
	Coach(string name, Date birthdate, CoachType coachRole, unsigned int id = 0);
	Coach(ifstream &in);
	unsigned int getID() const;
};
