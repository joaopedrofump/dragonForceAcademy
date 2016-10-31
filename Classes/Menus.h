/*

T7G02
Jo�o Pinheiro
Leonardo Teixeira

*/


#pragma once

#include "Club.hpp"

using namespace std;

bool initialInfo(string & fileSeasons);

bool confirm(vector<vector<string>> confirmationMsg, vector<bool> blocks, vector<int> spacesForColumn, unsigned int indentation);

void initialOptions(Club & footballClub);

unsigned short int mainMenu();

void showMainMenu(unsigned short int optionChosen = 0);

void optionsAthletesManagement(Club & footballClubo);

/*void listarClientesOrdemAlfabetica(VendeMaisMais & supermercado);

void listarProdutos(VendeMaisMais & supermercado);*/

/*void opcoesGestaoTransacoes(VendeMaisMais & supermercado);

void opcoesRecomendacao(VendeMaisMais & supermercado);

void showInitialMenu(unsigned short int opcaoEscolhida = 0);

void opcoesGestaoProdutos(VendeMaisMais &supermercado);*/
