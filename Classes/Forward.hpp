#pragma once

#include "Athlete.hpp"

class Forward : public Athlete
{
private:
	unsigned int goalsScored;

public:
	Forward(string name, Date birthdate, unsigned char height, unsigned id = 0);
	~Forward();
	Position getPosition() const;
	unsigned int getID() const;

};
