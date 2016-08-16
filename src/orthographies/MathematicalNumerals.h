//
// The Fontaine Font Analysis Project 
// 
// Copyright (c) 2009, 2015 by Edward H. Trager
// All Rights Reserved
// 
// Released under the GNU GPL version 2.0 or later.
//     


//
// MathematicalNumerals.h
//
// Arabic numeral forms used in academia
// contributed by christtrekker
//

#ifndef ORTHOGRAPHY_DATA
#include "../OrthographyData.h"
#endif

#ifndef MATH_NUMERALS
#define MATH_NUMERALS

namespace MathematicalNumerals{

//
// Unicode values 
//
UINT32 values[]={
	START_RANGE_PAIR,
	0x0030,0x0039,
	// superscripts
	0x2070,0x00B9,0x00B2,0x00B3,START_RANGE_PAIR,0x2074,0x2079,
	//subscripts
	START_RANGE_PAIR,
	0x2080,0x2089,0x23E8,
	// fractions
	START_RANGE_PAIR,
	0x00BC,0x00BE,
	START_RANGE_PAIR,
	0x2150,0x215F,
	// typographic variants
	START_RANGE_PAIR,
	0x1D7CE,0x1D7FF,
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
	"Mathematical Numerals", // Common name
	"Mathematical Numerals", // Native name
	0x1D7D1, // key
	values,
	"", // Sample characters
	sentences
};

const OrthographyData *pData = &data;

}; // end of namespace

#endif
