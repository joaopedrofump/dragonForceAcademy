//
//  main.cpp
//  DragonForceAcadamy
//
//  Created by Joao Furriel on 12/10/16.
//  Copyright © 2016 João Furriel Pinheiro. All rights reserved.
//
#ifdef __llvm__

#include "Menus.h"

#elif _MSC_VER

#include "Classes\\Menus.h"

#endif

#include "Season.hpp"
#include "Level.h"

class Season;
class Level;

int main(int argc, const char * argv[]) {

	//Ask the user if there is already a club, or if it will be created.

	string clubName;
    
    
    try {
        
        initialInfo(clubName);
		Club currentClubInProgram(clubName);
                
        //currentClubInProgram.scheduleMatch("Benfica", Date("12/01/2017"), (currentClubInProgram.getSeasons().at(0))->getLevels().at(4), home);
        //vector<unsigned int> matchPlayers;
        //currentClubInProgram.registerMatch("Seniors3", (currentClubInProgram.getSeasons().at(0))->getLevels().at(4), 2, 0, matchPlayers);
        
        currentClubInProgram.saveChanges();
        initialOptions(currentClubInProgram);
        
        //currentClubInProgram.updateECG(1, true);
        
    }
    
    catch(InvalidDate e) {
        
        cout << e.getMessage() << endl;
        
    }
    
    catch(InvalidStream invalidStream) {
        
        cout << invalidStream.getMessage() << endl;
        
    }
	catch (...) {
		cout << "Something went wrong.";
	}
	return 0;
}
