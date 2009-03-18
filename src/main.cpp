//
// Fontaine
//
//
// (c) 2009 by Edward H. Trager <ed.trager@gmail.com>
// All Rights Reserved.
// Released under GPL v. 2.0 or later.
//

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <set>
#include <vector>
#include "Utf8String.h"
#include "FontLibrary.h"
#include "FontFace.h"
#include "CLP.h"          // Command line processor
#include "Warning.h"
#include "Message.h"

//
// For reporting:
//
#include "MLR.h"
#include "XMLR.h"
#include "JSONR.h"
#include "TEXTR.h"
#include "XHTMLR.h"
#include "FXHTMLR.h"


//
// MAIN
//
int main(int argc, const char *argv[]){
	
	//
	// Command line processor:
	//
	CLP clp("Fontaine","1.0 alpha",L("Copyright ⓒ 2009 by Edward H. Trager. All Rights Reserved. Released under GPL v. 2 or later."),"http://www.unifont.org","fontaine [option]... [font file]...\n");
	
	//
	// Set up command line switches:
	//
	
	clp.addSwitch("--json"            , "-J" , "Produce output report in JSON format. (default)");
	clp.addSwitch("--text"            , "-T" , "Produce output report in plain text format.");
	clp.addSwitch("--xhtml"           , "-H" , "Produce output report in XHTML format.");
	clp.addSwitch("--fxhtml"          , "-Y" , "Produce output report in FANCY XHTML format.");
	clp.addSwitch("--xml"             , "-X" , "Produce output report in XML format.");
	clp.addSwitch("--show-missing"    , "-M" , "Report which Unicode values are missing from fragmentary and partially-supported orthographies. (default)");
	clp.addSwitch("--show-fragmentary", "-R" , "Report orthographies for which the font provides only fragmentary support.");
	clp.addSwitch("--show-partial"    , "-P" , "Report orthographies for which the font provides only partial support");
	clp.addSwitch("--show-full"       , "-F" , "Report orthographies for which the font provides full support");
	clp.addSwitch("--hide-missing"    , "-m" , "Don't report which Unicode values are missing from fragmentary and partially-supported orthographies.");
	clp.addSwitch("--hide-fragmentary", "-r" , "Don't report orthographies for which the font provides only fragmentary support.");
	clp.addSwitch("--hide-partial"    , "-p" , "Don't report orthographies for which the font provides only partial support");
	clp.addSwitch("--hide-full"       , "-f" , "Don't report orthographies for which the font provides full support");
	clp.addSwitch("--version"         , "-v" , "Print version and exit");
	clp.addSwitch("--help"            , "-h" , "Print help and exit");
	
	//
	// Parse command line arguments:
	//
	if(clp.parse(argc,argv)){
	
		// No error, process the switches
		if(clp.hasSwitchSet("--help")){
			clp.printHelp();
			return 0;
		}
		if(clp.hasSwitchSet("--version")){
			
			clp.printCopyrightNotice();
			return 0;
			
		}
		
		////////////////////
		//
		// MAIN PROCESSING:
		//
		////////////////////
		
		//
		// These are the arguments left over after stripping off command line arguments:
		//
		std::vector<std::string> arguments = clp.getArguments();
		
		FontLibrary myLibrary;
		
		////////////////////////////////////////////////////////////
		//
		// The report object:
		//
		// Can only have one report, so we only instantiate the first
		// one ...
		//
		////////////////////////////////////////////////////////////
		
		MLR *mlr;
		unsigned int reportCount=0;
		
		if      (clp.hasSwitchSet("--text" ) ) mlr = new TEXTR();
		else if (clp.hasSwitchSet("--xhtml") ) mlr = new XHTMLR();
		else if (clp.hasSwitchSet("--fxhtml")) mlr = new FXHTMLR();
		else if (clp.hasSwitchSet("--xml"  ) ) mlr = new XMLR();
		else {
			//
			// Always maintain JSON as the last option
			// so that it will be the default option as well:
			//
			// if (clp.hasSwitchSet("--json" ) ) ...
			//
			mlr = new JSONR();
			
		}
		
		mlr->startRoot();
		mlr->startList("fonts");
		//
		// Read font disk files:
		//
		for(unsigned i=0;i<arguments.size();i++){
			
			//
			// instantiate a FontFace object using the font file name:
			//
			FontFace myFace(myLibrary,arguments[i].c_str());
			
			//
			// The options are currently set in the FontFace object --
			// -- this could change to a more elegant design in the future ...
			//
			if      (clp.hasSwitchSet("--show-missing")) myFace.setReportOnMissing(true);
			else if (clp.hasSwitchSet("--hide-missing")) myFace.setReportOnMissing(false);
			
			if      (clp.hasSwitchSet("--show-fragmentary")) myFace.setReportOnFragmentary(true);
			else if (clp.hasSwitchSet("--hide-fragmentary")) myFace.setReportOnFragmentary(false);
			
			if      (clp.hasSwitchSet("--show-partial")) myFace.setReportOnPartial(true);
			else if (clp.hasSwitchSet("--hide-partial")) myFace.setReportOnPartial(false);
			
			if      (clp.hasSwitchSet("--show-full")) myFace.setReportOnFull(true);
			else if (clp.hasSwitchSet("--hide-full")) myFace.setReportOnFull(false);
			
			//
			// non-const method that calls methods 
			// on mlr to prepare the report:
			//
			myFace.fillReport(mlr);
			
		}
		
		mlr->endList("fonts");
		mlr->endRoot();
		
		//
		// Print the report:
		//
		std::cout << mlr->getReport();
		
		delete mlr;
	}
	
	return 0;
	
}

