//
// The Fontaine Font Analysis Project 
// 
// Copyright (c) 2009 by Edward H. Trager
// All Rights Reserved
// 
// Released under the GNU GPL version 2.0 or later.
//     


#include <string>
#include <set>
#include "FontFace.h"

//
// A FontFamily is a collection of FontFiles
// bearing the same family name.
// 
class FontFamily{
	
public:
	
	//
	// FontFamilies are distinguished uniquely by 
	// commonName:
	// 
	struct compare{
		bool operator()(const FontFamily *f1,const FontFamily *f2) const{
			return f1->_commonName < f2->_commonName;
		}
	};
	
	
private:
	
	std::string _commonName;
	std::string _nativeName;
	
	//
	// A FontFamily consists of a set of FontFaces:
	//
	std::set<FontFace *,FontFace::compare> _fontFaces;
	
};

