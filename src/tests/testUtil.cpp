#include <string>
#include <iostream>
#include "BasicLatinStringUtilities.h"

using namespace std;

int main(void){
	
	std::string segment = "thisIsAnExampleForSegmentation";
	std::string capital = "thisIsAnExampleForCapitalization";
	
	cout << BasicLatin::segmentize(segment) << endl;
	cout << BasicLatin::capitalize(capital) << endl;
	
	return 0;
}
