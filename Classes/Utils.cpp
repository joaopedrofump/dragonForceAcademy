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

unsigned int operator-(const Date & date)
{
	Date currentDate(true);
	

	if (date.getMonth() > currentDate.getMonth())
	{
		return (currentDate.getYear() - date.getYear() - 1);
	}

	if (date.getMonth() == currentDate.getMonth())
	{
		if (date.getDay() > currentDate.getDay())
		{
			return (currentDate.getYear() - date.getYear() - 1);
		}
		else
		{
			return (currentDate.getYear() - date.getYear());
		}
	}
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

			int dif = spacesForColumn.at(i) - tableVector.at(x).at(i).length(); //espaços a mais
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
	denominator = 1;
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
	Fraction  result;
	result.numerator = (numerator * value.denominator) + (value.numerator*denominator);
	result.denominator = denominator * value.denominator;
	return result;

}

void Fraction::operator+=(Fraction &value) {
	this->numerator = (numerator * value.denominator) + (value.numerator*denominator);
	this->denominator = denominator * value.denominator;
}

Fraction Fraction::operator-(Fraction value) const {
	Fraction  result;
	result.numerator = (numerator * value.denominator) - (value.numerator*denominator);
	result.denominator = denominator * value.denominator;
	return result;
}

void Fraction::operator-=(Fraction &value) {
	this->numerator = (numerator * value.denominator) - (value.numerator*denominator);
	this->denominator = denominator * value.denominator;
}

Fraction Fraction::operator*(Fraction value) const {
	Fraction result;
	result.numerator = numerator * value.numerator;
	result.denominator = denominator * value.denominator;
	return result;
}

void Fraction::operator*=(Fraction &value) {
	this->numerator = numerator * value.numerator;
	this->denominator = denominator * value.denominator;
}

Fraction Fraction::operator/(Fraction value) const {
	Fraction result;
	result.numerator = numerator * value.denominator;
	result.denominator = denominator * value.numerator;
	return result;
}

void Fraction::operator/=(Fraction &value) {
	this->numerator = numerator * value.denominator;
	this->denominator = denominator * value.numerator;
}

//  Comparers

bool Fraction::operator<(Fraction value) const {
	double frac1;
	double frac2;
	frac1 = (numerator*1.0 / denominator);
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

void Fraction::operator|=(Fraction &value) {
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

bool leUnsignedShortInt(unsigned short int &input, unsigned short int min, unsigned short int  max, string mensagemErro) {

	string inputUser;
	bool resultadoBool = false;

	Table tabelaMensagemErro({ mensagemErro });

	getline(cin, inputUser);
	stringstream inteirosStream(inputUser);
	trimString(inputUser);

	if (inputUser.size() == 0) {

		input = 0;
		return true;

	}

	while (!inteirosStream.eof()) {

		unsigned short int currentInt;
		inteirosStream >> currentInt;

		if (inteirosStream.fail()) {

			inteirosStream.clear();
			inteirosStream.ignore(1);


		}

		else {

			input = currentInt;
			resultadoBool = true;
			break;

		}


	}

	if (!resultadoBool) {

		cout << tabelaMensagemErro << endl;


	}

	return resultadoBool;


}

// ===========================================
// ===========  ENUMS & MAPS =================
// ===========================================

extern const map<string, CoachType> coachTypeMap = { { "HDC", HeadCoach },
{ "ASC", AssistantCoach },
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
    
    if(originalStr == "/") {
        return "\\";
    }
    
    vector<string> dirs;
    while (true) {
        
        dirs.push_back(originalStr.substr(0, originalStr.find('/', 0)));
        
        originalStr = originalStr.substr(originalStr.find('/', 0) + 1);
        
        if (originalStr == originalStr.substr(originalStr.find('/', 0) + 1)) {
            
            dirs.push_back(originalStr);
            break;
        }
        
    }
    
    string result;
    
    for (size_t i = 0; i < dirs.size() - 1; i++) {
        result = result + dirs.at(i) + "\\";
    }
    result = result + dirs.at(dirs.size() - 1);
    
    return result;
    
}
