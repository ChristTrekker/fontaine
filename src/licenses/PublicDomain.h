//
// The Fontaine Font Analysis Project 
// 
// Copyright (c) 2009 by Edward H. Trager
// All Rights Reserved
// 
// Released under the GNU GPL version 2.0 or later.
//     


//
// PublicDomain.h
//

#ifndef LICENSE_DATA
#include "LicenseData.h"
#endif

#ifndef PUBLIC_DOMAIN
#define PUBLIC_DOMAIN

namespace PublicDomain{

//
// Sample sentences
// 
const char *fullNames[]={
	"public domain",
	END_OF_LICENSE_NAMES
};


//
// LicenseData
//
LicenseData data={
	"Public Domain", // acronym
	"", // url
	fullNames // One or more full name descriptions used for matching
};

const LicenseData *pData = &data;

}; // end of namespace

#endif
