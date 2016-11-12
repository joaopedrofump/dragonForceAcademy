#include "Club.hpp"
#include "Season.hpp"
#include "Match.hpp"
#include "Level.h"

Club::Club(string clubName, bool empty) {
    
    this->clubName = clubName;
    this->programClub = !empty;
    if(!empty) {
        
        this->pathToClubFolder = stringPath((path() + clubName));
        this->pathToClubAthletesFile = stringPath(this->pathToClubFolder + "/athletes.txt");
        this->pathToClubCoachesFile = stringPath(this->pathToClubFolder+ "/coaches.txt");
        this->pathToClubInfoFile = stringPath(this->pathToClubFolder + "/club.txt");
        
        // =============================
        // ======  Read Coaches  ======
        // =============================
        
        ifstream inStreamCoaches;
        
        inStreamCoaches.open(this->pathToClubCoachesFile);
        
        while (!inStreamCoaches.eof()) {
            
            string tmpString;
            getline(inStreamCoaches, tmpString);
            
            // Empty file
            if(tmpString.length()==0) {
                continue;
            }
            
            // New Coach
            Worker* newCoach = new Coach(tmpString);
            
            this->allWorkers.insert(pair<unsigned int, Worker*>(newCoach->getID(), newCoach));
            
        }
        
        inStreamCoaches.close();
        
        // =============================
        // ======  Read Athletes  ======
        // =============================
        
        ifstream inStreamAthletes;
        
        inStreamAthletes.open(this->pathToClubAthletesFile);
        
        while (!inStreamAthletes.eof()) {
            
            string tmpString;
            getline(inStreamAthletes, tmpString);
            
            // Empty file/line
            if(tmpString.length()==0) {
                continue;
            }
            
            //Read the last line of file that contains inactive athletes
            if (tmpString == FILE_SEPARATOR) {
                //string tmpString;
                getline(inStreamAthletes, tmpString);
                
                unsigned int athleteId;
                
                stringstream inactiveClientsStream(tmpString);
                
                while (!inactiveClientsStream.eof()) {
                    
                    inactiveClientsStream >> athleteId;
                    
                    if (inactiveClientsStream.fail()) {
                        
                        break;
                    }
                    
                    this->allWorkers.at(athleteId)->setStatus(false);
                }
                break;
            }
            
            // Read athlete informations:
            
            //ID
            unsigned int newAthleteId = stoi(readAndCut(tmpString));
            
            //Civil ID
            unsigned int newAthleteCivilId = stoi(readAndCut(tmpString));
            
            //Position
            unsigned int newAthletePosition = stoi(readAndCut(tmpString));
            
            Worker* newAthlete = 0;
            
            if (newAthletePosition == GoalkeeperPos) {
                newAthlete = new Goalkeeper(tmpString);
            }
            else if (newAthletePosition == DefenderPos) {
                newAthlete = new Defender(tmpString);
            }
            else if (newAthletePosition == MidfielderPos) {
                newAthlete = new Midfielder(tmpString);
            }
            else if (newAthletePosition == ForwardPos) {
                newAthlete = new Forward(tmpString);
            }
            
            newAthlete->setId(newAthleteId);
            newAthlete->setCivilId(newAthleteCivilId);
            
            this->allWorkers.insert(pair<unsigned int, Worker*>(newAthlete->getID(), newAthlete));
            
        }
        
        inStreamAthletes.close();
        
        // ===========================================
        // ===== Read informations from fileClub  ====
        // ===========================================
        
        ifstream inStreamClub;
        
        inStreamClub.open(this->pathToClubInfoFile);
        
        // Read the Name of the Club
        
        if (!inStreamClub.eof()) {
            getline(inStreamClub, this->clubName);
        }
        
        while (!inStreamClub.eof()) {
            
            string seasonName;
            getline(inStreamClub, seasonName);
            
            if(seasonName.length() == 0) {
                continue;
            }
            
            Season* currentSeason = new Season(seasonName, this);
            
            this->seasons.push_back(currentSeason);
        }
        
        inStreamClub.close();
        
        this->numberOfSeasons = (int)seasons.size();
        
    }
    
}

string Club::getName() const {
	return this->clubName;
}

map<unsigned int, Worker*> Club::getWorkers() const {
	return allWorkers;
}

