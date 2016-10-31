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
	friend unsigned int operator-(const Date & date);
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

bool leUnsignedShortInt(unsigned short int &input, unsigned short int min, unsigned short int  max, string mensagemErro = "Invalid Input");


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
    
    GoalkeeperPos = 1,  // GK
    DefenderPos = 2,    // DF
    MidfielderPos = 3,  // MF
    ForwardPos = 4,      // FW
    
};

//map<string, Position> positionsMap;

enum DefenderPosition {
    
	CenterBack = 1, // CB
	LeftBack = 2,   // LB
	RightBack = 3,  // RB
    
};

//map<string, DefenderPosition> defendersMap;

enum MidfielderPosition {
    
    CentreMidfielder = 1,     // CM
    DefensiveMidfielder = 2,  // CDM
    AttackingMidfielder = 3,  // CAM
	LeftMidfield = 4,         // LM
	RightMidfield = 5		  // RM
    
};

//map<string, MidfielderPosition> midfieldersMap;

enum ForwardPosition {
    
	Striker = 1,       // ST
	CentreForward = 2, // CF
    RigthWinger = 3,   // RW
	LeftWinger = 4    // LW
    
};

//map<string, ForwardPosition> fowardsMap;

enum ageLevel {

	U13 = 1,
	U15 = 2,
	U17 = 3,
	U19 = 4,
	Seniors = 5

};

class Info {
public:
	Fraction trainingFreq;
	unsigned int yellowCards;
	unsigned int redCards;

	Info(Fraction trainingFreq, unsigned int yellowCards, unsigned int redCards)
		: trainingFreq(trainingFreq), yellowCards(yellowCards), redCards(redCards){}
};

class InfoGK : public Info {
public:
	unsigned int saves;
	unsigned int goalsConceeded;

	InfoGK(Fraction trainingFreq, unsigned int yellowCards, unsigned int redCards,
		   unsigned int saves, unsigned int goalsConceeded)
		: Info(trainingFreq, yellowCards, redCards), saves(saves), goalsConceeded(goalsConceeded){}

	//...
};

class InfoDF : public Info {
public:
	unsigned int tackles;
	unsigned int goalsConceeded;
	unsigned int faults;
	Fraction passAccuracy;
	vector<DefenderPosition> positions;


	InfoDF(Fraction trainingFreq, unsigned int yellowCards, unsigned int redCards,
		   unsigned int tackles, unsigned int goalsConceeded, unsigned int faults, Fraction passAccuracy, vector<DefenderPosition> positions)
		: Info(trainingFreq, yellowCards, redCards),
			   tackles(tackles), goalsConceeded(goalsConceeded), faults(faults), passAccuracy(passAccuracy), positions(positions){}
	
	//...
};

class InfoMF : public Info {
public:
	unsigned int tackles;
	unsigned int goalsScored;
	unsigned int assistsMade;
	unsigned int faults;
	Fraction passAccuracy;
	vector<MidfielderPosition> positions;

	InfoMF(Fraction trainingFreq, unsigned int yellowCards, unsigned int redCards,
		unsigned int tackles, unsigned int goalsScored, unsigned int assistsMade, unsigned int faults, Fraction passAccuracy, vector<MidfielderPosition> positions)
		: Info(trainingFreq, yellowCards, redCards),
		tackles(tackles), goalsScored(goalsScored), assistsMade(assistsMade), faults(faults), passAccuracy(passAccuracy), positions(positions) {}

	//...
};

struct InfoFW : public Info {
public:
	unsigned int goalsScored;
	unsigned int assistsMade;
	Fraction passAccuracy;
	vector<ForwardPosition> positions;

	InfoFW(Fraction trainingFreq, unsigned int yellowCards, unsigned int redCards,
		   unsigned int goalsScored, unsigned int assistsMade, Fraction passAccuracy, vector<ForwardPosition> positions)
		: Info(trainingFreq, yellowCards, redCards),
		goalsScored(goalsScored), assistsMade(assistsMade), passAccuracy(passAccuracy), positions(positions) {}

	//...
};




#endif /* Utils_hpp */
