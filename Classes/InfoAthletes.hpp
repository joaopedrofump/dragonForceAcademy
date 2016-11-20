//
//  InfoAthletes.hpp
//  DragonForceAcademy
//
//  Created by Joao Furriel on 02/11/16.
//  Copyright © 2016 João Furriel Pinheiro. All rights reserved.
//

#ifndef InfoAthletes_hpp
#define InfoAthletes_hpp

#include "Utils.hpp"

/// <summary>	map including the different types of coaches. </summary>
extern const map<string, CoachType> coachTypeMap;

/// <summary>	map including the different positions of the athlete. </summary>
extern const map<string, Position> positionsMap;

/// <summary>	map including the different positions of the defender. </summary>
extern const map<string, DefenderPosition> defendersMap;

/// <summary>	map including the different positions of the midfielder. </summary>
extern const map<string, MidfielderPosition> midfieldersMap;

/// <summary>	map including the different positiions of the forward. </summary>
extern const map<string, ForwardPosition> forwardsMap;

class Info {
protected:
    /// <summary>	athlete's training frequency percentage. </summary>
    Fraction trainingFreq;
    /// <summary>	athlete's number of yellow cards. </summary>
    unsigned int yellowCards;
    /// <summary>	athlete's number of red cards. </summary>
    unsigned int redCards;
    /// <summary>	athlete's number of tackles. </summary>
    unsigned int tackles;
    /// <summary>	athlete's number of fouls commited. </summary>
    unsigned int fouls;
    /// <summary>	athlete's number of goals scored. </summary>
    unsigned int goalsScored;
    /// <summary>	athlete's number of assist made. </summary>
    unsigned int assists;
    /// <summary>	athlete's pass accuracy percentage. </summary>
    Fraction passAccuracy;
public:
    
	//! Info constructors

	/*!
	*	This is a constructor that creates new athlete's performance information using training frequency, number of yellow cards, number of red cards, number of tackles, number of fouls commited, number of goals scored, number of assists, pass accuracy
	*/

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Constructor. </summary>
	///
	/// <remarks>	Luís, 20/11/2016. </remarks>
	///
	/// <param name="trainingFreq">	The training frequency. </param>
	/// <param name="yellowCards"> 	The yellow cards. </param>
	/// <param name="redCards">	   	The red cards. </param>
	/// <param name="tackles">	   	The tackles. </param>
	/// <param name="fouls">	   	The fouls. </param>
	/// <param name="goalsScored"> 	The goals scored. </param>
	/// <param name="assists">	   	The assists. </param>
	/// <param name="passAccuracy">	The pass accuracy. </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	Info(Fraction trainingFreq, unsigned int yellowCards, unsigned int redCards, unsigned int tackles, unsigned int fouls, unsigned int goalsScored, unsigned int assists, Fraction passAccuracy);
	
	/*!
	*	This is a constructor that creates new athlete's performance information by reading it from athletes file using a string
	*/

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Constructor that creates new athlete's performance information by reading it from athletes file using a string. </summary>
	///
	/// <remarks>	Luís, 20/11/2016. </remarks>
	///
	/// <param name="newInfo">	[in,out] Information describing the new. </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	Info(string &newInfo);
	

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Default constructor. </summary>
	///
	/// <remarks>	Luís, 20/11/2016. </remarks>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	Info();
    
	/*!
	*	This is a constructor that creates new athlete's performance information by reading it from thae athletes file using a stringstream
	*/

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Constructor that creates new athlete's performance information by reading it from thae athletes file using a stringstream. </summary>
	///
	/// <remarks>	Luís, 20/11/2016. </remarks>
	///
	/// <param name="inStream">	[in,out] Data read from the athletes file. </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	Info(istream &inStream);
    
	/*!
	*	This is a method that gets the athlete's training frequency
	*/

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Gets the athlete's training attendance. </summary>
	///
	/// <remarks>	Luís, 20/11/2016. </remarks>
	///
	/// <returns>	The training attendance. </returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	Fraction getTrainingFreq() const;
    
