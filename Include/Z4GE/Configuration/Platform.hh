//  Z4GE.System
//  Copyright 2022 DeathBlizzard
//
//  Redistribution and use in source and binary forms, with or without
//  modification, are permitted provided that the following conditions are met:
//
//  1.  Redistributions of source code must retain the above copyright notice,
//  this list of conditions and the following
//      disclaimer.
//
//  2.  Redistributions in binary form must reproduce the above copyright
//  notice, this list of conditions and the following
//      disclaimer in the documentation and/or other materials provided with the
//      distribution.
//
//  3.  Neither the name of the copyright holder nor the names of its
//  contributors may be used to endorse or promote products
//      derived from this software without specific prior written permission.
//
//  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
//  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
//  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
//  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
//  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
//  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
//  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
//  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
//  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
//  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
//  POSSIBILITY OF SUCH DAMAGE.
#ifndef Z4GE_CONFIGURATION__PLATFORM_HH_
#define Z4GE_CONFIGURATION__PLATFORM_HH_

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @cond       build_developer_documentation
/// @file       Z4GE/Configuration/Platform.hh
/// @brief      Platform, Compiler, Architecture Identification and Conditional Compilation Macros
/// @details    This file contains Platform, Compiler and architecture identification along with conditional compilation macros.
///             These macros are often used by other Z4GE packages for building cross platform / compiler / architecture
///             packagaes and/or executables.
///
///             The following are the list of platforms that are supported by
///             Z4GE:
///                 1.  Microsoft Windows
///                 2.  Linux
///                 3.  UNIX (FreeBSD, OpenBSD, NetBSD, etc.)
///                 4.  Androidd
///                 5.  Apple Mac
///
///             The follwing are the list of compilers that are recognised and
///             supported by Z4GE:
///                 1.  LLVM Clang
///                 2.  Apple Clang
///                 3.  GNU C / C++ Compiler Toolchain
///                 4.  Microsoft Visual C++
///                 5.  Intel oneAPI C / C++ / DPC++ Compiler
///                 6.  Nvidia CUDA C++ Compiler
///
///             The follwing are the architectures that are recognised and
///             supported by Z4GE:
///                 1.  x86
///                 2.  x86_64
///                 3.  ARM
///
///             The follwing are the SIMD capabilities that are recognised and
///             supported by Z4GE:
///                 1.  SSE
///                 2.  SSE 2
///                 3.  SSE 3
///                 4.  SSSE 3
///                 5.  SSE 4.1
///                 6.  SSE 4.2
///                 7.  AVX
///                 8.  AVX2
///                 9.  NEON
/// @note       This header file should not be directly included. If you wish to include this file, include
///             @ref Z4GE/Configuration.hh
/// @addtogroup z4ge_configuration
/// @{
/// @defgroup   Z4GE Platform Identification
/// @brief      Platform, Compiler, Architecture Identification and Conditional Compilation Macros
/// @{
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// @brief      Z4GE Unknown Compiler
#define Z4GE_COMPILER_UNKNOWN 0x00
/// @brief      Z4GE LLVM Clang Compiler
#define Z4GE_COMPILER_LLVM_CLANG 0x01
/// @brief      Z4GE Apple Clang Compiler
#define Z4GE_COMPILER_APPLE_CLANG 0x02
/// @brief      Z4GE GNU C Compiler
#define Z4GE_COMPILER_GCC 0x04
/// @brief      Z4GE Microsoft Visual C++ Compiler
#define Z4GE_COMPILER_MSVC 0x08
/// @brief      Z4GE Intel C/C++ Compiler
#define Z4GE_COMPILER_INTEL 0x10
/// @brief      Z4GE Nvidia CUDA C++ Compiler
#define Z4GE_COMPILER_NVCC 0x20

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @brief      Z4GE.Configuration Compiler
/// @details    This macro expands to one of the `Z4GE_COMPILER_*` definitions
/// depending on the host platform's compiler that
///             is used to compile sources including this header file. This
///             macro is primarily used to define compiler specific definitions
///             and conditional compilation macros. The host compiler that is
///             used to compile the Z4GE.Configuration package. The following
///             are the supported compilers:
///                 -#  LLVM Clang
///                 -#  Apple Clang
///                 -#  GNU C Compiler Toolchain
///                 -#  Microsoft Visual C++
///                 -#  Nvidia CUDA C++ Compiler for GPU
///                 -#  Intel C/C++ Compiler
/// @note       This macro expands to a bitfield representing the host platform
/// compiler. In order to retrieve the compiler name
///             utilize @ref Z4GE_COMPILER_NAME
/// @see        Z4GE_COMPILER_NAME
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef Z4GE_COMPILER
#    if defined(Z4GE_FORCE_UNKNOWN_COMPILER)
#        define Z4GE_COMPILER Z4GE_COMPILER_UNKNOWN
#    elif defined(__clang__)
#        if defined(__apple_build_version__)
#            define Z4GE_COMPILER Z4GE_COMPILER_APPLE_CLANG
#        else
#            define Z4GE_COMPILER Z4GE_COMPILER_LLVM_CLANG
#        endif
#    elif defined(__GNUC__)
#        define Z4GE_COMPILER Z4GE_COMPILER_GCC
#    elif defind(_MSC_VER)
#        define Z4GE_COMPILER Z4GE_COMPILER_MSVC
#    elif defined(__INTEL_COMPILER)
#        define Z4GE_COMPILER Z4GE_COMPILER_INTEL
#    elif defined(__CUDACC__)
#        define Z4GE_COMPILER Z4GE_COMPILER_CUDA
#    else
#        define Z4GE_COMPILER Z4GE_COMPILER_UNKNOWN
#    endif
#endif

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @brief      Z4GE Host Platform Compiler Name
/// @details    This macro expands to a string (const char *) representing the
/// name of the compiler used to compile source file
///             including this header.
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef Z4GE_COMPILER_NAME
#    if Z4GE_COMPILER & Z4GE_COMPILER_LLVM_CLANG
#        define Z4GE_COMPILER_NAME "LLVM Clang"
#    elif Z4GE_COMPILER & Z4GE_COMPILER_APPLE_CLANG
#        define Z4GE_COMPILER_NAME "Apple Clang"
#    elif Z4GE_COMPILER & Z4GE_COMPILER_GCC
#        define Z4GE_COMPILER_NAME "GNU C Compiler Toolchain"
#    elif Z4GE_COMPILER & Z4GE_COMPILER_MSVC
#        define Z4GE_COMPILER_NAME "Microsoft Visual C/C++"
#    elif Z4GE_COMPILER & Z4GE_COMPILER_INTEL
#        define Z4GE_COMPILER_NAME "Intel C++ Compiler"
#    elif Z4GE_COMPILER & Z4GE_COMPILER_CUDA
#        define Z4GE_COMPILER_NAME "Nvidia CUDA C++ Compiler"
#    else
#        define Z4GE_COMPILER_NAME "Unknown"
#    endif
#endif

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @brief      Z4GE Host Platform Compiler Version
/// @details    This macro expands to the numerical representation of the
/// compiler version. The version scheme is different for
///             different compilers and cannot be used reliably for version
///             identification
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef Z4GE_COMPILER_VERSION
#    if Z4GE_COMPILER & (Z4GE_COMPILER_LLVM_CLANG | Z4GE_COMPILER_APPLE_CLANG)
#        define Z4GE_COMPILER_VERSION (__clang_major__ * 10000 + __clang_minor__ * 100 + __clang_patchlevel__)
#    elif Z4GE_COMPILER & Z4GE_COMPILER_GCC
#        define Z4GE_COMPILER_VERSION (__GNUC__ * 10000 + __GNUC_MINOR__ * 100 + __GNUC_PATCHLEVEL__)
#    elif Z4GE_COMPILER & Z4GE_COMPILER_MSVC
#        define Z4GE_COMPILER_VERSION _MSC_FULL_VER
#    elif Z4GE_COMPILER & Z4GE_COMPILER_INTEL
#        define Z4GE_COMPILER_VERSION __INTEL_COMPILER
#    elif Z4GE_COMPILER & Z4GE_COMPILER_CUDA
#        define Z4GE_COMPILER_VERSION CUDA_VERSION
#    else
#        define Z4GE_COMPILER_VERSION 0
#    endif
#endif

