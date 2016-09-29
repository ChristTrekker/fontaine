//
// The Fontaine Font Analysis Project 
// 
// Copyright (c) 2009 by Edward H. Trager
// All Rights Reserved
// 
// Released under the GNU GPL version 2.0 or later.
//     


//
// SlavicCyrillic.h
//

#ifndef ORTHOGRAPHY_DATA
#include "../OrthographyData.h"
#endif

#ifndef SLAVIC_CYRILLIC
#define SLAVIC_CYRILLIC

namespace SlavicCyrillic{
// Belarusian, Bulgarian, Macedonian, Montenegrin, Russian, Serbian, Ukrainian

//
// Unicode values 
//
UINT32 values[]={
	START_RANGE_PAIR,
	0x0410,0x042f,
	0x0490,
	START_RANGE_PAIR,
	0x0401,0x040C,
	0x040E,
	0x040F,
	START_RANGE_PAIR,
	0x0430,0x044f,
	0x0491,
	START_RANGE_PAIR,
	0x0451,0x045C,
	0x045E,
	0x045F,
	0x0301,
	END_OF_DATA
};

//
// Sample sentences
// 
const char *sentences[]={
	"В чащах юга жил-был цитрус...—да, но фальшивый экземпляръ!",
	"Эх, чужак! Общий съём цен шляп (юфть) — вдрызг!",
	"Эй, жлоб! Где туз? Прячь юных съёмщиц в шкаф.",
	END_OF_DATA
};


//
// 
//
OrthographyData data={
	"Slavic Cyrillic", // Common name
	"Кири́ллица", // Native name
	0x0414, // CYRILLIC CAPITAL LETTER DE
	values,
	"АБВГДЕЖЗИЙКЛ", // Sample characters
	sentences
};

const OrthographyData *pData = &data;

}; // end of namespace

#endif