	/*!
	*	This is a method that adds a new training training frequency and calculates the athlete's overall training attendance
	*/

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Adds a training and calculates the athlete's overall training attendance. </summary>
	///
	/// <remarks>	Luís, 20/11/2016. </remarks>
	///
	/// <param name="newTraining">	(Optional) The new training. </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	void addTraining(Fraction newTraining = Fraction(1,1));
    
	/*!
	*	This is a method that gets the athlete's number of yellow cards
	*/

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Gets the athlete's number of yellow cards. </summary>
	/// 
	///
	/// <remarks>	Luís, 20/11/2016. </remarks>
	///
	/// <returns>	The athlete's number of yellow cards. </returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	unsigned int getYellowCards() const;
    
	/*!
	*	This is a method that gets the athlete's number of red cards
	*/

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Gets the athlete's number of red cards. </summary>
	///
	/// <remarks>	Luís, 20/11/2016. </remarks>
	///
	/// <returns>	The athlete's number of red cards. </returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	unsigned int getRedCards() const;
    
	/*!
	*	This is a method that adds a yellow card to the athlete's total number of yellow cards
	*/

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Adds a yellow card to the athlete's total number of yellow cards. </summary>
	///
	/// <remarks>	Luís, 20/11/2016. </remarks>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	void addYellowCard();
    
	/*!
	*	This is a method that adds a red card to the athlete's total number of red cards
	*/

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Adds a red card to the athlete's total number of red cards. </summary>
	///
	/// <remarks>	Luís, 20/11/2016. </remarks>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	void addRedCard();
    
	/*!
	*	This is a method that gets the number of tackles made by the athlete
	*/

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Gets the number of tackles made by the athlete. </summary>
	///
	/// <remarks>	Luís, 20/11/2016. </remarks>
	///
	/// <returns>	The number of tackles made by the athlete. </returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	unsigned int getTackles() const;
    
	/*!
	*	This is a method that adds tackles to the total number of tackles made by the athlete
	*/

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Adds tackles to the total number of tackles made by the athlete. </summary>
	///
	/// <remarks>	Luís, 20/11/2016. </remarks>
	///
	/// <param name="tackles">	The tackles made by the player. </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	void addTackles(unsigned int tackles);
    
	/*!
	*	This is a method that gets the number of fouls commited by the athlete
	*/

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Gets the number of fouls commited by the athlete. </summary>
	///
	/// <remarks>	Luís, 20/11/2016. </remarks>
	///
	/// <returns>	The fouls commited by the athlete. </returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	unsigned int getFouls() const;
    
	/*!
	*	This is a method that adds fouls to the total number of fouls commited by the athlete
	*/
	
	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>   Adds fouls to the total number of fouls commited by the athlete. </summary>
	///
	/// <remarks>   Luís, 20/11/2016. </remarks>
	///
	/// <param name="tackles">  The fouls commited by the player. </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	void addFouls(unsigned int fouls);
    
	/*!
	*	This is a method that gets the number of goals scored by the athlete
	*/

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Gets the number of goals scored by the athlete. </summary>
	///
	/// <remarks>	Luís, 20/11/2016. </remarks>
	///
	/// <returns>	The number of goals scored by the athlete. </returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	unsigned int getGoalsScored() const;
    
	/*!
	*	This is a method that adds goals to the total number of goals scored by the athlete
	*/

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Adds goals to the total number of goals scored by the athlete. </summary>
	///
	/// <remarks>	Luís, 20/11/2016. </remarks>
	///
	/// <param name="goalsScored">	The goals scored by the athlete. </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	void addGoalsScored(unsigned int goalsScored);
    