/// @brief      Z4GE Unknown platform
#define Z4GE_PLATFORM_UNKNOWN 0x00
/// @brief      Z4GE Microsoft Windows platform
#define Z4GE_PLATFORM_WINDOWS 0x01
/// @brief      Z4GE Cygwin (under Microsoft Windows) platform
#define Z4GE_PLATFORM_CYGWIN 0x02
/// @brief      Z4GE Linux platform
#define Z4GE_PLATFORM_LINUX 0x04
/// @brief      Z4GE UNIXs other than Linux platform
#define Z4GE_PLATFORM_UNIX 0x08
/// @brief      Z4GE Android platform
#define Z4GE_PLATFORM_ANDROID 0x10
/// @brief      Z4GE Apple MacOS platform
#define Z4GE_PLATFORM_MACOS 0x20

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @brief      Z4GE.Configuration Platform
/// @details    The host platform that was used to compile Z4GE.Configuration.
/// The following are the supported platforms
///             -#  Microsoft Windows
///             -#  Cygwin under Microsoft Windows
///             -#  Linux kernel
///             -#  Android
///             -#  Apple MacOS
///             -#  Other *Nix
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef Z4GE_PLATFORM
#    if defined(Z4GE_FORCE_UNKNOWN_PLATFORM)
#        define Z4GE_PLATFORM Z4GE_PLATFORM_UNKNOWN
#    elif defined(__CYGWIN__)
#        define Z4GE_PLATFORM Z4GE_PLATFORM_CYGWIN
#    elif defined(_WIN32) || defined(__WIN32) || defined(__WIN32__)
#        define Z4GE_PLATFORM Z4GE_PLATFORM_WINDOWS
#    elif defined(__ANDROID__)
#        define Z4GE_PLATFORM Z4GE_PLATFORM_ANDROID
#    elif defined(__linux) || defined(linux) || defined(__linux__)
#        define Z4GE_PLATFORM Z4GE_PLATFORM_LINUX
#    elif defined(__unix) || defined(__unix__)
#        define Z4GE_PLATFORM Z4GE_PLATFORM_UNIX
#    elif defined(__APPLE__)
#        define Z4GE_PLATFORM Z4GE_PLATFORM_APPLE
#    else
#        define Z4GE_PLATFORM Z4GE_PLATFORM_UNKNOWN
#    endif
#endif

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @brief      Z4GE.Configuration Platform Name
/// @details    This macro expands to a string which represents the formal name of the operating system according to
///             Z4GE.Configuration Package
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef Z4GE_PLATFORM_NAME
#    if Z4GE_PLATFORM & Z4GE_PLATFORM_WINDOWS
#        define Z4GE_PLATFORM_NAME "Microsoft Windows"
#    elif Z4GE_PLATFORM & Z4GE_PLATFORM_CYGWIN
#        define Z4GE_PLATFORM_NAME "Microsoft Windows under Cygwin"
#    elif Z4GE_PLATFORM & Z4GE_PLATFORM_LINUX
#        define Z4GE_PLATFORM_NAME "Linux"
#    elif Z4GE_PLATFORM & Z4GE_PLATFORM_UNIX
#        define Z4GE_PLATFORM_NAME "UNIX"
#    elif Z4GE_PLATFORM & Z4GE_PLATFORM_ANDROID
#        define Z4GE_PLATFORM_NAME "Android"
#    elif Z4GE_PLATFORM & Z4GE_PLATFORM_APPLE
#        define Z4GE_PLATFORM_NAME "Apple"
#    else
#        define Z4GE_PLATFORM_NAME "Unknown"
#    endif
#endif

