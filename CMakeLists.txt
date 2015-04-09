cmake_minimum_required (VERSION 2.6)
project (Yeta)
 
# The version number.
set (Yeta_VERSION_MAJOR 0)
set (Yeta_VERSION_MINOR 1)

include(CheckCXXCompilerFlag)
enable_language(CXX)

if(CMAKE_HOST_APPLE)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libc++")
endif()

set(ENABLE_CXXFLAGS_TO_CHECK 
    -std=gnu++1y 
    -std=c++1y
    -std=gnu++11 
    -std=c++11
    -std=gnu++0x 
    -std=c++0x)

foreach(flag ${ENABLE_CXXFLAGS_TO_CHECK})
    string(REPLACE "-std=" "_" flag_var ${flag})
    string(REPLACE "+" "x" flag_var ${flag_var})
    check_cxx_compiler_flag("${flag}" COMPILER_HAS_CXX_FLAG${flag_var})
    if(COMPILER_HAS_CXX_FLAG${flag_var})
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${flag}")
        break()
    endif()
endforeach()

include(CTest)

include_directories(.)

install (DIRECTORY yeta DESTINATION include)

add_custom_target(check COMMAND ${CMAKE_CTEST_COMMAND})

macro(add_test_executable TEST_NAME)
    add_executable (${TEST_NAME} EXCLUDE_FROM_ALL test/${TEST_NAME}.cpp)
    add_test(${TEST_NAME} ${TEST_NAME})
    add_dependencies(check ${TEST_NAME})
    set_tests_properties(${TEST_NAME} PROPERTIES FAIL_REGULAR_EXPRESSION "FAILED")
endmacro(add_test_executable)

add_test_executable(always)
add_test_executable(bind)
add_test_executable(fold)
add_test_executable(if)
add_test_executable(integral_constant)
add_test_executable(is_same)
add_test_executable(list)
add_test_executable(or)
add_test_executable(reverse_fold)

