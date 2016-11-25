#pragma once

#include "InfoAthletes.hpp"

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
    bool getTrainingGiven() const;
	
    bool isRegistered() const;

	static unsigned int getIdCounter();
    
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
