cmake_minimum_required(VERSION 3.16)
project(dsp-lib LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

# Output directories
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

# Option to enable/disable tests
option(DSP_BUILD_TESTS "Build unit tests" ON)

# Include the source files
file(GLOB_RECURSE DSP_SOURCES CONFIGURE_DEPENDS
    ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp
)

add_library(dsp STATIC ${DSP_SOURCES})
target_include_directories(dsp PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

# Add tests if enabled
if (DSP_BUILD_TESTS)
    add_subdirectory(extern/CppUTest)
    add_subdirectory(tests)
endif()
