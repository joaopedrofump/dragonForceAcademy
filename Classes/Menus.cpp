/*

João Pinheiro
Leonardo Teixeira

*/

#include "Menus.h"
#include "Season.hpp"

using namespace std;

void initialInfo(string &clubName) {

    clearScreen();
    ifstream inStreamClub;
    bool clubExists;
	string clubNameFromUser;
    
    cout << Table({ "Please, insert the name of the club or Enter to create a new one." });
    getline(cin, clubNameFromUser);
    
	if (clubNameFromUser != "") {
        
		inStreamClub.open((path() + clubNameFromUser + stringPath("/club.txt")).c_str());
		clubExists = inStreamClub.good();
        
        if(!clubExists) {
            string s = "Could not read file";
            throw InvalidStream((path() + clubNameFromUser + stringPath("/club.txt")), read);
        }
        
        clubName = clubNameFromUser;
		inStreamClub.close();

	}
		
	else {
		
        clearScreen();
        string newClubName;
        cout << Table({ "Ok. Let's create the club. Please, insert the name for the new club or press Enter to close." });
        getline(cin, newClubName);
        
        if (!newClubName.size()) {
            
            return;
            
        }
        
        clearScreen();
        
        clubName = newClubName;
        
        if(!createDirectory((path() + clubName).c_str())) {
			clearScreen();
			cout << Table({ "Folder correctly created!" });
        }
        Date currentDate;
        string year = to_string(currentDate.getYear());
		ofstream outfileClub((path() + clubName) + stringPath("/club.txt"));
		outfileClub << clubName << endl;
        outfileClub << year;
		outfileClub.close();
        ofstream outfileCoaches((path() + clubName) + stringPath("/coaches.txt"));
        outfileCoaches.close();
        ofstream outfileAthletes((path() + clubName) + stringPath("/athletes.txt"));
        outfileAthletes.close();
        
        
        //create folders for current season and levels
        createDirectory(stringPath((path() + clubName + "/" + year)).c_str());
        createDirectory(stringPath((path() + clubName + "/" + year + "/" + "U13")).c_str());
        createDirectory(stringPath((path() + clubName + "/" + year + "/" + "U15")).c_str());
        createDirectory(stringPath((path() + clubName + "/" + year + "/" + "U17")).c_str());
        createDirectory(stringPath((path() + clubName + "/" + year + "/" + "U19")).c_str());
        createDirectory(stringPath((path() + clubName + "/" + year + "/" + "Seniors")).c_str());
        
        createDirectory(stringPath((path() + clubName + "/" + year + "/" + "U13" + "/Matches")).c_str());
        createDirectory(stringPath((path() + clubName + "/" + year + "/" + "U15" + "/Matches")).c_str());
        createDirectory(stringPath((path() + clubName + "/" + year + "/" + "U17" + "/Matches")).c_str());
        createDirectory(stringPath((path() + clubName + "/" + year + "/" + "U19" + "/Matches")).c_str());
        createDirectory(stringPath((path() + clubName + "/" + year + "/" + "Seniors" + "/Matches")).c_str());
        
        createDirectory(stringPath((path() + clubName + "/" + year + "/" + "U13" + "/Tournaments")).c_str());
        createDirectory(stringPath((path() + clubName + "/" + year + "/" + "U15" + "/Tournaments")).c_str());
        createDirectory(stringPath((path() + clubName + "/" + year + "/" + "U17" + "/Tournaments")).c_str());
        createDirectory(stringPath((path() + clubName + "/" + year + "/" + "U19" + "/Tournaments")).c_str());
        createDirectory(stringPath((path() + clubName + "/" + year + "/" + "Seniors" + "/Tournaments")).c_str());
        
        //create info files for levels
        ofstream outfileInfoLevel(stringPath(path() + clubName + "/" + year + "/U13" + "/Athletes.txt").c_str());
        outfileInfoLevel.close();
        outfileInfoLevel.open(stringPath(path() + clubName + "/" + year + "/U13" + "/Coaches.txt").c_str());
        outfileInfoLevel.close();
        outfileInfoLevel.open(stringPath(path() + clubName + "/" + year + "/U13" + "/Matches.txt").c_str());
        outfileInfoLevel.close();
        outfileInfoLevel.open(stringPath(path() + clubName + "/" + year + "/U13" + "/Trainings.txt").c_str());
        outfileInfoLevel.close();
        outfileInfoLevel.open(stringPath(path() + clubName + "/" + year + "/U13" + "/Tournaments.txt").c_str());
        outfileInfoLevel.close();
        outfileInfoLevel.open(stringPath(path() + clubName + "/" + year + "/U15" + "/Athletes.txt").c_str());
        outfileInfoLevel.close();
        outfileInfoLevel.open(stringPath(path() + clubName + "/" + year + "/U15" + "/Coaches.txt").c_str());
        outfileInfoLevel.close();
        outfileInfoLevel.open(stringPath(path() + clubName + "/" + year + "/U15" + "/Matches.txt").c_str());
        outfileInfoLevel.close();
        outfileInfoLevel.open(stringPath(path() + clubName + "/" + year + "/U15" + "/Trainings.txt").c_str());
        outfileInfoLevel.close();
        outfileInfoLevel.open(stringPath(path() + clubName + "/" + year + "/U15" + "/Tournaments.txt").c_str());
        outfileInfoLevel.close();
        outfileInfoLevel.open(stringPath(path() + clubName + "/" + year + "/U17" + "/Athletes.txt").c_str());
        outfileInfoLevel.close();
        outfileInfoLevel.open(stringPath(path() + clubName + "/" + year + "/U17" + "/Coaches.txt").c_str());
        outfileInfoLevel.close();
        outfileInfoLevel.open(stringPath(path() + clubName + "/" + year + "/U17" + "/Matches.txt").c_str());
        outfileInfoLevel.close();
        outfileInfoLevel.open(stringPath(path() + clubName + "/" + year + "/U17" + "/Trainings.txt").c_str());
        outfileInfoLevel.close();
        outfileInfoLevel.open(stringPath(path() + clubName + "/" + year + "/U17" + "/Tournaments.txt").c_str());
        outfileInfoLevel.close();
        outfileInfoLevel.open(stringPath(path() + clubName + "/" + year + "/U19" + "/Athletes.txt").c_str());
        outfileInfoLevel.close();
        outfileInfoLevel.open(stringPath(path() + clubName + "/" + year + "/U19" + "/Coaches.txt").c_str());
        outfileInfoLevel.close();
        outfileInfoLevel.open(stringPath(path() + clubName + "/" + year + "/U19" + "/Matches.txt").c_str());
        outfileInfoLevel.close();
        outfileInfoLevel.open(stringPath(path() + clubName + "/" + year + "/U19" + "/Trainings.txt").c_str());
        outfileInfoLevel.close();
        outfileInfoLevel.open(stringPath(path() + clubName + "/" + year + "/U19" + "/Tournaments.txt").c_str());
        outfileInfoLevel.close();
        outfileInfoLevel.open(stringPath(path() + clubName + "/" + year + "/Seniors" + "/Athletes.txt").c_str());
        outfileInfoLevel.close();
        outfileInfoLevel.open(stringPath(path() + clubName + "/" + year + "/Seniors" + "/Coaches.txt").c_str());
        outfileInfoLevel.close();
        outfileInfoLevel.open(stringPath(path() + clubName + "/" + year + "/Seniors" + "/Matches.txt").c_str());
        outfileInfoLevel.close();
        outfileInfoLevel.open(stringPath(path() + clubName + "/" + year + "/Seniors" + "/Trainings.txt").c_str());
        outfileInfoLevel.close();
        outfileInfoLevel.open(stringPath(path() + clubName + "/" + year + "/Seniors" + "/Tournaments.txt").c_str());
        outfileInfoLevel.close();
        
	}

}

bool confirm(const Table &message) {

	unsigned int confirmResult = 1;
	bool control = false;
	while (!control) {
		try {

			cout << message << endl;

			cout << Table(vector<string>{ "1. YES", "2. NO" });

			control = readUnsignedInt(confirmResult, 0, 2);

		}
		catch (InvalidInput e) {

			showMainMenu(0);

			cout << Table({ e.getMessage() });

		}
	}

	switch (confirmResult) {
	case 0:
		confirmResult = 1;
		break;
	case 1:
		confirmResult = 1;
		break;
	case 2:
		confirmResult = 0;
		break;
	}

	return confirmResult;

}


/******************************************
* Initial Menu
******************************************/



void initialOptions(Club &mainClub) {
    unsigned int option;
	
	Season* currentSeason = 0;

	vector<Season*> tmpVector = mainClub.getSeasons();
	for (vector<Season*>::iterator i = tmpVector.begin(); i != tmpVector.end(); i++) {
		if ((*i)->getYear() == Date().getYear()) {
			currentSeason = *i;
			break;
		}
	}


    while ((option = mainMenu(currentSeason->getSeasonName())))
        switch (option) {
            case 1: optionsAthletesManagement(mainClub, currentSeason->getSeasonName());
                break;
            case 2: optionsCoachesManagement(mainClub, currentSeason->getSeasonName());
                break;
            case 3: optionsLevelsManagement(mainClub, currentSeason, currentSeason->getLevels().at(0));
                break;
            case 4: optionsLevelsManagement(mainClub, currentSeason, currentSeason->getLevels().at(1));
                break;
            case 5: optionsLevelsManagement(mainClub, currentSeason, currentSeason->getLevels().at(2));
                break;
            case 6: optionsLevelsManagement(mainClub, currentSeason, currentSeason->getLevels().at(3));
                break;
            case 7: optionsLevelsManagement(mainClub, currentSeason, currentSeason->getLevels().at(4));
                break;
            case 0:
                break;
        }
    //supermercado.saveChanges();
}

unsigned short int mainMenu(string seasonName) {
    unsigned int option = 0;
    bool control = false;
	Table closeProgram({ "Are you sure you want to quit the program?" });

	showMainMenu(0, seasonName);

    while (!control) {
		try {
			control = readUnsignedInt(option, 0, 8);
		}
		catch (InvalidInput e) {
			showMainMenu();

			cout << Table({ e.getMessage() });
		}
    }

	if (option == 0 && !confirm(closeProgram)) {
		option = 8;
	}
    return option;
}