	/*!
	*	This is a method that gets the number of assists made by the athlete
	*/

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Gets the number of assists made by the athlete. </summary>
	///
	/// <remarks>	Luís, 20/11/2016. </remarks>
	///
	/// <returns>	The assists made by the athlete. </returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	unsigned int getAssists() const;
    
	/*!
	*	This is a method that adds assists to the total number of assists made by the athlete
	*/

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Adds assists to the total number of assists made by the athlete. </summary>
	///
	/// <remarks>	Luís, 20/11/2016. </remarks>
	///
	/// <param name="assists">	The assists made by the athlete. </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	void addAssists(unsigned int assists);
    
	/*!
	*	This is a method that gets the athlete's passing accuracy
	*/

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Gets pass accuracy. </summary>
	///
	/// <remarks>	Luís, 20/11/2016. </remarks>
	///
	/// <returns>	The pass accuracy. </returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	Fraction getPassAccuracy() const;
    
	/*!
	*	This is a method that adds a new passing accuracy and calculates the athlete's overall passing accuracy
	*/

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Adds a new passing accuracy and calculates the athlete's overall passing accuracy. </summary>
	///
	/// <remarks>	Luís, 20/11/2016. </remarks>
	///
	/// <param name="passAccuracy">	The pass accuracy. </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	void addPassAccuracy(Fraction passAccuracy);
    
	/*!
	*	This is a virtual method that gets the number of saves made by the goalkeeper
	*/

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    /// <summary>	Gets the number of saves made by the goalkeeper. </summary>
    ///
    /// <remarks>	Luís, 20/11/2016. </remarks>
    ///
    /// <returns>	The number of saves made by the goalkeeper. </returns>
    ////////////////////////////////////////////////////////////////////////////////////////////////////

    virtual unsigned int getSaves() const {return 0;};
   
	/*!
	*	This is a virtual method that adds saves to the total number of saves made by the goalkeeper
	*/

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Adds saves to the total number of saves made by the goalkeeper. </summary>
	///
	/// <remarks>	Luís, 20/11/2016. </remarks>
	///
	/// <param name="saves">	The saves. </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	virtual void addSaves(unsigned int saves) {};
    
    /*!
	*	This is a virtual method that gets the number of goals conceeded by the goalkeeper
	*/

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Gets the number of goals conceeded by the goalkeeper. </summary>
	///
	/// <remarks>	Luís, 20/11/2016. </remarks>
	///
	/// <returns>	The goals conceeded. </returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	virtual unsigned int getGoalsConceeded() const {return 0;};
    
	/*!
	*	This is a virtual method that adds goals conceeded to total number of goals conceeded by the goalkeeper
	*/

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Adds goals conceeded to total number of goals conceeded by the goalkeeper. </summary>
	///
	/// <remarks>	Luís, 20/11/2016. </remarks>
	///
	/// <param name="goalsConceeded">	The goals conceeded. </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	virtual void addGoalsConceeded(unsigned int goalsConceeded){};
    
	
	/*!
	*	This is a virtual method that gets the vector containing the different positions of the defender
	*/

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    /// <summary>	Gets the vector containing the defender specific positions. </summary>
    ///
    /// <remarks>	Luís, 20/11/2016. </remarks>
    ///
    /// <returns>	The vector containing the defender specific positions. </returns>
    ////////////////////////////////////////////////////////////////////////////////////////////////////

    virtual vector<DefenderPosition> getDefenderSpecificPositions() const {vector<DefenderPosition> res; return res;}
    
	/*!
	*	This is a virtual method that adds a specific defender position to the vector containing the different positions of the defender
	*/

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Adds a defender specific position to the vector containing the different positions of the defender. </summary>
	///
	/// <remarks>	Luís, 20/11/2016. </remarks>
	///
	/// <param name="newPos">	The new position. </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	virtual void addDefenderSpecificPosition(DefenderPosition newPos){};
    
    
	/*!
	*	This is a virtual method that gets the vector containing the different positions of the midfielder
	*/

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Gets the vector containing the midfielder specific positions. </summary>
	///
	/// <remarks>	Luís, 20/11/2016. </remarks>
	///
	/// <returns>	The vector containing the midfielder specific positions. </returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	virtual vector<MidfielderPosition> getMidfielderSpecificPositions() const {vector<MidfielderPosition> res; return res;}
    
