#
# The Fontaine Font Analysis Project 
# 
# Copyright (c) 2009 by Edward H. Trager
# All Rights Reserved
# 
# Released under the GNU GPL version 2.0 or later.
#     
PROJECT(FONTAINE)
CMAKE_MINIMUM_REQUIRED(VERSION 2.4.2)
MARK_AS_ADVANCED(CMAKE_BACKWARDS_COMPATIBILITY)

#
# The FONTAINE version number:
# 
SET(FONTAINE_VERSION_MAJOR 1)
SET(FONTAINE_VERSION_MINOR 2)
SET(FONTAINE_VERSION "${FONTAINE_VERSION_MAJOR}.${FONTAINE_VERSION_MINOR}")

#
# Recurse subdirectories:
#
SUBDIRS(doxygen po src)
#SUBDIRS(po src)


INCLUDE_DIRECTORIES(${FONTAINE_SOURCE_DIR} ${FONTAINE_BINARY_DIR})
INCLUDE(${CMAKE_ROOT}/Modules/FindDoxygen.cmake)

CONFIGURE_FILE(${FONTAINE_SOURCE_DIR}/doxygen/Doxyfile.in ${FONTAINE_BINARY_DIR}/doxygen/Doxyfile)

INCLUDE( FindDoxygen )
IF(DOXYGEN) 
	ADD_CUSTOM_TARGET(api-docs ALL ${DOXYGEN} ${FONTAINE_BINARY_DIR}/doxygen/Doxyfile DEPENDS ${FONTAINE_SOURCE_DIR}/doxygen/Doxyfile.in)
ELSE(DOXYGEN)
	MESSAGE(STATUS "Unable to locate DOxygen : API Documentation will not be built!")
ENDIF(DOXYGEN)

#
# Put compiled libraries and executables in specified directories:
#
SET( LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/libs )
SET( EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin )


