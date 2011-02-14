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

#ifndef MIT_LICENSE
#define MIT_LICENSE

namespace MITLicense{

//
// Sample sentences
// 
const char *searchKeys[]={
	"MIT", "X11",
	END_OF_LICENSE_NAMES
};


//
// LicenseData
//
LicenseData data={
	"MIT (X11) License", // name
	"http://www.opensource.org/licenses/mit-license.php", // url
	searchKeys // One or more full name descriptions used for matching
};

const LicenseData *pData = &data;

}; // end of namespace

#endif
