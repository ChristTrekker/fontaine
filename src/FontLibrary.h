//
// The Fontaine Font Analysis Project 
// 
// Copyright (c) 2009 by Edward H. Trager
// All Rights Reserved
// 
// Released under the GNU GPL version 2.0 or later.
//     


#ifndef FONT_LIBRARY_INCLUDED
#define FONT_LIBRARY_INCLUDED

#include <ft2build.h>  
#include FT_FREETYPE_H

class FontLibrary{
	
private:
	
	FT_Library _library;
	
public:
	
	FontLibrary();
	~FontLibrary();
	
	FT_Library get();
	
};

#endif