void showMainMenu(unsigned short int opcaoChosen, string seasonName) {
    clearScreen();
	Table menu({ "Main Menu", "Current Season: " + seasonName });
    vector<string> headerMenu;
    switch (opcaoChosen) {
        case 0:
			headerMenu = { "1 - Athletes", "2 - Coaches", "3 - U13", "4 - U15", "5 - U17", "6 - U19", "7 - Seniors", "8 - Change Season", "0 - Exit" };
            break;
        case 1:
			headerMenu = { "1 - Athletes" + string(13, ' '), "2 - Coaches", "3 - U13", "4 - U15", "5 - U17", "6 - U19", "7 - Seniors", "8 - Change Season", "0 - Exit" };
            break;
        case 2:
			headerMenu = { "1 - Athletes", "2 - Coaches" + string(10, ' '), "3 - U13", "4 - U15", "5 - U17", "6 - U19", "7 - Seniors", "8 - Change Season", "0 - Exit" };
			break;
        case 3:
			headerMenu = { "1 - Athletes", "2 - Coaches", "3 - U13" + string(14, ' '), "4 - U15", "5 - U17", "6 - U19", "7 - Seniors", "8 - Change Season", "0 - Exit" };
			break;
		case 4:
			headerMenu = { "1 - Athletes", "2 - Coaches", "3 - U13", "4 - U15" + string(14, ' '), "5 - U17", "6 - U19", "7 - Seniors", "8 - Change Season", "0 - Exit" };
			break;
		case 5:
			headerMenu = { "1 - Athletes", "2 - Coaches", "3 - U13", "4 - U15", "5 - U17" + string(14, ' '), "6 - U19", "7 - Seniors", "8 - Change Season", "0 - Exit" };
			break;
		case 6:
			headerMenu = { "1 - Athletes", "2 - Coaches", "3 - U13", "4 - U15", "5 - U17", "6 - U19" + string(14, ' '), "7 - Seniors", "8 - Change Season", "0 - Exit" };
			break;
		case 7:
			headerMenu = { "1 - Athletes", "2 - Coaches", "3 - U13", "4 - U15", "5 - U17", "6 - U19", "7 - Seniors" + string(10, ' '), "8 - Change Season", "0 - Exit" };
			break;
		case 8:
			headerMenu = { "1 - Athletes", "2 - Coaches", "3 - U13", "4 - U15", "5 - U17", "6 - U19", "7 - Seniors", "8 - Change Season" + string(10, ' '), "0 - Exit" };
			break;
        default:
			headerMenu = { "1 - Athletes", "2 - Coaches", "3 - U13", "4 - U15", "5 - U17", "6 - U19", "7 - Seniors", "8 - Change Season", "0 - Exit" };
			break;
    }
    Table optionsMenu(headerMenu);
    cout << menu;
    cout << optionsMenu;
}

/******************************************
 * Athletes Management
 ******************************************/

void printAthletesMenu(string seasonName) {

	showMainMenu(1, seasonName);
	Table menuAthletes({ "1 - Show all Athletes" });
	menuAthletes.addNewLine({ "2 - See an Athlete" });
	menuAthletes.addNewLine({ "3 - Add Athlete" });
	menuAthletes.addNewLine({ "4 - Reactivate Athlete" });
	menuAthletes.addNewLine({ "5 - Remove Athlete" });
	menuAthletes.addNewLine({ "6 - Update ECG of Athlete" });
	menuAthletes.addNewLine({ "0 - Back to Main Menu" });
	cout << menuAthletes;
}

void printAddAthleteMenu(string seasonName) {

	showMainMenu(1, seasonName);
	Table menuAthletes({ "1 - Show all Athletes    " });
	menuAthletes.addNewLine({ "2 - See an Athlete" });
	menuAthletes.addNewLine({ "3 - Add Athlete" });

	Table addAthlete({ "1 - Goalkeeper" }, 11);
	addAthlete.addNewLine({ "2 - Defender" });
	addAthlete.addNewLine({ "3 - Midfielder" });
	addAthlete.addNewLine({ "4 - Forward" });

	Table menuAthletes2({ "4 - Reactivate Athlete" });
	menuAthletes2.addNewLine({ "5 - Remove Athlete" });
	menuAthletes2.addNewLine({ "6 - Update ECG of Athlete" });
	menuAthletes2.addNewLine({ "0 - Back to Main Menu" });
	cout << menuAthletes << addAthlete << menuAthletes2;
}

unsigned int menuAthletesManagement(string seasonName) {
    unsigned int option = 0;
    bool control = false;
	printAthletesMenu(seasonName);

	while (!control) {
		try {
			control = readUnsignedInt(option, 0, 6);
		}
		catch (InvalidInput e) {
			printAthletesMenu(seasonName);
			cout << Table({ e.getMessage() });
		}
    }
    return option;
}

void  optionsAthletesManagement(Club &mainClub, string seasonName) {
    unsigned int option;
    
    while ((option = menuAthletesManagement(seasonName))) {
		string input;
		unsigned int idWorker = 0;
        bool control = false;
		bool exitSwitch = false;

		
		Table showInformation(vector<string>{ "Information" , "Data" });

		Date today;

        switch (option) {
            case 1:				//=========== SHOW ATHLETES ==============
			{
				showMainMenu(0, seasonName);

				if (mainClub.getAthletes().size() == 0) {

					cout << Table({ "There are no athletes." });
					ignoreLine(false);
					break;
				}

				idWorker = 1;
				char order = 'a';

				control = false;
				while (!control) {
					try {
						mainClub.showAthletes((SortCriteria)(idWorker + 2), order == 'a' ? ascending : descending);
						cout << Table({ "Sort by:" });
						cout << Table({"1. Players position","2. Name","3. Age","4. Heigth", "5. ECG","0. Back" }) << endl;
						cout << Table({ "a. Ascending", "d. Descending" });
						getline(cin, input);

						if (input.length() == 0) {
							exitSwitch = true;
							break;
						}

						stringstream ssTmp(input);

						ssTmp >> idWorker;

						ssTmp >> order;

						if (ssTmp.fail() || idWorker < 1 || idWorker > 5 || (order != 'a' && order != 'd'))
							throw InvalidInput();

						control = false;
						showMainMenu(0, seasonName);
					}
					catch (InvalidInput e) {

						showMainMenu(0, seasonName);
						mainClub.showAthletes((SortCriteria)(idWorker + 2), order == 'a' ? ascending : descending);

						cout << Table({ e.getMessage() });
						control = false;
					}
				}

				if (exitSwitch) break;
				break;

			}
            case 2:				//============ SHOW ONE ATHLETE ============
			{
				if (mainClub.getAthletes().size() == 0) {

					showMainMenu();
					cout << Table({ "There are no Athletes." });
					ignoreLine(false);
					break;
				}

				showMainMenu(0, seasonName);
				mainClub.showAthletes(playerPosition);


				control = false;
				while (!control) {
					try {
						cout << Table({ "Please, enter the athlete's ID" }) << endl;
						control = readUnsignedInt(idWorker, 1, Worker::getLastId(), "Invalid ID.");

						if (!idWorker) {
							exitSwitch = true;
							break;
						}

						showMainMenu(0, seasonName);

						control = false;
						control = mainClub.showAthlete(idWorker);
						ignoreLine(false);
					}
					catch (InvalidInput e) {

						showMainMenu(0, seasonName);
						mainClub.showAthletes(playerPosition);

						cout << Table({ e.getMessage() });
					}
				}


				// If user push ENTER
				if (exitSwitch) break;

				break;
			}
            case 3:				//=========== ADD ATHLETE ================
			{
				printAddAthleteMenu(seasonName);


				unsigned int position = 0;

				control = false;
				while (!control) {
					try {
						control = readUnsignedInt(position, 0, 4);
					}
					catch (InvalidInput e) {
						printAddAthleteMenu(seasonName);

						cout << Table({ e.getMessage() });

					}
				}


				// If user push Enter or 0
				if (!position) {
					exitSwitch = true;
					break;
				}


				// Read Athlete's Name

				showMainMenu(0, seasonName);

				string newAthleteName;

				control = false;
				while (!control) {
					try {

						cout << Table({ "Please, enter the athlete's NAME." }) << endl;

						getline(cin, newAthleteName);

						if (emptyString(newAthleteName)) {
							exitSwitch = true;
							break;
						}

						control = validateName(newAthleteName);


					}
					catch (InvalidInput e) {
						showMainMenu(0, seasonName);

						Table printErrorMessage({ e.getMessage() });
						cout << printErrorMessage;

					}
				}

				//If user push ENTER
				if (exitSwitch) break;

				//==========================

				// Read Athlete's Birth Date
				showMainMenu(0, seasonName);

				Date newAthleteBirthDate;

				control = false;
				while (!control) {
					try {


						/*Table introBirthDate({ "Please, enter the athlete's BIRTH DATE." });
						cout << introBirthDate << endl;*/

						
						control = readDate(newAthleteBirthDate, Date(today.getDay(), today.getMonth(), today.getYear() - 45), 
																Date(today.getDay(), today.getMonth(), today.getYear() - 11), 
																"Please, enter the athlete's BIRTH DATE.", "Invalid Date");

						if (newAthleteBirthDate == today) {
							exitSwitch = true;
							break;
						}

						control = true;

					}
					catch (InvalidDate e) {

						showMainMenu(0, seasonName);

						Table printErrorMessage({ e.getMessage() });
						cout << printErrorMessage;

					}
				}

				//If user push ENTER
				if (exitSwitch) break;

				//==========================

				// Read Athlete's Height

				showMainMenu(0, seasonName);

				unsigned int heigth = 0;

				control = false;
				while (!control) {
					try {

						Table introHeight({ "Please, enter the athlete's HEIGHT." });
						cout << introHeight << endl;

						control = readUnsignedInt(heigth, 100, 250, "Invalid heigth: This value must be between 100 and 250");

						// ENTER
						if (!heigth) {
							exitSwitch = true;
							break;
						}



					}
					catch (InvalidInput e) {

						showMainMenu(0, seasonName);

						cout << Table({ e.getMessage() });

					}
				}

				//If user push ENTER
				if (exitSwitch) break;

				//==========================

				// Read Athlete's Civil ID

				showMainMenu(0, seasonName);

				unsigned int CivilID = 0;

				control = false;
				while (!control) {
					try {

						Table introCivilID({ "Please, enter the athlete's CIVIL ID." });
						cout << introCivilID << endl;

						control = readUnsignedInt(CivilID, 10000000, 99999999, "Invalid Civil ID: This value must to have 8 digits.");

						// ENTER
						if (!CivilID) {
							exitSwitch = true;
							break;
						}



					}
					catch (InvalidInput e) {

						showMainMenu(0, seasonName);

						cout << Table({ e.getMessage() });

					}
				}

				//If user push ENTER
				if (exitSwitch) break;
				//==========================


				//Mostrar resumo da operacao

				showInformation.addNewLine({ "ID: " , to_string(Worker::getLastId() + 1) });

				showInformation.addNewLine({ "Civil ID: " , to_string(CivilID) });

				showInformation.addNewLine({ "Name: " , newAthleteName });

				showInformation.addNewLine({ "Birth Date: " , newAthleteBirthDate.str() });

				showInformation.addNewLine({ "Level: " , getLevelFromAge(newAthleteBirthDate) });

				showMainMenu(0, seasonName);

				cout << showInformation;

				if (!confirm(Table({ "Are you sure you want to add the athlete?" }))) {
					break;
				}
				ignoreLine(false, "Athlete correctly added!");

				mainClub.addPlayer((Position)position, newAthleteName, newAthleteBirthDate, CivilID, heigth);

				mainClub.saveChanges();
				break;
			}
            case 5:				//============  REMOVE ATHLETES ================
			{
				if (mainClub.getAthletes().size() == 0) {

					showMainMenu(0, seasonName);
					cout << Table({ "There are no Athletes." });
					ignoreLine(false);
					break;
				}

				if (mainClub.getAthletes(true).size() == 0) {

					showMainMenu(0, seasonName);
					cout << Table({ "There are no active Athletes." });
					ignoreLine(false);
					break;

				}

				
				showMainMenu(0, seasonName);
				mainClub.showAthletes(playerPosition, ascending, false);

				control = false;
				while (!control) {
					try {
						cout << Table({ "Please enter the athlete's id to remove." }) << endl;
						
						control = readUnsignedInt(idWorker, 1, Worker::getLastId(), "Invalid ID.");

						if (!idWorker) {
							exitSwitch = true;
							break;
						}
						
						control = mainClub.removeAthlete(idWorker);
						if (!control)
							break;
					}
					catch (InvalidInput e) {

						showMainMenu(0, seasonName);
						mainClub.showAthletes(playerPosition, ascending, true);

						cout << Table({ e.getMessage() });
						control = false;
					}
				}


				//If user push ENTER
				if (exitSwitch) break;

				mainClub.saveChanges();
				break;
			}
			case 4:				//================ REATIVATE ATHLETE ==================
			{
				if (mainClub.getAthletes().size() == 0) {

					showMainMenu();
					cout << Table({ "There are no Athletes." });
					ignoreLine(false);
					break;
				}

				if (mainClub.getInactives(1).size() == 0) {

					showMainMenu();
					cout << Table({ "There are no inactive Athletes." });
					ignoreLine(false);
					break;

				}

				showMainMenu(0, seasonName);
				mainClub.showAthletesInactives();

				control = false;
				while (!control) {
					try {
						cout << Table({ "Please enter the athlete's id to reativate." }) << endl;

						control = readUnsignedInt(idWorker, 1, Worker::getLastId(), "Invalid ID.");

						if (!idWorker) {
							exitSwitch = true;
							break;
						}

						if (mainClub.getAthletes().at(idWorker)->isActive()) {
							
							throw InvalidInput( "This athlete is already active." );
						
						}

						map<unsigned int, Worker*> tmpMap = mainClub.getAthletes();
						if (tmpMap.find(idWorker) == tmpMap.end()) {
							
							throw InvalidInput( "This ID does not belong to an Athlete." );
						
						}

						// Show operation summary

						showInformation.addNewLine({ "ID: " , to_string(mainClub.getAthletes().at(idWorker)->getID()) });  // Show id

						showInformation.addNewLine({ "Civil ID: " , to_string(mainClub.getAthletes().at(idWorker)->getCivilID()) }); // Show Civil Id

						showInformation.addNewLine({ "Name: " , mainClub.getAthletes().at(idWorker)->getName() }); // Show Name

						showInformation.addNewLine({ "Birth Date: " , mainClub.getAthletes().at(idWorker)->getBirthdate().str() }); // Show Birth Date

						showInformation.addNewLine({ "Level: " , getLevelFromAge(mainClub.getAthletes().at(idWorker)->getBirthdate()) }); // Show Level

						showMainMenu(0, seasonName);


						cout << showInformation;

						if (!confirm(Table({ "Are you sure you want to reativate the athlete?" }))) {
							exitSwitch = true;
							break;
						}


						control = mainClub.reativateAthlete(idWorker);

						ignoreLine(false, "Athlete reativated correctly");

					}
					catch (InvalidInput e) {

						showMainMenu();
						mainClub.showAthletesInactives();

						cout << Table({ e.getMessage() });

						control = false;
					}
				}

				if (exitSwitch) break;

				mainClub.saveChanges();
				break;
			}
			case 6:				//================ UPDATE ECG ==================
			{
				if (mainClub.getAthletes().size() == 0) {

					showMainMenu(0, seasonName);
					cout << Table({ "There are no Athletes." });
					ignoreLine(false);
					break;
				}

				if (mainClub.getAthletes(true).size() == 0) {

					showMainMenu(0, seasonName);
					cout << Table({ "There are no active Athletes." });
					ignoreLine(false);
					break;

				}


				showMainMenu(0, seasonName);
				mainClub.showAthletes(playerPosition, ascending);

				control = false;
				while (!control) {
					try {
						cout << Table({ "Please enter the athlete's id to update ECG." }) << endl;

						control = readUnsignedInt(idWorker, 1, Worker::getLastId(), "Invalid ID.");

						if (!idWorker) {
							exitSwitch = true;
							break;
						}

					}
					catch (InvalidInput e) {

						showMainMenu(0, seasonName);
						mainClub.showAthletes(playerPosition, ascending);

						cout << Table({ e.getMessage() });
						control = false;
					}
				}


				//If user push ENTER
				if (exitSwitch) break;

				// Read the result of the ECG
				unsigned int result = 0;
				control = false;
				while (!control) {
					try {
						cout << Table({ "Please, enter the result of the ECG exam." }) << endl;
						cout << Table({ "1. Valid", "2. Invalid" });

						control = readUnsignedInt(result, 1, 2);

						if (!idWorker) {
							exitSwitch = true;
							break;
						}

						control = mainClub.updateECG(idWorker, result == 2 ? false : true);
					}
					catch (InvalidInput e) {

						showMainMenu(0, seasonName);
						mainClub.showAthletes(playerPosition, ascending, true);

						cout << Table({ e.getMessage() });
						control = false;
					}
				}


				//If user push ENTER
				if (exitSwitch) break;

				mainClub.saveChanges();
				break;
			}
            case 0:
                break;
        }
    }
}

