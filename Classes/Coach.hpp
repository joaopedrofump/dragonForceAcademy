#pragma once

/*#include <stdio.h>
#include <iostream>*/
#include "Worker.hpp"

class Coach : public Worker {

private:
	CoachType trainerPosition; //coach's position

public:
	
	//! Coach constructor
	/*!
	*	This is a constructor that uses the name, birthdate, civilID, coach's role and id
	*/
	Coach(string name, Date birthdate, unsigned int civilID, CoachType coachRole, unsigned int id = 0);
	
	/*!
	*	This is a constructor that uses the coach's name
	*/
	Coach(string &newCoach);
	
	/*!
	*	This is a method that gets the coach's id
	*/
	unsigned int getID() const;

	/*!
	*	This is a method that checks if the worker is an athlete
	*/
	bool isAthlete() const;

	/*!
	*	This is a method that gets the coach's position
	*/
	unsigned int getPosition() const;

	/*!
	*	This is a method that gets the coach's height
	*/
	unsigned int getHeight() const;

	/*!
	*	This is a method that gets the coach's information
	*/
    Info* getInfo() const { Info* res = new Info(); return res;};

	/*!
	*	This is a method that adds information to the coach
	*/
    void addInfo(Info* moreInfo){};

	/*!
	*	This is a method that generates coach's information
	*/
    string generateInfo() const;
    
	/*!
	*	This is a method that show all the coach's information on the screen
	*/
    vector<string> showInScreen() const;
};
