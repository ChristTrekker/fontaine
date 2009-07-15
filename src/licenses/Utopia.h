//
// The Fontaine Font Analysis Project 
// 
// Copyright (c) 2009 by Edward H. Trager
// All Rights Reserved
// 
// Released under the GNU GPL version 2.0 or later.
//     


//
// Utopia.h
//

#ifndef LICENSE_DATA
#include "LicenseData.h"
#endif

#ifndef UTOPIA_LICENSE
#define UTOPIA_LICENSE

namespace UtopiaLicense{

//
// Sample sentences
// 
const char *searchKeys[]={
	"The Utopia fonts are freely available; see http://tug.org/fonts/utopia",
	END_OF_LICENSE_NAMES
};


//
// LicenseData
//
LicenseData data={
	"License to TeX Users Group for the Utopia Typeface", // name
	"http://tug.org/fonts/utopia/LICENSE-utopia.txt", // url
	searchKeys // One or more full name descriptions used for matching
};

const LicenseData *pData = &data;

}; // end of namespace

#endif
