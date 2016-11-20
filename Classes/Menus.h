/*

T7G02
Jo�o Pinheiro
Leonardo Teixeira

*/


#pragma once

#include "Club.hpp"

using namespace std;

class Season;

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Initial information. </summary>
///
/// <remarks>	Lu�s, 20/11/2016. </remarks>
///
/// <param name="clubName">	[in,out] Name of the club. </param>
////////////////////////////////////////////////////////////////////////////////////////////////////

void initialInfo(string& clubName);

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Confirms the given message. </summary>
///
/// <remarks>	Lu�s, 20/11/2016. </remarks>
///
/// <param name="message">	The message. </param>
///
/// <returns>	True if it succeeds, false if it fails. </returns>
////////////////////////////////////////////////////////////////////////////////////////////////////

bool confirm(const Table &message);

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Displays initial options. </summary>
///
/// <remarks>	Lu�s, 20/11/2016. </remarks>
///
/// <param name="footballClub">	[in,out] The football club. </param>
////////////////////////////////////////////////////////////////////////////////////////////////////

void initialOptions(Club & footballClub);

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Main menu. </summary>
///
/// <remarks>	Lu�s, 20/11/2016. </remarks>
///
/// <param name="seasonName">	Name of the season. </param>
///
/// <returns>	An int. </returns>
////////////////////////////////////////////////////////////////////////////////////////////////////

unsigned short int mainMenu(string seasonName);

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Print add athlete menu. </summary>
///
/// <remarks>	Lu�s, 20/11/2016. </remarks>
///
/// <param name="seasonName">	Name of the season. </param>
////////////////////////////////////////////////////////////////////////////////////////////////////

void printAddAthleteMenu(string seasonName);

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Print athletes menu. </summary>
///
/// <remarks>	Lu�s, 20/11/2016. </remarks>
///
/// <param name="seasonName">	Name of the season. </param>
////////////////////////////////////////////////////////////////////////////////////////////////////

void printAthletesMenu(string seasonName);

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Print coaches menu. </summary>
///
/// <remarks>	Lu�s, 20/11/2016. </remarks>
///
/// <param name="seasonName">	Name of the season. </param>
////////////////////////////////////////////////////////////////////////////////////////////////////

void printCoachesMenu(string seasonName);

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Shows the main menu. </summary>
///
/// <remarks>	Lu�s, 20/11/2016. </remarks>
///
/// <param name="optionChosen">	(Optional) The option chosen. </param>
/// <param name="seasonName">  	(Optional) Name of the season. </param>
////////////////////////////////////////////////////////////////////////////////////////////////////

void showMainMenu(unsigned short int optionChosen = 0, string seasonName = Date().str());

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Displays athletes management options. </summary>
///
/// <remarks>	Lu�s, 20/11/2016. </remarks>
///
/// <param name="footballClub">	[in,out] The football club. </param>
/// <param name="seasonName">  	(Optional) Name of the season. </param>
////////////////////////////////////////////////////////////////////////////////////////////////////

void optionsAthletesManagement(Club &footballClub, string seasonName = to_string(Date().getYear()));

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Displays coaches management options. </summary>
///
/// <remarks>	Lu�s, 20/11/2016. </remarks>
///
/// <param name="footballClub">	[in,out] The football club. </param>
/// <param name="seasonName">  	(Optional) Name of the season. </param>
////////////////////////////////////////////////////////////////////////////////////////////////////

void optionsCoachesManagement(Club &footballClub, string seasonName = to_string(Date().getYear()));

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Displays levels management options. </summary>
///
/// <remarks>	Lu�s, 20/11/2016. </remarks>
///
/// <param name="mainClub">			[in,out] The main club. </param>
/// <param name="currentSeason">	[in,out] If non-null, the current season. </param>
/// <param name="currentLevel"> 	[in,out] If non-null, the current level. </param>
////////////////////////////////////////////////////////////////////////////////////////////////////

