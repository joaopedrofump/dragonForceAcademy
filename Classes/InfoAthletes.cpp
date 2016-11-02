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

Info::Info(string &newInfo) {

	// Training Assiduity
	Fraction tmpAthleteAssiduity(newInfo.substr(0, newInfo.find(';', 0) - 1));

	newInfo = newInfo.substr(newInfo.find(';', 0) + 2);

	// Tackles
	unsigned int  tmpAthleteTackles = atoi(newInfo.substr(0, newInfo.find(';', 0) - 1).c_str());

	newInfo = newInfo.substr(newInfo.find(';', 0) + 2);

	// Faults
	unsigned int tmpAthleteFouls = atoi(newInfo.substr(0, newInfo.find(';', 0) - 1).c_str());

	newInfo = newInfo.substr(newInfo.find(';', 0) + 2);

	// Yellow Cards
	unsigned int tmpAthleteYellowCards = atoi(newInfo.substr(0, newInfo.find(';', 0) - 1).c_str());

	newInfo = newInfo.substr(newInfo.find(';', 0) + 2);

	// Red Cards
	unsigned int tmpAthleteRedCards = atoi(newInfo.substr(0, newInfo.find(';', 0) - 1).c_str());

	newInfo = newInfo.substr(newInfo.find(';', 0) + 2);

	// Goals Scored
	unsigned int tmpAthleteGoalsScored = atoi(newInfo.substr(0, newInfo.find(';', 0) - 1).c_str());

	newInfo = newInfo.substr(newInfo.find(';', 0) + 2);

	// Assists made
	unsigned int tmpAthleteAssistsMade = atoi(newInfo.substr(0, newInfo.find(';', 0) - 1).c_str());

	newInfo = newInfo.substr(newInfo.find(';', 0) + 2);

	// Pass Acuracy
	Fraction tmpAthletePassAccuracy(newInfo.substr(0, newInfo.find(';', 0) - 1));

	newInfo = newInfo.substr(newInfo.find(';', 0) + 2);

	this->trainingFreq = tmpAthleteAssiduity;
	this->tackles = tmpAthleteTackles;
	this->fouls = tmpAthleteFouls;
	this->yellowCards = tmpAthleteYellowCards;
	this->redCards = tmpAthleteRedCards;
	this->goalsScored = tmpAthleteGoalsScored;
	this->assists = tmpAthleteAssistsMade;
	this->passAccuracy = tmpAthletePassAccuracy;

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

InfoGK::InfoGK(string &newInfo) : Info(newInfo) {

	unsigned int tmpGKsaves = atoi(newInfo.substr(0, newInfo.find(';', 0) - 1).c_str());

	newInfo = newInfo.substr(newInfo.find(';', 0) + 2);

	unsigned int tmpGKgoalsConceeded = atoi(newInfo.substr(0, newInfo.find(';', 0) - 1).c_str());

	newInfo = newInfo.substr(newInfo.find(';', 0) + 2);

	this->saves = tmpGKsaves;
	this->goalsConceeded = tmpGKgoalsConceeded;

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

InfoDF::InfoDF(string &newInfo) {

	string tmpAthletePositions = newInfo.substr(0, newInfo.find(';', 0) - 1);

	newInfo = newInfo.substr(newInfo.find(';', 0) + 2);

	// Read positions
	vector<DefenderPosition> tmpDFpositions;

	while (tmpAthletePositions != "") {

		positions.push_back(defendersMap.at(tmpAthletePositions.substr(0, tmpAthletePositions.find(',', 0) - 1)));

		if (tmpAthletePositions.find(',', 0) >= tmpAthletePositions.length())
			break;

		tmpAthletePositions = tmpAthletePositions.substr(tmpAthletePositions.find(',', 0) + 2);
	}

	this->positions = tmpDFpositions;
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

InfoMF::InfoMF(string &newInfo) {

	string tmpAthletePositions = newInfo.substr(0, newInfo.find(';', 0) - 1);

	newInfo = newInfo.substr(newInfo.find(';', 0) + 2);

	// Read positions
	vector<MidfielderPosition> tmpMFpositions;

	while (tmpAthletePositions != "") {

		positions.push_back(midfieldersMap.at(tmpAthletePositions.substr(0, tmpAthletePositions.find(',', 0) - 1)));

		if (tmpAthletePositions.find(',', 0) >= tmpAthletePositions.length())
			break;

		tmpAthletePositions = tmpAthletePositions.substr(tmpAthletePositions.find(',', 0) + 2);
	}

	this->positions = tmpMFpositions;
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

InfoFW::InfoFW(string &newInfo) {

	string tmpAthletePositions = newInfo.substr(0, newInfo.find(';', 0) - 1);

	newInfo = newInfo.substr(newInfo.find(';', 0) + 2);

	// Read positions
	vector<ForwardPosition> tmpFWpositions;

	while (tmpAthletePositions != "") {

		positions.push_back(forwardsMap.at(tmpAthletePositions.substr(0, tmpAthletePositions.find(',', 0) - 1)));

		if (tmpAthletePositions.find(',', 0) >= tmpAthletePositions.length())
			break;

		tmpAthletePositions = tmpAthletePositions.substr(tmpAthletePositions.find(',', 0) + 2);
	}

	this->positions = tmpFWpositions;
}

vector<ForwardPosition> InfoFW::getForwardSpecificPositions() const {
    
    return this->positions;
    
}

void InfoFW::addAttackerSpecificPosition(ForwardPosition newPos) {
    if(find(this->positions.begin(), this->positions.end(), newPos) == this->positions.end()) {
        this->positions.push_back(newPos);
    }
}
