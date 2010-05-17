//
// The Fontaine Font Analysis Project 
// 
// Copyright (c) 2009 by Edward H. Trager
// All Rights Reserved
// 
// Released under the GNU GPL version 2.0 or later.
//     


#include "JSONR.h"

// Needed for BasicLatin::EscapeASCIIDoubleQuote() function:
#include "BasicLatinStringUtilities.h" 

//
// Constructor:
//
JSONR::JSONR(){
	
	// Use 2 spaces by default for JSON indentation:
	_indentationString = "  ";
	
}

//
// start
//
void JSONR::start(const std::string &key){
	
	if(_getNumberOfChildren()>0){
		_ss << "," ;
	}
	
	_ss << std::endl;
	
	_indent();
	
	//
	// We need to know if the *parent* is a list
	// container, so this must come before _start(key):
	//
	bool isAListContainer = _isAListContainer();
	
	_start(key);
	
	if(isAListContainer){
		//
		// In JSON, just write out the bracket if
		// we are inside a list container (i.e. array):
		//
		_ss << "{" ;
		
	}else{
		//
		// The default case:
		//
		_ss << "\"" << key << "\":{" ;
		
	}
	
}

//
// start -- const char version
//
void JSONR::start(const char *key){
	
	std::string k(key);
	start(k);
	
}

//
// addKeyValuePair
//
void JSONR::addKeyValuePair(const std::string &key,const std::string &value){
	
	if(_getNumberOfChildren()>0){
		_ss << "," ;
	}
	
	_ss << std::endl;
	
	_incrementChildren();
	_indent();
	
	std::string v(value);
	BasicLatin::escapeASCIIDoubleQuote(v);
	_ss << "\"" << key << "\":\"" << v << "\"" ;
	
}

//
// addKeyValuePair -- const char * version
//
void JSONR::addKeyValuePair(const char *key,const char *value){
	
	std::string k(key);
	std::string v(value);
	
	addKeyValuePair(k,v);
	
}

//
// end
//
void JSONR::end(const std::string &key){
	
	_end(key);
	
	_ss << std::endl;
	
	_indent();
	
	_ss << "}" ;
	
	_incrementChildren();
	
}


//
// end -- const char * version
//
void JSONR::end(const char *key){
	
	std::string k(key);
	end(k);
	
}

//
// startRoot
//
void JSONR::startRoot(void){
	
	_ss << "{" ;
	
}

//
// endRoot
//
void JSONR::endRoot(void){
	
	_ss << "}" << std::endl;
	
}

//
// startList
//
void JSONR::startList(const std::string &key){
	
	if(_getNumberOfChildren()>0){
		_ss << "," ;
	}
	
	_ss << std::endl;
	
	_indent();
	_start(key);
	_setAsListContainer();
	
	_ss << "\"" << key << "\":[" ;
	
}

//
// addKeyValuePairToList
//
void JSONR::addKeyValuePairToList(const std::string &key,const std::string &value){
	
	if(_getNumberOfChildren()>0){
		_ss << "," ;
	}
	
	_ss << std::endl;
	
	_incrementChildren();
	_indent();
	
	_ss << "\"" << value << "\"" ;
	
}

//
// endList
//
void JSONR::endList(const std::string &key){
	
	_end(key);
	
	_ss << std::endl;
	
	_indent();
	
	_ss << "]" ;
	
}

//
// startList -- const char * version
//
void JSONR::startList(const char *key){
	
	std::string k(key);
	startList(k);
	
}

//
// addKeyValuePairToList -- const char * version
//
void JSONR::addKeyValuePairToList(const char *key,const char *value){
	
	std::string k(key);
	std::string v(value);
	
	addKeyValuePairToList(k,v);
	
}

//
// endList -- const char * version
//
void JSONR::endList(const char *key){
	
	std::string k(key);
	
	endList(k);
	
}



