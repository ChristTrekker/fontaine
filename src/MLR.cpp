//
// The Fontaine Font Analysis Project 
// 
// Copyright (c) 2009 by Edward H. Trager
// All Rights Reserved
// 
// Released under the GNU GPL version 2.0 or later.
//     


//
// MLR.cpp
//
// Markup Language Report base class
//

#include "MLR.h"
#include "Warning.h"

///////////////////////////////////////////
//
// class MLRItems Methods
//
///////////////////////////////////////////

MLRItem::MLRItem(const std::string &key){
	
	_key      = key;
	_children = 0;
	_isAListContainer = false;
	   
}

//
// incrementChildren:
//
void MLRItem::incrementChildren(){
	
	_children++;
	
}

//
// operator++: same as incrementChildren
//
void MLRItem::operator++(){
	
	_children++;
	
}

//
// setAsListContainer
//
void MLRItem::setAsListContainer(){
	
	_isAListContainer = true;
	
}

//
// isAListContainer -- CONST
//
bool MLRItem::isAListContainer() const{
	
	return _isAListContainer; 
	
};
///////////////////////////////////////////
//
// class MLR Methods
//
///////////////////////////////////////////

//
// Constructor:
//
MLR::MLR(){
	
	_indentationString=" ";
	_rootTag = "report";
	
}

//
// _start -- PROTECTED:
//
void MLR::_start(const std::string &key){
	
	_stack.push( new MLRItem(key) );
	
}

//
// _incrementChildren -- PROTECTED
//
void MLR::_incrementChildren(void){
	
	if(_stack.size()==0) return;
	
	MLRItem *element = _stack.top();
	element->incrementChildren();
	
}

//
// _getNumberOfChildren -- PROTECTED
//
unsigned MLR::_getNumberOfChildren(void){
	
	if(_stack.size()==0) return 0;
	
	MLRItem *element = _stack.top();
	return element->getNumberOfChildren();
	
}

//
// _end -- PROTECTED
//
void MLR::_end(const std::string &key){
	
	MLRItem *e = _stack.top();
	
	if( e->getKey() != key ){
		
		Warning("MLR::_end()","Start element '%s' does not match end element '%s'!",e->getKey().c_str(),key.c_str());
		
	}
	
	_stack.pop();
	
}


//
// _indent -- PROTECTED
//
void MLR::_indent(void){
	
	// Indentation:
	for(unsigned i=0;i<_stack.size();i++) _ss << _indentationString;
	
}

//
// setIndentationString
//
void MLR::setIndentationString(const std::string &indent){
	
	_indentationString = indent;
	
}

//
// getReport
//
std::string MLR::getReport() const{
	
	return _ss.str(); 
	
};

//
// setRootTag
//
void MLR::setRootTag(const std::string &tag){
	
	_rootTag=tag;
	
}

//
// setRootTag -- const char * version
//
void MLR::setRootTag(const char *tag){
	
	std::string t(tag);
	setRootTag(t);
	
}

//
// _setAsListContainer -- PROTECTED
//
void MLR::_setAsListContainer(void){
	
	if(_stack.size()==0) return;
	
	MLRItem *element = _stack.top();
	element->setAsListContainer();
	
}

//
// _isAListContainer -- PROTECTED
//
bool MLR::_isAListContainer(void){
	
	if(_stack.size()==0) return 0;
	
	MLRItem *element = _stack.top();
	
	return element->isAListContainer();
	
}


