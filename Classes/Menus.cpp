/*

João Pinheiro
Leonardo Teixeira

*/

#include "Menus.h"

using namespace std;

void initialInfo(string &clubName) {

    ifstream inStreamClub;
    bool clubExists;
	string clubNameFromUser;

    cout << Table({ "Please, insert the name of the club" });
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
		
        string newClubName;
        cout << Table({ "Ok. let's create the club. Please, insert the name for the new club" });
        getline(cin, clubName);
        
		clearScreen();

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
        
        
        string teste = stringPath((path() + clubName + "/" + year + "/" + "U13" + "/Matches"));
        
        createDirectory(stringPath((path() + clubName + "/" + year + "/" + "U13" + "/Matches")).c_str());
        createDirectory(stringPath((path() + clubName + "/" + year + "/" + "U15" + "/Matches")).c_str());
        createDirectory(stringPath((path() + clubName + "/" + year + "/" + "U17" + "/Matches")).c_str());
        createDirectory(stringPath((path() + clubName + "/" + year + "/" + "U19" + "/Matches")).c_str());
        createDirectory(stringPath((path() + clubName + "/" + year + "/" + "Seniors" + "/Matches")).c_str());
        
        //create info files for levels
        ofstream outfileInfoLevel(stringPath(path() + clubName + "/" + year + "/U13" + "/Athletes.txt").c_str());
        outfileInfoLevel.close();
        outfileInfoLevel.open(stringPath(path() + clubName + "/" + year + "/U13" + "/Coaches.txt").c_str());
        outfileInfoLevel.close();
        outfileInfoLevel.open(stringPath(path() + clubName + "/" + year + "/U13" + "/Matches.txt").c_str());
        outfileInfoLevel.close();
        outfileInfoLevel.open(stringPath(path() + clubName + "/" + year + "/U15" + "/Athletes.txt").c_str());
        outfileInfoLevel.close();
        outfileInfoLevel.open(stringPath(path() + clubName + "/" + year + "/U15" + "/Coaches.txt").c_str());
        outfileInfoLevel.close();
        outfileInfoLevel.open(stringPath(path() + clubName + "/" + year + "/U15" + "/Matches.txt").c_str());
        outfileInfoLevel.close();
        outfileInfoLevel.open(stringPath(path() + clubName + "/" + year + "/U17" + "/Athletes.txt").c_str());
        outfileInfoLevel.close();
        outfileInfoLevel.open(stringPath(path() + clubName + "/" + year + "/U17" + "/Coaches.txt").c_str());
        outfileInfoLevel.close();
        outfileInfoLevel.open(stringPath(path() + clubName + "/" + year + "/U17" + "/Matches.txt").c_str());
        outfileInfoLevel.close();
        outfileInfoLevel.open(stringPath(path() + clubName + "/" + year + "/U19" + "/Athletes.txt").c_str());
        outfileInfoLevel.close();
        outfileInfoLevel.open(stringPath(path() + clubName + "/" + year + "/U19" + "/Coaches.txt").c_str());
        outfileInfoLevel.close();
        outfileInfoLevel.open(stringPath(path() + clubName + "/" + year + "/U19" + "/Matches.txt").c_str());
        outfileInfoLevel.close();
        outfileInfoLevel.open(stringPath(path() + clubName + "/" + year + "/Seniors" + "/Athletes.txt").c_str());
        outfileInfoLevel.close();
        outfileInfoLevel.open(stringPath(path() + clubName + "/" + year + "/Seniors" + "/Coaches.txt").c_str());
        outfileInfoLevel.close();
        outfileInfoLevel.open(stringPath(path() + clubName + "/" + year + "/Seniors" + "/Matches.txt").c_str());
        outfileInfoLevel.close();
        
        newClubName = clubName;
	}

}

bool confirm(vector<vector<string>> confirmationMsg, vector<bool> blocks, vector<int> spacesForColumn, unsigned int indentation) {

	bool resultado = false;
	string answer;
	Table confirmar({ "Press Enter to confirm or any key to turn back." });
	Table msg(confirmationMsg, blocks, spacesForColumn, indentation);
	cout << msg << endl;
	cout << confirmar << endl;


	getline(cin, answer);

	if (answer.size() == 0) {
		resultado = true;
	}


	return resultado;

}


/******************************************
* Initial Menu
******************************************/



void initialOptions(Club &mainClub) {
    unsigned int option;
	
    while ((option = mainMenu()))
        switch (option) {
		case 1: optionsAthletesManagement(mainClub);
                break;
            /*case 2: opcoesGestaoProdutos(supermercado);
                break;
            case 3: opcoesGestaoTransacoes(supermercado);
                break;
            case 4: opcoesRecomendacao(supermercado);
				break;*/
			case 5:
				break;
        }
    //supermercado.saveChanges();
}

unsigned short int mainMenu() {
    unsigned short int option = 0;
    bool control = false;
	Table closeProgram({ "Are you sure you want to quit the program?" });
    while (!control) {
        showMainMenu(0);
        control = readUnsignedShortInt(option, 0, 4);
    }

	if (option == 0 && !confirm(closeProgram.getTableVector(), closeProgram.getBlocks(), closeProgram.getColumsWidth(), closeProgram.getIndentacao())) {
		option = 5;
	}
    return option;
}

