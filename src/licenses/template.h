//
// The Fontaine Font Analysis Project 
// 
// Copyright (c) 2009 by Edward H. Trager
// All Rights Reserved
// 
// Released under the GNU GPL version 2.0 or later.
//     


//
// .h
//

#ifndef LICENSE_DATA
#include "LicenseData.h"
#endif

#ifndef 
#define 

namespace {

//
// Sample sentences
// 
const char *searchKeys[]={
	"",
	END_OF_LICENSE_NAMES
};


//
// LicenseData
//
LicenseData data={
	"", // name
	"", // url
	searchKeys // One or more full name descriptions used for matching
};

const LicenseData *pData = &data;

}; // end of namespace

#endif
