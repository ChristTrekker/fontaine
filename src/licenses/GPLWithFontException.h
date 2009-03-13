//
// The Fontaine Font Analysis Project 
// 
// Copyright (c) 2009 by Edward H. Trager
// All Rights Reserved
// 
// Released under the GNU GPL version 2.0 or later.
//     


//
// GPLWithFontException.h
//

#ifndef LICENSE_DATA
#include "LicenseData.h"
#endif

#ifndef GPL_WITH_FONT_EXCEPTION
#define GPL_WITH_FONT_EXCEPTION

namespace GPLWithFontException{

//
// Sample sentences
// 
const char *searchKeys[]={
	"with font exception",
	END_OF_LICENSE_NAMES
};


//
// LicenseData
//
LicenseData data={
	"GPL with font exception", // name
	"http://www.gnu.org/copyleft/gpl.html", // url
	searchKeys // descriptions used for matching
};

const LicenseData *pData = &data;

}; // end of namespace

#endif
