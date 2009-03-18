//
// The Fontaine Font Analysis Project 
// 
// Copyright (c) 2009 by Edward H. Trager
// All Rights Reserved
// 
// Released under the GNU GPL version 2.0 or later.
//     


#include "OrthographyResults.h"
#include <sstream>
#include <iomanip>

//
// Constructor
//
OrthographyResults::OrthographyResults(const OrthographyData *pData,UINT32 hits, UINT32 tries,std::vector<UTF32> &missingValues){
	
	_pData = pData;
	_hits  = hits;
	_tries = tries;
	
	// Calling copy constructor:
	_missingValues = missingValues;
	
}

//
// Constructor
//
OrthographyResults::OrthographyResults(const OrthographyData *pData,UINT32 hits=0, UINT32 tries=0){
	
	_pData = pData;
	_hits  = hits;
	_tries = tries;
	
}

//
// getHits
//
UINT32 OrthographyResults::getHits(void) const{
	return _hits;
}

//
// getTries
//
UINT32 OrthographyResults::getTries(void) const{
	return _tries;
}

//
// getPercentCoverage
//
int OrthographyResults::getPercentCoverage(void) const{
	return 100*_hits/_tries;
}

//
// getSupportLevel
//
OrthographyResults::SUPPORTLEVEL OrthographyResults::getSupportLevel(void) const{
	
	if(!_hits) return UNSUPPORTED;
	if(_hits == _tries) return FULL;
	if(100*_hits/_tries<minCoverage) return FRAGMENTARY;
	else return PARTIAL;
	
}

//
// getSupportLevelAsCString
//
const char * OrthographyResults::getSupportLevelAsCString(void) const{
	
	SUPPORTLEVEL level = getSupportLevel();
	switch(level){
	case UNSUPPORTED:
		return "no";
	case FRAGMENTARY:
		return "fragmentary";
	case PARTIAL:
		return "partial";
	case FULL:
		return "full";
	}
	
	// Never get here, but this prevents compiler warnings:
	return "";
	
}


//
// getCommonName
//
const char* OrthographyResults::getCommonName(void) const{
	
	return _pData->commonName;
	
}

//
// getNativeName
//
const char* OrthographyResults::getNativeName(void) const{
	
	return _pData->nativeName;
	
}


//
// getSampleCharacters
//
const char* OrthographyResults::getSampleCharacters(void) const{
	
	return _pData->sampleCharacters;
	
}

//
// getSampleSentence
//
const char* OrthographyResults::getSampleSentence(int nth) const{
	
	// NEEDS WORK : THIS IS NOT SAFE:
	
	return _pData->sampleSentences[nth];
	
}

//
// getMissingValuesAsString
//
std::string OrthographyResults::getMissingValuesAsString(void) const{
	
	std::ostringstream ss;
	
	for(std::vector<UTF32>::const_iterator p=_missingValues.begin();p!=_missingValues.end();p++){
		
		ss << "U+" << std::hex << std::setw(4) << std::setfill('0') << (*p) << " (" << UTF32ValueToUTF8( *p ) << ")";
		
		//if(p==_missingValues.end()-1) ss << ".";
		//else                        ss << ", ";
		
		if(p!=_missingValues.end()-1) ss << ", ";
		
	}
	
	return ss.str();
	
}

//
// UTF32ValueToUTF8
//
const char *OrthographyResults::UTF32ValueToUTF8( UTF32 UTF32Value ) const{
	
	//
	// Static buffer:
	//
	static unsigned char utf8[7];
	
	unsigned int k;
	
	// Clear out utf8 array:
	for(unsigned int j=0;j<7;j++) utf8[j]=0;
		
	if (UTF32Value < 0x80){
		utf8[0] = (char) UTF32Value;
	}else if (UTF32Value < 0x800){
		k = UTF32Value & 0x3f;
		utf8[1] = 0x80 | k;
		UTF32Value >>= 6;
		k = UTF32Value & 0x1f;
		utf8[0] = 0xc0 | k;
	}else if (UTF32Value < 0x10000){
		k = UTF32Value & 0x3f;
		utf8[2] = 0x80 | k;
		UTF32Value >>= 6;
		
		k = UTF32Value & 0x3f;
		utf8[1] = 0x80 | k;
		UTF32Value >>= 6;
		
		k = UTF32Value & 0x0f;
		utf8[0] = 0xe0 | k;
	}else if (UTF32Value < 0x200000){
		k = UTF32Value & 0x3f;
		utf8[3] = 0x80 | k;
		UTF32Value >>= 6;
		
		k = UTF32Value & 0x3f;
		utf8[2] = 0x80 | k;
		UTF32Value >>= 6;
		
		k = UTF32Value & 0x3f;
		utf8[1] = 0x80 | k;
		UTF32Value >>= 6;
		
		k = UTF32Value & 0x07;
		utf8[0] = 0xf0 | k;
	}else if (UTF32Value < 0x4000000) {
		k = UTF32Value & 0x3f;
		utf8[4] = 0x80 | k;
		UTF32Value >>= 6;
		
		k = UTF32Value & 0x3f;
		utf8[3] = 0x80 | k;
		UTF32Value >>= 6;
		
		k = UTF32Value & 0x3f;
		utf8[2] = 0x80 | k;
		UTF32Value >>= 6;
		
		k = UTF32Value & 0x3f;
		utf8[1] = 0x80 | k;
		UTF32Value >>= 6;
		
		k = UTF32Value & 0x03;
		utf8[0] = 0xf8 | k;
	}else if (UTF32Value < 0x80000000) {
		k = UTF32Value & 0x3f;
		utf8[5] = 0x80 | k;
		UTF32Value >>= 6;
		
		k = UTF32Value & 0x3f;
		utf8[4] = 0x80 | k;
		UTF32Value >>= 6;
		
		k = UTF32Value & 0x3f;
		utf8[3] = 0x80 | k;
		UTF32Value >>= 6;
		
		k = UTF32Value & 0x3f;
		utf8[2] = 0x80 | k;
		UTF32Value >>= 6;
		
		k = UTF32Value & 0x3f;
		utf8[1] = 0x80 | k;
		UTF32Value >>= 6;
		
		k = UTF32Value & 0x01;
		utf8[0] = 0xfc | k;
	}
	
	return (const char *) utf8;
	
}

//
// getReport
//
std::string OrthographyResults::getReport(bool reportMissing) const{
	
	std::ostringstream ss;
	
	ss << "This font has ";
	 
	SUPPORTLEVEL level = getSupportLevel();
	switch(level){
	case UNSUPPORTED:
		ss << "NO";
		break;
	case FRAGMENTARY:
		ss << "FRAGMENTARY (" << getPercentCoverage() << "%)";
		break;
	case PARTIAL:
		ss << "PARTIAL (" << getPercentCoverage() << "%)";
		break;
	case FULL:
		ss << "FULL";
	}
	ss << " support for " << getCommonName() << " [" << getNativeName() << "]." << std::endl;
	
	if( reportMissing && getSupportLevel() != OrthographyResults::FULL ){
		
		ss << "   => Support is missing for " << getMissingValuesAsString() << std::endl;
		
	}
	
	// ss << std::endl;
	
	return ss.str();
	
}

//
// setReportOnMissing(bool)
//
void OrthographyResults::setReportOnMissing(bool x){
	
	_reportMissing = x;
	
}

