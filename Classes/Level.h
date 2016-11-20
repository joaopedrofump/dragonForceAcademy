#pragma once

#include "Goalkeeper.hpp"
#include "Match.hpp"
#include "Training.hpp"
#include "Tournament.hpp"

class Club;
class Training;




class Level {
private:
	/// <summary>	The parent club. </summary>
	Club* parentClub;
	/// <summary>	The level enum. </summary>
	ageLevel levelEnum;
    /// <summary>	Name of the level. </summary>
    string levelName;
    /// <summary>	Pathname of the path to level folder. </summary>
    string pathToLevelFolder;
    /// <summary>	The path to level athletes file. </summary>
    string pathToLevelAthletesFile;
    /// <summary>	The path to level coaches file. </summary>
    string pathToLevelCoachesFile;
    /// <summary>	The path to level matches file. </summary>
    string pathToLevelMatchesFile;
    /// <summary>	Pathname of the path to level matches folder. </summary>
    string pathToLevelMatchesFolder;
    /// <summary>	The path to level trainings file. </summary>
    string pathToLevelTrainingsFile;
    /// <summary>	The path to level tournaments file. </summary>
    string pathToLevelTournamentsFile;
    /// <summary>	Pathname of the path to level tournaments folder. </summary>
    string pathToLevelTournamentsFolder;
    /// <summary>	The year of season. </summary>
    string yearOfSeason;

    /// <summary>	Identifier for the last match. </summary>
    unsigned int lastMatchId;
    /// <summary>	The level matches. </summary>
    vector<Match*> levelMatches;
    /// <summary>	The level trainings. </summary>
    vector<Training*> levelTrainings;

    /// <summary>	The level main coach. </summary>
    int levelMainCoach;
	/// <summary>	The coaches identifiers vector. </summary>
	vector<unsigned int> coachesIdsVector;
	/// <summary>	The map information players. </summary>
	map<unsigned int, Info*> mapInfoPlayers;

	/// <summary>	The minimum age. </summary>
	unsigned int minAge;
	/// <summary>	The maximum age. </summary>
	unsigned int maxAge;

	/// <summary>	The minimum height. </summary>
	char minHeight;
	/// <summary>	The tournaments. </summary>
	vector<Tournament*> tournaments;

public:

	//Level(ageLevel ageLevelName, vector<Coach*> coachesVector, map<Athlete*, Info*> mapInfoSeason);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Constructor. </summary>
	///
	/// <remarks>	Luís, 20/11/2016. </remarks>
	///
	/// <param name="yearOfSeason">		 	The year of season. </param>
	/// <param name="pathToSeasonFolder">	Pathname of the path to season folder. </param>
	/// <param name="levelName">		 	Name of the level. </param>
	/// <param name="parentClub">		 	[in,out] If non-null, the parent club. </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	Level(string yearOfSeason, string pathToSeasonFolder, string levelName, Club* parentClub);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Gets minimum age. </summary>
	///
	/// <remarks>	Luís, 20/11/2016. </remarks>
	///
	/// <returns>	The minimum age. </returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	unsigned int getMinAge() const;

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Gets maximum age. </summary>
	///
	/// <remarks>	Luís, 20/11/2016. </remarks>
	///
	/// <returns>	The maximum age. </returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	unsigned int getMaxAge() const;

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Gets minimum height. </summary>
	///
	/// <remarks>	Luís, 20/11/2016. </remarks>
	///
	/// <returns>	The minimum height. </returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	char getMinHeight() const;

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    /// <summary>	Gets the map containing the athletes performance informations. </summary>
    ///
    /// <remarks>	Luís, 20/11/2016. </remarks>
    ///
    /// <returns>	Null if it fails, else the map containing the athletes performance informations. </returns>
    ////////////////////////////////////////////////////////////////////////////////////////////////////

    map<unsigned int, Info*> getMapInfoPlayers() const;

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    /// <summary>	Gets the coaches. </summary>
    ///
    /// <remarks>	Luís, 20/11/2016. </remarks>
    ///
    /// <returns>	The coaches. </returns>
    ////////////////////////////////////////////////////////////////////////////////////////////////////

