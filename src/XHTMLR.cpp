//
// The Fontaine Font Analysis Project 
// 
// Copyright (c) 2009 by Edward H. Trager
// All Rights Reserved
// 
// Released under the GNU GPL version 2.0 or later.
//     


#include "XHTMLR.h"
#include "BasicLatinStringUtilities.h"

//
// Constructor:
//
XHTMLR::XHTMLR(){
	
	// Specific to XHTMLR:
	_startTag        = "div" ;
	_keyValuePairTag = "p"   ;
	_startListTag    = "ul"  ;
	_listItemTag     = "li"  ;
	
}

//
// start
//
void XHTMLR::start(const std::string &key){
	
	_indent();
	
	//
	// We need to know if the *parent* is a list
	// container, so this must come before _start(key):
	//
	bool isAListContainer = _isAListContainer();
	
	_start(key);
	
	if(isAListContainer){
		_ss << "<" << _listItemTag << " class=\"" << key << "\">" << std::endl;
	}else{
		_ss << "<" << _startTag << " class=\"" << key << "\">" << std::endl;
	}
	
}

void XHTMLR::start(const char *key){
	
	std::string k(key);
	start(k);
	
}

//
// addKeyValuePair
//
void XHTMLR::addKeyValuePair(const std::string &key,const std::string &value){
	
	_indent();
	
	std::string humanReadableKey = key;
	BasicLatin::segmentize(humanReadableKey);
	
	_ss << "<" << _keyValuePairTag << " class=\"" << key << "\">" << humanReadableKey << ": " << value << "</" << _keyValuePairTag << ">" << std::endl;
	
}

//
// addKeyValuePair -- const char * version
//
void XHTMLR::addKeyValuePair(const char *key,const char *value){
	
	std::string k(key);
	std::string v(value);
	
	addKeyValuePair(k,v);
	
}

//
// end
//
void XHTMLR::end(const std::string &key){
	
	_end(key);
	_indent();
	
	//
	// We need to know if the *parent* is a list:
	//
	if( _isAListContainer() ){
		_ss << "</" << _listItemTag << ">" << std::endl;
	}else{
		//
		// 'start' and 'end' tag have to match 
		// and we just decided to call the tag '_startTag'
		// because it was easy to remember that way:
		//
		_ss << "</" << _startTag << ">" << std::endl;
	}
	
}


//
// end -- const char * version
//
void XHTMLR::end(const char *key){
	
	std::string k(key);
	end(k);
	
}

//
// startRoot
//
void XHTMLR::startRoot(void){
	
	//
	// We assume that these reports are going to be XHTML fragments suitable for insertion
	// into a larger XHTML document, so we probably don't really want the DOCTYPE --and a
	// user may want to use a different doctype anyway:
	//
	// _ss << "<!DOCTYPE html PUBLIC \"-//W3C//dtd xhtml 1.1//EN\" \"http://www.w3.org/TR/xhtml11/dtd/xhtml11.dtd\">\n"; 
	//
	
	//
	// Use the root tag to declare the class of the root 'div' in XHTML:
	// As for the tag itself, use whatever '_startTag' is -- by default a 'div'
	// but user could change it to 'p' or something else ...
	//
	_ss << "<" << _startTag << " class=\"" << _rootTag << "\">\n" ;
	
}

//
// endRoot
//
void XHTMLR::endRoot(void){
	
	_ss << "</" << _startTag << ">\n" ;
	
}

//
// startList()
//
void XHTMLR::startList(const std::string &key){
	
	
	_indent();
	_start(key);
	_setAsListContainer();
	
	_ss << "<" << _startListTag << " class=\"" << key << "\">" << std::endl;
	
}

//
// addKeyValuePairToList()
//
void XHTMLR::addKeyValuePairToList(const std::string &key,const std::string &value){
	
	_indent();
	
	_ss << "<" << _listItemTag << " class=\"" << key << "\">" << value << "</" << _listItemTag << ">" << std::endl;
	
}

//
// endList
//
void XHTMLR::endList(const std::string &key){
	
	_end(key);
	_indent();
	
	//
	// 'start' and 'end' tag have to match 
	// and we just decided to call the tag '_startListTag'
	// because it was easy to remember that way:
	//
	_ss << "</" << _startListTag << ">" << std::endl;
	
}

//
// startList -- const char * version
//
void XHTMLR::startList(const char *key){
	
	std::string k(key);
	startList(k);
	
}

//
// addKeyValuePair -- const char * version
//
void XHTMLR::addKeyValuePairToList(const char *key,const char *value){
	
	std::string k(key);
	std::string v(value);
	addKeyValuePairToList(k,v);
	
}

//
// endList  -- const char * version
//
void XHTMLR::endList(const char *key){
	
	std::string k(key);
	endList(k);
	
}

//
// Setters added to XHTMLR class:
//
void XHTMLR::setStartTag(const std::string &s)       { _startTag        = s; }
void XHTMLR::setKeyValuePairTag(const std::string &s){ _keyValuePairTag = s; }
void XHTMLR::setStartListTag(const std::string &s)   { _startListTag    = s; }
void XHTMLR::setListItemTag(const std::string &s)    { _listItemTag     = s; }
//
// const char * versions:
//
void XHTMLR::setStartTag(const char *s)       { std::string ss(s); setStartTag(ss);        }
void XHTMLR::setKeyValuePairTag(const char *s){ std::string ss(s); setKeyValuePairTag(ss); }
void XHTMLR::setStartListTag(const char *s)   { std::string ss(s); setStartListTag(ss);    }
void XHTMLR::setListItemTag(const char *s)    { std::string ss(s); setListItemTag(ss);     }
