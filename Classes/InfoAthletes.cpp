//
//  InfoAthletes.cpp
//  DragonForceAcademy
//
//  Created by Joao Furriel on 02/11/16.
//  Copyright © 2016 João Furriel Pinheiro. All rights reserved.
//

#include "InfoAthletes.hpp"

Info::Info(Fraction trainingFreq, unsigned int yellowCards, unsigned int redCards, unsigned int tackles, unsigned int fouls, unsigned int goalsScored, unsigned int assists, Fraction passAccuracy) {
    
    this->trainingFreq = trainingFreq;
    this->yellowCards = yellowCards;
    this->redCards = redCards;
    this->tackles = tackles;
    this->fouls = fouls;
    this->goalsScored = goalsScored;
    this->assists = assists;
    this->passAccuracy = passAccuracy;
}

Info::Info() {
    this->yellowCards = 0;
    this->redCards = 0;
    this->tackles = 0;
    this->fouls = 0;
    this->goalsScored = 0;
    this->assists = 0;

};

Fraction Info::getTrainingFreq() const {
    
    return this->trainingFreq;
    
}

void Info::addTraining(Fraction newTraining) {
    
    this->trainingFreq |= newTraining;
    
}

unsigned int Info::getYellowCards() const {
    
    return this->yellowCards;
    
}

unsigned int Info::getRedCards() const {
    
    return this->redCards;
    
}

void Info::addYellowCard() {
    this->yellowCards++;
}

void Info::addRedCard() {
    this->redCards++;
}

unsigned int Info::getTackles() const {
    return this->tackles;
}
void Info::addTackles(unsigned int tackles) {
    this->tackles += tackles;
}
unsigned int Info::getFouls() const {
    return this->fouls;
}
void Info::addFouls(unsigned int fouls) {
    this->fouls += fouls;
}
unsigned int Info::getGoalsScored() const {
    return this->goalsScored;
}
void Info::addGoalsScored(unsigned int goalsScored) {
    this->goalsScored += goalsScored;
}
unsigned int Info::getAssists() const {
    return this->assists;
}
void Info::addAssists(unsigned int assists) {
    this->assists += assists;
}
Fraction Info::getPassAccuracy() const {
    
    return this->passAccuracy;
    
}
void Info::addPassAccuracy(Fraction passAccuracy) {
    this->passAccuracy |= passAccuracy;
}

ostream& operator<<(ostream& out, const Info &info) {
    
    out << info.generateString();
    return out;
    
}

string Info::generateString() const {
    
    return (trainingFreq.getFrac() + " ; " + to_string(this->tackles) + " ; " + to_string(this->fouls) + " ; " + to_string(this->yellowCards) + " ; " + to_string(this->redCards) + " ; " + to_string(this->goalsScored) + " ; " + to_string(this->assists) + " ; " + this->passAccuracy.getFrac());
    
}

void Info::save(ofstream &out) {
    
    out << *this;
    
}

InfoGK::InfoGK(Fraction trainingFreq, unsigned int yellowCards, unsigned int redCards, unsigned int tackles, unsigned int fouls, unsigned int goalsScored, unsigned int assists, Fraction passAccuracy, unsigned int saves, unsigned int goalsConceeded) : Info(trainingFreq, yellowCards, redCards, tackles, fouls, goalsScored, assists, passAccuracy) {
    
    this->saves = saves;
    this->goalsConceeded = goalsConceeded;
    
}

InfoGK::InfoGK() : Info() {
    this->saves = 0;
    this->goalsConceeded = 0;
}

unsigned int InfoGK::getSaves() const {
    return this->saves;
}

void InfoGK::addSaves(unsigned int saves) {
    this->saves += saves;
}

unsigned int InfoGK::getGoalsConceeded() const {
    return this->goalsConceeded;
}

void InfoGK::addGoalsConceeded(unsigned int goalsConceeded) {
    this->goalsConceeded += goalsConceeded;
}

