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
#include <fstream>
#include <sstream>
#include <string>
#include <stdio.h>
#include <vector>
#include <map>

using namespace std;

string const FILE_SEPRATOR = "------------------------------------------------";

string trimLink(string link);

void trimString(string &inputString);

bool validateName(string &nome);


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
// ===============  ENUMS  ===================
// ===========================================

enum Position {
    
	General,        // GNR
    GoalkeeperPos,  // GK
    DefenderPos,    // DF
    MidfielderPos,  // MF
    ForwardPos      // FW
    
};

map<string, Position> positionsMap = { { "GNR", General },
									   { "GK", GoalkeeperPos },
									   { "DF", DefenderPos },
									   { "MF", MidfielderPos },
									   { "FW", ForwardPos } };


enum DefenderPosition {
    
	CenterBack, // CB
	LeftBack,   // LB
	RightBack,  // RB
    
};

map<string, DefenderPosition> defendersMap = { { "CB", CenterBack },
											   { "LB", LeftBack },
										       { "RB", RightBack }};


enum MidfielderPosition {
    
    CentreMidfielder,     // CM
    DefensiveMidfielder,  // CDM
    AttackingMidfielder,  // CAM
	LeftMidfield,         // LM
	RightMidfield		  // RM
    
};

map<string, MidfielderPosition> midfieldersMap = { { "CM", CentreMidfielder },
												 { "CDM", DefensiveMidfielder },
												 { "CAM", AttackingMidfielder },
												 { "LM", LeftMidfield },
												 { "RM", RightMidfield } };


enum ForwardPosition {
    
	Striker,       // ST
	CentreForward, // CF
    RigthWinger,   // RW
	LeftWinger     // LW
    
};

map<string, ForwardPosition> fowardsMap = { { "CM", Striker },
											  { "CDM", CentreForward },
											  { "CAM", RigthWinger },
											  { "LM", LeftWinger } };

enum ageLevel {

	U13,
	U15,
	U17,
	U19,
	Seniors

};



#endif /* Utils_hpp */
