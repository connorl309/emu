cmake_minimum_required(VERSION 3.20)
include(CMakePrintHelpers)
project(emulator)
add_executable(emulator)

set(PROJ_BUILD_TYPE "DEBUG")
if (${PROJ_BUILD_TYPE} STREQUAL "DEBUG")
    message("Building emulator in debug mode... (-G1)")
    set(build_release_or_debug "-g1")
elseif(${PROJ_BUILD_TYPE} STREQUAL "RELASE")
    message("Building emulator in release mode... (-O2)")
    set(build_release_or_debug "-o2")
endif()

file(GLOB_RECURSE C_SRCS CONFIGURE_DEPENDS ${CMAKE_SOURCE_DIR}
    "*.cpp"
)
file(GLOB_RECURSE C_HEADERS CONFIGURE_DEPENDS ${CMAKE_SOURCE_DIR}
    "*.hpp"
)
set(HEADER_PATHS "")
foreach(_headerFile ${C_HEADERS})
    get_filename_component(_dir ${_headerFile} DIRECTORY)
    list(APPEND HEADER_PATHS ${_dir})
endforeach()

target_compile_options(emulator PUBLIC -m64 ${build_release_or_debug})
target_include_directories(emulator PUBLIC ${HEADER_PATHS})
target_sources(emulator PUBLIC main.cpp ${C_SRCS})
target_link_libraries(emulator -lSDL2)
