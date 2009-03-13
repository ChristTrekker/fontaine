//
// The Fontaine Font Analysis Project 
// 
// Copyright (c) 2009 by Edward H. Trager
// All Rights Reserved
// 
// Released under the GNU GPL version 2.0 or later.
//     


#include "FontLibrary.h"

#include "Exception.h"


//
// Constructor:
//
FontLibrary::FontLibrary(){
	
	FT_Error err;
	
	err = FT_Init_FreeType( &_library ); 
	if(err) throw Exception("FontLibrary()","Unable to initialize the FreeType library");

	
}

//
// Destructor:
//
FontLibrary::~FontLibrary(){
	
	FT_Done_FreeType(_library);
	
}

//
// get(): Get the FreeType FT_Library pointer:
//
FT_Library FontLibrary::get(){
	
	return _library;
	
}



