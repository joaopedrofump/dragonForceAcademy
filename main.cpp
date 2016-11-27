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
        
        
        /*map<unsigned int, Worker*> test = currentClubInProgram.getAthletes();
        vector<Worker*> athletes;
        for (map<unsigned int, Worker*>::const_iterator i = test.begin() ; i != test.end(); i++) {
            
            Worker* curr = i->second;
            athletes.push_back(curr);
            
        }
        sort(athletes.begin(), athletes.end(), SortWorker(ecg, descending));
        
        for (size_t i = 0; i < test.size(); i++) {
            
            cout << *athletes.at(i)<< " ; ";
            if(athletes.at(i)->getECG()) {
                if (athletes.at(i)->getECG()->getResultado()) {
                    cout << "VALID" << " ; " << athletes.at(i)->getECG()->getExpirationDate() << endl;
                }
                else {
                    cout << "NOT VALID" << " ; " << endl;
                }
            }
            else {
                cout << "NO ECG" << endl;
            }
            
            
            
        }
        */

        
    }
    
    catch(InvalidDate e) {
        
        cout << e.getMessage() << endl;
		system("PAUSE");
        
    }
    
    catch(InvalidStream invalidStream) {
        
        cout << invalidStream.getMessage() << endl;
		system("PAUSE");
        
    }
    
    catch(string s) {
        cout << s << endl;
		system("PAUSE");
    }
    
	catch (...) {
		cout << "Something went wrong.";
		system("PAUSE");
	}
	return 0;

}