	/*!
	*	This is a virtual method that adds a specific midfielder position to the vector containing the different positions of the midfielder
	*/

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Adds a midfielder specific position to the vector containing the different positions of the midfielder. </summary>
	///
	/// <remarks>	Luís, 20/11/2016. </remarks>
	///
	/// <param name="newPos">	The new position. </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	virtual void addMidfielderSpecificPosition(MidfielderPosition newPos) {};
    
    
	/*!
	*	This is a virtual method that gets the vector containing the different position of the forward
	*/

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Gets the vector containing the forward specific positions. </summary>
	///
	/// <remarks>	Luís, 20/11/2016. </remarks>
	///
	/// <returns>	The forward specific positions. </returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	virtual vector<ForwardPosition> getForwardSpecificPositions() const {vector<ForwardPosition> res; return res;}
    
	/*!
	*	This is a virtual method that adds a specific forward position to the vector containing the different positions of the forward
	*/

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Adds an attacker specific position to the vector containing the different positions of the forward. </summary>
	///
	/// <remarks>	Luís, 20/11/2016. </remarks>
	///
	/// <param name="newPos">	The new position. </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	virtual void addAttackerSpecificPosition(ForwardPosition newPos){};
    
    /*!
	*	This is an stream extraction operator that writes in the athlete's file the string containing the athlete's performance information generated in the virtual method generateString(), using a stringstream
	*/

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Stream insertion operator that writes in the athlete's file the string containing the athlete's performance information generated in the virtual method generateString(), using a stringstream. </summary>
	///
	/// <remarks>	Luís, 20/11/2016. </remarks>
	///
	/// <param name="out"> 	[in,out] The atheletes file. </param>
	/// <param name="info">	The athlete's performance information. </param>
	///
	/// <returns>	The shifted result. </returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	friend ostream& operator<<(ostream& out, const Info &info);
   
	/*!
	*	This is a virtual method that generates a string containing the athlete's performance information
	*/

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Generates a string containing the athlete's performance information. </summary>
	///
	/// <remarks>	Luís, 20/11/2016. </remarks>
	///
	/// <returns>	The string containing the athlete's performance information. </returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	virtual string generateString() const;
    
	
	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Saves the athlete's performance information into the athlete's file using the overload of the operator<<, especified above. </summary>
	///
	/// <remarks>	Luís, 20/11/2016. </remarks>
	///
	/// <param name="out">	[in,out] The outfile to save. </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	virtual void save (ofstream& out);
    
	/*!
	*	This is a method that adds two different blocks of athlete's perfomance information, adding each atribute with the respective atribute of the other block
	*/

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Adds two different blocks of athlete's perfomance information, adding each atribute with the respective atribute of the other block. </summary>
	///
	/// <remarks>	Luís, 20/11/2016. </remarks>
	///
	/// <param name="info2">	The second block information. </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	void sumGeneralInfo(const Info &info2);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Addition assignment operator. </summary>
	///
	/// <remarks>	Luís, 20/11/2016. </remarks>
	///
	/// <param name="info2">	The second block information. </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	virtual void operator+=(const Info* info2){};
    
};

class InfoGK : public Info {
protected:
    /// <summary>	saves made by the goalkeeper atribute. </summary>
    unsigned int saves;
    /// <summary>	goals conceeded by the goalkeeper atribute. </summary>
    unsigned int goalsConceeded;
    
public:
    
	//! InfoGK's constructors 

