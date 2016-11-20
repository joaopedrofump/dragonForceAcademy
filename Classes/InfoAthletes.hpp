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

extern const map<string, CoachType> coachTypeMap; //map including the different types of coaches

extern const map<string, Position> positionsMap; //map including the different positions of the athlete

extern const map<string, DefenderPosition> defendersMap; //map including the different positions of the defender		

extern const map<string, MidfielderPosition> midfieldersMap; //map including the different positions of the midfielder

extern const map<string, ForwardPosition> forwardsMap; //map including the different positiions of the forward

class Info {
protected:
    Fraction trainingFreq; //athlete's training frequency percentage
    unsigned int yellowCards; //athlete's number of yellow cards
    unsigned int redCards; //athlete's number of red cards
    unsigned int tackles; //athlete's number of tackles
    unsigned int fouls; //athlete's number of fouls commited
    unsigned int goalsScored; //athlete's number of goals scored 
    unsigned int assists; //athlete's number of assist made
    Fraction passAccuracy; //athlete's pass accuracy percentage
public:
    
	//! Info constructors

	/*!
	*	This is a constructor that creates new athlete's performance information using training frequency, number of yellow cards, number of red cards, number of tackles, number of fouls commited, number of goals scored, number of assists, pass accuracy
	*/
	Info(Fraction trainingFreq, unsigned int yellowCards, unsigned int redCards, unsigned int tackles, unsigned int fouls, unsigned int goalsScored, unsigned int assists, Fraction passAccuracy);
	
	/*!
	*	This is a constructor that creates new athlete's performance information by reading it from athletes file using a string
	*/
	Info(string &newInfo);
	
	/*!
	*	This is the Info's class empty constructor
	*/
	Info();
    
	/*!
	*	This is a constructor that creates new athlete's performance information by reading it from thae athletes file using a stringstream
	*/
	Info(istream &inStream);
    
	/*!
	*	This is a method that gets the athlete's training frequency
	*/
	Fraction getTrainingFreq() const;
    
	/*!
	*	This is a method that adds a new training training frequency and calculates the athlete's overall training attendance
	*/
	void addTraining(Fraction newTraining);
    
	/*!
	*	This is a method that gets the athlete's number of yellow cards
	*/
	unsigned int getYellowCards() const;
    
	/*!
	*	This is a method that gets the athlete's number of red cards
	*/
	unsigned int getRedCards() const;
    
	/*!
	*	This is a method that adds a yellow card to the athlete's total number of yellow cards
	*/
	void addYellowCard();
    
	/*!
	*	This is a method that adds a red card to the athlete's total number of red cards
	*/
	void addRedCard();
    
	/*!
	*	This is a method that gets the number of tackles made by the athlete
	*/
	unsigned int getTackles() const;
    
	/*!
	*	This is a method that adds tackles to the total number of tackles made by the athlete
	*/
	void addTackles(unsigned int tackles);
    
	/*!
	*	This is a method that gets the number of fouls commited by the athlete
	*/
	unsigned int getFouls() const;
    
	/*!
	*	This is a method that adds fouls to the total number of fouls commited by the athlete
	*/
	void addFouls(unsigned int fouls);
    
	/*!
	*	This is a method that gets the number of goals scored by the athlete
	*/
	unsigned int getGoalsScored() const;
    
	/*!
	*	This is a method that adds goals to the total number of goals scored by the athlete
	*/
	void addGoalsScored(unsigned int goalsScored);
    
	/*!
	*	This is a method that gets the number of assists made by the athlete
	*/
	unsigned int getAssists() const;
    
	/*!
	*	This is a method that adds assists to the total number of assists made by the athlete
	*/
	void addAssists(unsigned int assists);
    
	/*!
	*	This is a method that gets the athlete's passing accuracy
	*/
	Fraction getPassAccuracy() const;
    
	/*!
	*	This is a method that adds a new passing accuracy and calculates the athlete's overall passing accuracy
	*/
	void addPassAccuracy(Fraction passAccuracy);
    
	/*!
	*	This is a virtual method that gets the number of saves made by the goalkeeper
	*/
    virtual unsigned int getSaves() const {return 0;};
   
	/*!
	*	This is a virtual method that adds saves to the total number of saves made by the goalkeeper
	*/
	virtual void addSaves(unsigned int saves) {};
    
    /*!
	*	This is a virtual method that gets the number of goals conceeded by the goalkeeper
	*/
	virtual unsigned int getGoalsConceeded() const {return 0;};
    
