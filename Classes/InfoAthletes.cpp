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

Info::Info(){};

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

InfoGK::InfoGK(Fraction trainingFreq, unsigned int yellowCards, unsigned int redCards, unsigned int tackles, unsigned int fouls, unsigned int goalsScored, unsigned int assists, Fraction passAccuracy, unsigned int saves, unsigned int goalsConceeded) : Info(trainingFreq, yellowCards, redCards, tackles, fouls, goalsScored, assists, passAccuracy) {
    
    this->saves = saves;
    this->goalsConceeded = goalsConceeded;
    
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

InfoDF::InfoDF(Fraction trainingFreq, unsigned int yellowCards, unsigned int redCards, unsigned int tackles, unsigned int fouls, unsigned int goalsScored, unsigned int assists, Fraction passAccuracy, vector<DefenderPosition> positions) : Info(trainingFreq, yellowCards, redCards, tackles, fouls, goalsScored, assists, passAccuracy) {
    
    this->positions = positions;
    
}


vector<DefenderPosition> InfoDF::getDefenderSpecificPositions() const {
    
    return this->positions;
    
}
void InfoDF::addDefenderSpecificPosition(DefenderPosition newPos) {
    
    if(find(this->positions.begin(), this->positions.end(), newPos) == this->positions.end()) {
        this->positions.push_back(newPos);
    }
    
}

InfoMF::InfoMF(Fraction trainingFreq, unsigned int yellowCards, unsigned int redCards, unsigned int tackles, unsigned int fouls, unsigned int goalsScored, unsigned int assists, Fraction passAccuracy, vector<MidfielderPosition> positions) : Info(trainingFreq, yellowCards, redCards, tackles, fouls, goalsScored, assists, passAccuracy) {
    
    this->positions = positions;
    
}

vector<MidfielderPosition> InfoMF::getMidfielderSpecificPositions() const {
    
    return this->positions;
    
}
void InfoMF::addMidfielderSpecificPosition(MidfielderPosition newPos) {
    
    if(find(this->positions.begin(), this->positions.end(), newPos) == this->positions.end()) {
        this->positions.push_back(newPos);
    }
}

InfoFW::InfoFW(Fraction trainingFreq, unsigned int yellowCards, unsigned int redCards, unsigned int tackles, unsigned int fouls, unsigned int goalsScored, unsigned int assists, Fraction passAccuracy, vector<ForwardPosition> positions) : Info(trainingFreq, yellowCards, redCards, tackles, fouls, goalsScored, assists, passAccuracy) {
    
    this->positions = positions;
    
}


vector<ForwardPosition> InfoFW::getForwardSpecificPositions() const {
    
    return this->positions;
    
}
void InfoFW::addAttackerSpecificPosition(ForwardPosition newPos) {
    if(find(this->positions.begin(), this->positions.end(), newPos) == this->positions.end()) {
        this->positions.push_back(newPos);
    }
}
