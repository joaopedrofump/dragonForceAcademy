#include "Level.h"

Level::Level(ageLevel ageLevelName, vector<Athlete *> playersVector, vector<Trainer*> trainersVector) {

	this->ageLevelName = ageLevelName;
	this->players = playersVector;
	this->trainers = trainersVector;

}

Level::Level(ifstream &in) {

	string tmpString;
	getline(in, tmpString);

	ifstream inStreamLevel;

	inStreamLevel.open(tmpString.c_str());

	while (!inStreamLevel.eof()) {
		
		string tmpWorker;
		getline(inStreamLevel, tmpWorker);


		// Checking if is a Trainer Responsible (TR), a Trainer (T), or a Player (P)
		string init = tmpWorker.substr(0, tmpWorker.find(';', 0));
		
		if(init == "TR" || init == "T"){

			// Read TrainerR's name
			string nameTrainerR = tmpWorker.substr(0, tmpWorker.find(';', 0));
			validateName(nameTrainerR);

			// Read TrainerR's birthday
			string birthDate = tmpWorker.substr(0, tmpWorker.find(';', 0));
			trimString(birthDate);

			Date birthDayTrainer(birthDate);

			// Read TrainerR's position
			Position positionTrainer = positionsMap.at(tmpWorker.substr(0, tmpWorker.find(';', 0)));

			Worker* newTrainerR = new Trainer(nameTrainerR, birthDayTrainer, positionTrainer);

			if(init == "TR")
				this->trainerResponsible = newTrainerR;

		}
		else if (init == "P") {

			//CONTINUAR
		}
	}
}