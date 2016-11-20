#pragma once

#include "Match.hpp"
#include "Club.hpp"

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Values that represent phases. </summary>
///
/// <remarks>	Luís, 20/11/2016. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

enum Phase {
    EightOfFinals = 4,
    QuarterFinals = 3,
    SemiFinals = 2,
    Final = 1
};

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Gets the phase string map. </summary>
///
/// <value>	The phase string map. </value>
////////////////////////////////////////////////////////////////////////////////////////////////////

const map<Phase,string> phaseStringMap {
    {EightOfFinals, "EightOfFinals"},
    {QuarterFinals, "QuarterFinals"},
    {SemiFinals, "SemiFinals"},
    {Final, "Final"}
};

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Tournament binary tree; </summary>
///
/// <remarks>	Luís, 20/11/2016. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

typedef pair<pair<unsigned int,unsigned int>, pair<Phase, Match*>> nodeMatch;

class Level;

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	A tournament. </summary>
///
/// <remarks>	Luís, 20/11/2016. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

class Tournament {

	/// <summary>	The tournament starting date. </summary>
	Date tournamentStartingDate;
	/// <summary>	The tournament ending date. </summary>
	Date tournamentEndingDate;
    /// <summary>	The clubs. </summary>
    vector<Club*> clubs;
    /// <summary>	The clubs auxiliary used. </summary>
    vector<unsigned int> clubsAuxUsed;
    /// <summary>	The tournament tree. </summary>
    BinaryTree<nodeMatch> tournamentTree;
    /// <summary>	The winner. </summary>
    Club* winner;
    /// <summary>	The initial phase. </summary>
    Phase initialPhase;
    /// <summary>	Number of matches. </summary>
    unsigned int numberOfMatches;
    /// <summary>	The name. </summary>
    string name;
    /// <summary>	The identifier counter. </summary>
    static unsigned int idCounter;
    /// <summary>	The identifier. </summary>
    unsigned int id;

public:

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Constructor. </summary>
	///
	/// <remarks>	Luís, 20/11/2016. </remarks>
	///
	/// <param name="tournamentStartingDate">	The tournament starting date. </param>
	/// <param name="tournamentEndingDate">  	The tournament ending date. </param>
	/// <param name="tournamentClubs">		 	The tournament clubs. </param>
	/// <param name="programClub">			 	[in,out] If non-null, the program club. </param>
	/// <param name="name">					 	The name. </param>
	/// <param name="id">					 	(Optional) The identifier. </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	Tournament(Date tournamentStartingDate, Date tournamentEndingDate, vector<string> tournamentClubs, Club* programClub, string name, unsigned int id = 0);

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    /// <summary>	Constructor. </summary>
    ///
    /// <remarks>	Luís, 20/11/2016. </remarks>
    ///
    /// <param name="inStream">		  	[in,out] Stream to read data from the club file.  </param>
    /// <param name="tournamentTree"> 	[in,out] The tournament tree. </param>
    /// <param name="tournamentLevel">	[in,out] If non-null, the tournament level. </param>
    ////////////////////////////////////////////////////////////////////////////////////////////////////

    Tournament(ifstream &inStream, ifstream &tournamentTree, Level* tournamentLevel);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Destructor. </summary>
	///
	/// <remarks>	Luís, 20/11/2016. </remarks>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	~Tournament() {};

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    /// <summary>	Gets the name. </summary>
    ///
    /// <remarks>	Luís, 20/11/2016. </remarks>
    ///
    /// <returns>	The name. </returns>
    ////////////////////////////////////////////////////////////////////////////////////////////////////

