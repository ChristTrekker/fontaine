//
// The Fontaine Font Analysis Project 
// 
// Copyright (c) 2009 by Edward H. Trager
// All Rights Reserved
// 
// Released under the GNU GPL version 2.0 or later.
//     


#include "FontFace.h"

#include "Encoding.h"
#include "Utf8String.h"
#include "Exception.h"

#include FT_GLYPH_H
#include FT_TRUETYPE_TABLES_H
#include FT_TYPE1_TABLES_H

#include "orthographies/orthographies.h"
#include "licenses/licenses.h"

#include <sstream>

//
// Constructor:
//
FontFace::FontFace( FontLibrary &library, const std::string &fileName ){
	
	_fileName=fileName;
	
	//
	// By default report on fragmentary and partial orthographic
	// support in addition to fully supported orthographies:
	//
	_reportMissing     = true;
	_reportFragmentary = true;
	_reportPartial     = true;
	_reportFull        = true;
	
	FT_Error err;
	
	err = FT_New_Face(library.get(),_fileName.c_str(),0, &_face ); 
	if(err==FT_Err_Unknown_File_Format) throw Exception("FontFace()","Unknown file format.");
	else if(err) throw Exception("FontFace()","Unable to open or process font file.");
	//
	//
	//
	_commonName = _face->family_name;
	_subFamily  = _face->style_name;
	_glyphCount = _face->num_glyphs;
	
	if(FT_IS_SFNT(_face)){
		
		FT_UInt count=FT_Get_Sfnt_Name_Count(_face);
		
		FT_SfntName fontName;
		
		for(unsigned j=0;j<count;j++){
			
			FT_Get_Sfnt_Name(_face,j,&fontName);
			
			if(fontName.platform_id==3 && fontName.encoding_id==1){
				//
				// Microsoft 3:1 Platform:
				//
				if( fontName.language_id==0x0409 ){
					//
					// This is the de-facto
					// default AMERICAN ENGLISH
					// entry:
					//
					switch(fontName.name_id){
					case NID_FONT_FAMILY:
						if(_commonName.empty()) _commonName = _getPlatform3Encoding1String(fontName.string_len,fontName.string);
						break;
					case NID_FONT_SUBFAM:
						if(_subFamily.empty()) _subFamily   = _getPlatform3Encoding1String(fontName.string_len,fontName.string);
						break;
					default:
						break;
					}
				}else{
					//
					// Some other language:
					// We take whatever the very first
					// other language is to be
					// our "nativeName" string:
					//
					switch(fontName.name_id){
					case NID_FONT_FAMILY:
						if(_nativeName.empty()) _nativeName = _getPlatform3Encoding1String(fontName.string_len,fontName.string);
						break;
					default:
						break;
					}
				}
				
				//
				// DEBUG
				//
				//if(fontName.name_id==NID_COPYRIGHT){
				//	// DEBUG:
				//	std::cout << ">>> COPYRIGHT: " << _getPlatform3Encoding1String(fontName.string_len,fontName.string) << std::endl;
				//}
				//if(fontName.name_id==NID_LICENSE){
				//	// DEBUG:
				//	std::cout << ">>> LICENSE: " << _getPlatform3Encoding1String(fontName.string_len,fontName.string) << std::endl;
				//}
				
				
			}else if(fontName.platform_id==1 && fontName.encoding_id==0){
				//
				// Macintosh 1:0 platform: This is going to 
				// be English in the MacRoman encoding:
				//
				// NOTA BENE: We currently do not deal with
				// non-English Mac strings.  They seem to be 
				// very rare in real fonts out there in the world.
				//
				switch(fontName.name_id){
				case NID_FONT_FAMILY:
					if(_commonName.empty()) _commonName = _getPlatform1Encoding0String(fontName.string_len,fontName.string);
					break;
				case NID_FONT_SUBFAM:
					if(_subFamily.empty()) _subFamily   = _getPlatform1Encoding0String(fontName.string_len,fontName.string);
					break;
				default:
					break;
				}
			}
			
			
		}
	}
	
	//
	// If native name is missing, fill it in:
	//
	//if(_nativeName.empty()) _nativeName = _commonName;
	
	_style=NORMAL;
	if( _face->style_flags & FT_STYLE_FLAG_ITALIC ) _style  = ITALIC;
	_weight=NORMAL_WEIGHT;
	if( _face->style_flags & FT_STYLE_FLAG_BOLD   ) _weight = BOLD;
	_isFixedWidth=FT_IS_FIXED_WIDTH(_face);
	
	
	
	//
	// Vertical metrics for Japanese, Chinese, Mongolian:
	//
	_hasVerticalMetrics = FT_HAS_VERTICAL(_face);
	//
	// Check for embedded bitmaps:
	//
	_hasFixedSizes = FT_HAS_FIXED_SIZES(_face);
	
	//
	// Get the set of unicode values this font covers
	//
	_getUnicodeValues();
	
	//
	// Check orthographic coverage:
	//
	_checkOrthographies();
	
	//
	// Check license:
	//
	_checkLicenses();
	
}

