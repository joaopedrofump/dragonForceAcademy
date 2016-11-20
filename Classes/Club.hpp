#pragma once

#include "Goalkeeper.hpp"
#include "Forward.hpp"

class Season;
class Match;
class Level;


/// <summary>	The coach type map. </summary>
extern const map<string, CoachType> coachTypeMap; //
/// <summary>	The age level map. </summary>
extern const map<string, ageLevel> ageLevelMap; //

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Confirms the given message. </summary>
///
/// <remarks>	Luís, 20/11/2016. </remarks>
///
/// <param name="message">	The message. </param>
///
/// <returns>	True if it succeeds, false if it fails. </returns>
////////////////////////////////////////////////////////////////////////////////////////////////////


extern bool confirm(const Table &message);

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Shows the main menu. </summary>
///
/// <remarks>	Luís, 20/11/2016. </remarks>
///
/// <param name="optionChosen">	The option chosen. </param>
/// <param name="seasonName">  	Name of the season. </param>
////////////////////////////////////////////////////////////////////////////////////////////////////

extern void showMainMenu(unsigned short int optionChosen, string seasonName);

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	A club. </summary>
///
/// <remarks>	Luís, 20/11/2016. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

class Club {

	
	/// <summary>	True to program club. </summary>
	bool programClub;
	/// <summary>	club's name. </summary>
	string clubName;
	/// <summary>	workers' map. </summary>
	map<unsigned int, Worker*> allWorkers;
	/// <summary>	vector that includes all played season. </summary>
	vector<Season*> seasons;
	/// <summary>	number of seasons played. </summary>
	unsigned int numberOfSeasons;
    /// <summary>	path to the club's folder. </summary>
    string pathToClubFolder;
    /// <summary>	path to the athletes' file. </summary>
    string pathToClubAthletesFile;
    /// <summary>	path to the coaches' file. </summary>
    string pathToClubCoachesFile;
    /// <summary>	path to the club's info file. </summary>
    string pathToClubInfoFile;







public:


	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Club's Constructor. </summary>
	///
	/// <remarks>	Luís, 20/11/2016. </remarks>
	///
	/// <param name="clubName">	Name of the club. </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	Club(string clubName);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Club's Constructor. </summary>
	///
	/// <remarks>	Luís, 20/11/2016. </remarks>
	///
	/// <param name="clubName">	Name of the club. </param>
	/// <param name="empty">   	(Optional) True to empty. </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	Club(string clubName, bool empty = false);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Gets the club's name. </summary>
	///
	/// <remarks>	Luís, 20/11/2016. </remarks>
	///
	/// <returns>	The name. </returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////


	/*!
	*	This is a method that gets the club's name
	*/

