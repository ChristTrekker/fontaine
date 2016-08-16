//
// Medical.h
//
// Contributed by christtrekker
//

#ifndef ORTHOGRAPHY_DATA
#include "../OrthographyData.h"
#endif

#ifndef MEDICAL
#define MEDICAL

namespace Medical{

//
// Unicode values 
//
UINT32 values[]={
	0x211E,
	0x2623,
	0x2695,
	0x271A,
	START_RANGE_PAIR,
	0x23BE,0x23CC, // Dentistry
	0x1F3E5,
	0x1F489,
	0x1F48A,
	0x1F54F,
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
	"Medical symbols", // Common name
	"Medical symbols", // Native name
	0x211E, // key
	values,
	"",// Sample characters
	sentences
};

const OrthographyData *pData = &data;

}; // end of namespace

#endif
