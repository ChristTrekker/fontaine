//
// The Fontaine Font Analysis Project 
// 
// Copyright (c) 2009 by Edward H. Trager
// All Rights Reserved
// 
// Released under the GNU GPL version 2.0 or later.
//     


//
// OFL.h
//

#ifndef LICENSE_DATA
#include "LicenseData.h"
#endif

#ifndef OPEN_FONT_LICENSE
#define OPEN_FONT_LICENSE

namespace OpenFontLicense{

//
// Sample sentences
// 
const char *fullNames[]={
	"Open Font License",
	END_OF_LICENSE_NAMES
};


//
// LicenseData
//
LicenseData data={
	"OFL", // acronym
	"http://scripts.sil.org/OFL", // url
	fullNames // One or more full name descriptions used for matching
};

const LicenseData *pData = &data;

}; // end of namespace

#endif
