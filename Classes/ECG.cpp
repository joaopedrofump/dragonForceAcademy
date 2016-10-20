//
//  ECG.cpp
//  DragonForceAcademy
//
//  Created by Joao Furriel on 20/10/16.
//  Copyright © 2016 João Furriel Pinheiro. All rights reserved.
//

#include "ECG.hpp"

ECG::ECG(bool resultado) {
    this->resultado=resultado;
}

ECG& ECG::setResultado(bool resultado){
    this->resultado = resultado; return *this;
}

bool ECG::getResultado() const {
    return this->resultado;
}

