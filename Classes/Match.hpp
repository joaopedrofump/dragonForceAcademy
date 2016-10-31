#pragma once

#include "Club.hpp"

class Match{
	Date matchDay;

	Club* homeTeam;
	Club* awayTeam;
	

	vector<Athlete*> players;
	
public:
	Match(Date matchDay, Club* homeTeam, Club* awayTeam);
	~Match();

	// GETS

	Date getMatchDay() const;
	Club* getHomeTeam() const;
	Club* getAwayTeam() const;
	vector<Athlete*> getPlayers() const;

	// SETS

	void setMatchDay(Date newDay);
	void setHomeTeam(Club* newHomeTeam);
	void setAwayTeam(Club* newAwayTeam);
	void setPlayers(vector<Athlete*> newPlayersList);
};



