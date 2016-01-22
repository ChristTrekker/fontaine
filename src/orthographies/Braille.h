//
// Braille.h
//
// Contributed by christtrekker
// 2015.08.13
//

#ifndef ORTHOGRAPHY_DATA
#include "../OrthographyData.h"
#endif

#ifndef BRAILLE6 // 8-dot Braille is mainly specialty usage
#define BRAILLE6

namespace Braille6{

//
// Unicode values
//
UINT32 values[]={
	START_RANGE_PAIR,
	0x2800,0x283F,
	END_OF_DATA
};

//
// Sample sentences
//
const char *sentences[]={
	"⠃⠗⠇⠀⠊⠎⠀⠠⠃⠗⠁⠊⠇⠇⠑⠲",
	END_OF_DATA
};


//
//
//
OrthographyData data={
	"Braille", // Common name
	"⠃⠗⠇", // Native name
	0x2801, // key
	values,
	"",// Sample characters
	sentences
};

const OrthographyData *pData = &data;

}; // end of namespace

#endif
