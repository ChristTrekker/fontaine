//
// The Fontaine Font Analysis Project 
// 
// Copyright (c) 2009 by Edward H. Trager
// All Rights Reserved
// 
// Released under the GNU GPL version 2.0 or later.
//     


//
// BitstreamVera.h
//

#ifndef LICENSE_DATA
#include "LicenseData.h"
#endif

#ifndef BITSTREAM_VERA_LICENSE
#define BITSTREAM_VERA_LICENSE

namespace BitstreamVeraLicense{

//
// Sample sentences
// 
const char *searchKeys[]={
	"Bitstream",
	"Vera",
	"DejaVu",
	END_OF_LICENSE_NAMES
};


//
// LicenseData
//
LicenseData data={
	"Bitstream Vera License (and derivative projects)", // name
	"http://www.gnome.org/fonts/", // url
	searchKeys // descriptions used for matching
};

const LicenseData *pData = &data;

}; // end of namespace

#endif