void showMainMenu(unsigned short int opcaoChosen) {
    clearScreen();
    Table menu({ "Main Menu" });
    vector<string> headerMenu;
    switch (opcaoChosen) {
        case 0:
			headerMenu = { "1 - Athletes", "2 - Coaches", "3 - Actual Season", "4 - Other Seasons", "0 - Exit" };
            break;
        case 1:
			headerMenu = { "1 - Athletes" + string(11, ' '), "2 - Coaches", "3 - Actual Season", "4 - Other Seasons", "0 - Exit" };
            break;
        case 2:
			headerMenu = { "1 - Athletes", "2 - Coaches" + string(11, ' '), "3 - Actual Season", "4 - Other Seasons", "0 - Exit" };
			break;
        case 3:
			headerMenu = { "1 - Athletes", "2 - Coaches", "3 - Actual Season" + string(11, ' '), "4 - Other Seasons" + string(11, ' '), "0 - Exit" };
			break;
        default:
			headerMenu = { "1 - Athletes", "2 - Coaches", "3 - Actual Season", "4 - Other Seasons", "0 - Exit" };
			break;
    }
    Table optionsMenu(headerMenu);
    cout << menu << endl;
    cout << optionsMenu;
}

/******************************************
 * Athletes Management
 ******************************************/

void printAthletesMenu() {
	clearScreen();
	showMainMenu(1);
	Table menuAthletes({ "1 - Show Athletes" });
	menuAthletes.addNewLine({ "2 - See an Athlete" });
	menuAthletes.addNewLine({ "3 - Add Athlete" });
	menuAthletes.addNewLine({ "4 - Reintroduce Athlete" });
	menuAthletes.addNewLine({ "5 - Remove Athlete" });
	menuAthletes.addNewLine({ "0 - Back to Main Menu" });
	cout << menuAthletes;
}

void printAddAthleteMenu() {
	clearScreen();
	showMainMenu(1);
	Table menuAthletes({ "1 - Show Athletes" });
	menuAthletes.addNewLine({ "2 - See an Athlete     " });
	menuAthletes.addNewLine({ "3 - Add Athlete" });

	Table addAthlete({ "1 - Goalkeeper" }, 28);
	addAthlete.addNewLine({ "2 - Defender" });
	addAthlete.addNewLine({ "3 - Midfielder" });
	addAthlete.addNewLine({ "4 - Forward" });

	Table menuAthletes2({ "4 - Reintroduce Athlete" });
	menuAthletes2.addNewLine({ "5 - Remove Athlete" });
	menuAthletes2.addNewLine({ "0 - Back to Main Menu" });
	cout << menuAthletes << addAthlete << menuAthletes2;
}


unsigned short int menuAthletesManagement() {
    unsigned short int option;
    bool control = false;
    do {
		printAthletesMenu();
        control = readUnsignedShortInt(option, 0, 5);
    } while (!control);
    return option;
}

