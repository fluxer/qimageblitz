cmake_minimum_required(VERSION 2.8.12 FATAL_ERROR)

project(blitz)

find_package(Katie QUIET)
if(NOT KATIE_FOUND)
   find_package(Qt4 REQUIRED)
endif()

# set up compile definitions and header directories
add_definitions(${QT_DEFINITIONS})
include_directories(${QT_INCLUDES})

set(LIB_SUFFIX "" CACHE STRING "Define suffix of directory name (32/64)" )
set(EXEC_INSTALL_PREFIX  ${CMAKE_INSTALL_PREFIX}       CACHE PATH  "Base directory for executables and libraries")
#
## the following are directories where stuff will be installed to
set(BIN_INSTALL_DIR "${EXEC_INSTALL_PREFIX}/bin" CACHE PATH "The kde binary install dir (default prefix/bin)")
set(LIB_INSTALL_DIR  "${EXEC_INSTALL_PREFIX}/lib${LIB_SUFFIX}" CACHE PATH "The subdirectory relative to the install prefix where libraries will be installed (default is /lib${LIB_SUFFIX})")

# Set up RPATH handling, so the libs are found if they are installed to a non-standard location.
# By default cmake builds the targets with full RPATH to everything in the build directory,
# but then removes the RPATH when installing.
# These two options below make it set the RPATH of the installed targets to all
# RPATH directories outside the current CMAKE_BINARY_DIR and also the library 
# install directory. Alex
set(CMAKE_INSTALL_RPATH_USE_LINK_PATH  TRUE)
set(CMAKE_INSTALL_RPATH "${LIB_INSTALL_DIR}" )

if(WIN32)
    set(CMAKE_DEBUG_POSTFIX "d")
    set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)
endif()

if(APPLE)
    set(CMAKE_INSTALL_NAME_DIR ${LIB_INSTALL_DIR})
endif(APPLE)

if(COMMAND cmake_policy)
    cmake_policy(SET CMP0003 NEW)
endif()

add_subdirectory(blitz)
add_subdirectory(test)
