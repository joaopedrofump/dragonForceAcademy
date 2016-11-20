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
        
        initialOptions(currentClubInProgram);

        currentClubInProgram.saveChanges();

        
        
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
