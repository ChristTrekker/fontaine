//
// The Fontaine Font Analysis Project 
// 
// Copyright (c) 2009 by Edward H. Trager
// All Rights Reserved
// 
// Released under the GNU GPL version 2.0 or later.
//     


//
// IPA.h
//

#ifndef LICENSE_DATA
#include "LicenseData.h"
#endif

#ifndef IPA_LICENSE
#define IPA_LICENSE

namespace IPALicense{

//
// Sample sentences
// 
const char *searchKeys[]={
	"IPA License",
	"Information-technology Promotion Agency",
	"(IPA)",
	" IPA ",
	END_OF_LICENSE_NAMES
};


//
// LicenseData
//
LicenseData data={
	"IPA", // acronym
	"http://opensource.org/licenses/ipafont.html", // url
	searchKeys // One or more full name descriptions used for matching
};

const LicenseData *pData = &data;

}; // end of namespace

#endif