void  optionsAthletesManagement(Club &mainClub) {
    unsigned int option;
    
    while ((option = menuAthletesManagement())) {
		string input;
		unsigned int idWorker;
        bool control = false;
		bool exitSwitch = false;

		stringstream ss;
		string str;
		Table showInformation({ "Information" , "Data" });
		Table confirmAdd({ "Are you sure you want to add the athlete?" });
		Table confirmRemove({ "Are you sure you want to remove the athlete?" });
		Table confirmReativate({ "Are you sure you want to reativate the athlete?" });


		string newAthleteName;
		string newAthleteBirthDateStr;
		Date newAthleteBirthDate;
		string newAthleteHeight;
		string newAthleteCivilId;
		Date today;

        switch (option) {
            case 1:           //=========== SHOW ATHLETES ==============
                
				clearScreen();
				showMainMenu(0);

                if (mainClub.getAthletes().size() == 0) {
                    
                    cout << Table({"There are no athletes."});
                    ignoreLine(false);
                    break;
                }


                
                mainClub.showAthletes();
                ignoreLine(false);
                break;/*
            case 2:          //============ MOSTRAR UM CLIENTE ============
                
                if (supermercado.getMapIDtoCliente().size() == 0) {
                    
                    clearScreen();
					showMainMenu();
                    cout << Table({"Nao existem clientes."});
                    ignoreLine(false);
                    break;
                }
                
                do {
                    clearScreen();
					showMainMenu(0);
					supermercado.listarClientesOrdemAlfa();
                    Table introIdNome({ "Introduza o ID ou o NOME do cliente." });
                    cout << introIdNome << endl;
                    getline(cin, input);
                    if (stringVazia(input)) {
                        break;
                    }
                    trimString(input);
                    if (isdigit(input.at(0))) {
                        idCliente = stoi(input);
                        clearScreen();
						showMainMenu(0);
                        control = supermercado.mostraInformacaoCliente(idCliente);
                        ignoreLine(false);
                    }
                    else {
                        clearScreen();
						showMainMenu(0);
                        control = supermercado.mostraInformacaoCliente(input);
                        ignoreLine(false);
                    }
                } while (!control);
                break;*/
            case 3:            //=========== ADD ATHLETE ================
                
				
				do {
					printAddAthleteMenu();
					

					unsigned short int position;

					control = false;
					while (!control) {
						try {
							control = readUnsignedShortInt(position, 0, 4);
						}
						catch (InvalidInput e) {
							printAddAthleteMenu();

							cout << Table({ e.getMessage() });

						}
					}
					

					// If user push Enter or 0
					if (!position) {
						exitSwitch = true;
						break;
					}


					// Read Athlete's Name
					clearScreen();
					showMainMenu(0);

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
							clearScreen();
							showMainMenu(0);

							Table printErrorMessage({ e.getMessage() });
							cout << printErrorMessage;

						}
					}

					//If user push ENTER
					if (exitSwitch) break;

					//==========================

					// Read Athlete's Birth Date
					clearScreen();
					showMainMenu(0);

					control = false;
					while (!control) {
						try {


							Table introBirthDate({ "Please, enter the athlete's BIRTH DATE." });
							cout << introBirthDate << endl;


							getline(cin, newAthleteBirthDateStr);

							if (emptyString(newAthleteBirthDateStr)) {
								exitSwitch = true;
								break;
							}

							trimString(newAthleteBirthDateStr);

							newAthleteBirthDate = Date(newAthleteBirthDateStr);

							control = true;

						}
						catch (InvalidDate e) {
							clearScreen();
							showMainMenu(0);

							Table printErrorMessage({ e.getMessage() });
							cout << printErrorMessage;

						}
					}

					//If user push ENTER
					if (exitSwitch) break;

					//==========================

					// Read Athlete's Height

					clearScreen();
					showMainMenu(0);

					unsigned short int heigth;

					control = false;
					while (!control) {
						try {

							Table introHeight({ "Please, enter the athlete's HEIGHT." });
							cout << introHeight << endl;

							control = readUnsignedShortInt(heigth, 100, 250, "Invalid heigth: This value must be between 100 and 250");

							// ENTER
							if (!heigth) {
								exitSwitch = true;
								break;
							}


							
						}
						catch (InvalidInput e) {

							clearScreen();
							showMainMenu(0);

							cout << Table({ e.getMessage() });

						}
					}

					//If user push ENTER
					if (exitSwitch) break;

					//==========================

                    // Read Athlete's Civil ID
                    
                    clearScreen();
                    showMainMenu(0);
                    
                    Table introCivilID({ "Please, enter the athlete's CIVIL ID." });
                    cout << introCivilID << endl;
                    
                    
                    getline(cin, newAthleteCivilId);
                    
                    if (emptyString(newAthleteCivilId)) {
                        exitSwitch = true;
                        break;
                    }
                    
                    trimString(newAthleteCivilId);

					mainClub.addPlayer((Position)position, newAthleteName, newAthleteBirthDate, stoi(newAthleteCivilId), heigth);
					
                    //control = validateName(input);
                    //ignoreLine(false, "Cliente adicionado com sucesso");*/
                } while (!control);

				if (exitSwitch) break;  //Teclar enter apenas, cancela a operacao
				

				//Mostrar resumo da operacao

				showInformation.addNewLine({ "ID: " , to_string(Worker::getLastId() + 1) });  // Mostra o id
                
                showInformation.addNewLine({ "Civil ID: " , newAthleteCivilId }); // Mostra o Nome

				showInformation.addNewLine({ "Name: " , newAthleteName }); // Mostra o Nome
				
				showInformation.addNewLine({ "Birth Date: " , newAthleteBirthDateStr });

				showInformation.addNewLine({ "Level: " , getLevelFromAge(newAthleteBirthDate) });

				clearScreen();
				showMainMenu(0);
								
				cout << confirmAdd;

				if (!confirm(showInformation.getTableVector(), showInformation.getBlocks(), showInformation.getColumsWidth(), showInformation.getIndentacao())) {
					break;
				}
				ignoreLine(false, "Athlete correctly added!");
                mainClub.saveChanges();
                break;
            case 5:            //============  REMOVE ATHLETES ================
                
                if (mainClub.getAthletes().size() == 0) {
                    
                    clearScreen();
                    showMainMenu();
                    cout << Table({"There are no Athletes."});
                    ignoreLine(false);
                    break;
                }
                
                if (mainClub.getAthletes(true).size() == 0) {
                    
                    clearScreen();
                    showMainMenu();
                    cout << Table({"There are no active Athletes."});
                    ignoreLine(false);
                    break;
                    
                }
                
                do {
                    clearScreen();
                    showMainMenu(0);
					mainClub.showAthletes(true);
                    Table introIdNome({ "Please enter the athlete's id to remove." });
                    cout << introIdNome << endl;
                    getline(cin, input);
                    if (emptyString(input)) {
                        break;
                    }

                    trimString(input);
                    
					idWorker = stoi(input);

					if (!mainClub.getAthletes().at(idWorker)->isActive()) {
						cout << Table({ "This Athlete was already remove." });
						ignoreLine(false);
						continue;
					}


					// Show operation summary

					showInformation.addNewLine({ "ID: " , to_string(mainClub.getAthletes().at(idWorker)->getID()) });  // Show id

					showInformation.addNewLine({ "Civil ID: " , to_string(mainClub.getAthletes().at(idWorker)->getCivilID()) }); // Show Civil Id

					showInformation.addNewLine({ "Name: " , mainClub.getAthletes().at(idWorker)->getName()}); // Show Name

					showInformation.addNewLine({ "Birth Date: " , mainClub.getAthletes().at(idWorker)->getBirthdate().str() }); // Show Birth Date

					showInformation.addNewLine({ "Level: " , getLevelFromAge(mainClub.getAthletes().at(idWorker)->getBirthdate()) }); // Show Level

					clearScreen();
					showMainMenu(0);


					cout << confirmRemove;

					if (!confirm(showInformation.getTableVector(), showInformation.getBlocks(), showInformation.getColumsWidth(), showInformation.getIndentacao())) {
						break;
					}

					ignoreLine(false, "Athlete removed correctly");

					control = mainClub.removeAthlete(idWorker);

                } while (!control);
                mainClub.saveChanges();
                break;
			/*case 4:  //================ REATIVAR CLIENTE ==================
				
                if (supermercado.getMapIDtoCliente().size() == 0) {
                    
                    clearScreen();
                    mostrarMenuInicial();
                    cout << Table({"Nao existem clientes."});
                    ignoreLine(false);
                    break;
                }
                
                
                if (!supermercado.existemClientesInactivos()) {
                    
                    clearScreen();
                    mostrarMenuInicial();
                    cout << Table({"Nao existem clientes inactivos."});
                    ignoreLine(false);
                    break;
                    
                }
                
                
                do {
					clearScreen();
					mostrarMenuInicial(0);
					supermercado.listarClientesOrdemAlfaInactivos();
					Table introIdNome({ "Introduza o ID ou o NOME do cliente." });
					cout << introIdNome << endl;
					getline(cin, input);
					if (stringVazia(input)) {
						break;
					}
					trimString(input);
					if (isdigit(input.at(0))) { //  REATIVAR PELO ID
						idCliente = stoi(input);
                        
                        if (supermercado.getMapIDtoCliente().at(idCliente).getStatus()) {
                            cout << Table({"O cliente ja se encontra activo."});
                            ignoreLine(false);
                            continue;
                        }
                        
						clearScreen();
						mostrarMenuInicial(0);
						control = supermercado.reactivarCliente(idCliente);
						
						//Mostrar resumo da operacao

						ss << idCliente;
						str = ss.str();

						mostrarCliente.addNewLine({ "Id de Cliente: " , str });  // Mostra o id

						ss.str("");
						ss << supermercado.getMapIDtoCliente().at(idCliente).getNome();
						str = ss.str();

						mostrarCliente.addNewLine({ "Nome do Cliente: " , str }); // Mostra o Nome

						ss.str("");
						ss << hoje.mostrarData();
						str = ss.str();


						mostrarCliente.addNewLine({ "Cartao de Cliente: " , str });

						clearScreen();
						mostrarMenuInicial(0);


						cout << confirmarReativar;

						if (!confirmar(mostrarCliente.getTableVector(), mostrarCliente.getBlocks(), mostrarCliente.getColumsWidth(), mostrarCliente.getIndentacao())) {
							break;
						}
						ignoreLine(false, "Cliente reativado com sucesso");
					}
					else {  //  REATIVAR PELO NOME
                        
                        if (supermercado.getMapNametoCliente().at(input).getStatus()) {
                            cout << Table({"O cliente ja se encontra activo."});
                            ignoreLine(false);
                            continue;
                        }
                        
						clearScreen();
						mostrarMenuInicial(0);
						control = supermercado.reactivarCliente(input);
						
						//Mostrar resumo da operacao

						ss << supermercado.getMapNametoCliente().at(input);
						str = ss.str();

						mostrarCliente.addNewLine({ "Id de Cliente: " , str });  // Mostra o id

						ss.str("");
						ss << input;
						str = ss.str();

						mostrarCliente.addNewLine({ "Nome do Cliente: " , str }); // Mostra o Nome

						ss.str("");
						ss << hoje.mostrarData();
						str = ss.str();


						mostrarCliente.addNewLine({ "Cartao de Cliente: " , str });

						clearScreen();
						mostrarMenuInicial(0);


						cout << confirmarReativar;

						if (!confirmar(mostrarCliente.getTableVector(), mostrarCliente.getBlocks(), mostrarCliente.getColumsWidth(), mostrarCliente.getIndentacao())) {
							break;
						}
						ignoreLine(false, "Cliente reativado com sucesso");
					}
				} while (!control);
                supermercado.saveChanges();
				break;
            case 0:
                break;*/
        }
    }
}

