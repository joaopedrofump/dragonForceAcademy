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
    this->pathToLevelTournamentsFolder = stringPath(this->pathToLevelFolder + "/Tournaments");
    this->pathToLevelTournamentsFile = stringPath(this->pathToLevelFolder + "/Tournaments.txt");
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
                
                levelMatches.at(i)->addInfoPlayer(make_pair(id, currentPlayerInfo));
                
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
    
    //TODO: read tournaments
    
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
		if (!onlyNotPlayed || !(*it)->getPlayed()) {
			result.push_back(*it);
		}
	}
    return result;
    
}

vector<Match*> Level::getMatchesReadyToPlay() const {

	vector<Match*> tmpVector = this->getAllLevelMatches(true);

	vector<Match*> result;
	for (vector<Match*>::const_iterator it = tmpVector.begin(); it != tmpVector.end(); it++) {
		if ((*it)->getMatchDay() < Date()) {
			result.push_back(*it);
		}
	}

	return result;
}

vector<Training*> Level::getTrainingsReadyToPlay() const {

	vector<Training*> tmpVector = this->getAllLevelTrainings(true);

	vector<Training*> result;
	for (vector<Training*>::const_iterator it = tmpVector.begin(); it != tmpVector.end(); it++) {
		if ((*it)->getTrainingDate() < Date()) {
			result.push_back(*it);
		}
	}

	return result;
}

vector<Training*> Level::getAllLevelTrainings(bool onlyNotPlayed) const {

	vector<Training*> result;
	for (vector<Training*>::const_iterator it = this->levelTrainings.begin(); it != levelTrainings.end(); it++) {
		if (!onlyNotPlayed || !(*it)->isRegistered()) {
			result.push_back(*it);
		}
	}
	return result;
}

Level* Level::addMatchToLevel(Match* newMatch) {
    this->levelMatches.push_back(newMatch);
	sort(levelMatches.begin(), levelMatches.end(), [](Match* a, Match* b) { return *b < *a; });
    return this;
}

