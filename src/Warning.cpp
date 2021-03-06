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
// This file was originally part of the MADELINE 2 program 
// written by Edward H. Trager and Ritu Khanna
// Copyright (c) 2005 by the
// Regents of the University of Michigan.
// All Rights Reserved.
// Released under the GNU General Public License v. 2.0 or later.
// 
/////////////////////////////////////////////////////////
//
// 2005.03.14.ET
//

//
// Warning.cpp
//

#include "Warning.h"
#include "Debug.h"
#include <string.h>

bool Warning::_suppressWarnings=false;
const char *Warning::_warningSalutation="Warning";

//
// Warning() constructor:
//
Warning::Warning( const char *const methodName , const char *format , ... ){
	
	//
	// The Warning class uses the Warning salutation:
	//
	_salutation = gettext(_warningSalutation);
	_methodName = methodName;
	int n;
	va_list args;
	if(strlen(format) > 0){
		va_start(args,format);
		n=vsnprintf(_message,GENERAL_STRING_BUFFER_SIZE,gettext(format),args);
		va_end(args);
		_truncated=(n==GENERAL_STRING_BUFFER_SIZE);
	}
	
	print();
	
}

//
// suppressWarnings()
//
void Warning::suppressWarnings(bool suppressWarnings){
	
	_suppressWarnings=suppressWarnings;
	
}

//
// print()
//
void Warning::print(void){
	
	std::cerr << "\x1b[1;31m" ;
	std::cerr << _salutation << ": ";
	std::cerr << "\x1b[0m" ;
	if(Debug::DEBUG){
		std::cerr << "\x1b[0;32m" ;
		std::cerr << _methodName << ": ";
		std::cerr << "\x1b[0m" ;
	}
	std::cerr << _message << std::endl;
	if(_truncated){
		std::cerr << gettext("(Message has been truncated)") << std::endl;
	}
}



