#pragma once

#include "Classes\Utils.hpp"

class Training
{
private:
	Date trainingDate;
	static unsigned int trainingCounter;
	unsigned int id;

public:
	Training(unsigned int id, Date trainingDate);
	Date getTrainingDate() const;
	unsigned int getId() const;
	

};
