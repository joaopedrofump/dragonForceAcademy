//
//  Utils.hpp
//  DragonForceAcadamy
//
//  Created by Joao Furriel on 13/10/16.
//  Copyright © 2016 João Furriel Pinheiro. All rights reserved.
//
#pragma once

#ifndef Utils_hpp
#define Utils_hpp

#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include <stdio.h>
#include <vector>
#include <map>
#include <ctime>
#include <direct.h>
#include <Windows.h>


using namespace std;

string const FILE_SEPARATOR = "------------------------------------------------";

// ===========================================
// ===============  DATE  ====================
// ===========================================

class Date {
private:
	int day;
	int month;
	int year;
	bool valid;
	bool isLeap() const;
	int numDays() const;
	bool isValid();

public:
	Date(bool currentDate = false);
	Date(string data); // data na forma DD/MM/AAAA
	Date(unsigned int dia, unsigned int mes, unsigned int ano);
	int getDay() const;
	int getMonth() const;
	int getYear() const;
	bool getValid() const;
	void setDay(int dia);
	void setMonth(int mes);
	void setYear(int ano);
	void save(ofstream &out) const;
	friend bool operator>=(const Date &date1, const Date date2);
	friend ostream& operator<<(ostream& out, const Date & data);
	string showDate() const;
	void setCurrentDate();
};


// ===========================================
// ===============  TABLE  ===================
// ===========================================

class Table {
private:
	//stringstream tableStream;
	vector<vector<string>> tableVector;
	vector<bool> blocks; //FALSE se a linha est· colada ‡ de cima, TRUE se s„o linhas separadas

	unsigned int numColumns;
	unsigned int numLines;
	vector<int> columnsWidth;
	vector<string> lastLineComponents;
	unsigned int indent;



public:
	stringstream tableStream;

	Table(vector<string> components, unsigned int indentacao = 0);
	Table(vector<string> components, vector<int> spacesForColumn, unsigned int indentacao = 0);
	Table(vector<vector<string>> tableVector, vector<bool> blocks, vector<int> spacesForColumn, unsigned int indentacao = 0);
	//Table(unsigned int indentacao = 0);

	void formatTable(char internalChar, char limitingChar, vector<int> spacesForColumn, unsigned int indentacaoFT = 0);

	vector<int> getColumsWidth() const;
	unsigned int getIndentacao() const;
	vector<vector<string>> getTableVector() const;
	vector<bool> getBlocks() const;

	void addNewLine(vector<string> components);
	void addDataInSameLine(vector<string> components);

	void adjustColumnsSize(vector<int> spaspacesForColumn);

	friend ostream& operator<<(ostream& out, const Table &table);

};

// ===========================================
// =============  FRACTION  ==================
// ===========================================

class Fraction {

private:
	int numerator;
	int denominator;

public:
	Fraction();
	Fraction(int num, int den);
	Fraction(string fractionString);

	//  Operations as fractions

	Fraction operator+(Fraction value) const;
	void operator+=(Fraction &value);

	Fraction operator-(Fraction value) const;
	void operator-=(Fraction &value);

	Fraction operator*(Fraction value) const;
	void operator*=(Fraction &value);

	Fraction operator/(Fraction value) const;
	void operator/=(Fraction &value);

	//  Comparers

	bool operator<(Fraction value) const;
	bool operator==(Fraction value) const;
	bool operator>=(Fraction value) const;
	bool operator>(Fraction value) const;
	bool operator<=(Fraction value) const;

	//  Operations as Ratio

	Fraction operator|(Fraction value) const;
	void Fraction::operator|=(Fraction &value);

	Fraction& operator++();
	Fraction operator++(int);

	void reduce();

	//  Console functions

	void print(bool originalFraction = true) const;
	void printPercentage() const;
};

// ===========================================
// ==============  FUNCTIONS  ================
// ===========================================

void trimString(string &inputString);

bool validateName(string &nome);

string trimLink(string link);

void clearScreen();

bool validateName(string &nome);

void SetCursor(int column, int line);

int GetCursorX();

int GetCursorY();

