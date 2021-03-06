#include "Club.hpp"
#include "Season.hpp"
#include "Match.hpp"
#include "Level.h"


int workerHashTable::operator() (Worker* worker) const {
    return 3 * worker->getID() + 4;
}

bool workerHashTable::operator()(Worker* worker1, Worker* worker2) const {
        return worker1->getID() == worker2->getID();
    }


struct AthletePtr_BST {
    Worker* athletePtr;
    double athletePerformance;
    Fraction athleteTrainingAttendance;
    
    AthletePtr_BST(Worker* athletePtr);
    bool operator<(const AthletePtr_BST &at2) const;
    bool operator==(const AthletePtr_BST &at2) const;
	double generalPerformance() const;
};

double AthletePtr_BST::generalPerformance() const {
	return athleteTrainingAttendance.fracValue() * (athletePerformance + 1.0); 
}

AthletePtr_BST::AthletePtr_BST(Worker* athletePtr) {
    
    this->athletePtr = athletePtr;
    
    if (athletePtr) {
        
		this->athleteTrainingAttendance = athletePtr->getInfo()->getTrainingFreq();
        this->athletePerformance = getAthletePerformance(athletePtr->getInfo()->getWinningFreq(),
														 athletePtr->getInfo()->getDrawFreq(),
														 athletePtr->getInfo()->getLosingFreq());
    }
    else {
        this->athleteTrainingAttendance = Fraction(0,0);
        this->athletePerformance = 0;
    }
    


}

bool AthletePtr_BST::operator<(const AthletePtr_BST &at2) const {
    
	if (this->generalPerformance() != at2.generalPerformance()) {
		return this->generalPerformance() > at2.generalPerformance();
	}
	else
	{
		if (!(this->athleteTrainingAttendance == at2.athleteTrainingAttendance)
			&& this->athleteTrainingAttendance.fracValue() == at2.athleteTrainingAttendance.fracValue())
			return this->athleteTrainingAttendance.numerator > at2.athleteTrainingAttendance.numerator;

		return this->athletePtr->getName() < at2.athletePtr->getName();
	}
}

