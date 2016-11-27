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

void showMainMenu(unsigned short int optionChosen = 0, string seasonName = Date().str());

void optionsAthletesManagement(Club &footballClub, string seasonName = to_string(Date().getYear()));

void optionsCoachesManagement(Club &footballClub, string seasonName = to_string(Date().getYear()));

void optionsLevelsManagement(Club &mainClub, Season* currentSeason, Level* currentLevel);

unsigned int menuAthletesManagement(string seasonName);

unsigned int menuCoachesManagement(string seasonName);

unsigned int menuLevelsManagement(Level* currentLevel);

void printFriendlysMenu(ageLevel level);

unsigned int menuFriendlysManagement(Level* currentLevel);

void optionsFriendlysManagement(Club &mainClub, Season* currentSeason, Level* currentLevel);


void printTrainingsMenu(ageLevel level);

unsigned int menuTrainingsManagement(Level* currentLevel);

void optionsTrainingsManagement(Club &mainClub, Season* currentSeason, Level* currentLevel);



unsigned int menuTournament(Level* currentLevel, unsigned int tournamentChosen);

void optionsTournament(Club &mainClub, Season* currentSeason, Level* currentLevel, unsigned int tournamentChosen);

void optionsTournamentsManagement(Club &mainClub, Season* currentSeason, Level* currentLevel);

unsigned int menuTournamentsManagement(Level* currentLevel);

void printOneTournamentMenu(Level* currentLevel, unsigned int tournamentChosen);

void printTournamentsMenu(Level* currentLevel);

/*void listarClientesOrdemAlfabetica(VendeMaisMais & supermercado);

void listarProdutos(VendeMaisMais & supermercado);*/

/*void opcoesGestaoTransacoes(VendeMaisMais & supermercado);

void opcoesRecomendacao(VendeMaisMais & supermercado);

void showInitialMenu(unsigned short int opcaoEscolhida = 0);

void opcoesGestaoProdutos(VendeMaisMais &supermercado);*/

