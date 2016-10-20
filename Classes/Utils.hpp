//
//  Utils.hpp
//  DragonForceAcadamy
//
//  Created by Joao Furriel on 13/10/16.
//  Copyright © 2016 João Furriel Pinheiro. All rights reserved.
//

#ifndef Utils_hpp
#define Utils_hpp

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stdio.h>
#include <vector>

using namespace std;

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

enum Position {
    
    GoalkeeperPos,
    DefenderPos,
    MIdfielderPos,
    ForwardPos
    
};

enum DefenderPosition {
    
    Centreback,
    Sweeper,
    Fullback,
    Wingback
    
};

enum MidfielderPosition {
    
    CentreMidfielder,
    Defensive,
    Attacking,
    Wide
    
};

enum ForwardPosition {
    
    CentreForward,
    SecondStriker,
    RigthWinger,
	LeftWinger
    
};

#endif /* Utils_hpp */
