//
// The Fontaine Font Analysis Project 
// 
// Copyright (c) 2009 by Edward H. Trager
// All Rights Reserved
// 
// Released under the GNU GPL version 2.0 or later.
//     


//
// JSON.h -- JSON Report
//

#ifndef  JSON_INCLUDED
#define JSON_INCLUDED

#include "MLR.h"

class JSONR : public MLR {
	
public:
	
	JSONR();
	
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
	
};

#endif

