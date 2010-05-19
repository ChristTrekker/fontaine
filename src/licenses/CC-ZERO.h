//
// The Fontaine Font Analysis Project 
// 
// Copyright (c) 2009 by Edward H. Trager
// Copyright (c) 2010 by Dave Crossland
// All Rights Reserved
// 
// Released under the GNU GPL version 2.0 or later.
//     


//
// CC-ZERO.h
//

#ifndef LICENSE_DATA
#include "LicenseData.h"
#endif

#ifndef CC_ZERO_LICENSE
#define CC_ZERO_LICENSE

namespace CC_ZERO{

//
// Sample sentences
// 
const char *fullNames[]={
	"Creative Commons Zero",
	"Creative-Commons-Zero",
	"Creative Commons 0",
	"Creative-Commons-0",
	"CC Zero",
	"CC-Zero",
	"CC 0",
	"CC-0",
	END_OF_LICENSE_NAMES
};


//
// LicenseData
//
LicenseData data={
	"CC-0", // acronym
	"http://creativecommons.org/publicdomain/zero/1.0/", // url
	fullNames // One or more full name descriptions used for matching
};

const LicenseData *pData = &data;

}; // end of namespace

#endif