void optionsLevelsManagement(Club &mainClub, Season* currentSeason, Level* currentLevel);

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Displays the athletes management menu. </summary>
///
/// <remarks>	Lu�s, 20/11/2016. </remarks>
///
/// <param name="seasonName">	Name of the season. </param>
///
/// <returns>	An int. </returns>
////////////////////////////////////////////////////////////////////////////////////////////////////

unsigned int menuAthletesManagement(string seasonName);

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Displays the coaches management menu. </summary>
///
/// <remarks>	Lu�s, 20/11/2016. </remarks>
///
/// <param name="seasonName">	Name of the season. </param>
///
/// <returns>	An int. </returns>
////////////////////////////////////////////////////////////////////////////////////////////////////

unsigned int menuCoachesManagement(string seasonName);

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Displays the levels management menu. </summary>
///
/// <remarks>	Lu�s, 20/11/2016. </remarks>
///
/// <param name="currentLevel">	[in,out] If non-null, the current level. </param>
///
/// <returns>	An int. </returns>
////////////////////////////////////////////////////////////////////////////////////////////////////

unsigned int menuLevelsManagement(Level* currentLevel);

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Print friendly matches menu. </summary>
///
/// <remarks>	Lu�s, 20/11/2016. </remarks>
///
/// <param name="level">	The level. </param>
////////////////////////////////////////////////////////////////////////////////////////////////////

void printFriendlysMenu(ageLevel level);

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Displays the friendly matches management menu. </summary>
///
/// <remarks>	Lu�s, 20/11/2016. </remarks>
///
/// <param name="currentLevel">	[in,out] If non-null, the current level. </param>
///
/// <returns>	An int. </returns>
////////////////////////////////////////////////////////////////////////////////////////////////////

unsigned int menuFriendlysManagement(Level* currentLevel);

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Friendly matches management options. </summary>
///
/// <remarks>	Lu�s, 20/11/2016. </remarks>
///
/// <param name="mainClub">			[in,out] The main club. </param>
/// <param name="currentSeason">	[in,out] If non-null, the current season. </param>
/// <param name="currentLevel"> 	[in,out] If non-null, the current level. </param>
////////////////////////////////////////////////////////////////////////////////////////////////////

void optionsFriendlysManagement(Club &mainClub, Season* currentSeason, Level* currentLevel);

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Print trainings menu. </summary>
///
/// <remarks>	Lu�s, 20/11/2016. </remarks>
///
/// <param name="level">	The level. </param>
////////////////////////////////////////////////////////////////////////////////////////////////////

void printTrainingsMenu(ageLevel level);

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Displays the trainings management menu. </summary>
///
/// <remarks>	Lu�s, 20/11/2016. </remarks>
///
/// <param name="currentLevel">	[in,out] If non-null, the current level. </param>
///
/// <returns>	An int. </returns>
////////////////////////////////////////////////////////////////////////////////////////////////////

unsigned int menuTrainingsManagement(Level* currentLevel);

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Trainings management options. </summary>
///
/// <remarks>	Lu�s, 20/11/2016. </remarks>
///
/// <param name="mainClub">			[in,out] The main club. </param>
/// <param name="currentSeason">	[in,out] If non-null, the current season. </param>
/// <param name="currentLevel"> 	[in,out] If non-null, the current level. </param>
////////////////////////////////////////////////////////////////////////////////////////////////////

void optionsTrainingsManagement(Club &mainClub, Season* currentSeason, Level* currentLevel);

/*void listarClientesOrdemAlfabetica(VendeMaisMais & supermercado);

void listarProdutos(VendeMaisMais & supermercado);*/

/*void opcoesGestaoTransacoes(VendeMaisMais & supermercado);

void opcoesRecomendacao(VendeMaisMais & supermercado);

void showInitialMenu(unsigned short int opcaoEscolhida = 0);

void opcoesGestaoProdutos(VendeMaisMais &supermercado);*/

