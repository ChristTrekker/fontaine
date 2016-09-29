//
// The Fontaine Font Analysis Project 
// 
// Copyright (c) 2009 by Edward H. Trager
// All Rights Reserved
// 
// Released under the GNU GPL version 2.0 or later.
//     


//
// AsianCyrillic.h
//

#ifndef ORTHOGRAPHY_DATA
#include "../OrthographyData.h"
#endif

#ifndef ASIAN_CYRILLIC
#define ASIAN_CYRILLIC

namespace AsianCyrillic{
// Iranian: Kurdish, Ossetian, Tajik
// Mongolian: Buryat, Kalmyk, Khalkha
// Turkic: Bashkir, Chuvash, Kazakh, Kyrgyz, Tatar, Uzbek
// Uralic: Kildin Sami, Komi, Mari

//
// Unicode values 
//
UINT32 values[]={
	START_RANGE_PAIR,
	0x0410,0x042f,
	0x0406,
	0x0408, // only Sami
	0x040E, // only Uzbek
	0x048A, // only Sami
	0x048C, // only Sami
	0x048E, // only Sami
	0x0492,
	0x0496,
	0x0498,
	0x049A,
	0x04A0,
	0x04A2,
	0x04A4, // only Mari
	0x04AA,
	0x04B0, // only Kazakh
	0x04BA,
	0x04C5, // only Sami
	0x04C7, // only Sami
	0x04CD, // only Sami
	0x04D0,
	0x04D4,
	0x04D8,
	0x04E6,
	0x04E8,
	0x04EC, // only Sami
	0x04EE, // only Tajik
	0x04F2, // only Chuvash
	0x04F8, // only Mari
	0x051A, // only Kurdish
	0x051C, // only Kurdish
	START_RANGE_PAIR,
	0x0430,0x044f,
	0x0456,
	0x0458,
	0x045E,
	0x048B,
	0x048D,
	0x048F,
	0x0493,
	0x0497,
	0x0499,
	0x049B,
	0x04A1,
	0x04A3,
	0x04A5,
	0x04AB,
	0x04B1,
	0x04BB,
	0x04C6,
	0x04C8,
	0x04CE,
	0x04D1,
	0x04D5,
	0x04D9,
	0x04E7,
	0x04E9,
	0x04ED,
	0x04EF,
	0x04F3,
	0x04F9,
	0x051B,
	0x051D,
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
	"Asian Cyrillic", // Common name
	"Кири́ллица", // Native name
	0x0414, // CYRILLIC CAPITAL LETTER DE
	values,
	"АБВГДЕЖЗИЙКЛ", // Sample characters
	sentences
};

const OrthographyData *pData = &data;

}; // end of namespace

#endif
