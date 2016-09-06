cmake_minimum_required (VERSION 3.0)
project(avl_test)

set_property(GLOBAL PROPERTY USE_FOLDERS ON) # For VS to organize the project in folders

#setup the compiler flags
if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++1z -D_USE_MATH_DEFINES")
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Weffc++ -pedantic -Wshadow -Wsign-compare -Wunused-function -Wunused-label  -Wunused-parameter -Wunused-value  -Wunused-variable -fconcepts -std=c++1z -D_USE_MATH_DEFINES") #-v -save-temps
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Intel")
  message ("Untested compiler, muild might fail.")
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
  if(CMAKE_CXX_FLAGS MATCHES "/Wall")
    string(REGEX REPLACE "/Wall" "/W4" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
  elseif(CMAKE_CXX_FLAGS MATCHES "/W[0-4]")
    string(REGEX REPLACE "/W[0-4]" "/W4" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
  else()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
  endif()
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /D_USE_MATH_DEFINES /D_SCL_SECURE_NO_WARNINGS")
endif()

set(CMAKE_EXPORT_COMPILE_COMMANDS 1)

message ("cxx flags: " ${CMAKE_CXX_FLAGS})

#configuration file
set (VERSION_NUMBER 0.1)

if(CMAKE_BUILD_TYPE MATCHES "Debug")
		set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/debug)
else()
		set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/release)
endif()

if (WIN32)
	set(PLATFORM _WIN32)
else()
	set(PLATFORM _LINUX)
endif()

configure_file (
	  "${PROJECT_SOURCE_DIR}/cmake/cfg.h.in" #The template to generate the actual header
	  "${PROJECT_SOURCE_DIR}/inc/cfg/cfg.h"
	)

file (GLOB_RECURSE TEST "test/*.cpp" "inc/*.h")

#source_group ("test" FILES ${TEST})

add_executable(avl_test ${TEST})