/******************************************
 * Coaches Management
 ******************************************/

void printCoachesMenu(string seasonName) {

	showMainMenu(2, seasonName);

	Table menuCoaches({ "1 - Show all Coaches" }, 17);
	menuCoaches.addNewLine({ "2 - Add Coach" });
	menuCoaches.addNewLine({ "3 - Reactivate Coach" });
	menuCoaches.addNewLine({ "4 - Remove Coach" });
	menuCoaches.addNewLine({ "0 - Back to Main Menu" });
	cout << menuCoaches;
}

void printAddCoachMenu(string seasonName) {

	showMainMenu(2, seasonName);
	Table menuCoaches({ "1 - Show all Coaches " }, 17);
	menuCoaches.addNewLine({ "2 - Add Coach" });

	Table addCoach({ "1 - Head Coach" }, 26);
	addCoach.addNewLine({ "2 - Goalkeeper Coach" });
	addCoach.addNewLine({ "3 - Physical Trainer" });

	Table menuCoaches2({ "3 - Reactivate Coach" }, 17);
	menuCoaches2.addNewLine({ "4 - Remove Coach" });
	menuCoaches2.addNewLine({ "0 - Back to Main Menu" });
	cout << menuCoaches << addCoach << menuCoaches2;
}

unsigned int menuCoachesManagement(string seasonName) {
	unsigned int option = 0;
	bool control = false;
	printCoachesMenu(seasonName);

	while (!control) {
		try {
			control = readUnsignedInt(option, 0, 4);
		}
		catch (InvalidInput e) {
			printCoachesMenu(seasonName);
			cout << Table({ e.getMessage() });
		}
	}
	return option;
}