//
//
//
FontFace::~FontFace(){
	
	FT_Done_Face(_face);
	
}

//
// _getPlatform3Encoding1String -- Private method
//
UTF8String FontFace::_getPlatform3Encoding1String( unsigned length, const FT_Byte *string) const{
	
	std::basic_string<UTF16> utf16;
	
	for(unsigned i=0;i<length;i+=2){
		
		UTF16 ch=0;
		ch=string[i];
		ch <<= 8;
		ch |= string[i+1];
		utf16.push_back( ch );
		
	}
	
	// convert to utf-8:
	return UTF8String(utf16);
	
}


//
// _getPlatform1Encoding0String -- Private method
//
UTF8String FontFace::_getPlatform1Encoding0String( unsigned length, const FT_Byte *string) const{
	
	std::basic_string<UTF32> utf32;
	
	for(unsigned i=0;i<length;i++){
		
		utf32.push_back( Encoding::macRomanToUTF32(string[i]) );
		
	}
	
	// convert to utf-8:
	return UTF8String(utf32);
	
}

//
// _getStringFromTrueTypeFont -- Currently this is a private method
//
UTF8String FontFace::_getStringFromTrueTypeFont(FT_SfntName &fontName) const{
	
	// FOR DEBUGGING:
	//std::cout << "PLATFORM ID  IS " << fontName.platform_id << std::endl;
	//std::cout << "PLATFORM ENC IS " << fontName.encoding_id << std::endl;
	
	if(fontName.platform_id==3 && fontName.encoding_id==1){
		//
		// Windows platform: This is the most commonly encountered situation:
		//
		return _getPlatform3Encoding1String(fontName.string_len,fontName.string);
	}else if(fontName.platform_id==1){
		//
		// For Apple OS X, the encoding_id theoretically 
		// represents different script codes: 0 is for Mac Roman.
		// To the extent tested, this seems to work even for non-zero encoding IDs:
		//
		return _getPlatform1Encoding0String(fontName.string_len,fontName.string);
	}else{
		
		std::ostringstream ss;
		ss << "Unsupported platform (" << fontName.platform_id << ") and id (" << fontName.encoding_id << ")!";
		return UTF8String( ss.str() );
		
	}
}

