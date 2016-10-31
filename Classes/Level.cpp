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

		Date tmpExpECG(tmpAthlete.substr(0, tmpAthlete.find(';', 0) - 1));

		tmpAthlete = tmpAthlete.substr(tmpAthlete.find(';', 0) + 2);

		Fraction tmpAthleteAssiduity(tmpAthlete.substr(0, tmpAthlete.find(';', 0) - 1));

		tmpAthlete = tmpAthlete.substr(tmpAthlete.find(';', 0) + 2);

		unsigned int tmpAthleteYellowCards = atoi(tmpAthlete.substr(0, tmpAthlete.find(';', 0) - 1).c_str());

		tmpAthlete = tmpAthlete.substr(tmpAthlete.find(';', 0) + 2);

		unsigned int tmpAthleteRedCards = atoi(tmpAthlete.substr(0, tmpAthlete.find(';', 0) - 1).c_str());

		tmpAthlete = tmpAthlete.substr(tmpAthlete.find(';', 0) + 2);

		Info* infoTmpAthlete;

		// Read Goalkeepers specific informations
		if (positionsMap.at(tmpAthletePos) == GoalkeeperPos) {

			unsigned int saves = atoi(tmpAthlete.substr(0, tmpAthlete.find(';', 0) - 1).c_str());

			tmpAthlete = tmpAthlete.substr(tmpAthlete.find(';', 0) + 2);

			unsigned int goalsConceeded = atoi(tmpAthlete.substr(0, tmpAthlete.find(';', 0) - 1).c_str());

			tmpAthlete = tmpAthlete.substr(tmpAthlete.find(';', 0) + 2);


			infoTmpAthlete = new InfoGK(tmpAthleteAssiduity, tmpAthleteYellowCards, tmpAthleteRedCards, saves, goalsConceeded);
		
		}

		// Read Defenders specific informations
		else if(positionsMap.at(tmpAthletePos) == DefenderPos){


			string tmpAthletePositions = tmpAthlete.substr(0, tmpAthlete.find(';', 0) - 1);

			tmpAthlete = tmpAthlete.substr(tmpAthlete.find(';', 0) + 2);

			// Read positions
			vector<DefenderPosition> positions;

			while (tmpAthletePositions != "") {
				
				positions.push_back(defendersMap.at(tmpAthletePositions.substr(0, tmpAthletePositions.find(',', 0) - 1)));

				if (tmpAthletePositions.find(',', 0) >= tmpAthletePositions.length())
					break;

				tmpAthletePositions = tmpAthletePositions.substr(tmpAthletePositions.find(',', 0) + 2);
			}
			
			// Pass Acuracy
			Fraction passAccuracy(tmpAthlete.substr(0, tmpAthlete.find(';', 0) - 1));

			tmpAthlete = tmpAthlete.substr(tmpAthlete.find(';', 0) + 2);

			// Tackles
			unsigned int tackles = atoi(tmpAthlete.substr(0, tmpAthlete.find(';', 0) - 1).c_str());

			tmpAthlete = tmpAthlete.substr(tmpAthlete.find(';', 0) + 2);

			// Goals Conceeded
			unsigned int goalsConceeded = atoi(tmpAthlete.substr(0, tmpAthlete.find(';', 0) - 1).c_str());

			tmpAthlete = tmpAthlete.substr(tmpAthlete.find(';', 0) + 2);

			// Faults
			unsigned int faults = atoi(tmpAthlete.substr(0, tmpAthlete.find(';', 0) - 1).c_str());

			tmpAthlete = tmpAthlete.substr(tmpAthlete.find(';', 0) + 2);

			infoTmpAthlete = new InfoDF(tmpAthleteAssiduity, tmpAthleteYellowCards, tmpAthleteRedCards,
										tackles, goalsConceeded, faults, passAccuracy, positions);

		}

		// Read Midfielders specific informations
		else if(positionsMap.at(tmpAthletePos) == MidfielderPos) {

			string tmpAthletePositions = tmpAthlete.substr(0, tmpAthlete.find(';', 0) - 1);

			tmpAthlete = tmpAthlete.substr(tmpAthlete.find(';', 0) + 2);

			// Read positions
			vector<MidfielderPosition> positions;

			while (tmpAthletePositions != "") {

				string test = tmpAthletePositions.substr(0, tmpAthletePositions.find(',', 0) - 1);

				positions.push_back(midfieldersMap.at(tmpAthletePositions.substr(0, tmpAthletePositions.find(',', 0) - 1)));

				if (tmpAthletePositions.find(',', 0) >= tmpAthletePositions.length())
					break;

				tmpAthletePositions = tmpAthletePositions.substr(tmpAthletePositions.find(',', 0) + 2);
			}

			// Pass Acuracy
			Fraction passAccuracy(tmpAthlete.substr(0, tmpAthlete.find(';', 0) - 1));

			tmpAthlete = tmpAthlete.substr(tmpAthlete.find(';', 0) + 2);

			// Tackles
			unsigned int tackles = atoi(tmpAthlete.substr(0, tmpAthlete.find(';', 0) - 1).c_str());

			tmpAthlete = tmpAthlete.substr(tmpAthlete.find(';', 0) + 2);

			// Goals Scored
			unsigned int goalsScored = atoi(tmpAthlete.substr(0, tmpAthlete.find(';', 0) - 1).c_str());

			tmpAthlete = tmpAthlete.substr(tmpAthlete.find(';', 0) + 2);

			// Assists made
			unsigned int assistsMade = atoi(tmpAthlete.substr(0, tmpAthlete.find(';', 0) - 1).c_str());

			tmpAthlete = tmpAthlete.substr(tmpAthlete.find(';', 0) + 2);

			// Faults
			unsigned int faults = atoi(tmpAthlete.substr(0, tmpAthlete.find(';', 0) - 1).c_str());

			tmpAthlete = tmpAthlete.substr(tmpAthlete.find(';', 0) + 2);

			infoTmpAthlete = new InfoMF(tmpAthleteAssiduity, tmpAthleteYellowCards, tmpAthleteRedCards,
				tackles, goalsScored, assistsMade, faults, passAccuracy, positions);

		}

		// Read Goalkeeper specific informations
		else if (positionsMap.at(tmpAthletePos) == ForwardPos) {

			string tmpAthletePositions = tmpAthlete.substr(0, tmpAthlete.find(';', 0) - 1);

			tmpAthlete = tmpAthlete.substr(tmpAthlete.find(';', 0) + 2);

			// Read positions
			vector<ForwardPosition> positions;

			while (tmpAthletePositions != "") {

				positions.push_back(forwardsMap.at(tmpAthletePositions.substr(0, tmpAthletePositions.find(',', 0) - 1)));

				if (tmpAthletePositions.find(',', 0) >= tmpAthletePositions.length())
					break;

				tmpAthletePositions = tmpAthletePositions.substr(tmpAthletePositions.find(',', 0) + 2);
			}

			// Pass Acuracy
			Fraction passAccuracy(tmpAthlete.substr(0, tmpAthlete.find(';', 0) - 1));

			tmpAthlete = tmpAthlete.substr(tmpAthlete.find(';', 0) + 2);

			// Goals Scored
			unsigned int goalsScored = atoi(tmpAthlete.substr(0, tmpAthlete.find(';', 0) - 1).c_str());

			tmpAthlete = tmpAthlete.substr(tmpAthlete.find(';', 0) + 2);

			// Assists made
			unsigned int assistsMade = atoi(tmpAthlete.substr(0, tmpAthlete.find(';', 0) - 1).c_str());

			tmpAthlete = tmpAthlete.substr(tmpAthlete.find(';', 0) + 2);

			infoTmpAthlete = new InfoFW(tmpAthleteAssiduity, tmpAthleteYellowCards, tmpAthleteRedCards,
										goalsScored, assistsMade, passAccuracy, positions);

		}

		

		this->mapInfoSeason.insert({ tmpAthleteId, infoTmpAthlete });

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
