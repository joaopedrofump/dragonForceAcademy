#include "Tournament.hpp"

Tournament::Tournament(Date tournamentStartingDate, Date tournamentEndingDate)
{
	this->tournamentStartingDate = tournamentStartingDate;
	this->getTournamentEndingDate = tournamentEndingDate;
}

Date Tournament::getTournamentStartingDate() const
{
	return tournamentStartingDate;
}

Date Tournament::getTournamentEndingDate() const
{
	return tournamentEndingDate;
}

vector<Match> Tournament::getMatches() const
{
	return matches;
}