//
// getBasicReport():
//
std::string FontFace::getBasicReport(void) const{
	
	std::ostringstream ss;
	
	ss << "Common Name :" << _commonName  << std::endl;
	ss << "Native Name :" << _nativeName  << std::endl;
	ss << "Sub Family  :" << _subFamily   << std::endl;
	ss << "Has Vertical:" << _hasVerticalMetrics << std::endl;
	ss << "Style       :" << ( _style==ITALIC ? "italic":"normal" ) << std::endl;
	ss << "Weight      :" << ( _weight==BOLD ?  "bold"  :"normal" ) << std::endl;
	ss << "Fixed Width?:" << std::hex << _isFixedWidth << std::endl;
	ss << "Fixed Sizes?:" << std::hex << _hasFixedSizes << std::endl;
	ss << "Num. Glyphs :" << std::dec << _face->num_glyphs << std::endl;
	ss << "Num. Chars  :" << std::dec << _unicodeValues.size() << std::endl;
	
	return ss.str();
	
}


//
// _getUnicodeValues() covered in this font
//
unsigned int FontFace::_getUnicodeValues(void){
	
	FT_ULong  characterCode;                                              
	FT_UInt   glyphIndex;
	                                                
	characterCode = FT_Get_First_Char(_face, &glyphIndex);
	while(glyphIndex !=0 ){
		
		characterCode = FT_Get_Next_Char(_face,characterCode,&glyphIndex);
		_unicodeValues.insert(characterCode);
	}
	
	return _unicodeValues.size();
	
}


//
// _checkOrthography
//
bool FontFace::_checkOrthography( const OrthographyData *pData ){
	
	UINT32 hits=0,tries=0;
	
	std::vector<UTF32> missingValues;
	
	//
	// Spot check using "key" value first
	// to avoid wasting time:
	//
	if(!hasUnicodeValue(pData->key)) return false;
	
	//
	// Check all values in the orthography:
	//
	for(int i=0;pData->values[i];i++){
		
		if(pData->values[i]==START_RANGE_PAIR){
			
			++i;
			int stt=pData->values[i];
			++i;
			int end=pData->values[i];
			
			for(int u=stt;u<=end;u++){
				tries++;
				if(hasUnicodeValue(u)){
					hits++;
				}else{
					missingValues.push_back(u);
					// DEBUG:
					// std::cout << "MISS " << pData->commonName << " : " << std::hex << u << std::endl;
				}
			}
			
		}else{
			tries++;
			if(hasUnicodeValue(pData->values[i])){
				hits++;
			}else{
				missingValues.push_back(pData->values[i]);
				// DEBUG:
				// std::cout << "MISS " << pData->commonName << " : "  << std::hex << pData->values[i] << std::endl;
			}
		}
	}
	
	//
	// Compare hits to tries:
	//
	if(hits==tries){
		//
		// DEBUG:
		//
		//std::cout << pData->commonName << " is supported!" << std::endl;
		
		//
		// Use the constructor with no missingValues:
		//
		OrthographyResults *orth = new OrthographyResults(pData,hits,tries);
		_supportedOrthographies.push_back(orth);
		return true;
	}else{
		
		//
		// On partial support, use the constructor which also stores
		// the vector of missing values:
		// 
		OrthographyResults *orth = new OrthographyResults(pData,hits,tries,missingValues);
		_supportedOrthographies.push_back(orth);
		
		//
		// DEBUG on partial support:
		// 
		//std::cout << pData->commonName << " PARTIAL SUPPORT with " << std::dec << hits << " hits on " << tries << " tries." << std::endl;
		
	}
	
	return false;
	
}

