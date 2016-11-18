#pragma once

#include "Match.hpp"
#include "Club.hpp"


class Tournament
{
	Date tournamentStartingDate, tournamentEndingDate;
	vector<Match> matches;

public:
	Tournament(Date tournamentStartingDate, Date tournamentEndingDate);
	~Tournament();
	Date getTournamentStartingDate() const;
	Date getTournamentEndingDate() const;
	vector<Match> getMatches() const;


};
