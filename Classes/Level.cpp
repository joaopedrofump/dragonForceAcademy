#include "Level.h"

#include "Club.hpp"

class Match;

Level::Level(string yearOfSeason, string pathToSeasonFolder, string levelName, Club* parentClub) {
    
	this->parentClub = parentClub;
    this->yearOfSeason = yearOfSeason;
    this->levelName = levelName;
    this->pathToLevelFolder = stringPath(pathToSeasonFolder + "/" + this->levelName);
    this->pathToLevelAthletesFile = stringPath(this->pathToLevelFolder + "/Athletes.txt");
    this->pathToLevelCoachesFile = stringPath(this->pathToLevelFolder + "/Coaches.txt");
    this->pathToLevelMatchesFile = stringPath(this->pathToLevelFolder + "/Matches.txt");
    this->pathToLevelMatchesFolder = stringPath(this->pathToLevelFolder + "/Matches");
    this->pathToLevelTrainingsFile = stringPath(this->pathToLevelFolder + "/Trainings.txt");
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

		if (tmpAthlete.length() == 0) {
			continue;
		}


		unsigned int tmpAthleteId = stoi(readAndCut(tmpAthlete));

		string tmpAthletePos = readAndCut(tmpAthlete);
	
		Info* infoTmpAthlete;

		// Read Goalkeepers specific informations
		if (stoi(tmpAthletePos) == GoalkeeperPos) {

            istringstream inStream(tmpAthlete);
			infoTmpAthlete = new InfoGK(inStream);

            
		}

		// Read Defenders specific informations
		else if (stoi(tmpAthletePos) == DefenderPos) {

            istringstream inStream(tmpAthlete);
			infoTmpAthlete = new InfoDF(inStream);
		}

		// Read Midfielders specific informations
		else if (stoi(tmpAthletePos) == MidfielderPos) {

            istringstream inStream(tmpAthlete);
            infoTmpAthlete = new InfoMF(inStream);
		}

		// Read Forwards specific informations
		else if (stoi(tmpAthletePos) == ForwardPos) {

            istringstream inStream(tmpAthlete);
            infoTmpAthlete = new InfoFW(inStream);
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
            Match* thisMatch;
            
            thisMatch = (type == 0) ? new Match(issEachMatch, parentClub, home) : thisMatch = new Match(issEachMatch, parentClub, away);
            this->levelMatches.push_back(thisMatch);
            
        }
        
    
    }

	sort(this->levelMatches.begin(), this->levelMatches.end(), [](Match* a, Match* b) { return *b < *a; });
    
    
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

	inStreamLevel.close();
    
    //read trainings info
    
    inStreamLevel.open(this->pathToLevelTrainingsFile);
    
    while (!inStreamLevel.eof()) {
        
        string eachTraining;
        getline(inStreamLevel, eachTraining);
        
        if(eachTraining.length() != 0) {
            istringstream issEachTraining(eachTraining);
            Training* trainingToAdd = new Training(issEachTraining);
            this->levelTrainings.push_back(trainingToAdd);
            
        }
        
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

string Level::getYear() const {
	return this->yearOfSeason;
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

vector<Match*> Level::getAllLevelMatches(bool onlyNotPlayed) const {
    
	vector<Match*> result;
	for (vector<Match*>::const_iterator it = this->levelMatches.begin(); it != levelMatches.end(); it++) {
		if (!onlyNotPlayed || (*it)->getPlayed()) {
			result.push_back(*it);
		}
	}
    return this->levelMatches;
    
}

vector<Match*> Level::getMatchesReadyToPlay() const {

	vector<Match*> tmpVector = this->getAllLevelMatches(true);

	vector<Match*> result;
	for (vector<Match*>::const_iterator it = tmpVector.begin(); it != tmpVector.end(); it++) {
		if ((*it)->getInfoPlayers().size()/* > 18*/) {
			result.push_back(*it);
		}
	}

	return result;
}

vector<Training*> Level::getAllLevelTrainings() const {
    return this->levelTrainings;
}

Level* Level::addMatchToLevel(Match* newMatch) {
    this->levelMatches.push_back(newMatch);
	sort(levelMatches.begin(), levelMatches.end(), [](Match* a, Match* b) { return *b < *a; });
    return this;
}

Table Level::showAthletesOfLevel() const {
	Table athletesTable({ "ID", "Civil ID", "Name", "Birthdate" , "Age", "Height", "Position", "Level" ,"Status", "ECG" });
	map<unsigned int, Info*> athletes = this->getMapInfoPlayers();
	map<unsigned int, Info*>::iterator workersIterator;

	bool firstActive = false;
	for (workersIterator = athletes.begin(); workersIterator != athletes.end(); workersIterator++) {
		if (parentClub->getAthletes().at(workersIterator->first)->isActive() && !firstActive) {

			athletesTable.addNewLine(parentClub->getAthletes().at(workersIterator->first)->showInScreen());
			firstActive = true;
			continue;
		}

		if (parentClub->getAthletes().at(workersIterator->first)->isActive() && firstActive && parentClub->getAthletes().at(workersIterator->first)->isAthlete()) {

			athletesTable.addDataInSameLine(parentClub->getAthletes().at(workersIterator->first)->showInScreen()); //addDataInSameLine
		}
	}

	return athletesTable;
}

Level* Level::addTrainingToLevel(Training* newTraining) {
    this->levelTrainings.push_back(newTraining);
    return this;
}


void Level::showMatches(vector<Match*> matches) {

	unsigned int tmpID = 0;
	Table matchesTable({ "ID", "Date", "Home Team", "Score", "Away Team", "Players Called-up" });

	for (vector<Match*>::iterator it = matches.begin(); it != matches.end(); it++) {
		matchesTable.addNewLine((*it)->showInScreen(++tmpID));
	}

	cout << matchesTable;
}

void Level::saveLevelTrainings() const {
    
    ofstream saveToTrainingsFile(this->pathToLevelTrainingsFile);
    
    for (size_t i = 0; i < this->levelTrainings.size(); i++) {
        
        saveToTrainingsFile << *this->levelTrainings.at(i);
        
        if (i != (this->levelTrainings.size() - 1)) {
            saveToTrainingsFile << endl;
        }
        
    }
    
}

void Level::scheduleTraining(Date trainingDate) {
    
    if (trainingDate < Date()) {
        throw string("Can't schedule trainings for the past.");
    }
    
    
    vector<unsigned int> players;
    Training* trainingToAdd = new Training(trainingDate, players);
    this->addTrainingToLevel(trainingToAdd);
    
}

void Level::registerTraining(unsigned int trainingId, vector<unsigned int> missingPlayers) {
    
    vector<Training*> listOfLevelTrainings = this->getAllLevelTrainings();
    vector<Training*>::const_iterator trainingToRegister = listOfLevelTrainings.begin();
    while (trainingToRegister != listOfLevelTrainings.end()) {
        
        if ((*trainingToRegister)->getId() == trainingId) {
            
            break;
            
        }
        trainingToRegister++;
        
    }
    
    
    if(trainingToRegister == listOfLevelTrainings.end()) {
        
        throw string("Error: Training not found.");
        
    }
    
    vector<unsigned int> filteredVector;
    map<unsigned int, Info*> mapLevelPLayers = this->getMapInfoPlayers();
    
    for (vector<unsigned int>::const_iterator missingPlayersIterator = missingPlayers.begin(); missingPlayersIterator != missingPlayers.end(); missingPlayersIterator++) {
        
        if (mapLevelPLayers.find(*missingPlayersIterator) != mapLevelPLayers.end()) {
            
            mapLevelPLayers.erase(mapLevelPLayers.find(*missingPlayersIterator));
            missingPlayersIterator--;
            
        }
    }
    
    for (map<unsigned int, Info*>::const_iterator iteratorPlayersMap = mapLevelPLayers.begin(); iteratorPlayersMap != mapLevelPLayers.end(); iteratorPlayersMap++) {
        
        filteredVector.push_back(iteratorPlayersMap->first);
        
    }
    
    (*trainingToRegister)->setPlayers(filteredVector);
    (*trainingToRegister)->setRegistered();
    
    for (unsigned int i = 0; i < filteredVector.size(); i++) {
        
        this->mapInfoPlayers.at(filteredVector.at(i))->addTraining();
        this->parentClub->getAthletes().at(filteredVector.at(i))->getInfo()->addTraining();
        
    }
    
    for (unsigned int i = 0; i < missingPlayers.size(); i++) {
        
        this->mapInfoPlayers.at(missingPlayers.at(i))->addTraining(Fraction(0,1));
        this->parentClub->getAthletes().at(missingPlayers.at(i))->getInfo()->addTraining(Fraction(0,1));
    }
    
    
    
}


void Level::registerTraining(Date trainingDate, vector<unsigned int> missingPlayers) {
    
    vector<unsigned int> players;
    Training* trainingToAdd = new Training(trainingDate, players);
    
    vector<unsigned int> filteredVector;
    map<unsigned int, Info*> mapLevelPLayers = this->getMapInfoPlayers();
    
    for (vector<unsigned int>::const_iterator missingPlayersIterator = missingPlayers.begin(); missingPlayersIterator != missingPlayers.end(); missingPlayersIterator++) {
        
        if (mapLevelPLayers.find(*missingPlayersIterator) != mapLevelPLayers.end()) {
            
            mapLevelPLayers.erase(mapLevelPLayers.find(*missingPlayersIterator));
            missingPlayersIterator--;
            
        }
    }
    
    for (map<unsigned int, Info*>::const_iterator iteratorPlayersMap = mapLevelPLayers.begin(); iteratorPlayersMap != mapLevelPLayers.end(); iteratorPlayersMap++) {
        
        filteredVector.push_back(iteratorPlayersMap->first);
        
    }
    
    trainingToAdd->setPlayers(filteredVector);
    trainingToAdd->setRegistered();
    this->addTrainingToLevel(trainingToAdd);
    
    for (unsigned int i = 0; i < filteredVector.size(); i++) {
        
        this->mapInfoPlayers.at(filteredVector.at(i))->addTraining();
        this->parentClub->getAthletes().at(filteredVector.at(i))->getInfo()->addTraining();
        
    }
    
    for (unsigned int i = 0; i < missingPlayers.size(); i++) {
        
        this->mapInfoPlayers.at(missingPlayers.at(i))->addTraining(Fraction(0,1));
        this->parentClub->getAthletes().at(missingPlayers.at(i))->getInfo()->addTraining(Fraction(0,1));
    }
    
    
}

vector<vector<string>> Level::getTrainingsList(SortCriteria criteria, SortOrder order, char listType) const {
    
    vector<vector<string>> result;
    
    vector<Training*> allTrainings;
    
    switch (listType) {
        case 'a':
            allTrainings = this->levelTrainings;
            sort(allTrainings.begin(), allTrainings.end(), SortTraining(criteria,order));
            for (size_t i = 0; i < allTrainings.size(); i++) {
                
                vector<string> eachTraining;
                eachTraining.push_back(to_string(allTrainings.at(i)->getId()));
                eachTraining.push_back(allTrainings.at(i)->getTrainingDate().str());
                string registed = allTrainings.at(i)->isRegistered() ? "Registed" : "Not Registed";
                eachTraining.push_back(registed);
                if (allTrainings.at(i)->isRegistered()) {
                    
                    string players = "";
                    for (size_t j = 0; j < allTrainings.at(i)->getPlayers().size(); j++) {
                        
                        players += to_string(allTrainings.at(i)->getPlayers().at(j)) + " " + positionsMapPosString.at((Position)this->parentClub->getAthletes().at(allTrainings.at(i)->getPlayers().at(j))->getPosition()) + " " + this->parentClub->getAthletes().at(allTrainings.at(i)->getPlayers().at(j))->getName();
                        
                        if (j != (allTrainings.at(i)->getPlayers().size() - 1)) {
                            players += ", ";
                        }
                        
                    }
                    eachTraining.push_back(players);
                    
                }
                
                result.push_back(eachTraining);
                
            }
            break;
        case 'p':
            for (size_t i = 0; i < this->levelTrainings.size(); i++) {
                
                if (!(Date() < this->levelTrainings.at(i)->getTrainingDate())) {
                    
                    allTrainings.push_back(this->levelTrainings.at(i));
                    
                }
                
            }
            sort(allTrainings.begin(), allTrainings.end(), SortTraining(criteria,order));
            for (size_t i = 0; i < allTrainings.size(); i++) {
                
                vector<string> eachTraining;
                eachTraining.push_back(to_string(allTrainings.at(i)->getId()));
                eachTraining.push_back(allTrainings.at(i)->getTrainingDate().str());
                string registed = allTrainings.at(i)->isRegistered() ? "Registed" : "Not Registed";
                eachTraining.push_back(registed);
                if (allTrainings.at(i)->isRegistered()) {
                    
                    string players = "";
                    for (size_t j = 0; j < allTrainings.at(i)->getPlayers().size(); j++) {
                        
                        players += to_string(allTrainings.at(i)->getPlayers().at(j)) + " " + positionsMapPosString.at((Position)this->parentClub->getAthletes().at(allTrainings.at(i)->getPlayers().at(j))->getPosition()) + " " + this->parentClub->getAthletes().at(allTrainings.at(i)->getPlayers().at(j))->getName();
                        
                        if (j != (allTrainings.at(i)->getPlayers().size() - 1)) {
                            players += ", ";
                        }
                        
                    }
                    eachTraining.push_back(players);
                    
                }
                result.push_back(eachTraining);
                
            }
            
            break;
        case 'r':
            for (size_t i = 0; i < this->levelTrainings.size(); i++) {
                
                if (!(Date() < this->levelTrainings.at(i)->getTrainingDate()) && this->levelTrainings.at(i)->isRegistered()) {
                    
                    allTrainings.push_back(this->levelTrainings.at(i));
                    
                }
                
            }
            sort(allTrainings.begin(), allTrainings.end(), SortTraining(criteria,order));
            for (size_t i = 0; i < allTrainings.size(); i++) {
                
                vector<string> eachTraining;
                eachTraining.push_back(to_string(allTrainings.at(i)->getId()));
                eachTraining.push_back(allTrainings.at(i)->getTrainingDate().str());
                string players = "";
                for (size_t j = 0; j < allTrainings.at(i)->getPlayers().size(); j++) {
                    
                    players += to_string(allTrainings.at(i)->getPlayers().at(j)) + " " + positionsMapPosString.at((Position)this->parentClub->getAthletes().at(allTrainings.at(i)->getPlayers().at(j))->getPosition()) + " " + this->parentClub->getAthletes().at(allTrainings.at(i)->getPlayers().at(j))->getName();
                    
                    if (j != (allTrainings.at(i)->getPlayers().size() - 1)) {
                        players += ", ";
                    }
                    
                }
                eachTraining.push_back(players);
                result.push_back(eachTraining);
            }
            break;
        case 'n':
            for (size_t i = 0; i < this->levelTrainings.size(); i++) {
                
                if (!(Date() < this->levelTrainings.at(i)->getTrainingDate()) && !this->levelTrainings.at(i)->isRegistered()) {
                    
                    allTrainings.push_back(this->levelTrainings.at(i));
                    
                }
                
            }
            sort(allTrainings.begin(), allTrainings.end(), SortTraining(criteria,order));
            for (size_t i = 0; i < allTrainings.size(); i++) {
                
                vector<string> eachTraining;
                eachTraining.push_back(to_string(allTrainings.at(i)->getId()));
                eachTraining.push_back(allTrainings.at(i)->getTrainingDate().str());
                result.push_back(eachTraining);
                
            }
            break;
        case 'f':
            for (size_t i = 0; i < this->levelTrainings.size(); i++) {
                
                if ((Date() < this->levelTrainings.at(i)->getTrainingDate())) {
                    
                    allTrainings.push_back(this->levelTrainings.at(i));
                    
                }
                
            }
            sort(allTrainings.begin(), allTrainings.end(), SortTraining(criteria,order));
            for (size_t i = 0; i < allTrainings.size(); i++) {
                
                vector<string> eachTraining;
                eachTraining.push_back(to_string(allTrainings.at(i)->getId()));
                eachTraining.push_back(allTrainings.at(i)->getTrainingDate().str());
                result.push_back(eachTraining);
                
            }
            break;
            
        default:
            break;
    }
    
    return result;
    
}

