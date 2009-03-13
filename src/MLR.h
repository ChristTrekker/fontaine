//
// The Fontaine Font Analysis Project 
// 
// Copyright (c) 2009 by Edward H. Trager
// All Rights Reserved
// 
// Released under the GNU GPL version 2.0 or later.
//     


//
// MLR.h
//
// Markup Language Report base class
//

#ifndef MLR_INCLUDED
#define MLR_INCLUDED

#include <string>
#include <vector>
#include <sstream>
#include <stack>

class MLRItem {
	
private:
	
	std::string   _key;
	unsigned _children;
	bool _isAListContainer;
	
public:
	
	MLRItem(const std::string &key);
	
	void incrementChildren();
	void operator++();
	void setAsListContainer();
	
	std::string getKey()           const { return _key;              };
	unsigned getNumberOfChildren() const { return _children;         };
	bool isAListContainer()        const;
};

//
// Markup Language Report base class
//
class MLR {
	
private:
	
	MLRItem *_item;
	
	
protected:
	
	std::string _rootTag;
	
	std::string _indentationString;
	std::stack<MLRItem *> _stack;
	std::ostringstream _ss;
	
	void _start(const std::string &key);
	void _end(const std::string &key);
	
	void _incrementChildren();
	unsigned _getNumberOfChildren();
	
	void _indent(void);
	
	void _setAsListContainer(void);
	bool _isAListContainer(void);
	
public:
	
	MLR();
	virtual ~MLR(){};
	
	void setRootTag(const std::string &tag);
	void setRootTag(const char *tag);
	 
	//
	// Virtuals and Pure Virtuals for defining in sub classes:
	//
	
	virtual void startRoot(void)=0;
	virtual void endRoot(void)=0;
	
	virtual void startList(const std::string &key)=0;
	virtual void addKeyValuePairToList(const std::string &key,const std::string &value)=0;
	virtual void endList(const std::string &key)=0;
	virtual void start(const std::string &key)=0;
	virtual void addKeyValuePair(const std::string &key,const std::string &value)=0;
	virtual void end(const std::string &key)=0;
	
	virtual void startList(const char *key)=0;
	virtual void addKeyValuePairToList(const char *key,const char *value)=0;
	virtual void endList(const char *key)=0;
	virtual void start(const char *key)=0;
	virtual void addKeyValuePair(const char *key,const char *value)=0;
	virtual void end(const char *key)=0;
	
	void setIndentationString(const std::string &indent);
	
	virtual std::string getReport() const;
	
};

#endif
