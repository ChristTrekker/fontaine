//
// The Fontaine Font Analysis Project 
// 
// Copyright (c) 2009, 2015 by Edward H. Trager
// All Rights Reserved
// 
// Released under the GNU GPL version 2.0 or later.
//     


//
// EskaleutLatin.h
//
// Contributed by christtrekker$
// Of the Eskaleut languages, the Aleut, Yuipik, and some Inuit languages
// are written using Latin letters. 
//

#ifndef ORTHOGRAPHY_DATA
#include "../OrthographyData.h"
#endif

#ifndef ALEUT_LATIN
#define ALEUT_LATIN

namespace EskaleutLatin{

//
// Unicode values 
//
UINT32 values[]={
	START_RANGE_PAIR,
	0x0041,0x0044,
	0x0046,
	0x0047,
	0x011C,
	0x0120,
	0x0048,
	0x0049,
	0x004B,
	0x004C,
	0x1E36,
	0x004D,
	0x1E3E,
	0x004E,
	0x00D1,
	0x0143,
	0x014A,
	START_RANGE_PAIR,
	0x004F,0x0055,
	0x00DB,
	START_RANGE_PAIR,
	0x0056,0x005A,
	START_RANGE_PAIR,
	0x0061,0x0064,
	0x0066,
	0x0067,
	0x011D,
	0x0121,
	0x0068,
	0x0069,
	START_RANGE_PAIR,
	0x006B,
	0x006C,
	0x1E37,
	0x006D,
	0x1E3F,
	0x006E,
	0x00F1,
	0x0144,
	0x014B,
	START_RANGE_PAIR,
	0x006F,0x0075,
	0x00FB,
	START_RANGE_PAIR,
	0x0076,0x007A,
	0x0302, // no separate codepoint for x with circumflex
	0x0323, // no separate codepoint for L stroke with dot below
	0x2019, // apostrophe indicates gemination in Yupik
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
	"Eskaleut Latin",
	"Inuktitut / Yugtun / Unangan",
	0x0041, // LATIN CAPITAL LETTER A
	values,
	"AaBbFfGgḾḿXxRrSsZz",
	sentences
};

const OrthographyData *pData = &data;

}; // end of namespace

#endif
