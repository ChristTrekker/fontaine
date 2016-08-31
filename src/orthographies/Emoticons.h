//
// The Fontaine Font Analysis Project 
// 
// Copyright (c) 2014 by Edward H. Trager
// All Rights Reserved
// 
// Released under the GNU GPL version 2.0 or later.
//     


//
// Emoticons.h
//

#ifndef ORTHOGRAPHY_DATA
#include "../OrthographyData.h"
#endif

#ifndef EMOTICONS
#define EMOTICONS

namespace Emoticons{

//
// Unicode values 
//
UINT32 values[]={
	//
	// facial expressions
	//
	START_RANGE_PAIR,
	0x2639,0x263B, // Sad & smily faces in the Miscellaneous Symbols block
	START_RANGE_PAIR,
	0x1F600,0x1F64F, // Emoticons Block
	START_RANGE_PAIR,
	0x1F910,0x1F917, // Supplemental Symbols and Pictographs
	START_RANGE_PAIR,
	0x1F920,0x1F927,
	//
	// selected hand and body gestures
	//
	START_RANGE_PAIR,
	0x270A,0x270C, // hands in Misc. Symbols block
	START_RANGE_PAIR,
	0x1F44A,0x1F450,
	0x1F483,
	0x1F4AA,
	START_RANGE_PAIR,
	0x1F58F,0x1F596,
	START_RANGE_PAIR,
	0x1F918,0x1F91E,
	0x1F933,
	START_RANGE_PAIR,
	0x1F937,0x1F939,
	//
	// abstract emotive symbols (e.g. hearts)
	//
	0x2620,
	0x2622,
	0x2764,
	0x1F3B5,
	0x1F3B6,
	0x1F480,
	START_RANGE_PAIR,
	0x1F48B,0x1F4A9,
	0x1F4AB,
	0x1F4AD,
	0x1F576,
	//
	// weather (mood metaphor)
	//
	0x2600,
	0x2601,
	0x263C,
	0x26C5,
	0x26C6,
	0x26C8,
	START_RANGE_PAIR,
	0x1F323,0x1F32A,
	//
	// celebration, congratulatory
	//
	0x1F37B,
	0x1F37E,
	START_RANGE_PAIR,
	0x1F380,0x1F382,
	START_RANGE_PAIR,
	0x1F386,0x1F38A,
	0x1F395,
	0x1F396,
	0x1F3AF,
	0x1F3C5,
	0x1F3C6,
	0x1F483,
	END_OF_DATA
};

//
// Sample sentences
// 
const char *sentences[]={
	"",
	"",
	END_OF_DATA
};


//
// 
//
OrthographyData data={
	"Emoticons",
	"Emoticons",
	0x263A, // WHITE SMILING FACE
	values,
	"",
	sentences
};

const OrthographyData *pData = &data;

}; // end of namespace

#endif

