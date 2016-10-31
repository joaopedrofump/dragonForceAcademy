//
//  ECG.hpp
//  DragonForceAcademy
//
//  Created by Joao Furriel on 20/10/16.
//  Copyright © 2016 João Furriel Pinheiro. All rights reserved.
//
#pragma once

#ifndef ECG_hpp
#define ECG_hpp
#include "Utils.hpp"

class ECG {

private:
    bool resultado;
	Date expirationDate;

public:
    ECG(bool resultado);
    ECG& setResultado(bool resultado);
    bool getResultado() const;
};

#endif /* ECG_hpp */
