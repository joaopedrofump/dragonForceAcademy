//
//  main.cpp
//  DragonForceAcadamy
//
//  Created by Joao Furriel on 12/10/16.
//  Copyright © 2016 João Furriel Pinheiro. All rights reserved.
//
#include "Menus.h"

int main(int argc, const char * argv[]) {


	//Ask the user if there is already a club, or if it will be created.

	string club;

	if (!initialInfo(club)) {
		cout << Table({ "Nao foi possivel ler todos os ficheiros. Por favor verifique os ficheiros." }) << endl;
		ignoreLine(false);
		return(1);
	}


	system("PAUSE");
	return 0;
}
