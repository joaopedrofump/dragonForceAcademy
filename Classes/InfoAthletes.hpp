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
    Fraction winningFreq; //athlete's frequency to won matches
    Fraction losingFreq; //athlete's frequency to lost matches
    Fraction drawFreq; //athlete's frequency to drawn matches
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
	Info(Fraction trainingFreq, Fraction winningFreq, Fraction losingFreq, Fraction drawFreq, unsigned int yellowCards, unsigned int redCards, unsigned int tackles, unsigned int fouls, unsigned int goalsScored, unsigned int assists, Fraction passAccuracy);
	
	/*!
	*	This is a constructor that creates new athlete's performance 
	*/
	Info(string &newInfo);
	Info();
    Info(istream &inStream);
    Fraction getTrainingFreq() const;
    void addTraining(Fraction newTraining = Fraction(1,1));
    Fraction getWinningFreq() const;
    void addWinningFreq(Fraction newFreq = Fraction(1,1));
    Fraction getLosingFreq() const;
    void addLosingFreq(Fraction newFreq = Fraction(1,1));
    Fraction getDrawFreq() const;
    void addDrawFreq(Fraction newFreq = Fraction(1,1));
    unsigned int getYellowCards() const;
    unsigned int getRedCards() const;
    void addYellowCard();
    void addRedCard();
    unsigned int  getTackles() const;
    void addTackles(unsigned int tackles);
    unsigned int  getFouls() const;
    void addFouls(unsigned int fouls);
    unsigned int getGoalsScored() const;
    void addGoalsScored(unsigned int goalsScored);
    unsigned int getAssists() const;
    void addAssists(unsigned int assists);
    Fraction getPassAccuracy() const;
    void addPassAccuracy(Fraction passAccuracy);
    
    virtual unsigned int getSaves() const {return 0;};
    virtual void addSaves(unsigned int saves) {};
    
    virtual unsigned int getGoalsConceeded() const {return 0;};
    virtual void addGoalsConceeded(unsigned int goalsConceeded){};
    
    virtual vector<DefenderPosition> getDefenderSpecificPositions() const {vector<DefenderPosition> res; return res;}
    virtual void addDefenderSpecificPosition(DefenderPosition newPos){};
    
    virtual vector<MidfielderPosition> getMidfielderSpecificPositions() const {vector<MidfielderPosition> res; return res;}
    virtual void addMidfielderSpecificPosition(MidfielderPosition newPos) {};
    
    virtual vector<ForwardPosition> getForwardSpecificPositions() const {vector<ForwardPosition> res; return res;}
    virtual void addAttackerSpecificPosition(ForwardPosition newPos){};
    
    friend ostream& operator<<(ostream& out, const Info &info);
    virtual string generateString() const;
    virtual void save (ofstream& out);
    void sumGeneralInfo(const Info &info2);
    virtual void operator+=(const Info* info2){};
    
};

class InfoGK : public Info {
protected:
    unsigned int saves;
    unsigned int goalsConceeded;
    
public:
    InfoGK(Fraction trainingFreq, Fraction winningFreq, Fraction losingFreq, Fraction drawFreq,unsigned int yellowCards, unsigned int redCards, unsigned int tackles, unsigned int fouls, unsigned int goalsScored, unsigned int assists, Fraction passAccuracy, unsigned int saves, unsigned int goalsConceeded);
	InfoGK(string &newInfo);
    InfoGK();
    InfoGK(istream &inStream);
    unsigned int getSaves() const;
    void addSaves(unsigned int saves);
    unsigned int  getGoalsConceeded() const;
    void addGoalsConceeded(unsigned int goalsConceeded);
    string generateString() const;
    void operator+=(const Info* info2);
    
};

class InfoDF : public Info {
protected:
    vector<DefenderPosition> positions;
public:
    InfoDF(Fraction trainingFreq, Fraction winningFreq, Fraction losingFreq, Fraction drawFreq, unsigned int yellowCards, unsigned int redCards, unsigned int tackles, unsigned int fouls, unsigned int goalsScored, unsigned int assists, Fraction passAccuracy, vector<DefenderPosition> positions);
	InfoDF(string &newInfo);
    InfoDF();
    InfoDF(istream &inStream);
    vector<DefenderPosition> getDefenderSpecificPositions() const;
    void addDefenderSpecificPosition(DefenderPosition newPos);
    string generateString() const;
    void operator+=(const Info* info2);
};

class InfoMF : public Info {
protected:
    vector<MidfielderPosition> positions;
public:
    InfoMF(Fraction trainingFreq, Fraction winningFreq, Fraction losingFreq, Fraction drawFreq, unsigned int yellowCards, unsigned int redCards, unsigned int tackles, unsigned int fouls, unsigned int goalsScored, unsigned int assists, Fraction passAccuracy, vector<MidfielderPosition> positions);
	InfoMF(string &newInfo);
    InfoMF();
    InfoMF(istream &inStream);
    //pass accuracy
    
    vector<MidfielderPosition> getMidfielderSpecificPositions() const;
    void addMidfielderSpecificPosition(MidfielderPosition newPos);
    string generateString() const;
    void operator+=(const Info* info2);
};

class InfoFW : public Info {
protected:

    vector<ForwardPosition> positions;
public:
    InfoFW(Fraction trainingFreq, Fraction winningFreq, Fraction losingFreq, Fraction drawFreq, unsigned int yellowCards, unsigned int redCards, unsigned int tackles, unsigned int fouls, unsigned int goalsScored, unsigned int assists, Fraction passAccuracy, vector<ForwardPosition> positions);
	InfoFW(string &newInfo);
    InfoFW();
    InfoFW(istream &inStream);
    vector<ForwardPosition> getForwardSpecificPositions() const;
    void addAttackerSpecificPosition(ForwardPosition newPos);
    string generateString() const;
    void operator+=(const Info* info2);
};

#endif /* InfoAthletes_hpp */
