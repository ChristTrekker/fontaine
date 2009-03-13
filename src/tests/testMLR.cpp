#include <iostream>
#include "XMLR.h"
#include "JSONR.h"
#include "TEXTR.h"
#include "XHTMLR.h"

int main(int argc,const char *argv[]){
	
	if(argc<2){
		std::cerr << "Specify an argument X (xml), J (json), T (text), or H (xHtml)" << std::endl;
		return 1;
	}
	
	// Markup Language Report -- Base class
	MLR *mlr;
	
	std::string type(argv[1]);
	if(type=="J"){
		mlr = new JSONR();
	}else if(type=="X"){
		mlr = new XMLR();
	}else if(type=="T"){
		mlr = new TEXTR();
	}else if(type=="H"){
		mlr = new XHTMLR();
	}
	
	mlr->startRoot();
	mlr->start("book");
	 mlr->addKeyValuePair("author","Charles Darwin");
	 mlr->addKeyValuePair("title","Origin of the Species");
	 mlr->start("libraries");
	  mlr->addKeyValuePair("library","Smithsonian");
	  mlr->addKeyValuePair("library","Library of Congress");
	  mlr->start("library");
	   mlr->addKeyValuePair("name","University of Michigan Library");
	   mlr->addKeyValuePair("street","State Street");
	   mlr->addKeyValuePair("city","Ann Arbor");
	   mlr->addKeyValuePair("state","Michigan");
	  mlr->end("library");
	  mlr->addKeyValuePair("library","New York Public Library");
	  mlr->addKeyValuePair("library","Ann Arbor District Library");
	  mlr->addKeyValuePair("library","Washtenaw Community College Library");
	 mlr->end("libraries");
	 mlr->addKeyValuePair("ISBN","123456789-1234");
	 mlr->startList("editions");
	  mlr->addKeyValuePairToList("edition","1876");
	  mlr->addKeyValuePairToList("edition","1881");
	  mlr->addKeyValuePairToList("edition","1893");
	  mlr->addKeyValuePairToList("edition","1907");
	 mlr->endList("editions");
	 mlr->addKeyValuePair("publisher","Tuttle Publishers");
	mlr->end("book");
	mlr->endRoot();
	
	std::cout << mlr->getReport() << std::endl;
	
	delete mlr;
	
	return 0;
	
}