void optionsCoachesManagement(Club &mainClub, string seasonName) {
	unsigned int option;

	while ((option = menuCoachesManagement(seasonName))) {
		string input;
		unsigned int idWorker;
		bool control = false;
		bool exitSwitch = false;


		Table showInformation({ "Information" , "Data" });

		Date today;

		switch (option) {
		case 1:             //=========== SHOW COACHES    ==============
		{
			showMainMenu(0, seasonName);

			if (mainClub.getCoaches().size() == 0) {

				cout << Table({ "There are no coaches." });
				ignoreLine(false);
				break;
			}

            unsigned int criteria = 1;
            char order = 'a';
            control = false;
            
            while (!control) {
                try {
                    
                    SortCriteria sortCriteria = typeOfCoach;
                    switch (criteria) {
                        case 1:
                            sortCriteria = typeOfCoach;
                            break;
                        case 2:
                            sortCriteria = name;
                            break;
                        case 3:
                            sortCriteria = age;
                            break;
                            
                    }
                    mainClub.showCoaches(sortCriteria, order == 'a' ? ascending : descending);
                    cout << Table({ "Sort by:" });
                    cout << Table({"1. Coach Position","2. Name","3. Age","0. Back" }) << endl;
                    cout << Table({ "a. Ascending", "d. Descending" });
                    getline(cin, input);
                    
                    if (input.length() == 0) {
                        exitSwitch = true;
                        break;
                    }
                    stringstream ssTmp(input);
                    
                    ssTmp >> criteria;
                    
                    ssTmp >> order;
                    
                    if (ssTmp.fail() || idWorker < 1 || idWorker > 3 || (order != 'a' && order != 'd'))
                        throw InvalidInput();
                    
                    control = false;
                    showMainMenu(0, seasonName);
                } catch (InvalidInput e) {
                    showMainMenu(0, seasonName);
                    mainClub.showCoaches((SortCriteria)(idWorker + 2), order == 'a' ? ascending : descending);
                    cout << Table({ e.getMessage() });
                    control = false;
                }
            }

            if (exitSwitch) break;
			break;
		}
		case 2:             //=========== ADD COACH       ==============
		{

			//Read Coach's position
			printAddCoachMenu(seasonName);
			
			unsigned int position = 0;

			control = false;
			while (!control) {
				try {
					control = readUnsignedInt(position, 0, 3);
				}
				catch (InvalidInput e) {
					printAddCoachMenu(seasonName);

					cout << Table({ e.getMessage() });

				}
			}


			// If user push Enter or 0
			if (!position) {
				exitSwitch = true;
				break;
			}


			// Read Athlete's Name

			showMainMenu(0, seasonName);

			string newCoachName;

			control = false;
			while (!control) {
				try {

					cout << Table({ "Please, enter the coach's NAME." }) << endl;

					getline(cin, newCoachName);

					if (emptyString(newCoachName)) {
						exitSwitch = true;
						break;
					}

					control = validateName(newCoachName);


				}
				catch (InvalidInput e) {

					showMainMenu(0, seasonName);

					cout << Table({ e.getMessage() });

				}
			}

			//If user push ENTER
			if (exitSwitch) break;

			//==========================

			// Read Coach's Birth Date

			showMainMenu(0, seasonName);

			Date newCoachBirthDate;

			control = false;
			while (!control) {
				try {

					control = readDate(newCoachBirthDate, Date(1, 1, 1900),
														  Date(today.getDay(), today.getMonth(), today.getYear() - 18),
														  "Please, enter the coach BIRTH DATE.", "Invalid Date");

					if (newCoachBirthDate == today) {
						exitSwitch = true;
						break;
					}

					control = true;

				}
				catch (InvalidDate e) {

					showMainMenu(0, seasonName);

					cout << Table({ e.getMessage() });

				}
			}

			//If user push ENTER
			if (exitSwitch) break;

			//==========================

			// Read coach's Civil ID

			showMainMenu(0, seasonName);

			unsigned int CivilID = 0;

			control = false;
			while (!control) {
				try {

					cout << Table({ "Please, enter the coach's CIVIL ID." }) << endl;

					control = readUnsignedInt(CivilID, 10000000, 99999999, "Invalid Civil ID: This value must to have 8 digits.");

					// ENTER
					if (!CivilID) {
						exitSwitch = true;
						break;
					}



				}
				catch (InvalidInput e) {

					showMainMenu(0, seasonName);

					cout << Table({ e.getMessage() });

				}
			}

			//If user push ENTER
			if (exitSwitch) break;
			//==========================

			// Read Coach's Height

			showMainMenu(0, seasonName);

			unsigned int level = 0;

			control = false;
			while (!control) {
				try {

					cout << Table({ "Please, enter the LEVEL that the coach will assume." }) << endl;

					cout << Table({ "1. U13", "2. U15", "3. U17", "4. U19", "5. Seniors"});

					control = readUnsignedInt(level, 0, 5);

					// ENTER
					if (!level) {
						exitSwitch = true;
						break;
					}



				}
				catch (InvalidInput e) {

					showMainMenu(0, seasonName);

					cout << Table({ e.getMessage() });

				}
			}

			//If user push ENTER
			if (exitSwitch) break;

			//==========================

			// Read Coach's Role

			showMainMenu(0, seasonName);

			unsigned int coachResponsible = 0;

			control = false;
			while (!control) {
				try {

					cout << Table({ "This Coach will be responsible for this Level?" }) << endl;

					cout << Table({ "1. YES", "2. NO" });

					control = readUnsignedInt(coachResponsible, 0, 2);

					// ENTER
					if (!coachResponsible) {
						exitSwitch = true;
						break;
					}



				}
				catch (InvalidInput e) {

					showMainMenu(0, seasonName);

					cout << Table({ e.getMessage() });

				}
			}

			//If user push ENTER
			if (exitSwitch) break;

			//==========================



			//Mostrar resumo da operacao

			showInformation.addNewLine({ "ID: " , to_string(Worker::getLastId() + 1) });

			showInformation.addNewLine({ "Civil ID: " , to_string(CivilID) });

			showInformation.addNewLine({ "Name: " , newCoachName });

			showInformation.addNewLine({ "Birth Date: " , newCoachBirthDate.str() });

			showMainMenu(0, seasonName);

			cout << Table({ "Are you sure you want to add the coach?" });;

			if (!confirm(showInformation)) {
				break;
			}
			ignoreLine(false, "Coach correctly added!");

			mainClub.addCoach((CoachType)position, newCoachName, newCoachBirthDate, CivilID, (ageLevel)level, !(coachResponsible-1));

			mainClub.saveChanges();
			break;
		}
		case 4:             //=========== REMOVE COACH    ==============
		{
			if (mainClub.getCoaches().size() == 0) {

				showMainMenu(0, seasonName);
				cout << Table({ "There are no Coaches." });
				ignoreLine(false);
				break;
			}

			if (mainClub.getCoaches(true).size() == 0) {

				showMainMenu(0, seasonName);
				cout << Table({ "There are no active Coaches." });
				ignoreLine(false);
				break;

			}


			showMainMenu(0, seasonName);
			mainClub.showCoaches(typeOfCoach,ascending, true);

			control = false;
			while (!control) {
				try {
					cout << Table({ "Please enter the coach's id to remove." }) << endl;

					control = readUnsignedInt(idWorker, 1, Worker::getLastId(), "Invalid ID.");

					if (!idWorker) {
						exitSwitch = true;
						break;
					}
					
					control = mainClub.removeCoach(idWorker);

					if (!control)
						break;
				}
				catch (InvalidInput e) {

					showMainMenu(0, seasonName);
					mainClub.showCoaches(typeOfCoach, ascending,true);

					cout << Table({ e.getMessage() });
					control = false;
				}
			}

			if (exitSwitch) break;

			mainClub.saveChanges();
			break;
		}
		case 3:				//=========== REATIVATE COACH ==============
		{
			if (mainClub.getCoaches().size() == 0) {

				showMainMenu();
				cout << Table({ "There are no Coaches." });
				ignoreLine(false);
				break;
			}

			if (mainClub.getInactives(2).size() == 0) {

				showMainMenu();
				cout << Table({ "There are no inactive Coaches." });
				ignoreLine(false);
				break;

			}

			showMainMenu(0, seasonName);
			mainClub.showCoachesInactives();

			control = false;
			while (!control) {
				try {
					cout << Table({ "Please enter the coach's id to reativate." }) << endl;

					control = readUnsignedInt(idWorker, 1, Worker::getLastId(), "Invalid ID.");

					if (!idWorker) {
						exitSwitch = true;
						break;
					}


					control = mainClub.reativateCoach(idWorker);
					

				}
				catch (InvalidInput e) {

					showMainMenu();
					mainClub.showCoachesInactives();

					cout << Table({ e.getMessage() });

					control = false;
				}
			}

			if (exitSwitch) break;

			mainClub.saveChanges();
			break;
		}
		case 0:
			break;
		}
	}
}

/******************************************
 * Levels Management
 ******************************************/

void printLevelsMenu(ageLevel level) {

	Table menuLevels({ "1 - Friendlies" }, 33 + 12*(level - 1));
    menuLevels.addNewLine({ "2 - Trainings"});
    menuLevels.addNewLine({ "3 - Tournaments"});
	menuLevels.addNewLine({ "0 - Back to Main Menu" });
	cout << menuLevels;
}

unsigned int menuLevelsManagement(Level* currentLevel) {

	unsigned int option = 0;
	bool control = false;

	showMainMenu((unsigned int) ageLevelMap.at(currentLevel->getLevelName()) + 2, currentLevel->getYear());
	printLevelsMenu(ageLevelMap.at(currentLevel->getLevelName()));

	while (!control) {
		try {
			control = readUnsignedInt(option, 0, 3);
		}
		catch (InvalidInput e) {
			printLevelsMenu(ageLevelMap.at(currentLevel->getLevelName()));
			cout << Table({ e.getMessage() });
		}
	}
	return option;
}

void optionsLevelsManagement(Club &mainClub, Season* currentSeason, Level* currentLevel) {
    
	unsigned int option;

	while ((option = menuLevelsManagement(currentLevel))) {
		string input;

		Table showInformation({ "Information" , "Data" });

		Date today;

		switch (option) {
		case 1:             //=========== FRIENDLIES   ==============
			optionsFriendlysManagement(mainClub, currentSeason, currentLevel);
			break;
		case 2:             //=======  TRAININGS   ======= 
			optionsTrainingsManagement(mainClub, currentSeason, currentLevel);
			break;
		case 3:				//=======  TOURNAMENTS   ======= 
			optionsTournamentsManagement(mainClub, currentSeason, currentLevel);

		case 0:
			break;
		}
	}
}

/******************************************
* Friendlies Management
******************************************/

void printFriendlysMenu(ageLevel level) {

	Table menuFriendlys({ "1 - Friendlies" + string(8, ' ') }, 33 + 12 * (level - 1));

	Table menuFriendlys2({ "1 - Friendlies Calendar" }, 33 + 12 * (level - 1) + 9);
	menuFriendlys2.addNewLine({ "2 - Schedule Friendly Match" });
	menuFriendlys2.addNewLine({ "3 - Call-up Players" });
	menuFriendlys2.addNewLine({ "4 - Register Scheduled Match" });
	menuFriendlys2.addNewLine({ "5 - Register UnScheduled Match" });

	Table menuFriendlys3({ "2 - Trainings" }, 33 + 12 * (level - 1));
	menuFriendlys3.addNewLine({ "3 - Tournaments" });
	menuFriendlys3.addNewLine({ "0 - Back to Main Menu" });

	cout << menuFriendlys << menuFriendlys2 << menuFriendlys3;
}

unsigned int menuFriendlysManagement(Level* currentLevel) {

	unsigned int option = 0;
	bool control = false;

	showMainMenu((unsigned int)ageLevelMap.at(currentLevel->getLevelName()) + 2, currentLevel->getYear());
	printFriendlysMenu(ageLevelMap.at(currentLevel->getLevelName()));

	while (!control) {
		try {
			control = readUnsignedInt(option, 0, 5);
		}
		catch (InvalidInput e) {
			printFriendlysMenu(ageLevelMap.at(currentLevel->getLevelName()));
			cout << Table({ e.getMessage() });
		}
	}
	return option;
}

