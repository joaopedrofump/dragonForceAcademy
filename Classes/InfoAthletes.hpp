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

extern const map<string, CoachType> coachTypeMap;

extern const map<string, Position> positionsMap;

extern const map<string, DefenderPosition> defendersMap;

extern const map<string, MidfielderPosition> midfieldersMap;

extern const map<string, ForwardPosition> forwardsMap;

class Info {
protected:
    Fraction trainingFreq;
    unsigned int yellowCards;
    unsigned int redCards;
    unsigned int tackles;
    unsigned int fouls;
    unsigned int goalsScored;
    unsigned int assists;
    Fraction passAccuracy;
public:
    Info(Fraction trainingFreq, unsigned int yellowCards, unsigned int redCards, unsigned int tackles, unsigned int fouls, unsigned int goalsScored, unsigned int assists, Fraction passAccuracy);
	Info(string &newInfo);
	Info();
    Fraction getTrainingFreq() const;
    void addTraining(Fraction newTraining);
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
    
    
};

class InfoGK : public Info {
protected:
    unsigned int saves;
    unsigned int goalsConceeded;
    
public:
    InfoGK(Fraction trainingFreq, unsigned int yellowCards, unsigned int redCards, unsigned int tackles, unsigned int fouls, unsigned int goalsScored, unsigned int assists, Fraction passAccuracy, unsigned int saves, unsigned int goalsConceeded);
	InfoGK(string &newInfo);
    InfoGK();
    unsigned int getSaves() const;
    void addSaves(unsigned int saves);
    unsigned int  getGoalsConceeded() const;
    void addGoalsConceeded(unsigned int goalsConceeded);
    string generateString() const;

};

class InfoDF : public Info {
protected:
    vector<DefenderPosition> positions;
public:
    InfoDF(Fraction trainingFreq, unsigned int yellowCards, unsigned int redCards, unsigned int tackles, unsigned int fouls, unsigned int goalsScored, unsigned int assists, Fraction passAccuracy, vector<DefenderPosition> positions);
	InfoDF(string &newInfo);
    InfoDF();
    vector<DefenderPosition> getDefenderSpecificPositions() const;
    void addDefenderSpecificPosition(DefenderPosition newPos);
    string generateString() const;
};

class InfoMF : public Info {
protected:
    vector<MidfielderPosition> positions;
public:
    InfoMF(Fraction trainingFreq, unsigned int yellowCards, unsigned int redCards, unsigned int tackles, unsigned int fouls, unsigned int goalsScored, unsigned int assists, Fraction passAccuracy, vector<MidfielderPosition> positions);
	InfoMF(string &newInfo);
    InfoMF();
    
    //pass accuracy
    
    vector<MidfielderPosition> getMidfielderSpecificPositions() const;
    void addMidfielderSpecificPosition(MidfielderPosition newPos);
    string generateString() const;
};

class InfoFW : public Info {
protected:

    vector<ForwardPosition> positions;
public:
    InfoFW(Fraction trainingFreq, unsigned int yellowCards, unsigned int redCards, unsigned int tackles, unsigned int fouls, unsigned int goalsScored, unsigned int assists, Fraction passAccuracy, vector<ForwardPosition> positions);
	InfoFW(string &newInfo);
    InfoFW();
    vector<ForwardPosition> getForwardSpecificPositions() const;
    void addAttackerSpecificPosition(ForwardPosition newPos);
    string generateString() const;
};

#endif /* InfoAthletes_hpp */
