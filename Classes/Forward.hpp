#pragma once


#include "Athlete.hpp"

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	A forward. </summary>
///
/// <remarks>	Luís, 20/11/2016. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

class Forward : public Athlete
{
private:
    /// <summary>	forward's general information. </summary>
    Info* generalInfo;

public:

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Constructor. The id is set automatically </summary>
	///
	/// <remarks>	Luís, 20/11/2016. </remarks>
	///
	/// <param name="name">			The name. </param>
	/// <param name="birthdate">	The birthdate. </param>
	/// <param name="civilID">  	Civil identifier. </param>
	/// <param name="height">   	The height. </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	Forward(string name, Date birthdate, unsigned int civilID, unsigned char height, unsigned id = 0);
	
	/*!
	*	This a constructor that creates a new forward using a subposition passed by reference
	*/
	Forward(string &newFW);
    
	//! Forward's destructor
	~Forward();
	
	/*!
	*	This is a method that gets the forward's id
	*/
	unsigned int getID() const;
    
	/*!
	*	This is a method that gets the forward's performance information
	*/
	Info* getInfo() const;
    
	/*!
	*	This is a method that adds information to the forward
	*/
	void addInfo(Info* moreInfo);


};
