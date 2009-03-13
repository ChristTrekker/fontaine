//
// The Fontaine Font Analysis Project 
// 
// Copyright (c) 2009 by Edward H. Trager
// All Rights Reserved
// 
// Released under the GNU GPL version 2.0 or later.
//     

//
// XMLR.h -- XML Report
//

#ifndef  XMLR_INCLUDED
#define XMLR_INCLUDED

#include "MLR.h"

class XMLR : public MLR {
	
public:
	
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