vector<Season*> Club::getSeasons() const {
	return seasons;
}

map<unsigned int, Worker*> Club::getAthletes(bool onlyActives) const {

	map<unsigned int, Worker*> result;
    
    map<unsigned int, Worker*>::const_iterator workersIterator = this->allWorkers.begin();
    map<unsigned int, Worker*>::const_iterator workersEnd = this->allWorkers.end();
    
    while(workersIterator != workersEnd) {
        
        if(workersIterator->second->isAthlete() && (onlyActives ? workersIterator->second->isActive() : true)) {
            
            result.insert(*workersIterator);
            
        }
        workersIterator++;
        
    }

	return result;
}

map<unsigned int, Worker*> Club::getInactives() const {

	map<unsigned int, Worker*> result;

	map<unsigned int, Worker*>::const_iterator workersIterator = this->allWorkers.begin();
	map<unsigned int, Worker*>::const_iterator workersEnd = this->allWorkers.end();

	while (workersIterator != workersEnd) {

		if (workersIterator->second->isAthlete() && !(workersIterator->second->isActive())) {

			result.insert(*workersIterator);

		}
		workersIterator++;

	}

	return result;
}

map<unsigned int, Worker*> Club::getCoaches() const {

    map<unsigned int, Worker*> result;
    
    map<unsigned int, Worker*>::const_iterator workersIterator = this->allWorkers.begin();
    map<unsigned int, Worker*>::const_iterator workersEnd = this->allWorkers.end();
    
    while(workersIterator != workersEnd) {
        
        if(!workersIterator->second->isAthlete()) {
            
            result.insert(*workersIterator);
            
        }
        workersIterator++;
        
    }
    
    return result;
}

string Club::getPathToClubFolder() const {
    return this->pathToClubFolder;
}
string Club::getPathToClubAthletesFile() const {
    return this->pathToClubAthletesFile;
}
string Club::getPathToClubCoachesFile() const {
    return this->pathToClubCoachesFile;
}
string Club::getPathToClubInfoFile() const {
    return this->pathToClubInfoFile;
}

void Club::addPlayer(Position pos, string name, Date birthdate, unsigned int civilID, unsigned char height) {
	
    
    if(this->findWorkerByCivilID(civilID) != -1) {
        throw string("This player is already registered");
    }
    
    Date currentDate;
    Season* currentSeason = 0;
    Athlete* athleteToAdd = 0;
    Info* infoAthleteToAdd = 0;

	try {
		if (pos == 1)
		{
			athleteToAdd = new Goalkeeper(name, birthdate, civilID, height);
            infoAthleteToAdd = new InfoGK();
			
		}
		else if (pos == 2)
		{
			athleteToAdd = new Defender(name, birthdate, civilID, height);
            infoAthleteToAdd = new InfoDF();
		
		}
		else if (pos == 3)
		{
			athleteToAdd = new Midfielder(name, birthdate, civilID, height);
            infoAthleteToAdd = new InfoMF();
		}
		else if (pos == 4)
		{
			athleteToAdd = new Forward(name, birthdate, civilID, height);
            infoAthleteToAdd = new InfoFW();
		}
		
		allWorkers.insert(pair<unsigned int, Worker*>(athleteToAdd->getID(), athleteToAdd));

		for (unsigned int i = 0; i < seasons.size(); i++)
		{
			if (currentDate.getYear() == seasons.at(i)->getYear())
			{
				currentSeason = seasons.at(i);
				break;
			}
		}
        
		for (unsigned int i = 0; i < currentSeason->getLevels().size(); i++) {

			if ((athleteToAdd->getIdade() > currentSeason->getLevels().at(i)->getMinAge()) && (athleteToAdd->getIdade() <= currentSeason->getLevels().at(i)->getMaxAge()))
			{
                currentSeason->getLevels().at(i)->addAthleteToLevel(make_pair(athleteToAdd->getID(), infoAthleteToAdd));
			}
		}
	
	}
	/*to be completed*/
    
	catch (...)	{
		cout << "Erro ao criar atleta";
	}
    
}

