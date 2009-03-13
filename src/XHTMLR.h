//
// The Fontaine Font Analysis Project 
// 
// Copyright (c) 2009 by Edward H. Trager
// All Rights Reserved
// 
// Released under the GNU GPL version 2.0 or later.
//     

//
// XHTMLR.h -- Basic XHTML Report
//

#ifndef  XHTMLR_INCLUDED
#define XHTMLR_INCLUDED

#include "MLR.h"

class XHTMLR : public MLR {
	
protected:
	
	std::string _startTag;
	std::string _keyValuePairTag;
	std::string _startListTag;
	std::string _listItemTag;
	
public:
	
	XHTMLR();
	
	void startRoot(void);
	void endRoot(void);
	
	void startList(const std::string &key);
	void addKeyValuePairToList(const std::string &key,const std::string &value);
	void endList(const std::string &key);
	
	void start(const std::string &key);
	void addKeyValuePair(const std::string &key,const std::string &value);
	void end(const std::string &key);
	
	void startList(const char *key);
	void addKeyValuePairToList(const char *key,const char *value);
	void endList(const char *key);
	
	void start(const char *key);
	void addKeyValuePair(const char *key,const char *value);
	void end(const char *key);
	
	void setStartTag(const std::string &s);
	void setKeyValuePairTag(const std::string &s);
	void setStartListTag(const std::string &s);
	void setListItemTag(const std::string &s);
	// const char * versions:
	void setStartTag(const char *s);
	void setKeyValuePairTag(const char *s);
	void setStartListTag(const char *s);
	void setListItemTag(const char *s);
	
};

#endif