	/*!
	*	This is a constructor that creates new goalkeeper's performance information using training frequency, number of yellow cards, number of red cards, number of tackles, number of fouls commited, number of goals scored, number of assists, pass accuracy
	*/

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Constructor. </summary>
	///
	/// <remarks>	Luís, 20/11/2016. </remarks>
	///
	/// <param name="trainingFreq">  	The training frequency. </param>
	/// <param name="yellowCards">   	The yellow cards. </param>
	/// <param name="redCards">		 	The red cards. </param>
	/// <param name="tackles">		 	The tackles. </param>
	/// <param name="fouls">		 	The fouls. </param>
	/// <param name="goalsScored">   	The goals scored. </param>
	/// <param name="assists">		 	The assists. </param>
	/// <param name="passAccuracy">  	The pass accuracy. </param>
	/// <param name="saves">		 	The saves. </param>
	/// <param name="goalsConceeded">	The goals conceeded. </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	InfoGK(Fraction trainingFreq, unsigned int yellowCards, unsigned int redCards, unsigned int tackles, unsigned int fouls, unsigned int goalsScored, unsigned int assists, Fraction passAccuracy, unsigned int saves, unsigned int goalsConceeded);
	
	/*!
	*	This is a constructor that creates new goalkeeper's performance information by reading it from athletes file using a string
	*/

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Constructor that creates new goalkeeper's performance information by reading it from athletes file using a string. </summary>
	///
	/// <remarks>	Luís, 20/11/2016. </remarks>
	///
	/// <param name="newInfo">	[in,out] Information describing the new. </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	InfoGK(string &newInfo);
    

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Default constructor. </summary>
	///
	/// <remarks>	Luís, 20/11/2016. </remarks>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	InfoGK();
    

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Constructor that creates new goalkeeper's performance information by reading it from thae athletes file using a stringstream. </summary>
	///
	/// <remarks>	Luís, 20/11/2016. </remarks>
	///
	/// <param name="inStream">	[in,out] Stream to read data from. </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	InfoGK(istream &inStream);
    
	/*!
	*	This is a method that adds saves to the total number of saves made by the goalkeeper
	*/

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Gets the number of saves made by the goalkeeper. </summary>
	///
	/// <remarks>	Luís, 20/11/2016. </remarks>
	///
	/// <returns>	The saves. </returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	unsigned int getSaves() const;
   
	/*!
	*	This is a method that adds saves to the total number of saves made by the goalkeeper
	*/

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Adds the saves to the total number of saves made by the goalkeeper. </summary>
	///
	/// <remarks>	Luís, 20/11/2016. </remarks>
	///
	/// <param name="saves">	The saves. </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	void addSaves(unsigned int saves);
    
	/*!
	*	This is a method that gets the number of goals conceeded by the goalkeeper
	*/

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Gets the number of goals conceeded by the goalkeeper. </summary>
	///
	/// <remarks>	Luís, 20/11/2016. </remarks>
	///
	/// <returns>	The goals conceeded. </returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	unsigned int  getGoalsConceeded() const;
    
	/*!
	*	This is a virtual method that adds goals conceeded to total number of goals conceeded by the goalkeeper
	*/

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Adds goals conceeded to total number of goals conceeded by the goalkeeper. </summary>
	///
	/// <remarks>	Luís, 20/11/2016. </remarks>
	///
	/// <param name="goalsConceeded">	The goals conceeded. </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	void addGoalsConceeded(unsigned int goalsConceeded);
    
	/*!
	*	This is a method that generates a string containing the goalkeeper's performance information
	*/

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Generates a string containing the goalkeeper's performance information. </summary>
	///
	/// <remarks>	Luís, 20/11/2016. </remarks>
	///
	/// <returns>	The string containing the goalkeeper's performance information. </returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	string generateString() const;
    
