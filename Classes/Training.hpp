#pragma once

#include "InfoAthletes.hpp"


class Training
{
private:
	Date trainingDate; //training's date
	static unsigned int trainingCounter; //number of trainings performed
	unsigned int id; //training's id

public:
	//! Training's constructor
	/*!
	* This is a constructor that creates a new training using the training's date and training's id
	*/
	Training(unsigned int id, Date trainingDate);
	
	/*!
	*	This is a method that gets the training's date
	*/
	Date getTrainingDate() const;
	
	/*!
	*	This is a method that the training's id
	*/
	unsigned int getId() const;
	

};
