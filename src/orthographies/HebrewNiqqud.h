//
// The Fontaine Font Analysis Project 
// 
// Copyright (c) 2016 
// All Rights Reserved
// 
// Released under the GNU GPL version 2.0 or later.
//     


//
// HebrewNiqqud.h
//

#ifndef ORTHOGRAPHY_DATA
#include "../OrthographyData.h"
#endif

#ifndef HEBREW_NIQQUD
#define HEBREW_NIQQUD

namespace HebrewNiqqud{

//
// Unicode values 
//
UINT32 values[]={
	START_RANGE_PAIR,
	0x05b0,0x05bc,
	0x05bf,
	0x05c1,
	0x05c2,
	END_OF_DATA
};

//
// Sample sentences
// 
const char *sentences[]={
	"לָכֵ֤ן חַכּוּ־לִי֙ נְאֻם־ה֔׳ לְי֖וֹם קוּמִ֣י לְעַ֑ד כִּ֣י מִשְׁפָּטִי֩ לֶאֱסֹ֨ף גּוֹיִ֜ם לְקָבְצִ֣י מַמְלָכ֗וֹת לִשְׁפֹּ֨ךְ עֲלֵיהֶ֤ם זַעְמִי֙ כֹּ֚ל חֲר֣וֹן אַפִּ֔י כִּ֚י בְּאֵ֣שׁ קִנְאָתִ֔י תֵּאָכֵ֖ל כָּל־הָאָֽרֶץ",
	END_OF_DATA
};


//
// 
//
OrthographyData data={
	"Hebrew Niqqud", // Common name
	"נִקּוּד", // Native name
	0x05bc, // DAGESH
	values,
	"", // Sample characters
	sentences
};

const OrthographyData *pData = &data;

}; // end of namespace

#endif