///@brief       32 bit Architecture / Execution model
#define Z4GE_BUILD_MODEL_32 0x01
///@brief       64 bit Architecture / Execution model
#define Z4GE_BUILD_MODEL_64 0x02

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @brief      Execution model of the target platform
/// @details    This macro is a conditional compilation flag that identifies both 32 bit and 64 bit execution models.
///             This macro currently recognizes X86 and ARM processor models
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef Z4GE_BUILD_MODEL
#    if defined(_M_ARM64) || defined(__LP64__) || defined(_M_X64) || defined(__ppc64__) || defined(__x86_64__)
#        define Z4GE_BUILD_MODEL Z4GE_BUILD_MODEL_64
#    elif defined(__i386__) || defined(__ppc__) || defined(__ILP32__) || defined(_M_ARM)
#        define Z4GE_BUILD_MODEL Z4GE_BUILD_MODEL_32
#    else
#        define Z4GE_BUILD_MODEL Z4GE_BUILD_MODEL_32
#    endif
#endif

/// @brief      x86 Architecture
#define Z4GE_ARCHITECTURE_BIT_X86 0x0001
/// @brief      x86 - SSE SIMD
#define Z4GE_ARCHITECTURE_BIT_SSE 0x0002
/// @brief      x86 - SSE2 SIMD
#define Z4GE_ARCHITECTURE_BIT_SSE2 0x0004
/// @brief      x86 - SSE3 SIMD
#define Z4GE_ARCHITECTURE_BIT_SSE3 0x0010
/// @brief      x86 - SSSE3 SIMD
#define Z4GE_ARCHITECTURE_BIT_SSSE3 0x0020
/// @brief      x86 - SSE41 SIMD
#define Z4GE_ARCHITECTURE_BIT_SSE41 0x0040
/// @brief      x86 - SSE42 SIMD
#define Z4GE_ARCHITECTURE_BIT_SSE42 0x0080
/// @brief      x86 - AVX SIMD
#define Z4GE_ARCHITECTURE_BIT_AVX 0x0100
/// @brief      x86 - AVX2 SIMD
#define Z4GE_ARCHITECTURE_BIT_AVX2 0x0200
/// @brief      ARM Architecture
#define Z4GE_ARCHITECTURE_BIT_ARM 0x0400
/// @brief      ARM Neon
#define Z4GE_ARCHITECTURE_BIT_NEON 0x0800
/// @brief      ARM V8 Architecture
#define Z4GE_ARCHITECTURE_BIT_ARMV8 0x1000