	string getName() const;

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Gets the workers' vector. </summary>
	///
	/// <remarks>	Luís, 20/11/2016. </remarks>
	///
	/// <returns>	Null if it fails, else gets the workers. </returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	map<unsigned int, Worker*> getWorkers() const;

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Gets the seasons' vector. </summary>
	///
	/// <remarks>	Luís, 20/11/2016. </remarks>
	///
	/// <returns>	Null if it fails, else gets the seasons. </returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	vector<Season*> getSeasons() const;

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Adds a player. </summary>
	///
	/// <remarks>	Luís, 20/11/2016. </remarks>
	///
	/// <param name="pos">			The position. </param>
	/// <param name="name">			The name. </param>
	/// <param name="birthdate">	The birthdate. </param>
	/// <param name="height">   	The height. </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	void addPlayer(Position pos, string name, Date birthdate, unsigned char height);


	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Adds a player to the club, putting the player in the respective season and level. </summary>
	///
	/// <remarks>	Luís, 20/11/2016. </remarks>
	///
	/// <param name="pos">			The position. </param>
	/// <param name="name">			The name. </param>
	/// <param name="birthdate">	The birthdate. </param>
	/// <param name="civilID">  	Identifier for the civil. </param>
	/// <param name="height">   	The height. </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	void addPlayer(Position pos, string name, Date birthdate, unsigned int civilID, unsigned char height);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Removes the athlete by his id. </summary>
	///
	/// <remarks>	Luís, 20/11/2016. </remarks>
	///
	/// <param name="athleteId">	Identifier for the athlete. </param>
	///
	/// <returns>	True if it finds the athlete and removes it, false if it doesn't find the player. </returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	bool removeAthlete(unsigned int athleteId);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Reativates an athlete. </summary>
	///
	/// <remarks>	Luís, 20/11/2016. </remarks>
	///
	/// <param name="athleteId">	Identifier for the athlete. </param>
	///
	/// <returns>	True if it finds the player and reativates him, false if it doesn't find the player. </returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	bool reativateAthlete(unsigned int athleteId);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Edits the athlete's atributes. </summary>
	///
	/// <remarks>	Luís, 20/11/2016. </remarks>
	///
	/// <param name="athleteId">   	Identifier for the athlete. </param>
	/// <param name="newName">	   	Name of the new. </param>
	/// <param name="newBirthDate">	The new birth date. </param>
	/// <param name="newHeight">   	Height of the new. </param>
	/// <param name="newCivilID">  	Identifier for the new civil. </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	void editPlayer(unsigned int athleteId, string newName, Date newBirthDate, unsigned int newHeight, unsigned int newCivilID);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Gets the athletes. </summary>
	///
	/// <remarks>	Luís, 20/11/2016. </remarks>
	///
	/// <param name="onlyActives">	(Optional) True to only actives. </param>
	///
	/// <returns>	Null if it fails, else gets the athletes. </returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	map<unsigned int, Worker*> getAthletes(bool onlyActives = false) const;


	

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Gets the inactives from the coaches map. </summary>
	///
	/// <remarks>	Luís, 20/11/2016. </remarks>
	///
	/// <param name="workersType">	(Optional) Type of the workers. </param>
	///
	/// <returns>	Null if it fails, else gets the inactives. </returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////


	map<unsigned int, Worker*> getInactives(unsigned char workersType = 0) const;

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Gets the coaches. </summary>
	///
	/// <remarks>	Luís, 20/11/2016. </remarks>
	///
	/// <param name="onlyActives">	(Optional) True to only actives. </param>
	///
	/// <returns>	Null if it fails, else gets the coaches. </returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	map<unsigned int, Worker*> getCoaches(bool onlyActives = false) const;

	

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Shows all the athletes. </summary>
	///
	/// <remarks>	Luís, 20/11/2016. </remarks>
	///
	/// <param name="onlyActives">	(Optional) True to only actives. </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	
	/*!
	*	This is a method that gets the inactive players from the workers' map
	*/
	//map<unsigned int, Worker*> getInactives() const;

	/*!
	*	This is a method that gets the coaches from the workers' map
	*/
	//map<unsigned int, Worker*> getCoaches() const;

	/*!
	*	This is a method that shows all the athletes of the club
	*/

	void showAthletes(bool onlyActives = false) const;
	

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Shows the athlete by his id. </summary>
	///
	/// <remarks>	Luís, 20/11/2016. </remarks>
	///
	/// <param name="id">	The identifier. </param>
	///
	/// <returns>	True if it finds the player, false if it fails. </returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	bool showAthlete(unsigned int id) const;

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Shows the inactive athletes. </summary>
	///
	/// <remarks>	Luís, 20/11/2016. </remarks>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	void showAthletesInactives() const;

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Adds a coach. </summary>
	///
	/// <remarks>	Luís, 20/11/2016. </remarks>
	///
	/// <param name="position"> 	The position. </param>
	/// <param name="name">			The name. </param>
	/// <param name="birthdate">	The birthdate. </param>
	/// <param name="civilID">  	Identifier for the civil. </param>
	/// <param name="level">		The level. </param>
	/// <param name="mainCoach">	(Optional) True to main coach. </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	void addCoach(CoachType position, string name, Date birthdate, unsigned int civilID, ageLevel level, bool mainCoach = false);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Removes the coach by coachId. </summary>
	///
	/// <remarks>	Luís, 20/11/2016. </remarks>
	///
	/// <param name="coachId">	Identifier for the coach. </param>
	///
	/// <returns>	True if it finds the coach, false if it fails. </returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	bool removeCoach(unsigned int coachId);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Reativates a coach. </summary>
	///
	/// <remarks>	Luís, 20/11/2016. </remarks>
	///
	/// <param name="coachId">	Identifier for the coach. </param>
	///
	/// <returns>	True if it finds an inactive coach, false if it fails. </returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	bool reativateCoach(unsigned int coachId);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Shows the coaches. </summary>
	///
	/// <remarks>	Luís, 20/11/2016. </remarks>
	///
	/// <param name="onlyActives">	(Optional) True to only actives. </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	void showCoaches(bool onlyActives = false) const;

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Shows the inactive coaches. </summary>
	///
	/// <remarks>	Luís, 20/11/2016. </remarks>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	void showCoachesInactives() const;

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    /// <summary>	Edits a coach. </summary>
    ///
    /// <remarks>	Luís, 20/11/2016. </remarks>
    ///
    /// <param name="coachId">	   	Identifier for the coach. </param>
    /// <param name="newName">	   	Name of the new. </param>
    /// <param name="newBirthDate">	The new birth date. </param>
    /// <param name="newCivilID">  	Identifier for the new civil. </param>
    /// <param name="newCoachType">	Type of the new coach. </param>
    ////////////////////////////////////////////////////////////////////////////////////////////////////

