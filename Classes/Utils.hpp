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
#include <math.h>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <vector>
#include <map>
#include <ctime>
#include <algorithm>
#include <unordered_set>
#include "Exceptions.hpp"
#include "BST.h"
#ifdef __llvm__
#include <sys/stat.h>
#elif _MSC_VER
#include <direct.h>
#include <Windows.h>
#endif


string const FILE_SEPARATOR = "------------------------------------------------";

// ===========================================
// ==========  ENUMS & STRUCTS ===============
// ===========================================


enum CoachType {
    
    HeadCoach = 1,			// HDC
    GoalkeeperCoach = 2,	// GKC
    PhysicalTrainer = 3		// PHT
    
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

enum MatchType {
    
    home,
    away,
    neutral
};

enum SortCriteria {
    
    id,
    date,
    numberOfPlayers,
    playerPosition,
    name,
    age,
    height,
    ecg,
    typeOfCoach,
    coachLevel
    
};

enum SortOrder {
    ascending,
    descending
};

enum Result {
    win,
    lost,
    draw
};


const map<Position, string> positionsMapPosString = {
    
    {GoalkeeperPos, "GK"},
    {DefenderPos, "DF"},
    {MidfielderPos, "MF"},
    {ForwardPos, "FW"}
    
};




// ===========================================
// ===============  DATE  ====================
// ===========================================

class Date {
private:
	int day;
	int month;
	int year;
	bool isLeap(int year) const;
	int numDays(int month, int year) const;

public:
	Date();//data actual
	Date(string data); // data na forma DD/MM/AAAA
	Date(unsigned int dia, unsigned int mes, unsigned int ano);
    Date(ifstream &inStream);
    friend ifstream& operator>>(ifstream &inStream, Date &dateToRead);
	int getDay() const;
	int getMonth() const;
	int getYear() const;
	void setDay(int dia);
	void setMonth(int mes);
	void setYear(int ano);
	void save(ofstream &out) const;
	friend bool operator>=(const Date &date1, const Date date2);
    friend bool operator<(const Date &date1, const Date &date2);
	friend bool operator==(const Date &date1, const Date &date2);
	friend ostream& operator<<(ostream& out, const Date & data);
	friend int operator-(const Date &date1, const Date &date2);
	friend Date operator+(const Date &date, int delta);
	Date& operator++();
	Date operator++(int);
	string showDate() const;
	void setCurrentDate();
	string str() const;
};


// ===========================================
// ===============  TABLE  ===================
// ===========================================

class Table {
private:
	vector<vector<string>> tableVector;
	vector<bool> blocks; //FALSE se a linha est· colada ‡ de cima, TRUE se s„o linhas separadas

	unsigned int numColumns;
	unsigned int numLines;
	vector<int> columnsWidth;
	vector<string> lastLineComponents;
	unsigned int indent;



public:
	stringstream tableStream;
	Table& operator=(const Table&);
	Table(const Table&);
	Table(vector<string> components, unsigned int indentacao = 0);
	Table(vector<string> components, vector<int> spacesForColumn, unsigned int indentacao = 0);
	Table(vector<vector<string>> tableVector, vector<bool> blocks, vector<int> spacesForColumn, unsigned int indentacao = 0);
	Table(vector<vector<string>> tableVector, unsigned int indentation, bool sameLine = true);
	//Table(unsigned int indentacao = 0);

	void formatTable(char internalChar, char limitingChar, vector<int> spacesForColumn, unsigned int indentacaoFT = 0);

	vector<int> getColumsWidth() const;
	unsigned int getIndentacao() const;
	vector<vector<string>> getTableVector() const;
	vector<bool> getBlocks() const;
	string getStream() const;

	void addNewLine(vector<string> components);
	void addDataInSameLine(vector<string> components);

	void adjustColumnsSize(vector<int> spaspacesForColumn);

	friend ostream& operator<<(ostream& out, const Table &table);

};

// ===========================================
// =============  FRACTION  ==================
// ===========================================

class Fraction {

public:
	int numerator;
	int denominator;

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

	double fracValue() const;

	//  Comparers

	bool operator<(Fraction value) const;
	bool operator==(Fraction value) const;
	bool operator>=(Fraction value) const;
	bool operator>(Fraction value) const;
	bool operator<=(Fraction value) const;

	//  Operations as Ratio

	Fraction operator|(Fraction value) const;
	void operator|=(const Fraction &value);

	Fraction& operator++();
	Fraction operator++(int);

	void reduce();

	//  Console functions

	void print(bool originalFraction = true) const;
	void printPercentage() const;
    string getFrac() const;
    int getNumerator() const;
    int getDenominator() const;
};

// ===========================================
// ==============  FUNCTIONS  ================
// ===========================================

void trimString(string &inputString);

bool validateName(string &nome, unsigned int minWords = 2);

string trimLink(string link);

void clearScreen();

void SetCursor(int column, int line);

int GetCursorX();

int GetCursorY();

void ignoreLine(bool ignoreControl = true, string message = "Press ENTER to continue.");

bool readUnsignedInt(unsigned int &input, unsigned int min, unsigned int  max, string errorMessage = "Invalid Input");

bool readDates(vector<Date> &resultVector, Date min, Date max, string message, string errorMessage);

bool readDate(Date &result, string message, string errorMessage);
bool readDate(Date &result, Date min, Date max, string message, string errorMessage);

bool emptyString(string stringTest);

string path();

int createDirectory(const char* path);


string stringPath(string originalStr);

string getLevelStringFromAge(Date birthDate);

string readAndCut(string &stringToCut);

string normalizeId(unsigned int digits, unsigned int id);

template <class T>
int findInVector(vector<T> vec1, T element) {
	for (int i = 0; i < vec1.size(); i++) {
		if (element == vec1.at(i))
			return i;
	}
	return -1;
}

string transformNumberToOrder(int number);

#endif /* Utils_hpp */