/******************************************
 * Gestao de Produtos
 ******************************************/

/*unsigned short int menuGestaoProdutos() {
    unsigned short int opcao;
    bool control = false;
    do {
        mostrarMenuInicial(2);
        Table menuProdutos({ "1 - Listar produtos" }, 17);
        menuProdutos.addNewLine({ "2 - Adicionar produto" });
        menuProdutos.addNewLine({ "3 - Reativar produto" });
		menuProdutos.addNewLine({ "4 - Remover produto" });
        menuProdutos.addNewLine({ "0 - Voltar ao menu inicial" });
        cout << menuProdutos;
        control = leUnsignedShortInt(opcao, 0, 4);
    } while (!control);
    return opcao;
}

void opcoesGestaoProdutos(VendeMaisMais &supermercado) {
    unsigned int opcao;
    while ((opcao = menuGestaoProdutos())) {
        string input;
        string nomeProduto;
        bool control = false;
        bool sairDoSwitch = false;
        pair<string, float> pairNomeCusto;
        vector<unsigned int> vectorInteiros;

		stringstream ss;
		string str;
		Table mostrarProduto({ "Informacao" , "Dados" });
		Table mostrarProdutos({ "Nome", "Custo" });

		Table confirmarAdicionar({ "Tem a certeza que pretende adicionar o produto?" });
		Table confirmarEliminar({ "Tem a certeza que pretende eliminar o(s) produto(s)?" });
		Table confirmarReativar({ "Tem a certeza que pretende reativar o(s) produto(s)?" });
        switch (opcao) {
            case 1:     // ============== MOSTRAR PRODUTOS ============
                clearScreen();
                mostrarMenuInicial(0);
                
                if (supermercado.getMapIDtoProduct().size() == 0) {
                    
                    cout << Table({"Nao existem produtos."});
                    ignoreLine(false);
                    break;
                }
                
                supermercado.listarProdutos();
                ignoreLine(false);
                break;
            case 2:     // ============== ADICIONAR PRODUTO ===========
                while (!control) {
                    clearScreen();
                    mostrarMenuInicial(0);
                    control = leStringFloat(pairNomeCusto, "Introduza o nome seguido do custo do produto. (Ex: produto 1.30)");
                    if (!control) {
                        cin.get();
                        continue;
                    }
                    if (pairNomeCusto.first == "" && pairNomeCusto.second == 0.0) {
                        sairDoSwitch = true;
                        break;
                    }
                }
                if (sairDoSwitch) break;  //Teclar enter apenas, cancela a operacao

				//================================================
				//Mostrar resumo da operacao
				//================================================
				ss << pairNomeCusto.first;
				str = ss.str();

				mostrarProduto.addNewLine({ "Nome do produto: " , str });  // Mostra o nome do produto

				ss.str("");
				ss << fixed << setprecision(2) << pairNomeCusto.second;
				str = ss.str();

				mostrarProduto.addNewLine({ "Custo do produto: " , str }); // Mostra o custo


				clearScreen();
				mostrarMenuInicial(0);


				cout << confirmarAdicionar;

				if (!confirmar(mostrarProduto.getTableVector(), mostrarProduto.getBlocks(), mostrarProduto.getColumsWidth(), mostrarProduto.getIndentacao())) {
					break;
				}
				ignoreLine(false, "Produto adicionado com sucesso");

                supermercado.adicionarProduto(pairNomeCusto.first, pairNomeCusto.second);
				supermercado.saveChanges();

                break;
            case 4:    // ================ ELIMINAR PRODUTO ===========
                
                if (supermercado.getMapIDtoProduct().size() == 0) {
                    
                    clearScreen();
                    mostrarMenuInicial();
                    cout << Table({"Nao existem produtos."});
                    ignoreLine(false);
                    break;
                }
                
                if (!supermercado.existemProdutosActivos()) {
                    
                    clearScreen();
                    mostrarMenuInicial();
                    cout << Table({"Nao existem produtos activos."});
                    ignoreLine(false);
                    break;
                    
                }

                while (!control) {
                    clearScreen();
                    mostrarMenuInicial(0);
                    supermercado.listarProdutos(true);
                    control = leVectorInteiros(vectorInteiros, "Introduza os ID's dos produtos a eliminar.");
                    if (!control) {
                        cin.get();
                        continue;
                    }
                    if (vectorInteiros.size() == 0) {
                        sairDoSwitch = true;
                        break;
                    }
                }
                if (sairDoSwitch) break;  //Teclar enter apenas, cancela a operacao

                for (size_t i = 0; i < vectorInteiros.size(); i++) {

					//================================================
					//Mostrar resumo da operacao
					//================================================
					if (vectorInteiros.size() == 1) {
						ss.str("");
						ss << supermercado.getMapIDtoProduct().at(vectorInteiros.at(i)).getNome();
						str = ss.str();

						mostrarProduto.addNewLine({ "Nome do produto: " , str });  // Mostra o nome do produto

						ss.str("");
						ss << supermercado.getMapIDtoProduct().at(vectorInteiros.at(i)).getCusto();
						str = ss.str();

						mostrarProduto.addNewLine({ "Custo do produto: " , str }); // Mostra o custo

						clearScreen();
						mostrarMenuInicial(0);
				
						cout << confirmarEliminar;

					}
					else {

						mostrarProdutos.addNewLine({ supermercado.getMapIDtoProduct().at(vectorInteiros.at(i)).getNome() , to_string(vectorInteiros.at(i)) });  // Mostra o produto
						
						clearScreen();
						mostrarMenuInicial(0);

						cout << confirmarEliminar;

						
					}		
                }

				if (vectorInteiros.size() == 1) {
					if (!confirmar(mostrarProduto.getTableVector(), mostrarProduto.getBlocks(), mostrarProduto.getColumsWidth(), mostrarProduto.getIndentacao())) {
						break;
					}
				}
				else {
					if (!confirmar(mostrarProdutos.getTableVector(), mostrarProdutos.getBlocks(), mostrarProdutos.getColumsWidth(), mostrarProdutos.getIndentacao())) {
						break;
					}
				}
					
				ignoreLine(false, "Produto(s) eliminado(s) com sucesso");
				
				for (size_t i = 0; i < vectorInteiros.size(); i++) {
					supermercado.eliminarProduto(vectorInteiros.at(i));
				}
				supermercado.saveChanges();
                break;

			case 3:    // ================ REATIVAR PRODUTO ===========
				
                if (supermercado.getMapIDtoProduct().size() == 0) {
                    
                    clearScreen();
                    mostrarMenuInicial();
                    cout << Table({"Nao existem produtos."});
                    ignoreLine(false);
                    break;
                }
                
                if (!supermercado.existemClientesInactivos()) {
                    
                    clearScreen();
                    mostrarMenuInicial();
                    cout << Table({"Nao existem produtos inactivos."});
                    ignoreLine(false);
                    break;
                    
                }
                
                
                
                while (!control) {
					clearScreen();
					mostrarMenuInicial(0);
					supermercado.listarProdutos();
					control = leVectorInteiros(vectorInteiros, "Introduza os ID's dos produtos a reativar.");
					if (!control) {
						cin.get();
						continue;
					}
					if (vectorInteiros.size() == 0) {
						sairDoSwitch = true;
						break;
					}
				}
				if (sairDoSwitch) break;  //Teclar enter apenas, cancela a operacao

				for (size_t i = 0; i < vectorInteiros.size(); i++) {

					//================================================
					//Mostrar resumo da operacao
					//================================================
					if (vectorInteiros.size() == 1) {
						ss.str("");
						ss << supermercado.getMapIDtoProduct().at(vectorInteiros.at(i)).getNome();
						str = ss.str();

						mostrarProduto.addNewLine({ "Nome do produto: " , str });  // Mostra o nome do produto

						ss.str("");
						ss << supermercado.getMapIDtoProduct().at(vectorInteiros.at(i)).getCusto();
						str = ss.str();

						mostrarProduto.addNewLine({ "Custo do produto: " , str }); // Mostra o custo

						clearScreen();
						mostrarMenuInicial(0);

						cout << confirmarReativar;

					}
					else {

						mostrarProdutos.addNewLine({ supermercado.getMapIDtoProduct().at(vectorInteiros.at(i)).getNome() , to_string(vectorInteiros.at(i)) });  // Mostra o produto

						clearScreen();
						mostrarMenuInicial(0);

						cout << confirmarReativar;


					}
				}
				if (vectorInteiros.size() == 1) {
					if (!confirmar(mostrarProduto.getTableVector(), mostrarProduto.getBlocks(), mostrarProduto.getColumsWidth(), mostrarProduto.getIndentacao())) {
						break;
					}
				}
				else {
					if (!confirmar(mostrarProdutos.getTableVector(), mostrarProdutos.getBlocks(), mostrarProdutos.getColumsWidth(), mostrarProdutos.getIndentacao())) {
						break;
					}
				}

				ignoreLine(false, "Produto(s) reativado(s) com sucesso");

				for (size_t i = 0; i < vectorInteiros.size(); i++) {
					supermercado.reactivarProduto(vectorInteiros.at(i));
				}
                supermercado.saveChanges();
				break;
                
        }
    }
}*/

