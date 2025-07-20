file(GLOB TEST_SOURCES CONFIGURE_DEPENDS
    ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
)

add_executable(dsp-tests ${TEST_SOURCES})
target_link_libraries(dsp-tests
    PRIVATE
        dsp
        CppUTest
        CppUTestExt
)

target_include_directories(dsp-tests PRIVATE
    ${CMAKE_SOURCE_DIR}/include
)
