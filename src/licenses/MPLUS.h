//
// The Fontaine Font Analysis Project 
// 
// Copyright (c) 2009 by Edward H. Trager
// All Rights Reserved
// 
// Released under the GNU GPL version 2.0 or later.
//     


//
// MPLUS.h
//

#ifndef LICENSE_DATA
#include "LicenseData.h"
#endif

#ifndef MPLUS_LICENSE
#define MPLUS_LICENSE

namespace MPLUSLicense{

//
// Sample sentences
// 
const char *searchKeys[]={
	"M+ FONTS PROJECT",
	END_OF_LICENSE_NAMES
};


//
// LicenseData
//
LicenseData data={
	"M+ Fonts Project License", // name
	"http://mplus-fonts.sourceforge.jp/webfonts/index-en.html#license", // url
	searchKeys // One or more full name descriptions used for matching
};

const LicenseData *pData = &data;

}; // end of namespace

#endif