Table Level::showAthletesOfLevel(bool onlyAvailable) const {
	Table athletesTable({ "ID", "Civil ID", "Name", "Birthdate" , "Age", "Height", "Position", "Level" ,"Status", "ECG" });
	map<unsigned int, Info*> athletes = this->getMapInfoPlayers();
	map<unsigned int, Info*>::iterator workersIterator;

	bool firstActive = false;
	for (workersIterator = athletes.begin(); workersIterator != athletes.end(); workersIterator++) {
		if (parentClub->getAthletes().at(workersIterator->first)->isActive() && !firstActive) {
			bool result = parentClub->getAthletes().at(workersIterator->first)->getECG()->getResultado();
			Date expiration = parentClub->getAthletes().at(workersIterator->first)->getECG()->getExpirationDate();
			if (!onlyAvailable || (result &&  expiration >= Date())) {
				
				athletesTable.addNewLine(parentClub->getAthletes().at(workersIterator->first)->showInScreen());
				firstActive = true;
				continue;
			}
			
			
		}

		if (parentClub->getAthletes().at(workersIterator->first)->isActive() && firstActive && parentClub->getAthletes().at(workersIterator->first)->isAthlete()) {
			
			if (!onlyAvailable || (parentClub->getAthletes().at(workersIterator->first)->getECG()->getResultado()
				&& parentClub->getAthletes().at(workersIterator->first)->getECG()->getExpirationDate() >= Date())) {

				athletesTable.addDataInSameLine(parentClub->getAthletes().at(workersIterator->first)->showInScreen()); //addDataInSameLine
			}
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
		if(it == matches.begin())
			matchesTable.addNewLine((*it)->showInScreen(++tmpID));
		else 
			matchesTable.addDataInSameLine((*it)->showInScreen(++tmpID));
	
		if(it != matches.end()-1)
			matchesTable.addDataInSameLine({});
	}

	cout << matchesTable;
}

void Level::showTrainings(vector<Training*> trainings) {

	unsigned int tmpID = 0;
	Table trainingsTable({ "ID", "Date", "Players who attended" });


	for (vector<Training*>::iterator it = trainings.begin(); it != trainings.end(); it++) {
		
		trainingsTable.addNewLine((*it)->showInScreen(this->parentClub).at(0));
		for (size_t i = 0; (*it)->showInScreen(this->parentClub).size(); i++) {
			trainingsTable.addDataInSameLine((*it)->showInScreen(this->parentClub).at(i));
		}

		if (it != trainings.end() - 1)
			trainingsTable.addDataInSameLine({});
	}

	cout << trainingsTable;
}

void Level::showMatch(Match* matchToShow) {

	showMainMenu(0, Date().str());

	Match* tmpMatch = matchToShow;
	//Show match
	Table showInformation({ "Information", "Data"});

	if (tmpMatch->getPlayed()) {
		showInformation.addNewLine({ "Match: " , tmpMatch->getHomeTeam() == this->parentClub ?
			(this->parentClub->getName() + " " + to_string(tmpMatch->getScore().first) + " - " + to_string(tmpMatch->getScore().second) + " " + tmpMatch->getAwayTeam()->getName())
			: (tmpMatch->getHomeTeam()->getName() + " " + to_string(tmpMatch->getScore().first) + " - " + to_string(tmpMatch->getScore().second) + " " + this->parentClub->getName()) });
	}
	else {
		showInformation.addNewLine({ "Match: " , tmpMatch->getHomeTeam() == this->parentClub ?
			(this->parentClub->getName() + " vs " + tmpMatch->getAwayTeam()->getName())
			: (tmpMatch->getHomeTeam()->getName() + " vs " + this->parentClub->getName()) });
	}
	
	showInformation.addNewLine({ "Date: " , tmpMatch->getMatchDay().str() });


	cout << showInformation;


	Table athletes({ "ID", "Athletes called-up" , "Position"});

	if (tmpMatch->getPlayers().size()) {

		for (size_t i = 0; i < tmpMatch->getPlayers().size(); i++) {

			if (!i) {
				switch (tmpMatch->getPlayers().at(i)->getPosition()) {

				case 1:
					athletes.addNewLine({ to_string(tmpMatch->getPlayers().at(i)->getID()), tmpMatch->getPlayers().at(i)->getName(), "Goalkeeper" });
					break;
				case 2:
					athletes.addNewLine({ to_string(tmpMatch->getPlayers().at(i)->getID()), tmpMatch->getPlayers().at(i)->getName(), "Defender" });
					break;
				case 3:
					athletes.addNewLine({ to_string(tmpMatch->getPlayers().at(i)->getID()), tmpMatch->getPlayers().at(i)->getName(), "Midfielder" });
					break;
				case 4:
					athletes.addNewLine({ to_string(tmpMatch->getPlayers().at(i)->getID()), tmpMatch->getPlayers().at(i)->getName(), "Forward" });
					break;
				}
			}

			else {
				switch (tmpMatch->getPlayers().at(i)->getPosition()) {
				case 1:
					athletes.addDataInSameLine({ to_string(tmpMatch->getPlayers().at(i)->getID()), tmpMatch->getPlayers().at(i)->getName(), "Goalkeeper" });
					break;
				case 2:
					athletes.addDataInSameLine({ to_string(tmpMatch->getPlayers().at(i)->getID()), tmpMatch->getPlayers().at(i)->getName(), "Defender" });
					break;
				case 3:
					athletes.addDataInSameLine({ to_string(tmpMatch->getPlayers().at(i)->getID()), tmpMatch->getPlayers().at(i)->getName(), "Midfielder" });
					break;
				case 4:
					athletes.addDataInSameLine({ to_string(tmpMatch->getPlayers().at(i)->getID()), tmpMatch->getPlayers().at(i)->getName(), "Forward" });
					break;
				}
			}
		}

		cout << athletes;

	}
	else {

		cout << Table({ "There are not called-up players." });
	}
	

	ignoreLine(false);
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

    map<unsigned int, Info*> mapLevelAllPLayers = this->getMapInfoPlayers();
	map<unsigned int, Info*> mapLevelPLayers;

	for (map<unsigned int, Info*>::iterator i = mapLevelAllPLayers.begin(); i != mapLevelAllPLayers.end(); i++) {

		if (this->parentClub->getAthletes().at(i->first)->getECG()->getResultado())
			mapLevelPLayers.insert(*i);
	}
    
    for (vector<unsigned int>::const_iterator missingPlayersIterator = missingPlayers.begin(); missingPlayersIterator != missingPlayers.end(); missingPlayersIterator++) {
        
        if (mapLevelPLayers.find(*missingPlayersIterator) != mapLevelPLayers.end()) {
            
            mapLevelPLayers.erase(mapLevelPLayers.find(*missingPlayersIterator));
            
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
    map<unsigned int, Info*> mapLevelAllPLayers = this->getMapInfoPlayers();
	map<unsigned int, Info*> mapLevelPLayers;

	for (map<unsigned int, Info*>::iterator i = mapLevelAllPLayers.begin(); i != mapLevelAllPLayers.end(); i++) {

		if (this->parentClub->getAthletes().at(i->first)->getECG()->getResultado())
			mapLevelPLayers.insert(*i);
	}
    
    for (vector<unsigned int>::const_iterator missingPlayersIterator = missingPlayers.begin(); missingPlayersIterator != missingPlayers.end(); missingPlayersIterator++) {
        
        if (mapLevelPLayers.find(*missingPlayersIterator) != mapLevelPLayers.end()) {
            
            mapLevelPLayers.erase(mapLevelPLayers.find(*missingPlayersIterator));
            
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

Table Level::getTrainingsList(SortCriteria criteria, SortOrder order, char listType) const {
    
	Table result( {"ID", "Date", "Status", "Athletes"} );
    
    vector<Training*> allTrainings;
    
    switch (listType) {
        case 'a':
		{
			allTrainings = this->levelTrainings;

			sort(allTrainings.begin(), allTrainings.end(), SortTraining(criteria, order));

			for (size_t i = 0; i < allTrainings.size(); i++) {

				vector<vector<string>> tmpMatrix = allTrainings.at(i)->showInScreen(parentClub);

				result.addNewLine(tmpMatrix.at(0));
				for (size_t j = 1; j < tmpMatrix.size(); j++) {
					if(tmpMatrix.at(j).at(0) != "")
						result.addNewLine(tmpMatrix.at(j));
					else
						result.addDataInSameLine(tmpMatrix.at(j));

				}

			}
			break;
		}
        case 'p':
            for (size_t i = 0; i < this->levelTrainings.size(); i++) {
                
                if (!(Date() < this->levelTrainings.at(i)->getTrainingDate())) {
                    
                    allTrainings.push_back(this->levelTrainings.at(i));
                    
                }
                
            }
            sort(allTrainings.begin(), allTrainings.end(), SortTraining(criteria,order));
            for (size_t i = 0; i < allTrainings.size(); i++) {
                
				vector<vector<string>> tmpMatrix = allTrainings.at(i)->showInScreen(parentClub);

				result.addNewLine(tmpMatrix.at(0));
				for (size_t j = 1; j < tmpMatrix.size(); j++) {
					if (tmpMatrix.at(j).at(0) != "")
						result.addNewLine(tmpMatrix.at(j));
					else
						result.addDataInSameLine(tmpMatrix.at(j));

				}
            }
            
            break;
        case 'r':
            for (size_t i = 0; i < this->levelTrainings.size(); i++) {
                
                if (!(Date() < this->levelTrainings.at(i)->getTrainingDate()) && this->levelTrainings.at(i)->isRegistered()) {
                    
					vector<vector<string>> tmpMatrix = allTrainings.at(i)->showInScreen(parentClub);

					result.addNewLine(tmpMatrix.at(0));
					for (size_t j = 1; j < tmpMatrix.size(); j++) {
						if (tmpMatrix.at(j).at(0) != "")
							result.addNewLine(tmpMatrix.at(j));
						else
							result.addDataInSameLine(tmpMatrix.at(j));

					}
                }
                
            }
            sort(allTrainings.begin(), allTrainings.end(), SortTraining(criteria,order));
            for (size_t i = 0; i < allTrainings.size(); i++) {
                
				vector<vector<string>> tmpMatrix = allTrainings.at(i)->showInScreen(parentClub);

				result.addNewLine(tmpMatrix.at(0));
				for (size_t j = 1; j < tmpMatrix.size(); j++) {
					if (tmpMatrix.at(j).at(0) != "")
						result.addNewLine(tmpMatrix.at(j));
					else
						result.addDataInSameLine(tmpMatrix.at(j));

				}
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
                
				vector<vector<string>> tmpMatrix = allTrainings.at(i)->showInScreen(parentClub);

				result.addNewLine(tmpMatrix.at(0));
				for (size_t j = 1; j < tmpMatrix.size(); j++) {
					if (tmpMatrix.at(j).at(0) != "")
						result.addNewLine(tmpMatrix.at(j));
					else
						result.addDataInSameLine(tmpMatrix.at(j));

				}
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
                
				vector<vector<string>> tmpMatrix = allTrainings.at(i)->showInScreen(parentClub);

				result.addNewLine(tmpMatrix.at(0));
				for (size_t j = 1; j < tmpMatrix.size(); j++) {
					if (tmpMatrix.at(j).at(0) != "")
						result.addNewLine(tmpMatrix.at(j));
					else
						result.addDataInSameLine(tmpMatrix.at(j));

				}
            }
            break;
            
        default:
            break;
    }
    
    return result;
    
}

void Level::addTournament(Date initialDate, Date endDate, vector<string> tournamentClubs, string name) {
    
    Tournament* newTournament = new Tournament(initialDate, endDate, tournamentClubs, this->parentClub, name);
    this->tournaments.push_back(newTournament);
    
}

vector<vector<string>> Level::getTournamentMatches(unsigned int tournamentId) const {
    
    Tournament* tournamentToShow = NULL;
    for (unsigned int i = 0; i < this->tournaments.size(); i++) {
        
        if (this->tournaments.at(i)->getId() == tournamentId) {
            
            tournamentToShow = tournaments.at(i);
            
        }
        
    }
    
    if (!tournamentToShow) {
        throw string("This tournament does not exist.");
    }

    return tournamentToShow->getTournamentMatches();
    
}

vector<Tournament*> Level::getTournaments() const {
    
    return this->tournaments;
}

vector<unsigned int> Level::filterPlayers(vector<unsigned int> originalPlayerIdsVector) const {
    
    vector<unsigned int> resultFilteredVector;
    
    if (!originalPlayerIdsVector.size()) {
        
        
        for (map<unsigned int, Info*>::const_iterator levelPlayersIterator = this->mapInfoPlayers.begin(); levelPlayersIterator != this->mapInfoPlayers.end(); levelPlayersIterator++) {
            
            resultFilteredVector.push_back(levelPlayersIterator->first);
            
        }
        
    }
    
    else {
        
        for (size_t i = 0; i < originalPlayerIdsVector.size(); i++) {
            
            map<unsigned int, Info*>::const_iterator existsInLevel = this->mapInfoPlayers.find(originalPlayerIdsVector.at(i));
            
            if (existsInLevel != this->mapInfoPlayers.end()) {
                
                resultFilteredVector.push_back(originalPlayerIdsVector.at(i));
                
            }
            
        }
        
    }
    
    return resultFilteredVector;

    
}

void Level::saveLevelTournaments() const {
    
    ofstream tournamentsOfStream(this->pathToLevelTournamentsFile);
    
    for (size_t i = 0; i < this->tournaments.size(); i++) {
        
        tournamentsOfStream << *this->tournaments.at(i);
        ofstream tournamentTreeOstream(this->pathToLevelTournamentsFolder + "/" + this->tournaments.at(i)->getName() + ".txt");
        tournamentsOfStream < *this->tournaments.at(i);
        
    }
    
    
}

Club* Level::getParentClub() const {
    return this->parentClub;
}
