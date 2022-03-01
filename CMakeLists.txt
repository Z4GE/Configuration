##  Z4GE.Configuration
##  Copyright 2022 DeathBlizzard
##  
##  Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following
##  conditions are met:
##  
##  1.  Redistributions of source code must retain the above copyright notice, this list of conditions and the following
##      disclaimer.
##  
##  2.  Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following
##      disclaimer in the documentation and/or other materials provided with the distribution.
##  
##  3.  Neither the name of the copyright holder nor the names of its contributors may be used to endorse or promote products
##      derived from this software without specific prior written permission.
##  
##  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES,
##  INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
##  DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
##  EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
##  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
##  STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
##  ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

##  Z4GE.Configuration CMake Version
##  Currently, Z4GE.Configuration Package requires CMake 3.11.0
if(NOT DEFINED Z4GE_CONFIGURATION_CMAKE_VERSION)
    set(Z4GE_CONFIGURATION_CMAKE_VERSION 3.11.0..3.22.0)
endif()
cmake_minimum_required(VERSION ${Z4GE_CONFIGURATION_CMAKE_VERSION})

##  Z4GE.Configuration Project Management
if(CMAKE_SOURCE_DIR STREQUAL CMAKE_CURRENT_SOURCE_DIR)
    set(Z4GE_CONFIGURATION_STANDALONE_BUILD ON)
else()
    set(Z4GE_CONFIGURATION_STANDALONE_BUILD OFF)
endif()

##  Z4GE.Configuration Variables
set(Z4GE_CONFIGURATION_ROOT_DIRECTORY                   ${CMAKE_CURRENT_SOURCE_DIR})
set(Z4GE_CONFIGURATION_INCLUDE_DIRECTORY                ${Z4GE_CONFIGURATION_ROOT_DIRECTORY}/Include)
set(Z4GE_CONFIGURATION_DOCUMENTATION_DIRECTORY          ${Z4GE_CONFIGURATION_ROOT_DIRECTORY}/Documentation)
set(Z4GE_CONFIGURATION_DOCUMENTATION_OUTPUT_DIRECTORY   ${CMAKE_CURRENT_BINARY_DIR}/Documentation)
set(Z4GE_CONFIGURATION_TESTING_DIRECTORY                ${Z4GE_CONFIGURATION_ROOT_DIRECTORY}/Testing)

##  CMake Modules
##  Add the cmake modules that are provided by the Z4GE.Configuration Package. This package contains a selection of some
##  development assertion, management and evaluation modules that makes developers' life a lot easier
list(APPEND CMAKE_MODULE_PATH ${Z4GE_CONFIGURATION_ROOT_DIRECTORY}/CMake)
include(AssertOutOfSourceBuilds)
include(SetGlobalVariable)

##  Z4GE.Configuration Version
##  Z4GE follows "Semantic Versioning" scheme for providing meaningful versioning to the package. For information, visit
##  https://semver.org
if(NOT DEFINED Z4GE_CONFIGURATION_PACKAGE_VERSION)
    set(Z4GE_CONFIGURATION_VERSION_MAJOR   0)
    set(Z4GE_CONFIGURATION_VERSION_MINOR   1)
    set(Z4GE_CONFIGURATION_VERSION_PATCH   0)
    set_global(Z4GE_CONFIGURATION_PACKAGE_VERSION
        ${Z4GE_CONFIGURATION_VERSION_MAJOR}.${Z4GE_CONFIGURATION_VERSION_MINOR}.${Z4GE_CONFIGURATION_VERSION_PATCH}
    )
endif()

##  Z4GE.Configuration CMake Project
project(
    Z4GEConfiguration
    DESCRIPTION "Platform / Compiler independent system headers, type definitions and macros for Z4GE"
    VERSION ${Z4GE_CONFIGURATION_VERSION_MAJOR}.${Z4GE_CONFIGURATION_VERSION_MINOR}.${Z4GE_CONFIGURATION_VERSION_PATCH}
    LANGUAGES CXX
)