//
// _checkOrthographies
//
void FontFace::_checkOrthographies(void){
	
	//
	// Latin:
	//
	if( _checkOrthography( BasicLatin::pData ) ){
		_checkOrthography(WesternEuropean::pData);
		_checkOrthography(Euro::pData);
		_checkOrthography(Catalan::pData);
		_checkOrthography(Baltic::pData);
		_checkOrthography(Turkish::pData);
		_checkOrthography(CentralEuropean::pData);
		_checkOrthography(Romanian::pData);
		_checkOrthography(Vietnamese::pData);
		_checkOrthography(PanAfricanLatin::pData); 
		_checkOrthography(Dutch::pData);
		_checkOrthography(Afrikaans::pData);
		_checkOrthography(Pinyin::pData);
		_checkOrthography(IPA::pData);
		_checkOrthography(LatinLigatures::pData);
		_checkOrthography(ClaudianLetters::pData);
	}
	
	// GREEK:
	if( _checkOrthography(BasicGreek::pData) ){
		_checkOrthography(PolytonicGreek::pData);
		_checkOrthography(ArchaicGreekLetters::pData);
	}
	
	// COPTIC:
	_checkOrthography(Coptic::pData);
	
	// CYRILLIC:
	_checkOrthography(BasicCyrillic::pData);
	
	//
	// Arabic:
	//
	if(_checkOrthography(Arabic::pData)){
		_checkOrthography(Farsi::pData);
		_checkOrthography(Urdu::pData);
		_checkOrthography(Kazakh::pData);
		_checkOrthography(Pashto::pData);
		_checkOrthography(Sindhi::pData);
		_checkOrthography(Uighur::pData);
	}
	
	//
	// CJK:
	//
	//
	// Spot check using the character zhong1 "middle"
	// which is used in Chinese, Japanese, and even still sometimes
	// used in Korean newspapers:
	//
	if(hasUnicodeValue(0x4e2d)){
	
		//
		// Chinese:
		//
		_checkOrthography(SimplifiedChinese::pData);
		_checkOrthography(TraditionalChinese::pData);
		_checkOrthography(HongKongSupplementaryCharacterSet::pData);
		_checkOrthography(ZhuYinFuHao::pData);
		
		//
		// Japanese: Spot check using kana and Kokuji spots:
		//
		// => Using 0x3059 "SU" for Kana spot
		// => Using 0x5ce0 "toge" mountain pass Kokuji
		//
		if(hasUnicodeValue(0x3059) && hasUnicodeValue(0x5ce0)){
			
			_checkOrthography(Kana::pData    );
			_checkOrthography(Joyo::pData    );
			_checkOrthography(Jinmeiyo::pData);
			_checkOrthography(Kokuji::pData  );
		}
		
	}
	//
	// Korean:
	//
	
	
	//
	// The Rest:
	//
	_checkOrthography(Armenian::pData);
	_checkOrthography(Hebrew::pData);
	_checkOrthography(Syriac::pData);
	_checkOrthography(Thaana::pData);
	_checkOrthography(Thai::pData);
	_checkOrthography(Lao::pData);
	_checkOrthography(Tibetan::pData);
	_checkOrthography(Myanmar::pData);
	_checkOrthography(Georgian::pData);
	_checkOrthography(Cherokee::pData);
	_checkOrthography(CanadianSyllabics::pData);
	_checkOrthography(Ogham::pData);
	_checkOrthography(Runic::pData);
	_checkOrthography(Khmer::pData);
	_checkOrthography(Yi::pData);
	_checkOrthography(Hangul::pData);
	
	//
	// Symbols -- Divide Unicode blocks
	// into meaningful groups such as "chess symbols"
	// as necessary.
	//
	_checkOrthography(MathematicalOperators::pData);
	_checkOrthography(ChessSymbols::pData);
	
	//
	// Indic:
	//
	_checkOrthography(Bengali::pData);
	_checkOrthography(Devanagari::pData);
	_checkOrthography(Kannada::pData);
	_checkOrthography(Tamil::pData);
	_checkOrthography(Sinhala::pData);
	_checkOrthography(Telugu::pData);
	_checkOrthography(Malayalam::pData);
	_checkOrthography(Gujarati::pData);
	_checkOrthography(Gurmukhi::pData);
	_checkOrthography(Oriya::pData);
	
	//
	// Philippine scripts
	//
	_checkOrthography(Hanunoo::pData);
	
	//
	// African scripts
	//
	_checkOrthography(Nko::pData);
	_checkOrthography(Osmanya::pData);
	_checkOrthography(Tifinagh::pData);
	_checkOrthography(Vai::pData);
	
}

