#pragma once

#include "Athlete.hpp"

class Forward : public Athlete
{
private:
    Info* generalInfo;

public:
	Forward(string name, Date birthdate, unsigned int civilID, unsigned char height, unsigned id = 0);
	Forward(string &newFW);
    ~Forward();
	unsigned int getID() const;
    Info* getInfo() const;
    void addInfo(Info* moreInfo);

};
