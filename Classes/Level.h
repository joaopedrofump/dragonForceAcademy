#pragma once

//#include <iostream>
//#include "Utils.hpp"
#include "Athlete.hpp"
#include "Trainer.hpp"

using namespace std;

class Level
{
private:
	
	ageLevel ageLevelName;

	vector<Athlete*> players;
	vector<Trainer*> trainers;

	Worker* trainerResponsible;

public:
    
	Level(ageLevel ageLevelName, vector<Athlete *> playersVector, vector<Trainer*> trainersVector);
	Level(ifstream &in);





};
