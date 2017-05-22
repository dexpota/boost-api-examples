cmake_minimum_required(VERSION 3.6)
project(boost-api-examples)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_VERBOSE_MAKEFILE ON)

find_package(Boost REQUIRED COMPONENTS program_options thread system unit_test_framework python)
include_directories(${Boost_INCLUDE_DIRS})

if(APPLE)
    find_program(PYTHON_CONFIG_EXECUTABLE python-config)
    if (NOT PYTHON_CONFIG_EXECUTABLE)
        message(SEND_ERROR "python-config executable not found, but python is required.")
    endif()
    # using "python-config --prefix" so that cmake always uses the python that is
    # in the user's path, this is a fix for homebrew on Mac:
    # https://github.com/Homebrew/homebrew/issues/25118 [^]
    execute_process(COMMAND ${PYTHON_CONFIG_EXECUTABLE} --prefix OUTPUT_VARIABLE python_prefix OUTPUT_STRIP_TRAILING_WHITESPACE)
    set(PYTHON_INCLUDE_DIR ${python_prefix}/include/python2.7)
    set(PYTHON_LIBRARY ${python_prefix}/lib/libpython2.7${CMAKE_SHARED_LIBRARY_SUFFIX})
endif()

find_package(PythonLibs 2.7 REQUIRED)
include_directories(${PYTHON_INCLUDE_DIRS})

add_subdirectory(any)
add_subdirectory(array)
add_subdirectory(bind)
add_subdirectory(iterator)
add_subdirectory(move)
add_subdirectory(optional)
add_subdirectory(program_options)
add_subdirectory(thread)
add_subdirectory(tuple)
add_subdirectory(variant)
add_subdirectory(unit_test_framework)
add_subdirectory(python)