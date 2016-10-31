//
//  Worker.hpp
//  DragonForceAcadamy
//
//  Created by Joao Furriel on 13/10/16.
//  Copyright © 2016 João Furriel Pinheiro. All rights reserved.
//
#pragma once

#ifndef Worker_hpp
#define Worker_hpp

#include "Utils.hpp"

using namespace std;

//! Worker Class
/*!
    Represents a club worker, can be either a player or a coach
*/


class Worker {
protected:
    /*!
     Worker name
     */
    string name;
    /*!
     Worker birthdate used to calculate age
     */
    Date birthdate;
    /*!
     Worker unique id for each club worker
     */
    unsigned int id;
	/*!
	Worker current status 
	*/
	bool status;
    /*!
     Worker counter to keep track and generate the ids
     */
    static unsigned int workersCounter;


public:
    //! Worker constructor.
    /*!
     \param name the name of the worker.
     \param birthdate the worker birthdate.
     */
    Worker(string name, Date birthdate, unsigned int id = 0);
    //! Worker constructor.
    /*!
     This is an abstract method to make this class abstract
     */
    virtual unsigned int getID() const = 0;
	/*!
	This is an abstract method to check if the object is an Athlete
	*/
	virtual bool isAthlete() const = 0;
	/*!
	This is the == operator that returns true if the  id's are equal
	*/
	bool operator==(Worker* worker) const;
	/*!
	This is the set status function that actualize the status atribute
	*/
	void setStatus(bool newStatus);

    ~Worker();
	unsigned int getIdade() const;


};

#endif /* Worker_hpp */