    vector<unsigned int> getCoaches() const;

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    /// <summary>	Adds an athlete to level. </summary>
    ///
    /// <remarks>	Luís, 20/11/2016. </remarks>
    ///
    /// <param name="playerInfo">	[in,out] If non-null, information describing the player. </param>
    ///
    /// <returns>	Null if it fails, else a pointer to a Level. </returns>
    ////////////////////////////////////////////////////////////////////////////////////////////////////

    Level* addAthleteToLevel(pair<unsigned int, Info*> playerInfo);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Adds a coach to level to 'mainCoach'. </summary>
	///
	/// <remarks>	Luís, 20/11/2016. </remarks>
	///
	/// <param name="idCoach">  	The identifier coach. </param>
	/// <param name="mainCoach">	(Optional) True to main coach. </param>
	///
	/// <returns>	Null if it fails, else a pointer to a Level. </returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	Level* addCoachToLevel(unsigned int idCoach, bool mainCoach = false);

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    /// <summary>	Gets the tournaments. </summary>
    ///
    /// <remarks>	Luís, 20/11/2016. </remarks>
    ///
    /// <returns>	Null if it fails, else the tournaments. </returns>
    ////////////////////////////////////////////////////////////////////////////////////////////////////

    vector<Tournament*> getTournaments() const;

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    /// <summary>	Gets level name. </summary>
    ///
    /// <remarks>	Luís, 20/11/2016. </remarks>
    ///
    /// <returns>	The level name. </returns>
    ////////////////////////////////////////////////////////////////////////////////////////////////////

    string getLevelName() const;

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    /// <summary>	Gets main coach identifier. </summary>
    ///
    /// <remarks>	Luís, 20/11/2016. </remarks>
    ///
    /// <returns>	The main coach identifier. </returns>
    ////////////////////////////////////////////////////////////////////////////////////////////////////

    int getMainCoachId() const;

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Gets the year. </summary>
	///
	/// <remarks>	Luís, 20/11/2016. </remarks>
	///
	/// <returns>	The year. </returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	string getYear() const;

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    /// <summary>	Gets path to level folder. </summary>
    ///
    /// <remarks>	Luís, 20/11/2016. </remarks>
    ///
    /// <returns>	The path to level folder. </returns>
    ////////////////////////////////////////////////////////////////////////////////////////////////////

    string getPathToLevelFolder() const;

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    /// <summary>	Gets path to level athletes file. </summary>
    ///
    /// <remarks>	Luís, 20/11/2016. </remarks>
    ///
    /// <returns>	The path to level athletes file. </returns>
    ////////////////////////////////////////////////////////////////////////////////////////////////////

    string getPathToLevelAthletesFile() const;

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    /// <summary>	Gets path to level coaches file. </summary>
    ///
    /// <remarks>	Luís, 20/11/2016. </remarks>
    ///
    /// <returns>	The path to level coaches file. </returns>
    ////////////////////////////////////////////////////////////////////////////////////////////////////

    string getPathToLevelCoachesFile() const;

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    /// <summary>	Gets path to level matches file. </summary>
    ///
    /// <remarks>	Luís, 20/11/2016. </remarks>
    ///
    /// <returns>	The path to level matches file. </returns>
    ////////////////////////////////////////////////////////////////////////////////////////////////////

    string getPathToLevelMatchesFile() const;

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    /// <summary>	Gets path to level matches folder. </summary>
    ///
    /// <remarks>	Luís, 20/11/2016. </remarks>
    ///
    /// <returns>	The path to level matches folder. </returns>
    ////////////////////////////////////////////////////////////////////////////////////////////////////

    string getPathToLevelMatchesFolder() const;

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    /// <summary>	Gets the last match identifier. </summary>
    ///
    /// <remarks>	Luís, 20/11/2016. </remarks>
    ///
    /// <returns>	The last match identifier. </returns>
    ////////////////////////////////////////////////////////////////////////////////////////////////////