    void editCoach(unsigned int coachId, string newName, Date newBirthDate, unsigned int newCivilID, unsigned int newCoachType);

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    /// <summary>	Query if this object is the program club. </summary>
    ///
    /// <remarks>	Luís, 20/11/2016. </remarks>
    ///
    /// <returns>	True if program club, false if not. </returns>
    ////////////////////////////////////////////////////////////////////////////////////////////////////

    bool isProgramClub() const;

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Saves the changesmade by the user. </summary>
	///
	/// <remarks>	Luís, 20/11/2016. </remarks>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	void saveChanges();
    
	

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Gets path to the club's folder. </summary>
	///
	/// <remarks>	Luís, 20/11/2016. </remarks>
	///
	/// <returns>	The path to the club's folder. </returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	string getPathToClubFolder() const;

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Gets path to the club athletes file. </summary>
	///
	/// <remarks>	Luís, 20/11/2016. </remarks>
	///
	/// <returns>	The path to the club athletes file. </returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	string getPathToClubAthletesFile() const;
    

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Gets path to the club coaches file. </summary>
	///
	/// <remarks>	Luís, 20/11/2016. </remarks>
	///
	/// <returns>	The path to the club coaches file. </returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	string getPathToClubCoachesFile() const;
   

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Gets path to the club information file. </summary>
	///
	/// <remarks>	Luís, 20/11/2016. </remarks>
	///
	/// <returns>	The path to the club information file. </returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	string getPathToClubInfoFile() const;

	

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Searches for the worker by civil identifier. </summary>
	///
	/// <remarks>	Luís, 20/11/2016. </remarks>
	///
	/// <param name="civilID">	Civil identifier. </param>
	///
	/// <returns>	The found worker by civil identifier. </returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	int findWorkerByCivilID(unsigned int civilID);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Updates the ecg. </summary>
	///
	/// <remarks>	Luís, 20/11/2016. </remarks>
	///
	/// <param name="athleteID">	Identifier for the athlete. </param>
	/// <param name="result">   	True to result. </param>
	///
	/// <returns>	True if it succeeds, false if it fails. </returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	bool updateECG(unsigned int athleteID, bool result);

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    /// <summary>	Schedule match. </summary>
    ///
    /// <remarks>	Luís, 20/11/2016. </remarks>
    ///
    /// <param name="opponentClub">	The opponent club. </param>
    /// <param name="matchDate">   	The match date. </param>
    /// <param name="level">	   	[in,out] If non-null, the level. </param>
    /// <param name="type">		   	The match type. </param>
    ////////////////////////////////////////////////////////////////////////////////////////////////////



    void scheduleMatch(string opponentClub, Date matchDate, Level* level, MatchType type);
    
    //convocar jogadores para jogo agendado

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    /// <summary>	Call up players for a scheduled match. </summary>
    ///
    /// <remarks>	Luís, 20/11/2016. </remarks>
    ///
    /// <param name="matchId">	   	Identifier for the match. </param>
    /// <param name="matchPlayers">	The match players. </param>
    /// <param name="level">	   	[in,out] If non-null, the level. </param>
    ////////////////////////////////////////////////////////////////////////////////////////////////////

