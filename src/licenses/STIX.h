//
// The Fontaine Font Analysis Project 
// 
// Copyright (c) 2009 by Edward H. Trager
// All Rights Reserved
// 
// Released under the GNU GPL version 2.0 or later.
//     


//
// STIX.h
//

#ifndef LICENSE_DATA
#include "LicenseData.h"
#endif

#ifndef STIX_LICENSE
#define STIX_LICENSE

namespace STIXLicense{

//
// Sample sentences
// 
const char *searchKeys[]={
	"STI Pub Companies",
	END_OF_LICENSE_NAMES
};


//
// LicenseData
//
LicenseData data={
	"STIX Font License (deprecated)", // name
	"http://www.aip.org/stixfonts/news.html", // url
	searchKeys // One or more full name descriptions used for matching
};

const LicenseData *pData = &data;

}; // end of namespace

#endif
