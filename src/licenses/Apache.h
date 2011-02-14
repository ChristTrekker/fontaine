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
// Apache.h
//

#ifndef LICENSE_DATA
#include "LicenseData.h"
#endif

#ifndef APACHE
#define APACHE

namespace ApacheLicense{

//
// Sample sentences
// 
const char *searchKeys[]={
	"Apache",
	"Apache License",
	"Apache 2 License",
	END_OF_LICENSE_NAMES
};


//
// LicenseData
//
LicenseData data={
	"Apache 2.0", // name
	"http://www.apache.org/licenses/LICENSE-2.0", // url
	searchKeys // One or more full name descriptions used for matching
};

const LicenseData *pData = &data;

}; // end of namespace

#endif
