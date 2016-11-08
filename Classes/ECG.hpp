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
#include "InfoAthletes.hpp"

class ECG {

private:
    bool resultado;
	Date expirationDate;

public:
    ECG(bool resultado, Date exprirationDate);
    bool getResultado() const;
    Date getExpirationDate() const;
};

#endif /* ECG_hpp */