    string getName() const;

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Gets tournament starting date. </summary>
	///
	/// <remarks>	Luís, 20/11/2016. </remarks>
	///
	/// <returns>	The tournament starting date. </returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	Date getTournamentStartingDate() const;

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Gets tournament ending date. </summary>
	///
	/// <remarks>	Luís, 20/11/2016. </remarks>
	///
	/// <returns>	The tournament ending date. </returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	Date getTournamentEndingDate() const;

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    /// <summary>	Fill tournament tree. </summary>
    ///
    /// <remarks>	Luís, 20/11/2016. </remarks>
    ///
    /// <param name="finalPhase">	The final phase. </param>
    ///
    /// <returns>	A BinaryTree&lt;nodeMatch&gt; </returns>
    ////////////////////////////////////////////////////////////////////////////////////////////////////

    BinaryTree<nodeMatch> fillTournamentTree(unsigned int finalPhase);

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    /// <summary>	Searches for the first match node. </summary>
    ///
    /// <remarks>	Luís, 20/11/2016. </remarks>
    ///
    /// <param name="tournamentMatchId">	Identifier for the tournament match. </param>
    ///
    /// <returns>	Null if it fails, else the found match node. </returns>
    ////////////////////////////////////////////////////////////////////////////////////////////////////

    nodeMatch* findMatchNode(unsigned int tournamentMatchId);

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    /// <summary>	Gets the identifier. </summary>
    ///
    /// <remarks>	Luís, 20/11/2016. </remarks>
    ///
    /// <returns>	The identifier. </returns>
    ////////////////////////////////////////////////////////////////////////////////////////////////////

    unsigned int getId() const;

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    /// <summary>	Gets tournament clubs. </summary>
    ///
    /// <remarks>	Luís, 20/11/2016. </remarks>
    ///
    /// <returns>	Null if it fails, else the tournament clubs. </returns>
    ////////////////////////////////////////////////////////////////////////////////////////////////////

    vector<Club*> getTournamentClubs() const;

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    /// <summary>	Gets tournament tree. </summary>
    ///
    /// <remarks>	Luís, 20/11/2016. </remarks>
    ///
    /// <returns>	The tournament tree. </returns>
    ////////////////////////////////////////////////////////////////////////////////////////////////////

    const BinaryTree<nodeMatch>& getTournamentTree() const;

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    /// <summary>	Gets tournament matches. </summary>
    ///
    /// <remarks>	Luís, 20/11/2016. </remarks>
    ///
    /// <returns>	The tournament matches. </returns>
    ////////////////////////////////////////////////////////////////////////////////////////////////////

    vector<vector<string>> getTournamentMatches() const;
    //para agendar um de uma fase posterior a fase inicial do torneio chamar funcao com dois ultimos parametros a 0

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    /// <summary>	Schedule tournament match. </summary>
    ///
    /// <remarks>	Luís, 20/11/2016. </remarks>
    ///
    /// <param name="tournamentMatchId">	Identifier for the tournament match. </param>
    /// <param name="matchDate">			The match date. </param>
    /// <param name="homeTeamIndex">		(Optional) Zero-based index of the home team. </param>
    /// <param name="awayTeamIndex">		(Optional) Zero-based index of the away team. </param>
    ////////////////////////////////////////////////////////////////////////////////////////////////////

    void scheduleTournamentMatch(unsigned int tournamentMatchId, Date matchDate, unsigned int homeTeamIndex = 0, unsigned int awayTeamIndex = 0);
    //convocar jogadores para jogo agendado

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    /// <summary>	Call up players. </summary>
    ///
    /// <remarks>	Luís, 20/11/2016. </remarks>
    ///
    /// <param name="tournamentMatchId">	Identifier for the tournament match. </param>
    /// <param name="matchPlayers">			The match players. </param>
    ////////////////////////////////////////////////////////////////////////////////////////////////////

    void callUpPlayers(unsigned int tournamentMatchId, vector<unsigned int> matchPlayers);
    //convocar jogadores para jogo não agendado
    //para agendar um de uma fase posterior a fase inicial do torneio chamar funcao com dois ultimos parametros a 0

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    /// <summary>	Call up players. </summary>
    ///
    /// <remarks>	Luís, 20/11/2016. </remarks>
    ///
    /// <param name="tournamentMatchId">	Identifier for the tournament match. </param>
    /// <param name="matchDate">			The match date. </param>
    /// <param name="level">				[in,out] If non-null, the level. </param>
    /// <param name="matchPlayers">			The match players. </param>
    /// <param name="homeTeamIndex">		(Optional) Zero-based index of the home team. </param>
    /// <param name="awayTeamIndex">		(Optional) Zero-based index of the away team. </param>
    ////////////////////////////////////////////////////////////////////////////////////////////////////

