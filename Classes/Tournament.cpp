#include "Tournament.hpp"
#include "Level.h"

unsigned int Tournament::idCounter = 0;

Tournament::Tournament(Date tournamentStartingDate, Date tournamentEndingDate, vector<string> tournamentClubs, Club* programClub, string name, unsigned int id) {
    
	this->tournamentStartingDate = tournamentStartingDate;
	this->tournamentEndingDate = tournamentEndingDate;
    this->name = name;
    this->id = !id ? ++Tournament::idCounter : id;
    this->winner = NULL;
    
    this->clubs.push_back(programClub);
    
    for (size_t i = 0; i < tournamentClubs.size(); i++) {
        
        Club* currentClub = new Club(tournamentClubs.at(i), true);
        this->clubs.push_back(currentClub);
        
    }
    
    this->initialPhase = (Phase)(int)log2(this->clubs.size());
    this->numberOfMatches =  pow(2, (double) this->initialPhase) - 1;
    this->tournamentTree = this->fillTournamentTree(Final);
    
    BTItrLevel<nodeMatch> matchIterator(this->tournamentTree);
    
    int numberOfMatchesTemp = this->numberOfMatches;
    while (!matchIterator.isAtEnd()) {
        
        nodeMatch* node = &matchIterator.retrieve();
        node->first.first = numberOfMatchesTemp--;
        matchIterator.advance();
        
    }
    
    this->updateTree();
    
}

Tournament::Tournament(istream &inStream, Level* tournamentLevel) {
    
    string tournamentStartingDate;
    string tournamentEndingDate;
    vector<string> tournamentClubs;
    string name;
    unsigned int id;
    
    string separator;
    inStream >> id >> separator;
    
    getline(inStream, name, ';');
    trimString(name);
    
    inStream >> tournamentStartingDate >> separator;
    inStream >> tournamentEndingDate >> separator;
    Date startDate(tournamentStartingDate);
    Date endDate(tournamentEndingDate);
    unsigned int phase, numberOfMatches;
    inStream >> phase >> separator >> numberOfMatches >> separator;
    
    getline(inStream, separator, ';');
    
    vector<string> clubs;
    
    for (size_t i = 0; i < numberOfMatches; i++) {
        string eachTeam;
        getline(inStream, eachTeam, ',');
        trimString(eachTeam);
        clubs.push_back(eachTeam);
        
    }
    //constroi novo torneio com arvore inicializada
    *this = Tournament(startDate, endDate, clubs, tournamentLevel->getParentClub(), name, id);
    
    ifstream tournamentTree(tournamentLevel->getPathtoLevelTournamentsFolder() + "/" + name + ".txt");
    
    for (int i = 0; i < this->numberOfMatches; i++) {
        
        unsigned int matchIdInTournament;
        unsigned int scheduled;
        unsigned int phaseInt;
        string separator;
        tournamentTree >> matchIdInTournament >> separator >> scheduled >> separator;
        tournamentTree >> phaseInt >> separator;
        Match eachMatch(tournamentTree);
        unsigned int numberOfPLayers;
        tournamentTree >> separator >> numberOfPLayers;
        
        vector<unsigned int> playersIds;
        
        for (size_t j = 0; j < numberOfPLayers ; j++) {
            
            unsigned int currentId;
            string separator;
            tournamentTree >> currentId >> separator;
            Info* waste = new Info(tournamentTree);
            delete waste;
            playersIds.push_back(currentId);
         
        }
        
        
        
        if (scheduled) {
            
            
            //find match date
            Date matchDate = eachMatch.getMatchDay();
            
            //find index of teams
            
            string homeTeam = eachMatch.getHomeTeam()->getName();
            string awayTeam = eachMatch.getAwayTeam()->getName();
            unsigned int indexHome = 0;
            unsigned int indexAway = 0;
            bool foundHome = false;
            bool foundAway = false;
            
            for (unsigned int k = 0; k < this->clubs.size(); k++) {
                
                if (homeTeam == this->clubs.at(k)->getName()) {
                    indexHome = k;
                    foundHome = true;
                    continue;
                }
                if (awayTeam == this->clubs.at(k)->getName()) {
                    indexAway = k;
                    foundAway = true;
                    continue;
                }
                
                if(foundHome && foundAway) {
                    break;
                }
                
                
            }
            
            
            if (eachMatch.getScore().first != eachMatch.getScore().second) {
                
                registerMatch(matchIdInTournament, matchDate, tournamentLevel, playersIds, eachMatch.getScore().first, eachMatch.getScore().second, indexHome, indexAway);
                
            }
            
            else {
                
                this->scheduleTournamentMatch(matchIdInTournament, matchDate, indexHome, indexAway);
                
            }
            
        }
        
    }
    tournamentTree.close();
    
}