string InfoGK::generateString() const {
    
    return Info::generateString() + " ; " + to_string(this->saves) + " ; " + to_string(this->goalsConceeded);
    
}

InfoDF::InfoDF(Fraction trainingFreq, unsigned int yellowCards, unsigned int redCards, unsigned int tackles, unsigned int fouls, unsigned int goalsScored, unsigned int assists, Fraction passAccuracy, vector<DefenderPosition> positions) : Info(trainingFreq, yellowCards, redCards, tackles, fouls, goalsScored, assists, passAccuracy) {
    
    this->positions = positions;
    
}

InfoDF::InfoDF() : Info() {
    
    vector<DefenderPosition> empty;
    this->positions = empty;
    
}


vector<DefenderPosition> InfoDF::getDefenderSpecificPositions() const {
    
    return this->positions;
    
}
void InfoDF::addDefenderSpecificPosition(DefenderPosition newPos) {
    
    if(find(this->positions.begin(), this->positions.end(), newPos) == this->positions.end()) {
        this->positions.push_back(newPos);
    }
    
}

string InfoDF::generateString() const {
    
    string positionsString;
    
    if(this->positions.size() > 0) {
        
        positionsString = this->positions.at(0);
        
    }
    
    for (size_t i = 1; i < this->positions.size(); i++) {
        
        positionsString += (" , " + to_string(this->positions.at(i)));
        
    }
    
    return Info::generateString() + " ; " + positionsString;
}

InfoMF::InfoMF(Fraction trainingFreq, unsigned int yellowCards, unsigned int redCards, unsigned int tackles, unsigned int fouls, unsigned int goalsScored, unsigned int assists, Fraction passAccuracy, vector<MidfielderPosition> positions) : Info(trainingFreq, yellowCards, redCards, tackles, fouls, goalsScored, assists, passAccuracy) {
    
    this->positions = positions;
    
}

InfoMF::InfoMF() : Info() {
    
    vector<MidfielderPosition> empty;
    this->positions = empty;
    
}

vector<MidfielderPosition> InfoMF::getMidfielderSpecificPositions() const {
    
    return this->positions;
    
}
void InfoMF::addMidfielderSpecificPosition(MidfielderPosition newPos) {
    
    if(find(this->positions.begin(), this->positions.end(), newPos) == this->positions.end()) {
        this->positions.push_back(newPos);
    }
}

string InfoMF::generateString() const {
    
    string positionsString;
    
    if(this->positions.size() > 0) {
        
        positionsString = this->positions.at(0);
        
    }
    
    for (size_t i = 1; i < this->positions.size(); i++) {
        
        positionsString += (" , " + to_string(this->positions.at(i)));
        
    }
    
    return Info::generateString() + " ; " + positionsString;
}

InfoFW::InfoFW(Fraction trainingFreq, unsigned int yellowCards, unsigned int redCards, unsigned int tackles, unsigned int fouls, unsigned int goalsScored, unsigned int assists, Fraction passAccuracy, vector<ForwardPosition> positions) : Info(trainingFreq, yellowCards, redCards, tackles, fouls, goalsScored, assists, passAccuracy) {
    
    this->positions = positions;
    
}

InfoFW::InfoFW() : Info() {
    
    vector<ForwardPosition> empty;
    this->positions = empty;
    
}


vector<ForwardPosition> InfoFW::getForwardSpecificPositions() const {
    
    return this->positions;
    
}
void InfoFW::addAttackerSpecificPosition(ForwardPosition newPos) {
    if(find(this->positions.begin(), this->positions.end(), newPos) == this->positions.end()) {
        this->positions.push_back(newPos);
    }
}

string InfoFW::generateString() const {
    
    string positionsString;
    
    if(this->positions.size() > 0) {
        
        positionsString = this->positions.at(0);
        
    }
    
    for (size_t i = 1; i < this->positions.size(); i++) {
        
        positionsString += (" , " + to_string(this->positions.at(i)));
        
    }
    
    return Info::generateString() + " ; " + positionsString;
}
