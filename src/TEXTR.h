//
// The Fontaine Font Analysis Project 
// 
// Copyright (c) 2009 by Edward H. Trager
// All Rights Reserved
// 
// Released under the GNU GPL version 2.0 or later.
//     

//
// TEXTR.h -- Plain Text Report
//

#ifndef  TEXTR_INCLUDED
#define  TEXTR_INCLUDED

#include "MLR.h"

class TEXTR : public MLR {
	
protected:
	
	std::string _listBullet;
	
public:
	
	TEXTR();
	
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
	
	void setListBullet(const std::string &bullet);
	void setListBullet(const char *bullet);
	
	//std::string & basicLatinCapitalize(std::string &s);
	//std::string & basicLatinSegmentize(std::string &s);
	
};

#endif