BinaryTree<nodeMatch> Tournament::fillTournamentTree(unsigned int finalPhase) {
    
    Match* emptyMatch = new Match(this->tournamentStartingDate);
    Club* homeClub = new Club("Home Team", true);
    Club* awayTeam = new Club("Away Team", true);
    
    emptyMatch->setHomeTeam(homeClub);
    emptyMatch->setAwayTeam(awayTeam);
    nodeMatch finalMatch = make_pair(make_pair(0,0), make_pair((Phase) finalPhase, emptyMatch));
    
    if (finalPhase == this->initialPhase) {
        
        return BinaryTree<nodeMatch>(finalMatch);
        
    }
    
    BinaryTree<nodeMatch> left = this->fillTournamentTree(finalPhase+1);
    BinaryTree<nodeMatch> right = this->fillTournamentTree(finalPhase+1);
    return BinaryTree<nodeMatch>(finalMatch, left, right);
    
}

nodeMatch* Tournament::findMatchNode(unsigned int tournamentMatchId) {
    
    BTItrLevel<nodeMatch> matchIterator(this->tournamentTree);
    
    nodeMatch* node = NULL;
    while (!matchIterator.isAtEnd()) {
        
        if (matchIterator.retrieve().first.first == tournamentMatchId) {
            node = &matchIterator.retrieve();
            break;
        }
        matchIterator.advance();
    }
    
    return node;
    
}
vector<Club*> Tournament::getTournamentClubs() const {
    return this->clubs;
}

Date Tournament::getTournamentStartingDate() const {
	return tournamentStartingDate;
}

Date Tournament::getTournamentEndingDate() const {
	return tournamentEndingDate;
}

unsigned int Tournament::getId() const {
    return this->id;
}

const BinaryTree<nodeMatch>& Tournament::getTournamentTree() const {
    
    return this->tournamentTree;
    
}

vector<Match*> Tournament::getMatches() const {
	
	vector<Match*> result;

	BTItrLevel<nodeMatch> matchIterator(this->getTournamentTree());
	while (!matchIterator.isAtEnd()) {

		result.push_back(matchIterator.retrieve().second.second);
		matchIterator.advance();
	}

	return result;

}

Phase Tournament::getInitialPhase() const {
	return this->initialPhase;
}

vector<vector<string>> Tournament::getTournamentMatches(bool onlyNotRegisted) const {
    
    vector<vector<string>> result;
    
    BTItrLevel<nodeMatch> matchIterator(this->getTournamentTree());
    while (!matchIterator.isAtEnd()) {
        
        nodeMatch* node = &matchIterator.retrieve();
        
		if (onlyNotRegisted && node->second.second->getPlayed()) {
			matchIterator.advance();
			continue;
		}

		vector<string>match = node->second.second->showInScreen(node->first.first);
        match.push_back(phaseStringMap.at(node->second.first));
        
		result.push_back(match);
        
		matchIterator.advance();
        
    }
    return result;
}

void Tournament::scheduleTournamentMatch(unsigned int tournamentMatchId, Date matchDate, unsigned int homeTeamIndex, unsigned int awayTeamIndex, bool played) {
    
    nodeMatch* node =this->findMatchNode(tournamentMatchId);
    
    if (!node) {
        throw string("Wrong Match Id");
    }
    string matchId = this->name + "-" + phaseStringMap.at(node->second.first) + normalizeId(3, node->first.first);
    if (node->second.first == this->initialPhase) {
        
		if (!this->clubsAuxUsed.empty()) {
			vector<unsigned int>::const_iterator iteClubHome = find(this->clubsAuxUsed.begin(), this->clubsAuxUsed.end(), homeTeamIndex);
			vector<unsigned int>::const_iterator iteClubAway = find(this->clubsAuxUsed.begin(), this->clubsAuxUsed.end(), awayTeamIndex);
			if (iteClubHome != this->clubsAuxUsed.end() || iteClubAway != this->clubsAuxUsed.end()) {
				throw string("This club was already used before");
			}
		}
        
        
        delete node->second.second;
        Match* newMatch = new Match(matchDate, this->clubs.at(homeTeamIndex), this->clubs.at(awayTeamIndex), matchId, played);
        node->second.second = newMatch;
        node->first.second = 1;
        this->clubsAuxUsed.push_back(homeTeamIndex);
        this->clubsAuxUsed.push_back(awayTeamIndex);

    }
    
    else {
        
        node->second.second->setId(matchId);
        node->first.second = 1;
		node->second.second->setMatchDay(matchDate);
        
    }
    
}

