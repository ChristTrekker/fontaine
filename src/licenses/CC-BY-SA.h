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
// CC-BY-SA.h
//

#ifndef LICENSE_DATA
#include "LicenseData.h"
#endif

#ifndef CC_BY_SA_LICENSE
#define CC_BY_SA_LICENSE

namespace CC_BY_SA{

//
// Sample sentences
// 
const char *fullNames[]={
	"Creative Commons Attribution ShareAlike",
	"Creative-Commons-Attribution-ShareAlike",
	"Creative Commons Attribution Share Alike",
	"Creative-Commons-Attribution-Share-Alike",
	"Creative Commons BY SA",
	"Creative-Commons-BY-SA",
	"CC BY SA",
	"CC-BY-SA",
	END_OF_LICENSE_NAMES
};


//
// LicenseData
//
LicenseData data={
	"CC-BY-SA", // acronym
	"http://creativecommons.org/licenses/by-sa/3.0/", // url
	fullNames // One or more full name descriptions used for matching
};

const LicenseData *pData = &data;

}; // end of namespace

#endif
