//
// The Fontaine Font Analysis Project 
// 
// Copyright (c) 2009 by Edward H. Trager
// All Rights Reserved
// 
// Released under the GNU GPL version 2.0 or later.
//     


//
// Kokuji.h
//

#ifndef ORTHOGRAPHY_DATA
#include "../OrthographyData.h"
#endif

#ifndef KOKUJI
#define KOKUJI

namespace Kokuji{

//
// Unicode values
// 
// Based on a partial list presented at
// http://www.sljfaq.org/w/kokuji,
// this list should still be quite helpful in identifying
// a truly Japanese font from a Chinese font ... maybe.
//
UINT32 values[]={
	0x9c2f,
	0x6a2b,
	0x7c81,
	0x55b0,
	0x8fbc,
	0x698a,
	0x9d2b,
	0x7cce,
	0x51e7,
	0x9c48,
	0x6802,
	0x8fbb,
	0x5ce0,
	0x6803,
	0x5678,
	0x51ea,
	0x5302,
	0x7551,
	0x7560,
	0x567a,
	0x92f2,
	0x8fba,
	0x67fe,
	0x4fe3,
	0x9ebf,
	0x7c8d,
	0x6762,
	0x7c7e,
	0x5301,
	0x9453,
	0x67a0,
	0x6bdf,
	0x4e44,
	0x6318,
	0x685b,
	0x68bb,
	END_OF_DATA
};

//
// Sample sentences
// 
const char *sentences[]={
	"碓氷峠（うすいとうげ）は群馬県安中市松井田町と長野県北佐久郡軽井沢町との境にある日本の峠である。",
	END_OF_DATA
};


//
// 
//
OrthographyData data={
	"Japanese Kokuji",
	"日本国字",
	0x5ce0, // Mountain pass, 峠 
	values,
	"峠栂込榊鴫辻畑柾梻毟",
	sentences
};

const OrthographyData *pData = &data;

}; // end of namespace

#endif