//
// hasUnicodeValue
//
bool FontFace::hasUnicodeValue( UTF32 v ) const {
	
	std::set<UTF32>::iterator p;
	
	p = _unicodeValues.find(v);
	
	return ( p != _unicodeValues.end() );
	
}

//
// getOrthographyReport
//
std::string FontFace::getOrthographyReport(void) const{
	
	std::ostringstream ss;
	
	std::vector< const OrthographyResults * >::const_iterator p;
	for(p=_supportedOrthographies.begin();p!=_supportedOrthographies.end();p++){
		
		OrthographyResults::SUPPORTLEVEL supportLevel = (*p)->getSupportLevel();
		if( supportLevel==OrthographyResults::FRAGMENTARY && _reportFragmentary ||
		    supportLevel==OrthographyResults::PARTIAL     && _reportPartial     ||
		    supportLevel==OrthographyResults::FULL        && _reportFull
		){
			
			ss << (*p)->getReport( _reportMissing );
			
		}
		
	}
	
	return ss.str();
	
}



//
// _checkLicenses();
//
void FontFace::_checkLicenses(void){
	
	//
	// Assign the default:
	//
	_licenseData = UnknownLicense::pData;
	
	std::string licenseString;
	
	///////////////////////////////////////
	//
	// Handle both (1) TrueType/OpenType
	//         and (2) Type1 fonts
	//
	///////////////////////////////////////
	if(FT_IS_SFNT(_face)){
		
		///////////////////////////////
		//
		// TrueType / OpenType CASE:
		//
		///////////////////////////////
		
		FT_UInt count=FT_Get_Sfnt_Name_Count(_face);
		
		FT_SfntName fontName;
		
		//
		// Check both the COPYRIGHT (TTF) and LICENSE (OPENTYPE) fields:
		//
		for(unsigned j=0;j<count;j++){
			
			FT_Get_Sfnt_Name(_face,j,&fontName);
			if(fontName.name_id==NID_LICENSE || fontName.name_id==NID_COPYRIGHT){
				
				licenseString = _getStringFromTrueTypeFont(fontName);
				
				if(fontName.name_id==NID_COPYRIGHT){
					_storeCopyrightSummary(licenseString);
				}
				
				if(_checkAllKnownLicenses(licenseString)){
					
					return;
					
				}
			}
			
			if(fontName.name_id==NID_URL_LICENSE){
				
				_licenseURL = _getStringFromTrueTypeFont(fontName);
				
			}
		}
		
		//
		// Get here if not a known license string:
		//
		
	}else if(FT_IS_SCALABLE(_face)){
		
		///////////////////////////////
		//
		// Could be Type 1, Type 42, 
		// CID, or PFR CASES:
		//
		///////////////////////////////
		
		PS_FontInfoRec fi;
		FT_Get_PS_Font_Info(_face,&fi);
		
		if(fi.notice){
			licenseString = fi.notice;
			_checkAllKnownLicenses(licenseString);
			_storeCopyrightSummary(licenseString);
		}
		
	}
	
	
}

//
// _storeCopyrightSummary
//
void FontFace::_storeCopyrightSummary(const std::string &copyrightString){
	if(copyrightString.length()){
		UTF8String utf8(copyrightString);
		_copyright = (std::string) utf8.unicodeSubStringOnWordBoundary(1,COPYRIGHT_SUMMARY_STRING_LENGTH);
		if(utf8.length() >COPYRIGHT_SUMMARY_STRING_LENGTH){
			_copyright += " ...";
		}
	}
}

