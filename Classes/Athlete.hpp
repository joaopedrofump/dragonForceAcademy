//
//  Athlete.hpp
//  DragonForceAcadamy
//
//  Created by Joao Furriel on 12/10/16.
//  Copyright © 2016 João Furriel Pinheiro. All rights reserved.
//
#pragma once

#ifndef Athlete_hpp
#define Athlete_hpp

#include "Coach.hpp"

class Athlete : public Worker {
    
protected:
    unsigned char height; //Athlete's height
    ECG* ecg; //apontador para ECG quando houver classe
	Position position; //Athlete's position

public:
	/*!
	* This is the constructor that creates an athleteuses name, birthdate, civilID, height. The id is set automatically
	*/
    Athlete(string name, Date birthdate, unsigned int civilID, unsigned char height, unsigned int id = 0);
	
	/*!
	*	This is the constructor that uses his subposition passed by reference and his position
	*/
	Athlete(string &newAthlete, Position position);

	//! Athlete's class destructor
	 ~Athlete();
	
	 /*!
	 * This is a method that gets the athlete's position
	 */
    unsigned int getPosition() const;

	/*!
	*	This is a method that gets the athlete's height
	*/
	unsigned int getHeight() const;

	/*!
	*	This is a method that return a pointer to the athlete's ECG  
	*/
	ECG* getECG() const;
    
	/*!
	*	This is a method that updates the athlete's ECG (result and expiration date)
	*/
    void updateECG(bool resultado, Date expirationDate);

	/*!
	*	This is a method that checks if the worker is an athlete
	*/
	bool isAthlete() const;
    
	/*!
	*	This is a method that generates the athlete's performance information
	*/
    string generateInfo() const;
    
	/*!
		This is a method that shows all the athlete's informaton on the screen
	*/
    vector<string> showInScreen() const;
    
    void setBirthDate(Date newBirthdate);
    
    void setHeight(unsigned int newHeight);
};


#endif /* Athlete_hpp */