void optionsFriendlysManagement(Club &mainClub, Season* currentSeason, Level* currentLevel) {

	unsigned int option = 0;

	while ((option = menuFriendlysManagement(currentLevel))) {
		string input;
		unsigned int idMatch = 0;
		bool control = false;
		bool exitSwitch = false;


		Table showInformation({ "Information" , "Data" });

		Date today;

		switch (option) {
		case 1:             //=========== SHOW CALENDAR   ==============
		{
			showMainMenu(0, currentSeason->getSeasonName());

			if (currentLevel->getAllLevelMatches().size() == 0) {

				cout << Table({ "There are no Matches." });
				ignoreLine(false);
				break;
			}

			control = false;
			while (!control) {
				try {
					showMainMenu(0, currentSeason->getSeasonName());
					currentLevel->showMatches(currentLevel->getAllLevelMatches());

					cout << Table({ "Please enter a MATCH ID to show game data." }) << endl;

					control = readUnsignedInt(idMatch, 1, (unsigned int)currentLevel->getAllLevelMatches(true).size(), "Invalid Match ID.");

					if (!idMatch) {
						exitSwitch = true;
						break;
					}

					currentLevel->showMatch(currentLevel->getAllLevelMatches().at(idMatch - 1));
					control = false;
				}
				catch (InvalidInput e) {

					showMainMenu(0, currentSeason->getSeasonName());
					currentLevel->showMatches(currentLevel->getAllLevelMatches());

					cout << Table({ e.getMessage() });
					control = false;
				}
			}

			if (exitSwitch) break;



			break;
		}
		case 2:             //=======  SCHEDULE FRIENDLY MATCH   ======= 
		{
			// Read Oponent Name

			showMainMenu(0, currentSeason->getSeasonName());

			string newOponentName;

			control = false;
			while (!control) {
				try {

					cout << Table({ "Please, enter the oponent NAME." }) << endl;

					getline(cin, newOponentName);

					if (emptyString(newOponentName)) {
						exitSwitch = true;
						break;
					}

					control = validateName(newOponentName, true);


				}
				catch (InvalidInput e) {

					showMainMenu(0, currentSeason->getSeasonName());

					cout << Table({ e.getMessage() });

				}
			}

			//If user push ENTER
			if (exitSwitch) break;

			//========================


			// Read Match Type

			showMainMenu(0, currentSeason->getSeasonName());

			unsigned int homeOrAway = 0;

			control = false;
			while (!control) {
				try {
					Table tmpTable({ "Information", "Data" });
					tmpTable.addNewLine({ "Oponent" , newOponentName });
					cout << tmpTable;

					cout << Table({ "This Match will be Home or Away?" }) << endl;

					cout << Table({ "1. HOME", "2. AWAY" });

					control = readUnsignedInt(homeOrAway, 0, 2);

					// ENTER
					if (!homeOrAway) {
						exitSwitch = true;
						break;
					}



				}
				catch (InvalidInput e) {

					showMainMenu(0, currentSeason->getSeasonName());

					cout << Table({ e.getMessage() });

				}
			}

			//If user push ENTER
			if (exitSwitch) break;

			//==========================
			// Read Match Date

			Date newMatchDate = Date(1, 1, 1900);

			showInformation.addNewLine({ "Match: " , homeOrAway == 1 ? (mainClub.getName() + " vs " + newOponentName) : (newOponentName + " vs " + mainClub.getName()) });
			
			showMainMenu(0, currentSeason->getSeasonName());
			cout << showInformation;

			control = false;
			while (!control) {
				try {


					control = readDate(newMatchDate, today, currentSeason->getEndDate(), "Please, enter the MATCH DATE.", "Invalid Date");

					if (newMatchDate == Date(1,1,1900)) {
						exitSwitch = true;
						break;
					}

					control = true;

				}
				catch (InvalidDate e) {

					showMainMenu(0, currentSeason->getSeasonName());
					cout << showInformation;

					cout << Table({ e.getMessage() });

				}
			}

			//If user push ENTER
			if (exitSwitch) break;

			//==========================

			//Mostrar resumo da operacao


			showInformation.addNewLine({ "Date: " , newMatchDate.str() });

			showMainMenu(0, currentSeason->getSeasonName());

			cout << Table({ "Are you sure you want to schedule this match?" });;

			if (!confirm(showInformation)) {
				break;
			}
			ignoreLine(false, "Match correctly scheduled!");

			// Ask to Call-up players

			showMainMenu(0, currentSeason->getSeasonName());

			unsigned int callUpPlayers = 0;

			control = false;
			while (!control) {
				try {

					cout << Table({ "Do you want to call-up the players for this match, right now?" }) << endl;

					cout << Table({ "1. YES", "2. NO" });

					control = readUnsignedInt(callUpPlayers, 0, 2);

				}
				catch (InvalidInput e) {

					showMainMenu(0, currentSeason->getSeasonName());

					cout << Table({ e.getMessage() });

				}
			}

			if (callUpPlayers == 0 || callUpPlayers == 2) {
				mainClub.scheduleMatch(newOponentName, newMatchDate, currentLevel, homeOrAway == 1 ? MatchType::home : MatchType::away);
			}
			else if (callUpPlayers == 1) {

				// Read players to call-up

				showMainMenu(0, currentSeason->getSeasonName());

				string playersToCallUp;
				vector<unsigned int> playersToCallUpVector;

				//Show players
				cout << Table(currentLevel->showAthletesOfLevel(playerPosition, ascending, true), 0);

				control = false;
				while (!control) {
					try {

						cout << Table({ "Please, enter the athletes ids to call-up in this match. (Eg: 1 4 7)" }) << endl;

						getline(cin, playersToCallUp);

						if (playersToCallUp.length() == 0)
							break;

						stringstream ssPlayers(playersToCallUp);

						while (!ssPlayers.eof()) {
							unsigned int idPlayer;
							ssPlayers >> idPlayer;

							if (!ssPlayers.fail())
								playersToCallUpVector.push_back(idPlayer);

						}
						control = true;

					}
					catch (InvalidInput e) {

						showMainMenu(0, currentSeason->getSeasonName());

						cout << Table(currentLevel->showAthletesOfLevel(playerPosition, ascending, true), 0);

						cout << Table({ e.getMessage() });

					}
				}

				if (playersToCallUp.length() == 0)
					mainClub.scheduleMatch(newOponentName, newMatchDate, currentLevel, homeOrAway == 1 ? MatchType::home : MatchType::away);

				mainClub.callUpPlayers(newOponentName, newMatchDate, currentLevel, homeOrAway == 1 ? MatchType::home : MatchType::away, playersToCallUpVector);

			}


			mainClub.saveChanges();
			break;
		}
		case 3:				//=======  CALL UP PLAYERS   ======= 
		{
			if (currentLevel->getAllLevelMatches(true).size() == 0) {

				showMainMenu(0, currentSeason->getSeasonName());
				cout << Table({ "There are no uncoming Matches." });
				ignoreLine(false);
				break;
			}


			showMainMenu(0, currentSeason->getSeasonName());

			currentLevel->showMatches(currentLevel->getAllLevelMatches(true));

			control = false;
			while (!control) {
				try {
					cout << Table({ "Please enter the MATCH ID to call-up players." }) << endl;

					control = readUnsignedInt(idMatch, 1, (unsigned int)currentLevel->getAllLevelMatches(true).size(), "Invalid Match ID.");

					if (!idMatch) {
						exitSwitch = true;
						break;
					}
				}
				catch (InvalidInput e) {

					showMainMenu(0, currentSeason->getSeasonName());
					currentLevel->showMatches(currentLevel->getAllLevelMatches(true));

					cout << Table({ e.getMessage() });
					control = false;
				}
			}

			if (exitSwitch) break;

			if (currentLevel->getAllLevelMatches(true).at(idMatch - 1)->getPlayersIds().size()) {

				if (!confirm(Table({ "This game already has players called-up. Do you want to continue?" })))
					break;
			}

			//Read Players to Call-up
			showMainMenu(0, currentSeason->getSeasonName());

			string playersToCallUp;
			vector<unsigned int> playersToCallUpVector;

			//Show players
			cout << Table(currentLevel->showAthletesOfLevel(playerPosition, ascending, true), 0);

			control = false;
			while (!control) {
				try {

					cout << Table({ "Please, enter the ATHLETES IDs to call-up in this match. (Eg: 1 4 7)" }) << endl;

					getline(cin, playersToCallUp);

					if (playersToCallUp.length() == 0) {
						exitSwitch = true;
						break;
					}

					stringstream ssPlayers(playersToCallUp);

					while (!ssPlayers.eof()) {
						unsigned int idPlayer;
						ssPlayers >> idPlayer;

						if (!ssPlayers.fail())
							playersToCallUpVector.push_back(idPlayer);
						else
							throw InvalidInput("Invalid athletes.");

					}
					control = true;

				}
				catch (InvalidInput e) {

					showMainMenu(0, currentSeason->getSeasonName());
					cout << Table(currentLevel->showAthletesOfLevel(playerPosition, ascending, true), 0);

					cout << Table({ e.getMessage() });

				}
			}

			if (exitSwitch)	break;


			mainClub.callUpPlayers(currentLevel->getAllLevelMatches(true).at(idMatch - 1)->getId(), playersToCallUpVector, currentLevel);


			mainClub.saveChanges();
			break;
		}
		case 4:				//=======  REGISTER SCHEDULED MATCH  ======= 
		{
			if (currentLevel->getMatchesReadyToPlay().size() == 0) {

				showMainMenu(0, currentSeason->getSeasonName());
				cout << Table({ "There are no not-registered Matches." });
				ignoreLine(false);
				break;
			}
			/*else if (currentLevel->getMatchesReadyToPlay().size() == 0) {

			showMainMenu(0, currentSeason->getSeasonName());
			cout << Table({ "There are no Matches with called-up players." });
			ignoreLine(false);
			break;
			}*/


			showMainMenu(0, currentSeason->getSeasonName());
			currentLevel->showMatches(currentLevel->getMatchesReadyToPlay());

			control = false;
			while (!control) {
				try {
					cout << Table({ "Please enter the MATCH ID to register." }) << endl;

					control = readUnsignedInt(idMatch, 1, (unsigned int)currentLevel->getMatchesReadyToPlay().size(), "Invalid Match ID.");

					if (!idMatch) {
						exitSwitch = true;
						break;
					}
				}
				catch (InvalidInput e) {

					showMainMenu(0, currentSeason->getSeasonName());
					currentLevel->showMatches(currentLevel->getMatchesReadyToPlay());

					cout << Table({ e.getMessage() });
					control = false;
				}
			}

			if (exitSwitch) break;

			//Read Score of Match
			showMainMenu(0, currentSeason->getSeasonName());

			string score;
			unsigned int homeTeamScore = 0;
			unsigned int awayTeamScore = 0;

			control = false;
			while (!control) {
				try {
					currentLevel->showMatches({ currentLevel->getMatchesReadyToPlay().at(idMatch - 1) });
					cout << Table({ "Please, enter the SCORE of the Match. (Eg: 2 x 1)" }) << endl;

					getline(cin, score);

					if (score.length() == 0) {
						exitSwitch = true;
						break;
					}

					stringstream ssPlayers(score);


					ssPlayers >> homeTeamScore;

					string separator;
					ssPlayers >> separator;

					ssPlayers >> awayTeamScore;

					if (ssPlayers.fail())
						throw InvalidInput("Invalid Score: " + score + " is not a valid score.");

					control = true;

				}
				catch (InvalidInput e) {

					showMainMenu(0, currentSeason->getSeasonName());

					cout << Table({ e.getMessage() });

				}
			}

			if (exitSwitch)	break;

			//==========================

			//Mostrar resumo da operacao

			Table showInfoMatch({ "Date", "Home Team", "Score", "Away Team" });

			showInfoMatch.addNewLine({ currentLevel->getMatchesReadyToPlay().at(idMatch - 1)->getMatchDay().str(),
				currentLevel->getMatchesReadyToPlay().at(idMatch - 1)->getHomeTeam()->getName(),
				to_string(homeTeamScore) + " - " + to_string(awayTeamScore),
				currentLevel->getMatchesReadyToPlay().at(idMatch - 1)->getAwayTeam()->getName() });

			showMainMenu(0, currentSeason->getSeasonName());

			cout << Table({ "Are you sure you want to register this match?" });;

			if (!confirm(showInfoMatch)) {
				break;
			}

			mainClub.registerMatch(currentLevel->getAllLevelMatches(true).at(idMatch - 1)->getId(), currentLevel, homeTeamScore, awayTeamScore,
				currentLevel->getAllLevelMatches(true).at(idMatch - 1)->getPlayersIds());
			ignoreLine(false, "Match correctly registed!");




			mainClub.saveChanges();
			break;
		}
		case 5:				//=======  REGISTER NOT SCHEDULED MATCH  ======= 
		{
			// Read Oponent Name

			showMainMenu(0, currentSeason->getSeasonName());

			string newOponentName;

			control = false;
			while (!control) {
				try {

					cout << Table({ "Please, enter the oponent NAME." }) << endl;

					getline(cin, newOponentName);

					if (emptyString(newOponentName)) {
						exitSwitch = true;
						break;
					}

					control = validateName(newOponentName);


				}
				catch (InvalidInput e) {

					showMainMenu(0, currentSeason->getSeasonName());

					cout << Table({ e.getMessage() });

				}
			}

			//If user push ENTER
			if (exitSwitch) break;

			//==========================
			// Read Match Date

			showMainMenu(0, currentSeason->getSeasonName());

			Date newMatchDate = Date(1, 1, 1900);
			control = false;
			while (!control) {
				try {

					control = readDate(newMatchDate, currentSeason->getInitialDate(), today, "Please, enter the MATCH DATE.", "Invalid Date");

					if (newMatchDate == Date(1, 1, 1900)) {
						exitSwitch = true;
						break;
					}

					control = true;

				}
				catch (InvalidDate e) {

					showMainMenu(0, currentSeason->getSeasonName());

					cout << Table({ e.getMessage() });

				}
			}

			//If user push ENTER
			if (exitSwitch) break;

			//==========================
			// Read Match Type

			showMainMenu(0, currentSeason->getSeasonName());

			unsigned int homeOrAway = 0;

			control = false;
			while (!control) {
				try {

					cout << Table({ "This Match was Home or Away?" }) << endl;

					cout << Table({ "1. HOME", "2. AWAY" });

					control = readUnsignedInt(homeOrAway, 0, 2);

					// ENTER
					if (!homeOrAway) {
						exitSwitch = true;
						break;
					}



				}
				catch (InvalidInput e) {

					showMainMenu(0, currentSeason->getSeasonName());

					cout << Table({ e.getMessage() });

				}
			}

			//If user push ENTER
			if (exitSwitch) break;



			// Read players to call-up

			showMainMenu(0, currentSeason->getSeasonName());

			string playersToCallUp;
			vector<unsigned int> playersToCallUpVector;

			//Show players
			cout << Table(currentLevel->showAthletesOfLevel(playerPosition, ascending, true), 0);

			control = false;
			while (!control) {
				try {

					cout << Table({ "Please, enter the athletes ids who was called-up in this match. (Eg: 1 4 7)" }) << endl;

					getline(cin, playersToCallUp);

					if (playersToCallUp.length() == 0)
						break;

					stringstream ssPlayers(playersToCallUp);

					while (!ssPlayers.eof()) {
						unsigned int idPlayer;
						ssPlayers >> idPlayer;

						if (!ssPlayers.fail())
							playersToCallUpVector.push_back(idPlayer);

					}
					control = true;

				}
				catch (InvalidInput e) {

					showMainMenu(0, currentSeason->getSeasonName());

					cout << Table({ e.getMessage() });

				}
			}



			//Read Score of Match
			showMainMenu(0, currentSeason->getSeasonName());

			string score;
			unsigned int homeTeamScore = 0;
			unsigned int awayTeamScore = 0;

			control = false;
			while (!control) {
				try {
					cout << Table({ "Please, enter the SCORE of the Match. (Eg: 2 x 1)" }) << endl;

					getline(cin, score);

					if (score.length() == 0) {
						exitSwitch = true;
						break;
					}

					stringstream ssPlayers(score);


					ssPlayers >> homeTeamScore;

					string separator;
					ssPlayers >> separator;

					ssPlayers >> awayTeamScore;

					if (ssPlayers.fail())
						throw InvalidInput("Invalid Score: " + score + " is not a valid score.");

					control = true;

				}
				catch (InvalidInput e) {

					showMainMenu(0, currentSeason->getSeasonName());

					cout << Table({ e.getMessage() });

				}
			}

			if (exitSwitch)	break;

			//==========================

			//Mostrar resumo da operacao

			Table showInfoMatch({ "Date", "Home Team", "Score", "Away Team" });

			showInfoMatch.addNewLine({ newMatchDate.str(),
				homeOrAway == 1 ? mainClub.getName() : newOponentName,
				to_string(homeTeamScore) + " - " + to_string(awayTeamScore),
				homeOrAway == 2 ? mainClub.getName() : newOponentName });

			showMainMenu(0, currentSeason->getSeasonName());

			Table athletes({ "ID", "Athletes called-up" , "Position" });

			for (size_t i = 0; i < playersToCallUpVector.size(); i++) {
				if (!i)
					switch (mainClub.getAthletes().at(playersToCallUpVector.at(i))->getPosition()) {
					case 1:
						athletes.addNewLine({ to_string(mainClub.getAthletes().at(playersToCallUpVector.at(i))->getID()), mainClub.getAthletes().at(playersToCallUpVector.at(i))->getName(), "Goalkeeper" });
						break;
					case 2:
						athletes.addNewLine({ to_string(mainClub.getAthletes().at(playersToCallUpVector.at(i))->getID()), mainClub.getAthletes().at(playersToCallUpVector.at(i))->getName(), "Defender" });
						break;
					case 3:
						athletes.addNewLine({ to_string(mainClub.getAthletes().at(playersToCallUpVector.at(i))->getID()), mainClub.getAthletes().at(playersToCallUpVector.at(i))->getName(), "Midfielder" });
						break;
					case 4:
						athletes.addNewLine({ to_string(mainClub.getAthletes().at(playersToCallUpVector.at(i))->getID()), mainClub.getAthletes().at(playersToCallUpVector.at(i))->getName(), "Forward" });
						break;
					}

				else
					switch (mainClub.getAthletes().at(playersToCallUpVector.at(i))->getPosition()) {
					case 1:
						athletes.addDataInSameLine({ to_string(mainClub.getAthletes().at(playersToCallUpVector.at(i))->getID()), mainClub.getAthletes().at(playersToCallUpVector.at(i))->getName(), "Goalkeeper" });
						break;
					case 2:
						athletes.addDataInSameLine({ to_string(mainClub.getAthletes().at(playersToCallUpVector.at(i))->getID()), mainClub.getAthletes().at(playersToCallUpVector.at(i))->getName(), "Defender" });
						break;
					case 3:
						athletes.addDataInSameLine({ to_string(mainClub.getAthletes().at(playersToCallUpVector.at(i))->getID()), mainClub.getAthletes().at(playersToCallUpVector.at(i))->getName(), "Midfielder" });
						break;
					case 4:
						athletes.addDataInSameLine({ to_string(mainClub.getAthletes().at(playersToCallUpVector.at(i))->getID()), mainClub.getAthletes().at(playersToCallUpVector.at(i))->getName(), "Forward" });
						break;
					}
			}

			cout << showInfoMatch << athletes;

			if (!confirm(Table({ "Are you sure you want to register this match?" }))) {
				break;
			}

			mainClub.registerMatch(newOponentName, newMatchDate, currentLevel, (MatchType)(homeOrAway - 1), homeTeamScore, awayTeamScore, playersToCallUpVector);
			ignoreLine(false, "Match correctly registed!");




			mainClub.saveChanges();
			break;
		}

		case 0:
			break;
		}
	}
}