	/*!
		This is an assignment operator that adds two different blocks of goalkeeper's performance information
	*/

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Addition assignment operator that adds two different blocks of goalkeeper's performance information. </summary>
	///
	/// <remarks>	Luís, 20/11/2016. </remarks>
	///
	/// <param name="info2">	The second block of information. </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	void operator+=(const Info* info2);
    
};

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Defender's performance information. </summary>
///
/// <remarks>	Luís, 20/11/2016. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

class InfoDF : public Info {
protected:
    /// <summary>	vector containing the different defender positions. </summary>
    vector<DefenderPosition> positions;
public:
    
	//! InfoDF's constructors

	/*!
	*	This is a constructor that creates new defender's performance information using training frequency, number of yellow cards, number of red cards, number of tackles, number of fouls commited, number of goals scored, number of assists, pass accuracy
	*/

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Constructor. </summary>
	///
	/// <remarks>	Luís, 20/11/2016. </remarks>
	///
	/// <param name="trainingFreq">	The training frequency. </param>
	/// <param name="yellowCards"> 	The yellow cards. </param>
	/// <param name="redCards">	   	The red cards. </param>
	/// <param name="tackles">	   	The tackles. </param>
	/// <param name="fouls">	   	The fouls. </param>
	/// <param name="goalsScored"> 	The goals scored. </param>
	/// <param name="assists">	   	The assists. </param>
	/// <param name="passAccuracy">	The pass accuracy. </param>
	/// <param name="positions">   	The positions. </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	InfoDF(Fraction trainingFreq, unsigned int yellowCards, unsigned int redCards, unsigned int tackles, unsigned int fouls, unsigned int goalsScored, unsigned int assists, Fraction passAccuracy, vector<DefenderPosition> positions);
	
	/*!
	*	This is a constructor that creates new defender's performance information by reading it from athletes file using a string
	*/

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Constructor that creates new defender's performance information by reading it from athletes file using a string. </summary>
	///
	/// <remarks>	Luís, 20/11/2016. </remarks>
	///
	/// <param name="newInfo">	[in,out] Information describing the new. </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	InfoDF(string &newInfo);
    
	/*!
	*	This is the InfoDF's class empty constructor
	*/

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Default constructor. </summary>
	///
	/// <remarks>	Luís, 20/11/2016. </remarks>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	InfoDF();
    
	/*!
	*	This is a constructor that creates new defender's performance information by reading it from thae athletes file using a stringstream
	*/

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Constructor that creates new defender's performance information by reading it from thae athletes file using a stringstream. </summary>
	///
	/// <remarks>	Luís, 20/11/2016. </remarks>
	///
	/// <param name="inStream">	[in,out] Stream to read data from. </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	InfoDF(istream &inStream);
    
	/*!
	*	This is a method that gets the vector containing the different positions of the defender
	*/

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Gets the vector containing defender specific positions. </summary>
	///
	/// <remarks>	Luís, 20/11/2016. </remarks>
	///
	/// <returns>	The the vector containing defender specific positions. </returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	vector<DefenderPosition> getDefenderSpecificPositions() const;
   
	/*!
	*	This is a method that adds a specific defender position to the vector containing the different positions of the defender
	*/

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Adds a defender specific position to the vector containing the different positions of the defender. </summary>
	///
	/// <remarks>	Luís, 20/11/2016. </remarks>
	///
	/// <param name="newPos">	The new position. </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	void addDefenderSpecificPosition(DefenderPosition newPos);
    
	/*!
	*	This is a method that generates a string containing the defender's performance information
	*/

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Generates a string containing the defender's performance information. </summary>
	///
	/// <remarks>	Luís, 20/11/2016. </remarks>
	///
	/// <returns>	The string containing the defender's performance information. </returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	string generateString() const;
    
	/*!
	*	This is an assignment operator that adds two different blocks of defender's performance information
	*/

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Addition assignment operator that adds two different blocks of defender's performance information. </summary>
	///
	/// <remarks>	Luís, 20/11/2016. </remarks>
	///
	/// <param name="info2">	The second block information. </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	void operator+=(const Info* info2);
};

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	A Midfielder's performance information. </summary>
///
/// <remarks>	Luís, 20/11/2016. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

