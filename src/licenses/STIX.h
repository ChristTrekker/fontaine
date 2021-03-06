//
// The Fontaine Font Analysis Project 
// 
// Copyright (c) 2009 by Edward H. Trager
// Copyright (c) 2010 by Nicolas Spalinger
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
// The metadata is quite similar to the new fonts released under OFL, but the small differences in date and definition allow us
// to distinguish the beta under the project-specific license and the 1.0 version under OFL
const char *searchKeys[]={
	"2007 by the STI Pub Companies",
	"the derivative work will carry a different name",
	END_OF_LICENSE_NAMES
};


//
// LicenseData
//
LicenseData data={
	"STIX Font License (deprecated: the new version of the fonts have been released under the OFL)", // name
	"http://www.aip.org/stixfonts/news.html", // url
	searchKeys // One or more full name descriptions used for matching
};

const LicenseData *pData = &data;

}; // end of namespace

#endif
