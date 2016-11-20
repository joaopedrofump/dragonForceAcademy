//
//  Midfielder.hpp
//  DragonForceAcadamy
//
//  Created by Joao Furriel on 20/10/16.
//  Copyright © 2016 João Furriel Pinheiro. All rights reserved.
//
#pragma once

#ifndef Midfielder_hpp
#define Midfielder_hpp

#include "Forward.hpp"

class Midfielder : public Athlete {
private:
    Info* generalInfo; //! midfielder's general information
public:
    //! Midfielder's constructors

	/*!
	*	This is a constructor that creates a new midfielder using his name, birthdate, civilID, height. Id is automatically set
	*/
	Midfielder(string name, Date birthdate, unsigned int civilID, unsigned char height, unsigned int id = 0);
	
	/*!
	*	This is a constructor that creates a new midfielder using his midfield position passed by reference
	*/
	Midfielder(string &newMF);
    
	//! Midfielder's destructor
	~Midfielder();
    
	/*!
	*	This is a method that gets the midfielder's id
	*/
	unsigned int getID() const;
    
	/*!
	*	This is a method that gets the midfielder's performance information
	*/
	Info* getInfo() const;
    
	/*!
	*	This is a method that adds information to the midfielder
	*/
	void addInfo(Info* moreInfo);
    
};

#endif /* Midfielder_hpp */
