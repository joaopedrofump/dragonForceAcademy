#include "Level.h"

#include "Club.hpp"

Level::Level(string yearOfSeason, string pathToSeasonFolder, string levelName, Club* parentClub) {

	this->levelName = levelName;
	this->pathToLevelFolder = stringPath(pathToSeasonFolder + "/" + this->levelName);
	this->pathToLevelAthletesFile = stringPath(this->pathToLevelFolder + "/Athletes.txt");
	this->pathToLevelCoachesFile = stringPath(this->pathToLevelFolder + "/Coaches.txt");

	if (levelName == "U13") {

		this->minAge = 11;
		this->maxAge = 13;
		this->minHeight = 130;
		this->levelEnum = U13;

	}

	else if (levelName == "U15") {

		this->minAge = 13;
		this->maxAge = 15;
		this->minHeight = 150;
		this->levelEnum = U15;

	}

	else if (levelName == "U17") {

		this->minAge = 15;
		this->maxAge = 17;
		this->minHeight = 170;
		this->levelEnum = U17;

	}

	else if (levelName == "U19") {

		this->minAge = 17;
		this->maxAge = 19;
		this->minHeight = 175;
		this->levelEnum = U19;

	}

	else {

		this->minAge = 19;
		this->maxAge = 45;
		this->minHeight = 180;
		this->levelEnum = Seniors;

	}



	// Read information of this level
	ifstream inStreamLevel;

	//Read information of athletes

	inStreamLevel.open(this->pathToLevelAthletesFile);

	while (!inStreamLevel.eof()) {

		string tmpAthlete;
		getline(inStreamLevel, tmpAthlete);

		if (tmpAthlete == FILE_SEPARATOR)
			break;

		if (tmpAthlete.length() == 0) {
			continue;
		}


		unsigned int tmpAthleteId = atoi(tmpAthlete.substr(0, tmpAthlete.find(';', 0) - 1).c_str());

		tmpAthlete = tmpAthlete.substr(tmpAthlete.find(';', 0) + 2);

		string tmpAthletePos = tmpAthlete.substr(0, tmpAthlete.find(';', 0) - 1);

		tmpAthlete = tmpAthlete.substr(tmpAthlete.find(';', 0) + 2);


		Info* infoTmpAthlete;

		// Read Goalkeepers specific informations
		if (stoi(tmpAthletePos) == GoalkeeperPos) {

			infoTmpAthlete = new InfoGK(tmpAthlete);

		}

		// Read Defenders specific informations
		else if (stoi(tmpAthletePos) == DefenderPos) {

			infoTmpAthlete = new InfoDF(tmpAthlete);
		}

		// Read Midfielders specific informations
		else if (stoi(tmpAthletePos) == MidfielderPos) {

			infoTmpAthlete = new InfoMF(tmpAthlete);
		}

		// Read Forwards specific informations
		else if (stoi(tmpAthletePos) == ForwardPos) {

			infoTmpAthlete = new InfoFW(tmpAthlete);
		}


		this->mapInfoPlayers.insert({ tmpAthleteId, infoTmpAthlete });

		map<unsigned int, Worker*> tmpMap = parentClub->getAthletes();

		Worker* thisWorker = parentClub->getAthletes().at(tmpAthleteId);

		thisWorker->addInfo(infoTmpAthlete);

	}

	inStreamLevel.close();

	// Read information of coaches

	inStreamLevel.open(pathToLevelCoachesFile);

	string mainCoach;
	getline(inStreamLevel, mainCoach);

	if (mainCoach.length() != 0) {
		this->levelMainCoach = stoi(mainCoach);
	}
	else {
		this->levelMainCoach = -1;
	}

	while (!inStreamLevel.eof()) {

		string tmpCoach;
		getline(inStreamLevel, tmpCoach);

		if (tmpCoach.length() == 0) {
			continue;
		}

		coachesIdsVector.push_back(stoi(tmpCoach));
	}


	inStreamLevel.close();
}

unsigned int Level::getMinAge() const
{
	return minAge;
}

unsigned int Level::getMaxAge() const
{
	return maxAge;
}

char Level::getMinHeight() const
{
	return minHeight;
}

map<unsigned int, Info*> Level::getMapInfoPlayers() const{
    
    return this->mapInfoPlayers;
    
}

Level* Level::addAthleteToLevel(pair<unsigned int, Info*> playerInfo) {
    
    this->mapInfoPlayers.insert(playerInfo);
    return this;
    
}

string Level::getLevelName() const {
    
    return this->levelName;
}

vector<unsigned int> Level::getCoaches() const {
    return this->coachesIdsVector;
}

int Level::getMainCoachId() const {
    return this->levelMainCoach;
}

string Level::getPathToLevelFolder() const {
    return this->pathToLevelFolder;
}
string Level::getPathToLevelAthletesFile() const {
    return this->pathToLevelAthletesFile;
}
string Level::getPathToLevelCoachesFile() const {
    return this->pathToLevelCoachesFile;
}

