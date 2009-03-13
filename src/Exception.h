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
// A version of this file was originally part of the MADELINE 2 program 
// written by Edward H. Trager and Ritu Khanna
// Copyright (c) 2005 by the Regents of the University of Michigan.
// and released under the GNU General Public License v. 2.0 or later.
// 
/////////////////////////////////////////////////////////
//
// 2006.12.18.ET Restructured as a class derived from Message
//

//
// Exception.h
//

#ifndef EXCEPTION_INCLUDED
#define EXCEPTION_INCLUDED

#include "Message.h"

class Exception : public Message{
	
private:
	
	static const char *_exceptionSalutation;
	
public:
	
	Exception(const char *const methodName, const char *format,...);
	
};

#endif

