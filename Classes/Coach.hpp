#pragma once

/*#include <stdio.h>
#include <iostream>*/
#include "Worker.hpp"

class Coach : public Worker {

private:
	CoachType trainerPosition;

public:
	Coach(string name, Date birthdate, unsigned int civilID, CoachType coachRole, unsigned int id = 0);
	Coach(string &newCoach);
	unsigned int getID() const;
	bool isAthlete() const;

	unsigned int getPosition() const;
	unsigned int getHeight() const;

    Info* getInfo() const { Info* res = new Info(); return res;};
    void addInfo(Info* moreInfo){};

    string generateInfo() const;
    
    vector<string> showInScreen() const;
    
    void setBirthDate(Date newBirthdate);
    void setCoachType(CoachType newType);
};
