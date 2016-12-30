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
    bool resultado; //ECG's result
	Date expirationDate; //ECG's expiration date

public:
	//! ECG's constructor
	/*!
	*	Creates a new ECG using result and expiration date
	*/
	ECG(bool resultado, Date expirationDate);
    
	/*!
	*	This is a method that gets the ECG's result
	*/
	bool getResultado() const;
    
	/*!
	*	This is a method that gets the ECG's expiration date
	*/
	Date getExpirationDate() const;
	
	/*!
		This is a method that shows all the ECG's information on the screen
	*/
	string showInScreen() const;
    
    /*!
     This is a method that returns if an ECG is a valid one
     */
    bool isValid() const;
};

#endif /* ECG_hpp */
