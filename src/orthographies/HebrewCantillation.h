//
// The Fontaine Font Analysis Project 
// 
// Copyright (c) 2016
// All Rights Reserved
// 
// Released under the GNU GPL version 2.0 or later.
//     


//
// HebrewCantillation.h
//

#ifndef ORTHOGRAPHY_DATA
#include "../OrthographyData.h"
#endif

#ifndef HEBREW_CANTILLATION
#define HEBREW_CANTILLATION

namespace HebrewCantillation{

//
// Unicode values 
//
UINT32 values[]={
	START_RANGE_PAIR,
	0x0591,0x05af,
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
	"Hebrew Cantillation", // Common name
	"טעמי המקרא", // Native name
	0x0591, // ETNAHTA
	values,
	"", // Sample characters
	sentences
};

const OrthographyData *pData = &data;

}; // end of namespace

#endif
