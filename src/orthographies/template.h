//
// .h
//

#ifndef ORTHOGRAPHY_DATA
#include "../OrthographyData.h"
#endif

#ifndef 
#define 

namespace {

//
// Unicode values 
//
UINT32 values[]={
	START_RANGE_PAIR,
	0x,0x,
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
	"", // Common name
	"", // Native name
	0x, // key
	values,
	"", // Sample characters
	sentences
};

const OrthographyData *pData = &data;

}; // end of namespace

#endif
