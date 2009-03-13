//
// The Fontaine Font Analysis Project 
// 
// Copyright (c) 2009 by Edward H. Trager
// All Rights Reserved
// 
// Released under the GNU GPL version 2.0 or later.
//     


#include "XMLR.h"

//
// start
//
void XMLR::start(const std::string &key){
	
	_indent();
	_start(key);
	
	_ss << "<" << key << ">" << std::endl;
	
}

void XMLR::start(const char *key){
	
	std::string k(key);
	start(k);
	
}

//
// addKeyValuePair
//
void XMLR::addKeyValuePair(const std::string &key,const std::string &value){
	
	_indent();
	
	_ss << "<" << key << ">" << value << "</" << key << ">" << std::endl;
	
}

//
// addKeyValuePair -- const char * version
//
void XMLR::addKeyValuePair(const char *key,const char *value){
	
	std::string k(key);
	std::string v(value);
	
	addKeyValuePair(k,v);
	
}

//
// end
//
void XMLR::end(const std::string &key){
	
	_end(key);
	_indent();
	
	_ss << "</" << key << ">" << std::endl;
	
}


//
// end
//
void XMLR::end(const char *key){
	
	std::string k(key);
	end(k);
	
}

//
// startRoot
//
void XMLR::startRoot(void){
	
	_ss << "<?xml version=\"1.0\" encoding=\"UTF-8\" ?>\n";
	_ss << "<" << _rootTag << ">\n" ;
	
}

//
// endRoot
//
void XMLR::endRoot(void){
	
	_ss << "</" << _rootTag << ">\n" ;
	
}

//
// startList()
//
// => For XML, this is identical to start()
//
void XMLR::startList(const std::string &key){
	
	start(key);
	
}

//
// addKeyValuePairToList()
//
// => For XML, this is identical to addKeyValuePair
//
void XMLR::addKeyValuePairToList(const std::string &key,const std::string &value){
	
	addKeyValuePair(key,value);
	
}

//
// endList
//
// => For XML, this is identical to end()
//
void XMLR::endList(const std::string &key){
	
	end(key);
	
}

void XMLR::startList(const char *key){
	
	start(key);
	
}

void XMLR::addKeyValuePairToList(const char *key,const char *value){
	
	addKeyValuePair(key,value);
	
}

void XMLR::endList(const char *key){
	
	end(key);
	
}

