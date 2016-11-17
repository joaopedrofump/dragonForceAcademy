//
//  Utils.cpp
//  DragonForceAcadamy
//
//  Created by Joao Furriel on 13/10/16.
//  Copyright © 2016 João Furriel Pinheiro. All rights reserved.
//

#include "Utils.hpp"

string path() {
	
#ifdef __llvm__

	string path = "";

#elif _MSC_VER

	string path = "..\\Debug\\";

#endif
	return path;
}


// ===========================================
// ==============  DATE  =====================
// ===========================================

// date in form DD/MM/YYYY

Date::Date() {
        
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
        this->month= (timeInfo.tm_mon) + 1;
        this->year = timeInfo.tm_year + 1900;
        
#endif
    
    
}

Date::Date(string dataStr) {
    
    stringstream dataStream(dataStr);
    char separator1;
    char separator2;
    int tmpDay;
    int tmpMonth;
    int tmpYear;
    
    dataStream >> tmpDay;
    dataStream >> separator1;
    dataStream >> tmpMonth;
    dataStream >> separator2;
    dataStream >> tmpYear;
    
    if (separator1 != '/' || separator2 != '/') {
        
        throw InvalidDate(InvalidSeparators,0,0,0);
        
    }
    
    *this = Date(tmpDay,tmpMonth,tmpYear);
    
}

Date::Date(unsigned int day, unsigned int month, unsigned int year) {
    
    if (year < 1900 || year > 2100) {
        throw InvalidDate(InvalidYear, day, month, year);
    }
    
    if (month <= 0 || month > 12) {
        
        throw InvalidDate(InvalidMonth, day, month, year);
    }
    
    if ((day <= 0) || (day  > numDays(month, year))) {
        
        throw InvalidDate(InvalidDay, day, month, year);
    }
    
    this->day = day;
    this->month = month;
    this->year = year;
    
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
    
    if ((day <= 0) || (day  > numDays(this->month, this->year))) {
        
        throw InvalidDate(InvalidDay, day, this->month, this->year);
    }
    
    this->day = day;
    
}

void Date::setMonth(int month) {
    
    if (month <= 0 || month > 12) {
        
        throw InvalidDate(InvalidYear, this->day, month, this->year);
    }
    
    if ((this->day <= 0) || (this->day  > numDays(month, this->year))) {
        
        throw InvalidDate(InvalidDay, this->day, month, this->year);
    }
    
    this->month = month;
}

void Date::setYear(int year) {
    
    if (year < 1900) {
        throw InvalidDate(InvalidYear, this->day, this->month, year);
    }
    
    if ((this->day <= 0) || (this->day  > numDays(this->month, year))) {
        
        throw InvalidDate(InvalidDay, day, this->month, year);
    }
    
    this->year = year;
}

bool Date::isLeap(int year) const {
    
    if (year % 400 == 0) {
        return true;
    }
    
    else {
        
        if (year % 4 == 0 && year % 100 != 0) {
            return true;
        }
        
        else {
            return false;
        }
    }
}

