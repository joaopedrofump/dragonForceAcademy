//
//  Exceptions.cpp
//  DragonForceAcademy
//
//  Created by Joao Furriel on 03/11/16.
//  Copyright © 2016 João Furriel Pinheiro. All rights reserved.
//

#include "Exceptions.hpp"

InvalidDate::InvalidDate(DateExceptionType type, int day, int month, int year, string minDate, string maxDate) {
    
    this->type = type;
    this->day = day;
    this->month = month;
    this->year = year;
	this->minDate = minDate;
	this->maxDate = maxDate;
}

/*InvalidDate::InvalidDate(string exceptionMessage, int day, int month, int year) {

	this->type = InvalidDay;
	this->day = day;
	this->month = month;
	this->year = year;

	this->exceptionMessage = exceptionMessage;

}*/

string InvalidDate::getMessage() {
    
    switch (this->type) {
        case InvalidDay:

			if(day > 31 || day < 1)
				return "Invalid Day: " + to_string(this->day) + " is not a valid day.";
			else
				return "Invalid Day: " + to_string(this->day) + "/" + to_string(this->month) + "/" + to_string(this->year) + " is not a valid date.";

			break;

        case InvalidMonth:

            return "Invalid Month: " + to_string(this->month) + " is not a valid month.";
            break;

        case InvalidYear:

            return "Invalid Year: " + to_string(this->year) + " is not a valid year.";
            break;

        case InvalidSeparators:

            return "Invalid Date: Either separator 1 or separator 2 is not a valid date separator (/).";
            break;

		case OutOfBoundsMin:

			return "Invalid Date: The date cannot be earlier than " + minDate;
			break;

		case OutOfBoundsMax:

			return "Invalid Date: The date cannot be later than " + maxDate;
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

InvalidInput::InvalidInput(string exceptionMessage) {

	this->exceptionMessage = exceptionMessage;
}

string InvalidInput::getMessage() {

	return this->exceptionMessage;
}
