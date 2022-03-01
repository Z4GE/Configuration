##  Z4GE.System
##  Copyright 2022 DeathBlizzard
##  
##  Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following
##  conditions are met:
##  
##  1.  Redistributions of source code must retain the above copyright notice, this list of conditions and the following
##      disclaimer.Configuration
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
##  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
##  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
##  EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

##  Module Guard
##  Prevent `AssertOutOfSourceBuilds` module to be included more than once by the parent CMakeLists.txt
if(DEFINED ASSERT_OUT_OF_SOURCE_BUILDS_INCLUDED)
    return()
endif()
set(ASSERT_OUT_OF_SOURCE_BUILDS_INCLUDED YES)

function(AssertOutOfSourceBuilds)
    get_filename_component(CURRENT_SOURCE_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}" REALPATH)
    get_filename_component(CURRENT_BINARY_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}" REALPATH)

    if(CURRENT_SOURCE_DIRECTORY STREQUAL CURRENT_BINARY_DIRECTORY)
        message(FATAL_ERROR
            "[AssertOutOfSourceBuilds] The current project has been configured for an 'In-Source build'."
            "\n"
            "The current project `${CMAKE_PROJECT_NAME}` has been configured to assert out of source builds. "
            "Out of source builds ensure that the generated configuration files and the built binaries are "
            "seperated from the source tree. In-source builds tend to pollute the source tree, inducing further "
            "problems while maintaining as a repository."
            "\n"
            "Please create a dedicated source directory such as `build` for storing the build configuration and "
            "end-product binaries. This configuration run should have created `CMakeFiles` directory and `CMakeCache.txt` "
            "file in the source directory (${CURRENT_SOURCE_DIRECTORY}). Please remove them before proceeding further."
            "\n"
        )
    endif()
endfunction()

##  AssertOutOfSourceBuilds
##  The actual function `AssertOutOfSourceBuilds` is called to ensure that the function is executed at the time of
##  project configuration
AssertOutOfSourceBuilds()

