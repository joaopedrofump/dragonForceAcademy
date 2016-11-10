#include "Level.h"

#include "Club.hpp"

/*Level::Level(ageLevel ageLevelName, vector<Coach*> coachesVector, map<Athlete*, Info*> mapInfoSeason) {

	this->ageLevelName = ageLevelName;
	this->trainers = coachesVector;
	this->mapInfoSeason = mapInfoSeason;

}*/

Level::Level(ifstream &in, string yearOfSeason, string fileClub, Club* club) {

	string tmpString;
	getline(in, tmpString);


	// Read information of this level
	ifstream inStreamLevel;

	inStreamLevel.open((fileClub + "\\" + trimLink(yearOfSeason) + "\\" + tmpString).c_str());

	
	if (!inStreamLevel.eof()) {
		
		string idHeadCoach;
		getline(inStreamLevel, idHeadCoach);

		unsigned int headCoachId = atoi(idHeadCoach.c_str());

		for (size_t i = 0; i < club->getWorkers().size(); i++) {
			if (club->getWorkers().at(i)->getID() == headCoachId) {
				this->mainCoach = (Coach*)club->getWorkers().at(i);
			}
		}

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
	ifstream inStreamAthletesLevel;

	inStreamAthletesLevel.open((fileClub + "\\" + trimLink(yearOfSeason) + "\\" + trimLink(tmpString) + "\\Athletes.txt").c_str());

	while (!inStreamAthletesLevel.eof()) {

		string tmpAthlete;
		getline(inStreamAthletesLevel, tmpAthlete);

		if (tmpAthlete == FILE_SEPARATOR)
			break;


		unsigned int tmpAthleteId = atoi(tmpAthlete.substr(0, tmpAthlete.find(';', 0) - 1).c_str());

		tmpAthlete = tmpAthlete.substr(tmpAthlete.find(';', 0) + 2);

		Date tmpExpECG(tmpAthlete.substr(0, tmpAthlete.find(';', 0) - 1));

		tmpAthlete = tmpAthlete.substr(tmpAthlete.find(';', 0) + 2);

		Fraction tmpAthleteAssiduity(tmpAthlete.substr(0, tmpAthlete.find(';', 0) - 1));

		tmpAthlete = tmpAthlete.substr(tmpAthlete.find(';', 0) + 2);

		unsigned int tmpAthleteYellowCards = atoi(tmpAthlete.substr(0, tmpAthlete.find(';', 0) - 1).c_str());

		tmpAthlete = tmpAthlete.substr(tmpAthlete.find(';', 0) + 2);

		unsigned int tmpAthleteRedCards = atoi(tmpAthlete.substr(0, tmpAthlete.find(';', 0) - 1).c_str());

		tmpAthlete = tmpAthlete.substr(tmpAthlete.find(';', 0) + 2);

		Athlete* tmpAthletePtr = 0;

		for (size_t i = 0; i < club->getWorkers().size(); i++) {
			if (club->getWorkers().at(i)->getID() == tmpAthleteId) {
				tmpAthletePtr = (Athlete*)club->getWorkers().at(i);
			}
		}

		Info* infoTmpAthlete;

		// Read Goalkeepers specific informations
		if (tmpAthletePtr->getPosition() == GoalkeeperPos) {

			unsigned int saves = atoi(tmpAthlete.substr(0, tmpAthlete.find(';', 0) - 1).c_str());

			tmpAthlete = tmpAthlete.substr(tmpAthlete.find(';', 0) + 2);

			unsigned int goalsConceeded = atoi(tmpAthlete.substr(0, tmpAthlete.find(';', 0) - 1).c_str());

			tmpAthlete = tmpAthlete.substr(tmpAthlete.find(';', 0) + 2);


			infoTmpAthlete = new InfoGK(tmpAthleteAssiduity, tmpAthleteYellowCards, tmpAthleteRedCards, saves, goalsConceeded);
		
		}

		// Read Defenders specific informations
		else if(tmpAthletePtr->getPosition() == DefenderPos){

			/*InfoDF* infoTmpAthletePos = new InfoDF;
			infoTmpAthletePos->trainingFreq = tmpAthleteAssiduity;
			infoTmpAthletePos->yellowCards = tmpAthleteYellowCards;
			infoTmpAthletePos->redCards = tmpAthleteRedCards;*/

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

			//cout << static_cast<InfoDF*>(infoTmpAthlete)->faults;
		}

		// Read Midfielders specific informations
		else if(tmpAthletePtr->getPosition() == MidfielderPos) {

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
		else if (tmpAthletePtr->getPosition() == ForwardPos) {

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

		

		this->mapInfoSeason.insert({ tmpAthletePtr, infoTmpAthlete });

	}

	inStreamAthletesLevel.close();

	// Read information of coaches

	ifstream inStreamCoachesLevel;

	inStreamCoachesLevel.open((fileClub + "\\" + trimLink(yearOfSeason) + "\\" + trimLink(tmpString) + "\\Coaches.txt").c_str());
	
	while (!inStreamAthletesLevel.eof()) {

		string tmpCoach;
		getline(inStreamAthletesLevel, tmpCoach);

		for (size_t i = 0; i < club->getWorkers().size(); i++) {
			if (club->getWorkers().at(i)->getID() == atoi(tmpCoach.c_str())) {
				this->trainers.push_back((Coach*)club->getWorkers().at(i));
			}
		}
	}

	inStreamCoachesLevel.close();
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

map<Athlete*, Info*> Level::getMapInfoSeason() const
{
	return mapInfoSeason;
}