/******************************************
 * Gestao de Transacoes
 ******************************************/

/*unsigned short int menuGestaoTransacoes() {
    unsigned short int opcao;
    bool control = false;
    do {
        mostrarMenuInicial(3);
        Table menuProdutos({ "1 - Registar compra" }, 34);
        menuProdutos.addNewLine({ "2 - Listar todas as transacoes" });
        menuProdutos.addNewLine({ "3 - Listar transacoes de um cliente" });
        menuProdutos.addNewLine({ "4 - Listar transacoes por data(s)" });
        menuProdutos.addNewLine({ "5 - Listar transacoes por produto" });
        menuProdutos.addNewLine({ "0 - Voltar ao menu inicial" });
        cout << menuProdutos;
        control = leUnsignedShortInt(opcao, 0, 5);
    } while (!control);
    return opcao;
}

void opcoesGestaoTransacoes(VendeMaisMais & supermercado) {
    
    unsigned int opcao;
    while ((opcao = menuGestaoTransacoes())) {
    
        string nome;
        string input;
        unsigned int idClienteOuProduto = 0;
        bool sairDoSwitch = false;
        bool control = false;
        vector<unsigned int> vetorIdProdutos;
        vector<string> vetorStringDatas;
        bool controlAux = false;

		stringstream ss;
		string str;
		Table mostrarCliente({ "Informacao" , "Dados" });
		Table mostrarTransacao({ "ID do produto", "Nome do produto", "Custo" });

		Table confirmarTransacao({ "Tem a certeza que pretende realizar a transacao?" });

		float total = 0;

        switch (opcao) {
            case 1:      //    =============== REGISTRAR COMPRA ==============
                
                clearScreen();
                mostrarMenuInicial(0);
                if (supermercado.getProdutos().size() == 0) {
                    cout << Table({"Nao existem produtos no supermercado."});
                    ignoreLine(false);
                    break;
                }
                
                if (supermercado.getClientes().size() == 0) {
                    cout << Table({"Nao existem clientes no supermercado."});
                    ignoreLine(false);
                    break;
                }
                
                if (!supermercado.existemClientesActivos()) {
                    
                    clearScreen();
                    mostrarMenuInicial();
                    cout << Table({"Nao existem clientes activos."});
                    ignoreLine(false);
                    break;
                    
                }
                
                if (!supermercado.existemProdutosActivos()) {
                    
                    clearScreen();
                    mostrarMenuInicial();
                    cout << Table({"Nao existem produtos activos."});
                    ignoreLine(false);
                    break;
                    
                }
                
                do {

                    supermercado.listarClientesOrdemAlfa(true); //Mostra clientes e seus respetivos ids
                    Table introIdNome({ "Introduza o ID do cliente." });
                    cout << introIdNome << endl;
                    getline(cin, input);
                    if (stringVazia(input)) {
                        sairDoSwitch = true;
                        break;
                    }
                    trimString(input);
                    if (isdigit(input.at(0))) {
                        idClienteOuProduto = stoi(input);
                        control = supermercado.encontrarCliente(idClienteOuProduto);
                        if (!control) ignoreLine(false);
                    }
                    else {
                        Table erro({ "Esse input nao corresponde a um ID" });
                        cout << erro;
                        //if (!control) break;
                        ignoreLine(false);
                    }
                } while (!control);
                if (sairDoSwitch) break;
                while (!controlAux) {
                    clearScreen();
                    mostrarMenuInicial(0);
                    supermercado.listarProdutos(true);
                    controlAux = leVectorInteiros(vetorIdProdutos, "Introduza os ID's dos produtos a comprar (Ex: 1 3 6)");
                    if (!controlAux) {
                        cin.get();
                    }
                }

				//================================================
				//      Mostrar resumo da operacao
				//================================================

				ss.str("");
				ss << idClienteOuProduto;
				str = ss.str();

				mostrarCliente.addNewLine({ "ID do cliente: " , str });  // Mostra o ID do cliente

				ss.str("");
				ss << supermercado.getMapIDtoCliente().at(idClienteOuProduto).getNome();
				str = ss.str();

				mostrarCliente.addNewLine({ "Nome do cliente: " , str }); // Mostra o nome do cliente

				
				for (size_t i = 0; i < vetorIdProdutos.size(); i++) {
					
					
					if (i == 0) {

						ss.str("");
						ss << setw(7) << fixed << setprecision(2) << right << supermercado.getMapIDtoProduct().at(vetorIdProdutos.at(i)).getCusto();
						str = ss.str();

						mostrarTransacao.addNewLine({ to_string(vetorIdProdutos.at(i)) , 
							supermercado.getMapIDtoProduct().at(vetorIdProdutos.at(i)).getNome(), 
							str });

						total += supermercado.getMapIDtoProduct().at(vetorIdProdutos.at(i)).getCusto();
					}
					else {
						ss.str("");
						ss << setw(7) << fixed << setprecision(2) << right << supermercado.getMapIDtoProduct().at(vetorIdProdutos.at(i)).getCusto();
						str = ss.str();
	
						mostrarTransacao.addDataInSameLine({ to_string(vetorIdProdutos.at(i)) ,
							supermercado.getMapIDtoProduct().at(vetorIdProdutos.at(i)).getNome(),
							str });

						total += supermercado.getMapIDtoProduct().at(vetorIdProdutos.at(i)).getCusto();
					}
				}

				ss.str("");
				ss << setw(7) << fixed << setprecision(2) << right << total;
				str = ss.str();
				
				mostrarTransacao.addNewLine({ "Total: ", to_string(vetorIdProdutos.size()) + " produto(s)" , str });


				clearScreen();
				mostrarMenuInicial(0);


				cout << confirmarTransacao << mostrarCliente;

				if (!confirmar(mostrarTransacao.getTableVector(), mostrarTransacao.getBlocks(), mostrarTransacao.getColumsWidth(), mostrarTransacao.getIndentacao())) {
					break;
				}
				ignoreLine(false, "Transacao efetuada com sucesso");

                supermercado.registarTransacao(idClienteOuProduto, vetorIdProdutos);
                supermercado.saveChanges();
                break;
            case 2:      //  =========== LISTAR TODAS AS TRANSACOES ===========
                clearScreen();
                mostrarMenuInicial(0);
                
                if (supermercado.getTransacoes().size() == 0) {
                    
                    cout << Table({"Nao existem transacoes"});
                    ignoreLine(false);
                    break;
                    
                }
                
                supermercado.listarTransacoes();
                ignoreLine(false);
                break;
            case 3:      // ============ LISTAR TRANSACOES DE UM CLIENTE ======
                
                if (supermercado.getTransacoes().size() == 0) {
                    
                    cout << Table({"Nao existem transacoes"});
                    ignoreLine(false);
                    break;
                    
                }
                
                
                do {
                    clearScreen();
                    mostrarMenuInicial(0);
                    supermercado.listarClientesOrdemAlfa();
                    Table introIdNome({ "Introduza o ID ou o NOME do cliente." });
                    cout << introIdNome << endl;
                    getline(cin, input);
                    if (stringVazia(input)) {
                        //cin.ignore();
                        sairDoSwitch = true;
                        break;
                    }
                    trimString(input);
                    if (isdigit(input.at(0))) {
                        idClienteOuProduto = stoi(input);
                        clearScreen();
                        mostrarMenuInicial(0);
                        control = supermercado.encontrarCliente(idClienteOuProduto);
                        if (!control) continue; //Se o cliente nao existir
                        supermercado.listarTransacoes(idClienteOuProduto);
                        //ignoreLine(false);
                    }
                    else {
                        clearScreen();
                        mostrarMenuInicial(0);
                        control = supermercado.encontrarCliente(input);
                        if (!control) continue; //Se o cliente nao existir
                        idClienteOuProduto = supermercado.getMapNametoCliente().at(input).getId();
                        supermercado.listarTransacoes(idClienteOuProduto);
                        //controlAux = true;
                        //ignoreLine(false);
                    }
                } while (!control);
                if (sairDoSwitch) break;  //Teclar enter apenas, cancela a operacao
                ignoreLine(false);
                break;
            case 4:      // ============ LISTAR TRANSACOES NUMA DATA ==========
                
                
                if (supermercado.getTransacoes().size() == 0) {
                    
                    cout << Table({"Nao existem transacoes"});
                    ignoreLine(false);
                    break;
                    
                }
                
                
                
                while (!controlAux) {
                    clearScreen();
                    mostrarMenuInicial(0);
                    supermercado.listarTransacoes();
                    controlAux = leDatas(vetorStringDatas, "Introduza uma data ou duas datas (intervalo de datas) no formato DD//MM/AAAA.");
                    if (!controlAux) {
                        cin.get();
                        continue;
                    }
                    if (vetorStringDatas.size() == 0) {
                        //cin.ignore();
                        sairDoSwitch = true;
                        break;
                    }
                }
                if (sairDoSwitch) break;  //Teclar enter apenas, cancela a operacao
                if (vetorStringDatas.size() == 2) {
                    clearScreen();
                    mostrarMenuInicial(0);
                    supermercado.listarTransacoes(vetorStringDatas.at(0), vetorStringDatas.at(1), false);
                }
                else {
                    clearScreen();
                    mostrarMenuInicial(0);
                    supermercado.listarTransacoes(vetorStringDatas.at(0));
                }
                ignoreLine(false);
                break;
            case 5:
                
                if (supermercado.getTransacoes().size() == 0) {
                    
                    cout << Table({"Nao existem transacoes"});
                    ignoreLine(false);
                    break;
                    
                }
                
                do {
                    clearScreen();
                    mostrarMenuInicial(0);
                    supermercado.listarProdutos();
                    Table introIdNome({ "Introduza o ID ou o NOME do produto." });
                    cout << introIdNome << endl;                    
                    getline(cin, input);
                    if (stringVazia(input)) {
                        sairDoSwitch = true;
                        break;
                    }
                    trimString(input);
                    if (isdigit(input.at(0))) {
                        idClienteOuProduto = stoi(input);
                        clearScreen();
                        mostrarMenuInicial(0);
                        control = supermercado.encontrarProduto(idClienteOuProduto);
                        if (!control) continue; //Se o produto nao existir
                        supermercado.listarTransacoesProduto(idClienteOuProduto);
                        //ignoreLine(false);
                    }
                    else {
                        clearScreen();
                        mostrarMenuInicial(0);
                        control = supermercado.encontrarProduto(input);
                        if (!control) continue; //Se o cliente nao existir
                        idClienteOuProduto = supermercado.getMapNametoCliente().at(input).getId();
                        supermercado.listarTransacoes(idClienteOuProduto);
                        //controlAux = true;
                        //ignoreLine(false);
                    }
                } while (!control);
                if (sairDoSwitch) break;  //Teclar enter apenas, cancela a operacao
                ignoreLine(false);
                break;
        }
    }
}*/

