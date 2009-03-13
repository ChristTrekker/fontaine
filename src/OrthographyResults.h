//
// The Fontaine Font Analysis Project 
// 
// Copyright (c) 2009 by Edward H. Trager
// All Rights Reserved
// 
// Released under the GNU GPL version 2.0 or later.
//     


//
// OrthographyAnalysis
//
#ifndef ORTHOGRAPHY_RESULTS
#define ORTHOGRAPHY_RESULTS

#include <string>
#include <set>
#include <vector>

#include "OrthographyData.h"

#include "Utf8String.h"
#include <string.h>

class OrthographyResults{
	
public:
	
	enum SUPPORTLEVEL { UNSUPPORTED=0, FRAGMENTARY, PARTIAL, FULL };
	//
	// Minimum allowable coverage to be considered
	// as having "partial support":
	// 
	const static int minCoverage=80;
	
	//
	// Comparison Functor:
	//
	struct compare{
		bool operator()(const OrthographyResults *o1,const OrthographyResults *o2) const{
			
			return strcmp(o1->_pData->commonName,o2->_pData->commonName) < 0;
			
		}
	};
	
private:
	
	const OrthographyData *_pData;
	
	UINT32 _hits;
	UINT32 _tries;
	SUPPORTLEVEL _supportLevel;
	
	std::vector<UTF32> _missingValues;
	
	// Report missing state flag:
	bool _reportMissing;
	
public:
	
	//
	// Constructors:
	//
	OrthographyResults(const OrthographyData *pData,UINT32 hits,UINT32 tries,std::vector<UTF32> &missing);
	OrthographyResults(const OrthographyData *pData,UINT32 hits, UINT32 tries);
	
	//
	// Destructor
	//
	~OrthographyResults();
	
	UINT32 getHits(void) const;
	UINT32 getTries(void) const;
	int getPercentCoverage(void) const;
	SUPPORTLEVEL getSupportLevel(void) const;
	const char * getSupportLevelAsCString(void) const;
	const char* getCommonName(void) const;
	const char* getNativeName(void) const;
	const char* getSampleCharacters(void) const;
	const char* getSampleSentence(int nth) const;
	std::string getMissingValuesAsString(void) const;
	
	std::string getReport(bool reportMissing) const;
	
	void setReportOnMissing(bool x);
	
private:
	
	const char* UTF32ValueToUTF8( UTF32 UTF32Value ) const;
	
};

#endif