    unsigned int getLastMatchId() const;

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    /// <summary>	Updates the last match identifier. </summary>
    ///
    /// <remarks>	Luís, 20/11/2016. </remarks>
    ////////////////////////////////////////////////////////////////////////////////////////////////////

    void updateLastMatchId();

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    /// <summary>	Gets all level matches. </summary>
    ///
    /// <remarks>	Luís, 20/11/2016. </remarks>
    ///
    /// <param name="onlyNotPlayed">	(Optional) True if only not played. </param>
    ///
    /// <returns>	Null if it fails, else all level matches. </returns>
    ////////////////////////////////////////////////////////////////////////////////////////////////////

    vector<Match*> getAllLevelMatches(bool onlyNotPlayed = false) const;

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Gets matches ready to play. </summary>
	///
	/// <remarks>	Luís, 20/11/2016. </remarks>
	///
	/// <returns>	Null if it fails, else the matches ready to play. </returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	vector<Match*> getMatchesReadyToPlay() const;

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Gets trainings ready be made. </summary>
	///
	/// <remarks>	Luís, 20/11/2016. </remarks>
	///
	/// <returns>	Null if it fails, else the trainings ready to play. </returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	vector<Training*> getTrainingsReadyToPlay() const;

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Shows the athletes of level. </summary>
	///
	/// <remarks>	Luís, 20/11/2016. </remarks>
	///
	/// <param name="onlyAvailable">	(Optional) True if only available. </param>
	///
	/// <returns>	A Table. </returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	Table showAthletesOfLevel(bool onlyAvailable = false) const;

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    /// <summary>	Gets all level trainings. </summary>
    ///
    /// <remarks>	Luís, 20/11/2016. </remarks>
    ///
    /// <param name="onlyNotPlayed">	(Optional) True if only not played. </param>
    ///
    /// <returns>	Null if it fails, else all level trainings. </returns>
    ////////////////////////////////////////////////////////////////////////////////////////////////////

    vector<Training*> getAllLevelTrainings(bool onlyNotPlayed = false) const;

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    /// <summary>	Adds a match to level. </summary>
    ///
    /// <remarks>	Luís, 20/11/2016. </remarks>
    ///
    /// <param name="newMatch">	[in,out] If non-null, a match specifying the new. </param>
    ///
    /// <returns>	Null if it fails, else a pointer to a Level. </returns>
    ////////////////////////////////////////////////////////////////////////////////////////////////////

    Level* addMatchToLevel(Match* newMatch);

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    /// <summary>	Adds a training to level. </summary>
    ///
    /// <remarks>	Luís, 20/11/2016. </remarks>
    ///
    /// <param name="newTraining">	[in,out] If non-null, the new training. </param>
    ///
    /// <returns>	Null if it fails, else a pointer to a Level. </returns>
    ////////////////////////////////////////////////////////////////////////////////////////////////////

    Level* addTrainingToLevel(Training* newTraining);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Shows the matches. </summary>
	///
	/// <remarks>	Luís, 20/11/2016. </remarks>
	///
	/// <param name="matches">	[in,out] If non-null, the matches. </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	void showMatches(vector<Match*> matches);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Shows the match. </summary>
	///
	/// <remarks>	Luís, 20/11/2016. </remarks>
	///
	/// <param name="matchToShow">	[in,out] If non-null, the match to show. </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	void showMatch(Match* matchToShow);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Shows the trainings. </summary>
	///
	/// <remarks>	Luís, 20/11/2016. </remarks>
	///
	/// <param name="matches">	[in,out] If non-null, the matches. </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	void showTrainings(vector<Training*> matches);

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    /// <summary>	Sort trainings. </summary>
    ///
    /// <remarks>	Luís, 20/11/2016. </remarks>
    ////////////////////////////////////////////////////////////////////////////////////////////////////

