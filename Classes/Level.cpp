#include "Level.h"


Level::Level(ageLevel ageLevelName, vector<Coach*> coachesVector, map<unsigned int, Info> mapInfoSeason) {

	this->ageLevelName = ageLevelName;
	this->trainers = coachesVector;
	this->mapInfoSeason = mapInfoSeason;

}

Level::Level(ifstream &in, string yearOfSeason, string fileClub) {

	string tmpString;
	getline(in, tmpString);


	// Read information of this level
	ifstream inStreamLevel;

	inStreamLevel.open((fileClub + "\\" + trimLink(yearOfSeason) + "\\" + tmpString).c_str());

	
	if (!inStreamLevel.eof()) {
		
		string idHeadCoach;
		getline(inStreamLevel, idHeadCoach);

		this->headCoachId = atoi(idHeadCoach.c_str());

		string ages;
		getline(inStreamLevel, ages);

		this->minAge =atoi(ages.substr(0, ages.find('-', 0)).c_str());

		ages = ages.substr(ages.find('-', 0) + 2);

		this->maxAge = atoi(ages.c_str());

		string heightLevel;

		getline(inStreamLevel, heightLevel);
		this->minHeight = atoi(heightLevel.c_str());

	}

	inStreamLevel.close();

	//Read information of athletes
	ifstream inStreamCoachesLevel;

	inStreamCoachesLevel.open((fileClub + "\\" + trimLink(yearOfSeason) + "\\" + trimLink(tmpString) + "\\Athletes.txt").c_str());

	while (!inStreamCoachesLevel.eof()) {

		string tmpAthlete;
		getline(inStreamCoachesLevel, tmpAthlete);

		unsigned int tmpAthleteId = atoi(tmpAthlete.substr(0, tmpAthlete.find(';', 0)).c_str());

		tmpAthlete = tmpAthlete.substr(tmpAthlete.find(';', 0) + 1);

		Date tmpExpECG(tmpAthlete.substr(0, tmpAthlete.find(';', 0)));

		tmpAthlete = tmpAthlete.substr(tmpAthlete.find(';', 0) + 1);

		Fraction tmpAthleteAssiduity(tmpAthlete.substr(0, tmpAthlete.find(';', 0)));

		tmpAthlete = tmpAthlete.substr(tmpAthlete.find(';', 0) + 1);

		unsigned int tmpAthleteGoalsScored = atoi(tmpAthlete.substr(0, tmpAthlete.find(';', 0)).c_str());

		tmpAthlete = tmpAthlete.substr(tmpAthlete.find(';', 0) + 1);

		Fraction tmpAthletePassAcc(tmpAthlete);




		Info infoTmpAthlete;
		infoTmpAthlete.trainingFreq = tmpAthleteAssiduity;
		infoTmpAthlete.goalsScored = tmpAthleteGoalsScored;
		infoTmpAthlete.passAccuracy = tmpAthletePassAcc;

		this->mapInfoSeason.insert({ tmpAthleteId, infoTmpAthlete });

	}

	inStreamCoachesLevel.close();
	
}