void ignoreLine(bool ignoreControl = true, string message = "Prima Enter para continuar.");

// ===========================================
// ==========  ENUMS & STRUCTS ===============
// ===========================================

enum CoachType {

	HeadCoach,			// HDC
	AssistantCoach,		// ASC
	GoalkeeperCoach,	// GKC
	PhysicalTrainer		// PHT

};

//map<string, CoachType> coachTypeMap;

enum Position {
    
    GoalkeeperPos,  // GK
    DefenderPos,    // DF
    MidfielderPos,  // MF
    ForwardPos      // FW
    
};

//map<string, Position> positionsMap;

enum DefenderPosition {
    
	CenterBack, // CB
	LeftBack,   // LB
	RightBack,  // RB
    
};

//map<string, DefenderPosition> defendersMap;

enum MidfielderPosition {
    
    CentreMidfielder,     // CM
    DefensiveMidfielder,  // CDM
    AttackingMidfielder,  // CAM
	LeftMidfield,         // LM
	RightMidfield		  // RM
    
};

//map<string, MidfielderPosition> midfieldersMap;

enum ForwardPosition {
    
	Striker,       // ST
	CentreForward, // CF
    RigthWinger,   // RW
	LeftWinger     // LW
    
};

//map<string, ForwardPosition> fowardsMap;

enum ageLevel {

	U13,
	U15,
	U17,
	U19,
	Seniors

};

class Info {
	Fraction trainingFreq;
	unsigned int yellowCards;
	unsigned int redCards;
public:
	Info(Fraction trainingFreq, unsigned int yellowCards, unsigned int redCards)
		: trainingFreq(trainingFreq), yellowCards(yellowCards), redCards(redCards){}
};

class InfoGK : public Info {
	
	unsigned int saves;
	unsigned int goalsConceeded;
public:
	InfoGK(Fraction trainingFreq, unsigned int yellowCards, unsigned int redCards,
		   unsigned int saves, unsigned int goalsConceeded)
		: Info(trainingFreq, yellowCards, redCards), saves(saves), goalsConceeded(goalsConceeded){}

	//...
};

class InfoDF : public Info {

	unsigned int tackles;
	unsigned int goalsConceeded;
	unsigned int faults;
	Fraction passAccuracy;
	vector<DefenderPosition> positions;

public:
	InfoDF(Fraction trainingFreq, unsigned int yellowCards, unsigned int redCards,
		   unsigned int tackles, unsigned int goalsConceeded, unsigned int faults, Fraction passAccuracy, vector<DefenderPosition> positions)
		: Info(trainingFreq, yellowCards, redCards),
			   tackles(tackles), goalsConceeded(goalsConceeded), faults(faults), passAccuracy(passAccuracy), positions(positions){}
	
	//...
};

class InfoMF : public Info {

	unsigned int tackles;
	unsigned int goalsScored;
	unsigned int assistsMade;
	unsigned int faults;
	Fraction passAccuracy;
	vector<MidfielderPosition> positions;
public:
	InfoMF(Fraction trainingFreq, unsigned int yellowCards, unsigned int redCards,
		unsigned int tackles, unsigned int goalsScored, unsigned int assistsMade, unsigned int faults, Fraction passAccuracy, vector<MidfielderPosition> positions)
		: Info(trainingFreq, yellowCards, redCards),
		tackles(tackles), goalsScored(goalsScored), assistsMade(assistsMade), faults(faults), passAccuracy(passAccuracy), positions(positions) {}

	//...
};

struct InfoFW : public Info {

	unsigned int goalsScored;
	unsigned int assistsMade;
	Fraction passAccuracy;
	vector<ForwardPosition> positions;
public:
	InfoFW(Fraction trainingFreq, unsigned int yellowCards, unsigned int redCards,
		   unsigned int goalsScored, unsigned int assistsMade, Fraction passAccuracy, vector<ForwardPosition> positions)
		: Info(trainingFreq, yellowCards, redCards),
		goalsScored(goalsScored), assistsMade(assistsMade), passAccuracy(passAccuracy), positions(positions) {}

	//...
};




#endif /* Utils_hpp */
