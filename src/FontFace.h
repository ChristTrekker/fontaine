//
// The Fontaine Font Analysis Project 
// 
// Copyright (c) 2009 by Edward H. Trager
// All Rights Reserved
// 
// Released under the GNU GPL version 2.0 or later.
//     


#ifndef FONTFACE_INCLUDED
#define FONTFACE_INCLUDED

#include <string>
#include <set>
#include <vector>

#include <ft2build.h>  
#include FT_FREETYPE_H
#include FT_SFNT_NAMES_H

#include "Utf8String.h"
#include "FontLibrary.h"
#include "OrthographyResults.h"
#include "LicenseData.h"

//
// Needed by the non-const fillReport() method:
//
#include "MLR.h"

//
// This class contains information
// about a single font file:
// 
class FontFace{
	
public:
	
	//
	// FontFaces are distinguished uniquely by 
	// using commonName + subFamily as the key:
	// 
	struct compare{
		bool operator()(const FontFace *f1,const FontFace *f2) const{
			std::string t1, t2;
			t1 =  f1->_commonName;
			t1 += f1->_subFamily ;
			t2 =  f2->_commonName;
			t2 += f2->_subFamily ;
			return t1 < t2;
		}
	};
	
	//
	// The following enums generally follow the W3C CSS Standard (http://www.w3.org/TR/REC-CSS1):
	//
	enum FAMILY  { SERIF, SANS, CURSIVE, FANTASY, MONOSPACE };
	enum STYLE   { NORMAL, ITALIC, OBLIQUE };
	enum VARIANT { NORMAL_VARIANT, SMALL_CAPS };
	// 
	enum WEIGHT  { NORMAL_WEIGHT, BOLD, W100, W200, W300, W400, W500, W600, W700, W800, W900 };
	//
	// As the common labels "serif" and "sans" are primarily applicable in typography in the
	// Western world, the following enum provides a generalization that is applicable across
	// all scripts:
	// 
	enum STROKE { UNMODULATED, SEMIMODULATED, MODULATED };
	
	enum NAMEID { 
		NID_COPYRIGHT   =0, 
		NID_FONT_FAMILY =1,
		NID_FONT_SUBFAM =2,
		NID_UNIQUE_ID   =3,
		NID_FULL_NAME   =4,
		NID_VERSION     =5,
		NID_POSTSCRIPT  =6,
		NID_TRADEMARK   =7,
		NID_VENDOR      =8,
		NID_DESIGNER    =9,
		NID_DESCRIPTION =10,
		NID_URL_VENDOR  =11,
		NID_URL_DESIGNER=12,
		NID_LICENSE     =13,
		NID_URL_LICENSE =14,
		NID_RESERVED    =15,
		NID_PREF_NAME   =16,
		NID_PREF_SUBFAM =17,
		NID_MAC_FULLNAME=18,
		NID_SAMPLETEXT  =19,
		NID_FINDFONT_NM =20,
	};
	
private:
	
	FT_Face _face;
	
	std::string _fileName;
	std::string _commonName; // The English or common Font Family name. e.g. "HanWangKaiMediumPoIn1"
	std::string _nativeName; // The native Font Family name, e.g. "漢宗中楷體破音一"
	std::string _subFamily;  // As given in the English or common subFamily record.
	
	std::string _copyright; 
	
	std::string _licenseURL; // 2009.07.16.ET addendum
	
	unsigned _glyphCount;    // Number of glyphs
	
	FAMILY  _genericFamily;
	STYLE   _style;
	VARIANT _variant;
	WEIGHT  _weight;
	STROKE  _stroke;
	
	//
	// Supported Orthographies
	//
	std::vector< const OrthographyResults * > _supportedOrthographies;
	
	//
	// License:
	//
	const LicenseData *_licenseData;
	
	bool _hasVerticalMetrics;
	bool _isFixedWidth;
	bool _hasFixedSizes;
	
	std::set<UTF32> _unicodeValues;
	
	UTF8String _getPlatform3Encoding1String( unsigned length, const FT_Byte *string) const;
	UTF8String _getPlatform1Encoding0String( unsigned length, const FT_Byte *string) const;
	UTF8String _getStringFromTrueTypeFont(FT_SfntName &fontName) const;
	
	unsigned int _getUnicodeValues(void);
	
	//
	// Reporting option state flags:
	//
	bool _reportMissing;
	bool _reportFragmentary;
	bool _reportPartial;
	bool _reportFull;
	
public:
	
	//
	// Constructor:
	//
	FontFace( FontLibrary &library, const std::string &fileName );
	
	//
	// Destructor:
	//
	~FontFace();
	
	//
	// hasUnicodeValue()
	//
	bool hasUnicodeValue(UTF32) const;
	
	//
	// getters for reports:
	//
	std::string getBasicReport(void) const;
	std::string getOrthographyReport(void) const;
	
	//
	// Reporting options:
	//
	void setReportOnMissing(bool x);
	void setReportOnFragmentary(bool x);
	void setReportOnPartial(bool x);
	void setReportOnFull(bool x);
	
private:
	
	bool _checkOrthography( const OrthographyData *pData );
	void _checkOrthographies(void);
	
	bool _checkLicense( const std::string &test, const LicenseData *pData);
	bool _checkAllKnownLicenses( const std::string &licenseString);
	void _storeCopyrightSummary(const std::string &copyrightString);
	void _checkLicenses(void);
	
public:
	
	//
	// getters:
	//
	const std::string & getFileName(void) const;
	const std::string & getCommonName(void) const;
	const std::string & getNativeName(void) const;
	const std::string & getSubFamily(void) const;
	
	std::string getLicenseReport(void) const;
	const std::string & getCopyright(void) const;
	
	unsigned getGlyphCount(void) const;
	unsigned getCharacterCount(void) const;
	FAMILY  getFamily(void)  const;
	STYLE   getStyle(void)   const;
	VARIANT getVariant(void) const;
	WEIGHT  getWeight(void)  const;
	STROKE  getStroke(void)  const;
	bool    hasVerticalMetrics(void) const;
	bool    isFixedWidth(void) const;
	bool    hasFixedSizes(void) const;
	
	//
	// Pass in a report object, mlr, 
	// and fill in the report:
	//
	void fillReport(MLR *mlr);
	
};

#endif