bool Club::removeAthlete(unsigned int athleteId) {

	//Verify if the athlete exists

	map<unsigned int, Worker*> tmpMap = this->getAthletes();
	map<unsigned int, Worker*>::const_iterator it = tmpMap.find(athleteId);

	if (it == tmpMap.end()) {

		throw InvalidInput("The Athlete was not found.");
		return false;

	}

	if (it->second->isActive()) {

		this->allWorkers.at(athleteId)->setStatus(false);

		cout << Table({ "The Athlete was correctly removed." }) << endl;
	}
	else {

		throw InvalidInput("The Athlete was already removed.");
	}
	return true;
}

bool Club::reativateAthlete(unsigned int athleteId) {

	//Verify if the athlete exists

	map<unsigned int, Worker*> tmpMap = this->getAthletes();
	map<unsigned int, Worker*>::const_iterator it = tmpMap.find(athleteId);

	if (it == tmpMap.end()) {

		throw InvalidInput("The Athlete was not found.");
		return false;

	}

	if (!it->second->isActive()) {

		this->allWorkers.at(athleteId)->setStatus(true);
	}
	else {

		throw InvalidInput( "The Athlete is already active." );
	}
	return true;
}

void Club::saveChanges() {

	// Save Athletes
	ofstream currentFile;
	currentFile.open(this->pathToClubAthletesFile);

	for (map<unsigned int, Worker*>::const_iterator i = allWorkers.begin(); i != allWorkers.end(); i++) {
		if (i->second->isAthlete()) {
			currentFile << i->second->getID() << " ; ";
			currentFile << i->second->getCivilID() << " ; ";
			currentFile << i->second->getPosition() << " ; ";
			currentFile << i->second->getName() << " ; ";
			currentFile << i->second->getBirthdate() << " ; ";
			currentFile << i->second->getHeight() << " ; ";

			if (i->second->getECG()) {
				currentFile << (i->second->getECG()->getResultado() ? "VALID" : "INVALID") << " ; ";
				currentFile << i->second->getECG()->getExpirationDate();
			}
			else {
				currentFile << "NONE";
			}

			if (i != allWorkers.end())
				currentFile << endl;
		}
	}

	currentFile << FILE_SEPARATOR << endl;

	// Save Inactive Players

	map<unsigned int, Worker*> tmpMap = getInactives();

	for (map<unsigned int, Worker*>::const_iterator i = tmpMap.begin(); i != tmpMap.end(); i++) {

		if (!(i->second->isActive())) {

			currentFile << i->second->getID();
			currentFile << " ";

		}

	}

	currentFile.close();
	// ================ // ====================

	// Save Coaches
	currentFile.open(stringPath(pathToClubCoachesFile));

	for (map<unsigned int, Worker*>::const_iterator i = allWorkers.begin(); i != allWorkers.end(); i++) {
		if (!i->second->isAthlete()) {
            currentFile << i->second->getID() << " ; ";
            currentFile << i->second->getCivilID() << " ; ";
			currentFile << i->second->getName() << " ; ";
			currentFile << i->second->getBirthdate() << " ; ";
			currentFile << i->second->getPosition();

			if (i != allWorkers.end())
				currentFile << endl;
		}
	}

	currentFile.close();
	// ================ // ====================

	// Save club.txt

	currentFile.open(this->pathToClubInfoFile);

	currentFile << this->clubName << endl;

	for (vector<Season*>::iterator i = seasons.begin(); i != seasons.end(); i++) {
		currentFile << (*i)->getYear();

		if (i != seasons.end())
			currentFile << endl;
	}
	currentFile.close();
	// ================ // ====================

	// Save Seasons

	for(vector<Season*>::const_iterator i = this->seasons.begin(); i != this->seasons.end(); i++) {
        
        ofstream athletesOStream;
        ofstream coachesOStream;
        ofstream matchesOStream;
        
        for(unsigned int iteLevels = 0; iteLevels < (*i)->getLevels().size(); iteLevels++) {
            
            athletesOStream.open((*i)->getLevels().at(iteLevels)->getPathToLevelAthletesFile());
            coachesOStream.open((*i)->getLevels().at(iteLevels)->getPathToLevelCoachesFile());
            matchesOStream.open((*i)->getLevels().at(iteLevels)->getPathToLevelMatchesFile());
            
            map<unsigned int, Info*> tempPlayersMap = (*i)->getLevels().at(iteLevels)->getMapInfoPlayers();
            
            map<unsigned int, Info*>::const_iterator playersIterator = tempPlayersMap.begin();
            
            while(playersIterator != tempPlayersMap.end()) {
                
                athletesOStream << playersIterator->first << " ; ";
                athletesOStream << this->allWorkers.at(playersIterator->first)->getPosition() << " ; ";
                athletesOStream << *(playersIterator->second);
                
                if (playersIterator != tempPlayersMap.end()) {
                    athletesOStream << endl;
                }
                
                playersIterator++;
                
            }
        
            coachesOStream << (*i)->getLevels().at(iteLevels)->getMainCoachId() << endl;

			vector<unsigned int> tmpVectorCoaches = (*i)->getLevels().at(iteLevels)->getCoaches();

			for(vector<unsigned int>::iterator iteratorCoaches = tmpVectorCoaches.begin(); iteratorCoaches != tmpVectorCoaches.end(); iteratorCoaches++) {
                
                coachesOStream << *iteratorCoaches;
                
                if (iteratorCoaches != tmpVectorCoaches.end()) {
                    
                    coachesOStream << endl;
                    
                }
                
            }
            
            matchesOStream << (*i)->getLevels().at(iteLevels)->getLastMatchId() << endl;
            
            vector<Match*> tmpVectorMatches = (*i)->getLevels().at(iteLevels)->getAllLevelMatches();
            
            for(vector<Match*>::const_iterator iteratorMatches = tmpVectorMatches.begin(); iteratorMatches != tmpVectorMatches.end(); iteratorMatches++) {
                
                if((*iteratorMatches)->getHomeTeam() == this) {
                    
                    matchesOStream << home << " ; ";
                    
                }
                else {
                    
                    matchesOStream << away << " ; ";
                }
                        
                matchesOStream << **iteratorMatches;
                
                if (iteratorMatches != tmpVectorMatches.end()) {
                    
                    matchesOStream << endl;
                    
                }
                
            }
            
            vector<Match*> levelMatches = (*i)->getLevels().at(iteLevels)->getAllLevelMatches();
            string pathToCurrentLevelFolder = (*i)->getLevels().at(iteLevels)->getPathToLevelFolder();
            
            for (size_t i = 0; i < levelMatches.size(); i++) {
                
                
                
            }
            
            
            
            athletesOStream.close();
            coachesOStream.close();
            matchesOStream.close();
            
        }
        
        
	}

}