/******************************************
* Trainings Management
******************************************/

void printTrainingsMenu(ageLevel level) {

	Table menuTraining({ "1 - Friendlys" + string(8, ' ') }, 33 + 12 * (level - 1));
	menuTraining.addNewLine({ "2 - Trainings" });

	Table menuTraining2({ "1 - Training Calendar" }, 33 + 12 * (level - 1) + 9);
	menuTraining2.addNewLine({ "2 - Schedule Training" });
	menuTraining2.addNewLine({ "3 - Register Scheduled Training" });
	menuTraining2.addNewLine({ "4 - Register Not Scheduled Training" });

	
	Table menuTraining3({ "3 - Tournaments" }, 33 + 12 * (level - 1));
	menuTraining3.addNewLine({ "0 - Back to Main Menu" });

	cout << menuTraining << menuTraining2 << menuTraining3;
}

unsigned int menuTrainingsManagement(Level* currentLevel) {

	unsigned int option = 0;
	bool control = false;

	showMainMenu((unsigned int)ageLevelMap.at(currentLevel->getLevelName()) + 2, currentLevel->getYear());
	printTrainingsMenu(ageLevelMap.at(currentLevel->getLevelName()));

	while (!control) {
		try {
			control = readUnsignedInt(option, 0, 4);
		}
		catch (InvalidInput e) {
			printTrainingsMenu(ageLevelMap.at(currentLevel->getLevelName()));
			cout << Table({ e.getMessage() });
		}
	}
	return option;
}

void optionsTrainingsManagement(Club &mainClub, Season* currentSeason, Level* currentLevel) {

	unsigned int option;

	while ((option = menuTrainingsManagement(currentLevel))) {
		string input;
		unsigned int idInput = 0;
		bool control = false;
		bool exitSwitch = false;


		Table showInformation({ "Information" , "Data" });

		Date today;

		switch (option) {
		case 1:             //=========== SHOW CALENDAR   ==============
		{
			showMainMenu(0, currentSeason->getSeasonName());

			if (currentLevel->getAllLevelTrainings().size() == 0) {

				cout << Table({ "There are no Trainings." });
				ignoreLine(false);
				break;
			}

			idInput = 1;
			char order = 'a';

			control = false;
			while (!control) {
				try {
					showMainMenu(0, currentSeason->getSeasonName());
					cout << currentLevel->getTrainingsList((SortCriteria)(idInput - 1), order == 'a' ? ascending : descending, 'a');

					cout << Table({ "Sort by:" , "1. Id", "2a. Date - Ascending", "2d. Date - Descending", "3a. Number of Athletes - Ascending", "3d. Number of Athletes - Descending", "0. Back"}) << endl;

					getline(cin, input);

					if (input.length() == 0) {
						exitSwitch = true;
						break;
					}
					
					stringstream ssTmp(input);

					ssTmp >> idInput;

					ssTmp >> order;

					if (ssTmp.fail() || idInput < 1 || idInput > 3 || (order != 'a' && order != 'd'))
						throw InvalidInput();

					control = false;
				}
				catch (InvalidInput e) {

					showMainMenu(0, currentSeason->getSeasonName());
					cout << currentLevel->getTrainingsList((SortCriteria)(idInput - 1), order == 'a' ? ascending : descending, 'a');

					cout << Table({ e.getMessage() });
					control = false;
				}
			}

			if (exitSwitch) break;

			

			break;
		}
		case 2:             //=======  SCHEDULE TRAINING   ======= 
		{

			// Read Training Date

			showMainMenu(0, currentSeason->getSeasonName());

			Date newTrainingDate;

			control = false;
			while (!control) {
				try {

					

					control = readDate(newTrainingDate, today, currentSeason->getEndDate(), "Please, enter the TRAINING DATE.", "Invalid Date");

					if (newTrainingDate == today) {
						exitSwitch = true;
						break;
					}

					control = true;

				}
				catch (InvalidDate e) {

					showMainMenu(0, currentSeason->getSeasonName());
					cout << Table({ e.getMessage() });

				}
			}

			//If user push ENTER
			if (exitSwitch) break;

			//==========================

			//Mostrar resumo da operacao


			showInformation.addNewLine({ "Date: " , newTrainingDate.str() });

			showMainMenu(0, currentSeason->getSeasonName());

			cout << Table({ "Are you sure you want to schedule this training?" });;

			if (!confirm(showInformation)) {
				break;
			}

			currentLevel->scheduleTraining(newTrainingDate);

			ignoreLine(false, "Training correctly scheduled!");

			mainClub.saveChanges();

		}
		case 3:				//=======  REGISTER SCHEDULED TRAINING  ======= 
		{
			if (currentLevel->getTrainingsReadyToPlay().size() == 0) {

				showMainMenu(0, currentSeason->getSeasonName());
				cout << Table({ "There are no not-registered Trainings." });
				ignoreLine(false);
				break;
			}


			showMainMenu(0, currentSeason->getSeasonName());


			control = false;
			while (!control) {
				try {
					cout << currentLevel->getTrainingsList(date, ascending, 'p');

					cout << Table({ "Please enter the TRAINING ID to register." }) << endl;

					control = readUnsignedInt(idInput, 1, (unsigned int)currentLevel->getTrainingsReadyToPlay().size(), "Invalid Training ID.");

					if (!idInput) {
						exitSwitch = true;
						break;
					}
				}
				catch (InvalidInput e) {

					showMainMenu(0, currentSeason->getSeasonName());

					cout << Table({ e.getMessage() });
					control = false;
				}
			}

			if (exitSwitch) break;

			showMainMenu(0, currentSeason->getSeasonName());

			string playersMissed;
			vector<unsigned int> playersMissedVector;

			//Show players
			cout << Table(currentLevel->showAthletesOfLevel(playerPosition, ascending, true), 0);

			control = false;
			while (!control) {
				try {

					cout << Table({ "Please, enter the athletes who MISSED this training. (Eg: 1 4 7)" }) << endl;

					getline(cin, playersMissed);

					if (playersMissed.length() == 0)
						break;

					stringstream ssPlayers(playersMissed);

					while (!ssPlayers.eof()) {
						unsigned int idPlayer;
						ssPlayers >> idPlayer;

						if (!ssPlayers.fail())
							playersMissedVector.push_back(idPlayer);

					}
					control = true;

				}
				catch (InvalidInput e) {

					showMainMenu(0, currentSeason->getSeasonName());

					cout << Table({ e.getMessage() });

				}

				currentLevel->registerTraining(idInput, playersMissedVector);

				mainClub.saveChanges();

				ignoreLine(false, "Training correctly registed.");
			}
		}
		case 4:				//=======  REGISTER UNSCHEDULED TRAINING  =======
		{
			// Read Training Date


			showMainMenu(0, currentSeason->getSeasonName());

			Date newTrainingDate;

			control = false;
			while (!control) {
				try {


					control = readDate(newTrainingDate, currentSeason->getInitialDate(), today, "Please, enter the TRAINING DATE.", "Invalid Date");

					if (newTrainingDate == today) {
						exitSwitch = true;
						break;
					}

					control = true;

				}
				catch (InvalidDate e) {

					showMainMenu(0, currentSeason->getSeasonName());
					cout << Table({ e.getMessage() });

				}
			}

			//If user push ENTER
			if (exitSwitch) break;

			//==========================
			
			showMainMenu(0, currentSeason->getSeasonName());

			string playersMissed;
			vector<unsigned int> playersMissedVector;

			//Show players
			cout << Table(currentLevel->showAthletesOfLevel(playerPosition, ascending, true), 0);

			control = false;
			while (!control) {
				try {

					cout << Table({ "Please, enter the athletes who MISSED this training. (Eg: 1 4 7)" }) << endl;

					getline(cin, playersMissed);

					stringstream ssPlayers(playersMissed);

					while (!ssPlayers.eof()) {
						unsigned int idPlayer;
						ssPlayers >> idPlayer;

						if (!ssPlayers.fail())
							playersMissedVector.push_back(idPlayer);

					}
					control = true;

				}
				catch (InvalidInput e) {

					showMainMenu(0, currentSeason->getSeasonName());

					cout << Table({ e.getMessage() });

				}

				currentLevel->registerTraining(newTrainingDate, playersMissedVector);

				ignoreLine(false, "Training correctly registed.");
			}




			mainClub.saveChanges();
			break;
		}
		
		case 0:
			break;
		}
	}
}