///@brief       Unknown Architecture
#define Z4GE_ARCHITECTURE_UNKNOWN 0x0000
///@brief       x86 Architecture
#define Z4GE_ARCHITECTURE_X86 Z4GE_ARCHITECTURE_BIT_X86
///@brief       x86 + SSE
#define Z4GE_ARCHITECTURE_SSE Z4GE_ARCHITECTURE_X86 | Z4GE_ARCHITECTURE_BIT_SSE
///@brief       SSE + SSE2
#define Z4GE_ARCHITECTURE_SSE2 Z4GE_ARCHITECTURE_SSE | Z4GE_ARCHITECTURE_BIT_SSE2
///@brief       SSE2 + SSE3
#define Z4GE_ARCHITECTURE_SSE3 Z4GE_ARCHITECTURE_SSE2 | Z4GE_ARCHITECTURE_BIT_SSE3
///@brief       SSE3 + SSSE3
#define Z4GE_ARCHITECTURE_SSSE3 Z4GE_ARCHITECTURE_SSE3 | Z4GE_ARCHITECTURE_BIT_SSSE3
///@brief       SSSE3 + SSE41
#define Z4GE_ARCHITECTURE_SSE41 Z4GE_ARCHITECTURE_SSSE3 | Z4GE_ARCHITECTURE_BIT_SSE41
///@brief       SSE41 + SSE42
#define Z4GE_ARCHITECTURE_SSE42 Z4GE_ARCHITECTURE_SSE41 | Z4GE_ARCHITECTURE_BIT_SSE42
///@brief       SSE42 + AVX
#define Z4GE_ARCHITECTURE_AVX Z4GE_ARCHITECTURE_SSE42 | Z4GE_ARCHITECTURE_BIT_AVX
///@brief       AVX + AVX2
#define Z4GE_ARCHITECTURE_AVX2 Z4GE_ARCHITECTURE_AVX | Z4GE_ARCHITECTURE_BIT_AVX2
///@brief       ARM Architecture
#define Z4GE_ARCHITECTURE_ARM Z4GE_ARCHITECTURE_BIT_ARM
///@brief       ARM + ARM Neon
#define Z4GE_ARCHITECTURE_NEON Z4GE_ARCHITECTURE_ARM | Z4GE_ARCHITECTURE_BIT_NEON
///@brief       ARM Neon + ARMV8 Intrinsics
#define Z4GE_ARCHITECTURE_ARMV8 Z4GE_ARCHITECTURE_NEON | Z4GE_ARCHITECTURE_BIT_ARMV8

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @brief      Z4GE.Configuration Architecture
/// @details    The host platform architecture along with SIMD (Single Instruction Multiple Data) Intrinsics that were enabled
///             and expected to be supported by the target system. The following are the supported architectures and SIMD
///             Intrinsics
///             -#  x86 Architecture
///             -#  x86 Architecture + SSE
///             -#  x86 Architecture + SSE + SSE 2
///             -#  x86 Architecture + SSE + SSE 2 + SSE 3
///             -#  x86 Architecture + SSE + SSE 2 + SSE 3 + SSSE 3
///             -#  x86 Architecture + SSE + SSE 2 + SSE 3 + SSSE 3 + SSE 4.1
///             -#  x86 Architecture + SSE + SSE 2 + SSE 3 + SSSE 3 + SSE 4.1 + SSE 4.2
///             -#  x86 Architecture + SSE + SSE 2 + SSE 3 + SSSE 3 + SSE 4.1 + SSE 4.2 + AVX
///             -#  x86 Architecture + SSE + SSE 2 + SSE 3 + SSSE 3 + SSE 4.1 + SSE 4.2 + AVX + AVX 2
///             -#  ARM Architecture
///             -#  ARM Architecture + ARM Neon
///             -#  ARM Architecture + ARM Neon + ARM V8 Intrinsics
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef Z4GE_ARCHITECTURE
#    if defined(Z4GE_FORCE_UNKNOWN_ARCHITECTURE) || defined(Z4GE_NO_SIMD_INTRINSICS)
#        define Z4GE_ARCHITECTURE Z4GE_ARCHITECTURE_UNKNOWN
#    elif defined(Z4GE_FORCE_AVX2_INTRINSICS)
#        define Z4GE_ARCHITECTURE Z4GE_ARCHITECTURE_AVX2
#    elif defined(Z4GE_FORCE_AVX_INTRINSICS)
#        define Z4GE_ARCHITECTURE Z4GE_ARCHITECTURE_AVX
#    elif defined(Z4GE_FORCE_SSE42_INTRINSICS)
#        define Z4GE_ARCHITECTURE Z4GE_ARCHITECTURE_SSE42
#    elif defined(Z4GE_FORCE_SSE41_INTRINSICS)
#        define Z4GE_ARCHITECTURE Z4GE_ARCHITECTURE_SSE41
#    elif defined(Z4GE_FORCE_SSSE3_INTRINSICS)
#        define Z4GE_ARCHITECTURE Z4GE_ARCHITECTURE_SSSE3
#    elif defined(Z4GE_FORCE_SSE3_INTRINSICS)
#        define Z4GE_ARCHITECTURE Z4GE_ARCHITECTURE_SSE3
#    elif defined(Z4GE_FORCE_SSE2_INTRINSICS)
#        define Z4GE_ARCHITECTURE Z4GE_ARCHITECTURE_SSE2
#    elif defined(Z4GE_FORCE_SSE_INTRINSICS)
#        define Z4GE_ARCHITECTURE Z4GE_ARCHITECTURE_SSE
#    elif defined(Z4GE_FORCE_X86_INTRINSICS)
#        define Z4GE_ARCHITECTURE Z4GE_ARCHITECTURE_X86
#    elif defined(Z4GE_FORCE_ARMV8_INTRINSICS)
#        define Z4GE_ARCHITECTURE Z4GE_ARCHITECTURE_ARMV8
#    elif defined(Z4GE_FORCE_NEON_INTRINSICS)
#        define Z4GE_ARCHITECTURE Z4GE_ARCHITECTURE_NEON
#    elif defined(Z4GE_FORCE_ARM_INTRINSICS)
#        define Z4GE_ARCHITECTURE Z4GE_ARCHITECTURE_ARM
#    elif defined(Z4GE_FORCE_INTRINSICS)
#        if defined(__AVX2__)
#            define Z4GE_ARCHITECTURE Z4GE_ARCHITECTURE_AVX2
#        elif defined(__AVX__)
#            define Z4GE_ARCHITECTURE Z4GE_ARCHITECTURE_AVX
#        elif defined(__SSE4_2__)
#            define Z4GE_ARCHITECTURE Z4GE_ARCHITECTURE_SSE42
#        elif defined(__SSE4_1__)
#            define Z4GE_ARCHITECTURE Z4GE_ARCHITECTURE_SSE41
#        elif defined(__SSSE3__)
#            define Z4GE_ARCHITECTURE Z4GE_ARCHITECTURE_SSSE3
#        elif defined(__SSE3__)
#            define Z4GE_ARCHITECTURE Z4GE_ARCHITECTURE_SSE3
#        elif defined(__SSE2__) || defined(__x86_64__) || defined(_M_X64) || defined(_M_IX86_FP)
#            define Z4GE_ARCHITECTURE Z4GE_ARCHITECTURE_SSE2
#        elif defined(__i386__)
#            define Z4GE_ARCHITECTURE Z4GE_ARCHITECTURE_X86
#        elif defined(__ARM_ARCH) && (__ARM_ARCH >= 8)
#            define Z4GE_ARCHITECTURE Z4GE_ARCHITECTURE_ARMV8
#        elif defined(__ARM_NEON)
#            define Z4GE_ARCHITECTURE Z4GE_ARCHITECTURE_NEON
#        elif defined(__arm__) || defined(_M_ARM)
#            define Z4GE_ARCHITECTURE Z4GE_ARCHITECTURE_ARM
#        else
#            define Z4GE_ARCHITECTURE Z4GE_ARCHITECTURE_UNKNOWN
#        endif
#    else
#        if defined(__x86_64__) || defined(_M_X64) || defined(_M_IX86) || defined(__i386__)
#            define Z4GE_ARCHITECTURE Z4GE_ARCHITECTURE_X86
#        elif defined(__arm__) || defined(_M_ARM)
#            define Z4GE_ARCHITECTURE Z4GE_ARCHITECTURE_ARM
#        else
#            define Z4GE_ARCHITECTURE Z4GE_ARCHITECTURE_UNKNOWN
#        endif
#    endif
#endif

/// @}
/// @}
/// @endcond
#endif