##  Build options
##  The follwing are the build options that can be configured according to the requirements
##
##  Z4GE_CONFIGURATION_DISABLE_PEDANTIC_ERRORS      -   By default, Z4GE.Configuration package is compiler with pedantic errors.
##                                                      This ensures that the package is standard compilant and enables the
##                                                      developers to detect and debug effectively. This feature can be disabled
##                                                      by setting this build option to 'ON'
##
##  Z4GE_CONFIGURATION_DISABLE_WARNING_AS_ERROR     -   By default, Z4GE.Configuration package is compiler with warnings as
##                                                      errors. This ensures that the package is standard compilant and enables
##                                                      the developers to detect and debug effectively. This feature can be
##                                                      disabled by setting this build option to 'ON'
option(Z4GE_CONFIGURATION_DISABLE_PEDANTIC_ERRORS   "Disable pedantic errors by compiler for Z4GE.Configuration Package" OFF)
option(Z4GE_CONFIGURATION_DISABLE_WARNING_AS_ERROR 
    "Disable treating warning as errors by compiler for Z4GE.Configuration Package" OFF
)
option(Z4GE_CONFIGURATION_BUILD_DOCUMENTATION       "Build documentation for Z4GE.Configuration Package"                OFF)
option(Z4GE_CONFIGURATION_ENABLE_DEVELOPER_DOCUMENTATION
    "Build documentation that includes developer sections"                                                              ON
)

##  Compiler Options
##  The follwing segment of CMake configuration code tries to capture compiler specifc pedantic errors that can be used in case
##  Z4GE_CONFIGURATION_DISABLE_PEDANTIC_ERRORS is not specified
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU")
    set(Z4GE_CONFIGURATION_PEDANTIC_ERROR_FLAGS
        -pedantic-errors -Wall -Wextra -pedantic -Wold-style-cast -Wundef -Wredundant-decls -Wwrite-strings -Wpointer-arith
        -Wcast-qual -Wformat=2 -Wmissing-include-dirs -Wcast-align -Wctor-dtor-privacy -Wdisabled-optimization
        -Winvalid-pch -Woverloaded-virtual -Wconversion -Wundef -Wno-ctor-dtor-privacy -Wno-format-nonliteral
        -Wno-dangling-else -Wno-unused-local-typedefs -Wdouble-promotion -Wtrampolines -Wzero-as-null-pointer-constant
        -Wuseless-cast -Wvector-operation-performance -Wsized-deallocation -Wshadow -Wshift-overflow=2 -Wnull-dereference
        -Wduplicated-cond
    )
    set(Z4GE_CONFIGURATION_WERROR_FLAG -Werror)
