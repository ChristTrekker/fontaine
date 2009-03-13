//
// The Fontaine Font Analysis Project 
// 
// Copyright (c) 2009 by Edward H. Trager
// All Rights Reserved
// 
// Released under the GNU GPL version 2.0 or later.
//     


//
// Math.h
//

#ifndef ORTHOGRAPHY_DATA
#include "../OrthographyData.h"
#endif

#ifndef MATH_OPERATORS 
#define MATH_OPERATORS

namespace MathematicalOperators{

//
// Unicode values 
//
UINT32 values[]={
	START_RANGE_PAIR,
	0x2200,0x22F1,
	END_OF_DATA
};

//
// Sample sentences
// 
const char *sentences[]={
	"∂∈∉∫∬≠⊂⊗⋈⋂",
	END_OF_DATA
};


//
// 
//
OrthographyData data={
	"Mathematical Operators", // Common name
	"Mathematical Operators", // Native name
	0x2208, // key
	values,
	"∂∈∉∫∬≠⊂⊗⋈⋂", // Sample characters
	sentences
};

const OrthographyData *pData = &data;

}; // end of namespace

#endif
