//
// The Fontaine Font Analysis Project 
// 
// Copyright (c) 2009, 2015 by Edward H. Trager
// All Rights Reserved
// 
// Released under the GNU GPL version 2.0 or later.
//     


//
// Currencies.h
//

#ifndef ORTHOGRAPHY_DATA
#include "../OrthographyData.h"
#endif

#ifndef CURRENCIES_HISTORIC
#define CURRENCIES_HISTORIC

namespace CurrenciesOld{

//
// Unicode values 
//
UINT32 values[]={
	0x20A0,
	0x20A2,
	0x20A3,
	0x20A4,
	0x20A5,
	0x20A7,
	0x20A8,
	0x20AF,
	0x20B0,
	0x20B3,
	0x20B6,
	0x20B7,
	0x20BB,
	END_OF_DATA
};

//
// Sample sentences
// 
const char *sentences[]={
	"Unicode currency symbols ₠, ₢, ₣, ₤, ₥, ₧, ₳, ₶, ₷, and ₻ are not in use as of 2016.",
	END_OF_DATA
};


//
// data
//
OrthographyData data={
	"Historic Currencies",
	"Historic Currencies",
	0x20A3,
	values,
	"",
	sentences
};

const OrthographyData *pData = &data;

}; // end of namespace

#endif
