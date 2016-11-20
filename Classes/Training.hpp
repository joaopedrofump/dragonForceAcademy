#pragma once

#include "InfoAthletes.hpp"

class Training {
private:
	Date trainingDate; //! training's date
	static unsigned int trainingCounter; //! number of trainings performed
	unsigned int id; //! training's id
    vector<unsigned int> playersTrained; //! vector that includes all the players present in that training

public:
    
	//! Training's constructor

	/*!
	*	This is a constructor that creates a new training using the training date and a vector containing the ids of the player that attended the training. The training's id is set automatically.
	*/
	Training(Date trainingDate, vector<unsigned int> playersIds, unsigned int id = 0);
    
	Training(istream& iss);
    
	/*!
		This is a method that resets the training's id and adds a training performed
	*/
	static void resetID(unsigned int newId);
    

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
