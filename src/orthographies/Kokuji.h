//
// The Fontaine Font Analysis Project 
// 
// Copyright (c) 2009 by Edward H. Trager
// All Rights Reserved
// 
// Released under the GNU GPL version 2.0 or later.
//     


//
// Kokuji.h
//

#ifndef ORTHOGRAPHY_DATA
#include "../OrthographyData.h"
#endif

#ifndef KOKUJI
#define KOKUJI

namespace Kokuji{

//
//  国字 Unicode values
// 
// Based on a partial list presented at
// http://www.sljfaq.org/afaq/kokuji-list.html
// Updated 2011.04.19.ET.
// This list should still be quite helpful in identifying
// a truly Japanese font from a Chinese font ... maybe!
//
UINT32 values[]={
		// UTF8         JIS VALUE
	0x4FE3,	// 俣 	4B73 
	0x4FE4,	// 俤 	505F 
	0x4FE5,	// 俥 	5060 
	0x50CD,	// 働 	462F 
	0x51E7,	// 凧 	427C 
	0x51E9,	// 凩 	515E 
	0x51EA,	// 凪 	4664 
	0x5301,	// 匁 	4C68 
	0x5302,	// 匂 	4677 
	0x53FA,	// 叺 	525D 
	0x54D8,	// 哘 	5326 
	0x55B0,	// 喰 	3674 
	0x5678,	// 噸 	4655 
	0x567A,	// 噺 	4838 
	0x5737,	// 圷 	542A 
	0x5738,	// 圸 	542B 
	0x5788,	// 垈 	5432 
	0x5840,	// 塀 	4A3D 
	0x5870,	// 塰 	544B 
	0x5B36,	// 嬶 	554E 
	0x5CE0,	// 峠 	463D 
	0x603A,	// 怺 	576A 
	0x6762,	// 杢 	4C5D 
	0x6763,	// 杣 	5B3C 
	0x67A0,	// 枠 	4F48 
	0x67A1,	// 枡 	5B46 
	0x67FE,	// 柾 	4B6F 
	0x6802,	// 栂 	444E 
	0x6803,	// 栃 	464A 
	0x691A,	// 椚 	5C2F 
	0x6923,	// 椣 	5C30 
	0x698A,	// 榊 	3A67 
	0x6A2B,	// 樫 	335F 
	0x6BDF,	// 毟 	5D5B 
	0x6C62,	// 汢 	5D69 
	0x71F5,	// 燵 	5F7D 
	0x74E7,	// 瓧 	6123 
	0x74E9,	// 瓩 	6124 
	0x74F0,	// 瓰 	6127 
	0x74F1,	// 瓱 	6128 
	0x74F8,	// 瓸 	6129 
	0x7505,	// 甅 	612D 
	0x7551,	// 畑 	482A 
	0x7560,	// 畠 	482B 
	0x766A,	// 癪 	617B 
	0x7ACD,	// 竍 	6367 
	0x7ACF,	// 竏 	6368 
	0x7AD3,	// 竓 	636A 
	0x7AD5,	// 竕 	6369 
	0x7AE1,	// 竡 	636E 
	0x7AF0,	// 竰 	6372 
	0x7C13,	// 簓 	6449 
	0x7C75,	// 籵 	6462 
	0x7C7E,	// 籾 	4C62 
	0x7C81,	// 粁 	364E 
	0x7C8D,	// 粍 	4C30 
	0x7CA8,	// 粨 	646A 
	0x7CCE,	// 糎 	4138 
	0x7E05,	// 縅 	654F 
	0x8062,	// 聢 	665E 
	0x81A4,	// 膤 	6733 
	0x84D9,	// 蓙 	6868 
	0x88C3,	// 裃 	6A61 
	0x88C4,	// 裄 	6A62 
	0x8904,	// 褄 	6A6D 
	0x8977,	// 襷 	6B27 
	0x8ADA,	// 諚 	6B5C 
	0x8EBE,	// 躾 	6D3F 
	0x8EC8,	// 軈 	6D41 
	0x8FB7,	// 辷 	6D68 
	0x8FBB,	// 辻 	4454 
	0x8FBC,	// 込 	397E 
	0x8FDA,	// 迚 	6D69 
	0x92F2,	// 鋲 	4946 
	0x933A,	// 錺 	6F25 
	0x933B,	// 錻 	6F27 
	0x93B9,	// 鎹 	6F31 
	0x9453,	// 鑓 	4C7A 
	0x958A,	// 閊 	6F5B 
	0x9596,	// 閖 	6F5D 
	0x9786,	// 鞆 	705D 
	0x98AA,	// 颪 	7124 
	0x9942,	// 饂 	713B 
	0x9B96,	// 鮖 	723B 
	0x9B97,	// 鮗 	723C 
	0x9BA0,	// 鮠 	723E 
	0x9BCF,	// 鯏 	7245 
	0x9BD1,	// 鯑 	7246 
	0x9BD2,	// 鯒 	7247 
	0x9BF0,	// 鯰 	7250 
	0x9BF1,	// 鯱 	724F 
	0x9C2F,	// 鰯 	3073 
	0x9C30,	// 鰰 	7260 
	0x9C48,	// 鱈 	432D 
	0x9C5A,	// 鱚 	7265 
	0x9D2B,	// 鴫 	3C32 
	0x9EBF,	// 麿 	4B7B 
	END_OF_DATA
};

//
// Sample sentences
// 
const char *sentences[]={
	"碓氷峠（うすいとうげ）は群馬県安中市松井田町と長野県北佐久郡軽井沢町との境にある日本の峠である。",
	END_OF_DATA
};


//
// 
//
OrthographyData data={
	"Japanese Kokuji",
	"日本国字",
	0x5ce0, // Mountain pass, 峠 
	values,
	"峠栂込榊鴫辻畑柾梻毟",
	sentences
};

const OrthographyData *pData = &data;

}; // end of namespace

#endif
