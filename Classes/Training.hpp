#pragma once

#include "InfoAthletes.hpp"

enum SortCriteria {
    
    id,
    date,
    numberOfPlayers
    
};

enum SortOrder {
    ascending,
    descending
};

class Club;

class Training {
private:
	Date trainingDate;
	static unsigned int trainingCounter;
	unsigned int id;
    vector<unsigned int> playersTrained;
    bool registed;

public:

	//! Training's constructor

	/*!
	*	This is a constructor that creates a new training using the training date and a vector containing the ids of the player that attended the training. The training's id is set automatically.
	*/
Training(Date trainingDate, vector<unsigned int> playersIds, unsigned int id = 0);

    Training(istream& iss);
    static void resetID(unsigned int newId);
	

	/*!
		This is a method that resets the training's id and adds a training performed
	*/
    


	Date getTrainingDate() const;
	
	/*!
	*	This is a method that the training's id
	*/
	unsigned int getId() const;
    vector<unsigned int> getPlayers() const;
    bool getTrainingGiven() const;
    bool isRegistered() const;
    
    void setPlayers(vector<unsigned int> playersTrained);
    void setDate(Date newDate);
    friend ostream& operator<<(ostream &outStream, Training &trainingToSave);
    void setRegistered();
    void cancelRegister();

	vector<vector<string>> showInScreen(Club* parentClub) const;
    
};

class SortTraining {
private:
    SortCriteria criteria;
    SortOrder order;
public:
    SortTraining(SortCriteria criteria, SortOrder order);
    bool operator()(Training* t1, Training* t2);
};