/******************************************
* Tournaments Management
******************************************/

void printTournamentsMenu(Level* currentLevel) {

	Table menuTournament({ "1 - Friendlys" + string(8, ' ') }, 33 + 12 * (currentLevel->getAgeLevel() - 1));
	menuTournament.addNewLine({ "2 - Trainings" });
	menuTournament.addNewLine({ "3 - Tournaments" });

	cout << menuTournament;

	Table menuTournament2({ "1. New Tournament" }, 33 + 12 * (currentLevel->getAgeLevel() - 1) + 8);

	for (size_t i = 0; i < currentLevel->getTournaments().size(); i++) {
		menuTournament2.addNewLine({ to_string(i + 2) + ". " + currentLevel->getTournaments().at(i)->getName() });
	}

	cout << menuTournament2;

	Table menuTournament3({ "0 - Back" }, 33 + 12 * (currentLevel->getAgeLevel() - 1));

	 cout << menuTournament3;
}

void printOneTournamentMenu(Level* currentLevel, unsigned int tournamentChosen, string seasonName) {
	clearScreen();
	//showMainMenu(0, seasonName);
	
	cout << Table({ currentLevel->getTournaments().at(tournamentChosen)->getName() });;
	cout << Table({ "1 - Table", "2 - Schedule Match", "3 - Call-Up Players", "4 - Register Scheduled Match", "5 - Register Not Scheduled Match", "0 - Back" });

}

unsigned int menuTournamentsManagement(Level* currentLevel) {

	unsigned int option = 0;
	bool control = false;

	showMainMenu((unsigned int)ageLevelMap.at(currentLevel->getLevelName()) + 2, currentLevel->getYear());
	printTournamentsMenu(currentLevel);

	while (!control) {
		try {
			control = readUnsignedInt(option, 0, (unsigned int)currentLevel->getTournaments().size()+1);
		}
		catch (InvalidInput e) {
			printTournamentsMenu(currentLevel);
			cout << Table({ e.getMessage() });
		}
	}
	return option;
}

