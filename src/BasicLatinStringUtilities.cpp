//
// BasicLatinStringUtilities.cpp
//

#include "BasicLatinStringUtilities.h"


namespace BasicLatin{

//
// capitalize
//
std::string & capitalize(std::string &s){
	
	std::string::iterator it(s.begin());
	
	if(it != s.end()){
		*it = toupper((unsigned char) *it);
	}
	
	while(++it != s.end()){
		
		*it = tolower((unsigned char)*it);
		
	}
	
	return s;
	
}

//
// segmentize : changes "thisIsAnExample" into "This is an example
//
std::string & segmentize(std::string &s){
	
	std::string::iterator it(s.begin());
	
	if(it != s.end()){
		*it = toupper((unsigned char) *it);
	}
	
	while(++it != s.end()){
		
		if( isupper(*it)){
			
			*it = tolower((unsigned char)*it);
			it = s.insert(it,' ');
			it++;
		}
		
	}
	
	return s;
	
}

//
// toUpperCase
//
std::string & toUpperCase(std::string &s){
	
	std::string::iterator it(s.begin());
	
	for(;it != s.end();it++){
		
		*it = toupper((unsigned char)*it);
		
	}
	
	return s;
	
}

//
// escapeASCIIDoubleQuote : changes "He said, "Hello!"" into "He said, \"Hello!\""
//
std::string & escapeASCIIDoubleQuote(std::string &s){
	
	std::string::iterator it(s.begin());
	
	for(;it != s.end();it++){
		
		if( *it == '"' ){
			
			it = s.insert(it,(unsigned char) 0x005C);
			it++;
			
		}
	}
	
	return s;
	
}



} // end namespace


