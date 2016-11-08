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
    
    catch(InvalidDateException e) {
        cout << e.getMessage() << endl;
    }
    
    
    this->resultado=resultado;
}

bool ECG::getResultado() const {
    return this->resultado;
}

Date ECG::getExpirationDate() const {
    return this->expirationDate;
}