//
// _checkAllKnownLicenses
//
bool FontFace::_checkAllKnownLicenses( const std::string &licenseString){
	
	//
	// First check for the most common Open/Libre font licenses:
	//
	if( _checkLicense(licenseString,OpenFontLicense::pData)) return true;
	//
	// For GPL, we need to distinguish the "GPL with Font Exception" sub category:
	//
	if( _checkLicense(licenseString,GPL::pData)){
		if( _checkLicense(licenseString,GPLWithFontException::pData)) return true;
		if( _checkLicense(licenseString,LGPL::pData)) return true;
	}
	
	//
	// Historical licenses for fonts from specific vendors / projects / organisations:
	//
	if( _checkLicense(licenseString,BitstreamVeraLicense::pData)) return true;
	if( _checkLicense(licenseString,ArphicPublicLicense::pData)) return true;
	if( _checkLicense(licenseString,MagentaOpenLicense::pData)) return true;
	if( _checkLicense(licenseString,AladdinFreePublicLicense::pData)) return true;
	if( _checkLicense(licenseString,IPALicense::pData)) return true;
	if( _checkLicense(licenseString,UtopiaLicense::pData)) return true;
	if( _checkLicense(licenseString,STIXLicense::pData)) return true;
	if( _checkLicense(licenseString,MITLicense::pData)) return true;
	if( _checkLicense(licenseString,MPLUSLicense::pData)) return true;
	if( _checkLicense(licenseString,GUSTLicense::pData)) return true;
	if( _checkLicense(licenseString,XFree86License::pData)) return true;
	
	//
	// Licenses which --subject to debate-- aren't really true 
	// licenses at all:
	//
	if( _checkLicense(licenseString,Freeware::pData)) return true;
	if( _checkLicense(licenseString,PublicDomain::pData)) return true;
	
	return false;
	
}

//
// _checkLicense
//
bool FontFace::_checkLicense( const std::string &teststr, const LicenseData *pData){
	
	for(const char **key=pData->searchKeys;*key;key++){
		if(strcasestr(teststr.c_str(),*key)){
			_licenseData = pData;
			return true;
		}
	}
	return false;
	
}

//
// setReportOnMissing
//
void FontFace::setReportOnMissing(bool x){
	_reportMissing = x;
}

//
// setReportOnFragmentary
//
void FontFace::setReportOnFragmentary(bool x){
	_reportFragmentary = x;
}

//
// setReportOnPartial
//
void FontFace::setReportOnPartial(bool x){
	_reportPartial = x;
}

//
// setReportOnFull
//
void FontFace::setReportOnFull(bool x){
	_reportFull = x;
}

//
// getFileName
//
const std::string & FontFace::getFileName(void) const{
	
	return _fileName;
	
}

//
// getCommonName
//
const std::string & FontFace::getCommonName(void) const{
	
	return _commonName;
	
}

//
// getNativeName
//
const std::string & FontFace::getNativeName(void) const{
	
	return _nativeName;
	
}

//
// getSubFamily
//
const std::string & FontFace::getSubFamily(void) const{
	
	return _subFamily;
	
}

//
// getLicenseReport
//
std::string FontFace::getLicenseReport(void) const{
	
	std::ostringstream ss;
	
	ss << "LICENSE: " << _licenseData->name;
	if(_licenseData->url[0]){
		ss << " (" << _licenseData->url << ")";
	}
	
	ss << std::endl;
	
	return ss.str();
	
}

//
// getCopyright
//
const std::string & FontFace::getCopyright(void) const{
	
	return _copyright;
	
}

//
// getGlyphCount
//
unsigned FontFace::getGlyphCount(void) const{
	
	return _glyphCount;
	
}

//
// getCharacterCount
//
unsigned FontFace::getCharacterCount(void) const{
	
	return _unicodeValues.size();
	
}

//
// getFamily
//
FontFace::FAMILY  FontFace::getFamily(void) const{
	
	return _genericFamily;
	
}

//
// getStyle
//
FontFace::STYLE   FontFace::getStyle(void)  const{
	
	return _style;
	
}

//
// getVariant
//
FontFace::VARIANT FontFace::getVariant(void) const{
	
	return _variant;
	
}

//
// getWeight
//
FontFace::WEIGHT  FontFace::getWeight(void) const{
	
	return _weight;
	
}