void Club::showAthletes(bool onlyActives) const {
    
    Table athletesTable({ "ID", "Civil ID", "Name", "Birthdate" , "Age", "Height", "Position", "Level" ,"Status", "ECG" });
    map<unsigned int, Worker*>::const_iterator workersIterator;
    
    if(onlyActives) {
        
        bool firstActive = false;
        for (workersIterator = this->allWorkers.begin(); workersIterator != this->allWorkers.end(); workersIterator++) {
            if (workersIterator->second->isActive() && !firstActive && workersIterator->second->isAthlete()) {
                
                athletesTable.addNewLine(workersIterator->second->showInScreen());
                firstActive = true;
                continue;
            }
            
            if (workersIterator->second->isActive() && firstActive && workersIterator->second->isAthlete()) {
                
                athletesTable.addDataInSameLine(workersIterator->second->showInScreen()); //addDataInSameLine
            }
        }
        
    }
    
    else {
        
        for (workersIterator = this->allWorkers.begin(); workersIterator != this->allWorkers.end(); workersIterator++) {
            
            if (workersIterator == this->allWorkers.begin()) {
                
                athletesTable.addNewLine(workersIterator->second->showInScreen());
            }
            else {
                
                athletesTable.addDataInSameLine(workersIterator->second->showInScreen()); //addDataInSameLine
            }
        }
        
    }
    
    cout << athletesTable << endl;
    
}

void Club::showAthletesInactives() const {
	Table athletesTable({ "ID", "Civil ID", "Name", "Birthdate" , "Age", "Height", "Position", "Level" ,"Status", "ECG" });
	map<unsigned int, Worker*>::const_iterator workersIterator;

	bool firstInactive = false;
		for (workersIterator = this->allWorkers.begin(); workersIterator != this->allWorkers.end(); workersIterator++) {
			if (!workersIterator->second->isActive() && !firstInactive && workersIterator->second->isAthlete()) {

				athletesTable.addNewLine(workersIterator->second->showInScreen());
				firstInactive = true;
				continue;
			}

			if (!workersIterator->second->isActive() && firstInactive && workersIterator->second->isAthlete()) {

				athletesTable.addDataInSameLine(workersIterator->second->showInScreen()); //addDataInSameLine
			}
		}

	cout << athletesTable << endl;
}