	/*!
	*	This is a virtual method that adds goals conceeded to total number of goals conceeded by the goalkeeper
	*/
	virtual void addGoalsConceeded(unsigned int goalsConceeded){};
    
	
	/*!
	*	This is a virtual method that gets the vector containing the different positions of the defender
	*/
    virtual vector<DefenderPosition> getDefenderSpecificPositions() const {vector<DefenderPosition> res; return res;}
    
	/*!
	*	This is a virtual method that adds a specific defender position to the vector containing the different positions of the defender
	*/
	virtual void addDefenderSpecificPosition(DefenderPosition newPos){};
    
    
	/*!
	*	This is a virtual method that gets the vector containing the different positions of the midfielder
	*/
	virtual vector<MidfielderPosition> getMidfielderSpecificPositions() const {vector<MidfielderPosition> res; return res;}
    
	/*!
	*	This is a virtual method that adds a specific midfielder position to the vector containing the different positions of the midfielder
	*/
	virtual void addMidfielderSpecificPosition(MidfielderPosition newPos) {};
    
    
	/*!
	*	This is a virtual method that gets the vector containing the different position of the forward
	*/
	virtual vector<ForwardPosition> getForwardSpecificPositions() const {vector<ForwardPosition> res; return res;}
    
	/*!
	*	This is a virtual method that adds a specific forward position to the vector containing the different positions of the forward
	*/
	virtual void addAttackerSpecificPosition(ForwardPosition newPos){};
    
    /*!
	*	This is an stream extraction operator that writes in the athlete's file the string containing the athlete's performance information generated in the virtual method generateString(), using a stringstream
	*/
	friend ostream& operator<<(ostream& out, const Info &info);
   
	/*!
	*	This is a virtual method that generates a string containing the athlete's performance information
	*/
	virtual string generateString() const;
    
	/*!
	*	This is a virtual method that saves the athlete's performance information into the athlete's file using the overload of the operator<<, especified above
	*/
	virtual void save (ofstream& out);
    
	/*!
	*	This is a method that adds two different blocks of athlete's perfomance information, adding each atribute with the respective atribute of the other block
	*/
	void sumGeneralInfo(const Info &info2);
    
	virtual void operator+=(const Info* info2){};
    
};

class InfoGK : public Info {
protected:
    unsigned int saves; //! saves made by the goalkeeper atribute
    unsigned int goalsConceeded; //! goals conceeded by the goalkeeper atribute
    
public:
    
	//! InfoGK's constructors 

	/*!
	*	This is a constructor that creates new goalkeeper's performance information using training frequency, number of yellow cards, number of red cards, number of tackles, number of fouls commited, number of goals scored, number of assists, pass accuracy
	*/
	InfoGK(Fraction trainingFreq, unsigned int yellowCards, unsigned int redCards, unsigned int tackles, unsigned int fouls, unsigned int goalsScored, unsigned int assists, Fraction passAccuracy, unsigned int saves, unsigned int goalsConceeded);
	
	/*!
	*	This is a constructor that creates new goalkeeper's performance information by reading it from athletes file using a string
	*/
	InfoGK(string &newInfo);
    
	/*!
	*	This is the InfoGK's class empty constructor
	*/
	InfoGK();
    
	/*!
	*	This is a constructor that creates new goalkeeper's performance information by reading it from thae athletes file using a stringstream
	*/
	InfoGK(istream &inStream);
    
	/*!
	*	This is a method that adds saves to the total number of saves made by the goalkeeper
	*/
	unsigned int getSaves() const;
   
	/*!
	*	This is a method that adds saves to the total number of saves made by the goalkeeper
	*/
	void addSaves(unsigned int saves);
    
	/*!
	*	This is a method that gets the number of goals conceeded by the goalkeeper
	*/
	unsigned int  getGoalsConceeded() const;
    
	/*!
	*	This is a virtual method that adds goals conceeded to total number of goals conceeded by the goalkeeper
	*/
	void addGoalsConceeded(unsigned int goalsConceeded);
    
	/*!
	*	This is a method that generates a string containing the goalkeeper's performance information
	*/
	string generateString() const;
    
	/*!
		This is an assignment operator that adds two different blocks of goalkeeper's performance information
	*/
	void operator+=(const Info* info2);
    
};

class InfoDF : public Info {
protected:
    vector<DefenderPosition> positions; //! vector containing the different defender positions
public:
    
	//! InfoDF's constructors

