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

#include "InfoAthletes.hpp"

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
    /*!
     Worker Civil ID
     */
    unsigned int civilID;


public:
    //! Worker constructor.
    /*!
     \param name the name of the worker.
     \param birthdate the worker birthdate.
     */
    Worker(string name, Date birthdate, unsigned int civilID, unsigned int id = 0);
	//! Worker empty constructor.
	Worker();
    //! Abstract method - get the worker id.
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
	/*!
	This is the set ID function that actualize the ID atribute
	*/
	void setId(unsigned int newId);

	

    ~Worker();

	//====== GETTERS =============
	unsigned int getIdade() const;
    
    Date getBirthdate() const;
    
    virtual Info* getInfo() const { Info* res = new Info(); return res;};
    virtual void addInfo(Info* moreInfo){};
    
    friend ostream& operator<<(ostream& out, const Worker &worker);
	virtual string generateInfo() const { return ""; };

	string getName() const;
	/*!
	This is an abstract method to get the athlete or coach position
	*/
	virtual unsigned int getPosition() const = 0;
	/*!
	This is an abstract method to get the athlete height
	*/
	virtual unsigned int getHeight() const = 0;
    
    unsigned int getCivilID() const;
    
    virtual vector<string> showInScreen() const;
    
    bool isActive() const;


};

#endif /* Worker_hpp */