int Date::numDays(int month, int year) const {
    
    switch (month) {
        case 4: case 6: case 9: case 11:
            return 30;
            break;
        case 2:
            if (this->isLeap(year)) {
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

bool operator<(const Date &date1, const Date &date2) {
    return !(date1 >= date2);
}

bool operator==(const Date &date1, const Date &date2) {
	return (!(date1 < date2) && !(date2 < date1));
}

void Date::save(ofstream &out) const {
    
    out << this;
    
}

ostream& operator<<(ostream& out, const Date &data) {
    
    out << data.getDay() << "/" << data.getMonth() << "/" << data.getYear();
    return out;
}

int operator-(const Date &date1, const Date &date2)
{
	
	if (date2.getMonth() > date1.getMonth())
	{
		return (date1.getYear() - date2.getYear() - 1);
	}

	if (date2.getMonth() == date1.getMonth())
	{
		if (date2.getDay() > date1.getDay())
		{
			return (date1.getYear() - date2.getYear() - 1);
		}
		else
		{
			return (date1.getYear() - date2.getYear());
		}
	}
    
    return date1.getYear() - date2.getYear();
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

string Date::str() const {
    return this->showDate();
}




// ===========================================
// ===============  TABLE  ===================
// ===========================================

Table::Table(vector<string> components, unsigned int indentacao) {

	vector<int> spaces;
	for (size_t i = 0; i < components.size(); i++) {
		spaces.push_back((int)components.at(i).length());
	}
	formatTable('_', ' ', spaces, indentacao);
	formatTable(' ', '|', spaces, indentacao);
	tableStream << string(indentacao, ' ') << " |  ";
	for (int i = 0; i < components.size(); i++) {
		tableStream << components.at(i) << "  |  ";
	}
	tableStream << endl;
	formatTable('_', '|', spaces, indentacao);

	numColumns = (int)components.size();
	numLines = 1;
	columnsWidth = spaces;
	lastLineComponents = components;
	tableVector.push_back(components);
	blocks.push_back(true);

	indent = indentacao;
}

Table::Table(vector<string> components, vector<int> spacesForColumn, unsigned int indentacao) {
	formatTable('_', ' ', spacesForColumn, indentacao);
	formatTable(' ', '|', spacesForColumn, indentacao);
	tableStream << string(indentacao, ' ') << " |  ";
	for (int i = 0; i < components.size(); i++) {
		tableStream << components.at(i) << string(spacesForColumn.at(i) - components.at(i).length(), ' ') << "  |  ";
	}
	tableStream << endl;
	formatTable('_', '|', spacesForColumn, indentacao);

	numColumns = (int)components.size();
	numLines = 1;
	columnsWidth = spacesForColumn;
	lastLineComponents = components;
	tableVector.push_back(components);

	this->indent = indentacao;
}

Table::Table(vector<vector<string>> tableVector, vector<bool> blocks, vector<int> spacesForColumn, unsigned int indentacao) {

	unsigned int numColumnsV = 0;
	vector<int> columnsSizes;
	for (size_t i = 0; i < tableVector.size(); i++) {
		if (numColumnsV < tableVector.at(i).size()) {
			numColumnsV = (int)tableVector.at(i).size();
		}
	}
	for (int j = 0; j < numColumnsV; j++) {
		columnsSizes.push_back(0);
	}
	formatTable('_', ' ', spacesForColumn, indentacao);
	formatTable(' ', '|', spacesForColumn, indentacao);
	for (int x = 0; x < tableVector.size(); x++) {
		if (tableVector.at(x).size() < numColumnsV) {
			tableVector.at(x).push_back("");
		}

		tableStream << string(indentacao, ' ') << " |  ";

		for (unsigned int i = 0; i < numColumnsV; i++) {

			int dif = spacesForColumn.at(i) - (unsigned int)tableVector.at(x).at(i).length(); //espaços a mais
			string temporario;
			if (dif > 0) {
				temporario = string(spacesForColumn.at(i) - tableVector.at(x).at(i).length(), ' ');
			}
			else {
				temporario = string(tableVector.at(x).at(i).length() - spacesForColumn.at(i), ' ');
			}

			tableStream << tableVector.at(x).at(i) << temporario << "  |  ";
		}
		tableStream << endl;

		if (blocks.at(x)) {
			formatTable('_', '|', spacesForColumn, indentacao);
			//formatTable(' ', '|', spacesForColumn, indentacao);
			if (x < tableVector.size() - 1) {
				//formatTable('_', '|', spacesForColumn, indentacao);
				formatTable(' ', '|', spacesForColumn, indentacao);
			}
		}
	}


	this->blocks = blocks;
	this->tableVector = tableVector;
	this->columnsWidth = spacesForColumn;
	this->numColumns = numColumnsV;
	this->numLines = (int)tableVector.size();
	this->lastLineComponents = tableVector.at(tableVector.size() - 1);
	this->indent = indentacao;
}

void Table::addNewLine(vector<string> components) {
	if (components.size() < this->numColumns) {  //Verifica se vector componentes tem menor nÃºmero de termos
		for (size_t x = components.size(); x < numColumns; x++) {  //da tabela original e adiciona nesse caso.
			components.push_back("");
		}
	}
	if (components.size() > this->numColumns) {  //Verifica se vector componentes tem maior nÃºmero de termos
		for (int x = numColumns; x < components.size(); x++) { //da tabela original e remove-os, nesse caso.
			components.pop_back();
		}
	}
	vector<int> spaces;
	for (size_t i = 0; i < components.size(); i++) {
		if (components.at(i).length() >= this->columnsWidth.at(i)) {
			spaces.push_back((int)components.at(i).length());
		}
		else {
			spaces.push_back(columnsWidth.at(i));
		}
	} //Redefine a largura das colunas para a tabela alterada
	tableStream.str(string());
	tableStream.clear();
	Table newTable(this->tableVector, this->blocks, spaces, this->indent); //Reconstroi a tabela anterior com a largura das colunas redefinida
	tableStream << newTable;
	formatTable(' ', '|', spaces, this->indent);
	tableStream << string(this->indent, ' ') << " |  ";
	for (int i = 0; i < components.size(); i++) {
		tableStream << components.at(i) << string(spaces.at(i) - components.at(i).length(), ' ') << "  |  ";
	}
	tableStream << endl;
	formatTable('_', '|', spaces, this->indent);

	numLines++;
	this->lastLineComponents = components;
	this->tableVector.push_back(components);
	this->columnsWidth = spaces;
	this->blocks.push_back(true);
}

void Table::addDataInSameLine(vector<string> components) {

	if (components.size() < this->numColumns) {  //Verifica se vector componentes tem menor nÃºmero de termos
		for (size_t x = components.size(); x < numColumns; x++) {  //da tabela original e adiciona nesse caso.
			components.push_back("");
		}
	}
	if (components.size() > this->numColumns) {  //Verifica se vector componentes tem maior nÃºmero de termos
		for (int x = numColumns; x < components.size(); x++) { //da tabela original e remove-os, nesse caso.  MELHORAR!!!
			components.pop_back();
		}
	}
	vector<int> spaces;
	for (size_t i = 0; i < components.size(); i++) {
		if (components.at(i).length() >= this->columnsWidth.at(i)) {
			spaces.push_back((int)components.at(i).length());
		}
		else {
			spaces.push_back(columnsWidth.at(i));
		}
	} //Redefine a largura das colunas para a tabela alterada

	tableStream.str(string());
	tableStream.clear();
	tableVector.push_back(components);
	blocks.pop_back();
	blocks.push_back(false);

	blocks.push_back(true); //concatena a penultima linha com a œltima

	Table newTable(this->tableVector, this->blocks, spaces); //Reconstroi a tabela anterior com a largura das colunas redefinida
	tableStream << newTable;
	/*tableStream << " |  ";
	for (int i = 0; i < components.size(); i++){
	tableStream << components.at(i) << string(spaces.at(i) - components.at(i).length(), ' ') << "  |  ";
	}
	tableStream << endl;
	formatTable('_', '|', spaces);*/

	this->columnsWidth = spaces;
}

void Table::formatTable(char internalChar, char limitingChar, vector<int> spacesForColumn, unsigned int indentacaoFT) {
	tableStream << string(indentacaoFT, ' ') << " " << limitingChar;
	for (size_t i = 0; i < spacesForColumn.size(); i++) {
		for (int x = 0; x < spacesForColumn.at(i) + 4; x++) {
			tableStream << internalChar;
		}
		tableStream << limitingChar;
	}
	tableStream << endl;
}

vector<int> Table::getColumsWidth() const {
	return columnsWidth;
}

unsigned int Table::getIndentacao() const {
	return indent;
}

vector<vector<string>> Table::getTableVector() const {
	return this->tableVector;
}

vector<bool> Table::getBlocks() const {
	return this->blocks;
}

ostream& operator<<(ostream& out, const Table &tableToShow) {
	out << tableToShow.tableStream.str();
	//formatTableShow('_', '|', tableToShow.getColumsWidth(), tableToShow.getIndentacao(), out);
	return out;
}

//=================================
//=========  FRACTION  ============
//=================================

Fraction::Fraction() {
	numerator = 0;
	denominator = 0;
}

Fraction::Fraction(int newNumerator, int newDenominator) {
	numerator = newNumerator;
	denominator = newDenominator;
}

Fraction::Fraction(string fractionString) {
	string tmpString = fractionString;
	numerator = atoi(tmpString.substr(0, tmpString.find('/', 0)).c_str());
	tmpString = tmpString.substr(tmpString.find('/', 0) + 1);
	denominator = atoi(tmpString.c_str());
}

void Fraction::reduce() {

	if (numerator == 0 && denominator == 0)
		return;

	int num = numerator;
	int den = denominator;

	if (num>den) {
		for (int counter = 2; counter<den; counter++) {
			while (num%counter == 0 & den%counter == 0) {
				num = (num / counter);
				den = (den / counter);
			}
		}
	}
	else if (den > num) {
		for (int counter = 2; counter<num; counter++) {
			while (num%counter == 0 & den%counter == 0) {
				num = (num / counter);
				den = (den / counter);
			}
		}
	}

	this->numerator = num;
	this->denominator = den;
}

//  Operations as fractions

Fraction Fraction::operator+(Fraction value) const {
	if ((numerator == 0 && denominator == 0) | (value.numerator == 0 && value.denominator == 0))
		return *this;
	
	Fraction  result;
	result.numerator = (numerator * value.denominator) + (value.numerator*denominator);
	result.denominator = denominator * value.denominator;
	return result;

}

void Fraction::operator+=(Fraction &value) {
	if ((numerator == 0 && denominator == 0) | (value.numerator == 0 && value.denominator == 0))
		return;

	this->numerator = (numerator * value.denominator) + (value.numerator*denominator);
	this->denominator = denominator * value.denominator;
}

Fraction Fraction::operator-(Fraction value) const {
	if ((numerator == 0 && denominator == 0) | (value.numerator == 0 && value.denominator == 0))
		return *this;

	Fraction  result;
	result.numerator = (numerator * value.denominator) - (value.numerator*denominator);
	result.denominator = denominator * value.denominator;
	return result;
}

void Fraction::operator-=(Fraction &value) {
	if ((numerator == 0 && denominator == 0) | (value.numerator == 0 && value.denominator == 0))
		return;

	this->numerator = (numerator * value.denominator) - (value.numerator*denominator);
	this->denominator = denominator * value.denominator;
}

Fraction Fraction::operator*(Fraction value) const {
	if ((numerator == 0 && denominator == 0) | (value.numerator == 0 && value.denominator == 0))
		return *this;

	Fraction result;
	result.numerator = numerator * value.numerator;
	result.denominator = denominator * value.denominator;
	return result;
}

void Fraction::operator*=(Fraction &value) {
	if ((numerator == 0 && denominator == 0) | (value.numerator == 0 && value.denominator == 0))
		return;

	this->numerator = numerator * value.numerator;
	this->denominator = denominator * value.denominator;
}

Fraction Fraction::operator/(Fraction value) const {
	if ((numerator == 0 && denominator == 0) | (value.numerator == 0 && value.denominator == 0))
		return *this;

	Fraction result;
	result.numerator = numerator * value.denominator;
	result.denominator = denominator * value.numerator;
	return result;
}

void Fraction::operator/=(Fraction &value) {
	if ((numerator == 0 && denominator == 0) | (value.numerator == 0 && value.denominator == 0))
		return;
	
	this->numerator = numerator * value.denominator;
	this->denominator = denominator * value.numerator;
}

//  Comparers

bool Fraction::operator<(Fraction value) const {


	double frac1;
	double frac2;
	if (denominator == 0)
		frac1 = (numerator*1.0 / denominator + 1);
	else
		frac1 = (numerator*1.0 / denominator);

	if (denominator == 0)
		frac2 = (value.numerator*1.0 / value.denominator + 1);
	else
		frac2 = (value.numerator*1.0 / value.denominator);

	
	return frac1 < frac2;
}

bool Fraction::operator==(Fraction value) const {
	return (numerator*1.0 / denominator) == (value.numerator*1.0 / value.denominator);
}

bool Fraction::operator>=(Fraction value) const {
	return !this->operator<(value);
}

bool Fraction::operator>(Fraction value) const {
	double frac1;
	double frac2;
	frac1 = (numerator*1.0 / denominator);
	frac2 = (value.numerator*1.0 / value.denominator);
	return frac1 > frac2;
}

bool Fraction::operator<=(Fraction value) const {
	return !this->operator>(value);
}

//  Operations as Ratio

Fraction Fraction::operator|(Fraction value) const {
	Fraction result;
	result.numerator = numerator + value.numerator;
	result.denominator = denominator + value.denominator;
	return result;

}

void Fraction::operator|=(const Fraction &value) {
	this->numerator = numerator + value.numerator;
	this->denominator = denominator + value.denominator;
}

Fraction& Fraction::operator++ () {    // prefix ++
	this->numerator += 1;
	this->denominator += 1;
	return *this;
}

Fraction Fraction::operator++ (int) { // postfix ++
	Fraction result(*this);
	++(*this);
	return result;
}

//  Console functions

void Fraction::print(bool originalFraction) const {
	int num = numerator;
	int den = denominator;

	if (!originalFraction) {
		if (num>den) {
			for (int counter = 2; counter<den; counter++) {
				while (num%counter == 0 & den%counter == 0) {
					num = (num / counter);
					den = (den / counter);
				}
			}
		}
		else if (den > num) {
			for (int counter = 2; counter<num; counter++) {
				while (num%counter == 0 & den%counter == 0) {
					num = (num / counter);
					den = (den / counter);
				}
			}
		}
	}

	cout << num << "/" << den;
}

void Fraction::printPercentage() const {
	double number = numerator*1.0 / denominator;

	cout << fixed << setprecision(2) << 100 * number << "%";
}

string Fraction::getFrac() const {
    
    return (to_string(this->numerator) + "/" +  to_string(this->denominator));
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

bool validateName(string &name) {

	trimString(name);

	stringstream nomeStream(name); //stringStream that contains the name
	vector<string> names; //vector with a list of names

	//verify if it contains digits

	for (size_t i = 0; i < name.size(); i++) {

		if (isdigit((int)name.at(i))) {

			throw InvalidInput("The name cannot contain digits, only letters.");
			return false;

		}

	}

	//fill the vector with the names

	while (!nomeStream.eof()) {
		string currentName;
		getline(nomeStream, currentName, ' ');
		names.push_back(currentName);


	}

	//verify if it contains at least two names

	if (names.size() < 2) {

		throw InvalidInput("The name must be comprised of at least two names.");
		return false;

	}

	//verify if each name contains at least two letters

	for (size_t i = 0; i < names.size(); i++) {

		if (names.at(i).size() < 2) {

			throw InvalidInput("Each name must contain at least two letters.");
			return false;

		}
	}

	name.at(0) = (char)toupper(name.at(0));


	for (size_t i = 0; i < name.size() - 1; i++) {

		if (name.at(i) == ' ') {

			name.at(i + 1) = toupper(name.at(i + 1));
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

void clearScreen() {

#ifdef __llvm__

	system("clear");

#elif _MSC_VER

	system("cls");

#endif

}

void SetCursor(int column, int line)

{

#ifdef _MSC_VER
	COORD coord;
	coord.X = column;
	coord.Y = line;
	SetConsoleCursorPosition(
		GetStdHandle(STD_OUTPUT_HANDLE),
		coord
		);

#endif
}

int GetCursorX()
{

#ifdef _MSC_VER
	CONSOLE_SCREEN_BUFFER_INFO SBInfo;
	COORD                      result;
	if (!GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &SBInfo))
		return -1;


	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &SBInfo);

	return SBInfo.dwCursorPosition.X;
#endif

	return 1;
}

int GetCursorY()
{

#ifdef _MSC_VER
	CONSOLE_SCREEN_BUFFER_INFO SBInfo;
	COORD                      result;
	if (!GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &SBInfo))
		return -1;


	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &SBInfo);

	return SBInfo.dwCursorPosition.Y;

#endif

	return 1;
}

void ignoreLine(bool ignoreControl, string message) {

	string temp;
	Table tableEnter({ message });
	cout << tableEnter << endl;
	if (ignoreControl) {

		cin.ignore(1000, '\n');

	}
	getline(cin, temp);


}

bool readUnsignedInt(unsigned int &input, unsigned int min, unsigned int  max, string errorMessage) {

	string inputUser;
	bool result = false;

	Table tableErrorMessage({ errorMessage });

	getline(cin, inputUser);
	stringstream integersStream(inputUser);
	trimString(inputUser);

	if (inputUser.size() == 0) {

		input = 0;
		return true;
	}

	while (!integersStream.eof()) {

		unsigned int currentInt;
		integersStream >> currentInt;

		if (integersStream.fail()) {

			integersStream.clear();
			integersStream.ignore(1);
		}
		else if (currentInt > max || currentInt < min) {
			throw InvalidInput(errorMessage);
		}
		else{
			input = currentInt;
			result = true;
			break;
		}
	}

	if (!result) {

		throw InvalidInput(errorMessage);
	}

	return result;
}

bool readDates(vector<Date> &resultVector, string message, string errorMessage) {


	string dates;
	bool resultBool = false;



	Table tableMessage({ message });
	Table tableErrorMessage({ errorMessage });
	cout << tableMessage << endl;
	getline(cin, dates);
	stringstream datesStream(dates);
	trimString(dates);

	if (dates.size() == 0) {

		return true;
	}

	while (!datesStream.eof()) {

		string currentDateStr;
		getline(datesStream, currentDateStr, ' ');

		Date currentDate(currentDateStr);

		resultVector.push_back(currentDate);
		resultBool = true;

		if (resultVector.size() == 2) {

			resultBool = true;

		}
	}

	if (!resultBool) {

		cout << tableErrorMessage << endl;
	}

	return resultBool;

}

bool readDate(Date &result, string message, string errorMessage) {

	cout << Table({ message });
	 
	string input;

	getline(cin, input);

	if (input.size() == 0) {

		return true;
	}

	result = Date(input);

	return true;
}

bool readDate(Date &result, Date min, Date max, string message, string errorMessage) {

	cout << Table({ message });

	string input;

	getline(cin, input);

	if (input.size() == 0) {

		return true;
	}
	trimString(input);
	if (Date(input) < min) {
		throw InvalidDate("The date cannot be earlier than " + min.str(), min.getDay(), min.getMonth(), min.getYear());
	}
	if (max < Date(input)) {
		throw InvalidDate("The date cannot be later than " + max.str(), max.getDay(), max.getMonth(), max.getYear());
	}



	result = Date(input);

	return true;
}


bool emptyString(string stringTest) {

	if (stringTest.size() == 0) {
		return true;
	}
	return false;
}

// ===========================================
// ===========  ENUMS & MAPS =================
// ===========================================
extern const map<string, ageLevel> ageLevelMap = { { "Seniors", Seniors },
{ "U13", U13 },
{ "U15", U15 },
{ "U17", U17 },
{ "U19", U19 } };

extern const map<string, CoachType> coachTypeMap = { { "HDC", HeadCoach },
{ "GKC", GoalkeeperCoach },
{ "PHT", PhysicalTrainer } };

extern const map<string, Position> positionsMap = { { "GK", GoalkeeperPos },
{ "DF", DefenderPos },
{ "MF", MidfielderPos },
{ "FW", ForwardPos } };

extern const map<string, DefenderPosition> defendersMap = { { "CB", CenterBack },
{ "LB", LeftBack },
{ "RB", RightBack } };

extern const map<string, MidfielderPosition> midfieldersMap = { { "CM", CentreMidfielder },
{ "CDM", DefensiveMidfielder },
{ "CAM", AttackingMidfielder },
{ "LM", LeftMidfield },
{ "RM", RightMidfield } };

extern const map<string, ForwardPosition> forwardsMap = { { "CM", Striker },
{ "CDM", CentreForward },
{ "CAM", RigthWinger },
{ "LM", LeftWinger } };


int createDirectory(const char* path) {
    
#ifdef __llvm__
    
    mkdir(path, 0777);
    return 0;

#elif _MSC_VER
    
    _mkdir(path);
    return 0;

#endif
    
}

string stringPath(string originalStr) {
    
#ifdef __llvm__
    
    return originalStr;
#endif

	string result = "";

	for (size_t i = 0; i < originalStr.size(); i++) {

		if (originalStr.at(i) == '/') {

			result += "\\";

		}
		else {
			result += originalStr.at(i);
		}

	}

	return result;
    
}

string getLevelFromAge(Date birthDate) {
    
    unsigned int age = Date() - birthDate;
    
    if (age < 13)
        return "Under 13";
    
    else if (age >= 13 && age < 15)
        return "Under 15";
    
    else if (age >= 15 && age < 17)
        return "Under 17";
    
    else if (age >= 17 && age < 19)
        return "Under 19";
    
    else if (age >= 19 && age < 45)
        return "Seniors";
    
    else
        return "No Level available";
}

string readAndCut(string &stringToCut) {

	/*stringstream ss(stringToCut);

	string result;
	string separator;

	ss >> result;
	ss >> separator;

	stringToCut = ss.str();*/

	string result = stringToCut.substr(0, stringToCut.find(';', 0) - 1);

	stringToCut = stringToCut.substr(stringToCut.find(';', 0) + 2);

	return result;
}

string normalizeId(unsigned int digits, unsigned int id) {
    
    string idString = to_string(id);
    if (idString.length() >= digits) {
        return idString;
    }
    size_t diff = digits - idString.length();
    string tmp;
    while (diff-- > 0) {
        tmp += '0';
    }
    return tmp + idString;
    
}