//
// getStroke
//
FontFace::STROKE  FontFace::getStroke(void) const{
	
	return _stroke;
	
}

//
// hasVerticalMetrics
//
bool    FontFace::hasVerticalMetrics(void) const{
	
	return _hasVerticalMetrics;
	
}

//
// isFixedWidth
//
bool    FontFace::isFixedWidth(void) const{
	
	return _isFixedWidth;
	
}

//
// hasFixedSizes
//
bool    FontFace::hasFixedSizes(void) const{
	
	return _hasFixedSizes;
	
}

//
// fillReport():
//
void FontFace::fillReport(MLR *mlr){
	
	
	std::ostringstream s1,s2;
	
	mlr->start("font");
	 mlr->addKeyValuePair("commonName",_commonName);
	 mlr->addKeyValuePair("nativeName",_nativeName);
	 mlr->addKeyValuePair("subFamily" ,_subFamily );
	 mlr->addKeyValuePair("style"     , _style==ITALIC ? "italic":"normal" );
	 mlr->addKeyValuePair("weight"    , _weight==BOLD  ?  "bold"  :"normal" );
	 mlr->addKeyValuePair("fixedWidth", _isFixedWidth  ? "yes":"no" );
	 mlr->addKeyValuePair("fixedSizes", _hasFixedSizes ? "yes":"no" );
	 mlr->addKeyValuePair("copyright" , _copyright );
	 mlr->addKeyValuePair("license"   , _licenseData->name);
	 
	 if(_licenseURL.length()){
		mlr->addKeyValuePair("licenseUrl",_licenseURL);
	}else if(_licenseData->url[0]){
		mlr->addKeyValuePair("licenseUrl",_licenseData->url);
	}
	 
	 s1 << std::dec << _glyphCount;
	 mlr->addKeyValuePair("glyphCount",s1.str());
	 
	 s2 << std::dec << _unicodeValues.size();
	 mlr->addKeyValuePair("characterCount",s2.str());
	
	 ////////////////////////////////////////
	 //
	 // STT iteration over the orthographies:
	 //
	 ////////////////////////////////////////
	mlr->startList("orthographies");
	
	std::vector< const OrthographyResults * >::const_iterator p;
	for(p=_supportedOrthographies.begin();p!=_supportedOrthographies.end();p++){
		
		OrthographyResults::SUPPORTLEVEL supportLevel = (*p)->getSupportLevel();
		if( supportLevel==OrthographyResults::FRAGMENTARY && _reportFragmentary ||
		    supportLevel==OrthographyResults::PARTIAL     && _reportPartial     ||
		    supportLevel==OrthographyResults::FULL        && _reportFull
		){
			
			mlr->start("orthography");
			
			 mlr->addKeyValuePair("commonName"  ,(*p)->getCommonName()            );
			 mlr->addKeyValuePair("nativeName"  ,(*p)->getNativeName()            );
			 mlr->addKeyValuePair("supportLevel",(*p)->getSupportLevelAsCString() );
			 if( supportLevel==OrthographyResults::FRAGMENTARY ||
			     supportLevel==OrthographyResults::PARTIAL 
			 ){
				
				std::ostringstream ss;
				ss << (*p)->getPercentCoverage();
				mlr->addKeyValuePair("percentCoverage",ss.str());
				
			 }
			        
			 if( _reportMissing && 
			     (
			       supportLevel==OrthographyResults::FRAGMENTARY ||
			       supportLevel==OrthographyResults::PARTIAL 
			     )
			 ){
				     
				mlr->addKeyValuePair("missingValues",(*p)->getMissingValuesAsString());
				
			 }
			 
			mlr->end("orthography");
			
		}
		
	}
	
	mlr->endList("orthographies");
	 ////////////////////////////////////////
	 //
	 // END iteration over the orthographies
	 //
	 ////////////////////////////////////////
	  
	mlr->end("font");
	
}

