//
//  Goalkeeper.hpp
//  DragonForceAcadamy
//
//  Created by Joao Furriel on 13/10/16.
//  Copyright © 2016 João Furriel Pinheiro. All rights reserved.
//
#pragma once

#ifndef Goalkeeper_hpp
#define Goalkeeper_hpp

#include "Defender.hpp"

class Goalkeeper : public Athlete {
private:
    /// <summary>	goalkeeper's general info. </summary>
    Info* generalInfo;
        
public:
    
	//! Goalkeeper's constructors
	/*!
	*	This is a constructor that creates a new goalkeeper using his name, birthdate, civilID and height. The id is set automatically 
	*/

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Constructor. th id is set automatically </summary>
	///
	/// <remarks>	Luís, 20/11/2016. </remarks>
	///
	/// <param name="name">			The name. </param>
	/// <param name="birthdate">	The birthdate. </param>
	/// <param name="civilID">  	Identifier for the civil. </param>
	/// <param name="height">   	The height. </param>
	/// <param name="int">			(Optional) The int. </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	Goalkeeper(string name, Date birthdate, unsigned int civilID, unsigned char height, unsigned int = 0);
	

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Constructor that creates a new goalkeeper by reading from the athletes file. </summary>
	///
	/// <remarks>	Luís, 20/11/2016. </remarks>
	///
	/// <param name="newGK">	[in,out] The new goalkeeper. </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	Goalkeeper(string &newGK);
    

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Destructor. </summary>
	///
	/// <remarks>	Luís, 20/11/2016. </remarks>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	~Goalkeeper();
    
	/*!
	*	This is a method that gets the goalkeeper's id
	*/

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Gets the goalkeeper's identifier. </summary>
	///
	/// <remarks>	Luís, 20/11/2016. </remarks>
	///
	/// <returns>	The goalkeeper's identifier. </returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	unsigned int getID() const;
    
	/*!
	*	This is a method that gets the goalkeeper's performance information 
	*/

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Gets the goalkeeper's performance information. </summary>
	///
	/// <remarks>	Luís, 20/11/2016. </remarks>
	///
	/// <returns>	Null if it fails, else the goalkeeper's performance information. </returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	Info* getInfo() const;
    
	/*!
	*	This is a method that adds information to the goalkeeper
	*/

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Adds performance information to the goalkeeper. </summary>
	///
	/// <remarks>	Luís, 20/11/2016. </remarks>
	///
	/// <param name="moreInfo">	[in,out] If non-null, goalkeeper's performance information. </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	void addInfo(Info* moreInfo);

};

#endif /* Goalkeeper_hpp */
