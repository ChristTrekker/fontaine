//
// The Fontaine Font Analysis Project 
// 
// Copyright (c) 2009, 2011, 2014 by Edward H. Trager
// All Rights Reserved
// 
// Released under the GNU GPL version 2.0 or later.
//

//
// MUFI_3_0.h
//

#ifndef ORTHOGRAPHY_DATA
#include "../OrthographyData.h"
#endif

#ifndef MUFI_3_0
#define MUFI_3_0

namespace Mufi_3_0 {

//
// Unicode values: Based on http://www.mufi.info/specs/MUFI-CodeChart-3-0.pdf: 
//
UINT32 values[]={
	START_RANGE_PAIR,
	0x0020,0x007F,     // Basic ASCII Latin subset
	START_RANGE_PAIR,
	0x00A0,0x00FF,     // Latin 1 Supplement
	START_RANGE_PAIR,
	0x0100,0x010B,
	START_RANGE_PAIR,
	0x0110,0x0121,
	0x0127,
	START_RANGE_PAIR,
	0x012A,0x0133,
	START_RANGE_PAIR,
	0x0139,0x013A,
	START_RANGE_PAIR,
	0x0141,0x0144,
	START_RANGE_PAIR,
	0x014A,0x0155,
	START_RANGE_PAIR,
	0x015A,0x015B,
	START_RANGE_PAIR,
	0x016A,0x016F,
	START_RANGE_PAIR,
	0x0170,0x017C,
	0x017F,
	0x0180,
	0x0195,
	0x0199,
	0x019A,
	0x019E,
	0x01A6,
	START_RANGE_PAIR,
	0x01B5,0x01B7,
	0x01BF,
	START_RANGE_PAIR,
	0x01D1,0x01D6,
	START_RANGE_PAIR,
	0x01E2,0x01E5,
	START_RANGE_PAIR,
	0x01EA,0x01ED,
	START_RANGE_PAIR,
	0x01F4,0x01F7,
	START_RANGE_PAIR,
	0x01FC,0x01FF,
	START_RANGE_PAIR,
	0x021C,0x021D,
	START_RANGE_PAIR,
	0x0226,0x0227,
	START_RANGE_PAIR,
	0x022A,0x022B,

	START_RANGE_PAIR,
	0x,0x,
	START_RANGE_PAIR,
	0x,0x,
	START_RANGE_PAIR,
	0x,0x,
	START_RANGE_PAIR,
	0x,0x,
	START_RANGE_PAIR,
	0x,0x,
	START_RANGE_PAIR,
	0x,0x,
	END_OF_DATA
};

//
// Sample sentences
// 
const char *sentences[]={
	"",
	END_OF_DATA
};


//
// 
//
OrthographyData data={
	"MUFI 3.0", // Common name
	"MUFI 3.0", // Native name
	0x, // key
	values,
	"", // Sample characters
	sentences
};

const OrthographyData *pData = &data;

}; // end of namespace

#endif
