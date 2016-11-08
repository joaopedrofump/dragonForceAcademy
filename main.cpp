//
//  main.cpp
//  DragonForceAcadamy
//
//  Created by Joao Furriel on 12/10/16.
//  Copyright � 2016 Jo�o Furriel Pinheiro. All rights reserved.
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
        
        currentClubInProgram.saveChanges();
        
        
        
        initialOptions(currentClubInProgram);
        
        //currentClubInProgram.updateECG(1, true);
        cout << "teste" << endl;
        
        
    
    }
    
    catch(InvalidDateException e) {
        
        cout << e.getMessage() << endl;
        
    }
    
    catch(InvalidStream invalidStream) {
        
        cout << invalidStream.getMessage() << endl;
        
    }
	catch (...) {
		cout << "Qualquer excepcao";
	}
	return 0;
}