class InfoMF : public Info {
protected:
    /// <summary>	vector containing the different midfielder positions. </summary>
    vector<MidfielderPosition> positions;
public:
    
	//! InfoMF's constructors

	/*!
	*	This is a constructor that creates new midfielder's performance information using training frequency, number of yellow cards, number of red cards, number of tackles, number of fouls commited, number of goals scored, number of assists, pass accuracy
	*/

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Constructor. </summary>
	///
	/// <remarks>	Luís, 20/11/2016. </remarks>
	///
	/// <param name="trainingFreq">	The training frequency. </param>
	/// <param name="yellowCards"> 	The yellow cards. </param>
	/// <param name="redCards">	   	The red cards. </param>
	/// <param name="tackles">	   	The tackles. </param>
	/// <param name="fouls">	   	The fouls. </param>
	/// <param name="goalsScored"> 	The goals scored. </param>
	/// <param name="assists">	   	The assists. </param>
	/// <param name="passAccuracy">	The pass accuracy. </param>
	/// <param name="positions">   	The positions. </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	InfoMF(Fraction trainingFreq, unsigned int yellowCards, unsigned int redCards, unsigned int tackles, unsigned int fouls, unsigned int goalsScored, unsigned int assists, Fraction passAccuracy, vector<MidfielderPosition> positions);
	
	/*!
	*	This is a constructor that creates new midfielder's performance information by reading it from athletes file using a string
	*/

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Constructor that creates new midfielder's performance information by reading it from athletes file using a string
	///	* / . </summary>
	///
	/// <remarks>	Luís, 20/11/2016. </remarks>
	///
	/// <param name="newInfo">	[in,out] Information describing the new. </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	InfoMF(string &newInfo);
    
	/*!
	*	This is the InfoMF's class empty constructor
	*/

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Default constructor. </summary>
	///
	/// <remarks>	Luís, 20/11/2016. </remarks>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	InfoMF();
    
	/*!
	*	This is a constructor that creates new midfielder's performance information by reading it from thae athletes file using a stringstream
	*/

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Constructor that creates new midfielder's performance information by reading it from thae athletes file using a stringstream. </summary>
	///
	/// <remarks>	Luís, 20/11/2016. </remarks>
	///
	/// <param name="inStream">	[in,out] Stream to read data from. </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	InfoMF(istream &inStream);

	/*!
	*	This is a method that gets the vector containing the different positions of the midfielder
	*/

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    /// <summary>	Gets the vector containing midfielder specific positions. </summary>
    ///
    /// <remarks>	Luís, 20/11/2016. </remarks>
    ///
    /// <returns>	The midfielder specific positions. </returns>
    ////////////////////////////////////////////////////////////////////////////////////////////////////

    vector<MidfielderPosition> getMidfielderSpecificPositions() const;
    
	/*!
	*	This is a method that adds a specific midfielder position to the vector containing the different positions of the midfielder
	*/

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Adds a midfielder specific position to the vector containing the different positions of the midfielder. </summary>
	///
	/// <remarks>	Luís, 20/11/2016. </remarks>
	///
	/// <param name="newPos">	The new position. </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	void addMidfielderSpecificPosition(MidfielderPosition newPos);
    
	/*!
	*	This is a method that generates a string containing the midfielder's performance information
	*/

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Generates a string containing the midfielder's performance information. </summary>
	///
	/// <remarks>	Luís, 20/11/2016. </remarks>
	///
	/// <returns>	The string. </returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	string generateString() const;
    
	/*!
	*	This is an assignment operator that adds two different blocks of midfielder's performance information
	*/

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Addition assignment operator that adds two different blocks of midfielder's performance information. </summary>
	///
	/// <remarks>	Luís, 20/11/2016. </remarks>
	///
	/// <param name="info2">	The second block information. </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	void operator+=(const Info* info2);
};

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	 Forward's performance information. </summary>
///
/// <remarks>	Luís, 20/11/2016. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

