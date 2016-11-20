//
//  ECG.cpp
//  DragonForceAcademy
//
//  Created by Joao Furriel on 20/10/16.
//  Copyright © 2016 João Furriel Pinheiro. All rights reserved.
//

#include "ECG.hpp"

ECG::ECG(bool resultado, Date expirationDate) {
    
    try {
      
        if(expirationDate < Date()) {
            throw string("invalid expiration date");
        }
        this->resultado = resultado;
        this->expirationDate = expirationDate;
        
    }
    
    catch(InvalidDate e) {
        cout << e.getMessage() << endl;
    }
    
    
    this->resultado=resultado;
}

bool ECG::getResultado() const {
	if(this)
		return this->resultado;
	return false;
}

Date ECG::getExpirationDate() const {
	if(this)
		return this->expirationDate;
	return Date(1, 1, 1900);
}

string ECG::showInScreen() const {
	string result;
	if (getExpirationDate() < Date()) {
		result = "EXPIRED";
	}
	else if (this->getResultado()) {

		result = getExpirationDate().str();
	}
	else {
		result = "INVALID";
	}
	return result;
}
