//
//  Worker.hpp
//  DragonForceAcadamy
//
//  Created by Joao Furriel on 13/10/16.
//  Copyright © 2016 João Furriel Pinheiro. All rights reserved.
//

#ifndef Worker_hpp
#define Worker_hpp

#include <stdio.h>
#include <iostream>
#include "Utils.hpp"

using namespace std;

//! Worker Class
/*!
    Represents a club worker, can be either a player or a coach
*/


class Worker {
private:
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
     Worker counter to keep track and generate the ids
     */
    static unsigned int workersCounter;
public:
    //! Worker constructor.
    /*!
     \param name the name of the worker.
     \param birthdate the worker birthdate.
     */
    Worker(string name, Date birthdate);
    //! Worker constructor.
    /*!
     \param id the id to set. This is an abstract method to make this class abstract
     */
    virtual bool setID(unsigned int id) = 0;
};

#endif /* Worker_hpp */
