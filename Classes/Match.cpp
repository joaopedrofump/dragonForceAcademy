#include "Match.hpp"

Match::Match(string id):id(id){}

Match::Match(Date matchDay, Club* homeTeam, Club* awayTeam, string id, bool played)
	: matchDay(matchDay), homeTeam(homeTeam), awayTeam(awayTeam), id(id){
    
        if (!played && matchDay < Date()) {
            
            throw string("Erro ao criar jogo, se o jogo não foi realizado, a data tem de ser futura.");
            
        }
        
        else if (played && Date() < matchDay) {
            
            throw string("Erro ao criar jogo, se o jogo já foi realizado, a data tem de ser passada.");
            
        }
        
        if(!played) {
            this->homeTeamScore = 0;
            this->awayTeamScore = 0;
        }
    
    }

Match::~Match() {

    if(this->getPlayers().size() != 0) {
        
        for(map<unsigned int, Info*>::iterator iteratorMapInfo = this->mapInfoPlayers.begin(); iteratorMapInfo != this->mapInfoPlayers.end(); iteratorMapInfo++) {
            
            delete iteratorMapInfo->second;
            
        }

    }
    /*
    if (!homeTeam->isProgramClub()) {
        delete homeTeam;
    }
    if (!awayTeam->isProgramClub()) {
        delete awayTeam;
    }
     */
};

Match::Match(Date matchDay) {
    this->id = "Temporary ID";
    this->matchDay = matchDay;
    this->homeTeamScore = 0;
    this->awayTeamScore = 0;
    this->played = false;
}

Match::Match(istream& iss) {
    
    string separator;
    string homeTeam;
    string awayTeam;
    string date;
    getline(iss, this->id, ';');
    iss >> date;
    iss >> separator;

    getline(iss, homeTeam, ';');
    getline(iss, awayTeam, ';');

    iss >> this->homeTeamScore;
    iss >> separator;
    iss >> this->awayTeamScore;
    iss >> separator;
    iss >> this->played;
    
    this->matchDay = Date(date);
    
    trimString(homeTeam);
    trimString(awayTeam);
    this->homeTeam = new Club(homeTeam,true);
    this->awayTeam = new Club(awayTeam,true);
    
    
}

Match::Match(istream& iss, Club* programClub, MatchType homeOrAway) {
    
    string separator;
    string tmpHomeTeam;
    string tmpAwayTeam;
    string date;
    iss >> this->id;
    iss >> separator;
    iss >> date;
    iss >> separator;

    getline(iss, tmpHomeTeam, ';');
    getline(iss, tmpAwayTeam, ';');

    iss >> this->homeTeamScore;
    iss >> separator;
    iss >> this->awayTeamScore;
    iss >> separator;
    iss >> played;
    
    trimString(tmpHomeTeam);
    trimString(tmpAwayTeam);
    
    this->matchDay = Date(date);
    this->homeTeam = (homeOrAway == home) ? programClub : new Club(tmpHomeTeam,true);
    this->awayTeam = (homeOrAway == home) ? new Club(tmpAwayTeam,true) : programClub;
    
    
}

void Match::setHomeTeamScore(unsigned int newHomeTeamScore) {
    this->homeTeamScore = newHomeTeamScore;
}
void Match::setAwayTeamScore(unsigned int newAwayTeamScore) {
    this->awayTeamScore = newAwayTeamScore;
}

// GETTERS

Date Match::getMatchDay() const {
	return matchDay;
}

Club* Match::getHomeTeam() const {
	return homeTeam;
}

Club* Match::getAwayTeam() const {
	return awayTeam;
}

pair<unsigned int, unsigned int> Match::getScore() const {
	return { this->homeTeamScore, this->awayTeamScore };
}

map<unsigned int, Info*> Match::getInfoPlayers() const {
	return this->mapInfoPlayers;
}

void Match::addInfoPlayer(pair<unsigned int, Info*> newPlayer) {
    
    this->mapInfoPlayers.insert(newPlayer);
    
}

vector<Worker*> Match::getPlayers() const {
    
    vector<Worker*> result;
    Club* thisClub;
    if(homeTeam->getSeasons().size() != 0) {
        thisClub = homeTeam;
    }
    else if(awayTeam->getSeasons().size() != 0) {
        thisClub = awayTeam;
    }
    else {
        return result;
    }
    for(map<unsigned int, Info*>::const_iterator iteratorMapInfo = this->mapInfoPlayers.begin(); iteratorMapInfo != this->mapInfoPlayers.end(); iteratorMapInfo++) {
        Worker* currentAthlete = thisClub->getAthletes().at(iteratorMapInfo->first);
        result.push_back(currentAthlete);
    }
    return result;
    
}

