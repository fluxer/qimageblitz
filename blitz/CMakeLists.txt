project(blitz_lib) 
include(CheckCXXSourceCompiles)
include(CheckIncludeFile)

include_directories(
  ${CMAKE_SOURCE_DIR}  
  ${blitz_lib_BINARY_DIR} 
  ${QT_INCLUDE_DIR}
  ${QT_QTCORE_INCLUDE_DIR}  
  ${QT_QTGUI_INCLUDE_DIR}
  )

CHECK_INCLUDE_FILE(stdint.h HAVE_STDINT_H)
if(HAVE_STDINT_H)
    add_definitions(-DHAVE_STDINT_H)
endif()

SET(BLITZ_LIB_MAJOR_VERSION "4")
SET(BLITZ_LIB_MINOR_VERSION "0")
SET(BLITZ_LIB_PATCH_VERSION "0")

SET(BLITZ_LIB_VERSION_STRING "${BLITZ_LIB_MAJOR_VERSION}.${BLITZ_LIB_MINOR_VERSION}.${BLITZ_LIB_PATCH_VERSION}")

set(blitz_LIB_SRCS blitz.cpp colors.cpp convolve.cpp histogram.cpp
                   scale.cpp scalefilter.cpp gradient.cpp)

if(COMMAND cmake_policy)
      cmake_policy(SET CMP0003 NEW)
endif(COMMAND cmake_policy) 

add_library(qimageblitz SHARED ${blitz_LIB_SRCS})

target_link_libraries(qimageblitz ${QT_QTCORE_LIBRARY} ${QT_QTGUI_LIBRARY})
if (NOT CMAKE_COMPILER_IS_GNUCXX AND CMAKE_SYSTEM_NAME MATCHES SunOS)
    target_link_libraries(qimageblitz -lm -lsunmath)
endif (NOT CMAKE_COMPILER_IS_GNUCXX AND CMAKE_SYSTEM_NAME MATCHES SunOS)

set_target_properties(qimageblitz PROPERTIES
                            VERSION ${BLITZ_LIB_MAJOR_VERSION}.${BLITZ_LIB_MINOR_VERSION}.${BLITZ_LIB_PATCH_VERSION}
                            SOVERSION ${BLITZ_LIB_MAJOR_VERSION}
                            DEFINE_SYMBOL MAKE_QIMAGEBLITZ_LIB
)
install( TARGETS qimageblitz  
    RUNTIME DESTINATION ${BIN_INSTALL_DIR} 
    LIBRARY DESTINATION ${LIB_INSTALL_DIR} 
    ARCHIVE DESTINATION ${LIB_INSTALL_DIR} 
)

install( FILES qimageblitz.h qimageblitz_export.h DESTINATION include/qimageblitz COMPONENT Devel )

if(NOT WIN32)
  configure_file("qimageblitz.pc.cmake" "${CMAKE_CURRENT_BINARY_DIR}/qimageblitz.pc"
  @ONLY) 

  install(FILES ${CMAKE_CURRENT_BINARY_DIR}/qimageblitz.pc DESTINATION 
  ${LIB_INSTALL_DIR}/pkgconfig)  
endif(NOT WIN32)


