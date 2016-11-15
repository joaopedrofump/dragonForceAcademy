#pragma once

#include "InfoAthletes.hpp"

class Training {
private:
	Date trainingDate;
	static unsigned int trainingCounter;
	unsigned int id;
    vector<unsigned int> playersTrained;

public:
    Training(Date trainingDate, vector<unsigned int> playersIds, unsigned int id = 0);
    Training(istream& iss);
    static void resetID(unsigned int newId);
    
	Date getTrainingDate() const;
	unsigned int getId() const;
    vector<unsigned int> getPlayers() const;
    
    void setPlayers(vector<unsigned int> playersTrained);
    void setDate(Date newDate);
    
};