vector<unsigned int> Match::getPlayersIds() const {

	vector<unsigned int> result;
	for (map<unsigned int, Info*>::const_iterator iteratorMapInfo = this->mapInfoPlayers.begin(); iteratorMapInfo != this->mapInfoPlayers.end(); iteratorMapInfo++) {
		result.push_back(iteratorMapInfo->first);
	}

	return result;
}

string Match::getId() const {
    return this->id;
}

bool Match::getPlayed() const {
	return this->played;
}
// SETTERS

void Match::setMatchDay(Date newDay) {
	matchDay = newDay;
}

void Match::setHomeTeam(Club* newHomeTeam) {
	homeTeam = newHomeTeam;
}

void Match::setAwayTeam(Club* newAwayTeam) {
	awayTeam = newAwayTeam;
}

void Match::setPlayers(vector<unsigned int> playersIds) {
	
    Club* thisClub;
    if(this->homeTeam->isProgramClub()) {
        thisClub = homeTeam;
    }
    else if(this->awayTeam->isProgramClub()) {
        thisClub = awayTeam;
    }
    else {
        return;
    }
    
    for (vector<unsigned int>::const_iterator idsIterator = playersIds.begin(); idsIterator < playersIds.end(); idsIterator++) {
        
        Worker* currentPlayer = thisClub->getAthletes().at(*idsIterator);
        Info* currentInfo;
        
        switch (currentPlayer->getPosition()) {
            case GoalkeeperPos:
                currentInfo = new InfoGK();
                break;
            case DefenderPos:
                currentInfo = new InfoDF();
                break;
            case MidfielderPos:
                currentInfo = new InfoMF();
                break;
            case ForwardPos:
                currentInfo = new InfoFW();
                break;
        }
    
        this->mapInfoPlayers.insert(make_pair(*idsIterator, currentInfo));
        
    }
    
}

void Match::registerMatch(unsigned int homeTeamScore, unsigned int awayTeamScore, map<unsigned int, Info*> infoPlayers) {
    
    this->homeTeamScore = homeTeamScore;
    this->awayTeamScore = awayTeamScore;
    
    if(this->mapInfoPlayers.size() == 0) {
        
        vector<unsigned int> ids;
        for(map<unsigned int, Info*>::iterator idsIterator = infoPlayers.begin(); idsIterator != infoPlayers.end(); idsIterator++) {
            
            ids.push_back(idsIterator->first);
            
        }
        this->setPlayers(ids);
        
    }
    
    for(map<unsigned int, Info*>::iterator infoIterator = infoPlayers.begin(); infoIterator != infoPlayers.end(); infoIterator++) {
        
        *(this->mapInfoPlayers.at(infoIterator->first)) += infoPlayers.at(infoIterator->first);
        
    }
    
    
    this->homeTeamScore = homeTeamScore;
    this->awayTeamScore = awayTeamScore;
    this->played = true;
    
    
}

bool operator<(const Match& match1, const Match& match2) {
	return match2.getMatchDay() < match1.getMatchDay();
}

ostream& operator<<(ostream& out, Match &match) {

    
    out << match.id << " ; " << match.matchDay << " ; " << match.homeTeam->getName() << " ; " << match.awayTeam->getName() << " ; " << match.homeTeamScore << " ; " << match.awayTeamScore << " ; " << match.played;
    
    return out;
    
}


bool Match::operator==(const Match &compareMatch) const {
    return this->id == compareMatch.getId();
}

vector<string> Match::showInScreen(unsigned int tmpID) const {

	vector<string> result;

	result.push_back(to_string(tmpID));

	result.push_back(this->getMatchDay().str());

	result.push_back(this->getHomeTeam()->getName());

	result.push_back((this->getPlayed() ? to_string(this->getScore().first) : "X") + " - " + (this->getPlayed() ? to_string(this->getScore().second) : "X"));
	
	result.push_back(this->getAwayTeam()->getName());

	result.push_back(this->getInfoPlayers().size() ? "YES" : "NO");

	return result;

}

void Match::setId(string newId) {
    this->id = newId;
}

void Match::setPlayed(bool played) {
    this->played = played;
}
