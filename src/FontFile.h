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
#include "Script.h"

enum fontStroke{ UNMODULATED, MODULATED };
enum fontWeight{ LIGHT, NORMAL_WEIGHT, BOLD };
enum fontStyle{ NORMAL, ITALIC, OBLIQUE };

//
// This class contains information
// about a single font file:
// 
class FontFile{
	
private:
	
	std::string _fileName;
	std::string _commonName;
	std::string _nativeName;
	
	fontStroke _stroke;
	fontWeight _weight;
	fontStyle  _style;
	
	std::set<Script> _supportedScripts;
	
};

