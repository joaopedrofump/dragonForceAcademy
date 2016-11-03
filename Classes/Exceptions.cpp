//
//  Exceptions.cpp
//  DragonForceAcademy
//
//  Created by Joao Furriel on 03/11/16.
//  Copyright © 2016 João Furriel Pinheiro. All rights reserved.
//

#include "Exceptions.hpp"

InvalidDateException::InvalidDateException(DateExceptionType type, int day, int month, int year) {
    
    this->type = type;
    this->day = day;
    this->month = month;
    this->year = year;
    
}

string InvalidDateException::getMessage() {
    
    switch (this->type) {
        case InvalidDay:
            return "Invalid Day Exception: " + to_string(this->day) + "/" + to_string(this->month) + "/" + to_string(this->year) + " is not a valid date.";
            break;
        case InvalidMonth:
            return "Invalid Month Exception: " + to_string(this->month) + " is not a valid month.";
            break;
        case InvalidYear:
            return "Invalid Year Exception: " + to_string(this->year) + " is not a valid year.";
            break;
        case InvalidSeparators:
            return "Invalid Date Exception: Either separator 1 or separator 2 is not a valid date separator (/).";
            break;
            
        default:
            break;
    }

}


InvalidStream::InvalidStream(string fileName, InvalidStreamType type) {
    this->fileName = fileName;
    this->type = type;
}
string InvalidStream::getMessage() {
    
    switch (this->type) {
        case read:
            return "Could not read the file: " + this->fileName + ".";
            break;
        case write:
            return "Could not write to file: " + this->fileName + ".";
            break;
            
        default:
            break;
    }
    
    
    return this->fileName;
}
