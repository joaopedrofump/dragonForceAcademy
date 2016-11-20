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

#include "ECG.hpp"

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
    /*!
     This is the set Civil ID function that actualize the civil ID atribute
     */
    void setCivilId(unsigned int newCivilId);

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    /// <summary>	Updates the ecg. </summary>
    ///
    /// <remarks>	Luís, 20/11/2016. </remarks>
    ///
    /// <param name="resultado">	 	True to resultado. </param>
    /// <param name="expirationDate">	(Optional) The expiration date. </param>
    ////////////////////////////////////////////////////////////////////////////////////////////////////

    virtual void updateECG(bool resultado, Date expirationDate = Date(Date().getDay(), Date().getMonth(),Date().getYear()+1));

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    /// <summary>	Sets a name. </summary>
    ///
    /// <remarks>	Luís, 20/11/2016. </remarks>
    ///
    /// <param name="newName">	Name of the new. </param>
    ////////////////////////////////////////////////////////////////////////////////////////////////////

    void setName(string newName);

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    /// <summary>	Sets birth date. </summary>
    ///
    /// <remarks>	Luís, 20/11/2016. </remarks>
    ///
    /// <param name="newBirthdate">	The new birthdate. </param>
    ////////////////////////////////////////////////////////////////////////////////////////////////////

    virtual void setBirthDate(Date newBirthdate){};

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    /// <summary>	Sets a height. </summary>
    ///
    /// <remarks>	Luís, 20/11/2016. </remarks>
    ///
    /// <param name="newHeight">	Height of the new. </param>
    ////////////////////////////////////////////////////////////////////////////////////////////////////

    virtual void setHeight(unsigned int newHeight){};

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    /// <summary>	Sets coach type. </summary>
    ///
    /// <remarks>	Luís, 20/11/2016. </remarks>
    ///
    /// <param name="newType">	Type of the new. </param>
    ////////////////////////////////////////////////////////////////////////////////////////////////////

    virtual void setCoachType(CoachType newType) {};
	

    ~Worker();
	

	//====== GETTERS =============

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Gets the age. </summary>
	///
	/// <remarks>	Luís, 20/11/2016. </remarks>
	///
	/// <returns>	The age. </returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	unsigned int getAge() const;

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    /// <summary>	Gets the birthdate. </summary>
    ///
    /// <remarks>	Luís, 20/11/2016. </remarks>
    ///
    /// <returns>	The birthdate. </returns>
    ////////////////////////////////////////////////////////////////////////////////////////////////////

    Date getBirthdate() const;

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    /// <summary>	Gets the information. </summary>
    ///
    /// <remarks>	Luís, 20/11/2016. </remarks>
    ///
    /// <returns>	Null if it fails, else the information. </returns>
    ////////////////////////////////////////////////////////////////////////////////////////////////////

    virtual Info* getInfo() const { Info* res = new Info(); return res;};

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    /// <summary>	Adds an information. </summary>
    ///
    /// <remarks>	Luís, 20/11/2016. </remarks>
    ///
    /// <param name="moreInfo">	[in,out] If non-null, information describing the more. </param>
    ////////////////////////////////////////////////////////////////////////////////////////////////////

    virtual void addInfo(Info* moreInfo){};

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    /// <summary>	Stream insertion operator. </summary>
    ///
    /// <remarks>	Luís, 20/11/2016. </remarks>
    ///
    /// <param name="out">   	[in,out] The out. </param>
    /// <param name="worker">	The worker. </param>
    ///
    /// <returns>	The shifted result. </returns>
    ////////////////////////////////////////////////////////////////////////////////////////////////////

    friend ostream& operator<<(ostream& out, const Worker &worker);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Generates an information. </summary>
	///
	/// <remarks>	Luís, 20/11/2016. </remarks>
	///
	/// <returns>	The information. </returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////

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
	/*!
	This is an abstract method to get the athlete's ECG
	*/
	virtual ECG* getECG() const;


    
    unsigned int getCivilID() const;
    
    virtual vector<string> showInScreen() const;
    
    bool isActive() const;

	/*!
	This is a static method to get the last Id created
	*/
	static unsigned int getLastId();



};

#endif /* Worker_hpp */
