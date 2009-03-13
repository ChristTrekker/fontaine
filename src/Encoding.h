//
// The Fontaine Font Analysis Project 
// 
// Copyright (c) 2009 by Edward H. Trager
// All Rights Reserved
// 
// Released under the GNU GPL version 2.0 or later.
//     

#ifndef ENCODING_INCLUDED
#define ENCODING_INCLUDED
//
// We use some type definitions from Utf8String:
//
#include "Utf8String.h"

//
// Encoding:
//
class Encoding{
	
private:
	
	static UTF32 _macRoman[256];
	static UTF32 _macThai[256];
	static UTF32 _macArabic[256];
	static UTF32 _macCentralEuropean[256];
	
public:
	
	static UTF32 macRomanToUTF32( unsigned char idx);
	static UTF32 macThaiToUTF32 ( unsigned char idx);
	static UTF32 macCentralEuropeanToUTF32( unsigned char idx);
	
};

#endif