void Tournament::callUpPlayers(unsigned int tournamentMatchId, vector<unsigned int> matchPlayers) {
    
    nodeMatch* node =this->findMatchNode(tournamentMatchId);
    if (!node) {
        throw string("Wrong Match Id");
    }
    
    if (!node->first.second) {
        throw string("This match is not scheduled");
    }
    
    node->second.second->setPlayers(matchPlayers);
    
}

void Tournament::callUpPlayers(unsigned int tournamentMatchId, Date matchDate, Level* level, vector<unsigned int> matchPlayers, unsigned int homeTeamIndex, unsigned int awayTeamIndex) {
    
    if (homeTeamIndex != 0 && awayTeamIndex != 0) {
        throw string("You can't call up players for other teams.");
    }
    
    nodeMatch* node =this->findMatchNode(tournamentMatchId);
    
    if (!node) {
        throw string("Wrong Match Id");
    }
    
    this->scheduleTournamentMatch(tournamentMatchId, matchDate, homeTeamIndex, awayTeamIndex);
    node->second.second->setPlayers(matchPlayers);

}

void Tournament::registerMatch(unsigned int tournamentMatchId, Level* level, unsigned int homeTeamScore, unsigned int awayTeamScore, vector<unsigned int> matchPlayers) {
    
    nodeMatch* node =this->findMatchNode(tournamentMatchId);
    
    if (!node) {
        throw string("Wrong Match Id.");
    }
    
    if (!node->first.second) {
        throw string("This match is not scheduled.");
    }
    
    if ((homeTeamScore != 0) && (awayTeamScore != 0)) {
        matchPlayers.clear();
    }
    
    vector<unsigned int> filteredVector = level->filterPlayers(matchPlayers);
        
    node->second.second->setPlayers(filteredVector);
    map<unsigned int, Info *> infoPlayersEmpty;
    node->second.second->registerMatch(homeTeamScore, awayTeamScore, infoPlayersEmpty);

    if (node->second.first == Final && (homeTeamScore != awayTeamScore)) {
        
        this->winner = homeTeamScore > awayTeamScore ? node->second.second->getHomeTeam() : node->second.second->getAwayTeam();
    }
    this->updateTree();
    
}

void Tournament::registerMatch(unsigned int tournamentMatchId, Date matchDate, Level* level, vector<unsigned int> matchPlayers, unsigned int homeTeamScore, unsigned int awayTeamScore, unsigned int homeTeamIndex, unsigned int awayTeamIndex) {
    
    this->scheduleTournamentMatch(tournamentMatchId, matchDate, homeTeamIndex, awayTeamIndex, true);
    this->registerMatch(tournamentMatchId, level, homeTeamScore, awayTeamScore, matchPlayers);
    
    
}

void Tournament::updateTree() {
    
    BTItrLevel<nodeMatch> matchIterator(this->getTournamentTree());
    while (!matchIterator.isAtEnd()) {
        
        string matchId = this->name + "-" + phaseStringMap.at(matchIterator.retrieve().second.first) + normalizeId(3, matchIterator.retrieve().first.first);
        matchIterator.retrieve().second.second->setId(matchId);
        
        if (matchIterator.retrieve().second.first != this->initialPhase) {
            
            Club* homeTeamTmp = new Club("Winner " + to_string(matchIterator.getNode()->getRightNode()->getElement().first.first), true);
            Club* awayTeamTmp = new Club("Winner " + to_string(matchIterator.getNode()->getLeftNode()->getElement().first.first), true);
            
            matchIterator.retrieve().second.second->setHomeTeam(homeTeamTmp);
            matchIterator.retrieve().second.second->setAwayTeam(awayTeamTmp);
            
            //check left node match winner
            unsigned int homeTeamScoreLeftNode = matchIterator.getNode()->getLeftNode()->getElement().second.second->getScore().first;
            unsigned int awayTeamScoreLeftNode = matchIterator.getNode()->getLeftNode()->getElement().second.second->getScore().second;
            
            if (homeTeamScoreLeftNode > awayTeamScoreLeftNode) {
                
                matchIterator.retrieve().second.second->setHomeTeam(matchIterator.getNode()->getLeftNode()->getElement().second.second->getHomeTeam());
                
            }
            else if (homeTeamScoreLeftNode < awayTeamScoreLeftNode) {
                
                matchIterator.retrieve().second.second->setHomeTeam(matchIterator.getNode()->getLeftNode()->getElement().second.second->getAwayTeam());
                
            }
            
            //check left node match winner
            unsigned int homeTeamScoreRightNode = matchIterator.getNode()->getRightNode()->getElement().second.second->getScore().first;
            unsigned int awayTeamScoreRightNode = matchIterator.getNode()->getRightNode()->getElement().second.second->getScore().second;
            
            if (homeTeamScoreRightNode > awayTeamScoreRightNode) {
                
                matchIterator.retrieve().second.second->setAwayTeam(matchIterator.getNode()->getRightNode()->getElement().second.second->getHomeTeam());
                
            }
            else if (homeTeamScoreLeftNode < awayTeamScoreLeftNode) {
                
                matchIterator.retrieve().second.second->setAwayTeam(matchIterator.getNode()->getRightNode()->getElement().second.second->getAwayTeam());
                
            }
        
        }
        
        matchIterator.advance();
        
    }
    
}

