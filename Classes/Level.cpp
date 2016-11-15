#include "Level.h"

#include "Club.hpp"

class Match;

Level::Level(string yearOfSeason, string pathToSeasonFolder, string levelName, Club* parentClub) {
    
    this->yearOfSeason = yearOfSeason;
    this->levelName = levelName;
    this->pathToLevelFolder = stringPath(pathToSeasonFolder + "/" + this->levelName);
    this->pathToLevelAthletesFile = stringPath(this->pathToLevelFolder + "/Athletes.txt");
    this->pathToLevelCoachesFile = stringPath(this->pathToLevelFolder + "/Coaches.txt");
    this->pathToLevelMatchesFile = stringPath(this->pathToLevelFolder + "/Matches.txt");
    this->pathToLevelMatchesFolder = stringPath(this->pathToLevelFolder + "/Matches");
    this->lastMatchId = 0;
    
    if(levelName == "U13") {
        
        this->minAge = 11;
        this->maxAge = 13;
        this->minHeight = 130;
        this->levelEnum = U13;
        
    }
    
    else if(levelName == "U15") {
        
        this->minAge = 13;
        this->maxAge = 15;
        this->minHeight = 150;
        this->levelEnum = U15;
        
    }
    
    else if(levelName == "U17") {
        
        this->minAge = 15;
        this->maxAge = 17;
        this->minHeight = 170;
        this->levelEnum = U17;
        
    }
    
    else if(levelName == "U19") {
        
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
        
        if(tmpAthlete.length() == 0) {
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
		else if(stoi(tmpAthletePos) == DefenderPos){

			infoTmpAthlete = new InfoDF(tmpAthlete);
		}

		// Read Midfielders specific informations
		else if(stoi(tmpAthletePos) == MidfielderPos) {

			infoTmpAthlete = new InfoMF(tmpAthlete);
		}

		// Read Forwards specific informations
		else if (stoi(tmpAthletePos) == ForwardPos) {

			infoTmpAthlete = new InfoFW(tmpAthlete);
		}
			

		this->mapInfoPlayers.insert({ tmpAthleteId, infoTmpAthlete });
        
        map<unsigned int, Worker*> tmpMap =  parentClub->getAthletes();
        
        Worker* thisWorker = parentClub->getAthletes().at(tmpAthleteId);
        
        thisWorker->addInfo(infoTmpAthlete);

	}

	inStreamLevel.close();

	// Read information of coaches

	inStreamLevel.open(pathToLevelCoachesFile);
    
    string mainCoach;
    getline(inStreamLevel, mainCoach);
    
    if(mainCoach.length() != 0) {
        this->levelMainCoach = stoi(mainCoach);
    }
    else {
        this->levelMainCoach = -1;
    }
    
	while (!inStreamLevel.eof()) {

		string tmpCoach;
		getline(inStreamLevel, tmpCoach);
        
        if(tmpCoach.length() == 0) {
            continue;
        }

		coachesIdsVector.push_back(stoi(tmpCoach));
	}

	inStreamLevel.close();
    
	// Read information of matches

    inStreamLevel.open(this->pathToLevelMatchesFile);
    
    string lastMatchIdString;
    getline(inStreamLevel, lastMatchIdString);
    
    if(lastMatchIdString.size() != 0) {
        
        this->lastMatchId = stoi(lastMatchIdString);
        
    }
    
    while (!inStreamLevel.eof()) {
        
        string eachMatch;
        getline(inStreamLevel, eachMatch);
        
        if(eachMatch.length() != 0) {
            istringstream issEachMatch(eachMatch);
            unsigned int type;
            issEachMatch >> type;
            string waste;
            issEachMatch >> waste;
            Match *thisMatch;
            
            thisMatch = (type == 0) ? new Match(issEachMatch, parentClub, home) : thisMatch = new Match(issEachMatch, parentClub, away);
            this->levelMatches.push_back(thisMatch);
            
        }
        
    
    }
    
    
    inStreamLevel.close();
    
    //ler informação especifica do ficheiro de cada jogo
    for (size_t i = 0; i < this->levelMatches.size(); i++) {
        
        string pathToCurrentMatchFile = stringPath(this->getPathToLevelMatchesFolder() + "/" + this->levelMatches.at(i)->getId() + ".txt");
        ifstream currentMatchFileStream(pathToCurrentMatchFile);
        
        while (!currentMatchFileStream.eof()) {
            
            string currentPlayerLine;
            getline(currentMatchFileStream, currentPlayerLine);
            
            if (currentPlayerLine.size() != 0) {
                
                istringstream inStreamAthlete(currentPlayerLine);
                string separator;
                unsigned int id;
                unsigned int pos;
                Info* currentPlayerInfo;
                inStreamAthlete >> id;
                inStreamAthlete >> separator;
                inStreamAthlete >> pos;
                inStreamAthlete >> separator;
                
                switch (pos) {
                    case 1:
                        currentPlayerInfo = new InfoGK(inStreamAthlete);
                        break;
                    case 2:
                        currentPlayerInfo = new InfoDF(inStreamAthlete);
                        break;
                    case 3:
                        currentPlayerInfo = new InfoMF(inStreamAthlete);
                        break;
                    case 4:
                        currentPlayerInfo = new InfoFW(inStreamAthlete);
                        break;
                        
                }
                
                levelMatches.at(i)->addInfoPlayer(make_pair(pos, currentPlayerInfo));
                
            }
            
            
        }
        currentMatchFileStream.close();
        
        
    }
    
    

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

Level* Level::addCoachToLevel(unsigned int idCoach, bool mainCoach) {

	this->coachesIdsVector.push_back(idCoach);
	if (mainCoach) {
		this->levelMainCoach = idCoach;
	}
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
string Level::getPathToLevelMatchesFile() const {
    return this->pathToLevelMatchesFile;
}
string Level::getPathToLevelMatchesFolder() const {
    return this->pathToLevelMatchesFolder;
}

unsigned int Level::getLastMatchId() const {
    return this->lastMatchId;
}

void Level::updateLastMatchId() {
    this->lastMatchId++;
}

vector<Match*> Level::getAllLevelMatches() const {
    
    return this->levelMatches;
    
}

vector<Training*> Level::getAllLevelTrainings() const {
    return this->levelTrainings;
}

Level* Level::addMatchToLevel(Match* newMatch) {
    this->levelMatches.push_back(newMatch);
    return this;
}

Level* Level::addTrainingToLevel(Training* newTraining) {
    this->levelTrainings.push_back(newTraining);
    return this;
}
