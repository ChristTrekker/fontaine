//
// The Fontaine Font Analysis Project 
// 
// Copyright (c) 2009 by Edward H. Trager
// All Rights Reserved
// 
// Released under the GNU GPL version 2.0 or later.
//     


//
// GUST.h
//

#ifndef LICENSE_DATA
#include "LicenseData.h"
#endif

#ifndef GUST_LICENSE
#define GUST_LICENSE

namespace GUSTLicense{

//
// Sample sentences
// 
const char *searchKeys[]={
	"GUST",
	END_OF_LICENSE_NAMES
};


//
// LicenseData
//
LicenseData data={
	"GUST Font License", // name
	"http://tug.org/fonts/licenses/GUST-FONT-LICENSE.txt", // url
	searchKeys // One or more full name descriptions used for matching
};

const LicenseData *pData = &data;

}; // end of namespace

#endif
