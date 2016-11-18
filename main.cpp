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
                
        //currentClubInProgram.scheduleMatch("Sporting", Date("12/04/2014"), (currentClubInProgram.getSeasons().at(0))->getLevels().at(4), home);

        //vector<unsigned int> matchPlayers;
        //matchPlayers.push_back(1);
        //currentClubInProgram.registerMatch("Seniors002|20170412", (currentClubInProgram.getSeasons().at(0))->getLevels().at(4), 2, 0, matchPlayers);
        //currentClubInProgram.updateECG(1, true);*/

        
        
        
        initialOptions(currentClubInProgram);
        //currentClubInProgram.getSeasons().at(0)->getLevels().at(1)->scheduleTraining(Date(2,12,2016));
        //currentClubInProgram.getSeasons().at(0)->getLevels().at(1)->registerTraining(2, {});
        //currentClubInProgram.getSeasons().at(0)->getLevels().at(1)->registerTraining(Date(19,9,2016), {2});
        currentClubInProgram.saveChanges();
        //currentClubInProgram.updateECG(1, true);
        
        cout << currentClubInProgram.getSeasons().at(0)->getEndDate() << endl;
        
        vector<vector<string>> testTrainings = currentClubInProgram.getSeasons().at(0)->getLevels().at(1)->getTrainingsList(numberOfPlayers,descending);
        
        for (size_t i = 0; i < testTrainings.size(); i++) {
            
            for (size_t j = 0; j < testTrainings.at(i).size(); j++) {
                
                cout << testTrainings.at(i).at(j) << " ";
                
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

	cout << endl;
	system("pause");
}
