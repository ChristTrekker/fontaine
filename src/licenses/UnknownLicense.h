//
// The Fontaine Font Analysis Project 
// 
// Copyright (c) 2009 by Edward H. Trager
// All Rights Reserved
// 
// Released under the GNU GPL version 2.0 or later.
//     


//
// UnknownLicense.h
//

#ifndef LICENSE_DATA
#include "LicenseData.h"
#endif

#ifndef UNKNOWN_LICENSE
#define UNKNOWN_LICENSE

namespace UnknownLicense{

//
// Sample sentences
// 
const char *fullNames[]={
	"",
	END_OF_LICENSE_NAMES
};


//
// LicenseData
//
LicenseData data={
	"Unknown or Proprietary License", // name
	"", // url
	fullNames // One or more full name descriptions used for matching
};

const LicenseData *pData = &data;

}; // end of namespace

#endif