    void callUpPlayers(string matchId, vector<unsigned int> matchPlayers, Level* level);
    
    //convocar jogadores para jogo não agendado

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    /// <summary>	Call up players for a non scheduled match. </summary>
    ///
    /// <remarks>	Luís, 20/11/2016. </remarks>
    ///
    /// <param name="opponentClub">	The opponent club. </param>
    /// <param name="matchDate">   	The match date. </param>
    /// <param name="level">	   	[in,out] If non-null, the level. </param>
    /// <param name="type">		   	The type. </param>
    /// <param name="matchPlayers">	The match players. </param>
    ////////////////////////////////////////////////////////////////////////////////////////////////////

    void callUpPlayers(string opponentClub, Date matchDate, Level* level, MatchType type, vector<unsigned int> matchPlayers);
    
    //registar jogo já agendado com performance de jogadores (para mais tarde)

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    /// <summary>	Registers a scheduled match and the match players performance. </summary>
    ///
    /// <remarks>	Luís, 20/11/2016. </remarks>
    ///
    /// <param name="matchId">			Identifier for the match. </param>
    /// <param name="level">			[in,out] If non-null, the level. </param>
    /// <param name="homeTeamScore">	The home team score. </param>
    /// <param name="awayTeamScore">	The away team score. </param>
    /// <param name="matchPlayers"> 	[in,out] If non-null, the match players. </param>
    ////////////////////////////////////////////////////////////////////////////////////////////////////

    void registerMatch(string matchId, Level* level, unsigned int homeTeamScore, unsigned int awayTeamScore, map<unsigned int, Info*> matchPlayers);
    
    //registar jogo não agendado com performance de jogadores (para mais tarde)

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    /// <summary>	Registers a non scheduled match and the match players performance. </summary>
    ///
    /// <remarks>	Luís, 20/11/2016. </remarks>
    ///
    /// <param name="opponentClub"> 	The opponent club. </param>
    /// <param name="matchDate">		The match date. </param>
    /// <param name="level">			[in,out] If non-null, the level. </param>
    /// <param name="type">				The type. </param>
    /// <param name="homeTeamScore">	The home team score. </param>
    /// <param name="awayTeamScore">	The away team score. </param>
    /// <param name="matchPlayers"> 	[in,out] If non-null, the match players. </param>
    ////////////////////////////////////////////////////////////////////////////////////////////////////

    void registerMatch(string opponentClub, Date matchDate, Level* level, MatchType type, unsigned int homeTeamScore, unsigned int awayTeamScore, map<unsigned int, Info*> matchPlayers);
    
    //registar jogo já agendado sem performance de jogadores (para já)

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    /// <summary>	Registers a sheduled match without the match players perforamnce. </summary>
    ///
    /// <remarks>	Luís, 20/11/2016. </remarks>
    ///
    /// <param name="matchId">			Identifier for the match. </param>
    /// <param name="level">			[in,out] If non-null, the level. </param>
    /// <param name="homeTeamScore">	The home team score. </param>
    /// <param name="awayTeamScore">	The away team score. </param>
    /// <param name="matchPlayers"> 	The match players. </param>
    ////////////////////////////////////////////////////////////////////////////////////////////////////

    void registerMatch(string matchId, Level* level, unsigned int homeTeamScore, unsigned int awayTeamScore, vector<unsigned int> matchPlayers);
    
    //registar jogo não agendado sem performance de jogadores (para já)
    void registerMatch(string opponentClub, Date matchDate, Level* level, MatchType type, unsigned int homeTeamScore, unsigned int awayTeamScore, vector<unsigned int> matchPlayers);

    
    
    void scheduleTraining(Date trainingDate, Level* level);
    
    //registar treino já agendado
    void registerTraining(unsigned int trainingId, Level* level, vector<unsigned int> missingPlayers);
    
    //registar treino não agendado
    void registerTraining(Date trainingDate, Level* level, vector<unsigned int> missingPlayers);
    

};
