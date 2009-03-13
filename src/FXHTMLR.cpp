//
// The Fontaine Font Analysis Project 
// 
// Copyright (c) 2009 by Edward H. Trager
// All Rights Reserved
// 
// Released under the GNU GPL version 2.0 or later.
//     


#include "FXHTMLR.h"
#include "BasicLatinStringUtilities.h"
#include "Message.h" // ... for localization L() ...
#include "BasicLatinStringUtilities.h" // ... for segmentize()

//
// Constructor:
//
FXHTMLR::FXHTMLR(){
	
	// Specific to FXHTMLR:
	_startTag        = "div" ;
	_keyValuePairTag = "p"   ;
	_startListTag    = "ul"  ;
	_listItemTag     = "li"  ;
	
}

//
// start
//
void FXHTMLR::start(const std::string &key){
	
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

void FXHTMLR::start(const char *key){
	
	std::string k(key);
	start(k);
	
}

//
// addKeyValuePair
//
void FXHTMLR::addKeyValuePair(const std::string &key,const std::string &value){
	
	std::string k;
	
	if(key == "commonName"){
		_fsp.commonName = value;
		goto normalCase;
	}else if(key == "nativeName"){
		_fsp.nativeName = value;
		goto normalCase;
	}else if(key == "supportLevel"){
		_fsp.supportLevel = value;
		BasicLatin::toUpperCase(_fsp.supportLevel);
		goto specialCase;
	}else if(key == "percentCoverage"){
		_fsp.percentCoverage = value;
		goto specialCase;
	}
	
	//
	// DEFAULT:
	//
	normalCase:
	
	_indent();
	_ss << "<" << _keyValuePairTag << " class=\"" << key << "\">" ;
	k=key;
	_ss << L(BasicLatin::segmentize(k).c_str()) << ": ";
	_ss << value << "</" << _keyValuePairTag << ">" << std::endl;
	
	//
	// SPECIAL CASE:
	//
	specialCase:
	
	if( _fsp.supportLevel=="FULL" || _fsp.percentCoverage.size()>0 ){
		
		_indent();
		
		_ss << "<" << _keyValuePairTag << " class=\"coverage\">" ;
		
		if( _fsp.percentCoverage.size()>0 ){
			
			_ss << L("This font has %1$s (%2$s%) coverage of %3$s (%4$s).",_fsp.supportLevel.c_str(),_fsp.percentCoverage.c_str(),_fsp.commonName.c_str(),_fsp.nativeName.c_str());
		}else{
			_ss << L("This font has %1$s coverage of %2$s (%3$s).",_fsp.supportLevel.c_str(),_fsp.commonName.c_str(),_fsp.nativeName.c_str());
		}
		_ss << "</" << _keyValuePairTag << ">" << std::endl;
		
		// clear fsp for next iteration:
		_fsp.clear();
		
	}else{
		return;
	}
}

//
// addKeyValuePair -- const char * version
//
void FXHTMLR::addKeyValuePair(const char *key,const char *value){
	
	std::string k(key);
	std::string v(value);
	
	addKeyValuePair(k,v);
	
}

//
// end
//
void FXHTMLR::end(const std::string &key){
	
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
void FXHTMLR::end(const char *key){
	
	std::string k(key);
	end(k);
	
}

//
// startRoot
//
void FXHTMLR::startRoot(void){
	
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
void FXHTMLR::endRoot(void){
	
	_ss << "</" << _startTag << ">\n" ;
	
}

//
// startList()
//
void FXHTMLR::startList(const std::string &key){
	
	
	_indent();
	_start(key);
	_setAsListContainer();
	
	_ss << "<" << _startListTag << " class=\"" << key << "\">" << std::endl;
	
}

//
// addKeyValuePairToList()
//
void FXHTMLR::addKeyValuePairToList(const std::string &key,const std::string &value){
	
	_indent();
	
	_ss << "<" << _listItemTag << " class=\"" << key << "\">" << value << "</" << _listItemTag << ">" << std::endl;
	
}

//
// endList
//
void FXHTMLR::endList(const std::string &key){
	
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
void FXHTMLR::startList(const char *key){
	
	std::string k(key);
	startList(k);
	
}

//
// addKeyValuePair -- const char * version
//
void FXHTMLR::addKeyValuePairToList(const char *key,const char *value){
	
	std::string k(key);
	std::string v(value);
	addKeyValuePairToList(k,v);
	
}

//
// endList  -- const char * version
//
void FXHTMLR::endList(const char *key){
	
	std::string k(key);
	endList(k);
	
}

//
// Setters added to FXHTMLR class:
//
void FXHTMLR::setStartTag(const std::string &s)       { _startTag        = s; }
void FXHTMLR::setKeyValuePairTag(const std::string &s){ _keyValuePairTag = s; }
void FXHTMLR::setStartListTag(const std::string &s)   { _startListTag    = s; }
void FXHTMLR::setListItemTag(const std::string &s)    { _listItemTag     = s; }
//
// const char * versions:
//
void FXHTMLR::setStartTag(const char *s)       { std::string ss(s); setStartTag(ss);        }
void FXHTMLR::setKeyValuePairTag(const char *s){ std::string ss(s); setKeyValuePairTag(ss); }
void FXHTMLR::setStartListTag(const char *s)   { std::string ss(s); setStartListTag(ss);    }
void FXHTMLR::setListItemTag(const char *s)    { std::string ss(s); setListItemTag(ss);     }
