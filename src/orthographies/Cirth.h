//
// Cirth.h
//
// Contributed by christtrekker
// 2015.07.01
//

#ifndef ORTHOGRAPHY_DATA
#include "../OrthographyData.h"
#endif

#ifndef CIRTH
#define CIRTH

namespace Cirth{

//
// Unicode values
//
UINT32 values[]={
	START_RANGE_PAIR,
	0xE080,0xE0EB,
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
	"Cirth", // Common name
	"", // Native name
	0xE080, // key
	values,
	"",// Sample characters
	sentences
};

const OrthographyData *pData = &data;

}; // end of namespace

#endif
