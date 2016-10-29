#pragma once

#include "Goalkeeper.hpp"

using namespace std;

class Level
{
private:
	
	ageLevel ageLevelName;

	vector<Coach*> trainers;
	map<unsigned int, Info> mapInfoSeason;

	unsigned int headCoachId;

	unsigned int minAge;
	unsigned int maxAge;

	unsigned int minHeight;

	//vector<Tournament> tournaments;
	//vector<Training> trainings;
	//vector<Match> friendlys;

public:
	Level(ageLevel ageLevelName, vector<Coach*> coachesVector, map<unsigned int, Info> mapInfoSeason);
	Level(ifstream &in, string yearOfSeason, string fileClub); 





};