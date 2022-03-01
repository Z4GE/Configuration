//  Z4GE.System
//  Copyright 2022 DeathBlizzard
//
//  Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following
//  conditions are met:
//
//  1.  Redistributions of source code must retain the above copyright notice, this list of conditions and the following
//      disclaimer.
//
//  2.  Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following
//      disclaimer in the documentation and/or other materials provided with the distribution.
//
//  3.  Neither the name of the copyright holder nor the names of its contributors may be used to endorse or promote products
//      derived from this software without specific prior written permission.
//
//  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES,
//  INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
//  DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
//  EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
//  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
//  STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
//  ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
#ifndef Z4GE__INCLUDE__SYSTEM_HH_
#define Z4GE__INCLUDE__SYSTEM_HH_

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @file       Z4GE/Configuration.hh
/// @brief      The Z4GE Cofiguration Package Header
/// @details    This header contains all the macros, definitions, declarations and conditional compilation flags that are
///             required by other Z4GE packages. Z4GE packages try to be cross-platform, optimised for their purpose and be
///             uniform in the way the implement a functionality. In order to main these characteristics, it is essential that
///             a configuration system is present to allow the packages to be customised for the clients' requirements.
///
///             However, individual configuration files that contain package specific configuration along with the same
///             condiaitional compilation flags, platform, compiler and language standard identification and fallback
///             implementation seems reduntant. Therefore, this package, `Z4GE.Configuration` provides a all-in-one
///             configuration header that includes all the above mentioned implementations and can be easily included in the
///             packages required by them
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include <Z4GE/Configuration/CompilerTraits.hh>
#include <Z4GE/Configuration/Macros.hh>
#include <Z4GE/Configuration/Platform.hh>

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @defgroup   z4ge_configuration Z4GE.Configuration Package
/// @brief      Encapsulates several feature identification and conditional compilation macros
/// @details    This package contains several macros that detect, identify and implement functionalities based on compiler,
///             host and target platform, language standard and enabled langauge features and extensions. These macros are
///             utilized by all the other libraries for implementing and providing a platform, compiler & standard independent
///             functionality implementation.
/// @{
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

namespace Z4GE { namespace Configuration {

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// @namespace  Z4GE::Configuration
    /// @brief      Platform, Compiler and Standard Identification
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// @brief      Host Platform
    /// @details    This enumerations contains all the platforms that are supported by the Z4GE project.
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    enum Platform {
        Unknown          = Z4GE_PLATFORM_UNKNOWN, ///!    An unknown platform
        MicrosoftWindows = Z4GE_PLATFORM_WINDOWS, ///!    Microsoft Windows
        Cygwin           = Z4GE_PLATFORM_CYGWIN,  ///!    Microsoft Windows under Cygwin
        Linux            = Z4GE_PLATFORM_LINUX,   ///!    Linux
        Unix             = Z4GE_PLATFORM_UNIX,    ///!    UNIXes other than Linux
        Android          = Z4GE_PLATFORM_ANDROID, ///!    Android
        MacOS            = Z4GE_PLATFORM_MACOS    ///!    Apple MacOS
    };

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// @brief      Host Compiler
    /// @details    This enumerations contains all the compilers that are supported by the Z4GE project.
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    enum Compiler {
        Unknown    = Z4GE_COMPILER_UNKNOWN,     ///!    An unknown compiler
        MSVC       = Z4GE_COMPILER_MSVC,        ///!    Microsoft Visual C++ (Visual Studio)
        GCC        = Z4GE_COMPILER_GCC,         ///!    GNU C/CXX Compiler Toolchain
        AppleClang = Z4GE_COMPILER_APPLE_CLANG, ///!    Apple Clang
        LLVMClang  = Z4GE_COMPILER_LLVM_CLANG,  ///!    LLVM Clang
        Intel      = Z4GE_COMPILER_INTEL        ///!    Intel C/CXX Compiler
    };


    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// @brief      Get Host Platform as an ID
    /// @details    This function returns a compile-time constant (if configured && available) identifier that represents
    ///             host platform. The platform is represented by the @ref Z4GE::Configuration::Platform "Platform" enumeration.
    /// @returns    A @ref Z4GE::Configuration::Platform "Platform" that represents the platform
    /// @see        Z4GE::Configuration::Platform
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static Z4GE_CONSTEXPR Platform GetPlatform (void) { return static_cast<Platform> (Z4GE_PLATFORM); }

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// @brief      Get Host Platform Name
    /// @details    This function returns a compile-time constant (if configured && available) that represents the name of the
    ///             host platform.
    /// @returns    A `const char *` that represents the platform name as a string
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static Z4GE_CONSTEXPR const char* GetPlatformName (void) Z4GE_NOEXCEPT { return Z4GE_PLATFORM_NAME; }

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// @brief      Get Host Compiler Name
    /// @details    This function returns a compile-time constant (if configured && available) that represents the name of the
    ///             host compiler.
    /// @returns    A `const char *` that represents the compiler name as a string
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static Z4GE_CONSTEXPR const char* GetCompilerName (void) { return Z4GE_COMPILER_NAME; }

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// @brief      Get Host Compiler as an ID
    /// @details    This function returns a compile-time constant (if configured && available) identifier that represents
    ///             host compiler. The compiler is represented by the @ref Z4GE::Configuration::Compiler "Compiler" enumeration.
    /// @returns    A @ref Z4GE::Configuration::Compiler "Compiler" that represents the platform
    /// @see        Z4GE::Configuration::Compiler
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static Z4GE_CONSTEXPR Compiler GetCompiler (void) { return static_cast<Compiler> (Z4GE_PLATFORM); }

}} // namespace Z4GE::Configuration

/// @}

#endif