bool AthletePtr_BST::operator==(const AthletePtr_BST &at2) const {
    return this->athletePtr->getID() == at2.athletePtr->getID();
}


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

			//Read the last line of file that contains inactive coaches
			if (tmpString == FILE_SEPARATOR) {

				getline(inStreamCoaches, tmpString);

				unsigned int coachId;

				stringstream inactiveCoachesStream(tmpString);

				while (!inactiveCoachesStream.eof()) {

					inactiveCoachesStream >> coachId;

					if (inactiveCoachesStream.fail()) {

						break;
					}

					this->allWorkers.at(coachId)->setStatus(false);
				}
				break;
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

                getline(inStreamAthletes, tmpString);
                
                unsigned int athleteId;
                
                stringstream inactiveAthletesStream(tmpString);
                
                while (!inactiveAthletesStream.eof()) {
                    
					inactiveAthletesStream >> athleteId;
                    
                    if (inactiveAthletesStream.fail()) {
                        
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
            
            Athlete* newAthlete = 0;

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

        for (map<unsigned int, Worker*>::const_iterator workerIterator = this->allWorkers.begin(); workerIterator != this->allWorkers.end(); workerIterator++) {
            
            if (!workerIterator->second->isActive()) {
                
                this->formerPlayers.insert(workerIterator->second);
                
            }
            
        }
        
    }
}

//====================================
//===========  GETTERS  ==============
//====================================

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

map<unsigned int, Worker*> Club::getInactives(unsigned char workersType) const {

	map<unsigned int, Worker*> result;

	map<unsigned int, Worker*>::const_iterator workersIterator = this->allWorkers.begin();
	map<unsigned int, Worker*>::const_iterator workersEnd = this->allWorkers.end();

	while (workersIterator != workersEnd) {

		switch (workersType) {
		case 0:
			if (!(workersIterator->second->isActive())) {

				result.insert(*workersIterator);

			}
			workersIterator++;
			break;
		case 1:
			if (!(workersIterator->second->isActive()) && workersIterator->second->isAthlete()) {

				result.insert(*workersIterator);

			}
			workersIterator++;
			break;
		case 2:
			if (!(workersIterator->second->isActive()) && !workersIterator->second->isAthlete()) {

				result.insert(*workersIterator);

			}
			workersIterator++;
			break;
		}
		

	}

	return result;
}

map<unsigned int, Worker*> Club::getCoaches(bool onlyActives) const {

    map<unsigned int, Worker*> result;
    
    map<unsigned int, Worker*>::const_iterator workersIterator = this->allWorkers.begin();
    map<unsigned int, Worker*>::const_iterator workersEnd = this->allWorkers.end();
    
    while(workersIterator != workersEnd) {
        
        if(!workersIterator->second->isAthlete() && (onlyActives ? workersIterator->second->isActive() : true)) {
            
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


//=====================================
//===========  ATHLETES  ==============
//=====================================

void Club::addPlayer(Position pos, string name, Date birthdate, unsigned int civilID, unsigned char height) {
	
    
    if(this->findWorkerByCivilID(civilID) != -1) {
        throw string("This id is already registered");
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
			if ((seasons.at(i)->getInitialDate() <= currentDate) && (currentDate <= seasons.at(i)->getEndDate()))
			{
				currentSeason = seasons.at(i);
				break;
			}
		}
        
		for (unsigned int i = 0; i < currentSeason->getLevels().size(); i++) {

			if ((athleteToAdd->getAge() > currentSeason->getLevels().at(i)->getMinAge()) && (athleteToAdd->getAge() <= currentSeason->getLevels().at(i)->getMaxAge()))
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
		// Show operation summary
		Table showInformation({ "Information" , "Data" });

		showInformation.addNewLine({ "ID: " , to_string(this->getAthletes().at(athleteId)->getID()) });  // Show id

		showInformation.addNewLine({ "Civil ID: " , to_string(this->getAthletes().at(athleteId)->getCivilID()) }); // Show Civil Id

		showInformation.addNewLine({ "Name: " , this->getAthletes().at(athleteId)->getName() }); // Show Name

		showInformation.addNewLine({ "Birth Date: " , this->getAthletes().at(athleteId)->getBirthdate().str() }); // Show Birth Date

		showInformation.addNewLine({ "Level: " , getLevelStringFromAge(this->getAthletes().at(athleteId)->getBirthdate()) }); // Show Level

		showMainMenu(0, to_string(Date().getYear()));


		cout << showInformation;

		if (!confirm(Table({ "Are you sure you want to remove the athlete?" }))) {
			return false;
		}


		ignoreLine(false, "Athlete removed correctly");

		this->allWorkers.at(athleteId)->setStatus(false);
        this->formerPlayers.insert(this->allWorkers.at(athleteId));

	}
	else {

		throw InvalidInput("The Athlete was already removed.");
	}
	return true;
}

void Club::editPlayer(unsigned int athleteId, string newName, Date newBirthDate, unsigned int newHeight, unsigned int newCivilID) {

	map<unsigned int, Worker*> athletesMap = this->getAthletes();

	if (athletesMap.find(athleteId) != athletesMap.end()) {

		unsigned int newCivilIdParsed = !newCivilID ? athletesMap.at(athleteId)->getCivilID() : newCivilID;
		string newNameParsed = newName.length() == 0 ? athletesMap.at(athleteId)->getName() : newName;
		Date newBirthDateParsed = newBirthDate == Date() ? athletesMap.at(athleteId)->getBirthdate() : newBirthDate;
		unsigned int newHeightParsed = !newHeight ? athletesMap.at(athleteId)->getHeight() : newHeight;

		try {

			athletesMap.at(athleteId)->setName(newNameParsed);
			athletesMap.at(athleteId)->setBirthDate(newBirthDateParsed);
			athletesMap.at(athleteId)->setHeight(newHeightParsed);

			if (newCivilID && findWorkerByCivilID(newCivilID) != -1) {

				throw string("Civil ID already assigned to other player");

			}
			athletesMap.at(athleteId)->setCivilId(newCivilIdParsed);

		}

		catch (string s) {
			cout << s << endl;
		}

		catch (...) {
			cout << "something went wrong." << endl;
		}

	}
	throw string("Athlete does not exist");

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
        this->formerPlayers.erase(this->allWorkers.at(athleteId));
	}
	else {

		throw InvalidInput("The Athlete is already active.");
	}
	return true;
}

bool Club::updateECG(unsigned int athleteID, bool result) {

	if (this->allWorkers.find(athleteID) == allWorkers.end()) {

		throw string("Athlete not found");
		return false;
	}

	allWorkers.find(athleteID)->second->updateECG(result);

	ignoreLine(false, "ECG correctly updated!");
	return true;

}


void Club::showAthletes(SortCriteria criteria, SortOrder order, bool onlyAvailable) const {

	Table athletesTable({ "ID", "Civil ID", "Name", "Birthdate" , "Age", "Height", "Position", "Level" ,"Status", "ECG" });
	map<unsigned int, Worker*> athletes = this->getAthletes();
	map<unsigned int, Worker*>::iterator workersIterator;
	vector<Level*> levels = this->getSeasons().at(0)->getLevels();


	for (size_t i = 0; i < levels.size(); i++) {
		vector<vector<string>> athletesOfLevel = levels.at(i)->showAthletesOfLevel(criteria, order, onlyAvailable);

		if(athletesOfLevel.size()>1) athletesTable.addNewLine(athletesOfLevel.at(1));

		for (size_t i = 2; i < athletesOfLevel.size(); i++) {
			athletesTable.addDataInSameLine(athletesOfLevel.at(i));
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

	showInformation.addNewLine({ "Level: " , getLevelStringFromAge(currentAthlete->getBirthdate()) });

	cout << showInformation;

	return true;
}

void Club::updateQueue_ECGNotify() {

	//Update priority_queue to players who don't have a valid ECG

	priority_queue<AthletePtr_PQ> newPQ;

	for (map<unsigned int, Worker*>::iterator it = allWorkers.begin(); it != allWorkers.end(); it++) {

		if (it->second->isAthlete() && it->second->isActive() && it->second->isECGDelivered()) {

			AthletePtr_PQ notValidECG_player;
			notValidECG_player.athlete = (Athlete*)it->second;
			newPQ.push(notValidECG_player);
		}
	}

	ECG_queue = newPQ;
}

void Club::showNotificationList() {

	Table athletesTable({ "ID", "Name", "Birthdate" , "ECG", "Message" });
	
	priority_queue<AthletePtr_PQ> tmpHeap = this->ECG_queue;

	size_t size = tmpHeap.size();
	for (size_t i = 0; i < size; i++) {
		
		string message;
		switch (tmpHeap.top().athlete->isECGDelivered()) {
		case 1:
			message = "Unfortunately, you don't have a positive ECG so you are not able to participate in " + this->getName() + " matches.";
			break;
		case 2:
			message = "Your last ECG expired on " + tmpHeap.top().athlete->getECG()->getExpirationDate().str() + " then you need to take a new electrocardiogram.";
			break;
		case 3:
			message = "Your last ECG is almost out of date (" + tmpHeap.top().athlete->getECG()->getExpirationDate().str() + ") then you need to take a new electrocardiogram.";
			break;
		case 4:
			message = "You don't have a ECG exame and you need it to perform in " + this->getName() + " matches. Please consider take a new ECG.";
			break;
		default:
			message = "You already have a valid ECG. Keep going!";
			break;
		}
		if (i == 0) {
			athletesTable.addNewLine({ to_string(tmpHeap.top().athlete->getID()),
				tmpHeap.top().athlete->getName() ,
				tmpHeap.top().athlete->getBirthdate().str(),
				tmpHeap.top().athlete->getECG() ? tmpHeap.top().athlete->getECG()->showInScreen() : "NONE",
				message });
		}
		else {
			athletesTable.addDataInSameLine({ to_string(tmpHeap.top().athlete->getID()),
				tmpHeap.top().athlete->getName() ,
				tmpHeap.top().athlete->getBirthdate().str(),
				tmpHeap.top().athlete->getECG() ? tmpHeap.top().athlete->getECG()->showInScreen() : "NONE",
				message });
		}
		

		if (i != size - 1)
			athletesTable.addDataInSameLine({ "" });

		tmpHeap.pop();
	}

	cout << athletesTable << endl;
}

//====================================
//===========  COACHES  ==============
//====================================

void Club::addCoach(CoachType position, string name, Date birthdate, unsigned int civilID, ageLevel level, bool mainCoach){


	if (this->findWorkerByCivilID(civilID) != -1) {
		throw string("This coach is already registered");
	}

	Date currentDate;
	Season* currentSeason = 0;
	Coach* coachToAdd = 0;

	try {
		
		coachToAdd = new Coach(name, birthdate, civilID, position);

		allWorkers.insert(pair<unsigned int, Worker*>(coachToAdd->getID(), coachToAdd));

		// Find current season
		for (unsigned int i = 0; i < seasons.size(); i++)
		{
			if (seasons.at(i)->getInitialDate() <= currentDate && currentDate <= seasons.at(i)->getEndDate())
			{
				currentSeason = seasons.at(i);
				break;
			}
		}

		// Add coach to level
		for (unsigned int i = 0; i < currentSeason->getLevels().size(); i++) {

			if (ageLevelMap.at(currentSeason->getLevels().at(i)->getLevelName()) == level){

				currentSeason->getLevels().at(i)->addCoachToLevel(coachToAdd->getID(), mainCoach);
			}
		}

	}
	/*to be completed*/

	catch (string s) {
		cout << s;
		ignoreLine(false);
	}

}

void Club::editCoach(unsigned int coachId, string newName, Date newBirthDate, unsigned int newCivilID, unsigned int newCoachType) {
    
    map<unsigned int, Worker*> coachesMap = this->getCoaches();
    
    if (coachesMap.find(coachId) != coachesMap.end()) {
        
        unsigned int newCivilIdParsed = !newCivilID ? coachesMap.at(coachId)->getCivilID() : newCivilID;
        string newNameParsed = newName.length() == 0 ? coachesMap.at(coachId)->getName() : newName;
        Date newBirthDateParsed = newBirthDate == Date() ? coachesMap.at(coachId)->getBirthdate() : newBirthDate;
        
        try {
            
            coachesMap.at(coachId)->setName(newNameParsed);
            coachesMap.at(coachId)->setBirthDate(newBirthDateParsed);
            switch (newCoachType) {
                case 1:
                    coachesMap.at(coachId)->setCoachType(HeadCoach);
                    break;
                case 2:
                    coachesMap.at(coachId)->setCoachType(GoalkeeperCoach);
                    break;
                case 3:
                    coachesMap.at(coachId)->setCoachType(PhysicalTrainer);
                    break;
                    
                default:
                    break;
            }
            
            if (newCivilID && findWorkerByCivilID(newCivilID) != -1) {
                
                throw string("Civil ID already assigned to other worker");
                
            }
            coachesMap.at(coachId)->setCivilId(newCivilIdParsed);
            
        }
        
        catch(string s) {
            cout << s << endl;
        }
        
        catch(...) {
            cout << "something went wrong." << endl;
        }
        
    }
    throw string("Coach does not exist");
    
}

bool Club::removeCoach(unsigned int coachId) {
	//Verify if the athlete exists

	map<unsigned int, Worker*> tmpMap = this->getCoaches();
	map<unsigned int, Worker*>::const_iterator it = tmpMap.find(coachId);

	if (it == tmpMap.end()) {

		throw InvalidInput("The Coach was not found.");
		return false;

	}

	if (it->second->isActive()) {

		// Show operation summary

		Table showInformation({ "Information" , "Data" });

		showInformation.addNewLine({ "ID: " , to_string(this->getCoaches().at(coachId)->getID()) });  // Show id

		showInformation.addNewLine({ "Civil ID: " , to_string(this->getCoaches().at(coachId)->getCivilID()) }); // Show Civil Id

		showInformation.addNewLine({ "Name: " , this->getCoaches().at(coachId)->getName() }); // Show Name

		showInformation.addNewLine({ "Birth Date: " , this->getCoaches().at(coachId)->getBirthdate().str() }); // Show Birth Date

		showInformation.addNewLine({ "Age: " , to_string(this->getCoaches().at(coachId)->getAge()) }); // Show Age

		showMainMenu(0, to_string(Date().getYear()));


		cout << Table({ "Are you sure you want to remove the coach?" });

		if (!confirm(showInformation)) {
			return false;
		}


		ignoreLine(false, "Coach removed correctly");

		this->allWorkers.at(coachId)->setStatus(false);
        this->formerPlayers.insert(this->allWorkers.at(coachId));

	}
	else {

		throw InvalidInput("The Coach was already removed.");
	}

	return true;

}

bool Club::reativateCoach(unsigned int coachId) {

	//Verify if the coach exists

	map<unsigned int, Worker*> tmpMap = this->getCoaches();
	map<unsigned int, Worker*>::const_iterator it = tmpMap.find(coachId);

	if (it == tmpMap.end()) {

		throw InvalidInput("The Coach was not found.");
		return false;

	}

	if (!it->second->isActive()) {

		// Show operation summary
		Table showInformation({ "Information" , "Data" });

		showInformation.addNewLine({ "ID: " , to_string(this->getCoaches().at(coachId)->getID()) });  // Show id

		showInformation.addNewLine({ "Civil ID: " , to_string(this->getCoaches().at(coachId)->getCivilID()) }); // Show Civil Id

		showInformation.addNewLine({ "Name: " , this->getCoaches().at(coachId)->getName() }); // Show Name

		showInformation.addNewLine({ "Birth Date: " , this->getCoaches().at(coachId)->getBirthdate().str() }); // Show Birth Date

		showInformation.addNewLine({ "Level: " , getLevelStringFromAge(this->getCoaches().at(coachId)->getBirthdate()) }); // Show Level

		showMainMenu(0, to_string(Date().getYear()));


		cout << Table({ "Are you sure you want to reativate the coach?" });;

		if (!confirm(showInformation)) {
			return false;
		}


		ignoreLine(false, "Coach reativated correctly");

		this->allWorkers.at(coachId)->setStatus(true);
        this->formerPlayers.erase(this->allWorkers.at(coachId));
	}
	else {

		throw InvalidInput("The Coach is already active.");
	}
	return true;
}

void Club::showCoaches(SortCriteria criteria, SortOrder order, bool onlyActives) const {

	Table coachesTable({ "ID", "Civil ID", "Name", "Birthdate" , "Age", "Position", "Status", "Level","Responsible" });
	map<unsigned int, Worker*> coaches = this->getCoaches();
	map<unsigned int, Worker*>::iterator workersIterator;
    vector<Level*> levels = this->getSeasons().at(0)->getLevels();

    
    /*
	if (onlyActives) {

		bool firstActive = false;
		for (workersIterator = coaches.begin(); workersIterator != coaches.end(); workersIterator++) {
			if (workersIterator->second->isActive() && !firstActive) {

				coachesTable.addNewLine(workersIterator->second->showInScreen());
				firstActive = true;
				continue;
			}

			if (workersIterator->second->isActive() && firstActive && !workersIterator->second->isAthlete()) {

				coachesTable.addDataInSameLine(workersIterator->second->showInScreen()); //addDataInSameLine
			}
		}

	}

	else {

		for (workersIterator = coaches.begin(); workersIterator != coaches.end(); workersIterator++) {

			if (workersIterator == coaches.begin()) {

				coachesTable.addNewLine(workersIterator->second->showInScreen());
			}
			else {

				coachesTable.addDataInSameLine(workersIterator->second->showInScreen()); //addDataInSameLine
			}
		}

	}

     */
    
    for (size_t i = 0; i < levels.size(); i++) {
        vector<vector<string>> coachesOfLevel = levels.at(i)->showCoachesOfLevel(criteria, order);
        
        if(coachesOfLevel.size()>1) coachesTable.addNewLine(coachesOfLevel.at(1));
        
        for (size_t i = 2; i < coachesOfLevel.size(); i++) {
            coachesTable.addDataInSameLine(coachesOfLevel.at(i));
        }
    }

	cout << coachesTable << endl;

}

void Club::showCoachesInactives() const {

	Table coachesTable({ "ID", "Civil ID", "Name", "Birthdate" , "Age", "Position", "Status" });
	map<unsigned int, Worker*> coaches = this->getCoaches();
	map<unsigned int, Worker*>::iterator workersIterator;

	bool firstActive = false;
	for (workersIterator = coaches.begin(); workersIterator != coaches.end(); workersIterator++) {
		if (!workersIterator->second->isActive() && !firstActive) {

			coachesTable.addNewLine(workersIterator->second->showInScreen());
			firstActive = true;
			continue;
		}

		if (!workersIterator->second->isActive() && firstActive && !workersIterator->second->isAthlete()) {

			coachesTable.addDataInSameLine(workersIterator->second->showInScreen()); //addDataInSameLine
		}
	}

	cout << coachesTable << endl;
}



bool Club::isProgramClub() const {
    return this->programClub;
}

//====================================
//=======  MATCHES/TRAININGS  ========
//====================================

void Club::scheduleMatch(string opponentClub, Date matchDate, Level* level, MatchType type) {
        
    Club* opponent = new Club(opponentClub, true);
    level->updateLastMatchId();
    
    string matchId = level->getLevelName() + normalizeId(3, level->getLastMatchId()) + "-" + to_string(matchDate.getYear()) + normalizeId(2,matchDate.getMonth()) + normalizeId(2,matchDate.getDay());
    
    Match* matchToAdd = (type == home) ? new Match(matchDate, this, opponent, matchId) : new Match(matchDate, opponent, this, matchId);
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
    
    
    /* 
     to be completed if we use this function
     
    Club* programClub = NULL;
    unsigned int programClubScore = 0;
    unsigned int otherClubScore = 0;
    Result winLoseDraw = draw;
    
    if ((*matchToRegister)->getHomeTeam()->isProgramClub()) {
        programClub = (*matchToRegister)->getHomeTeam();
        programClubScore = homeTeamScore;
        otherClubScore = awayTeamScore;
        
    }
    else if ((*matchToRegister)->getAwayTeam()->isProgramClub()) {
        programClub = (*matchToRegister)->getAwayTeam();
        programClubScore = awayTeamScore;
        otherClubScore = homeTeamScore;
        
    }
    
    if (programClub) {
        
        if(programClubScore > otherClubScore) {
            winLoseDraw = win;
        }
        else if (programClubScore < otherClubScore) {
            winLoseDraw = lost;
        }
        else {
            winLoseDraw = draw;
        }
        
    }
    */
    for (map<unsigned int, Info*>::iterator iteratorInfoPlayer = matchPlayers.begin(); iteratorInfoPlayer != matchPlayers.end(); iteratorInfoPlayer++) {
        
        /* 
         to be completed when we use this function
        switch (winLoseDraw) {
            case win:
                break;
            case lost:
                break;
            case draw:
                break;
            
        }
        */
        *(level->getMapInfoPlayers().at(iteratorInfoPlayer->first)) += iteratorInfoPlayer->second;
        this->allWorkers.at(iteratorInfoPlayer->first)->addInfo(iteratorInfoPlayer->second);
        
    }
    
    //adicionar a winning, losing and draw frequency depending on the result of the match when we use this function
    
   
    
    
}

void Club::registerMatch(string opponentClub, Date matchDate, Level* level, MatchType type, unsigned int homeTeamScore, unsigned int awayTeamScore, map<unsigned int, Info*> matchPlayers) {
    
    Club* opponent = new Club(opponentClub, true);
    level->updateLastMatchId();
    string matchId = level->getLevelName() + normalizeId(3, level->getLastMatchId()) + "-" + to_string(matchDate.getYear()) + normalizeId(2,matchDate.getMonth()) + normalizeId(2,matchDate.getDay());
    Match* matchToAdd = (type == home) ? new Match(matchDate, this, opponent, matchId) : new Match(matchDate, opponent, this, matchId);
    
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
        
        throw string("Not scheduled match.");
        
    }
    
    vector<unsigned int> filteredVector;
    vector<unsigned int> playersNotCalledUp;
    map<unsigned int, Info*> levelPlayers = level->getMapInfoPlayers();
    
    
    //se não houver jogadores convocados registar todos nos convocados
    if (matchPlayers.size() == 0 && (*matchToRegister)->getInfoPlayers().size() == 0) {
        
        for (map<unsigned int, Info*>::const_iterator levelPlayersIterator = levelPlayers.begin(); levelPlayersIterator != levelPlayers.end(); levelPlayersIterator++) {
            
            if(this->allWorkers.at(levelPlayersIterator->first)->hasValidECG() && this->allWorkers.at(levelPlayersIterator->first)->isActive()) {
                
                filteredVector.push_back(levelPlayersIterator->first);
            }
            
        }
        
    }
    
    else {
        
        
        for (map<unsigned int, Info*>::const_iterator infoIterator = levelPlayers.begin(); infoIterator != levelPlayers.end(); infoIterator++) {
            
            if (this->allWorkers.at(infoIterator->first)->hasValidECG() && this->allWorkers.at(infoIterator->first)->isActive()) {
                bool playerCalledUp = false;
                for (size_t i = 0; i < matchPlayers.size(); i++) {
                    
                    if (matchPlayers.at(i) == infoIterator->first && this->allWorkers.at(matchPlayers.at(i))->hasValidECG()) {
                        
                        playerCalledUp = true;
                        break;
                        
                    }
                    
                }
                if (playerCalledUp) {
                    filteredVector.push_back(infoIterator->first);
                }
                else {
                    playersNotCalledUp.push_back(infoIterator->first);
                };
            }
            
        }
    
    }
    
    (*matchToRegister)->setPlayers(filteredVector);
    map<unsigned int, Info *> infoPlayersEmpty;
    (*matchToRegister)->registerMatch(homeTeamScore, awayTeamScore, infoPlayersEmpty);
    
    //actualizar game frequency
    
    Club* programClub = NULL;
    unsigned int programClubScore = 0;
    unsigned int otherClubScore = 0;
    Result winLoseDraw = draw;
    
    if ((*matchToRegister)->getHomeTeam()->isProgramClub()) {
        programClub = (*matchToRegister)->getHomeTeam();
        programClubScore = homeTeamScore;
        otherClubScore = awayTeamScore;
        
    }
    else if ((*matchToRegister)->getAwayTeam()->isProgramClub()) {
        programClub = (*matchToRegister)->getAwayTeam();
        programClubScore = awayTeamScore;
        otherClubScore = homeTeamScore;
        
    }
    
    if (programClub) {
        
        if(programClubScore > otherClubScore) {
            winLoseDraw = win;
        }
        else if (programClubScore < otherClubScore) {
            winLoseDraw = lost;
        }
        else {
            winLoseDraw = draw;
        }
        
        
        //add for players calld up
        for (size_t i = 0; i < filteredVector.size(); i++) {
            
            switch (winLoseDraw) {
                case win:
                    level->getMapInfoPlayers().at(filteredVector.at(i))->addWinningFreq();
                    this->allWorkers.at(filteredVector.at(i))->getInfo()->addWinningFreq();
                    break;
                case lost:
                    level->getMapInfoPlayers().at(filteredVector.at(i))->addLosingFreq();
                    this->allWorkers.at(filteredVector.at(i))->getInfo()->addLosingFreq();
                    break;
                case draw:
                    level->getMapInfoPlayers().at(filteredVector.at(i))->addDrawFreq();
                    this->allWorkers.at(filteredVector.at(i))->getInfo()->addDrawFreq();
                    break;
                    
            }
            
        }
        
        //add for players not calld up
        for (size_t i = 0; i < playersNotCalledUp.size(); i++) {
            
            switch (winLoseDraw) {
                case win:
                    level->getMapInfoPlayers().at(playersNotCalledUp.at(i))->addWinningFreq(Fraction(0,1));
                    this->allWorkers.at(playersNotCalledUp.at(i))->getInfo()->addWinningFreq(Fraction(0,1));
                    break;
                case lost:
                    level->getMapInfoPlayers().at(playersNotCalledUp.at(i))->addLosingFreq(Fraction(0,1));
                    this->allWorkers.at(playersNotCalledUp.at(i))->getInfo()->addLosingFreq(Fraction(0,1));
                    break;
                case draw:
                    level->getMapInfoPlayers().at(playersNotCalledUp.at(i))->addDrawFreq(Fraction(0,1));
                    this->allWorkers.at(playersNotCalledUp.at(i))->getInfo()->addDrawFreq(Fraction(0,1));
                    break;
                    
            }
            
        }
        
    }
    
    
    
}

void Club::registerMatch(string opponentClub, Date matchDate, Level* level, MatchType type, unsigned int homeTeamScore, unsigned int awayTeamScore, vector<unsigned int> matchPlayers) {
    
    
    Club* opponent = new Club(opponentClub, true);
    level->updateLastMatchId();
    string matchId = level->getLevelName() + normalizeId(3, level->getLastMatchId()) + "-" + to_string(matchDate.getYear()) + normalizeId(2,matchDate.getMonth()) + normalizeId(2,matchDate.getDay());
    Match* matchToAdd = (type == home) ? new Match(matchDate, this, opponent, matchId, true) : new Match(matchDate, opponent, this, matchId, true);
    
    vector<unsigned int> filteredVector;
    vector<unsigned int> playersNotCalledUp;
    map<unsigned int, Info*> levelPlayers = level->getMapInfoPlayers();
    
    if (!matchPlayers.size()) {
        
        for (map<unsigned int, Info*>::const_iterator levelPlayersIterator = levelPlayers.begin(); levelPlayersIterator != levelPlayers.end(); levelPlayersIterator++) {
            
            if(this->allWorkers.at(levelPlayersIterator->first)->hasValidECG() && this->allWorkers.at(levelPlayersIterator->first)->isActive()) {

            
                filteredVector.push_back(levelPlayersIterator->first);
                
            }
            
        }
        
    }
    
    else {
    
        for (map<unsigned int, Info*>::const_iterator infoIterator = levelPlayers.begin(); infoIterator != levelPlayers.end(); infoIterator++) {
            
           
            if (this->allWorkers.at(infoIterator->first)->hasValidECG() && this->allWorkers.at(infoIterator->first)->isActive()) {
                
                bool playerCalledUp = false;
                for (size_t i = 0; i < matchPlayers.size(); i++) {
                    
                    if (matchPlayers.at(i) == infoIterator->first) {
                        
                        playerCalledUp = true;
                        break;
                        
                    }
                    
                }
                if (playerCalledUp) {
                    filteredVector.push_back(infoIterator->first);
                }
                else {
                    playersNotCalledUp.push_back(infoIterator->first);
                };
            }
            
            
            
        }
        
    }
    
    matchToAdd->setPlayers(filteredVector);
    map<unsigned int, Info *> infoPlayersEmpty;
    matchToAdd->registerMatch(homeTeamScore, awayTeamScore, infoPlayersEmpty);
    

    level->addMatchToLevel(matchToAdd);
    
    //actualizar game frequency
    
    Club* programClub = NULL;
    unsigned int programClubScore = 0;
    unsigned int otherClubScore = 0;
    Result winLoseDraw = draw;
    
    if (matchToAdd->getHomeTeam()->isProgramClub()) {
        programClub = matchToAdd->getHomeTeam();
        programClubScore = homeTeamScore;
        otherClubScore = awayTeamScore;
        
    }
    else if (matchToAdd->getAwayTeam()->isProgramClub()) {
        programClub = matchToAdd->getAwayTeam();
        programClubScore = awayTeamScore;
        otherClubScore = homeTeamScore;
        
    }
    
    if (programClub) {
        
        if(programClubScore > otherClubScore) {
            winLoseDraw = win;
        }
        else if (programClubScore < otherClubScore) {
            winLoseDraw = lost;
        }
        else {
            winLoseDraw = draw;
        }
        
        //add for players calld up
        for (size_t i = 0; i < filteredVector.size(); i++) {
            
            
            switch (winLoseDraw) {
                case win:
                    level->getMapInfoPlayers().at(filteredVector.at(i))->addWinningFreq();
                    this->allWorkers.at(filteredVector.at(i))->getInfo()->addWinningFreq();
                    break;
                case lost:
                    level->getMapInfoPlayers().at(filteredVector.at(i))->addLosingFreq();
                    this->allWorkers.at(filteredVector.at(i))->getInfo()->addLosingFreq();
                    break;
                case draw:
                    level->getMapInfoPlayers().at(filteredVector.at(i))->addDrawFreq();
                    this->allWorkers.at(filteredVector.at(i))->getInfo()->addDrawFreq();
                    break;
                    
            }
            
        }
        
        //add for players not calld up
        for (size_t i = 0; i < playersNotCalledUp.size(); i++) {
            
            switch (winLoseDraw) {
                case win:
                    level->getMapInfoPlayers().at(playersNotCalledUp.at(i))->addWinningFreq(Fraction(0,1));
                    this->allWorkers.at(playersNotCalledUp.at(i))->getInfo()->addWinningFreq(Fraction(0,1));
                    break;
                case lost:
                    level->getMapInfoPlayers().at(playersNotCalledUp.at(i))->addLosingFreq(Fraction(0,1));
                    this->allWorkers.at(playersNotCalledUp.at(i))->getInfo()->addLosingFreq(Fraction(0,1));
                    break;
                case draw:
                    level->getMapInfoPlayers().at(playersNotCalledUp.at(i))->addDrawFreq(Fraction(0,1));
                    this->allWorkers.at(playersNotCalledUp.at(i))->getInfo()->addDrawFreq(Fraction(0,1));
                    break;
                    
            }
            
        }
        
    }
    
    
    cout << endl;
    
}

void Club::callUpPlayers(string matchId, vector<unsigned int> matchPlayers, Level* level) {
    
    vector<Match*> listOfLevelMatches = level->getAllLevelMatches();
    vector<Match*>::const_iterator matchToRegister = listOfLevelMatches.begin();
    while (matchToRegister != listOfLevelMatches.end()) {
        
        if ((*matchToRegister)->getId() == matchId) {
            
            break;
            
        }
        matchToRegister++;
        
    }
    
    
    if(matchToRegister == listOfLevelMatches.end()) {
        
        throw string("Not scheduled match.");
        
    }
    
    (*matchToRegister)->setPlayers(matchPlayers);
    
}

void Club::callUpPlayers(string opponentClub, Date matchDate, Level* level, MatchType type, vector<unsigned int> matchPlayers) {
    
    Club* opponent = new Club(opponentClub, true);
    level->updateLastMatchId();
    
    string matchId = level->getLevelName() + normalizeId(3, level->getLastMatchId()) + "-" + to_string(matchDate.getYear()) + normalizeId(2,matchDate.getMonth()) + normalizeId(2,matchDate.getDay());
    
    Match* matchToAdd = (type == home) ? new Match(matchDate, this, opponent, matchId) : new Match(matchDate, opponent, this, matchId);
    matchToAdd->setPlayers(matchPlayers);
    level->addMatchToLevel(matchToAdd);

}

//=======================================
//=======  PRESERVE INFORMATION  ========
//=======================================

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

			if (i->second->getECG() != NULL) {
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

		if (i->second->isAthlete() && !(i->second->isActive())) {

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

	currentFile << FILE_SEPARATOR << endl;

	// Save Inactive Coaches

	tmpMap = getInactives();

	for (map<unsigned int, Worker*>::const_iterator i = tmpMap.begin(); i != tmpMap.end(); i++) {

		if (!i->second->isAthlete() && !(i->second->isActive())) {

			currentFile << i->second->getID();
			currentFile << " ";

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

	for (vector<Season*>::const_iterator i = this->seasons.begin(); i != this->seasons.end(); i++) {

		ofstream athletesOStream;
		ofstream coachesOStream;
		ofstream matchesOStream;

		for (unsigned int iteLevels = 0; iteLevels < (*i)->getLevels().size(); iteLevels++) {

			athletesOStream.open((*i)->getLevels().at(iteLevels)->getPathToLevelAthletesFile());
			coachesOStream.open((*i)->getLevels().at(iteLevels)->getPathToLevelCoachesFile());
			matchesOStream.open((*i)->getLevels().at(iteLevels)->getPathToLevelMatchesFile());

			map<unsigned int, Info*> tempPlayersMap = (*i)->getLevels().at(iteLevels)->getMapInfoPlayers();

			map<unsigned int, Info*>::const_iterator playersIterator = tempPlayersMap.begin();

			while (playersIterator != tempPlayersMap.end()) {

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

			for (vector<unsigned int>::iterator iteratorCoaches = tmpVectorCoaches.begin(); iteratorCoaches != tmpVectorCoaches.end(); iteratorCoaches++) {

				coachesOStream << *iteratorCoaches;

				if (iteratorCoaches != tmpVectorCoaches.end()) {

					coachesOStream << endl;

				}


			}

			matchesOStream << (*i)->getLevels().at(iteLevels)->getLastMatchId() << endl;

			vector<Match*> tmpVectorMatches = (*i)->getLevels().at(iteLevels)->getAllLevelMatches();

			for (vector<Match*>::const_iterator iteratorMatches = tmpVectorMatches.begin(); iteratorMatches != tmpVectorMatches.end(); iteratorMatches++) {

				if ((*iteratorMatches)->getHomeTeam() == this) {

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

			vector<Match*> levelMatchesTmp = (*i)->getLevels().at(iteLevels)->getAllLevelMatches();
			string pathToCurrentLevelFolder = (*i)->getLevels().at(iteLevels)->getPathToLevelFolder();
			string pathToCurrentLevelMatchesFolder = (*i)->getLevels().at(iteLevels)->getPathToLevelMatchesFolder();

			for (size_t i = 0; i < levelMatchesTmp.size(); i++) {

				string pathToCurrentMatchFile = stringPath(pathToCurrentLevelMatchesFolder + "/" + levelMatchesTmp.at(i)->getId() + ".txt");
				ofstream matchesFile;
				matchesFile.open(pathToCurrentMatchFile);
				map<unsigned int, Info*> mapInfoPlayers = levelMatchesTmp.at(i)->getInfoPlayers();
				for (map<unsigned int, Info*>::const_iterator matchMapInfoPlayersIterator = mapInfoPlayers.begin(); matchMapInfoPlayersIterator != mapInfoPlayers.end(); matchMapInfoPlayersIterator++) {

					matchesFile << matchMapInfoPlayersIterator->first << " ; ";
					matchesFile << this->allWorkers.at(matchMapInfoPlayersIterator->first)->getPosition() << " ; ";
					matchesFile << *(matchMapInfoPlayersIterator->second);

					if (matchMapInfoPlayersIterator != mapInfoPlayers.end()) {
						matchesFile << endl;
					}

				}
				matchesFile.close();

			}

			athletesOStream.close();
			coachesOStream.close();
			matchesOStream.close();
            
            (*i)->getLevels().at(iteLevels)->saveLevelTrainings();
            (*i)->getLevels().at(iteLevels)->saveLevelTournaments();


			(*i)->getLevels().at(iteLevels)->saveLevelTrainings();
		}


	}

}

vector<vector<string>> Club::getPlayersDiplomas() const {
    
    vector<vector<string>> result;
    BST<AthletePtr_BST> playersBST(0);
    
    map<unsigned int, Worker*> athletesMap = this->getAthletes();
    for (map<unsigned int, Worker*>::const_iterator playersIterator = athletesMap.begin(); playersIterator != athletesMap.end(); playersIterator++) {
        
        AthletePtr_BST thisAthleteStructBST(playersIterator->second);
        playersBST.insert(thisAthleteStructBST);
        
    }
    
    BSTItrIn<AthletePtr_BST> bstIterator(playersBST);
    int rank = 0;
    
    while (!bstIterator.isAtEnd()) {
        
        vector<string> eachPlayerResult;
        string rankString = to_string(bstIterator.retrieve().athletePtr->getID());
        eachPlayerResult.push_back(rankString);
        rankString = transformNumberToOrder(++rank);
        
        string playerDiploma;
        string playerTrainingAttendance;
        string playerWonGames;
        string playerLostGames;
        string playerDrawGames;
        
        if(rank <= 3) {
            
            if (rank == 1) {
                playerDiploma = bstIterator.retrieve().athletePtr->getName() + ", congratulations!! You are our best player! Keep the good working!";
            }
            else {
                playerDiploma = bstIterator.retrieve().athletePtr->getName() + ", congratulations!! You are our " + rankString + " best player! Keep the good working!";
            }
            
        }
        else {
            playerDiploma = bstIterator.retrieve().athletePtr->getName() + ", you are at " + rankString + " position!";
        }
        
        playerTrainingAttendance = bstIterator.retrieve().athletePtr->getInfo()->getTrainingFreq().getFrac();
        playerWonGames = bstIterator.retrieve().athletePtr->getInfo()->getWinningFreq().getFrac();
        playerLostGames = bstIterator.retrieve().athletePtr->getInfo()->getLosingFreq().getFrac();
        playerDrawGames = bstIterator.retrieve().athletePtr->getInfo()->getDrawFreq().getFrac();
        
        eachPlayerResult.push_back(playerDiploma);
        eachPlayerResult.push_back(playerTrainingAttendance);
        eachPlayerResult.push_back(playerWonGames);
        eachPlayerResult.push_back(playerDrawGames);
        eachPlayerResult.push_back(playerLostGames);
		eachPlayerResult.push_back(to_string(bstIterator.retrieve().generalPerformance()));
        result.push_back(eachPlayerResult);
        
        bstIterator.advance();
        
    }

	Table athletesTable({ "ID", "Diploma", "Training attendance" , "Wins", "Draws", "Losses", "Performance" });
    
	for (size_t i = 0; i < result.size(); i++) {
		
		if (!i)
			athletesTable.addNewLine(result.at(i));
		else {
			athletesTable.addDataInSameLine({ "" });

			athletesTable.addDataInSameLine(result.at(i));
				
		}
	}

	cout << athletesTable;
    return result;
}


vector<vector<string>> Club::getFormerPlayersPostals() const {
    
    vector<vector<string>> result;
    for (hashTableInactivePlayers::const_iterator formerWorkersIterator = this->formerPlayers.begin(); formerWorkersIterator != this->formerPlayers.end(); formerWorkersIterator++) {
        
        Date thisYearBD = (*formerWorkersIterator)->getBirthdate();
        thisYearBD.setYear((*formerWorkersIterator)->getBirthdate().getYear() + (*formerWorkersIterator)->getAge() + 1);
        Date in10Days = Date() + 10;
        
        if (Date() < thisYearBD && thisYearBD < in10Days) {
            
            vector<string> eachPlayerGreeting;
            
        
            string id = to_string((*formerWorkersIterator)->getID());
            string message = "Dear " + (*formerWorkersIterator)->getName() + ", from " + this->clubName + ", we wish you a happy " +  transformNumberToOrder(Date() - (*formerWorkersIterator)->getBirthdate() + 1) + " birthday on " + thisYearBD.str() + "!";
            eachPlayerGreeting.push_back(id);
            eachPlayerGreeting.push_back(message);
            result.push_back(eachPlayerGreeting);
            
        }
        
    }
    
	Table workersTable({ "ID", "Congratulation message" });

	for (size_t i = 0; i < result.size(); i++) {

		if (!i)
			workersTable.addNewLine(result.at(i));
		else {
			workersTable.addDataInSameLine({ "" });

			workersTable.addDataInSameLine(result.at(i));

		}
	}

	cout << workersTable;
    return result;
}

