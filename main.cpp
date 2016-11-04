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

int main(int argc, const char * argv[]) {

	//Ask the user if there is already a club, or if it will be created.

	string clubName;
    
    try {
        
        initialInfo(clubName);
        Club currentClubInProgram(clubName);
        /*
        currentClubInProgram.addPlayer(DefenderPos, "Joao Pedro", Date(10,12,1991), 12877354, 178);
        currentClubInProgram.addPlayer(GoalkeeperPos, "Leo", Date(23,4,2003), 17486937, 190);
		currentClubInProgram.addPlayer(MidfielderPos, "Inacio Correia", Date(21, 5, 2000), 84625386, 160);
		currentClubInProgram.addPlayer(GoalkeeperPos, "Manuel Gomes", Date(12, 1, 1991), 12523759 ,166);
         */
        currentClubInProgram.saveChanges();
        //initialOptions(currentClubInProgram);
        currentClubInProgram.showAthletes();
        
        
    }
    
    catch(InvalidDateException e) {
        
        cout << e.getMessage() << endl;
        
    }
    
    catch(InvalidStream invalidStream) {
        
        cout << invalidStream.getMessage() << endl;
        
    }

	return 0;
}
