//
// The Fontaine Font Analysis Project 
// 
// Copyright (c) 2009 by Edward H. Trager
// All Rights Reserved
// 
// Released under the GNU GPL version 2.0 or later.
//     


//
// Freeware.h
//

#ifndef LICENSE_DATA
#include "LicenseData.h"
#endif

#ifndef FREEWARE_LICENSE
#define FREEWARE_LICENSE

namespace Freeware{

//
// Sample sentences
// 
const char *searchKeys[]={
	"freeware",
	"free ware",
	END_OF_LICENSE_NAMES
};


//
// LicenseData
//
LicenseData data={
	"Freeware", // acronym
	"", // url
	searchKeys // One or more full name descriptions used for matching
};

const LicenseData *pData = &data;

}; // end of namespace

#endif
