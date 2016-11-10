#pragma once

#include "Goalkeeper.hpp"

using namespace std;

class Club;
class Level
{
private:
	
	ageLevel ageLevelName;

	vector<Coach*> trainers;
	map<Athlete*, Info*> mapInfoSeason;

	Coach* mainCoach;

	unsigned int minAge;
	unsigned int maxAge;

	char minHeight;

	//vector<Tournament> tournaments;
	//vector<Training> trainings;
	//vector<Match> friendlys;

public:

	//Level(ageLevel ageLevelName, vector<Coach*> coachesVector, map<Athlete*, Info*> mapInfoSeason);
	Level(ifstream &in, string yearOfSeason, string fileClub, Club* club); 
	unsigned int getMinAge() const;
	unsigned int getMaxAge() const;
	char getMinHeight() const;
	map<Athlete*, Info*> getMapInfoSeason() const;






};
