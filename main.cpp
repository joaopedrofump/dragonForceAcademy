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

	string club;
    
    try {
        
        initialInfo(club);
        Club currProgramClub(club);
        currProgramClub.addPlayer(DefenderPos, "Joao Pedro", Date(10,02,1991), 178);
        currProgramClub.addPlayer(GoalkeeperPos, "Leo", Date(23,04,1991), 190);
		currProgramClub.addPlayer(MidfielderPos, "Inacio Correia", Date(21, 05, 1991), 160);
		currProgramClub.addPlayer(GoalkeeperPos, "Manuel Gomes", Date(12, 1, 1991), 166);
        initialOptions(currProgramClub);
        
        
    }
    
    catch(string s) {
        
        cout << s << endl;
        
    }
    
	system("PAUSE");
	return 0;
}
