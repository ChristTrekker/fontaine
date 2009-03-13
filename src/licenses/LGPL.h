//
// The Fontaine Font Analysis Project 
// 
// Copyright (c) 2009 by Edward H. Trager
// All Rights Reserved
// 
// Released under the GNU GPL version 2.0 or later.
//     


//
// LGPL.h
//

#ifndef LICENSE_DATA
#include "LicenseData.h"
#endif

#ifndef LGPL_LICENSE
#define LGPL_LICENSE

namespace LGPL{

//
// Sample sentences
// 
const char *searchKeys[]={
	"GNU Lesser General Public License",
	"Lesser General Public License",
	END_OF_LICENSE_NAMES
};


//
// LicenseData
//
LicenseData data={
	"GNU Lesser General Public License", // name
	"http://www.gnu.org/licenses/lgpl.html", // url
	searchKeys // One or more full name descriptions used for matching
};

const LicenseData *pData = &data;

}; // end of namespace

#endif
