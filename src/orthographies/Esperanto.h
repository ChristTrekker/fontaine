//
// The Fontaine Font Analysis Project 
// 
// Copyright (c) 2009, 2011, 2014, 2016 by Edward H. Trager
// All Rights Reserved
// 
// Released under the GNU GPL version 2.0 or later.
//

//
// Esperanto.h
//

#ifndef ORTHOGRAPHY_DATA
#include "../OrthographyData.h"
#endif

#ifndef ESPERANTO
#define ESPERANTO

namespace Esperanto{

//
// Unicode values 
// Extended Latin characters unique to Esperanto:
//
UINT32 values[]={
	START_RANGE_PAIR,
	0x0108, // Ĉ
	0x0109, // ĉ
	0x011C, // Ĝ
	0x011D, // ĝ
	0x0124, // Ĥ
	0x0125, // ĥ
	0x0134, // Ĵ
	0x0135, // ĵ
	0x015C, // Ŝ
	0x015D, // ŝ
	0x016C, // Ŭ
	0x016D, // ŭ
	END_OF_DATA
};

//
// Sample sentences
// 
const char *sentences[]={
	"Tri tre drinkemaj fratoj trafis truon de l' trotuaro",
	END_OF_DATA
};


//
// 
//
OrthographyData data={
	"Esperanto", // Common name
	"Esperanto", // Native name
	0x0108, // key: Ĉ
	values,
	"ĈĜĤĴŜŬĉĝĥĵŝŭ", // Sample characters
	sentences
};

const OrthographyData *pData = &data;

}; // end of namespace

#endif
