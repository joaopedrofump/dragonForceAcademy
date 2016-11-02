#pragma once

#include "Athlete.hpp"

class Forward : public Athlete
{
private:
    Info* generalInfo;

public:
	Forward(string name, Date birthdate, unsigned char height, unsigned id = 0);
    ~Forward();
	Position getPosition() const;
	unsigned int getID() const;
    Info* getInfo() const;
    void addInfo(Info* moreInfo);

};
