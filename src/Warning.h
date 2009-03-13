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
// Warning.h
//

#ifndef WARNING_INCLUDED
#define WARNING_INCLUDED

#include "Message.h"

//#include <iostream>
//#include <libintl.h>
//#include <stdarg.h>
//#include "BufferSizes.h"

class Warning : public Message{
	
private:
	
	static bool _suppressWarnings;
	static const char *_warningSalutation;
public:
	
	Warning(const char *const methodName, const char *format,...);
	static void suppressWarnings(bool suppressWarnings);
	void print(void);
	
};

#endif

