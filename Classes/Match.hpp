#pragma once

#include "Club.hpp"

class Match{
    string id;
	Date matchDay;
	Club* homeTeam;
	Club* awayTeam;
    unsigned int homeTeamScore;
    unsigned int awayTeamScore;
    map<unsigned int, Info*> mapInfoPlayers;
    bool played;
	
public:
    Match(string id);
	Match(Date matchDay, Club* homeTeam, Club* awayTeam, string id, bool played = false);
    Match(istringstream& iss);
    Match(istringstream& iss, Club* programClub, MatchType homeOrAway);
	~Match();

	// GETTERS

	Date getMatchDay() const;
	Club* getHomeTeam() const;
	Club* getAwayTeam() const;
	vector<Worker*> getPlayers() const;
    map<unsigned int, Info*> getInfoPlayers() const;
    void addInfoPlayer(pair<unsigned int, Info*> newPlayer);
    string getId() const;

	// SETTERS

	void setMatchDay(Date newDay);
	void setHomeTeam(Club* newHomeTeam);
	void setAwayTeam(Club* newAwayTeam);
    void setHomeTeamScore(unsigned int newHomeTeamScore);
    void setAwayTeamScore(unsigned int newAwayTeamScore);
    
    void setPlayers(vector<unsigned int> playersIds);
    void registerMatch(unsigned int homeTeamScore, unsigned int awayTeamScore, map<unsigned int, Info*> infoPlayers);
    
    //IO
    
    friend ostream& operator<<(ostream& out, Match &match);
    bool operator==(const Match &compareMatch) const;
};



