#pragma once


#include "Athlete.hpp"

class Forward : public Athlete
{
private:
    Info* generalInfo; //forward's general information

public:
	
	//! Forward's constructors

	/*!
	*	This is a constructor that creates a new forward using his name, birthdate, civilID and height. The id is set automatically
	*/
	Forward(string name, Date birthdate, unsigned int civilID, unsigned char height, unsigned id = 0);
	
	/*!
	*	This a constructor that creates a new forward using a subposition passed by reference
	*/
	Forward(string &newFW);
    
	//! Forward's destructor
	~Forward();
	
	/*!
	*	This is a method that gets the forward's id
	*/
	unsigned int getID() const;
    
	/*!
	*	This is a method that gets the forward's performance information
	*/
	Info* getInfo() const;
    
	/*!
	*	This is a method that adds information to the forward
	*/
	void addInfo(Info* moreInfo);


};
