//
// The Fontaine Font Analysis Project 
// 
// Copyright (c) 2009 by Edward H. Trager
// All Rights Reserved
// 
// Released under the GNU GPL version 2.0 or later.
//     

/////////////////////////////////////////////////////////
//
// A version of this file was originally written as part of
// the MADELINE 2 program 
// written by Edward H. Trager and Ritu Khanna
// Copyright (c) 2005 by the Regents of the University of Michigan.
// and released under the GNU GPL v. 2.0 or later.
// 
/////////////////////////////////////////////////////////
//
// 2005.03.14.ET -- Originally written as Warning class
// 2006.12.18.ET -- Reimplemented as Message base class

//
// Message.h
//


#ifndef MESSAGE_INCLUDED
#define MESSAGE_INCLUDED

#include <iostream>
#include <libintl.h>
#include <locale.h>
#include <stdarg.h>
#include "BufferSizes.h"
#include <string>
#include <stdio.h>

// Loader class:
class MessageInitializer;

class Message{
	
	friend class MessageInitializer;
	
private:
	
	static const char *_defaultSalutation;
	
	// initialize:
	static void _initialize( void );
	
protected:
	
	const char *_salutation;
	const char *_methodName;
	char _message[GENERAL_STRING_BUFFER_SIZE];
	bool _truncated;
	
public:
	
	// Constructors:
	Message(){};
	Message(const char *const methodName, const char *format,...);
	
	// print:
	void print(void);
	
	// get:
	std::string get(void) const;
};

//
// MessageInitializer loader class:
//
class MessageInitializer{
	
	static MessageInitializer messageInitializer;
	MessageInitializer(){
		Message::_initialize();
	}
	
};

//
// Independent utility method for localization:
//
std::string L(const char *format,...);

#endif

