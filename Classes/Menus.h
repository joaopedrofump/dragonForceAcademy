/*

T7G02
João Pinheiro
Leonardo Teixeira

*/


#pragma once

#include "Club.hpp"

using namespace std;

class Season;

void initialInfo(string& clubName);

bool confirm(const Table &message);

void initialOptions(Club & footballClub);

unsigned short int mainMenu(string seasonName);

void printAddAthleteMenu(string seasonName);

void printAthletesMenu(string seasonName);

void printCoachesMenu(string seasonName);

void showMainMenu(unsigned short int optionChosen = 0, string seasonName = "Main Menu");

void optionsAthletesManagement(Club &footballClub, string seasonName = to_string(Date().getYear()));

void optionsCoachesManagement(Club &footballClub, string seasonName = to_string(Date().getYear()));

void optionsLevelsManagement(Club &mainClub, Season* currentSeason, Level* currentLevel);

unsigned int menuAthletesManagement(string seasonName);

unsigned int menuCoachesManagement(string seasonName);

unsigned short int menuLevelsManagement(Level* currentLevel);

/*void listarClientesOrdemAlfabetica(VendeMaisMais & supermercado);

void listarProdutos(VendeMaisMais & supermercado);*/

/*void opcoesGestaoTransacoes(VendeMaisMais & supermercado);

void opcoesRecomendacao(VendeMaisMais & supermercado);

void showInitialMenu(unsigned short int opcaoEscolhida = 0);

void opcoesGestaoProdutos(VendeMaisMais &supermercado);*/

