//
//  Defender.hpp
//  DragonForceAcadamy
//
//  Created by Joao Furriel on 19/10/16.
//  Copyright © 2016 João Furriel Pinheiro. All rights reserved.
//
#pragma once

#ifndef Defender_hpp
#define Defender_hpp

#include "Midfielder.hpp"

class Defender : public Athlete {
private:
    Info* generalInfo; //defender's general info
    
public:
    //! Defender's constructor
	/*!
	*	This is the constructor that creates a defender using his name, birthdate, civilID and height. The id is set automatically
	*/
	Defender(string name, Date birthdate, unsigned int civilID, unsigned char height, unsigned int = 0);
	
	/*!
	*	This is the constructor that creates a defender using his defending position
	*/
	Defender(string &newDF);
    
	//! Defender's destructor
	~Defender();
    
	/*!
	*	This is the method that gets the defender's id
	*/
	unsigned int getID() const;
    
	/*!
	*	This is the method that gets the defender's performance information 
	*/
	Info* getInfo() const;
    
	/*!
	*	This is the method that adds information to the defender
	*/
	void addInfo(Info* moreInfo);
    
};
    

#endif /* Defender_hpp */