    void callUpPlayers(unsigned int tournamentMatchId, Date matchDate, Level* level, vector<unsigned int> matchPlayers, unsigned int homeTeamIndex = 0, unsigned int awayTeamIndex = 0);
    //registar jogo já agendado sem performance de jogadores (para já)

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    /// <summary>	Registers the match. </summary>
    ///
    /// <remarks>	Luís, 20/11/2016. </remarks>
    ///
    /// <param name="tournamentMatchId">	Identifier for the tournament match. </param>
    /// <param name="level">				[in,out] If non-null, the level. </param>
    /// <param name="homeTeamScore">		The home team score. </param>
    /// <param name="awayTeamScore">		The away team score. </param>
    /// <param name="matchPlayers">			The match players. </param>
    ////////////////////////////////////////////////////////////////////////////////////////////////////

    void registerMatch(unsigned int tournamentMatchId, Level* level, unsigned int homeTeamScore, unsigned int awayTeamScore, vector<unsigned int> matchPlayers);
    //registar jogo não agendado sem performance de jogadores (para já)
    //para agendar um de uma fase posterior a fase inicial do torneio chamar funcao com quatro ultimos parametros a 0

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    /// <summary>	Registers the match. </summary>
    ///
    /// <remarks>	Luís, 20/11/2016. </remarks>
    ///
    /// <param name="tournamentMatchId">	Identifier for the tournament match. </param>
    /// <param name="matchDate">			The match date. </param>
    /// <param name="level">				[in,out] If non-null, the level. </param>
    /// <param name="matchPlayers">			The match players. </param>
    /// <param name="homeTeamScore">		(Optional) The home team score. </param>
    /// <param name="awayTeamScore">		(Optional) The away team score. </param>
    /// <param name="homeTeamIndex">		(Optional) Zero-based index of the home team. </param>
    /// <param name="awayTeamIndex">		(Optional) Zero-based index of the away team. </param>
    ////////////////////////////////////////////////////////////////////////////////////////////////////

    void registerMatch(unsigned int tournamentMatchId, Date matchDate, Level* level, vector<unsigned int> matchPlayers, unsigned int homeTeamScore = 0, unsigned int awayTeamScore = 0, unsigned int homeTeamIndex = 0, unsigned int awayTeamIndex = 0);

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    /// <summary>	Updates the tree. </summary>
    ///
    /// <remarks>	Luís, 20/11/2016. </remarks>
    ////////////////////////////////////////////////////////////////////////////////////////////////////

    void updateTree();

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    /// <summary>	Stream insertion operator. </summary>
    ///
    /// <remarks>	Luís, 20/11/2016. </remarks>
    ///
    /// <param name="oStream">				[in,out] The stream. </param>
    /// <param name="tournamentToWrite">	[in,out] The tournament to write. </param>
    ///
    /// <returns>	The shifted result. </returns>
    ////////////////////////////////////////////////////////////////////////////////////////////////////

    friend ostream& operator<<(ostream& oStream, Tournament &tournamentToWrite);

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    /// <summary>	Less-than comparison operator. </summary>
    ///
    /// <remarks>	Luís, 20/11/2016. </remarks>
    ///
    /// <param name="oStream">				[in,out] The first instance to compare. </param>
    /// <param name="tournamentToWrite">	[in,out] The second instance to compare. </param>
    ///
    /// <returns>	True if the first parameter is less than the second. </returns>
    ////////////////////////////////////////////////////////////////////////////////////////////////////

    friend ostream& operator<(ostream& oStream, Tournament &tournamentToWrite);
	
};
