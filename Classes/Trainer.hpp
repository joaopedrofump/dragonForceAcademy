#pragma once

#include <stdio.h>
#include <iostream>
#include "Worker.hpp"

class Trainer : public Worker {

private:
	unsigned char height;

public:
	Trainer(string name, Date birthdate, unsigned char height);
	virtual Position getPosition() const = 0;
};
