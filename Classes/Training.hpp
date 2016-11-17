#pragma once

#include "InfoAthletes.hpp"

class Training {
private:
	Date trainingDate;
	static unsigned int trainingCounter;
	unsigned int id;
    vector<unsigned int> playersTrained;

public:
	//! Training's constructor
	/*!
	* This is a constructor that creates a new training using the training's date and training's id
	*/
    Training(Date trainingDate, vector<unsigned int> playersIds, unsigned int id = 0);

    Training(istream& iss);
    static void resetID(unsigned int newId);
	
	/*!
	*	This is a method that gets the training's date
	*/
	Date getTrainingDate() const;
	
	/*!
	*	This is a method that the training's id
	*/
	unsigned int getId() const;
    vector<unsigned int> getPlayers() const;
    
    void setPlayers(vector<unsigned int> playersTrained);
    void setDate(Date newDate);
    friend ostream& operator<<(ostream& outStream, Training& trainingToSave);
    
};
