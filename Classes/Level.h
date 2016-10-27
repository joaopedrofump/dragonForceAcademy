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

	vector<Worker*> workers;

	Trainer* trainerResponsible;

	unsigned int minAge;
	unsigned int maxAge;

	unsigned int minHeight;

	//vector<Tournament> tournaments;
	//vector<Training> trainings;
	//vector<Match> friendlys;

public:
	Level(ageLevel ageLevelName, vector<Worker*> workersVector);
	Level(ifstream &in);





};