bool Club::showAthlete(unsigned int id) const {

	if (allWorkers.find(id) == allWorkers.end()) {
		throw InvalidInput("This ID is not atributted.");
	}
	else {
		map<unsigned int, Worker*> athletes = getAthletes();
		if (athletes.find(id) == athletes.end()) {
			throw InvalidInput("This ID is does not belong to an Athlete.");
		}
	}

	Worker* currentAthlete = this->allWorkers.at(id);

	//Mostrar resumo da operacao
	Table showInformation({ "Information" , "Data" });

	showInformation.addNewLine({ "ID: " , to_string(currentAthlete->getID()) });

	showInformation.addNewLine({ "Civil ID: " , to_string(currentAthlete->getCivilID()) });

	showInformation.addNewLine({ "Name: " , currentAthlete->getName() });

	showInformation.addNewLine({ "Birth Date: " , currentAthlete->getBirthdate().str() });

	showInformation.addNewLine({ "Level: " , getLevelFromAge(currentAthlete->getBirthdate()) });

	cout << showInformation;

	return true;
}

int Club::findWorkerByCivilID(unsigned int civilID) {
    
    map<unsigned int, Worker*>::const_iterator clientsIterator = this->allWorkers.begin();
    while (clientsIterator != this->allWorkers.end()) {
        
        if ((clientsIterator->second)->getCivilID() == civilID) {
            
            return clientsIterator->first;
            
        }
        clientsIterator++;
        
    }
    return -1;
    
}

void Club::updateECG(unsigned int athleteID, bool result) {
    
    if(this->allWorkers.find(athleteID) == allWorkers.end()) {
        
        throw string("Athlete not found");
        
    }
    
    allWorkers.find(athleteID)->second->updateECG(result);
    
}
bool Club::isProgramClub() const {
    return this->programClub;
}

void Club::scheduleMatch(string opponentClub, Date matchDate, Level* level, MatchType type) {
    
    Club* opponent = new Club(opponentClub, true);
    level->updateLastMatchId();
    Match* matchToAdd = (type == home) ? new Match(matchDate, this, opponent, level->getLevelName() + to_string(level->getLastMatchId())) : new Match(matchDate, opponent, this, level->getLevelName() + to_string(level->getLastMatchId()));
    level->addMatchToLevel(matchToAdd);
    
}

void Club::registerMatch(string matchId, Level* level, unsigned int homeTeamScore, unsigned int awayTeamScore, map<unsigned int, Info*> matchPlayers) {
    
    vector<Match*> listOfLevelMatches = level->getAllLevelMatches();
    vector<Match*>::const_iterator matchToRegister = listOfLevelMatches.begin();
    while (matchToRegister != listOfLevelMatches.end()) {
        
        if ((*matchToRegister)->getId() == matchId) {
            
            break;
            
        }
        matchToRegister++;
        
    }
    
    
    if(matchToRegister == listOfLevelMatches.end()) {
        
        throw string("jogo não agendado");
        
    }
    
    (*matchToRegister)->registerMatch(homeTeamScore, awayTeamScore, matchPlayers);
    
    for (map<unsigned int, Info*>::iterator iteratorInfoPlayer = matchPlayers.begin(); iteratorInfoPlayer != matchPlayers.end(); iteratorInfoPlayer++) {
        
        *(level->getMapInfoPlayers().at(iteratorInfoPlayer->first)) += iteratorInfoPlayer->second;
        this->allWorkers.at(iteratorInfoPlayer->first)->addInfo(iteratorInfoPlayer->second);
    }
    
}