ostream& operator<<(ostream& oStream, Tournament &tournamentToWrite) {
    
    oStream << tournamentToWrite.id << " ; " << tournamentToWrite.name << " ; " << tournamentToWrite.tournamentStartingDate << " ; " << tournamentToWrite.tournamentEndingDate << " ; " << tournamentToWrite.initialPhase << " ; " << tournamentToWrite.numberOfMatches << " ; ";
    
    string winner = tournamentToWrite.winner ? tournamentToWrite.winner->getName() : "NONE";
    oStream << winner << " ; ";
    
    for (size_t i = 1; i < tournamentToWrite.clubs.size(); i++) {
        
        oStream << tournamentToWrite.clubs.at(i)->getName();
        if (i != tournamentToWrite.clubs.size() - 1) {
            oStream << " , ";
        }
        
    }

    return oStream;
}

ostream& operator<(ostream& oStream, Tournament &tournamentToWrite) {
    
    BTItrLevel<nodeMatch> matchIterator(tournamentToWrite.getTournamentTree());
    while (!matchIterator.isAtEnd()) {
        
        nodeMatch* node = &matchIterator.retrieve();
    
        oStream << node->first.first << " ; " << node->first.second << " ; " << node->second.first << " ; " << *node->second.second << " ; " << (node->second.second)->getPlayers().size() << endl;
        
        map<unsigned int, Info*> matchPlayersMap = node->second.second->getInfoPlayers();
        
        for (map<unsigned int, Info*>::const_iterator playersIterator = matchPlayersMap.begin(); playersIterator!= matchPlayersMap.end(); playersIterator++) {
            
            oStream << playersIterator->first << " ; " << *playersIterator->second << endl;
            
        }
        
        matchIterator.advance();
        
    }
    
    return oStream;
    
}

string Tournament::getName() const {
    return this->name;
}

vector<unsigned int> Tournament::getClubsAuxUsed() const {
	return this->clubsAuxUsed;
}

void Tournament::showMatches() const {

	vector<Table> result;
	unsigned int currentPhase = -1;
	Table tmpTable({ "" });

	BTItrLevel<nodeMatch> matchIterator(this->getTournamentTree());
	while (!matchIterator.isAtEnd()) {

		if (currentPhase == (unsigned int)matchIterator.retrieve().second.first) {

			tmpTable.addDataInSameLine(vector<string>(7, ""));
			tmpTable.addDataInSameLine(matchIterator.retrieve().second.second->showInScreen(matchIterator.retrieve().first.first));
		}
		else {
			if (tmpTable.getTableVector() != vector<vector<string>>{{ "" }})
				result.push_back(tmpTable);
			result.push_back(Table({ phaseStringMap.at(matchIterator.retrieve().second.first) }));
			
			Table newTable(matchIterator.retrieve().second.second->showInScreen(matchIterator.retrieve().first.first));
			tmpTable = newTable;

			currentPhase = (unsigned int)matchIterator.retrieve().second.first;

		}

		matchIterator.advance();

		if(matchIterator.isAtEnd())
			result.push_back(tmpTable);
	}

	for (size_t i = 0; i < result.size(); i++) {

		cout << result.at(i);
	}


}