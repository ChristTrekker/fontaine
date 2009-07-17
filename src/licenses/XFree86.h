//
// The Fontaine Font Analysis Project 
// 
// Copyright (c) 2009 by Edward H. Trager
// All Rights Reserved
// 
// Released under the GNU GPL version 2.0 or later.
//     


//
// MIT.h
//

#ifndef LICENSE_DATA
#include "LicenseData.h"
#endif

#ifndef XFREE86_LICENSE
#define XFREE86_LICENSE

namespace XFree86License{

//
// Sample sentences
// 
const char *searchKeys[]={
	"XFree86",
	END_OF_LICENSE_NAMES
};


//
// LicenseData
//
LicenseData data={
	"XFree86 License", // name
	"http://www.xfree86.org/legal/licenses.html", // url
	searchKeys // One or more full name descriptions used for matching
};

const LicenseData *pData = &data;

}; // end of namespace

#endif
