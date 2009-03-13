//
// testing
//

#include <iostream>

///////////////////////
//
// Latin Orthographies
//
///////////////////////

#include "BasicLatin.h"
#include "WesternEuropean.h"
#include "Euro.h"
#include "Catalan.h"
#include "Baltic.h"
#include "Turkish.h"
#include "CentralEuropean.h"
#include "Romanian.h"
#include "Vietnamese.h"
#include "Dutch.h"
#include "Afrikaans.h"
#include "Pinyin.h"
#include "IPA.h"
#include "LatinLigatures.h"
#include "ClaudianLetters.h"

//////////////////////
//
// NON LATIN
//
//////////////////////

//
// Japanese subsets:
//
#include "Kokuji.h"    // National characters
#include "Joyo.h"      // Standard education set
#include "Jinmeiyo.h"  // Person and place name set

//
// Chinese subsets
//
#include "SimplifiedChinese.h"  // Top 3500 simplified
#include "TraditionalChinese.h" // Top 3500 traditional
#include "HKSCS.h"              // Hong Kong supplementary plane set


using namespace std;

void foo(const OrthographyData *);

int main(int argc, const char *argv[]){
	
	//
	// Latin:
	//
	foo(BasicLatin::pData);
	foo(WesternEuropean::pData);
	foo(Euro::pData);
	foo(Catalan::pData);
	foo(Baltic::pData);
	foo(Turkish::pData);
	foo(CentralEuropean::pData);
	foo(Romanian::pData);
	foo(Vietnamese::pData);
	foo(Dutch::pData);
	foo(Afrikaans::pData);
	foo(Pinyin::pData);
	foo(IPA::pData);
	foo(LatinLigatures::pData);
	foo(ClaudianLetters::pData);
	
	//
	// Japanese:
	//
	foo(Kokuji::pData);
	foo(Joyo::pData);
	foo(Jinmeiyo::pData);
	
	//
	// Chinese:
	//
	foo(SimplifiedChinese::pData);
	foo(TraditionalChinese::pData);
	foo(HongKongSupplementaryCharacterSet::pData);
	
	return 0;
	
}

//
// foo
//
void foo(const OrthographyData *p){
	
	cout << p->commonName << endl;
	cout << p->nativeName << endl;
	cout << "Key is " << p->key << endl;
	cout << "Values are:" << endl;
	
	for(int i=0;p->values[i];i++){
		
		if(p->values[i]==START_RANGE_PAIR){
			
			++i;
			int stt=p->values[i];
			++i;
			int end=p->values[i];
			
			cout << "STT RANGE" << endl;
			for(int u=stt;u<=end;u++){
				cout << "R:" << std::hex << u << endl;
			}
			
			cout << "END RANGE" << endl;
			
		}else{
			cout << i << ". " << std::hex << p->values[i] << endl;
		}
	}
	
	cout << "SAMPLE CHARS: " << p->sampleCharacters << endl;
	
	cout << "SAMPLE SENTENCES: " << endl;
	for(int i=0;p->sampleSentences[i];i++){
		
		cout << p->sampleSentences[i] << endl;
		
	}
	
}
