//
// The Fontaine Font Analysis Project 
// 
// Copyright (c) 2009 by Edward H. Trager
// All Rights Reserved
// 
// Released under the GNU GPL version 2.0 or later.
//     


//
// Aladdin.h
//

#ifndef LICENSE_DATA
#include "LicenseData.h"
#endif

#ifndef ALADDIN_LICENSE
#define ALADDIN_LICENSE

namespace AladdinFreePublicLicense{

//
// Sample sentences
// 
const char *searchKeys[]={
	"Aladdin",
	END_OF_LICENSE_NAMES
};


//
// LicenseData
//
LicenseData data={
	"Aladdin Free Public License", // name
	"http://pages.cs.wisc.edu/~ghost/doc/AFPL/6.01/Public.htm", // url
	searchKeys // descriptions used for matching
};

const LicenseData *pData = &data;

}; // end of namespace

#endif
