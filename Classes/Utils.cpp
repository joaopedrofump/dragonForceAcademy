//
//  Utils.cpp
//  DragonForceAcadamy
//
//  Created by Joao Furriel on 13/10/16.
//  Copyright © 2016 João Furriel Pinheiro. All rights reserved.
//

#include "Utils.hpp"

#include <string>
#include <fstream>
#include <ctime>
#include <vector>

//teste branch



// ===========================================
// ==============  DATE  =====================
// ===========================================

// data na forma DD/MM/AAAA

Date::Date(bool currentDate) {
    
    if (currentDate) {
        
#ifdef __llvm__
        
        time_t t = time(NULL);
        tm* timePtr = localtime(&t);
        
        this->day = timePtr->tm_mday;
        this->month = (timePtr->tm_mon) + 1;
        this->year = timePtr->tm_year + 1900;
        this->valid = this->isValid();
        
#elif _MSC_VER
        
        time_t t = time(NULL);
        struct tm timeInfo;
        localtime_s(&timeInfo, &t);
        
        this->day = timeInfo.tm_mday;
        this->month= (timeInfo.tm_mon) + 1;
        this->year = timeInfo.tm_year + 1900;
        this->valid = this->isValid();
        
#endif
        
    }
    
    else {
        
        this->day = 0;
        this->month = 0;
        this->year = 0;
        this->valid = this->isValid();
        
        
    }
    
}

Date::Date(string dataStr) {
    
    stringstream dataStream(dataStr);
    char separator1;
    char separator2;
    
    dataStream >> this->day;
    dataStream >> separator1;
    dataStream >> this->month;
    dataStream >> separator2;
    dataStream >> this->year;
    
    if (separator1 != '/' || separator2 != '/') {
        
        valid = false;
        
    }
    
    else {
        
        this->valid = isValid();
        
    }
    
    
}

Date::Date(unsigned int day, unsigned int month, unsigned int year) {
    
    this->day = day;
    this->month = month;
    this->year = year;
    
    this->valid = isValid();
    
}

int Date::getDay() const {
    return day;
}

int Date::getMonth() const {
    return month;
}

int Date::getYear() const {
    return year;
}

void Date::setDay(int day) {
    
    this->day = day;
    
}

void Date::setMonth(int month) {
    this->month = month;
}

void Date::setYear(int year) {
    this->year = year;
}

bool Date::isLeap() const {
    
    if (this->year % 400 == 0) {
        return true;
    }
    
    else {
        
        if (this->year % 4 == 0 && this->year % 100 != 0) {
            return true;
        }
        
        else {
            return false;
        }
    }
}

int Date::numDays() const {
    
    switch (this->year) {
        case 4: case 6: case 9: case 11:
            return 30;
            break;
        case 2:
            if (this->isLeap()) {
                return 29;
            }
            else {
                return 28;
                
            }
            break;
        default:
            return 31;
            break;
    }
}

bool Date::isValid() {
    
    if (this->year < 1900) {
        return false;
    }
    
    if (this->month == 0 || this->year > 12) {
        
        return false;
    }
    
    if ((this->day == 0) || (this->day  > numDays())) {
        
        return false;
    }
    
    return true;
    
    
}

bool operator>=(const Date &date1, const Date date2) {
    
    if (date1.getYear() < date2.getYear()) {
        
        return false;
        
    }
    
    else if (date1.getYear() > date2.getYear()) {
        
        return true;
    }
    
    else {
        
        
        if (date1.getMonth() < date2.getMonth()) {
            
            return false;
            
        }
        
        else if (date1.getMonth() > date2.getMonth()) {
            
            return true;
        }
        
        else {
            
            
            if (date1.getDay() < date2.getDay()) {
                
                return false;
                
            }
            
            else if (date1.getDay() > date2.getDay()) {
                
                return true;
            }
            
            else {
                
                
                return true;
                
            }
            
        }
        
    }
    
}

void Date::save(ofstream &out) const {
    
    out << this;
    
}

bool Date::getValid() const {
    
    return this->valid;
    
}

ostream& operator<<(ostream& out, const Date &data) {
    
    if (data.getValid()) {
        out << data.getDay() << "/" << data.getMonth() << "/" << data.getYear();
    }
    
    else {
        
        out << "Data Inválida";
        
    }
    
    return out;
}

string Date::showDate() const {
    
    string finalDate = "";
    
    if (this->day < 10) {
        
        finalDate += '0';
        finalDate.append(to_string(this->day));
    }
    
    else {
        
        finalDate.append(to_string(this->day));
    }
    
    finalDate += '/';
    
    if (this->month < 10) {
        
        finalDate += '0';
        finalDate.append(to_string(this->month));
        
    }
    else {
        
        finalDate.append(to_string(this->month));
        
    }
    
    finalDate += '/';
    
    if (this->year == 0) {
        
        finalDate.append("0000");
        
    }
    else {
        
        finalDate.append(to_string(this->year));
    }
    
    return finalDate;
    
}

void Date::setCurrentDate() {
    
#ifdef __llvm__
    
    time_t t = time(NULL);
    tm* timePtr = localtime(&t);
    
    this->day = timePtr->tm_mday;
    this->month = (timePtr->tm_mon) + 1;
    this->year = timePtr->tm_year + 1900;
    
#elif _MSC_VER
    
    time_t t = time(NULL);
    struct tm timeInfo;
    localtime_s(&timeInfo, &t);
    
    this->day = timeInfo.tm_mday;
    this->month = (timeInfo.tm_mon) + 1;
    this->year = timeInfo.tm_year + 1900;
    
#endif
    
}



// ===========================================
// ==============  FUNCTIONS  ================
// ===========================================

void trimString(string &inputString) {


	//only for strings bigger than one char
	if (inputString.size() > 1) {

		//erase every ' ' char till it finds the fisrt that it is not ' '
		inputString.erase(0, inputString.find_first_not_of(" "));

		if (inputString == "")
			return;

		//while the last char is empty, it will be removed from the string
		while (inputString.at(inputString.size() - 1) == ' ') {

			inputString.pop_back();

		}
	}
}

bool validateName(string &nome) {

	trimString(nome);

	stringstream nomeStream(nome); //stringStream que contém o nome do cliente
	vector<string> nomes; //vector com a lista de nomes do cliente

						  //verificar se contém digitos

	for (size_t i = 0; i < nome.size(); i++) {

		if (isdigit((int)nome.at(i))) {

			cout << "O nome não pode conter digitos, apenas letras." << endl;
			return false;

		}

	}

	//preencher o vector com os nomes

	while (!nomeStream.eof()) {
		string nomeActual;
		getline(nomeStream, nomeActual, ' ');
		nomes.push_back(nomeActual);


	}

	//verificar se tem pelo menos dois nomes

	if (nomes.size() < 2) {

		cout << "O nome do cliente tem de ser constituído por pelo menos dois nomes" << endl;
		return false;

	}

	//verificar que cada nome tem pelo menos 3 letras

	for (size_t i = 0; i < nomes.size(); i++) {

		if (nomes.at(i).size() < 2) {

			cout << "Cada nome tem de conter pelo menos duas letras." << endl;
			return false;

		}
	}

	nome.at(0) = (char)toupper(nome.at(0));



	for (size_t i = 0; i < nome.size() - 1; i++) {

		if (nome.at(i) == ' ') {

			nome.at(i + 1) = toupper(nome.at(i + 1));

		}


	}

	return true;


}

string trimLink(string link) {

	string trimedString;

	for (size_t i = 0; i < link.length(); i++) {
		if (link[i] == '.')
			break;
		else
			trimedString += link[i];
	}

	return trimedString;
}
