//
// Religion.h
//
// Contributed by christtrekker
// 2015.07.23
//

#ifndef ORTHOGRAPHY_DATA
#include "../OrthographyData.h"
#endif

#ifndef RELIGION
#define RELIGION

namespace Religion{

//
// Unicode values
//
UINT32 values[]={
	0x06DD,
	0x06DE,
	0x06E9,
	0x0FD5,
	0x0FD6,
	0x211F,
	0x2123,
	START_RANGE_PAIR,
	0x2625,0x262C,
	0x262F,
	0x2638,
	0x2670,
	0x2671,
	START_RANGE_PAIR,
	0x26E4,0x26E7,
	0x26E9,
	0x26EA,
	START_RANGE_PAIR,
	0x271D,0x2721,
	START_RANGE_PAIR,
	0x2CE7,0x2CE9,
	0xFDF2,
	0x101A0,
	0x1F4FF,
	START_RANGE_PAIR,
	0x1F540,0x1F54E,
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
	"Religious symbols", // Common name
	"Religious symbols", // Native name
	0x271D, // key
	values,
	"✡✝☯",// Sample characters
	sentences
};

const OrthographyData *pData = &data;

}; // end of namespace

#endif