void optionsTournamentsManagement(Club &mainClub, Season* currentSeason, Level* currentLevel) {

	unsigned int tournamentChosen = 0;
	while ((tournamentChosen = menuTournamentsManagement(currentLevel))) {

		string input;
		bool control = false;
		bool exitSwitch = false;

		Date today;

		Table showInformation({ "Information" , "Data" });

		switch (tournamentChosen) {
		case 0:
			break;
		case 1:  // =========== CREATE NEW TOURNAMENT  ===============
		{
			// Read Tournament's Name

			showMainMenu(0, currentLevel->getYear());

			string newTournamentName;

			control = false;
			while (!control) {
				try {

					cout << Table({ "Please, enter the Tournaments's NAME." }) << endl;

					getline(cin, newTournamentName);

					if (emptyString(newTournamentName)) {
						exitSwitch = true;
						break;
					}

					control = validateName(newTournamentName, 1);


				}
				catch (InvalidInput e) {

					showMainMenu(0, currentLevel->getYear());

					cout << Table({ e.getMessage() });

				}
			}

			//If user push ENTER
			if (exitSwitch) break;

			//==========================

			// Read Tournament Dates

			showMainMenu(0, currentSeason->getSeasonName());

			vector<Date> newTournamentDates;

			control = false;
			while (!control) {
				try {

					newTournamentDates = {};

					control = readDates(newTournamentDates, currentSeason->getInitialDate(), currentSeason->getEndDate(),
							  "Please, enter the TOURNAMENT start and end DATES (Eg: 21/10/2016 12/02/2017).", "Invalid Dates");

					if (newTournamentDates.size() == 0) {
						exitSwitch = true;
						break;
					}
					else if (newTournamentDates.size() != 2) {
						throw InvalidInput("Invalid Dates");
					}

					control = true;

				}
				catch (InvalidInput e) {

					showMainMenu(0, currentSeason->getSeasonName());
					cout << Table({ e.getMessage() });
					continue;

				}
				catch (InvalidDate e) {

					showMainMenu(0, currentSeason->getSeasonName());
					cout << Table({ e.getMessage() });

				}
			}

			//If user push ENTER
			if (exitSwitch) break;

			//==========================

			// Read number of teams

			showMainMenu(0, currentSeason->getSeasonName());

			unsigned int numberOfTeams = 0;

			control = false;
			while (!control) {
				try
				{
					Table tmpTable({ "Information", "Data" });
					tmpTable.addNewLine({ "Tournament Name" , newTournamentName });
					cout << tmpTable;

					cout << Table({ "This Tournament will have how much teams?" }) << endl;

					cout << Table({ "2. Final", "4. Semi-Finals", "8. Quarter-Finals", "16. Round of 16" });

					control = readUnsignedInt(numberOfTeams, 0, 16, "Invalid Number of Teams");

					if (numberOfTeams != 2 && numberOfTeams != 4 && numberOfTeams != 8 && numberOfTeams != 16)
						throw InvalidInput("Invalid Number of Teams");

					// ENTER
					if (!numberOfTeams) {
						exitSwitch = true;
						break;
					}
				}
				catch (InvalidInput e) {

					showMainMenu(0, currentSeason->getSeasonName());

					cout << Table({ e.getMessage() });

				}
			}

			//If user push ENTER
			if (exitSwitch) break;

			//==========================

			// Read Teams to the Tournament
			Table showTeams({ "N", "Name" });

			unsigned int teamCounter = 1;
			showTeams.addNewLine({ to_string(teamCounter), mainClub.getName() });
			vector<string> vectorTeams;
			for (size_t n = 0; n < numberOfTeams-1; n++) {

				// Read Teams

				showMainMenu(0, currentSeason->getSeasonName());
				cout << showTeams;

				string newTeamName;

				control = false;
				while (!control) {
					try {

						cout << Table({ "Please, enter a team NAME to add to tournament." }) << endl;

						getline(cin, newTeamName);

						if (emptyString(newTeamName)) {
							exitSwitch = true;
							break;
						}

						control = validateName(newTeamName, 1);


					}
					catch (InvalidInput e) {

						showMainMenu(0, currentSeason->getSeasonName());

						cout << Table({ e.getMessage() });

					}
				}

				//If user push ENTER
				if (exitSwitch) {
					if (!vectorTeams.size()) break;

					n--;
					n--;
					vectorTeams.pop_back();

					vector<vector<string>> tableVectorTmp = showTeams.getTableVector();
					tableVectorTmp.pop_back();

					vector<bool> blocksTmp = showTeams.getBlocks();
					blocksTmp.pop_back();


					showTeams = Table(tableVectorTmp, blocksTmp, showTeams.getColumsWidth() ,showTeams.getIndentacao());

					exitSwitch = false;
					continue;
				}

				vectorTeams.push_back(newTeamName);

				showTeams.addNewLine({ to_string(++teamCounter), newTeamName });
			}

			//If user push ENTER
			if (exitSwitch) break;

			//========================

			// Ask to Schedule Matches

			showMainMenu(0, currentSeason->getSeasonName());

			unsigned int scheduleMatches = 0;

			control = false;
			while (!control) {
				try {

					cout << Table({ "Do you want to Schedule/Register matches for this Tournament, right now?" }) << endl;

					cout << Table({ "1. YES", "2. NO" });

					control = readUnsignedInt(scheduleMatches, 0, 2);

				}
				catch (InvalidInput e) {

					showMainMenu(0, currentSeason->getSeasonName());

					cout << Table({ e.getMessage() });

				}
			}

			currentLevel->addTournament(newTournamentDates.at(0), newTournamentDates.at(1), vectorTeams, newTournamentName);


			if (scheduleMatches == 1 || scheduleMatches == 0) {

				Tournament* newTournament = currentLevel->getTournaments().at(currentLevel->getTournaments().size() - 1);

				unsigned int idTournamentMatch = 0;

				for (size_t n = 0; n < newTournament->getTournamentClubs().size() / 2; n++) {
					
					//Read Matches
					showMainMenu(0, currentSeason->getSeasonName());

					string tmpMatch;
                    unsigned int idTeam1 = 0;
                    unsigned int idTeam2 = 0;

					//Show matches
					

					vector<vector<string>> newTable = { showTeams.getTableVector().at(0) };
					for (size_t i = 1; i < showTeams.getTableVector().size(); i++) {
						control = false;
						for (size_t j = 0; j < newTournament->getClubsAuxUsed().size(); j++) {

							if (showTeams.getTableVector().at(i).at(1) == newTournament->getTournamentClubs().at(newTournament->getClubsAuxUsed().at(j))->getName()) {
								control = true;
							}
						}
						if (!control)
							newTable.push_back(showTeams.getTableVector().at(i));
					}

					cout << Table(newTable, 0);

					control = false;
					while (!control) {
						try {

							cout << Table({ "Please, enter the Teams IDs to this tournament. (Eg: 1 x 4)" }) << endl;

							getline(cin, tmpMatch);

							if (tmpMatch.length() == 0) {
								exitSwitch = true;
								break;
							}

							stringstream ssPlayers(tmpMatch);

							
							char separator;

							ssPlayers >> idTeam1 >> separator >> idTeam2;

							if (ssPlayers.fail())
								throw InvalidInput(tmpMatch + " is not a valid Match.");

							if (!newTournament->getClubsAuxUsed().empty()) {
								vector<unsigned int> tmpAux = newTournament->getClubsAuxUsed();
								vector<unsigned int>::const_iterator iteClubHome = find(tmpAux.begin(), tmpAux.end(), idTeam1-1);
								vector<unsigned int>::const_iterator iteClubAway = find(tmpAux.begin(), tmpAux.end(), idTeam2-1);
								if (iteClubHome != tmpAux.end() || iteClubAway != tmpAux.end()) {
									throw InvalidInput("One of those clubs was already used before");
								}
							}

							control = true;

						}
						catch (InvalidInput e) {

							showMainMenu(0, currentSeason->getSeasonName());
							cout << Table(newTable, 0);

							cout << Table({ e.getMessage() });

						}
					}

					if (exitSwitch)	break;

					//======================
					// Read Match Date

					Date newMatchDate = Date(1,1,1900);

					showInformation.addNewLine({ "Match: " , newTournament->getTournamentClubs().at(idTeam1-1)->getName() + " vs " + newTournament->getTournamentClubs().at(idTeam2-1)->getName() });

					showMainMenu(0, currentSeason->getSeasonName());
					cout << showInformation;

					control = false;
					while (!control) {
						try {


							control = readDate(newMatchDate, newTournament->getTournamentStartingDate(), newTournament->getTournamentEndingDate(), "Please, enter the MATCH DATE.", "Invalid Date");

							if (newMatchDate == Date(1, 1, 1900)) {
								exitSwitch = true;
								break;
							}

							control = true;

						}
						catch (InvalidDate e) {

							showMainMenu(0, currentSeason->getSeasonName());
							cout << showInformation;

							cout << Table({ e.getMessage() });

						}
					}

					//If user push ENTER
					if (exitSwitch) break;

					// Schedule Match
					if (today < newMatchDate) {
						newTournament->scheduleTournamentMatch(++idTournamentMatch, newMatchDate, idTeam1, idTeam2);
					}
					else {

						//Read Score of Match
						showMainMenu(0, currentSeason->getSeasonName());
						cout << showInformation;

						string score;
						unsigned int homeTeamScore = 0;
						unsigned int awayTeamScore = 0;

						control = false;
						while (!control) {
							try {
								cout << Table({ "Please, enter the SCORE of the Match. (Eg: 2 x 1)" }) << endl;

								getline(cin, score);

								if (score.length() == 0) {
									exitSwitch = true;
									break;
								}

								stringstream ssPlayers(score);


								ssPlayers >> homeTeamScore;

								string separator;
								ssPlayers >> separator;

								ssPlayers >> awayTeamScore;

								if (ssPlayers.fail())
									throw InvalidInput("Invalid Score: " + score + " is not a valid score.");

								control = true;

							}
							catch (InvalidInput e) {

								showMainMenu(0, currentSeason->getSeasonName());

								cout << Table({ e.getMessage() });

							}
						}

						if (exitSwitch)	break;

						//==========================


						vector<unsigned int> playersToCallUpVector;

						// Call-up players
						if (newTournament->getTournamentClubs().at(idTeam1-1)->getName() == mainClub.getName() ||
							newTournament->getTournamentClubs().at(idTeam2-1)->getName() == mainClub.getName()) {

							//Read Players to Call-up
							showMainMenu(0, currentSeason->getSeasonName());

							string playersToCallUp;

							//Show players
							cout << Table(currentLevel->showAthletesOfLevel(playerPosition, ascending, true),0);

							control = false;
							while (!control) {
								try {

									cout << Table({ "Please, enter the ATHLETES IDs to call-up in this match. (Eg: 1 4 7)" }) << endl;

									getline(cin, playersToCallUp);

									if (playersToCallUp.length() == 0) {
										exitSwitch = true;
										break;
									}

									stringstream ssPlayers(playersToCallUp);

									while (!ssPlayers.eof()) {
										unsigned int idPlayer;
										ssPlayers >> idPlayer;

										if (!ssPlayers.fail())
											playersToCallUpVector.push_back(idPlayer);

									}
									control = true;

								}
								catch (InvalidInput e) {

									showMainMenu(0, currentSeason->getSeasonName());

									cout << Table({ e.getMessage() });

								}
							}

							if (exitSwitch)	break;

						}

						newTournament->registerMatch(++idTournamentMatch, newMatchDate, currentLevel, playersToCallUpVector, homeTeamScore, awayTeamScore, idTeam1 - 1, idTeam2 - 1);

					}

					//==========================
				}
			}
			else {


				break;
			}
			mainClub.saveChanges();
			ignoreLine(false, "Tournament correcly created.");
			break;
			
		}
		default:
			optionsTournament(mainClub, currentSeason, currentLevel, tournamentChosen - 2);
		}

	}
}

unsigned int menuTournament(Level* currentLevel, unsigned int tournamentChosen) {

	unsigned int option = 0;
	bool control = false;

	showMainMenu((unsigned int)ageLevelMap.at(currentLevel->getLevelName()) + 2, currentLevel->getYear());
	printOneTournamentMenu(currentLevel, tournamentChosen, currentLevel->getYear());

	while (!control) {
		try {
			control = readUnsignedInt(option, 0, (unsigned int)currentLevel->getTournaments().size());
		}
		catch (InvalidInput e) {
			printTournamentsMenu(currentLevel);
			cout << Table({ e.getMessage() });
		}
	}
	return option;
}

void optionsTournament(Club &mainClub, Season* currentSeason, Level* currentLevel, unsigned int tournamentChosen) {

	unsigned int option;

	while ((option = menuTournament(currentLevel, tournamentChosen)))
	{
		string input;
		unsigned int idInput;
		bool control = false;
		bool exitSwitch = false;

		Tournament* currentTournament = currentLevel->getTournaments().at(tournamentChosen);


		Table showInformation({ "Information" , "Data" });

		Date today;

		switch (option) {
		case 1:             //=========== SHOW TABLE   ==============
		{
			printOneTournamentMenu(currentLevel, tournamentChosen, currentLevel->getYear());

			currentLevel->getTournaments().at(tournamentChosen)->showMatches();
			ignoreLine(false);
			break;
		}
		case 2:             //=======  SCHEDULE MATCH   ======= 
		/*{

			printOneTournamentMenu(currentLevel, tournamentChosen, currentLevel->getYear());

			currentTournament->showMatches();

			control = false;
			while (!control) {
				try {
					cout << Table({ "Please enter the MATCH ID to register." }) << endl;

					control = readUnsignedInt(idInput, 1, currentLevel->getMatchesReadyToPlay().size(), "Invalid Match ID.");

					if (!idInput) {
						exitSwitch = true;
						break;
					}

					if (currentTournament->getMatches().at(idInput)->getPlayed())
						throw InvalidInput("That match was already registed.");
					if (Date() < currentTournament->getMatches().at(idInput)->getMatchDay())
						throw InvalidInput("That match didn't happen yet.");

				}
				catch (InvalidInput e) {

					showMainMenu(0, currentSeason->getSeasonName());
					currentTournament->showMatches();

					cout << Table({ e.getMessage() });
					control = false;
				}
			}

			if (exitSwitch) break;

			//=======================
			cout << Table(newTable, 0);

			control = false;
			while (!control) {
				try {

					cout << Table({ "Please, enter the Teams IDs to this tournament. (Eg: 1 x 4)" }) << endl;

					getline(cin, tmpMatch);

					if (tmpMatch.length() == 0) {
						exitSwitch = true;
						break;
					}

					stringstream ssPlayers(tmpMatch);


					char separator;

					ssPlayers >> idTeam1 >> separator >> idTeam2;

					if (ssPlayers.fail())
						throw InvalidInput(tmpMatch + " is not a valid Match.");

					if (!newTournament->getClubsAuxUsed().empty()) {
						vector<unsigned int> tmpAux = newTournament->getClubsAuxUsed();
						vector<unsigned int>::const_iterator iteClubHome = find(tmpAux.begin(), tmpAux.end(), idTeam1 - 1);
						vector<unsigned int>::const_iterator iteClubAway = find(tmpAux.begin(), tmpAux.end(), idTeam2 - 1);
						if (iteClubHome != tmpAux.end() || iteClubAway != tmpAux.end()) {
							throw InvalidInput("One of those clubs was already used before");
						}
					}

					control = true;

				}
				catch (InvalidInput e) {

					showMainMenu(0, currentSeason->getSeasonName());
					cout << Table(newTable, 0);

					cout << Table({ e.getMessage() });

				}
			}

			if (exitSwitch)	break;

			//======================
			// Read Match Date


			Date newMatchDate;


			printOneTournamentMenu(currentLevel, tournamentChosen, currentLevel->getYear());
			cout << showInformation;

			control = false;
			while (!control) {
				try {


					control = readDate(newMatchDate, today < currentTournament->getTournamentStartingDate() ? currentTournament->getTournamentStartingDate() : today, currentSeason->getEndDate(), "Please, enter the MATCH DATE.", "Invalid Date");

					if (newMatchDate == today) {
						exitSwitch = true;
						break;
					}

					control = true;

				}
				catch (InvalidDate e) {

					printOneTournamentMenu(currentLevel, tournamentChosen, currentLevel->getYear());
					cout << showInformation;

					cout << Table({ e.getMessage() });

				}
			}

			//If user push ENTER
			if (exitSwitch) break;

			//==========================


			currentTournament->scheduleTournamentMatch(idInput,newMatchDate,
				currentTournament->findMatchNode(idInput)->second.first == currentTournament->getInitialPhase() ? )

		}*/
		case 3:             //=======  CALL UP PLAYERS   ======= 
		{

		}
		case 4:				//=======  REGISTER SCHEDULED MATCH  ======= 
		{

		}
		case 5:				//=======  REGISTER NOT SCHEDULED MATCH  ======= 
		{

		}

		case 0:
			break;
		}
	}
}