class InfoFW : public Info {
protected:

    /// <summary>	vector containing the different midfielder positions. </summary>
    vector<ForwardPosition> positions;
public:
    

	//! InfoFW's constructors

	/*!
	*	This is a constructor that creates new forward's performance information using training frequency, number of yellow cards, number of red cards, number of tackles, number of fouls commited, number of goals scored, number of assists, pass accuracy
	*/

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Constructor. </summary>
	///
	/// <remarks>	Luís, 20/11/2016. </remarks>
	///
	/// <param name="trainingFreq">	The training frequency. </param>
	/// <param name="yellowCards"> 	The yellow cards. </param>
	/// <param name="redCards">	   	The red cards. </param>
	/// <param name="tackles">	   	The tackles. </param>
	/// <param name="fouls">	   	The fouls. </param>
	/// <param name="goalsScored"> 	The goals scored. </param>
	/// <param name="assists">	   	The assists. </param>
	/// <param name="passAccuracy">	The pass accuracy. </param>
	/// <param name="positions">   	The positions. </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	InfoFW(Fraction trainingFreq, unsigned int yellowCards, unsigned int redCards, unsigned int tackles, unsigned int fouls, unsigned int goalsScored, unsigned int assists, Fraction passAccuracy, vector<ForwardPosition> positions);
	
	/*!
	*	This is a constructor that creates new forward's performance information by reading it from athletes file using a string
	*/

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Constructor that creates new forward's performance information by reading it from athletes file using a string. </summary>
	/// 
	/// <remarks>	Luís, 20/11/2016. </remarks>
	///
	/// <param name="newInfo">	[in,out] Information describing the new. </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	InfoFW(string &newInfo);
    
	/*!
	*	This is the InfoFW's class empty constructor
	*/

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Default constructor. </summary>
	///
	/// <remarks>	Luís, 20/11/2016. </remarks>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	InfoFW();
    
	/*!
	*	This is a constructor that creates new forward's performance information by reading it from thae athletes file using a stringstream
	*/

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Constructor that creates new forward's performance information by reading it from thae athletes file using a stringstream. </summary>
	///
	/// <remarks>	Luís, 20/11/2016. </remarks>
	///
	/// <param name="inStream">	[in,out] Stream to read data from. </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	InfoFW(istream &inStream);
    
	/*!
	*	This is a method that gets the vector containing the different positions of the forward
	*/

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Gets the vector containing forward specific positions. </summary>
	///
	/// <remarks>	Luís, 20/11/2016. </remarks>
	///
	/// <returns>	The vector containing forward specific positions. </returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	vector<ForwardPosition> getForwardSpecificPositions() const;
    
	/*!
	*	This is a method that adds a specific forward position to the vector containing the different positions of the forward
	*/

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Adds an attacker specific position to the vector containing the different positions of the forward. </summary>
	///
	/// <remarks>	Luís, 20/11/2016. </remarks>
	///
	/// <param name="newPos">	The new position. </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	void addAttackerSpecificPosition(ForwardPosition newPos);
    
	/*!
	*	This is a method that generates a string containing the forward's performance information
	*/

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Generates a string containing the forward's performance information. </summary>
	///
	/// <remarks>	Luís, 20/11/2016. </remarks>
	///
	/// <returns>	The string containing the forward's performance information. </returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	string generateString() const;
    
	/*!
	*	This is an assignment operator that adds two different blocks of forward's performance information
	*/

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Addition assignment operator that adds two different blocks of forward's performance information. </summary>
	///
	/// <remarks>	Luís, 20/11/2016. </remarks>
	///
	/// <param name="info2">	The second block information. </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	void operator+=(const Info* info2);
};

#endif /* InfoAthletes_hpp */
