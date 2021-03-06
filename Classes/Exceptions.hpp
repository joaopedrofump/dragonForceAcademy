//
//  Exceptions.hpp
//  DragonForceAcademy
//
//  Created by Joao Furriel on 03/11/16.
//  Copyright © 2016 João Furriel Pinheiro. All rights reserved.
//

#ifndef Exceptions_hpp
#define Exceptions_hpp

#include <stdio.h>
#include <string>
using namespace std;

enum DateExceptionType {
    
    InvalidDay,
    InvalidMonth,
    InvalidYear,
    InvalidSeparators,
    OutOfBoundsMin,
	OutOfBoundsMax
};

enum InvalidStreamType {
    
    write,
    read
    
};

class InvalidDate {
private:
    int day;
    int month;
    int year;
    DateExceptionType type;
	string maxDate;
	string minDate;
	//string exceptionMessage;
public:
	InvalidDate(DateExceptionType type, int day, int month ,int year, string minDate = "", string maxDate = "");
	//InvalidDate(string exceptionMessage, int day, int month, int year);
    string getMessage();
};

class InvalidStream {
private:
    string fileName;
    InvalidStreamType type;
public:
    InvalidStream(string fileName, InvalidStreamType type);
    string getMessage();
};

class InvalidInput {
private:
	string exceptionMessage;
public:
	InvalidInput(string exceptionMessage = "Invalid Input");
	string getMessage();
};


#endif /* Exceptions_hpp */
