//
// LatinConstructs.h
//
// Contributed by christtrekker
//

#ifndef ORTHOGRAPHY_DATA
#include "../OrthographyData.h"
#endif

#ifndef LATIN_CONSTRUCTS
#define LATIN_CONSTRUCTS

// constructed languages based on Latin script (other than Esperanto)
// considered significant historically or due to wide usage:
// Afrihili, Bolak, Glosa, Ido, Interlingua, Volapük

namespace LatinConstructs{

//
// Unicode values
//
UINT32 values[]={
	START_RANGE_PAIR,
	0x0041,0x005A,
	START_RANGE_PAIR,
	0x0061,0x007A,
	0x00C4, 0x00E4, // A umlaut
	0x00D6, 0x00F6, // O umlaut
	0x00DC, 0x00FC, // U umlaut
	0x0186, 0x0254, // open O
	0x0190, 0x025B, // open E
	0x0427, 0x0447, // Che
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
	"Latin Constructs", // Common name
	"Latin Constructs", // Native name
	0x0186, // key: Ɔ
	values,
	"ÄäÖöÜüƆɔƐɛЧч", // Sample characters
	sentences
};

const OrthographyData *pData = &data;

}; // end of namespace

#endif
