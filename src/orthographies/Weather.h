//
// Weather.h
//
// Contributed by christtrekker
//

#ifndef ORTHOGRAPHY_DATA
#include "../OrthographyData.h"
#endif

#ifndef WEATHER
#define WEATHER

namespace Weather{

//
// Unicode values 
//
UINT32 values[]={
	START_RANGE_PAIR,
	0x2600,0x2603,
	0x2607,
	0x2608,
	0x2614,
	0x263C,
	START_RANGE_PAIR,
	0x26C4,0x26C8,
	START_RANGE_PAIR,
	0x2744,0x2746,
	START_RANGE_PAIR,
	0x1F300,0x1F302,
	START_RANGE_PAIR,
	0x1F321,0x1F32C,
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
	"Weather", // Common name
	"Weather", // Native name
	0x211E, // key
	values,
	"",// Sample characters
	sentences
};

const OrthographyData *pData = &data;

}; // end of namespace

#endif
