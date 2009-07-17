//
// The Fontaine Font Analysis Project 
// 
// Copyright (c) 2009 by Edward H. Trager
// All Rights Reserved
// 
// Released under the GNU GPL version 2.0 or later.
//     


//
// ArphicPublic.h
//

#ifndef LICENSE_DATA
#include "../LicenseData.h"
#endif

#ifndef ARPHIC_PUBLIC
#define ARPHIC_PUBLIC

namespace ArphicPublicLicense{

//
// Sample sentences
// 
const char *searchKeys[]={
	"ARPHIC PUBLIC LICENSE",
	"Arphic Public License",
	"文鼎公眾授權書",
	"Arphic",
	END_OF_LICENSE_NAMES
};


//
// LicenseData
//
LicenseData data={
	"Arphic Public License", // name
	"http://ftp.gnu.org/gnu/non-gnu/chinese-fonts-truetype/LICENSE", // url
	searchKeys // descriptions used for matching
};

const LicenseData *pData = &data;

}; // end of namespace

#endif