	/*!
	*	This is a constructor that creates new defender's performance information using training frequency, number of yellow cards, number of red cards, number of tackles, number of fouls commited, number of goals scored, number of assists, pass accuracy
	*/
	InfoDF(Fraction trainingFreq, unsigned int yellowCards, unsigned int redCards, unsigned int tackles, unsigned int fouls, unsigned int goalsScored, unsigned int assists, Fraction passAccuracy, vector<DefenderPosition> positions);
	
	/*!
	*	This is a constructor that creates new defender's performance information by reading it from athletes file using a string
	*/
	InfoDF(string &newInfo);
    
	/*!
	*	This is the InfoDF's class empty constructor
	*/
	InfoDF();
    
	/*!
	*	This is a constructor that creates new defender's performance information by reading it from thae athletes file using a stringstream
	*/
	InfoDF(istream &inStream);
    
	/*!
	*	This is a method that gets the vector containing the different positions of the defender
	*/
	vector<DefenderPosition> getDefenderSpecificPositions() const;
   
	/*!
	*	This is a method that adds a specific defender position to the vector containing the different positions of the defender
	*/
	void addDefenderSpecificPosition(DefenderPosition newPos);
    
	/*!
	*	This is a method that generates a string containing the defender's performance information
	*/
	string generateString() const;
    
	/*!
	*	This is an assignment operator that adds two different blocks of defender's performance information
	*/
	void operator+=(const Info* info2);
};

class InfoMF : public Info {
protected:
    vector<MidfielderPosition> positions; //! vector containing the different midfielder positions
public:
    
	//! InfoMF's constructors

	/*!
	*	This is a constructor that creates new midfielder's performance information using training frequency, number of yellow cards, number of red cards, number of tackles, number of fouls commited, number of goals scored, number of assists, pass accuracy
	*/
	InfoMF(Fraction trainingFreq, unsigned int yellowCards, unsigned int redCards, unsigned int tackles, unsigned int fouls, unsigned int goalsScored, unsigned int assists, Fraction passAccuracy, vector<MidfielderPosition> positions);
	
	/*!
	*	This is a constructor that creates new midfielder's performance information by reading it from athletes file using a string
	*/
	InfoMF(string &newInfo);
    
	/*!
	*	This is the InfoMF's class empty constructor
	*/
	InfoMF();
    
	/*!
	*	This is a constructor that creates new midfielder's performance information by reading it from thae athletes file using a stringstream
	*/
	InfoMF(istream &inStream);

	/*!
	*	This is a method that gets the vector containing the different positions of the midfielder
	*/
    vector<MidfielderPosition> getMidfielderSpecificPositions() const;
    
	/*!
	*	This is a method that adds a specific midfielder position to the vector containing the different positions of the midfielder
	*/
	void addMidfielderSpecificPosition(MidfielderPosition newPos);
    
	/*!
	*	This is a method that generates a string containing the midfielder's performance information
	*/
	string generateString() const;
    
	/*!
	*	This is an assignment operator that adds two different blocks of midfielder's performance information
	*/
	void operator+=(const Info* info2);
};

class InfoFW : public Info {
protected:

    vector<ForwardPosition> positions; //! vector containing the different midfielder positions
public:
    

	//! InfoFW's constructors

	/*!
	*	This is a constructor that creates new forward's performance information using training frequency, number of yellow cards, number of red cards, number of tackles, number of fouls commited, number of goals scored, number of assists, pass accuracy
	*/
	InfoFW(Fraction trainingFreq, unsigned int yellowCards, unsigned int redCards, unsigned int tackles, unsigned int fouls, unsigned int goalsScored, unsigned int assists, Fraction passAccuracy, vector<ForwardPosition> positions);
	
	/*!
	*	This is a constructor that creates new forward's performance information by reading it from athletes file using a string
	*/
	InfoFW(string &newInfo);
    
	/*!
	*	This is the InfoFW's class empty constructor
	*/
	InfoFW();
    
	/*!
	*	This is a constructor that creates new forward's performance information by reading it from thae athletes file using a stringstream
	*/
	InfoFW(istream &inStream);
    
	/*!
	*	This is a method that gets the vector containing the different positions of the forward
	*/
	vector<ForwardPosition> getForwardSpecificPositions() const;
    
	/*!
	*	This is a method that adds a specific forward position to the vector containing the different positions of the forward
	*/
	void addAttackerSpecificPosition(ForwardPosition newPos);
    
	/*!
	*	This is a method that generates a string containing the forward's performance information
	*/
	string generateString() const;
    
	/*!
	*	This is an assignment operator that adds two different blocks of forward's performance information
	*/
	void operator+=(const Info* info2);
};

#endif /* InfoAthletes_hpp */
