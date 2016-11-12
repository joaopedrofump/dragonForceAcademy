/*

T7G02
João Pinheiro
Leonardo Teixeira

*/


#pragma once

#include "Club.hpp"

using namespace std;

void initialInfo(string& clubName);

bool confirm(const Table &message);

void initialOptions(Club & footballClub);

unsigned short int mainMenu();

void printAddAthleteMenu();

void printAthletesMenu();

void showMainMenu(unsigned short int optionChosen = 0);

void optionsAthletesManagement(Club & footballClubo);

/*void listarClientesOrdemAlfabetica(VendeMaisMais & supermercado);

void listarProdutos(VendeMaisMais & supermercado);*/

/*void opcoesGestaoTransacoes(VendeMaisMais & supermercado);

void opcoesRecomendacao(VendeMaisMais & supermercado);

void showInitialMenu(unsigned short int opcaoEscolhida = 0);

void opcoesGestaoProdutos(VendeMaisMais &supermercado);*/