void Club::registerMatch(string opponentClub, Date matchDate, Level* level, MatchType type, unsigned int homeTeamScore, unsigned int awayTeamScore, map<unsigned int, Info*> matchPlayers) {
    
    Club* opponent = new Club(opponentClub, true);
    level->updateLastMatchId();
    Match* matchToAdd = (type == home) ? new Match(matchDate, this, opponent, level->getLevelName() + to_string(level->getLastMatchId())) : new Match(matchDate, opponent, this, level->getLevelName() + to_string(level->getLastMatchId()));
    
    matchToAdd->registerMatch(homeTeamScore, awayTeamScore, matchPlayers);
    level->addMatchToLevel(matchToAdd);
    
    for (map<unsigned int, Info*>::iterator iteratorInfoPlayer = matchPlayers.begin(); iteratorInfoPlayer != matchPlayers.end(); iteratorInfoPlayer++) {
        
        *(level->getMapInfoPlayers().at(iteratorInfoPlayer->first)) += iteratorInfoPlayer->second;
        this->allWorkers.at(iteratorInfoPlayer->first)->addInfo(iteratorInfoPlayer->second);
    }
    
}

void Club::registerMatch(string matchId, Level* level, unsigned int homeTeamScore, unsigned int awayTeamScore, vector<unsigned int> matchPlayers) {
    
    vector<Match*> listOfLevelMatches = level->getAllLevelMatches();
    vector<Match*>::const_iterator matchToRegister = listOfLevelMatches.begin();
    while (matchToRegister != listOfLevelMatches.end()) {
        
        if ((*matchToRegister)->getId() == matchId) {
            
            break;
            
        }
        matchToRegister++;
        
    }
    
    
    if(matchToRegister == listOfLevelMatches.end()) {
        
        throw string("jogo não agendado");
        
    }
    
    vector<unsigned int> filteredVector;
    map<unsigned int, Info*> levelPlayers = level->getMapInfoPlayers();
    
    if (matchPlayers.size() == 0) {
        
        
        for (map<unsigned int, Info*>::const_iterator levelPlayersIterator = levelPlayers.begin(); levelPlayersIterator != levelPlayers.end(); levelPlayersIterator++) {
            
            filteredVector.push_back(levelPlayersIterator->first);
            
        }
        
    }
    
    else {
        
        for (size_t i = 0; i < matchPlayers.size(); i++) {
            
            map<unsigned int, Info*>::const_iterator existsInLevel = levelPlayers.find(matchPlayers.at(i));
            
            if (existsInLevel != levelPlayers.end()) {
                
                filteredVector.push_back(matchPlayers.at(i));
                
            }
            
        }
        
    }
    
    (*matchToRegister)->setPlayers(filteredVector);
    map<unsigned int, Info *> infoPlayersEmpty;
    (*matchToRegister)->registerMatch(homeTeamScore, awayTeamScore, infoPlayersEmpty);
    
}

void Club::registerMatch(string opponentClub, Date matchDate, Level* level, MatchType type, unsigned int homeTeamScore, unsigned int awayTeamScore, vector<unsigned int> matchPlayers) {
    
    
    Club* opponent = new Club(opponentClub, true);
    level->updateLastMatchId();
    Match* matchToAdd = (type == home) ? new Match(matchDate, this, opponent, level->getLevelName() + to_string(level->getLastMatchId())) : new Match(matchDate, opponent, this, level->getLevelName() + to_string(level->getLastMatchId()));
    
    vector<unsigned int> filteredVector;
    map<unsigned int, Info*> levelPlayers = level->getMapInfoPlayers();
    
    if (matchPlayers.size() == 0) {
        
        
        for (map<unsigned int, Info*>::const_iterator levelPlayersIterator = levelPlayers.begin(); levelPlayersIterator != levelPlayers.end(); levelPlayersIterator++) {
            
            filteredVector.push_back(levelPlayersIterator->first);
            
        }
        
    }
    
    else {
        
        for (size_t i = 0; i < matchPlayers.size(); i++) {
            
            map<unsigned int, Info*>::const_iterator existsInLevel = levelPlayers.find(matchPlayers.at(i));
            
            if (existsInLevel != levelPlayers.end()) {
                
                filteredVector.push_back(matchPlayers.at(i));
                
            }
            
        }
        
    }
    
    matchToAdd->setPlayers(filteredVector);
    map<unsigned int, Info *> infoPlayersEmpty;
    matchToAdd->registerMatch(homeTeamScore, awayTeamScore, infoPlayersEmpty);
    

    level->addMatchToLevel(matchToAdd);
     
}
