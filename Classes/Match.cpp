#include "Match.hpp"

Match::Match(Date matchDay, Club homeTeam, Club awayTeam) 
	: matchDay(matchDay), homeTeam(homeTeam), awayTeam(awayTeam){}

// GETTERS

Date Match::getMatchDay() const {
	return matchDay;
}

Club Match::getHomeTeam() const {
	return homeTeam;
}

Club Match::getAwayTeam() const {
	return awayTeam;
}

vector<Athlete*> Match::getPlayers() const {
	return players;
}

// SETTERS

void Match::setMatchDay(Date newDay) {
	matchDay = newDay;
}

void Match::setHomeTeam(Club newHomeTeam) {
	homeTeam = newHomeTeam;
}

void Match::setPlayers(vector<Athlete*> newPlayersList) {
	players = newPlayersList;
}