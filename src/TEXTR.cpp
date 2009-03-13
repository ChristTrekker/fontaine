//
// The Fontaine Font Analysis Project 
// 
// Copyright (c) 2009 by Edward H. Trager
// All Rights Reserved
// 
// Released under the GNU GPL version 2.0 or later.
//     


#include "TEXTR.h"
#include <cctype>

#include "BasicLatinStringUtilities.h"

//
// Constructor:
//
TEXTR::TEXTR(){
	
	// Use 3 spaces by default for TEXTR indentation:
	_indentationString = "   ";
	_listBullet = "•"; // Unicode Round Bullet U+2022 is our default ...
}


//
// start
//
void TEXTR::start(const std::string &key){
	
	_indent();
	_start(key);
	
	std::string k(key);
	_ss << BasicLatin::segmentize(k) << ":" << std::endl;
	
}

//
// start -- const char * version
//
void TEXTR::start(const char *key){
	
	std::string k(key);
	start(k);
	
}

//
// addKeyValuePair
//
void TEXTR::addKeyValuePair(const std::string &key,const std::string &value){
	
	_indent();
	
	std::string k(key);
	_ss << BasicLatin::segmentize(k) << ": " << value << std::endl;
	
}

//
// addKeyValuePair -- const char * version
//
void TEXTR::addKeyValuePair(const char *key,const char *value){
	
	std::string k(key);
	std::string v(value);
	
	addKeyValuePair(k,v);
	
}

//
// end
//
void TEXTR::end(const std::string &key){
	
	_end(key);
	_indent();
	
	_ss << std::endl;
	
	
}


//
// end -- const char * version
//
void TEXTR::end(const char *key){
	
	std::string k(key);
	end(k);
	
}

//
// startRoot
//
void TEXTR::startRoot(void){
	
	_ss << std::endl;
	
}

//
// endRoot
//
void TEXTR::endRoot(void){
	
	_ss << std::endl;
	
}

//
// startList
//
void TEXTR::startList(const std::string &key){
	
	start(key);
	
}

//
// addKeyValuePairToList
//
void TEXTR::addKeyValuePairToList(const std::string &key,const std::string &value){
	
	_indent();
	
	_ss << _listBullet << " " << value << std::endl;
	
}

//
// endList
//
void TEXTR::endList(const std::string &key){
	
	end(key);
	
}

//
// startList -- const char * version
//
void TEXTR::startList(const char *key){
	
	std::string k(key);
	startList(k);
	
}

//
// addKeyValuePairToList -- const char * version
//
void TEXTR::addKeyValuePairToList(const char *key,const char *value){
	
	std::string k(key);
	std::string v(value);
	addKeyValuePairToList(k,v);
	
}

//
// endList -- const char * version
//
void TEXTR::endList(const char *key){
	
	std::string k(key);
	endList(k);
	
}

//
// setListBullet
//
void TEXTR::setListBullet(const std::string &bullet){
	
	_listBullet = bullet;
	
}

//
// setListBullet -- const char * version
//
void TEXTR::setListBullet(const char *bullet){
	
	std::string b(bullet);
	setListBullet(b);
	
}
