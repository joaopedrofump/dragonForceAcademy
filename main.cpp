//
//  main.cpp
//  DragonForceAcadamy
//
//  Created by Joao Furriel on 12/10/16.
//  Copyright © 2016 João Furriel Pinheiro. All rights reserved.
//
#ifdef __llvm__

#include "Menus.h"
#include "Season.hpp"
#include "Level.h"

#elif _MSC_VER

#include "Classes\\Menus.h"
#include "Classes\\Season.hpp"
#include "Classes\\Level.h"

#endif


class Season;
class Level;

int main(int argc, const char * argv[]) {

	//Ask the user if there is already a club, or if it will be created.

	string clubName;
    
    try {
        
        initialInfo(clubName);
        
        if (!clubName.size()) {
            return 0;
        }

        
		Club currentClubInProgram(clubName);
        //initialOptions(currentClubInProgram);

        //currentClubInProgram.saveChanges();
        //currentClubInProgram.updateECG(1, true);
        
        vector<string> clubes = {"Benfica", "Sporting", "Braga", "Academica", "Guimaraes", "Belenenses", "Boavista","PSG", "Manchester United", "Real Madrid", "Barcelona", "Atletico", "Deportivo", "Arsenal", "Chelsea"};
        vector<string> clubes2 = {"Benfica", "Sporting", "Braga"};
        
        currentClubInProgram.getSeasons().at(0)->getLevels().at(0)->addTournament(Date(), Date(1,2,2017), clubes, "Torneio Teste");
        
        
        currentClubInProgram.getSeasons().at(0)->getLevels().at(0)->getTournaments().at(0)->scheduleTournamentMatch(2, Date(1,2,2017), 1, 3);
        currentClubInProgram.getSeasons().at(0)->getLevels().at(0)->getTournaments().at(0)->scheduleTournamentMatch(3, Date(1,2,2017), 1, 3);
        
         /*
        currentClubInProgram.getSeasons().at(0)->getLevels().at(0)->getTournaments().at(0)->callUpPlayers(2, {4});
       
        currentClubInProgram.getSeasons().at(0)->getLevels().at(0)->getTournaments().at(0)->callUpPlayers(1, Date(1,2,2017), currentClubInProgram.getSeasons().at(0)->getLevels().at(0), {4}, 0, 5);
        
        currentClubInProgram.getSeasons().at(0)->getLevels().at(0)->getTournaments().at(0)->registerMatch(1, currentClubInProgram.getSeasons().at(0)->getLevels().at(0), 2, 0, {});
        
        currentClubInProgram.getSeasons().at(0)->getLevels().at(0)->getTournaments().at(0)->registerMatch(2, currentClubInProgram.getSeasons().at(0)->getLevels().at(0), 2, 0, {});
        */
        
        vector<vector<string>> teste = currentClubInProgram.getSeasons().at(0)->getLevels().at(0)->getTournamentMatches(1);
        
        for (size_t i = 0; i < teste.size(); i++) {
            
            for (size_t j = 0; j < teste.at(i).size(); j++) {
                
                cout << teste.at(i).at(j) << " ";
                
            }
            cout << endl;
            
        }
        
        
    }
    
    catch(InvalidDate e) {
        
        cout << e.getMessage() << endl;
        
    }
    
    catch(InvalidStream invalidStream) {
        
        cout << invalidStream.getMessage() << endl;
        
    }
    
    catch(string s) {
        cout << s << endl;
    }
    
	catch (...) {
		cout << "Something went wrong.";
	}
	return 0;

}
