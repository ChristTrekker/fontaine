//
// The Fontaine Font Analysis Project 
// 
// Copyright (c) 2009 by Edward H. Trager
// All Rights Reserved
// 
// Released under the GNU GPL version 2.0 or later.
//     

//
// Afrikaans.h
//

#ifndef ORTHOGRAPHY_DATA
#include "../OrthographyData.h"
#endif

#ifndef AFRIKAANS
#define AFRIKAANS

namespace Afrikaans{

//
// Unicode values 
//
UINT32 values[]={
	0x00C8,
	0x00E8,
	0x00C9,
	0x00E9,
	0x00CA,
	0x00EA,
	0x00CB,
	0x00EB,
	0x00CE,
	0x00EE,
	0x00CF,
	0x00EF,
	0x00D4,
	0x00F4,
	0x00DB,
	0x00FB,
	0x0149,
	END_OF_DATA
};

//
// Sample sentences
// 
const char *sentences[]={
	"Alle menslike wesens word vry, met gelyke waardigheid en regte, gebore.",
	END_OF_DATA
};


//
// 
//
OrthographyData data={
	"Afrikaans",
	"Afrikaans",
	0x0149, // LATIN SMALL LETTER N PRECEDED BY APOSTROPHE
	values,
	"ÈèËëÔôÛûŉ",
	sentences
};

const OrthographyData *pData = &data;

}; // end of namespace

#endif
