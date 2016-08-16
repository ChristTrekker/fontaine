//
// The Fontaine Font Analysis Project 
// 
// Copyright (c) 2009 by Edward H. Trager
// All Rights Reserved
// 
// Released under the GNU GPL version 2.0 or later.
//     


//
// Thai.h
//

#ifndef ORTHOGRAPHY_DATA
#include "../OrthographyData.h"
#endif

#ifndef THAI
#define THAI

namespace Thai{

//
// Unicode values 
//
UINT32 values[]={
	/* consonants */
	START_RANGE_PAIR,
	0x0e01,0x0e23,
	0x0e25,
	START_RANGE_PAIR,
	0x0e27,0x0e2e,
	0x0e33,
	/* vowels */
	START_RANGE_PAIR,
	0x0e30,0x0e36,
	0x0e38,
	0x0e39,
	0x0e3a,
	0x0e40,
	0x0e42,
	0x0e43,
	0x0e44,
	0x0e45,
	0x0e4d,
	/* tones and diacritics */
	START_RANGE_PAIR,
	0x0e47,0x0e4c,
	END_OF_DATA
};

//
// Sample sentences
// 
const char *sentences[]={
	"มื่อชั่วพ่อขุนรามคำแหง เมืองสุโขทัยนี้ดี ในน้ำมีปลา ในนามีข้าว",
	END_OF_DATA
};


//
// 
//
OrthographyData data={
	"Thai", // Common name
	"ภาษาไทย", // Native name
	0x0e01, // THAI CHARACTER KO KAI
	values,
	"ฟหกดสวงท", // Sample characters
	sentences
};

const OrthographyData *pData = &data;

}; // end of namespace

#endif
