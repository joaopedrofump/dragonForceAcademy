#include "Level.h"

//#include "Club.hpp"

/*Level::Level(ageLevel ageLevelName, vector<Coach*> coachesVector, map<Athlete*, Info*> mapInfoSeason) {

	this->ageLevelName = ageLevelName;
	this->trainers = coachesVector;
	this->mapInfoSeason = mapInfoSeason;

}*/

Level::Level(string yearOfSeason, string fileClub, string levelName) {

    if(levelName == "U13") {
        
        this->minAge = 11;
        this->maxAge = 13;
        this->minHeight = 130;
        this->ageLevelName = U13;
        
    }
    
    else if(levelName == "U15") {
        
        this->minAge = 13;
        this->maxAge = 15;
        this->minHeight = 150;
        this->ageLevelName = U15;
        
    }
    
    else if(levelName == "U17") {
        
        this->minAge = 15;
        this->maxAge = 17;
        this->minHeight = 170;
        this->ageLevelName = U17;
        
    }
    
    else if(levelName == "U19") {
        
        this->minAge = 17;
        this->maxAge = 19;
        this->minHeight = 175;
        this->ageLevelName = U19;
        
    }
    
    else {
        
        this->minAge = 19;
        this->maxAge = 45;
        this->minHeight = 180;
        this->ageLevelName = Seniors;
        
    }
    
	// Read information of this level
    ifstream inStreamLevel(stringPath(path() + fileClub + "/" + levelName + "/infoLevel.txt"));

	if (!inStreamLevel.eof()) {
		
		string idHeadCoach;
		getline(inStreamLevel, idHeadCoach);
        
        if(idHeadCoach.length() != 0) {
            
            unsigned int headCoachId = atoi(idHeadCoach.c_str());
            
            this->mainCoachID = headCoachId;
        }
            
	}

	inStreamLevel.close();

	//Read information of athletes
    
    string caminho = stringPath(path() + fileClub  + "/" + levelName + "/Athletes.txt");
    
    inStreamLevel.open(caminho.c_str());


	while (!inStreamLevel.eof()) {

		string tmpAthlete;
		getline(inStreamLevel, tmpAthlete);

		if (tmpAthlete == FILE_SEPARATOR)
			break;
        
        if(tmpAthlete.length() == 0) {
            continue;
        }


		unsigned int tmpAthleteId = atoi(tmpAthlete.substr(0, tmpAthlete.find(';', 0) - 1).c_str());

		tmpAthlete = tmpAthlete.substr(tmpAthlete.find(';', 0) + 2);

		string tmpAthletePos = tmpAthlete.substr(0, tmpAthlete.find(';', 0) - 1);

		tmpAthlete = tmpAthlete.substr(tmpAthlete.find(';', 0) + 2);
		

		Info* infoTmpAthlete;

		// Read Goalkeepers specific informations
		if (positionsMap.at(tmpAthletePos) == GoalkeeperPos) {


			infoTmpAthlete = new InfoGK(tmpAthlete);

		}

		// Read Defenders specific informations
		else if(positionsMap.at(tmpAthletePos) == DefenderPos){


			infoTmpAthlete = new InfoDF(tmpAthlete);

		}

		// Read Midfielders specific informations
		else if(positionsMap.at(tmpAthletePos) == MidfielderPos) {

			infoTmpAthlete = new InfoMF(tmpAthlete);
		}

		// Read Forwards specific informations
		else if (positionsMap.at(tmpAthletePos) == ForwardPos) {

			infoTmpAthlete = new InfoFW(tmpAthlete);
		}
			

		this->mapInfoPlayers.insert({ tmpAthleteId, infoTmpAthlete });

	}

	inStreamLevel.close();

	// Read information of coaches

	inStreamLevel.open(stringPath(path() + fileClub + "/" + levelName + "Coaches.txt").c_str());
	
	while (!inStreamLevel.eof()) {

		string tmpCoach;
		getline(inStreamLevel, tmpCoach);
        
        if(tmpCoach.length() == 0) {
            continue;
        }


		trainersIds.push_back(atoi(tmpCoach.c_str()));
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

string Level::levelName() const {
    
    string result;
    
    switch (this->ageLevelName) {
        case U13:
            result = "U13";
            break;
        case U15:
            result = "U15";
            break;
        case U17:
            result = "U17";
            break;
        case U19:
            result = "U19";
            break;
        case Seniors:
            result = "Seniors";
            break;
        default:
            break;
    }
    return result;
}
