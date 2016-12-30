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
    Match(istream& iss);
    Match(istream& iss, Club* programClub, MatchType homeOrAway);
    Match(Date matchDay);
	~Match();

	// GETTERS

	Date getMatchDay() const;
	Club* getHomeTeam() const;
	Club* getAwayTeam() const;

	pair<unsigned int, unsigned int> getScore() const;

	vector<Worker*> getPlayers() const;
	vector<unsigned int> getPlayersIds() const;
    map<unsigned int, Info*> getInfoPlayers() const;
    void addInfoPlayer(pair<unsigned int, Info*> newPlayer);
    string getId() const;
	bool getPlayed() const;

	// SETTERS

	void setMatchDay(Date newDay);
	void setHomeTeam(Club* newHomeTeam);
	void setAwayTeam(Club* newAwayTeam);
    void setHomeTeamScore(unsigned int newHomeTeamScore);
    void setAwayTeamScore(unsigned int newAwayTeamScore);
    void setId(string newId);
    void setPlayed(bool played);
    
    void setPlayers(vector<unsigned int> playersIds);
    void registerMatch(unsigned int homeTeamScore, unsigned int awayTeamScore, map<unsigned int, Info*> infoPlayers);
    
    //IO
    friend ostream& operator<<(ostream& out, Match &match);
	vector<string> showInScreen(unsigned int tmpID) const;

	//COMPARES
	friend bool operator<(const Match& match1, const Match& match2);
    bool operator==(const Match &compareMatch) const;

};



