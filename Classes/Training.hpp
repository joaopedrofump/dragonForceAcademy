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

class Training {
private:
	Date trainingDate;
	static unsigned int trainingCounter;
	unsigned int id;
    vector<unsigned int> playersTrained;
    bool registed;

public:
    Training(Date trainingDate, vector<unsigned int> playersIds, unsigned int id = 0);
    Training(istream& iss);
    static void resetID(unsigned int newId);
    
	Date getTrainingDate() const;
	unsigned int getId() const;
    vector<unsigned int> getPlayers() const;
    bool getTrainingGiven() const;
    bool isRegistered() const;
    
    void setPlayers(vector<unsigned int> playersTrained);
    void setDate(Date newDate);
    friend ostream& operator<<(ostream& outStream, Training& trainingToSave);
    void setRegistered();
    void cancelRegister();
    
};

class SortTraining {
private:
    SortCriteria criteria;
    SortOrder order;
public:
    SortTraining(SortCriteria criteria, SortOrder order);
    bool operator()(Training* t1, Training* t2);
};
