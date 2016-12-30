#pragma once

#include "Match.hpp"
#include "Club.hpp"

enum Phase {
    EightOfFinals = 4,
    QuarterFinals = 3,
    SemiFinals = 2,
    Final = 1
};

const map<Phase,string> phaseStringMap {
    {EightOfFinals, "EightOfFinals"},
    {QuarterFinals, "QuarterFinals"},
    {SemiFinals, "SemiFinals"},
    {Final, "Final"}
};

/**<, matchScheduled>, <Phase, Match*>*/
typedef pair<pair<unsigned int,unsigned int>, pair<Phase, Match*>> nodeMatch;

class Level;

class Tournament {
	Date tournamentStartingDate, tournamentEndingDate;
    vector<Club*> clubs;
    vector<unsigned int> clubsAuxUsed;
    BinaryTree<nodeMatch> tournamentTree;
    Club* winner;
    Phase initialPhase;
    unsigned int numberOfMatches;
    string name;
    static unsigned int idCounter;
    unsigned int id;

public:
	Tournament(Date tournamentStartingDate, Date tournamentEndingDate, vector<string> tournamentClubs, Club* programClub, string name, unsigned int id = 0);
    Tournament(istream &inStream, Level* tournamentLevel);
	~Tournament() {};
    string getName() const;
	Date getTournamentStartingDate() const;
	Date getTournamentEndingDate() const;
    BinaryTree<nodeMatch> fillTournamentTree(unsigned int finalPhase);
    nodeMatch* findMatchNode(unsigned int tournamentMatchId);
    unsigned int getId() const;
    vector<Club*> getTournamentClubs() const;
	vector<unsigned int> getClubsAuxUsed() const;
    const BinaryTree<nodeMatch>& getTournamentTree() const;
    vector<vector<string>> getTournamentMatches(bool onlyNotRegisted = false) const;
	Phase getInitialPhase() const;
    //para agendar um de uma fase posterior a fase inicial do torneio chamar funcao com dois ultimos parametros a 0
    void scheduleTournamentMatch(unsigned int tournamentMatchId, Date matchDate, unsigned int homeTeamIndex = 0, unsigned int awayTeamIndex = 0, bool played = false);
    //convocar jogadores para jogo agendado
    void callUpPlayers(unsigned int tournamentMatchId, vector<unsigned int> matchPlayers);
    //convocar jogadores para jogo não agendado
    //para agendar um de uma fase posterior a fase inicial do torneio chamar funcao com dois ultimos parametros a 0
    void callUpPlayers(unsigned int tournamentMatchId, Date matchDate, Level* level, vector<unsigned int> matchPlayers, unsigned int homeTeamIndex = 0, unsigned int awayTeamIndex = 0);
    //registar jogo já agendado sem performance de jogadores (para já)
    void registerMatch(unsigned int tournamentMatchId, Level* level, unsigned int homeTeamScore, unsigned int awayTeamScore, vector<unsigned int> matchPlayers, bool previouslyRegistered = false);
    //registar jogo não agendado sem performance de jogadores (para já)
    //para agendar um de uma fase posterior a fase inicial do torneio chamar funcao com quatro ultimos parametros a 0
    void registerMatch(unsigned int tournamentMatchId, Date matchDate, Level* level, vector<unsigned int> matchPlayers, unsigned int homeTeamScore = 0, unsigned int awayTeamScore = 0, unsigned int homeTeamIndex = 0, unsigned int awayTeamIndex = 0, bool previouslyRegistered = false);
    void updateTree();
    
	// Write to Tournaments file
    friend ostream& operator<<(ostream& oStream, Tournament &tournamentToWrite);
	// Write to Tournament file in Tournaments folder
    friend ostream& operator<(ostream& oStream, Tournament &tournamentToWrite);

	vector<Match*> getMatches() const;

	void showMatches() const;
};
