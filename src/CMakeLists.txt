cmake_minimum_required(VERSION 3.20)
include(CMakePrintHelpers)
project(emulator)
add_executable(emulator)

file(GLOB_RECURSE C_SRCS CONFIGURE_DEPENDS ${CMAKE_SOURCE_DIR}
    "*.cpp"
)
file(GLOB_RECURSE C_HEADERS CONFIGURE_DEPENDS ${CMAKE_SOURCE_DIR}
    "*.hpp"
)

target_compile_options(emulator PUBLIC -m64)
target_include_directories(emulator PUBLIC ${C_HEADERS})
target_sources(emulator PUBLIC main.cpp ${C_SRCS})
target_link_libraries(emulator -lSDL2)
