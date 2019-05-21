project(blitztest)

include_directories(
    ${CMAKE_SOURCE_DIR}
    ${blitztest_BINARY_DIR}
    ${blitz_lib_SOURCE_DIR}
)

set(blitztest_SRCS main.cpp mainwindow.cpp scaledialog.cpp)

add_executable(blitztest ${blitztest_SRCS})

target_link_libraries(blitztest ${QT_QTCORE_LIBRARY} ${QT_QTGUI_LIBRARY} qimageblitz)

install(
    TARGETS blitztest
    DESTINATION ${BIN_INSTALL_DIR}
)

