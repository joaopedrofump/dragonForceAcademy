//
//  Athlete.hpp
//  DragonForceAcadamy
//
//  Created by Joao Furriel on 12/10/16.
//  Copyright © 2016 João Furriel Pinheiro. All rights reserved.
//

#ifndef Athlete_hpp
#define Athlete_hpp

#include <stdio.h>
#include <iostream>
#include "Worker.hpp"

class ECG {
private:
    bool resultado;
public:
    ECG(bool resultado) {this->resultado=resultado;};
    ECG& setResultado(bool resultado){this->resultado = resultado; return *this;};
    bool getResultado() const {return this->resultado;};
};

class Athlete : public Worker {
    
protected:
    unsigned char height;
    ECG* ecg; //apontador para ECG quando houver classe

public:
    Athlete(string name, Date birthdate, unsigned char height);
    ~Athlete();
    virtual Position getPosition() const = 0;
    void addECG(bool resultado);
};

#endif /* Athlete_hpp */
