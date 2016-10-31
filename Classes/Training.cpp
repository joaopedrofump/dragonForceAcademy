#include "Training.hpp"

 unsigned int Training::trainingCounter = 0;

Training::Training(unsigned int id, Date trainingDate)
{
	if (id == 0) {
		this->id = ++trainingCounter;
	}
	else {
		this->id = id;
	}

	this->trainingDate = trainingDate;
}

Date Training::getTrainingDate() const
{
	return trainingDate;
}

unsigned int Training::getId() const
{
	return id;
}