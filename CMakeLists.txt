cmake_minimum_required(VERSION 2.8)
project(uv)

set(LIBUVDIR libuv)

include_directories(${LIBUVDIR}/include  
                    ${LIBUVDIR}/src)
file(GLOB SOURCES ${LIBUVDIR}/src/*.c ${LIBUVDIR}/src/*.h)

if(WIN32)
  add_definitions(-DWIN32_LEAN_AND_MEAN -D_WIN32_WINNT=0x0600 -D_CRT_SECURE_NO_WARNINGS)
  include_directories(${LIBUVDIR}/src/win)
  file(GLOB SYS ${LIBUVDIR}/src/win/*.c ${LIBUVDIR}/src/win/*.h)
else()
  include_directories(${LIBUVDIR}/src/unix)
  file(GLOB SYS ${LIBUVDIR}/src/unix/*.c ${LIBUVDIR}/src/unix/*.h)
endif()

add_library(uv ${SOURCES} ${SYS})

### INSTALL ###

install(TARGETS uv ARCHIVE DESTINATION lib)
file(GLOB_RECURSE HDRS ${LIBUVDIR}/include/*.h)
install(FILES ${HDRS} DESTINATION include)

### PACKAGE CONFIG ###

export(PACKAGE uv)
export(TARGETS uv FILE uv-targets-config.cmake)

include(CMakePackageConfigHelpers)
set(UV_INCLUDE_DIR ${LIBUVDIR}/include)
configure_package_config_file(uv-config.cmake.in
    ${CMAKE_CURRENT_BINARY_DIR}/uv-config.cmake          
    INSTALL_DESTINATION xxx    # not sure what this does
    PATH_VARS UV_INCLUDE_DIR)
