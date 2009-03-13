#
# Fontaine Font Analysis Program 
# 
# Copyright (c) 2009 by Edward H. Trager
# All Rights Reserved
# 
# Released under the GNU GPL version 2.0 or later.
#
SET( SOURCES 
	
	BasicLatinStringUtilities.cpp
	BasicLatinStringUtilities.h
	
	CLP.cpp
	CLP.h
	
	Debug.cpp
	Debug.h
	
	Encoding.cpp
	Encoding.h
	
	Exception.cpp
	Exception.h
	
	FontFace.cpp
	FontFace.h
	   
	FontLibrary.cpp
	FontLibrary.h
	
	LicenseData.h
	
	Message.cpp
	Message.h
	
	OrthographyData.h
	
	OrthographyResults.cpp
	OrthographyResults.h
	
	Utf8String.cpp
	Utf8String.h
	 
	Warning.cpp
	Warning.h    
	
	MLR.h
	MLR.cpp
	
	XMLR.h
	XMLR.cpp
	
	JSONR.h
	JSONR.cpp
	
	XHTMLR.h
	XHTMLR.cpp
	
	TEXTR.h
	TEXTR.cpp
	
	FXHTMLR.h
	FXHTMLR.cpp
	
	main.cpp
	
)

#
# Where to look first for cmake modules, before ${CMAKE_ROOT}/Modules/ is checked:
# 
SET(CMAKE_MODULE_PATH "${FONTAINE_SOURCE_DIR}/cmake/modules")

#
# Include UsePkgConfig.cmake
#
#INCLUDE( UsePkgConfig )

INCLUDE( FindFreetype )

SET(requiredLibs)
SET(requiredCFlags)

#SET(optionalLibs)
#SET(optionalCFlags)

#
# Freetype2 support:
#
IF( FREETYPE_FOUND )
	INCLUDE_DIRECTORIES(${FREETYPE_INCLUDE_DIR})
	SET(requiredLibs ${requiredLibs} ${FREETYPE_LIBRARIES})
ENDIF( FREETYPE_FOUND )

#
# LibIntl support:
#
INCLUDE( FindLibintl )
IF( LIBINTL_FOUND )
	INCLUDE_DIRECTORIES(${LIBINTL_INCLUDE_DIR})
	SET(requiredLibs ${requiredLibs} ${LIBINTL_LIBRARIES})
ENDIF( LIBINTL_FOUND )


#
# Config.h File generation:
#
INCLUDE (CheckIncludeFiles)
# usage: CHECK_INCLUDE_FILES (<header> <RESULT_VARIABLE> )
CHECK_INCLUDE_FILES (malloc.h HAVE_MALLOC_H)
CHECK_INCLUDE_FILES ("sys/param.h;sys/mount.h" HAVE_SYS_MOUNT_H)
SET( PACKAGE fontaine )
SET( LOCALEDIR ${CMAKE_INSTALL_PREFIX}/share/locale )
CONFIGURE_FILE(${CMAKE_CURRENT_SOURCE_DIR}/config.h.cmake ${FONTAINE_BINARY_DIR}/config.h)
INCLUDE_DIRECTORIES( ${FONTAINE_BINARY_DIR} )

#
# Executables:
#
ADD_EXECUTABLE(fontaine ${SOURCES} )

#
# Link target:
#
TARGET_LINK_LIBRARIES(fontaine 
	${requiredLibs} 
	stdc++
)

#
# Installation directory:
#
MESSAGE(STATUS "=== NOTA BENE: === Fontaine will be installed in ${CMAKE_INSTALL_PREFIX}")

#
# Installable items:
#
INSTALL_TARGETS( /bin fontaine )

