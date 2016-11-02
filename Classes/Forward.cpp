#include "Forward.hpp"

Forward::Forward(string name, Date birthdate, unsigned char height, unsigned int id) : Athlete(name, birthdate, height, ForwardPos, id)
{
    if (id != 0) {
        this->id = id;
    }
}

Forward::~Forward()
{
	cout << "Forward destroyed\n" << endl;
}

Position Forward::getPosition() const
{
	return ForwardPos;
}

unsigned int Forward::getID() const
{
	return this->id;
}