elseif(CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    set(Z4GE_CONFIGURATION_PEDANTIC_ERROR_FLAGS
        -Wall -Wextra -pedantic -Wconversion -Wundef -Wdeprecated -Wweak-vtables -Wshadow -Wno-gnu-zero-variadic-macro-arguments
        -Wzero-as-null-pointer-constant
    )
    set(Z4GE_CONFIGURATION_WERROR_FLAG -Werror)
elseif(MSVC)
    set(Z4GE_CONFIGURATION_PEDANTIC_ERROR_FLAGS    /W4)
    set(Z4GE_CONFIGURATION_WERROR_FLAG             /WX)
else()
    set(Z4GE_CONFIGURATION_PEDANTIC_ERROR_FLAGS    )
    set(Z4GE_CONFIGURATION_WERROR_FLAG             )
    message(WARNING "Z4GE.Configuration    =>  Unable to capture Pedantic error and Werror flags for the host compiler")
endif()

set(Z4GE_CONFIGURATION_COMPILE_OPTIONS)
if(NOT Z4GE_CONFIGURATION_DISABLE_PEDANTIC_ERRORS)
    list(APPEND Z4GE_CONFIGURATION_COMPILE_OPTIONS ${Z4GE_CONFIGURATION_PEDANTIC_ERROR_FLAGS})
endif()
if(NOT Z4GE_CONFIGURATION_DISABLE_WARNING_AS_ERROR)
    list(APPEND Z4GE_CONFIGURATION_COMPILE_OPTIONS ${Z4GE_CONFIGURATION_WERROR_FLAG})
endif()

##  Create the Z4GE.Configuration Library
##  Z4GE.Configuration is a header only library. Therefore it is defined as an INTERFACE library rather than a STATIC or
##  SHARED library
set(Z4GE_CONFIGURATION_HEADERS
    Z4GE/Configuration/Macros.hh
    Z4GE/Configuration/Platform.hh
    Z4GE/Configuration/CompilerTraits.hh

    Z4GE/Configuration.hh
)

add_library(Z4GE.Configuration INTERFACE)
add_library(Z4GE::Configuration ALIAS Z4GE.Configuration)
foreach(HEADER_FILE IN LISTS ${Z4GE_CONFIGURATION_HEADERS})
    target_sources(
        Z4GE.Configuration PUBLIC
        $<BUILD_INTERFACE:${Z4GE_CONFIGURATION_INCLUDE_DIRECTORY}/${HEADER_FILE}>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}/${HEADER_FILE}>
    )
endforeach()
target_include_directories(Z4GE.Configuration INTERFACE ${Z4GE_CONFIGURATION_INCLUDE_DIRECTORY})
target_compile_options(Z4GE.Configuration INTERFACE ${Z4GE_CONFIGURATION_COMPILE_OPTIONS})

##  Testing
include(FetchContent)

FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v3.0.0-preview4
)

FetchContent_MakeAvailable(Catch2)
list(APPEND CMAKE_MODULE_PATH ${catch2_SOURCE_DIR}/extras)
include(CTest)
include(Catch)

add_executable(PlatformTesting ${Z4GE_CONFIGURATION_TESTING_DIRECTORY}/Platform.cc)
target_link_libraries(PlatformTesting PRIVATE Z4GE::Configuration Catch2::Catch2WithMain)

add_executable(MacrosTesting ${Z4GE_CONFIGURATION_TESTING_DIRECTORY}/Macros.cc)
target_link_libraries(MacrosTesting PRIVATE Z4GE::Configuration Catch2::Catch2WithMain)

catch_discover_tests(PlatformTesting)
catch_discover_tests(MacrosTesting)

##  Configure Doxygen for XML output
set(Z4GE_CONFIGURATION_DOXYGEN_SECTIONS)
if(Z4GE_CONFIGURATION_ENABLE_DEVELOPER_DOCUMENTATION)
    list(APPEND Z4GE_CONFIGURATION_DOXYGEN_SECTIONS "build_developer_documentation")
endif()

configure_file(
    ${Z4GE_CONFIGURATION_DOCUMENTATION_DIRECTORY}/Doxygen/Doxyfile.in
    ${Z4GE_CONFIGURATION_DOCUMENTATION_OUTPUT_DIRECTORY}/Doxyfile
    @ONLY
)

add_custom_target(
    GenerateDocumentation_Z4GEConfiguration
    COMMAND ${CMAKE_COMMAND} -E make_directory ${Z4GE_CONFIGURATION_DOCUMENTATION_OUTPUT_DIRECTORY}
    COMMAND echo "Documentations are located at ${Z4GE_CONFIGURATION_DOCUMENTATION_OUTPUT_DIRECTORY}"
    COMMAND doxygen Doxyfile
    WORKING_DIRECTORY "${Z4GE_CONFIGURATION_DOCUMENTATION_OUTPUT_DIRECTORY}"
    COMMENT "Generating documentation for Z4GE.Configuration @ ${Z4GE_CONFIGURATION_DOCUMENTATION_OUTPUT_DIRECTORY}"
    VERBATIM
)
