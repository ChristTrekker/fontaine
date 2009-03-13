//
// The Fontaine Font Analysis Project 
// 
// Copyright (c) 2009 by Edward H. Trager
// All Rights Reserved
// 
// Released under the GNU GPL version 2.0 or later.
//     


//
// GPL.h
//

#ifndef LICENSE_DATA
#include "LicenseData.h"
#endif

#ifndef GPL_LICENSE
#define GPL_LICENCE

namespace GPL{

//
// Sample sentences
// 
const char *searchKeys[]={
	"GNU General Public License",
	"GPL",
	"General Public License",
	"GNU copyleft",
	END_OF_LICENSE_NAMES
};


//
// LicenseData
//
LicenseData data={
	"GNU General Public License", // acronym
	"http://www.gnu.org/copyleft/gpl.html", // url
	searchKeys // One or more full name descriptions used for matching
};

const LicenseData *pData = &data;

}; // end of namespace

#endif