    void sortTrainings();

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    /// <summary>	Saves the level trainings. </summary>
    ///
    /// <remarks>	Luís, 20/11/2016. </remarks>
    ////////////////////////////////////////////////////////////////////////////////////////////////////

    void saveLevelTrainings() const;

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    /// <summary>	Saves the level tournaments. </summary>
    ///
    /// <remarks>	Luís, 20/11/2016. </remarks>
    ////////////////////////////////////////////////////////////////////////////////////////////////////

    void saveLevelTournaments() const;

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    /// <summary>	Schedule training. </summary>
    ///
    /// <remarks>	Luís, 20/11/2016. </remarks>
    ///
    /// <param name="trainingDate">	The training date. </param>
    ////////////////////////////////////////////////////////////////////////////////////////////////////

    void scheduleTraining(Date trainingDate);
    
 

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    /// <summary>	Registers scheduled training. </summary>
    ///
    /// <remarks>	Luís, 20/11/2016. </remarks>
    ///
    /// <param name="trainingId">	 	Identifier for the training. </param>
    /// <param name="missingPlayers">	The missing players. </param>
    ////////////////////////////////////////////////////////////////////////////////////////////////////

    void registerTraining(unsigned int trainingId, vector<unsigned int> missingPlayers);
   

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    /// <summary>	Registers non scheduled training. </summary>
    ///
    /// <remarks>	Luís, 20/11/2016. </remarks>
    ///
    /// <param name="trainingDate">  	The training date. </param>
    /// <param name="missingPlayers">	The missing players. </param>
    ////////////////////////////////////////////////////////////////////////////////////////////////////

    void registerTraining(Date trainingDate, vector<unsigned int> missingPlayers);
    
    
    //! Get the all the trainings of the level.
    /*!
     \param criteria criteria enum argument: id = sorted by id, date = sorted by date, numberOfPlayers = sorted by number of players who trained
     \param order order enum argument: ascending = sorted ascending, descending = sorted descending
     \param listType char argument: a = all trainings, p = past trainings, r = registed trainings, n = trainings not registered, f = future trainings
	 \return Returns a vector of string vectors where each string vector contains the list of trainings attributes
     */
    
	Table getTrainingsList(SortCriteria criteria = date, SortOrder order = ascending, char listType = 'a') const;

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    /// <summary>	Adds a tournament. </summary>
    ///
    /// <remarks>	Luís, 20/11/2016. </remarks>
    ///
    /// <param name="initialDate">	  	The initial date. </param>
    /// <param name="endDate">		  	The end date. </param>
    /// <param name="tournamentClubs">	The tournament clubs. </param>
    /// <param name="name">			  	The name. </param>
    ////////////////////////////////////////////////////////////////////////////////////////////////////

    void addTournament(Date initialDate, Date endDate, vector<string> tournamentClubs, string name);

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    /// <summary>	Gets tournament matches. </summary>
    ///
    /// <remarks>	Luís, 20/11/2016. </remarks>
    ///
    /// <param name="tournamentId">	Identifier for the tournament. </param>
    ///
    /// <returns>	The tournament matches. </returns>
    ////////////////////////////////////////////////////////////////////////////////////////////////////

    vector<vector<string>> getTournamentMatches(unsigned int tournamentId) const;

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    /// <summary>	Filter players. </summary>
    ///
    /// <remarks>	Luís, 20/11/2016. </remarks>
    ///
    /// <param name="originalPlayerIdsVector">	The original player identifiers vector. </param>
    ///
    /// <returns>	A vector of players ids; </returns>
    ////////////////////////////////////////////////////////////////////////////////////////////////////

    vector<unsigned int> filterPlayers(vector<unsigned int> originalPlayerIdsVector) const;

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    /// <summary>	Gets the parent club. </summary>
    ///
    /// <remarks>	Luís, 20/11/2016. </remarks>
    ///
    /// <returns>	Null if it fails, else the parent club. </returns>
    ////////////////////////////////////////////////////////////////////////////////////////////////////

    Club* getParentClub() const;
    
};
