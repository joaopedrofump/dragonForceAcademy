//
//  Goalkeeper.hpp
//  DragonForceAcadamy
//
//  Created by Joao Furriel on 13/10/16.
//  Copyright © 2016 João Furriel Pinheiro. All rights reserved.
//
#pragma once

#ifndef Goalkeeper_hpp
#define Goalkeeper_hpp

#include "Defender.hpp"

class Goalkeeper : public Athlete {
private:
    Info* generalInfo; //goalkeeper's general info
        
public:
    
	//! Goalkeeper's constructors
	/*!
	*	This is a constructor that creates a new goalkeeper using his name, birthdate, civilID and height. The id is set automatically 
	*/
	Goalkeeper(string name, Date birthdate, unsigned int civilID, unsigned char height, unsigned int = 0);
	
	/*!
	*	This is a constructor that creates a new goalkeeper using goalkeeping position
	*/
	Goalkeeper(string &newGK);
    
	//! Goalkeeper's deconstructor
	~Goalkeeper();
    
	/*!
	*	This is a method that gets the goalkeeper's id
	*/
	unsigned int getID() const;
    
	/*!
	*	This is a method that gets the goalkeeper's performance information 
	*/
	Info* getInfo() const;
    
	/*!
	*	This is a method that adds information to the goalkeeper
	*/
	void addInfo(Info* moreInfo);

};

#endif /* Goalkeeper_hpp */
