project(blitz_lib)

include(CheckIncludeFile)

include_directories(
    ${CMAKE_SOURCE_DIR}
    ${blitz_lib_BINARY_DIR}
)

check_include_file(stdint.h HAVE_STDINT_H)
if(HAVE_STDINT_H)
    add_definitions(-DHAVE_STDINT_H)
endif()

set(BLITZ_LIB_MAJOR_VERSION "0")
set(BLITZ_LIB_MINOR_VERSION "0")
set(BLITZ_LIB_PATCH_VERSION "7")

set(BLITZ_LIB_VERSION_STRING "${BLITZ_LIB_MAJOR_VERSION}.${BLITZ_LIB_MINOR_VERSION}.${BLITZ_LIB_PATCH_VERSION}")

set(blitz_LIB_SRCS blitz.cpp colors.cpp convolve.cpp histogram.cpp scalefilter.cpp gradient.cpp)

add_library(qimageblitz SHARED ${blitz_LIB_SRCS})

target_link_libraries(qimageblitz ${QT_QTCORE_LIBRARY} ${QT_QTGUI_LIBRARY})
if (NOT CMAKE_COMPILER_IS_GNUCXX AND CMAKE_SYSTEM_NAME MATCHES SunOS)
    target_link_libraries(qimageblitz -lm -lsunmath)
endif()

set_target_properties(qimageblitz PROPERTIES
    VERSION ${BLITZ_LIB_MAJOR_VERSION}.${BLITZ_LIB_MINOR_VERSION}.${BLITZ_LIB_PATCH_VERSION}
    SOVERSION ${BLITZ_LIB_MAJOR_VERSION}
    DEFINE_SYMBOL MAKE_QIMAGEBLITZ_LIB
)

install(
    TARGETS qimageblitz
    RUNTIME DESTINATION ${BIN_INSTALL_DIR}
    LIBRARY DESTINATION ${LIB_INSTALL_DIR}
    ARCHIVE DESTINATION ${LIB_INSTALL_DIR}
)

install(
    FILES qimageblitz.h qimageblitz_export.h
    DESTINATION include/qimageblitz
    COMPONENT Devel
)

if(NOT WIN32)
    configure_file("qimageblitz.pc.cmake" "${CMAKE_CURRENT_BINARY_DIR}/qimageblitz.pc" @ONLY)

    install(
        FILES ${CMAKE_CURRENT_BINARY_DIR}/qimageblitz.pc
        DESTINATION ${LIB_INSTALL_DIR}/pkgconfig
    )
endif()


