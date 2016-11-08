#include "Club.hpp"

#include "Season.hpp"
//#include "Level.h"

Club::Club(string clubName) {

    this->clubName = clubName;
	string pathtest = path();
    this->pathToClubFolder = stringPath((pathtest + clubName));
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

string Club::getName() const {
	return this->clubName;
}

map<unsigned int, Worker*> Club::getWorkers() const {
	return allWorkers;
}

vector<Season*> Club::getSeasons() const {
	return seasons;
}

map<unsigned int, Worker*> Club::getAthletes() const {

	map<unsigned int, Worker*> result;
    
    map<unsigned int, Worker*>::const_iterator workersIterator = this->allWorkers.begin();
    map<unsigned int, Worker*>::const_iterator workersEnd = this->allWorkers.end();
    
    while(workersIterator != workersEnd) {
        
        if(workersIterator->second->isAthlete()) {
            
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
		
	}
    
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
			currentFile << (i->second->getECG()->getResultado() ? "VALID" : "INVALID") << " ; ";
			currentFile << i->second->getECG()->getExpirationDate();

			if (i != allWorkers.end())
				currentFile << endl;
		}
	}

	currentFile << FILE_SEPARATOR << endl;

	// Save Inactive Players
	for (map<unsigned int, Worker*>::const_iterator i = allWorkers.begin(); i != allWorkers.end(); i++) {

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
        
        for(unsigned int iteLevels = 0; iteLevels < (*i)->getLevels().size(); iteLevels++) {
            
            athletesOStream.open((*i)->getLevels().at(iteLevels)->getPathToLevelAthletesFile());
            coachesOStream.open((*i)->getLevels().at(iteLevels)->getPathToLevelCoachesFile());
            
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
                
                if (iteratorCoaches != (*i)->getLevels().at(iteLevels)->getCoaches().end()) {
                    
                    coachesOStream << endl;
                    
                }
                
            }
            
            athletesOStream.close();
            coachesOStream.close();
            
        }
        
        
	}

}

void Club::showAthletes(bool onlyActives) const {
    
    Table athletesTable({ "ID", "Civil ID", "Name", "Birthdate" , "Age", "Height", "Position", "Level" ,"Status" });
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

