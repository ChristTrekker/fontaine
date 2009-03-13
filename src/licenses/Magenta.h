//
// The Fontaine Font Analysis Project 
// 
// Copyright (c) 2009 by Edward H. Trager
// All Rights Reserved
// 
// Released under the GNU GPL version 2.0 or later.
//     


//
// Magenta.h
//

#ifndef LICENSE_DATA
#include "LicenseData.h"
#endif

#ifndef MAGENTA_OPEN
#define MAGENTA_OPEN

namespace MagentaOpenLicense{

//
// Sample sentences
// 
const char *searchKeys[]={
	"MgOpen",
	END_OF_LICENSE_NAMES
};


//
// LicenseData
//
LicenseData data={
	"Magenta Open License", // name
	"http://www.ellak.gr/fonts/mgopen/index.en.html", // url
	searchKeys // One or more full name descriptions used for matching
};

const LicenseData *pData = &data;

}; // end of namespace

#endif
