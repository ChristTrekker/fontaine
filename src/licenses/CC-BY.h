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
// CC-BY.h
//

#ifndef LICENSE_DATA
#include "LicenseData.h"
#endif

#ifndef CC_BY_LICENSE
#define CC_BY_LICENSE

namespace CC_BY{

//
// Sample sentences
// 
const char *fullNames[]={
	"Creative Commons Attribution",
	"Creative-Commons-Attribution",
	"CC BY",
	"CC-BY",
	END_OF_LICENSE_NAMES
};


//
// LicenseData
//
LicenseData data={
	"CC-BY", // acronym
	"http://creativecommons.org/licenses/by/3.0/", // url
	fullNames // One or more full name descriptions used for matching
};

const LicenseData *pData = &data;

}; // end of namespace

#endif