/******************************************
 * Gestao de Recomendacao
 ******************************************/

/*unsigned short int menuRecomendacao() {
    unsigned short int opcao;
    bool control = false;
    do {
        mostrarMenuInicial(4);
        Table menuProdutos({ "1 - Listar sugestoes para todos os clientes" }, 53);
        menuProdutos.addNewLine({ "2 - Mostrar sugestao de produto para um cliente" });
        menuProdutos.addNewLine({ "3 - Listar sugestoes para os N piores clientes" });
        menuProdutos.addNewLine({ "0 - Voltar ao menu inicial" });
        cout << menuProdutos;
        control = leUnsignedShortInt(opcao, 0, 3);
    } while (!control);
    return opcao;
}

void opcoesRecomendacao(VendeMaisMais & supermercado) {
    unsigned int opcao;
    
    if (supermercado.getClientes().size() == 0) {
        cout << Table({"Nao existem clientes no supermercado."});
        ignoreLine(false);
        return;
    }
    
    if (!supermercado.existemClientesActivos()) {
        cout << Table({"Nao existem clientes activos no supermercado."});
        ignoreLine(false);
        return;
    }
    
    if (supermercado.getProdutos().size() == 0) {
        cout << Table({"Nao existem produtos no supermercado."});
        ignoreLine(false);
        return;
    }
    
    if (!supermercado.existemProdutosActivos()) {
        cout << Table({"Nao existem produtos activos no supermercado."});
        ignoreLine(false);
        return;
    }
    
    if (supermercado.getTransacoes().size() == 0) {
        clearScreen();
        mostrarMenuInicial(0);
        cout << Table({"Nao existem compras efectuadas no supermercado, nao e possivel fazer recomendacoes."});
        ignoreLine(false);
        return;
    }
    
    bool transacoesProdutosActivos = false;
    
    for (size_t i = 0; i < supermercado.getTransacoes().size(); i++) {
        
        for (size_t j = 0; j < supermercado.getTransacoes().at(i).getProdutosProduto().size(); j++) {
            
            if (supermercado.getProdutos().at(supermercado.getTransacoes().at(i).getProdutosProduto().at(j).getProdutoId()).getStatus())  {
                
                transacoesProdutosActivos = true;
                
            }
            
        }
        
        
    }
    
    if (!transacoesProdutosActivos) {
        clearScreen();
        mostrarMenuInicial(0);
        cout << Table({"Nao existem compras efectuadas no supermercado com produtos activos, nao e possivel fazer recomendacoes."});
        ignoreLine(false);
        return;
    }
    
	
	while ((opcao = menuRecomendacao())) {
        
		string input;
		unsigned int idCliente;
		bool control = false;
		switch (opcao) {
		case 1:  //================== LISTAR TODAS AS RECOMENDACOES ============
			clearScreen();
			mostrarMenuInicial(0);
			supermercado.listarRecomendacoes();
			ignoreLine(false);
			break;
		case 2: //================== MOSTRAR RECOMENDACAO DE UM CLIENTE ========
			do {
				clearScreen();
				mostrarMenuInicial(0);
                supermercado.listarClientesOrdemAlfa();
				Table introIdNome({ "Introduza o ID ou o NOME do cliente." });
				cout << introIdNome << endl;
				getline(cin, input);
				if (stringVazia(input)) {
					break;
				}
				trimString(input);
				if (isdigit(input.at(0))) {
					idCliente = stoi(input);
					clearScreen();
					mostrarMenuInicial(0);
					control = supermercado.mostraMensagemRecomendacaoCliente(idCliente);
					ignoreLine(false);
				}
				else {
					clearScreen();
					mostrarMenuInicial(0);
					control = supermercado.mostraMensagemRecomendacaoCliente(input);
					ignoreLine(false);
				}
			} while (!control);
			break;
		case 3:  //================== MOSTRAR RECOMENDACAO DOS N PIORES CLIENTES ========
			do {
				clearScreen();
				mostrarMenuInicial(0);
                supermercado.listarClientesOrdemAlfa();
				Table introN({ "Introduza N para mostrar as recomendacoes dos N piores clientes." });
				cout << introN << endl;
				getline(cin, input);
				if (stringVazia(input)) {
					break;
				}
				trimString(input);

				//control = leUnsignedInt(idCliente, 1, supermercado.getMapIDtoCliente().size(), "Numero de clientes invalido");//idCLiente = N

				

				if (isdigit(input.at(0))) {
					idCliente = stoi(input);
					clearScreen();
					mostrarMenuInicial(0);
					supermercado.listarRecomendacoes(supermercado.calcularBottomN(idCliente));
					control = true;
					ignoreLine(false);
				}
				else {
	
					Table erro({ "Valor invalido" });
					cout << erro;
					control = false;
					ignoreLine(false);
				}
			} while (!control);

			break;
		}
	}
}*/
