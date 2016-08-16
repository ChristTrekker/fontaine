//
// Klingon.h
//
// Contributed by christtrekker
// 2015.07.01
//

#ifndef ORTHOGRAPHY_DATA
#include "../OrthographyData.h"
#endif

#ifndef KLINGON
#define KLINGON

namespace Klingon{

//
// Unicode values
//
UINT32 values[]={
	START_RANGE_PAIR,
	0xF8D0,0xF8E9,
	START_RANGE_PAIR,
	0xF8F0,0xF8F9,
	START_RANGE_PAIR,
	0xF8FD,0xF8FF,
	END_OF_DATA
};

//
// Sample sentences
//
const char *sentences[]={
	"?",
	END_OF_DATA
};


//
//
//
OrthographyData data={
	"Klingon", // Common name
	" ", // Native name
	0xF8FF, // key
	values,
	"",// Sample characters
	sentences
};

const OrthographyData *pData = &data;

}; // end of namespace

#endif
