//  Z4GE.Configuration
//  Copyright 2022 DeathBllizzard
//
//  Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following
//  conditions are met:
//
//  1.  Redistributions of source code must retain the above copyright notice, this list of conditions and the following
//      disclaimer.Configuration
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
//  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
//  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
//  EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
#ifndef Z4GE_CONFIGURATION__COMPILER_TRAITS_HH_
#define Z4GE_CONFIGURATION__COMPILER_TRAITS_HH_

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @cond       build_developer_documentation
/// @file       Z4GE/Configuration/CompilerTraits.hh
/// @brief      Compiler and Language Traits Configuration
/// @details    This header contains macro definitions and conditional compilation macros that come in handy while configuring
///             Z4GE Packages in terms of Compiler and Language Traits Configuration
/// @note       This header file should not be directly included. If you wish to include this file, include
///             @ref Z4GE/Configuration.hh
/// @addtogroup z4ge_configuration
/// @{
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include <Z4GE/Configuration/Macros.hh>
#include <Z4GE/Configuration/Platform.hh>

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @brief      CXX 11 Standard Compliance
/// @details    This is a conditional compilation flag that represents whether the compiler is configured for CXX 11 standard.
///             This means that the compiler supports a minimal set of CXX 11 features and can be successfully built under
///             CXX 11 standard.
///
///             A list of conditional compilation flags that represent all the CXX 11 features that are currently taken into
///             account by the Z4GE.Configuration project are
///                 -#  @ref Z4GE_HAS_ALIGN_AS
///                 -#  @ref Z4GE_HAS_ALIGN_OF
///                 -#  @ref Z4GE_HAS_AUTO
///                 -#  @ref Z4GE_HAS_CONSTEXPR
///                 -#  @ref Z4GE_HAS_IF_CONSTEXPR
///                 -#  @ref Z4GE_HAS_DECLTYPE
///                 -#  @ref Z4GE_HAS_DEFAULTED_FUNCTIONS
///                 -#  @ref Z4GE_HAS_DEFAULT_FUNCTION_TEMPLATE_ARGUMENTS
///                 -#  @ref Z4GE_HAS_DELEGATING_CONSTRUCTORS
///                 -#  @ref Z4GE_HAS_DELETED_FUNCTIONS
///                 -#  @ref Z4GE_HAS_EXPLICIT_CONVERSION_OPERATORS
///                 -#  @ref Z4GE_HAS_EXTENDED_FRIEND_DECLARATIONS
///                 -#  @ref Z4GE_HAS_EXTENDED_SIZEOF
///                 -#  @ref Z4GE_HAS_EXTERN_TEMPLATES
///                 -#  @ref Z4GE_HAS_FORWARD_DECLARED_ENUMS
///                 -#  @ref Z4GE_HAS_INHERITANCE_FINAL
///                 -#  @ref Z4GE_HAS_INHERITING_CONSTRUCTORS
///                 -#  @ref Z4GE_HAS_INITIALIZER_LISTS
///                 -#  @ref Z4GE_HAS_INLINE_NAMESPACES
///                 -#  @ref Z4GE_HAS_LAMBDA_EXPRESSIONS
///                 -#  @ref Z4GE_HAS_LOCAL_CLASS_TEMPLATE_PARAMETERS
///                 -#  @ref Z4GE_HAS_NOEXCEPT
///                 -#  @ref Z4GE_HAS_NORETURN
///                 -#  @ref Z4GE_HAS_NONSTATIC_MEMBER_INITIALIZERS
///                 -#  @ref Z4GE_HAS_NULLPTR
///                 -#  @ref Z4GE_HAS_OVERRIDE
///                 -#  @ref Z4GE_HAS_RANGE_BASED_FOR_LOOPS
///                 -#  @ref Z4GE_HAS_RAW_LITERALS
///                 -#  @ref Z4GE_HAS_RIGHT_ANGLED_BRACKETS
///                 -#  @ref Z4GE_HAS_RVALUE_REFERENCES
///                 -#  @ref Z4GE_HAS_POD_RELAXATION
///                 -#  @ref Z4GE_HAS_STATIC_ASSERT
///                 -#  @ref Z4GE_HAS_STRONGLY_TYPED_ENUMS
///                 -#  @ref Z4GE_HAS_TEMPLATE_ALIASES
///                 -#  @ref Z4GE_HAS_TRAILING_RETURN_TYPES
///                 -#  @ref Z4GE_HAS_UNICODE_STRING_LITERALS
///                 -#  @ref Z4GE_HAS_UNIFORM_INITIALIZATION_SYNTAX
///                 -#  @ref Z4GE_HAS_UNRESTRICTED_UNIONS
///                 -#  @ref Z4GE_HAS_USER_LITERALS
///                 -#  @ref Z4GE_HAS_VARIADIC_TEMPLATES
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef Z4GE_CXX11_STANDARD_COMPLIANT
#    if defined(__cplusplus) && __cplusplus >= 201103L
#        define Z4GE_CXX11_STANDARD_COMPLIANT Z4GE_ENABLE
#    elif Z4GE_COMPILER & Z4GE_COMPILER_GCC && defined(__GXX_EXPERIMENTAL_CXX0X__)
#        define Z4GE_CXX11_STANDARD_COMPLIANT Z4GE_ENABLE
#    elif Z4GE_COMPILER & Z4GE_COMPILER_MSVC && Z4GE_COMPILER_VERSION >= 160000000
#        define Z4GE_CXX11_STANDARD_COMPLIANT Z4GE_ENABLE
#    else
#        define Z4GE_CXX11_STANDARD_COMPLIANT Z4GE_DISABLE
#    endif
#endif

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @brief      CXX 14 Standard Compliance
/// @details    This is a conditional compilation flag that represents whether the compiler is configured for CXX 14 standard.
///             This means that the compiler supports a minimal set of CXX 14 features and can be successfully built under
///             CXX 14 standard.
///
///             A list of conditional compilation flags that represent all the CXX 14 features that are currently taken into
///             account by the Z4GE.Configuration project are
///                 -#  @ref Z4GE_HAS_VARIABLE_TEMPLATES
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef Z4GE_CXX14_STANDARD_COMPLIANT
#    if defined(__cplusplus) && __cplusplus >= 201402L
#        define Z4GE_CXX14_STANDARD_COMPLIANT Z4GE_ENABLE
#    elif Z4GE_COMPILER & Z4GE_COMPILER_MSVC && Z4GE_COMPILER_VERSION >= 190000000
#        define Z4GE_CXX14_STANDARD_COMPLIANT Z4GE_ENABLE
#    else
#        define Z4GE_CXX14_STANDARD_COMPLIANT Z4GE_DISABLE
#    endif
#endif

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @brief      CXX 17 Standard Compliance
/// @details    This is a conditional compilation flag that represents whether the compiler is configured for CXX 17 standard.
///             This means that the compiler supports a minimal set of CXX 17 features and can be successfully built under
///             CXX 17 standard.
///
///             A list of conditional compilation flags that represent all the CXX 17 features that are currently taken into
///             account by the Z4GE.Configuration project are
///                 -#  @ref Z4GE_HAS_ALIGNED_NEW
///                 -#  @ref Z4GE_HAS_FALLTHROUGH_ATTRIBUTE
///                 -#  @ref Z4GE_HAS_MAYBE_UNUSED_ATTRIBUTE
///                 -#  @ref Z4GE_HAS_NODISCARD_ATTRIBUTE
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef Z4GE_CXX17_STANDARD_COMPLIANT
#    if defined(__cplusplus) && __cplusplus >= 201703L
#        define Z4GE_CXX17_STANDARD_COMPLIANT Z4GE_ENABLE
#    elif Z4GE_COMPILER & Z4GE_COMPILER_MSVC && defined(_MSVC_LANG) && (_MSVC_LANG >= 201703L)
#        define Z4GE_CXX17_STANDARD_COMPLIANT Z4GE_ENABLE
#    else
#        define Z4GE_CXX17_STANDARD_COMPLIANT Z4GE_DISABLE
#    endif
#endif

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @brief      Checks whether a given CXX attribute is supported by the compiler
/// @details    This macro makes use of the `__has_attribute` compiler macro to determine whether a given CXX attribute is
///             supported by the host compiler. If the compiler does not have `__has_attribute` or similar functionality
///             then this macro plainly evaluates to 0.
/// @param[in]  __ATTRIBUTE__   The CXX attribute
/// @return     1 if the CXX attribute @p __ATTRIBUTE__ is supported by the compiler
///             0 otherwise
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef Z4GE_HAS_ATTRIBUTE
#    if defined(__has_attribute)
#        define Z4GE_HAS_ATTRIBUTE(__ATTRIBUTE__) __has_attribute (__ATTRIBUTE__)
#    else
#        define Z4GE_HAS_ATTRIBUTE(__ATTRIBUTE__) 0
#    endif
#endif

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @brief      Checks whether a given CXX compiler builtin function is supported
/// @details    This macro makes use of the `__has_builtin` compiler macro to determine whether a given CXX CXX compiler builtin
///             is available. If the compiler does not have `__has_attribute` or similar functionality then this macro plainly
///             evaluates to 0.
/// @param[in]  __BUILTIN__ The CXX compiler builtin function
/// @return     1 if the CXX builtin @p __BUILTIN__ is available
///             0 otherwise
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef Z4GE_HAS_BUILTIN
#    if defined(__has_builtin)
#        define Z4GE_HAS_BUILTIN(__BUILTIN__) __has_builtin (__BUILTIN__)
#    else
#        define Z4GE_HAS_BUILTIN(__BUILTIN__) 0
#    endif
#endif

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @brief      Checks whether a given CXX feature is supported by the compiler
/// @details    This macro makes use of the `__has_feature` compiler macro to determine whether a given CXX feature is
///             supported by the host compiler. If the compiler does not have `__has_feature` or similar functionality
///             then this macro plainly evaluates to 0.
/// @param[in]  __FEATURE__ The CXX feature
/// @return     1 if the CXX feature @p __FEATURE__ is supported by the compiler
///             0 otherwise
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef Z4GE_HAS_FEATURE
#    if defined(__has_feature)
#        define Z4GE_HAS_FEATURE(__FEATURE__) __has_feature (__FEATURE__)
#    else
#        define Z4GE_HAS_FEATURE(__FEATURE__) 0
#    endif
#endif

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @brief      Checks whether a given CXX header is supported by the compiler
/// @details    This macro makes use of the `__has_include` compiler macro to determine whether a given CXX header file is
///             supported by the host compiler. If the compiler does not have `__has_feature` or similar functionality
///             then this macro plainly evaluates to 0.
/// @param[in]  __INCLUDE__ The CXX header file
/// @return     1 if the CXX feature @p __INCLUDE__ is supported by the compiler
///             0 otherwise
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef Z4GE_HAS_INCLUDE
#    if Z4GE_CXX17_STANDARD_COMPLIANT
#        define Z4GE_HAS_INCLUDE(__INCLUDE__) __has_include(__INCLUDE__)
#    else
#        if Z4GE_COMPILER & (Z4GE_COMPILER_APPLE_CLANG | Z4GE_COMPILER_LLVM_CLANG)
#            define Z4GE_HAS_INCLUDE(__INCLUDE__) __has_include(__INCLUDE__)
#        elif Z4GE_COMPILER & Z4GE_COMPILER_GCC
#            define Z4GE_HAS_INCLUDE(__INCLUDE__) __has_include(__INCLUDE__)
#        else
#            define Z4GE_HAS_INCLUDE(__INCLUDE__) 0
#        endif
#    endif
#endif


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @defgroup   cxx_compiler_feature_detection    CXX Compiler Feature Detection
/// @brief      CXX Compiler / Language Standard Specific Feature Detection
/// @details    These are a set of macros that detect features that are available on various platforms, compilers, language
///             standards in a platform/compiler/standard independent manner. These macros are used to define
///             @ref cxx_compiler_features_implementation "CXX Compiler Feature Identification" that
///             supported by a particular platform / compiler / CXX standard
/// @{
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @brief      Whether the CXX 11 alignas specifier is supported by the compiler
/// @details    This conditional compilation flags is set based on whether the `alignas` specifier is supported by the host
///             compiler. The conditional compilation flag is set under one of the following circumstances
///                 -#  __has_feature(cxx_alignas) evaluates to 1
///                 -#  Microsoft Visual C++ Version 1900 or higher (Visual Studio 2015 or higher)
///                 -#  Apple Clang Version 4.1 or higher
///                 -#  LLVM Clang Version 3.0 or higher
///                 -#  GCC Version 4.8 or higher
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef Z4GE_HAS_ALIGN_AS
#    if Z4GE_HAS_FEATURE(cxx_alignas)
#        define Z4GE_HAS_ALIGN_AS Z4GE_ENABLE
#    elif Z4GE_CXX11_STANDARD_COMPLIANT
#        if Z4GE_COMPILER & Z4GE_COMPILER_MSVC && Z4GE_COMPILER_VERSION >= 190000000
#            define Z4GE_HAS_ALIGN_AS Z4GE_ENABLE
#        elif Z4GE_COMPILER & Z4GE_COMPILER_APPLE_CLANG && Z4GE_COMPILER_VERSION >= 40100
#            define Z4GE_HAS_ALIGN_AS Z4GE_ENABLE
#        elif Z4GE_COMPILER & Z4GE_COMPILER_LLVM_CLANG && Z4GE_COMPILER_VERSION >= 30000
#            define Z4GE_HAS_ALIGN_AS Z4GE_ENABLE
#        elif Z4GE_COMPILER & Z4GE_COMPILER_GCC && Z4GE_COMPILER_VERSION >= 40800
#            define Z4GE_HAS_ALIGN_AS Z4GE_ENABLE
#        else
#            define Z4GE_HAS_ALIGN_AS Z4GE_DISABLE
#        endif
#    else
#        define Z4GE_HAS_ALIGN_AS Z4GE_DISABLE
#    endif
#endif

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @brief      Whether the CXX 11 alignof specifier is supported by the compiler
/// @details    This conditional compilation flags is set based on whether the `alignof` specifier is supported by the host
///             compiler. The conditional compilation flag is set under one of the following circumstances
///                 -#  __has_feature(cxx_alignof) evaluates to 1
///                 -#  Microsoft Visual C++ Version 1900 or higher (Visual Studio 2015 or higher)
///                 -#  Apple Clang and LLVM Clang Version 2.9 or higher
///                 -#  GCC Version 4.5 or higher
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef Z4GE_HAS_ALIGN_OF
#    if Z4GE_HAS_FEATURE(cxx_alignof)
#        define Z4GE_HAS_ALIGN_OF Z4GE_ENABLE
#    elif Z4GE_CXX11_STANDARD_COMPLIANT
#        if Z4GE_COMPILER & Z4GE_COMPILER_MSVC && Z4GE_COMPILER_VERSION >= 190000000
#            define Z4GE_HAS_ALIGN_OF Z4GE_ENABLE
#        elif Z4GE_COMPILER & (Z4GE_COMPILER_APPLE_CLANG | Z4GE_COMPILER_LLVM_CLANG) && Z4GE_COMPILER_VERSION >= 20900
#            define Z4GE_HAS_ALIGN_OF Z4GE_ENABLE
#        elif Z4GE_COMPILER & Z4GE_COMPILER_GCC && Z4GE_COMPILER_VERSION >= 40500
#            define Z4GE_HAS_ALIGN_OF Z4GE_ENABLE
#        else
#            define Z4GE_HAS_ALIGN_OF Z4GE_DISABLE
#        endif
#    else
#        define Z4GE_HAS_ALIGN_OF Z4GE_DISABLE
#    endif
#endif

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @brief      Whether the CXX 11 auto type deduction is supported by the compiler
/// @details    This conditional compilation flags is set based on whether the `automatic type deduction is supported by the
///             host compiler. The conditional compilation flag is set under one of the following circumstances
///                 -#  __has_feature(cxx_auto_type) evaluates to 1
///                 -#  Microsoft Visual C++ Version 1600 or higher (Visual Studio 2010 or higher)
///                 -#  Apple Clang and LLVM Clang Version 2.9 or higher
///                 -#  GCC Version 4.4 or higher
///
/// @par        Automatic Type Deduction
///             -#  For variables, the `auto` keyword specifies that the type of the variable is automatically deduced from its
///                 initializer.
///             -#  For functions, the `auto` keyword specfies that the return type of the function is deduced from the return
///                 statements present within the function's body.
///             -#  For non-type template arguments, the `auto` keyword specifies that the type of the argument is deduced from
///                 from the argument.
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef Z4GE_HAS_AUTO
#    if Z4GE_HAS_FEATURE(cxx_auto_type)
#        define Z4GE_HAS_AUTO Z4GE_ENABLE
#    elif Z4GE_CXX11_STANDARD_COMPLIANT
#        if Z4GE_COMPILER & Z4GE_COMPILER_MSVC && Z4GE_COMPILER_VERSION >= 160000000
#            define Z4GE_HAS_AUTO Z4GE_ENABLE
#        elif Z4GE_COMPILER & (Z4GE_COMPILER_APPLE_CLANG | Z4GE_COMPILER_LLVM_CLANG) && Z4GE_COMPILER_VERSION >= 20900
#            define Z4GE_HAS_AUTO Z4GE_ENABLE
#        elif Z4GE_COMPILER & Z4GE_COMPILER_GCC && Z4GE_COMPILER_VERSION >= 40400
#            define Z4GE_HAS_AUTO Z4GE_ENABLE
#        else
#            define Z4GE_HAS_AUTO Z4GE_DISABLE
#        endif
#    else
#        define Z4GE_HAS_AUTO Z4GE_DISABLE
#    endif
#endif

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @brief      Whether the CXX 11 `constexpr`s are supported by the compiler
/// @details    This conditional compilation flags is set based on whether the constant expressions (`constexpr`) are supported
///             by the host compiler. The conditional compilation flag is set under one of the following circumstances
///                 -#  __has_feature(cxx_alignof) evaluates to 1
///                 -#  Microsoft Visual C++ Version 1900 or higher (Visual Studio 2015 or higher)
///                 -#  Apple Clang and LLVM Clang Version 3.1 or higher
///                 -#  GCC Version 4.6 or higher
///
/// @par        Constant Expressions
///             The `constexpr` specifies that it is possible to to evaluate the value of the function or a given variable ath
///             the compile time. Such variables and functions can be used later where only compile time constants are allowed.
///             The following requirements are to be satisfied inorder to make a `constexpr` variable:
///                 -#  It must be a literal type
///                 -#  It must be immediately initialized
///                 -#  The full-expression of its initialization including all implicit conversions, constructor calls must be
///                     constant expressions
///             The following requirements are to be satisfied inorder to make a `constexpr` function:
///                 -#  It must not be a virtual function
///                 -#  Its return type (if any) and its parameters should be literal type
///                 -#  In case of constructors, the class must not have any virtual base classes
///                 -#  The function of the body must not be a function-try block
///                 -#  The function body must not contain:
///                     -#  A `goto` statement
///                     -#  A `try` block
///                     -#  An ASM declaration
///                     -#  A definition of a variable for which initialization id not performed
///                     -#  A definition of a variable of non-literal type
///                     -#  A definition of a variable of `static` or `thread` storage duration
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef Z4GE_HAS_CONSTEXPR
#    if Z4GE_HAS_FEATURE(cxx_constexpr)
#        define Z4GE_HAS_CONSTEXPR Z4GE_ENABLE
#    elif Z4GE_CXX11_STANDARD_COMPLIANT
#        if Z4GE_COMPILER & Z4GE_COMPILER_MSVC && Z4GE_COMPILER_VERSION >= 190000000
#            define Z4GE_HAS_CONSTEXPR Z4GE_ENABLE
#        elif Z4GE_COMPILER & (Z4GE_COMPILER_APPLE_CLANG | Z4GE_COMPILER_LLVM_CLANG) && Z4GE_COMPILER_VERSION >= 30100
#            define Z4GE_HAS_CONSTEXPR Z4GE_ENABLE
#        elif Z4GE_COMPILER & Z4GE_COMPILER_GCC && Z4GE_COMPILER_VERSION >= 40600
#            define Z4GE_HAS_CONSTEXPR Z4GE_ENABLE
#        else
#            define Z4GE_HAS_CONSTEXPR Z4GE_DISABLE
#        endif
#    else
#        define Z4GE_HAS_CONSTEXPR Z4GE_DISABLE
#    endif
#endif

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @brief      Whether the CXX 11 `decltype`s are supported by the compiler
/// @details    This conditional compilation flags is set based on whether `decltype`s are supported by the host compiler.
///             The conditional compilation flag is set under one of the
///             following circumstances
///                 -#  __has_feature(cxx_decltype) evaluates to 1
///                 -#  Microsoft Visual C++ Version 1611 or higher (Visual Studio 2010 or higher)
///                 -#  Apple Clang and LLVM Clang Version 2.9 or higher
///                 -#  GCC Version 4.3 or higher
///
/// @par        If Constant Expressions
///             In a constexpr if statement, the value of condition must be a contextually converted constant expression of
///             type `bool`. If the value is `true`, then statement-false is discarded (if present), otherwise,
///             statement-true is discarded. The return statements in a discarded statement do not participate in function
///             return type deduction
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef Z4GE_HAS_DECLTYPE
#    if Z4GE_HAS_FEATURE(cxx_decltype)
#        define Z4GE_HAS_DECLTYPE Z4GE_ENABLE
#    elif Z4GE_CXX11_STANDARD_COMPLIANT
#        if Z4GE_COMPILER & Z4GE_COMPILER_MSVC && Z4GE_COMPILER_VERSION >= 160000000
#            define Z4GE_HAS_DECLTYPE Z4GE_ENABLE
#        elif Z4GE_COMPILER & (Z4GE_COMPILER_APPLE_CLANG | Z4GE_COMPILER_LLVM_CLANG) && Z4GE_COMPILER_VERSION >= 20900
#            define Z4GE_HAS_DECLTYPE Z4GE_ENABLE
#        elif Z4GE_COMPILER & Z4GE_COMPILER_GCC && Z4GE_COMPILER_VERSION >= 40300
#            define Z4GE_HAS_DECLTYPE Z4GE_ENABLE
#        else
#            define Z4GE_HAS_DECLTYPE Z4GE_DISABLE
#        endif
#    else
#        define Z4GE_HAS_DECLTYPE Z4GE_DISABLE
#    endif
#endif

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @brief      Whether the CXX 11 `default`ed member functions are supported by the compiler
/// @details    This conditional compilation flags is set based on whether `default`ed  member functions are
///             supported by the host compiler. The conditional compilation flag is set under one of the following circumstances
///                 -#  __has_feature(cxx_defaulted_functions) evaluates to 1
///                 -#  Microsoft Visual C++ Version 1800 or higher (Visual Studio 2013 or higher)
///                 -#  Apple Clang and LLVM Clang Version 3.0 or higher
///                 -#  GCC Version 4.4 or higher
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef Z4GE_HAS_DEFAULTED_FUNCTIONS
#    if Z4GE_HAS_FEATURE(cxx_defaulted_functions)
#        define Z4GE_HAS_DEFAULTED_FUNCTIONS Z4GE_ENABLE
#    elif Z4GE_CXX11_STANDARD_COMPLIANT
#        if Z4GE_COMPILER & Z4GE_COMPILER_MSVC && Z4GE_COMPILER_VERSION >= 180000000
#            define Z4GE_HAS_DEFAULTED_FUNCTIONS Z4GE_ENABLE
#        elif Z4GE_COMPILER & (Z4GE_COMPILER_APPLE_CLANG | Z4GE_COMPILER_LLVM_CLANG) && Z4GE_COMPILER_VERSION >= 30000
#            define Z4GE_HAS_DEFAULTED_FUNCTIONS Z4GE_ENABLE
#        elif Z4GE_COMPILER & Z4GE_COMPILER_GCC && Z4GE_COMPILER_VERSION >= 40400
#            define Z4GE_HAS_DEFAULTED_FUNCTIONS Z4GE_ENABLE
#        else
#            define Z4GE_HAS_DEFAULTED_FUNCTIONS Z4GE_DISABLE
#        endif
#    else
#        define Z4GE_HAS_DEFAULTED_FUNCTIONS Z4GE_DISABLE
#    endif
#endif

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @brief      Whether the CXX 11 `default`ed function temmplate arguments are supported by the compiler
/// @details    This conditional compilation flags is set based on whether default`ed function temmplate arguments are
///             supported by the host compiler. The conditional compilation flag is set under one of the following circumstances
///                 -#  __has_feature(cxx_default_function_template_args) evaluates to 1
///                 -#  Microsoft Visual C++ Version 1700 or higher (Visual Studio 2012 or higher)
///                 -#  Apple Clang Version 4.1 or higher
///                 -#  LLVM Clang Version 3.0 or higher
///                 -#  GCC Version 4.6 or higher
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef Z4GE_HAS_DEFAULT_FUNCTION_TEMPLATE_ARGUMENTS
#    if Z4GE_HAS_FEATURE(cxx_default_function_template_args)
#        define Z4GE_HAS_DEFAULT_FUNCTION_TEMPLATE_ARGUMENTS Z4GE_ENABLE
#    elif Z4GE_CXX11_STANDARD_COMPLIANT
#        if Z4GE_COMPILER & Z4GE_COMPILER_MSVC && (Z4GE_COMPILER_VERSION >= 170000000)
#            define Z4GE_HAS_DEFAULT_FUNCTION_TEMPLATE_ARGUMENTS Z4GE_ENABLE
#        elif Z4GE_COMPILER & Z4GE_COMPILER_APPLE_CLANG && Z4GE_COMPILER_VERSION >= 40100
#            define Z4GE_HAS_DEFAULT_FUNCTION_TEMPLATE_ARGUMENTS Z4GE_ENABLE
#        elif Z4GE_COMPILER & Z4GE_COMPILER_LLVM_CLANG && Z4GE_COMPILER_VERSION >= 30100
#            define Z4GE_HAS_DEFAULT_FUNCTION_TEMPLATE_ARGUMENTS Z4GE_ENABLE
#        elif Z4GE_COMPILER & Z4GE_COMPILER_GCC && Z4GE_COMPILER_VERSION >= 40600
#            define Z4GE_HAS_DEFAULT_FUNCTION_TEMPLATE_ARGUMENTS Z4GE_ENABLE
#        else
#            define Z4GE_HAS_DEFAULT_FUNCTION_TEMPLATE_ARGUMENTS Z4GE_DISABLE
#        endif
#    else
#        define Z4GE_HAS_DEFAULT_FUNCTION_TEMPLATE_ARGUMENTS Z4GE_DISABLE
#    endif
#endif

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @brief      Whether the CXX 11 constructor delegations are supported by the compiler
/// @details    This conditional compilation flags is set based on whether constructor delegations are supported by the host
///             compiler. The conditional compilation flag is set under one of the following circumstances
///                 -#  __has_feature(cxx_delegating_constructors) evaluates to 1
///                 -#  Microsoft Visual C++ Version 1800 or higher (Visual Studio 2013 or higher)
///                 -#  Apple Clang Version 4.1 or higher
///                 -#  LLVM Clang Version 3.0 or higher
///                 -#  GCC Version 4.7 or higher
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef Z4GE_HAS_DELEGATING_CONSTRUCTORS
#    if Z4GE_HAS_FEATURE(cxx_delegating_constructors)
#        define Z4GE_HAS_DELEGATING_CONSTRUCTORS Z4GE_ENABLE
#    elif Z4GE_CXX11_STANDARD_COMPLIANT
#        if Z4GE_COMPILER & Z4GE_COMPILER_MSVC && Z4GE_COMPILER_VERSION >= 180000000
#            define Z4GE_HAS_DELEGATING_CONSTRUCTORS Z4GE_ENABLE
#        elif Z4GE_COMPILER & Z4GE_COMPILER_APPLE_CLANG && Z4GE_COMPILER_VERSION >= 40100
#            define Z4GE_HAS_DELEGATING_CONSTRUCTORS Z4GE_ENABLE
#        elif Z4GE_COMPILER & Z4GE_COMPILER_LLVM_CLANG && Z4GE_COMPILER_VERSION >= 30000
#            define Z4GE_HAS_DELEGATING_CONSTRUCTORS Z4GE_ENABLE
#        elif Z4GE_COMPILER & Z4GE_COMPILER_GCC && Z4GE_COMPILER_VERSION >= 40700
#            define Z4GE_HAS_DELEGATING_CONSTRUCTORS Z4GE_ENABLE
#        else
#            define Z4GE_HAS_DELEGATING_CONSTRUCTORS Z4GE_DISABLE
#        endif
#    else
#        define Z4GE_HAS_DELEGATING_CONSTRUCTORS Z4GE_DISABLE
#    endif
#endif

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @brief      Whether the CXX 11 `deelte`ed member functions are supported by the compiler
/// @details    This conditional compilation flags is set based on whether `deelte`ed  member functions are
///             supported by the host compiler. The conditional compilation flag is set under one of the following circumstances
///                 -#  __has_feature(cxx_deleted_functions) evaluates to 1
///                 -#  Microsoft Visual C++ Version 1800 or higher (Visual Studio 2013 or higher)
///                 -#  Apple Clang and LLVM Clang Version 2.9 or higher
///                 -#  GCC Version 4.4 or higher
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef Z4GE_HAS_DELETED_FUNCTIONS
#    if Z4GE_HAS_FEATURE(cxx_deleted_functions)
#        define Z4GE_HAS_DELETED_FUNCTIONS Z4GE_ENABLE
#    elif Z4GE_CXX11_STANDARD_COMPLIANT
#        if Z4GE_COMPILER & Z4GE_COMPILER_MSVC && Z4GE_COMPILER_VERSION >= 180000000
#            define Z4GE_HAS_DELETED_FUNCTIONS Z4GE_ENABLE
#        elif Z4GE_COMPILER & (Z4GE_COMPILER_APPLE_CLANG | Z4GE_COMPILER_LLVM_CLANG) && Z4GE_COMPILER_VERSION >= 20900
#            define Z4GE_HAS_DELETED_FUNCTIONS Z4GE_ENABLE
#        elif Z4GE_COMPILER & Z4GE_COMPILER_GCC && Z4GE_COMPILER_VERSION >= 40400
#            define Z4GE_HAS_DELETED_FUNCTIONS Z4GE_ENABLE
#        else
#            define Z4GE_HAS_DELETED_FUNCTIONS Z4GE_DISABLE
#        endif
#    else
#        define Z4GE_HAS_DELETED_FUNCTIONS Z4GE_DISABLE
#    endif
#endif

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @brief      Whether the CXX 11 explicit conversion operators are supported by the compiler
/// @details    This conditional compilation flags is set based on whether explicit conversion operators are supported by the
///             host compiler. The conditional compilation flag is set under one of the following circumstances
///                 -#  __has_feature(cxx_explicit_conversions) evaluates to 1
///                 -#  Microsoft Visual C++ Version 1800 or higher (Visual Studio 2013 or higher)
///                 -#  Apple Clang Version 4.1 or higher
///                 -#  LLVM Clang Version 3.0 or higher
///                 -#  GCC Version 4.5 or higher
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef Z4GE_HAS_EXPLICIT_CONVERSION_OPERATORS
#    if Z4GE_HAS_FEATURE(cxx_explicit_conversions)
#        define Z4GE_HAS_EXPLICIT_CONVERSION_OPERATORS Z4GE_ENABLE
#    elif Z4GE_CXX11_STANDARD_COMPLIANT
#        if Z4GE_COMPILER & Z4GE_COMPILER_MSVC && (Z4GE_COMPILER_VERSION >= 180000000 || Z4GE_COMPILER_VERSION == 170051025)
#            define Z4GE_HAS_EXPLICIT_CONVERSION_OPERATORS Z4GE_ENABLE
#        elif Z4GE_COMPILER & Z4GE_COMPILER_APPLE_CLANG && Z4GE_COMPILER_VERSION >= 40100
#            define Z4GE_HAS_EXPLICIT_CONVERSION_OPERATORS Z4GE_ENABLE
#        elif Z4GE_COMPILER & Z4GE_COMPILER_LLVM_CLANG && Z4GE_COMPILER_VERSION >= 30000
#            define Z4GE_HAS_EXPLICIT_CONVERSION_OPERATORS Z4GE_ENABLE
#        elif Z4GE_COMPILER & Z4GE_COMPILER_GCC && Z4GE_COMPILER_VERSION >= 40500
#            define Z4GE_HAS_EXPLICIT_CONVERSION_OPERATORS Z4GE_ENABLE
#        else
#            define Z4GE_HAS_EXPLICIT_CONVERSION_OPERATORS Z4GE_DISABLE
#        endif
#    else
#        define Z4GE_HAS_EXPLICIT_CONVERSION_OPERATORS Z4GE_DISABLE
#    endif
#endif

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @brief      Whether the CXX 11 extended friend declarations are supported by the compiler
/// @details    This conditional compilation flags is set based on whether extended friend declarations are supported by the
///             host compiler. The conditional compilation flag is set under one of the following circumstances
///                 -#  __has_feature(cxx_extended_friend_declarations) evaluates to 1
///                 -#  Microsoft Visual C++ Version 1600 or higher (Visual Studio 2010 or higher)
///                 -#  Apple Clang or LLVM Clang Version 2.9 or higher
///                 -#  GCC Version 4.7 or higher
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef Z4GE_HAS_EXTENDED_FRIEND_DECLARATIONS
#    if Z4GE_HAS_FEATURE(cxx_extended_friend_declarations)
#        define Z4GE_HAS_EXTENDED_FRIEND_DECLARATIONS Z4GE_ENABLE
#    elif Z4GE_CXX11_STANDARD_COMPLIANT
#        if Z4GE_COMPILER & Z4GE_COMPILER_MSVC && (Z4GE_COMPILER_VERSION >= 160000000)
#            define Z4GE_HAS_EXTENDED_FRIEND_DECLARATIONS Z4GE_ENABLE
#        elif Z4GE_COMPILER & (Z4GE_COMPILER_APPLE_CLANG | Z4GE_COMPILER_LLVM_CLANG) && Z4GE_COMPILER_VERSION >= 20900
#            define Z4GE_HAS_EXTENDED_FRIEND_DECLARATIONS Z4GE_ENABLE
#        elif Z4GE_COMPILER & Z4GE_COMPILER_GCC && Z4GE_COMPILER_VERSION >= 40700
#            define Z4GE_HAS_EXTENDED_FRIEND_DECLARATIONS Z4GE_ENABLE
#        else
#            define Z4GE_HAS_EXTENDED_FRIEND_DECLARATIONS Z4GE_DISABLE
#        endif
#    else
#        define Z4GE_HAS_EXTENDED_FRIEND_DECLARATIONS Z4GE_DISABLE
#    endif
#endif

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @brief      Whether the CXX 11 sizeof for class / struct members are supported by the compiler
/// @details    This conditional compilation flags is set based on whether sizeof for class / struct members are supported by
///             the host compiler. The conditional compilation flag is set under one of the following circumstances
///                 -#  __has_feature(cxx_sizeof_member) evaluates to 1
///                 -#  Microsoft Visual C++ Version 1900 or higher (Visual Studio 2015 or higher)
///                 -#  Apple Clang Version 4.1 or higher
///                 -#  LLVM Clang Version 3.1 or higher
///                 -#  GCC Version 4.5 or higher
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef Z4GE_HAS_EXTENDED_SIZEOF
#    if Z4GE_HAS_FEATURE(cxx_sizeof_member)
#        define Z4GE_HAS_EXTENDED_SIZEOF Z4GE_ENABLE
#    elif Z4GE_CXX11_STANDARD_COMPLIANT
#        if Z4GE_COMPILER & Z4GE_COMPILER_MSVC && (Z4GE_COMPILER_VERSION >= 190000000)
#            define Z4GE_HAS_EXTENDED_SIZEOF Z4GE_ENABLE
#        elif Z4GE_COMPILER & Z4GE_COMPILER_APPLE_CLANG && Z4GE_COMPILER_VERSION >= 40100
#            define Z4GE_HAS_EXTENDED_SIZEOF Z4GE_ENABLE
#        elif Z4GE_COMPILER & Z4GE_COMPILER_LLVM_CLANG && Z4GE_COMPILER_VERSION >= 30100
#            define Z4GE_HAS_EXTENDED_SIZEOF Z4GE_ENABLE
#        elif Z4GE_COMPILER & Z4GE_COMPILER_GCC && Z4GE_COMPILER_VERSION >= 40500
#            define Z4GE_HAS_EXTENDED_SIZEOF Z4GE_ENABLE
#        else
#            define Z4GE_HAS_EXTENDED_SIZEOF Z4GE_DISABLE
#        endif
#    else
#        define Z4GE_HAS_EXTENDED_SIZEOF Z4GE_DISABLE
#    endif
#endif

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @brief      Whether the CXX 11 `extern template` declarations are supported by the compiler
/// @details    This conditional compilation flags is set based on whether sizeof for `extern template` declarations are
///             supported by the host compiler. The conditional compilation flag is set under one of the following circumstances
///                 -#  __has_feature(cxx_extern_templates) evaluates to 1
///                 -#  Microsoft Visual C++ Version 1900 or higher (Visual Studio 2015 or higher)
///                 -#  Apple Clang Version 4.1 or higher
///                 -#  LLVM Clang Version 3.1 or higher
///                 -#  GCC Version 4.5 or higher
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef Z4GE_HAS_EXTERN_TEMPLATES
#    if Z4GE_HAS_FEATURE(cxx_extern_templates)
#        define Z4GE_HAS_EXTERN_TEMPLATES Z4GE_ENABLE
#    elif Z4GE_CXX11_STANDARD_COMPLIANT
#        if Z4GE_COMPILER & Z4GE_COMPILER_MSVC && (Z4GE_COMPILER_VERSION >= 190000000)
#            define Z4GE_HAS_EXTERN_TEMPLATES Z4GE_ENABLE
#        elif Z4GE_COMPILER & Z4GE_COMPILER_APPLE_CLANG && Z4GE_COMPILER_VERSION >= 40100
#            define Z4GE_HAS_EXTERN_TEMPLATES Z4GE_ENABLE
#        elif Z4GE_COMPILER & Z4GE_COMPILER_LLVM_CLANG && Z4GE_COMPILER_VERSION >= 30100
#            define Z4GE_HAS_EXTERN_TEMPLATES Z4GE_ENABLE
#        elif Z4GE_COMPILER & Z4GE_COMPILER_GCC && Z4GE_COMPILER_VERSION >= 40500
#            define Z4GE_HAS_EXTERN_TEMPLATES Z4GE_ENABLE
#        else
#            define Z4GE_HAS_EXTERN_TEMPLATES Z4GE_DISABLE
#        endif
#    else
#        define Z4GE_HAS_EXTERN_TEMPLATES Z4GE_DISABLE
#    endif
#endif

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @brief      Whether the CXX 11 `extern template` declarations are supported by the compiler
/// @details    This conditional compilation flags is set based on whether `extern template` declarations are supported by the
///             host compiler. The conditional compilation flag is set under one of the following circumstances
///                 -#  __has_feature(cxx_enum_forward_declarations) evaluates to 1
///                 -#  Microsoft Visual C++ Version 1700 or higher (Visual Studio 2012 or higher)
///                 -#  Apple Clang Version 4.1 or higher
///                 -#  LLVM Clang Version 3.1 or higher
///                 -#  GCC Version 4.6 or higher
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef Z4GE_HAS_FORWARD_DECLARED_ENUMS
#    if Z4GE_HAS_FEATURE(cxx_enum_forward_declarations)
#        define Z4GE_HAS_FORWARD_DECLARED_ENUMS Z4GE_ENABLE
#    elif Z4GE_CXX11_STANDARD_COMPLIANT
#        if Z4GE_COMPILER & Z4GE_COMPILER_MSVC && (Z4GE_COMPILER_VERSION >= 170000000)
#            define Z4GE_HAS_FORWARD_DECLARED_ENUMS Z4GE_ENABLE
#        elif Z4GE_COMPILER & Z4GE_COMPILER_APPLE_CLANG && Z4GE_COMPILER_VERSION >= 40100
#            define Z4GE_HAS_FORWARD_DECLARED_ENUMS Z4GE_ENABLE
#        elif Z4GE_COMPILER & Z4GE_COMPILER_LLVM_CLANG && Z4GE_COMPILER_VERSION >= 30100
#            define Z4GE_HAS_FORWARD_DECLARED_ENUMS Z4GE_ENABLE
#        elif Z4GE_COMPILER & Z4GE_COMPILER_GCC && Z4GE_COMPILER_VERSION >= 40600
#            define Z4GE_HAS_FORWARD_DECLARED_ENUMS Z4GE_ENABLE
#        else
#            define Z4GE_HAS_FORWARD_DECLARED_ENUMS Z4GE_DISABLE
#        endif
#    else
#        define Z4GE_HAS_FORWARD_DECLARED_ENUMS Z4GE_DISABLE
#    endif
#endif

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @brief      Whether the CXX 11 `final` in inheritance declaration supported by the compiler
/// @details    This conditional compilation flags is set based on whether `final` in inheritance declaration are supported by
///             the host compiler. The conditional compilation flag is set under one of the following circumstances
///                 -#  __has_feature(cxx_final) evaluates to 1
///                 -#  Microsoft Visual C++ Version 1500 or higher (Visual Studio 2008 or higher)
///                 -#  Apple Clang or LLVM Clang Version 2.9 or higher
///                 -#  GCC Version 4.7 or higher
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef Z4GE_HAS_INHERITANCE_FINAL
#    if Z4GE_HAS_FEATURE(cxx_final)
#        define Z4GE_HAS_INHERITANCE_FINAL Z4GE_ENABLE
#    elif Z4GE_CXX11_STANDARD_COMPLIANT
#        if Z4GE_COMPILER & Z4GE_COMPILER_MSVC && (Z4GE_COMPILER_VERSION >= 150000000)
#            define Z4GE_HAS_INHERITANCE_FINAL Z4GE_ENABLE
#        elif Z4GE_COMPILER & (Z4GE_COMPILER_APPLE_CLANG | Z4GE_COMPILER_LLVM_CLANG) && Z4GE_COMPILER_VERSION >= 20900
#            define Z4GE_HAS_INHERITANCE_FINAL Z4GE_ENABLE
#        elif Z4GE_COMPILER & Z4GE_COMPILER_GCC && Z4GE_COMPILER_VERSION >= 40700
#            define Z4GE_HAS_INHERITANCE_FINAL Z4GE_ENABLE
#        else
#            define Z4GE_HAS_INHERITANCE_FINAL Z4GE_DISABLE
#        endif
#    else
#        define Z4GE_HAS_INHERITANCE_FINAL Z4GE_DISABLE
#    endif
#endif

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @brief      Whether the CXX 11 constructor inheritance declaration supported by the compiler
/// @details    This conditional compilation flags is set based on whether `final` in inheritance declaration are supported by
///             the host compiler. The conditional compilation flag is set under one of the following circumstances
///                 -#  __has_feature(cxx_inheriting_constructors) evaluates to 1
///                 -#  Microsoft Visual C++ Version 1900 or higher (Visual Studio 2015 or higher)
///                 -#  GCC Version 4.8 or higher
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef Z4GE_HAS_INHERITING_CONSTRUCTORS
#    if Z4GE_HAS_FEATURE(cxx_inheriting_constructors)
#        define Z4GE_HAS_INHERITING_CONSTRUCTORS Z4GE_ENABLE
#    elif Z4GE_CXX11_STANDARD_COMPLIANT
#        if Z4GE_COMPILER & Z4GE_COMPILER_MSVC && (Z4GE_COMPILER_VERSION >= 190000000)
#            define Z4GE_HAS_INHERITING_CONSTRUCTORS Z4GE_ENABLE
#        elif Z4GE_COMPILER & Z4GE_COMPILER_GCC && Z4GE_COMPILER_VERSION >= 40800
#            define Z4GE_HAS_INHERITING_CONSTRUCTORS Z4GE_ENABLE
#        else
#            define Z4GE_HAS_INHERITING_CONSTRUCTORS Z4GE_DISABLE
#        endif
#    else
#        define Z4GE_HAS_INHERITING_CONSTRUCTORS Z4GE_DISABLE
#    endif
#endif

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @brief      Whether the CXX 11 initializer lists are supported by the compiler
/// @details    This conditional compilation flags is set based on whether initializer lists are supported by the
///             host compiler. The conditional compilation flag is set under one of the following circumstances
///                 -#  __has_feature(cxx_generalized_initializers) evaluates to 1
///                 -#  Microsoft Visual C++ Version 1800 or higher (Visual Studio 2013 or higher)
///                 -#  Apple Clang Version 4.1 or higher
///                 -#  LLVM Clang Version 3.1 or higher
///                 -#  GCC Version 4.4 or higher
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef Z4GE_HAS_INITIALIZER_LISTS
#    if Z4GE_HAS_FEATURE(cxx_generalized_initializers)
#        define Z4GE_HAS_INITIALIZER_LISTS Z4GE_ENABLE
#    elif Z4GE_CXX11_STANDARD_COMPLIANT
#        if Z4GE_COMPILER & Z4GE_COMPILER_MSVC && (Z4GE_COMPILER_VERSION >= 180000000)
#            define Z4GE_HAS_INITIALIZER_LISTS Z4GE_ENABLE
#        elif Z4GE_COMPILER & Z4GE_COMPILER_APPLE_CLANG && Z4GE_COMPILER_VERSION >= 40100
#            define Z4GE_HAS_INITIALIZER_LISTS Z4GE_ENABLE
#        elif Z4GE_COMPILER & Z4GE_COMPILER_LLVM_CLANG && Z4GE_COMPILER_VERSION >= 30100
#            define Z4GE_HAS_INITIALIZER_LISTS Z4GE_ENABLE
#        elif Z4GE_COMPILER & Z4GE_COMPILER_GCC && Z4GE_COMPILER_VERSION >= 40400
#            define Z4GE_HAS_INITIALIZER_LISTS Z4GE_ENABLE
#        else
#            define Z4GE_HAS_INITIALIZER_LISTS Z4GE_DISABLE
#        endif
#    else
#        define Z4GE_HAS_INITIALIZER_LISTS Z4GE_DISABLE
#    endif
#endif

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @brief      Whether the CXX 11 `inline`-able namespaces are supported by the compiler
/// @details    This conditional compilation flags is set based on whether `inline`-able namespaces are supported by the
///             host compiler. The conditional compilation flag is set under one of the following circumstances
///                 -#  __has_feature(cxx_inline_namespaces) evaluates to 1
///                 -#  Microsoft Visual C++ Version 1900 or higher (Visual Studio 2015 or higher)
///                 -#  Apple Clang Version 4.1 or higher
///                 -#  LLVM Clang Version 3.1 or higher
///                 -#  GCC Version 4.5 or higher
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef Z4GE_HAS_INLINE_NAMESPACES
#    if Z4GE_HAS_FEATURE(cxx_inline_namespaces)
#        define Z4GE_HAS_INLINE_NAMESPACES Z4GE_ENABLE
#    elif Z4GE_CXX11_STANDARD_COMPLIANT
#        if Z4GE_COMPILER & Z4GE_COMPILER_MSVC && (Z4GE_COMPILER_VERSION >= 190000000)
#            define Z4GE_HAS_INLINE_NAMESPACES Z4GE_ENABLE
#        elif Z4GE_COMPILER & Z4GE_COMPILER_APPLE_CLANG && Z4GE_COMPILER_VERSION >= 40100
#            define Z4GE_HAS_INLINE_NAMESPACES Z4GE_ENABLE
#        elif Z4GE_COMPILER & Z4GE_COMPILER_LLVM_CLANG && Z4GE_COMPILER_VERSION >= 30100
#            define Z4GE_HAS_INLINE_NAMESPACES Z4GE_ENABLE
#        elif Z4GE_COMPILER & Z4GE_COMPILER_GCC && Z4GE_COMPILER_VERSION >= 40500
#            define Z4GE_HAS_INLINE_NAMESPACES Z4GE_ENABLE
#        else
#            define Z4GE_HAS_INLINE_NAMESPACES Z4GE_DISABLE
#        endif
#    else
#        define Z4GE_HAS_INLINE_NAMESPACES Z4GE_DISABLE
#    endif
#endif

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @brief      Whether the CXX 11 lambdas are supported by the compiler
/// @details    This conditional compilation flags is set based on whether lambda expressions are supported by the
///             host compiler. The conditional compilation flag is set under one of the following circumstances
///                 -#  __has_feature(cxx_lambdas) evaluates to 1
///                 -#  Microsoft Visual C++ Version 1600 or higher (Visual Studio 2010 or higher)
///                 -#  Apple Clang Version 4.1 or higher
///                 -#  LLVM Clang Version 3.1 or higher
///                 -#  GCC Version 4.4 or higher
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef Z4GE_HAS_LAMBDA_EXPRESSIONS
#    if Z4GE_HAS_FEATURE(cxx_lambdas)
#        define Z4GE_HAS_LAMBDA_EXPRESSIONS Z4GE_ENABLE
#    elif Z4GE_CXX11_STANDARD_COMPLIANT
#        if Z4GE_COMPILER & Z4GE_COMPILER_MSVC && (Z4GE_COMPILER_VERSION >= 160000000)
#            define Z4GE_HAS_LAMBDA_EXPRESSIONS Z4GE_ENABLE
#        elif Z4GE_COMPILER & Z4GE_COMPILER_APPLE_CLANG && Z4GE_COMPILER_VERSION >= 40100
#            define Z4GE_HAS_LAMBDA_EXPRESSIONS Z4GE_ENABLE
#        elif Z4GE_COMPILER & Z4GE_COMPILER_LLVM_CLANG && Z4GE_COMPILER_VERSION >= 30100
#            define Z4GE_HAS_LAMBDA_EXPRESSIONS Z4GE_ENABLE
#        elif Z4GE_COMPILER & Z4GE_COMPILER_GCC && Z4GE_COMPILER_VERSION >= 40400
#            define Z4GE_HAS_LAMBDA_EXPRESSIONS Z4GE_ENABLE
#        else
#            define Z4GE_HAS_LAMBDA_EXPRESSIONS Z4GE_DISABLE
#        endif
#    else
#        define Z4GE_HAS_LAMBDA_EXPRESSIONS Z4GE_DISABLE
#    endif
#endif

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @brief      Whether the CXX 11 lambdas are supported by the compiler
/// @details    This conditional compilation flags is set based on whether lambda expressions are supported by the
///             host compiler. The conditional compilation flag is set under one of the following circumstances
///                 -#  __has_feature(cxx_local_type_template_args) evaluates to 1
///                 -#  Microsoft Visual C++ Version 1600 or higher (Visual Studio 2010 or higher)
///                 -#  Apple Clang Version 4.2 or higher
///                 -#  LLVM Clang Version 2.9 or higher
///                 -#  GCC Version 4.5 or higher
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef Z4GE_HAS_LOCAL_CLASS_TEMPLATE_PARAMETERS
#    if Z4GE_HAS_FEATURE(cxx_local_type_template_args)
#        define Z4GE_HAS_LOCAL_CLASS_TEMPLATE_PARAMETERS Z4GE_ENABLE
#    elif Z4GE_CXX11_STANDARD_COMPLIANT
#        if Z4GE_COMPILER & Z4GE_COMPILER_MSVC && (Z4GE_COMPILER_VERSION >= 160000000)
#            define Z4GE_HAS_LOCAL_CLASS_TEMPLATE_PARAMETERS Z4GE_ENABLE
#            if Z4GE_COMPILER_VERSION < 160000000 //  Fixed:  VS2010 complains about using a
#                pragma warning(disable : 4836)   //          non-standard C++ extension
#            endif
#        elif Z4GE_COMPILER & Z4GE_COMPILER_APPLE_CLANG && Z4GE_COMPILER_VERSION >= 40200
#            define Z4GE_HAS_LOCAL_CLASS_TEMPLATE_PARAMETERS Z4GE_ENABLE
#        elif Z4GE_COMPILER & Z4GE_COMPILER_LLVM_CLANG && Z4GE_COMPILER_VERSION >= 20900
#            define Z4GE_HAS_LOCAL_CLASS_TEMPLATE_PARAMETERS Z4GE_ENABLE
#        elif Z4GE_COMPILER & Z4GE_COMPILER_GCC && Z4GE_COMPILER_VERSION >= 40500
#            define Z4GE_HAS_LOCAL_CLASS_TEMPLATE_PARAMETERS Z4GE_ENABLE
#        else
#            define Z4GE_HAS_LOCAL_CLASS_TEMPLATE_PARAMETERS Z4GE_DISABLE
#        endif
#    else
#        define Z4GE_HAS_LOCAL_CLASS_TEMPLATE_PARAMETERS Z4GE_DISABLE
#    endif
#endif

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @brief      Whether the CXX 11 `noexcept` specifier is supported by the compiler
/// @details    This conditional compilation flags is set based on whether `noexcept` specifier is supported by the
///             host compiler. The conditional compilation flag is set under one of the following circumstances
///                 -#  __has_feature(cxx_noexcept) evaluates to 1
///                 -#  Microsoft Visual C++ Version 1900 or higher (Visual Studio 2015 or higher)
///                 -#  Apple Clang Version 4.1 or higher
///                 -#  LLVM Clang Version 3.1 or higher
///                 -#  GCC Version 4.6 or higher
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef Z4GE_HAS_NOEXCEPT
#    if Z4GE_HAS_FEATURE(cxx_noexcept)
#        define Z4GE_HAS_NOEXCEPT Z4GE_ENABLE
#    elif Z4GE_CXX11_STANDARD_COMPLIANT
#        if Z4GE_COMPILER & Z4GE_COMPILER_MSVC && (Z4GE_COMPILER_VERSION >= 190000000)
#            define Z4GE_HAS_NOEXCEPT Z4GE_ENABLE
#        elif Z4GE_COMPILER & Z4GE_COMPILER_APPLE_CLANG && Z4GE_COMPILER_VERSION >= 40100
#            define Z4GE_HAS_NOEXCEPT Z4GE_ENABLE
#        elif Z4GE_COMPILER & Z4GE_COMPILER_LLVM_CLANG && Z4GE_COMPILER_VERSION >= 30000
#            define Z4GE_HAS_NOEXCEPT Z4GE_ENABLE
#        elif Z4GE_COMPILER & Z4GE_COMPILER_GCC && Z4GE_COMPILER_VERSION >= 40600
#            define Z4GE_HAS_NOEXCEPT Z4GE_ENABLE
#        else
#            define Z4GE_HAS_NOEXCEPT Z4GE_DISABLE
#        endif
#    else
#        define Z4GE_HAS_NOEXCEPT Z4GE_DISABLE
#    endif
#endif

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @brief      Whether the CXX 11 `noreturn` attribute is supported by the compiler
/// @details    This conditional compilation flags is set based on whether `noreturn` attribute is supported by the
///             host compiler. The conditional compilation flag is set under one of the following circumstances
///                 -#  Microsoft Visual C++ Version 1300 or higher (Visual Studio 2022 or higher)
///                 -#  Apple Clang Version 4.1 or higher
///                 -#  LLVM Clang Version 3.0 or higher
///                 -#  GCC Version 4.8 or higher
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef Z4GE_HAS_NORETURN
#    if Z4GE_CXX11_STANDARD_COMPLIANT
#        if Z4GE_COMPILER & Z4GE_COMPILER_MSVC && (Z4GE_COMPILER_VERSION >= 130000000)
#            define Z4GE_HAS_NORETURN Z4GE_ENABLE
#        elif Z4GE_COMPILER & Z4GE_COMPILER_APPLE_CLANG && Z4GE_COMPILER_VERSION >= 40100
#            define Z4GE_HAS_NORETURN Z4GE_ENABLE
#        elif Z4GE_COMPILER & Z4GE_COMPILER_LLVM_CLANG && Z4GE_COMPILER_VERSION >= 30000
#            define Z4GE_HAS_NORETURN Z4GE_ENABLE
#        elif Z4GE_COMPILER & Z4GE_COMPILER_GCC && Z4GE_COMPILER_VERSION >= 40800
#            define Z4GE_HAS_NORETURN Z4GE_ENABLE
#        else
#            define Z4GE_HAS_NORETURN Z4GE_DISABLE
#        endif
#    else
#        define Z4GE_HAS_NORETURN Z4GE_DISABLE
#    endif
#endif

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @brief      Whether the CXX 11 non-static member initializers are supported by the compiler
/// @details    This conditional compilation flags is set based on whether non-static member initializers are supported by the
///             host compiler. The conditional compilation flag is set under one of the following circumstances
///                 -#  __has_feature(cxx_nonstatic_member_init) evaluates to 1
///                 -#  Microsoft Visual C++ Version 1800 or higher (Visual Studio 2013 or higher)
///                 -#  Apple Clang Version 4.1 or higher
///                 -#  LLVM Clang Version 3.0 or higher
///                 -#  GCC Version 4.7 or higher
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef Z4GE_HAS_NONSTATIC_MEMBER_INITIALIZERS
#    if Z4GE_HAS_FEATURE(cxx_nonstatic_member_init)
#        define Z4GE_HAS_NONSTATIC_MEMBER_INITIALIZERS Z4GE_ENABLE
#    elif Z4GE_CXX11_STANDARD_COMPLIANT
#        if Z4GE_COMPILER & Z4GE_COMPILER_MSVC && (Z4GE_COMPILER_VERSION >= 180000000)
#            define Z4GE_HAS_NONSTATIC_MEMBER_INITIALIZERS Z4GE_ENABLE
#        elif Z4GE_COMPILER & Z4GE_COMPILER_APPLE_CLANG && Z4GE_COMPILER_VERSION >= 40100
#            define Z4GE_HAS_NONSTATIC_MEMBER_INITIALIZERS Z4GE_ENABLE
#        elif Z4GE_COMPILER & Z4GE_COMPILER_LLVM_CLANG && Z4GE_COMPILER_VERSION >= 30000
#            define Z4GE_HAS_NONSTATIC_MEMBER_INITIALIZERS Z4GE_ENABLE
#        elif Z4GE_COMPILER & Z4GE_COMPILER_GCC && Z4GE_COMPILER_VERSION >= 40700
#            define Z4GE_HAS_NONSTATIC_MEMBER_INITIALIZERS Z4GE_ENABLE
#        else
#            define Z4GE_HAS_NONSTATIC_MEMBER_INITIALIZERS Z4GE_DISABLE
#        endif
#    else
#        define Z4GE_HAS_NONSTATIC_MEMBER_INITIALIZERS Z4GE_DISABLE
#    endif
#endif

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @brief      Whether the CXX 11 `nullptr`s are supported by the compiler
/// @details    This conditional compilation flags is set based on whether `nullptr`s are supported by the
///             host compiler. The conditional compilation flag is set under one of the following circumstances
///                 -#  __has_feature(cxx_nullptr) evaluates to 1
///                 -#  Microsoft Visual C++ Version 1600 or higher (Visual Studio 2010 or higher)
///                 -#  Apple Clang or LLVM Clang
///                 -#  GCC Version  5.0 or higher
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef Z4GE_HAS_NULLPTR
#    if Z4GE_HAS_FEATURE(cxx_nullptr)
#        define Z4GE_HAS_NULLPTR Z4GE_ENABLE
#    elif Z4GE_CXX11_STANDARD_COMPLIANT
#        if Z4GE_COMPILER & Z4GE_COMPILER_MSVC && (Z4GE_COMPILER_VERSION >= 160000000)
#            define Z4GE_HAS_NULLPTR Z4GE_ENABLE
#        elif Z4GE_COMPILER & (Z4GE_COMPILER_APPLE_CLANG | Z4GE_COMPILER_LLVM_CLANG)
#            define Z4GE_HAS_NULLPTR Z4GE_ENABLE
#        elif Z4GE_COMPILER & Z4GE_COMPILER_GCC && Z4GE_COMPILER_VERSION >= 50000
#            define Z4GE_HAS_NULLPTR Z4GE_ENABLE
#        else
#            define Z4GE_HAS_NULLPTR Z4GE_DISABLE
#        endif
#    else
#        define Z4GE_HAS_NULLPTR Z4GE_DISABLE
#    endif
#endif

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @brief      Whether the CXX 11 `override` specifier is supported by the compiler
/// @details    This conditional compilation flags is set based on whether inheritance member overrides are supported by the
///             host compiler. The conditional compilation flag is set under one of the following circumstances
///                 -#  __has_feature(cxx_override) evaluates to 1
///                 -#  Microsoft Visual C++ Version 1600 or higher (Visual Studio 2010 or higher)
///                 -#  Apple Clang Version 4.1 or LLVM Clang Version 2.9 or higher
///                 -#  GCC Version 4.7 or higher
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef Z4GE_HAS_OVERRIDE
#    if Z4GE_HAS_FEATURE(cxx_override)
#        define Z4GE_HAS_OVERRIDE Z4GE_ENABLE
#    elif Z4GE_CXX11_STANDARD_COMPLIANT
#        if Z4GE_COMPILER & Z4GE_COMPILER_MSVC && (Z4GE_COMPILER_VERSION >= 160000000)
#            define Z4GE_HAS_OVERRIDE Z4GE_ENABLE
#        elif Z4GE_COMPILER & (Z4GE_COMPILER_APPLE_CLANG | Z4GE_COMPILER_LLVM_CLANG) && Z4GE_COMPILER_VERSION >= 20900
#            define Z4GE_HAS_OVERRIDE Z4GE_ENABLE
#        elif Z4GE_COMPILER & Z4GE_COMPILER_GCC && Z4GE_COMPILER_VERSION >= 40700
#            define Z4GE_HAS_OVERRIDE Z4GE_ENABLE
#        else
#            define Z4GE_HAS_OVERRIDE Z4GE_DISABLE
#        endif
#    else
#        define Z4GE_HAS_OVERRIDE Z4GE_DISABLE
#    endif
#endif

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @brief      Whether the CXX 11 range based for loops are supported by the compiler
/// @details    This conditional compilation flags is set based on whether range based for loops are supported by the
///             host compiler. The conditional compilation flag is set under one of the following circumstances
///                 -#  __has_feature(cxx_range_for) evaluates to 1
///                 -#  Microsoft Visual C++ Version 1700 or higher (Visual Studio 2012 or higher)
///                 -#  Apple Clang Version 4.1 or LLVM Clang Version 3.0 or higher
///                 -#  GCC Version 4.6 or higher
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef Z4GE_HAS_RANGE_BASED_FOR_LOOPS
#    if Z4GE_HAS_FEATURE(cxx_range_for)
#        define Z4GE_HAS_RANGE_BASED_FOR_LOOPS Z4GE_ENABLE
#    elif Z4GE_CXX11_STANDARD_COMPLIANT
#        if Z4GE_COMPILER & Z4GE_COMPILER_MSVC && (Z4GE_COMPILER_VERSION >= 170000000)
#            define Z4GE_HAS_RANGE_BASED_FOR_LOOPS Z4GE_ENABLE
#        elif Z4GE_COMPILER & (Z4GE_COMPILER_APPLE_CLANG | Z4GE_COMPILER_LLVM_CLANG) && Z4GE_COMPILER_VERSION >= 30000
#            define Z4GE_HAS_RANGE_BASED_FOR_LOOPS Z4GE_ENABLE
#        elif Z4GE_COMPILER & Z4GE_COMPILER_GCC && Z4GE_COMPILER_VERSION >= 40600
#            define Z4GE_HAS_RANGE_BASED_FOR_LOOPS Z4GE_ENABLE
#        else
#            define Z4GE_HAS_RANGE_BASED_FOR_LOOPS Z4GE_DISABLE
#        endif
#    else
#        define Z4GE_HAS_RANGE_BASED_FOR_LOOPS Z4GE_DISABLE
#    endif
#endif

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @brief      Whether the CXX 11 raw string literal are supported by the compiler
/// @details    This conditional compilation flags is set based on whether raw string literal are supported by the
///             host compiler. The conditional compilation flag is set under one of the following circumstances
///                 -#  __has_feature(cxx_raw_string_literals) evaluates to 1
///                 -#  Microsoft Visual C++ Version 1800 or higher (Visual Studio 2013 or higher)
///                 -#  Apple Clang Version 4.1 or higher
///                 -#  LLVM Clang Version 3.0 or higher
///                 -#  GCC Version 4.5 or higher
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef Z4GE_HAS_RAW_LITERALS
#    if Z4GE_HAS_FEATURE(cxx_raw_string_literals)
#        define Z4GE_HAS_RAW_LITERALS Z4GE_ENABLE
#    elif Z4GE_CXX11_STANDARD_COMPLIANT
#        if Z4GE_COMPILER & Z4GE_COMPILER_MSVC && (Z4GE_COMPILER_VERSION >= 180000000)
#            define Z4GE_HAS_RAW_LITERALS Z4GE_ENABLE
#        elif Z4GE_COMPILER & Z4GE_COMPILER_APPLE_CLANG && Z4GE_COMPILER_VERSION >= 40100
#            define Z4GE_HAS_RAW_LITERALS Z4GE_ENABLE
#        elif Z4GE_COMPILER & Z4GE_COMPILER_LLVM_CLANG && Z4GE_COMPILER_VERSION >= 30000
#            define Z4GE_HAS_RAW_LITERALS Z4GE_ENABLE
#        elif Z4GE_COMPILER & Z4GE_COMPILER_GCC && Z4GE_COMPILER_VERSION >= 40500
#            define Z4GE_HAS_RAW_LITERALS Z4GE_ENABLE
#        else
#            define Z4GE_HAS_RAW_LITERALS Z4GE_DISABLE
#        endif
#    else
#        define Z4GE_HAS_RAW_LITERALS Z4GE_DISABLE
#    endif
#endif

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @brief      Whether the CXX 11 right angled brackets (>) parsing feature is supported by the compiler
/// @details    This conditional compilation flags is set based on whether right angled brackets (>) parsing feature is
///             supported by the host compiler. The conditional compilation flag is set under one of the following circumstances
///                 -#  __has_feature(cxx_right_angle_brackets) evaluates to 1
///                 -#  Microsoft Visual C++ Version 1600 or higher (Visual Studio 2010 or higher)
///                 -#  Apple Clang or LLVM Clang Version 2.9 or higher
///                 -#  GCC Version 4.3 or higher
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef Z4GE_HAS_RIGHT_ANGLED_BRACKETS
#    if Z4GE_HAS_FEATURE(cxx_right_angle_brackets)
#        define Z4GE_HAS_RIGHT_ANGLED_BRACKETS Z4GE_ENABLE
#    elif Z4GE_CXX11_STANDARD_COMPLIANT
#        if Z4GE_COMPILER & Z4GE_COMPILER_MSVC && (Z4GE_COMPILER_VERSION >= 160000000)
#            define Z4GE_HAS_RIGHT_ANGLED_BRACKETS Z4GE_ENABLE
#        elif Z4GE_COMPILER & (Z4GE_COMPILER_APPLE_CLANG | Z4GE_COMPILER_LLVM_CLANG) && Z4GE_COMPILER_VERSION >= 20900
#            define Z4GE_HAS_RIGHT_ANGLED_BRACKETS Z4GE_ENABLE
#        elif Z4GE_COMPILER & Z4GE_COMPILER_GCC && Z4GE_COMPILER_VERSION >= 40300
#            define Z4GE_HAS_RIGHT_ANGLED_BRACKETS Z4GE_ENABLE
#        else
#            define Z4GE_HAS_RIGHT_ANGLED_BRACKETS Z4GE_DISABLE
#        endif
#    else
#        define Z4GE_HAS_RIGHT_ANGLED_BRACKETS Z4GE_DISABLE
#    endif
#endif

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @brief      Whether the CXX 11 rvalue references are supported by the compiler
/// @details    This conditional compilation flags is set based on whether rvalue references are supported by the
///             host compiler. The conditional compilation flag is set under one of the following circumstances
///                 -#  __has_feature(cxx_raw_string_literals) evaluates to 1
///                 -#  Microsoft Visual C++ Version 1600 or higher (Visual Studio 2010 or higher)
///                 -#  GCC Version 4.5 or higher
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef Z4GE_HAS_RVALUE_REFERENCES
#    if Z4GE_HAS_FEATURE(cxx_rvalue_references)
#        define Z4GE_HAS_RVALUE_REFERENCES Z4GE_ENABLE
#    elif Z4GE_CXX11_STANDARD_COMPLIANT
#        if Z4GE_COMPILER & Z4GE_COMPILER_MSVC && (Z4GE_COMPILER_VERSION >= 160000000)
#            define Z4GE_HAS_RVALUE_REFERENCES Z4GE_ENABLE
#        elif Z4GE_COMPILER & Z4GE_COMPILER_GCC && Z4GE_COMPILER_VERSION >= 40500
#            define Z4GE_HAS_RVALUE_REFERENCES Z4GE_ENABLE
#        else
#            define Z4GE_HAS_RVALUE_REFERENCES Z4GE_DISABLE
#        endif
#    else
#        define Z4GE_HAS_RVALUE_REFERENCES Z4GE_DISABLE
#    endif
#endif

#ifndef Z4GE_HAS_POD_RELAXATION
#    if Z4GE_CXX11_STANDARD_COMPLIANT
#        if Z4GE_COMPILER & Z4GE_COMPILER_MSVC && (Z4GE_COMPILER_VERSION >= 170000000)
#            define Z4GE_HAS_POD_RELAXATION Z4GE_ENABLE
#        elif Z4GE_COMPILER & Z4GE_COMPILER_APPLE_CLANG && Z4GE_COMPILER_VERSION >= 40100
#            define Z4GE_HAS_POD_RELAXATION Z4GE_ENABLE
#        elif Z4GE_COMPILER & Z4GE_COMPILER_LLVM_CLANG && Z4GE_COMPILER_VERSION >= 30000
#            define Z4GE_HAS_POD_RELAXATION Z4GE_ENABLE
#        elif Z4GE_COMPILER & Z4GE_COMPILER_GCC && Z4GE_COMPILER_VERSION >= 40500
#            define Z4GE_HAS_POD_RELAXATION Z4GE_ENABLE
#        else
#            define Z4GE_HAS_POD_RELAXATION Z4GE_DISABLE
#        endif
#    else
#        define Z4GE_HAS_POD_RELAXATION Z4GE_DISABLE
#    endif
#endif

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @brief      Whether the CXX 11 raw string literal are supported by the compiler
/// @details    This conditional compilation flags is set based on whether raw string literal are supported by the
///             host compiler. The conditional compilation flag is set under one of the following circumstances
///                 -#  __has_feature(cxx_static_assert) evaluates to 1
///                 -#  Microsoft Visual C++ Version 1910 or higher (Visual Studio 2017 or higher)
///                 -#  Apple Clang or LLVM Clang Version 2.5 or higher
///                 -#  GCC Version 6.0 or higher
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef Z4GE_HAS_STATIC_ASSERT
#    if Z4GE_HAS_FEATURE(cxx_static_assert)
#        define Z4GE_HAS_STATIC_ASSERT Z4GE_ENABLE
#    elif Z4GE_CXX11_STANDARD_COMPLIANT
#        if Z4GE_COMPILER & Z4GE_COMPILER_MSVC && (Z4GE_COMPILER_VERSION >= 191000000)
#            define Z4GE_HAS_STATIC_ASSERT Z4GE_ENABLE
#        elif Z4GE_COMPILER & (Z4GE_COMPILER_APPLE_CLANG | Z4GE_COMPILER_LLVM_CLANG) && Z4GE_COMPILER_VERSION >= 20500
#            define Z4GE_HAS_STATIC_ASSERT Z4GE_ENABLE
#        elif Z4GE_COMPILER & Z4GE_COMPILER_GCC && Z4GE_COMPILER_VERSION >= 60000
#            define Z4GE_HAS_STATIC_ASSERT Z4GE_ENABLE
#        else
#            define Z4GE_HAS_STATIC_ASSERT Z4GE_DISABLE
#        endif
#    else
#        define Z4GE_HAS_STATIC_ASSERT Z4GE_DISABLE
#    endif
#endif

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @brief      Whether the CXX 11 raw string literal are supported by the compiler
/// @details    This conditional compilation flags is set based on whether raw string literal are supported by the
///             host compiler. The conditional compilation flag is set under one of the following circumstances
///                 -#  __has_feature(cxx_strong_enums) evaluates to 1
///                 -#  Microsoft Visual C++ Version 1700 or higher (Visual Studio 2012 or higher)
///                 -#  Apple Clang or LLVM Clang Version 2.9 or higher
///                 -#  GCC Version 4.4 or higher
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef Z4GE_HAS_STRONGLY_TYPED_ENUMS
#    if Z4GE_HAS_FEATURE(cxx_strong_enums)
#        define Z4GE_HAS_STRONGLY_TYPED_ENUMS Z4GE_ENABLE
#    elif Z4GE_CXX11_STANDARD_COMPLIANT
#        if Z4GE_COMPILER & Z4GE_COMPILER_MSVC && (Z4GE_COMPILER_VERSION >= 170000000)
#            define Z4GE_HAS_STRONGLY_TYPED_ENUMS Z4GE_ENABLE
#        elif Z4GE_COMPILER & (Z4GE_COMPILER_APPLE_CLANG | Z4GE_COMPILER_LLVM_CLANG) && Z4GE_COMPILER_VERSION >= 20900
#            define Z4GE_HAS_STRONGLY_TYPED_ENUMS Z4GE_ENABLE
#        elif Z4GE_COMPILER & Z4GE_COMPILER_GCC && Z4GE_COMPILER_VERSION >= 40400
#            define Z4GE_HAS_STRONGLY_TYPED_ENUMS Z4GE_ENABLE
#        else
#            define Z4GE_HAS_STRONGLY_TYPED_ENUMS Z4GE_DISABLE
#        endif
#    else
#        define Z4GE_HAS_STRONGLY_TYPED_ENUMS Z4GE_DISABLE
#    endif
#endif

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @brief      Whether the CXX 11 template aliases are supported by the compiler
/// @details    This conditional compilation flags is set based on whether template aliases are supported by the
///             host compiler. The conditional compilation flag is set under one of the following circumstances
///                 -#  __has_feature(cxx_alias_templates) evaluates to 1
///                 -#  Microsoft Visual C++ Version 1800 or higher (Visual Studio 2013 or higher)
///                 -#  Apple Clang Version 4.1 or higher
///                 -#  LLVM Clang Version 3.0 or higher
///                 -#  GCC Version 4.7 or higher
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef Z4GE_HAS_TEMPLATE_ALIASES
#    if Z4GE_HAS_FEATURE(cxx_alias_templates)
#        define Z4GE_HAS_TEMPLATE_ALIASES Z4GE_ENABLE
#    elif Z4GE_CXX11_STANDARD_COMPLIANT
#        if Z4GE_COMPILER & Z4GE_COMPILER_MSVC && (Z4GE_COMPILER_VERSION >= 180000000)
#            define Z4GE_HAS_TEMPLATE_ALIASES Z4GE_ENABLE
#        elif Z4GE_COMPILER & Z4GE_COMPILER_APPLE_CLANG && Z4GE_COMPILER_VERSION >= 40100
#            define Z4GE_HAS_TEMPLATE_ALIASES Z4GE_ENABLE
#        elif Z4GE_COMPILER & Z4GE_COMPILER_LLVM_CLANG && Z4GE_COMPILER_VERSION >= 30000
#            define Z4GE_HAS_TEMPLATE_ALIASES Z4GE_ENABLE
#        elif Z4GE_COMPILER & Z4GE_COMPILER_GCC && Z4GE_COMPILER_VERSION >= 40700
#            define Z4GE_HAS_TEMPLATE_ALIASES Z4GE_ENABLE
#        else
#            define Z4GE_HAS_TEMPLATE_ALIASES Z4GE_DISABLE
#        endif
#    else
#        define Z4GE_HAS_TEMPLATE_ALIASES Z4GE_DISABLE
#    endif
#endif

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @brief      Whether the CXX 11 trailing return types are supported by the compiler
/// @details    This conditional compilation flags is set based on whether trailing return types are supported by the
///             host compiler. The conditional compilation flag is set under one of the following circumstances
///                 -#  __has_feature(cxx_trailing_return_types) evaluates to 1
///                 -#  Microsoft Visual C++ Version 1600 or higher (Visual Studio 2010 or higher)
///                 -#  Apple Clang Version 4.1 or higher
///                 -#  LLVM Clang Version 3.1 or higher
///                 -#  GCC Version 4.4 or higher
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef Z4GE_HAS_TRAILING_RETURN_TYPES
#    if Z4GE_HAS_FEATURE(cxx_trailing_return_types)
#        define Z4GE_HAS_TRAILING_RETURN_TYPES Z4GE_ENABLE
#    elif Z4GE_CXX11_STANDARD_COMPLIANT
#        if Z4GE_COMPILER & Z4GE_COMPILER_MSVC && (Z4GE_COMPILER_VERSION >= 160000000)
#            define Z4GE_HAS_TRAILING_RETURN_TYPES Z4GE_ENABLE
#        elif Z4GE_COMPILER & Z4GE_COMPILER_APPLE_CLANG && Z4GE_COMPILER_VERSION >= 40100
#            define Z4GE_HAS_TRAILING_RETURN_TYPES Z4GE_ENABLE
#        elif Z4GE_COMPILER & Z4GE_COMPILER_LLVM_CLANG && Z4GE_COMPILER_VERSION >= 30100
#            define Z4GE_HAS_TRAILING_RETURN_TYPES Z4GE_ENABLE
#        elif Z4GE_COMPILER & Z4GE_COMPILER_GCC && Z4GE_COMPILER_VERSION >= 40400
#            define Z4GE_HAS_TRAILING_RETURN_TYPES Z4GE_ENABLE
#        else
#            define Z4GE_HAS_TRAILING_RETURN_TYPES Z4GE_DISABLE
#        endif
#    else
#        define Z4GE_HAS_TRAILING_RETURN_TYPES Z4GE_DISABLE
#    endif
#endif

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @brief      Whether the CXX 11 unicode string literals are supported by the compiler
/// @details    This conditional compilation flags is set based on whether unicode string literals are supported by the
///             host compiler. The conditional compilation flag is set under one of the following circumstances
///                 -#  __has_feature(cxx_unicode_literals) evaluates to 1
///                 -#  Microsoft Visual C++ Version 1900 or higher (Visual Studio 2015 or higher)
///                 -#  Apple Clang Version 4.1 or higher
///                 -#  LLVM Clang Version 3.1 or higher
///                 -#  GCC Version 4.4 or higher
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef Z4GE_HAS_UNICODE_STRING_LITERALS
#    if Z4GE_HAS_FEATURE(cxx_unicode_literals)
#        define Z4GE_HAS_UNICODE_STRING_LITERALS Z4GE_ENABLE
#    elif Z4GE_CXX11_STANDARD_COMPLIANT
#        if Z4GE_COMPILER & Z4GE_COMPILER_MSVC && (Z4GE_COMPILER_VERSION >= 190000000)
#            define Z4GE_HAS_UNICODE_STRING_LITERALS Z4GE_ENABLE
#        elif Z4GE_COMPILER & Z4GE_COMPILER_APPLE_CLANG && Z4GE_COMPILER_VERSION >= 40100
#            define Z4GE_HAS_UNICODE_STRING_LITERALS Z4GE_ENABLE
#        elif Z4GE_COMPILER & Z4GE_COMPILER_LLVM_CLANG && Z4GE_COMPILER_VERSION >= 30100
#            define Z4GE_HAS_UNICODE_STRING_LITERALS Z4GE_ENABLE
#        elif Z4GE_COMPILER & Z4GE_COMPILER_GCC && Z4GE_COMPILER_VERSION >= 40400
#            define Z4GE_HAS_UNICODE_STRING_LITERALS Z4GE_ENABLE
#        else
#            define Z4GE_HAS_UNICODE_STRING_LITERALS Z4GE_DISABLE
#        endif
#    else
#        define Z4GE_HAS_UNICODE_STRING_LITERALS Z4GE_DISABLE
#    endif
#endif

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @brief      Whether the CXX 11 uniform initialization syntax are supported by the compiler
/// @details    This conditional compilation flags is set based on whether uniform initialization syntax are supported by the
///             host compiler. The conditional compilation flag is set under one of the following circumstances
///                 -#  __has_feature(cxx_uniform_initialization) evaluates to 1
///                 -#  Microsoft Visual C++ Version 1800 or higher (Visual Studio 2013 or higher)
///                 -#  Apple Clang Version 4.1 or higher
///                 -#  LLVM Clang Version 3.1 or higher
///                 -#  GCC Version 4.4 or higher
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef Z4GE_HAS_UNIFORM_INITIALIZATION_SYNTAX
#    if Z4GE_HAS_FEATURE(cxx_uniform_initialization)
#        define Z4GE_HAS_UNIFORM_INITIALIZATION_SYNTAX Z4GE_ENABLE
#    elif Z4GE_CXX11_STANDARD_COMPLIANT
#        if Z4GE_COMPILER & Z4GE_COMPILER_MSVC && (Z4GE_COMPILER_VERSION >= 180000000)
#            define Z4GE_HAS_UNIFORM_INITIALIZATION_SYNTAX Z4GE_ENABLE
#        elif Z4GE_COMPILER & Z4GE_COMPILER_APPLE_CLANG && Z4GE_COMPILER_VERSION >= 40100
#            define Z4GE_HAS_UNIFORM_INITIALIZATION_SYNTAX Z4GE_ENABLE
#        elif Z4GE_COMPILER & Z4GE_COMPILER_LLVM_CLANG && Z4GE_COMPILER_VERSION >= 30100
#            define Z4GE_HAS_UNIFORM_INITIALIZATION_SYNTAX Z4GE_ENABLE
#        elif Z4GE_COMPILER & Z4GE_COMPILER_GCC && Z4GE_COMPILER_VERSION >= 40400
#            define Z4GE_HAS_UNIFORM_INITIALIZATION_SYNTAX Z4GE_ENABLE
#        else
#            define Z4GE_HAS_UNIFORM_INITIALIZATION_SYNTAX Z4GE_DISABLE
#        endif
#    else
#        define Z4GE_HAS_UNIFORM_INITIALIZATION_SYNTAX Z4GE_DISABLE
#    endif
#endif

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @brief      Whether the CXX 11 uniform initialization syntax are supported by the compiler
/// @details    This conditional compilation flags is set based on whether uniform initialization syntax are supported by the
///             host compiler. The conditional compilation flag is set under one of the following circumstances
///                 -#  __has_feature(cxx_uniform_initialization) evaluates to 1
///                 -#  Microsoft Visual C++ Version 1800 or higher (Visual Studio 2013 or higher)
///                 -#  Apple Clang Version 4.1 or higher
///                 -#  LLVM Clang Version 3.1 or higher
///                 -#  GCC Version 4.4 or higher
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef Z4GE_HAS_UNRESTRICTED_UNIONS
#    if Z4GE_HAS_FEATURE(cxx_unrestricted_unions)
#        define Z4GE_HAS_UNRESTRICTED_UNIONS Z4GE_ENABLE
#    elif Z4GE_CXX11_STANDARD_COMPLIANT
#        if Z4GE_COMPILER & Z4GE_COMPILER_MSVC && (Z4GE_COMPILER_VERSION >= 190000000)
#            define Z4GE_HAS_UNRESTRICTED_UNIONS Z4GE_ENABLE
#        elif Z4GE_COMPILER & Z4GE_COMPILER_APPLE_CLANG && Z4GE_COMPILER_VERSION >= 40100
#            define Z4GE_HAS_UNRESTRICTED_UNIONS Z4GE_ENABLE
#        elif Z4GE_COMPILER & Z4GE_COMPILER_LLVM_CLANG && Z4GE_COMPILER_VERSION >= 30100
#            define Z4GE_HAS_UNRESTRICTED_UNIONS Z4GE_ENABLE
#        elif Z4GE_COMPILER & Z4GE_COMPILER_GCC && Z4GE_COMPILER_VERSION >= 40600
#            define Z4GE_HAS_UNRESTRICTED_UNIONS Z4GE_ENABLE
#        else
#            define Z4GE_HAS_UNRESTRICTED_UNIONS Z4GE_DISABLE
#        endif
#    else
#        define Z4GE_HAS_UNRESTRICTED_UNIONS Z4GE_DISABLE
#    endif
#endif

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @brief      Whether the CXX 11 user defined literals are supported by the compiler
/// @details    This conditional compilation flags is set based on whether user defined literals are supported by the
///             host compiler. The conditional compilation flag is set under one of the following circumstances
///                 -#  __has_feature(cxx_user_literals) evaluates to 1
///                 -#  Microsoft Visual C++ Version 1900 or higher (Visual Studio 2015 or higher)
///                 -#  Apple Clang Version 4.1 or higher
///                 -#  LLVM Clang Version 3.1 or higher
///                 -#  GCC Version 4.7 or higher
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef Z4GE_HAS_USER_LITERALS
#    if Z4GE_HAS_FEATURE(cxx_user_literals)
#        define Z4GE_HAS_USER_LITERALS Z4GE_ENABLE
#    elif Z4GE_CXX11_STANDARD_COMPLIANT
#        if Z4GE_COMPILER & Z4GE_COMPILER_MSVC && (Z4GE_COMPILER_VERSION >= 190000000)
#            define Z4GE_HAS_USER_LITERALS Z4GE_ENABLE
#        elif Z4GE_COMPILER & Z4GE_COMPILER_APPLE_CLANG && Z4GE_COMPILER_VERSION >= 40100
#            define Z4GE_HAS_USER_LITERALS Z4GE_ENABLE
#        elif Z4GE_COMPILER & Z4GE_COMPILER_LLVM_CLANG && Z4GE_COMPILER_VERSION >= 30100
#            define Z4GE_HAS_USER_LITERALS Z4GE_ENABLE
#        elif Z4GE_COMPILER & Z4GE_COMPILER_GCC && Z4GE_COMPILER_VERSION >= 40700
#            define Z4GE_HAS_USER_LITERALS Z4GE_ENABLE
#        else
#            define Z4GE_HAS_USER_LITERALS Z4GE_DISABLE
#        endif
#    else
#        define Z4GE_HAS_USER_LITERALS Z4GE_DISABLE
#    endif
#endif

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @brief      Whether the CXX 11 user defined literals are supported by the compiler
/// @details    This conditional compilation flags is set based on whether user defined literals are supported by the
///             host compiler. The conditional compilation flag is set under one of the following circumstances
///                 -#  __has_feature(cxx_variadic_templates) evaluates to 1
///                 -#  Microsoft Visual C++ Version 1700.51025 (Visual Studio 2012)
///                 -#  Microsoft Visual C++ Version 1800 or higher (Visual Studio 2013 or higher)
///                 -#  Apple Clang Version 4.1 or higher
///                 -#  LLVM Clang Version 3.1 or higher
///                 -#  GCC Version 4.7 or higher
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef Z4GE_HAS_VARIADIC_TEMPLATES
#    if Z4GE_HAS_FEATURE(cxx_variadic_templates)
#        define Z4GE_HAS_VARIADIC_TEMPLATES Z4GE_ENABLE
#    elif Z4GE_CXX11_STANDARD_COMPLIANT
#        if Z4GE_COMPILER & Z4GE_COMPILER_MSVC && (Z4GE_COMPILER_VERSION >= 180000000 || Z4GE_COMPILER_VERISON == 170051025)
#            define Z4GE_HAS_VARIADIC_TEMPLATES Z4GE_ENABLE
#        elif Z4GE_COMPILER & Z4GE_COMPILER_LLVM_CLANG && Z4GE_COMPILER_VERSION >= 20900
#            define Z4GE_HAS_VARIADIC_TEMPLATES Z4GE_ENABLE
#        elif Z4GE_COMPILER & Z4GE_COMPILER_GCC && Z4GE_COMPILER_VERSION >= 40400
#            define Z4GE_HAS_VARIADIC_TEMPLATES Z4GE_ENABLE
#        else
#            define Z4GE_HAS_VARIADIC_TEMPLATES Z4GE_DISABLE
#        endif
#    else
#        define Z4GE_HAS_VARIADIC_TEMPLATES Z4GE_DISABLE
#    endif
#endif

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @brief      Whether the CXX 14 variable templates are supported by the compiler
/// @details    This conditional compilation flags is set based on whether variable templates are supported by the
///             host compiler. The conditional compilation flag is set under one of the following circumstances
///                 -#  __has_feature(cxx_variable_templates) evaluates to 1
///                 -#  Microsoft Visual C++ Version 190023918 or higher (Visual Studio 2015 or higher)
///                 -#  LLVM Clang Version 3.4 or higher
///                 -#  GCC Version 5.0 or higher
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef Z4GE_HAS_VARIABLE_TEMPLATES
#    if Z4GE_HAS_FEATURE(cxx_variable_templates)
#        define Z4GE_HAS_VARIABLE_TEMPLATES Z4GE_ENABLE
#    elif Z4GE_CXX14_STANDARD_COMPLIANT
#        if Z4GE_COMPILER & Z4GE_COMPILER_MSVC && Z4GE_COMPILER_VERSION >= 190023918
#            define Z4GE_HAS_VARIABLE_TEMPLATES Z4GE_ENABLE
#        elif Z4GE_COMPILER & Z4GE_COMPILER_LLVM_CLANG && Z4GE_COMPILER_VERSION >= 30400
#            define Z4GE_HAS_VARIABLE_TEMPLATES Z4GE_ENABLE
#        elif Z4GE_COMPILER & Z4GE_COMPILER_GCC && Z4GE_COMPILER_VERSION >= 50000
#            define Z4GE_HAS_VARIABLE_TEMPLATES Z4GE_ENABLE
#        else
#            define Z4GE_HAS_VARIABLE_TEMPLATES Z4GE_DISABLE
#        endif
#    else
#        define Z4GE_HAS_VARIABLE_TEMPLATES Z4GE_DISABLE
#    endif
#endif

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @brief      Whether the `new` operator returns aligned memory
/// @details    This conditional compilation flags is set based on whether the `new` operator returns aligned memory upon
///             invocation. The conditional compilation flag is set under one of the following circumstances
///                 -#  CXX 17 standard is satisfied ( @ref Z4GE_CXX17_STANDARD_COMPLIANT is set )
///                 -#  Microsoft Visual C++ is the host compiler and `_HAS_ALIGNED_NEW` flag is defined and set to 1
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef Z4GE_HAS_ALIGNED_NEW
#    if Z4GE_CXX17_STANDARD_COMPLIANT
#        define Z4GE_HAS_ALIGNED_NEW Z4GE_ENABLE
#    elif defined(_HAS_ALIGNED_NEW) && _HAS_ALIGNED_NEW
#        define Z4GE_HAS_ALIGNED_NEW Z4GE_ENABLE
#    else
#        define Z4GE_HAS_ALIGNED_NEW Z4GE_DISABLE
#    endif
#endif

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @brief      Whether the CXX 17 `constexpr`s in if statements are supported by the compiler
/// @details    This conditional compilation flags is set based on whether the constant expressions (`constexpr`) in if
///             statements are supported by the host compiler. The conditional compilation flag is set under one of the
///             following circumstances
///                 -#  __has_feature(cxx_if_constexpr) evaluates to 1
///                 -#  Microsoft Visual C++ Version 1911 or higher (Visual Studio 2017 version 15.3 or higher)
///                 -#  Apple Clang and LLVM Clang Version 3.9 or higher
///                 -#  GCC Version 7.0 or higher
///
/// @par        If Constant Expressions
///             In a constexpr if statement, the value of condition must be a contextually converted constant expression of
///             type `bool`. If the value is `true`, then statement-false is discarded (if present), otherwise,
///             statement-true is discarded. The return statements in a discarded statement do not participate in function
///             return type deduction
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef Z4GE_HAS_IF_CONSTEXPR
#    if Z4GE_HAS_FEATURE(cxx_if_constexpr)
#        define Z4GE_HAS_IF_CONSTEXPR Z4GE_ENABLE
#    elif Z4GE_CXX17_STANDARD_COMPLIANT
#        if Z4GE_COMPILER & Z4GE_COMPILER_MSVC && Z4GE_COMPILER_VERSION >= 191100000
#            define Z4GE_HAS_IF_CONSTEXPR Z4GE_ENABLE
#        elif Z4GE_COMPILER & (Z4GE_COMPILER_APPLE_CLANG | Z4GE_COMPILER_LLVM_CLANG) && Z4GE_COMPILER_VERSION >= 30900
#            define Z4GE_HAS_IF_CONSTEXPR Z4GE_ENABLE
#        elif Z4GE_COMPILER & Z4GE_COMPILER_GCC && Z4GE_COMPILER_VERSION >= 70000
#            define Z4GE_HAS_IF_CONSTEXPR Z4GE_ENABLE
#        else
#            define Z4GE_HAS_IF_CONSTEXPR Z4GE_DISABLE
#        endif
#    else
#        define Z4GE_HAS_IF_CONSTEXPR Z4GE_DISABLE
#    endif
#endif

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @brief      Whether CXX 17 [[fallthrough]] attribute is supported by the compiler
/// @details    This conditional compilation flag is set based on whether the [[fallthrough]] are similar attribute is supported
///             by the host compiler. The conditional compilation flag is set under one of the follwing circumstances
///                 -#  CXX 17 standard is satisfied ( @ref Z4GE_CXX17_STANDARD_COMPLIANT is set )
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef Z4GE_HAS_FALLTHROUGH_ATTRIBUTE
#    if Z4GE_CXX17_STANDARD_COMPLIANT
#        define Z4GE_HAS_FALLTHROUGH_ATTRIBUTE Z4GE_ENABLE
#    else
#        define Z4GE_HAS_FALLTHROUGH_ATTRIBUTE Z4GE_DISABLE
#    endif
#endif

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @brief      Whether CXX 17 [[nodiscard]] attribute is supported by the compiler
/// @details    This conditional compilation flag is set based on whether the [[nodiscard]] are similar attribute is supported
///             by the host compiler. The conditional compilation flag is set under one of the follwing circumstances
///                 -#  CXX 17 standard is satisfied ( @ref Z4GE_CXX17_STANDARD_COMPLIANT is set )
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef Z4GE_HAS_NODISCARD_ATTRIBUTE
#    if Z4GE_CXX17_STANDARD_COMPLIANT
#        define Z4GE_HAS_NODISCARD_ATTRIBUTE Z4GE_ENABLE
#    else
#        define Z4GE_HAS_NODISCARD_ATTRIBUTE Z4GE_DISABLE
#    endif
#endif

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @brief      Whether CXX 17 [[maybe_unused]] attribute is supported by the compiler
/// @details    This conditional compilation flag is set based on whether the [[maybe_unused]] are similar attribute is
///             supported by the host compiler. The conditional compilation flag is set under one of the follwing circumstances
///                 -#  CXX 17 standard is satisfied ( @ref Z4GE_CXX17_STANDARD_COMPLIANT is set )
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef Z4GE_HAS_MAYBE_UNUSED_ATTRIBUTE
#    if Z4GE_CXX17_STANDARD_COMPLIANT
#        define Z4GE_HAS_MAYBE_UNUSED_ATTRIBUTE Z4GE_ENABLE
#    else
#        define Z4GE_HAS_MAYBE_UNUSED_ATTRIBUTE Z4GE_DISABLE
#    endif
#endif

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @}
/// @defgroup   cxx_compiler_features_implementation    CXX Compiler Feature Implementation
/// @brief      CXX Feature Implementation based on @ref cxx_compiler_feature_detection "CXX Compiler Feature Detection"
/// @details    These are a set of macros that implement features that are available on various platforms, compilers, language
///             standards in a platform/compiler/standard independent manner. These macros are dependent on the
///             @ref cxx_compiler_feature_detection "CXX Compiler Feature Detection" macros to query and implement features that
///             supported by a particular platform / compiler / CXX standard
///
///             The following macros are implemented to make use of the features that are supported by Z4GE
///                 -#  @ref Z4GE_ALIGN_OF
///                 -#  @ref Z4GE_ALIGN_AS
///                 -#  @ref Z4GE_ALIGNED_TYPEDEF
///                 -#  @ref Z4GE_API
///                 -#  @ref Z4GE_API_EXPORT
///                 -#  @ref Z4GE_API_IMPORT
///                 -#  @ref Z4GE_CONSTEXPR
///                 -#  @ref Z4GE_CONSTEXPR_OR_CONST
///                 -#  @ref Z4GE_CURRENT_FUNCTION
///                 -#  @ref Z4GE_DEPRECATED
///                 -#  @ref Z4GE_DEPRECATED_MESSAGE
///                 -#  @ref Z4GE_EXPLICIT
///                 -#  @ref Z4GE_EXTERN_TEMPLATE
///                 -#  @ref Z4GE_FINAL
///                 -#  @ref Z4GE_IF_CONSTEXPR
///                 -#  @ref Z4GE_INLINE
///                 -#  @ref Z4GE_NOEXCEPT
///                 -#  @ref Z4GE_NOINLINE
///                 -#  @ref Z4GE_NORETURN
///                 -#  @ref Z4GE_LIKELY
///                 -#  @ref Z4GE_OFFSET_OF
///                 -#  @ref Z4GE_OVERRIDE
///                 -#  @ref Z4GE_PACKED
///                 -#  @ref Z4GE_PRAGMA
///                 -#  @ref Z4GE_RESTRICT
///                 -#  @ref Z4GE_SIZEOF_MEMBER
///                 -#  @ref Z4GE_STATIC_ASSERT
///                 -#  @ref Z4GE_UNLIKELY
///                 -#  @ref Z4GE_UNUSED
/// @{
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @brief      Compiler independent `#pragma` implementation
/// @details    This macro expands to a compiler defined macro / directive that can be used in place of `#pragma`
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef Z4GE_PRAGMA
#    if Z4GE_COMPILER & (Z4GE_COMPILER_GCC | Z4GE_COMPILER_LLVM_CLANG | Z4GE_COMPILER_APPLE_CLANG)
#        define Z4GE_PRAGMA(...) _Pragma (__VA_ARGS__)
#    elif Z4GE_COMPILER & Z4GE_COMPILER_MSVC
#        define Z4GE_PRAGMA(...) __pragma (__VA_ARGS__)
#    else
#        define Z4GE_PRAGMA(...)
#    endif
#endif

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @brief      Compiler / Language standard independent Alignment Specifier
/// @details    This macro provides a compiler independent implementation of the alignment specifier. This macro expands to the
///             compiler / language standard specific alignment specifier that can be used to define the alignment of the
///             defined struct, class, member or a variable.
///
/// @par        AlignAs
///             The alignas specifies may be applied to
///                 -#  The declaration or definition of a class/struct/union or enumeration.
///                 -#  The declaration of a non-bitfield class data member.
///                 -#  The declaration of a variable, which is not
///                     -#  A function parameter.
///                     -#  The exception parameter of a catch clause.
///             The object or the type declared by such a declaration will have its alignment requirement equal to the strictest
///             (largest) non-zero expression of all `alignas` specifiers used in the declaration, unless it would weaken the
///             natural alignment of the type.
/// @see        Z4GE_ALIGNED_TYPEDEF
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef Z4GE_ALIGN_AS
#    if Z4GE_HAS_ALIGN_AS
#        define Z4GE_ALIGN_AS(__ALIGNMENT__) alignas (__ALIGNMENT__)
#    elif Z4GE_COMPILER & Z4GE_COMPILER_GCC && Z4GE_COMPILER_VERSION >= 30000
#        define Z4GE_ALIGN_AS(__ALIGNMENT__) __attribute__ ((aligned (__ALIGNMENT__)))
#    elif Z4GE_COMPILER & (Z4GE_COMPILER_LLVM_CLANG | Z4GE_COMPILER_APPLE_CLANG)
#        define Z4GE_ALIGN_AS(__ALIGNMENT__) __attribute__ ((aligned (__ALIGNMENT__)))
#    elif Z4GE_COMPILER & (Z4GE_COMPILER_INTEL | Z4GE_COMPILER_MSVC)
#        define Z4GE_ALIGN_AS(__ALIGNMENT__) __declspec(align (__ALIGNMENT__))
#    else
#        define Z4GE_ALIGN_AS(__ALIGNMENT__) 0
#    endif
#endif

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @brief      Compiler / Language standard independent aligned `typedef`
/// @details    This macro provides a compiler independent implementation for defining a type with a alignment specification.
///             This macro makes use of the @ref Z4GE_ALIGN_AS macro implementing this behaviour and therefore can be used
///             rather than
///             @code
///                 typedef Z4GE_ALIGN_AS(float) struct {
///                     ...
///                 } Type;
///             @endcode
/// @see        Z4GE_ALIGN_AS
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef Z4GE_ALIGNED_TYPEDEF
#    if Z4GE_COMPILER & (Z4GE_COMPILER_GCC | Z4GE_COMPILER_LLVM_CLANG | Z4GE_COMPILER_APPLE_CLANG)
#        define Z4GE_ALIGNED_TYPEDEF(__TYPE__, __IDENTIFIER__, __ALIGNMENT__)                                                  \
            __TYPE__ __IDENTIFIER__ Z4GE_ALIGN_AS (__ALIGNMENT__)
#    else
#        define Z4GE_ALIGNED_TYPEDEF(__TYPE__, __IDENTIFIER__, __ALIGNMENT__)                                                  \
            Z4GE_ALIGN_AS (__ALIGNMENT__) __TYPE__ __IDENTIFIER__
#    endif
#endif

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @brief      Compiler / Language standard independent `alignof`
/// @details    This macro provides a compiler independent implementation  of `alignof`. This macro expands to the compiler /
///             language specific attribute / builtin that retrieves the required alignment of the underlying type.
///
/// @par        AlignOf
///             Returns the alignment, in bytes, required for any instance of the type, which is either complete object type,
///             an array type whose element type is complete, or a reference type to one of those types.
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef Z4GE_ALIGN_OF
#    if Z4GE_HAS_ALIGN_OF
#        define Z4GE_ALIGN_OF(__TYPE__) alignof (__TYPE__)
#    elif Z4GE_COMPILER & (Z4GE_COMPILER_GCC | Z4GE_COMPILER_LLVM_CLANG | Z4GE_COMPILER_APPLE_CLANG)
#        define Z4GE_ALIGN_OF(__TYPE__) ((size_t) __alignof__(__TYPE__))
#    elif Z4GE_COMPILER & (Z4GE_COMPILER_INTEL | Z4GE_COMPILER_MSVC)
#        define Z4GE_ALIGN_OF(__TYPE__) ((size_t) __alignof(__TYPE__))
#    else
#        define Z4GE_ALIGN_OF(__TYPE__) 0
#    endif
#endif

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @brief      Compiler / Platform independent Z4GE API expicifier
/// @details    This macro expands to the equivalent of the `__declspec(dllexport)` or `__declspec(dllimport)` in Microsoft
///             Visual C++ depending upon the package configuration. This macro can be used to annotate a function or a class
///             that it has to be "exported" to an external library or to be "imported" from an external library. This macro
///             expands to @ref Z4GE_API_EXPORT or @ref Z4GE_API_IMPORT depending upon the configuration, platform and compiler.
/// @see        Z4GE_API_IMPORT
/// @see        Z4GE_API_EXPORT
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef Z4GE_API
#    if defined(Z4GE_SHARED_BUILD) && defined(Z4GE_EXPORT_PACKAGE)
#        define Z4GE_API Z4GE_API_EXPORT
#    elif defined(Z4GE_SHARED_BUILD) && defined(Z4GE_IMPORT_PACKAGE)
#        define Z4GE_API Z4GE_API_IMPORT
#    else
#        define Z4GE_API
#    endif
#endif

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @brief      Compiler / Platform independent object visibility specifier (export)
/// @details    This macro expands to the equivalent of the `__declspec(dllexport)` in Microsoft Visual C++. This macro can be
///             used to annotate a function or a class that it has been "exported" to an external library and can be "imported"
///             by using @ref Z4GE_API_IMPORT or API defined macro
/// @see        Z4GE_API_IMPORT
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef Z4GE_API_EXPORT
#    if Z4GE_COMPILER & (Z4GE_COMPILER_GCC | Z4GE_COMPILER_APPLE_CLANG | Z4GE_COMPILER_LLVM_CLANG)
#        if Z4GE_PLATFORM & Z4GE_PLATFORM_CYGWIN
#            define Z4GE_API_EXPORT __declspec(dllexport)
#        else
#            define Z4GE_API_IMPORT __attribute__ ((visibility ("default")))
#        endif
#    elif Z4GE_COMPILER & (Z4GE_COMPILER_MSVC | Z4GE_COMPILER_INTEL)
#        define Z4GE_API_EXPORT __declspec(dllexport)
#    else
#        define Z4GE_API_EXPORT
#    endif
#endif

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @brief      Compiler / Platform independent object visibility specifier (import)
/// @details    This macro expands to the equivalent of the `__declspec(dllimport)` in Microsoft Visual C++. This macro can be
///             used to annotate a function or a class that it has been "imported" from an external library and has be
///             "exported" by using @ref Z4GE_API_EXPORT or API defined macro
/// @see        Z4GE_API_EXPORT
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef Z4GE_API_IMPORT
#    if Z4GE_COMPILER & (Z4GE_COMPILER_GCC | Z4GE_COMPILER_APPLE_CLANG | Z4GE_COMPILER_CLANG)
#        if Z4GE_PLATFORM & Z4GE_CYGWIN
#            define Z4GE_API_IMPORT __declspec(dllimport)
#        else
#            define Z4GE_API_IMPORT __attribute__ ((visibility ("default")))
#        endif
#    elif Z4GE_COMPILER & (Z4GE_COMPILER_MSVC | Z4GE_COMPILER_INTEL)
#        define Z4GE_API_IMPORT __declspec(dllimport)
#    else
#        define Z4GE_API_IMPORT
#    endif
#endif

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @brief      Compiler / Language standard independent `constexpr`
/// @details    This macro expands to the constant expressions declaration (`constexpr`) that is supported
///             by the host compiler. Ifit is not supported by the host compiler, then this macro expands to nothing.
///
/// @par        Constant Expressions
///             The `constexpr` specifies that it is possible to to evaluate the value of the function or a given variable ath
///             the compile time. Such variables and functions can be used later where only compile time constants are allowed.
///             The following requirements are to be satisfied inorder to make a `constexpr` variable:
///                 -#  It must be a literal type
///                 -#  It must be immediately initialized
///                 -#  The full-expression of its initialization including all implicit conversions, constructor calls must be
///                     constant expressions
///             The following requirements are to be satisfied inorder to make a `constexpr` function:
///                 -#  It must not be a virtual function
///                 -#  Its return type (if any) and its parameters should be literal type
///                 -#  In case of constructors, the class must not have any virtual base classes
///                 -#  The function of the body must not be a function-try block
///                 -#  The function body must not contain:
///                     -#  A `goto` statement
///                     -#  A `try` block
///                     -#  An ASM declaration
///                     -#  A definition of a variable for which initialization id not performed
///                     -#  A definition of a variable of non-literal type
///                     -#  A definition of a variable of `static` or `thread` storage duration
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef Z4GE_CONSTEXPR
#    if Z4GE_HAS_CONSTEXPR
#        define Z4GE_CONSTEXPR constexpr
#    else
#        define Z4GE_CONSTEXPR
#    endif
#endif

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @brief      Compiler / Language standard independent `constexpr` with fallback to `const`
/// @details    This macro expands to the constant expressions declaration (`constexpr`) that is supported
///             by the host compiler. Unlike @ref Z4GE_CONSTEXPR, if it is not supported by the host compiler, then this macro
///             expands to `const`.
///
/// @par        Constant Expressions
///             The `constexpr` specifies that it is possible to to evaluate the value of the function or a given variable ath
///             the compile time. Such variables and functions can be used later where only compile time constants are allowed.
///             The following requirements are to be satisfied inorder to make a `constexpr` variable:
///                 -#  It must be a literal type
///                 -#  It must be immediately initialized
///                 -#  The full-expression of its initialization including all implicit conversions, constructor calls must be
///                     constant expressions
///             The following requirements are to be satisfied inorder to make a `constexpr` function:
///                 -#  It must not be a virtual function
///                 -#  Its return type (if any) and its parameters should be literal type
///                 -#  In case of constructors, the class must not have any virtual base classes
///                 -#  The function of the body must not be a function-try block
///                 -#  The function body must not contain:
///                     -#  A `goto` statement
///                     -#  A `try` block
///                     -#  An ASM declaration
///                     -#  A definition of a variable for which initialization id not performed
///                     -#  A definition of a variable of non-literal type
///                     -#  A definition of a variable of `static` or `thread` storage duration
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef Z4GE_CONSTEXPR_OR_CONST
#    if Z4GE_HAS_CONSTEXPR
#        define Z4GE_CONSTEXPR_OR_CONST constexpr
#    else
#        define Z4GE_CONSTEXPR_OR_CONST const
#    endif
#endif

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @brief      Compiler / Language independent function name macro equivalent to `__FUNCTION__`
/// @details    This macro expands a compiler / language specific function name macro that can be used in debugging and loading
///             functions from a external library. Currently, It fallbacks to C implementation (i.e `__func__`)
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef Z4GE_CURRENT_FUNCTION
#    if Z4GE_COMPILER & Z4GE_COMPILER_GCC
#        define Z4GE_CURRENT_FUNCTION __PRETTY_FUNCTION__
#    elif defined(__FUNCSIG__)
#        define Z4GE_CURRENT_FUNCTION __FUNCSIG__
#    elif defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L
#        define Z4GE_CURRENT_FUNCTION __func__
#    else
#        define Z4GE_CURRENT_FUNCTION "<unknown function>"
#    endif
#endif

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @brief      Compiler / Language standard independent `default` specifier
/// @details    This macro expands to a compiler / language standard independent `default` specifier that can be used in
///             member function declarations within a `struct` or a `class`.
///
/// @par        Default
///             The `default` keyword is used to specify a default constructor which can be called with no arguments.
///                 -#  Declaration of a default constructor inside of class definition.
///                 -#  Definition of the constructor outside of class definition
///                 -#  Deleted default constructor: if it is selected by overload resolution, the program fails to compile.
///                 -#  Defaulted default constructor: the compiler will define the implicit default constructor even if other
///                     constructors are present.
///                 -#  Defaulted default constructor outside of class definition.
///             Default constructors are called during default initializations and value initializations.
///
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef Z4GE_DEFAULT
#    if Z4GE_HAS_DEFAULTED_FUNCTIONS
#        define Z4GE_DEFAULT = default
#    else
#        define Z4GE_DEFAULT
#    endif
#endif

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @brief      Compiler / Language standard independent CXX 14 [[deprecated]] attribute
/// @details    This macro expands to a compiler / language standard independent [[deprecated]] attribute that can be used to
///             denote that the function is deprecated and is likely become obsolete in upcoming versions of the source.
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef Z4GE_DEPRECTAED
#    if Z4GE_CXX14_STANDARD_COMPLIANT
#        define Z4GE_DEPRECATED [[deprecated]]
#    elif Z4GE_COMPILER & Z4GE_COMPILER_MSVC && Z4GE_COMPILER_VERSION > 130000000
#        define Z4GE_DEPRECATED __declspec(deprecated)
#    elif Z4GE_COMPILER & (Z4GE_COMPILER_APPLE_CLANG | Z4GE_COMPILER_LLVM_CLANG | Z4GE_COMPILER_GCC)
#        define Z4GE_DEPRECATED __attribute__ ((deprecated))
#    else
#        define Z4GE_DEPRECATED
#    endif
#endif

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @brief      Compiler / Language standard independent CXX 14 [[deprecated]] attribute with a message
/// @details    This macro expands to a compiler / language standard independent [[deprecated]] attribute that can be used to
///             denote that the function is deprecated and is likely become obsolete in upcoming versions of the source.
/// @param[in]  __MESSAGE__ The message that should be produced while issuing the deprecation warning
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef Z4GE_DEPRECTAED_MESSAGE
#    if Z4GE_CXX14_STANDARD_COMPLIANT
#        define Z4GE_DEPRECATED_MESSAGE(__MESSAGE__) [[deprecated (__MESSAGE__)]]
#    else
#        define Z4GE_DEPRECATED_MESSAGE(__MESSAGE__) Z4GE_DEPRECATED
#    endif
#endif

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @brief      Convinience macro for making constructors explicit, if configured
/// @details    This macro expands to `explicit` if the configuration header was configured with the flag
///             `Z4GE_FORCE_EXPLICIT_CONSTRUCTORS`. This makes the constructors explicit that has been declared explicit using
///             this macro.
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef Z4GE_EXPLICIT
#    if defined(Z4GE_FORCE_EXPLICIT_CONSTRUCTORS)
#        define Z4GE_EXPLICIT explicit
#    else
#        define Z4GE_EXPLICIT
#    endif
#endif

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @brief      Compiler / Language standard independent `extern template`
/// @details    This macro expands to `extern template` if the extern definition for templates are supported by the compiler /
///             language standard, otherwise this macro expands to just template declaration.
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef Z4GE_EXTERN_TEMPLATE
#    if Z4GE_HAS_EXTERN_TEMPLATES
#        define Z4GE_EXTERN_TEMPLATE extern template
#    else
#        define Z4GE_EXTERN_TEMPLATE template
#    endif
#endif

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @brief      Compiler / Language standard independent CXX 17 [[fallthrough]] attribute
/// @details    This macro expands to a compiler / language standard independent [[fallthrough]] attribute that can be used in
///             switch cases to denote explicit fallthrough. This macro is essential in order to avoid compiler warnings
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef Z4GE_FALLTHROUGH
#    if Z4GE_HAS_FALLTHROUGH_ATTRIBUTE
#        define Z4GE_FALLTHROUGH [[fallthrough]]
#    elif Z4GE_COMPILER & (Z4GE_COMPILER_LLVM_CLANG | Z4GE_COMPILER_APPLE_CLANG) && Z4GE_COMPILER_VERSION >= 30300
#        define Z4GE_FALLTHROUGH [[clang::fallthrough]]
#    elif Z4GE_COMPILER & (Z4GE_COMPILER_GCC)
#        define Z4GE_FALLTHROUGH __attribute__ ((fallthrough))
#    else
#        define Z4GE_FALLTHROUGH
#    endif
#endif

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @brief      Compiler / Language standard independent `final` inheritence specifier
/// @details    This macro expands to a compiler / language standard independent `final` specifier that can be used to denote
///             the current derivation will be final derivation of the base class and cannot be derieved anymore.
///
/// @par        Final
///             The `default` keyword is used to specify a default constructor which can be called with no arguments.
///                 -#  Declaration of a default constructor inside of class definition.
///                 -#  Definition of the constructor outside of class definition
///                 -#  Deleted default constructor: if it is selected by overload resolution, the program fails to compile.
///                 -#  Defaulted default constructor: the compiler will define the implicit default constructor even if other
///                     constructors are present.
///                 -#  Defaulted default constructor outside of class definition.
///             Default constructors are called during default initializations and value initializations.
///
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef Z4GE_FINAL
#    if Z4GE_HAS_INHERITANCE_FINAL
#        define Z4GE_FINAL final
#    elif Z4GE_COMPILER & Z4GE_COMPILER_MSVC && Z4GE_COMPILER_VERSION <= 170000000
#        define Z4GE_FINAL sealed
#    else
#        define Z4GE_FINAL
#    endif
#endif

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @brief      Compiler / Language standard independent `constexpr` for `if` statements
/// @details    This macro expands to the constant expressions declaration (`constexpr`) in an `if` statement that is supported
///             by the host compiler. If it is not supported by the host compiler, then this macro expands to just `if`
///
/// @par        If Constant Expressions
///             In a constexpr if statement, the value of condition must be a contextually converted constant expression of
///             type `bool`. If the value is `true`, then statement-false is discarded (if present), otherwise,
///             statement-true is discarded. The return statements in a discarded statement do not participate in function
///             return type deduction
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef Z4GE_IF_CONSTEXPR
#    if Z4GE_HAS_IF_CONSTEXPR
#        define Z4GE_IF_CONSTEXPR if constexpr
#    else
#        define Z4GE_IF_CONSTEXPR if
#    endif
#endif

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @brief      Compiler / Language standard independent `noinline` hint
/// @details    This macro is a compiler / language standard independent `inline` specifier. The inline property can be forced
///             by issuing `Z4GE_FORCE_INLINE` definition before including this header file. This hints the compiler with
///             appropriate attribute / hints to ensure that the functions' body is inlined.
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef Z4GE_INLINE
#    if defined(Z4GE_FORCE_INLINE)
#        if Z4GE_COMPILER & Z4GE_COMPILER_MSVC
#            define Z4GE_INLINE __forceinline
#        elif Z4GE_COMPILER & (Z4GE_COMPILER_APPLE_CLANG | Z4GE_COMPILER_LLVM_CLANG | Z4GE_COMPILER_GCC)
#            define Z4GE_INLINE __attribute__ ((__always_inline__))
#        elif Z4GE_COMPILER & (Z4GE_COMPILER_NVCC)
#            define Z4GE_INLINE __forceinline__
#        else
#            define Z4GE_INLINE inline
#        endif
#    else
#        define Z4GE_INLINE inline
#    endif
#endif

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @brief      Compiler independent hint for branch prediction (likely)
/// @details    This macro expands to a compiler independent hint for branch prediction denoting that the branch is "likely" to
///             be executed.
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef Z4GE_LIKELY
#    if Z4GE_COMPILER & Z4GE_COMPILER_GCC && Z4GE_COMPILER_VERSION >= 30000
#        define Z4GE_LIKELY(__EXPRESSION__) __builtin_expect (!!(__EXPRESSION__), true)
#    elif Z4GE_COMPILER & (Z4GE_COMPILER_APPLE_CLANG | Z4GE_COMPILER_LLVM_CLANG) && Z4GE_HAS_BUILTIN(__builtin_expect)
#        define Z4GE_LIKELY(__EXPRESSION__) __builtin_expect (!!(__EXPRESSION__), true)
#    else
#        define Z4GE_LIKELY(__EXPRESSION__) (__EXPRESSION__)
#    endif
#endif

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @brief      Compiler / Language standard independent CXX 17 [[maybe_unused]] attribute
/// @details    This macro expands to a compiler / language standard independent [[maybe_unused]] attribute that can be used
///             to suppress warnings regarding not using a particular entity with in the translation unit.
///
/// @par        [[maybe_unused]]
///             This attribute can appear in the declaration of the following entities:
///
///             -#  Class / Struct / Union
///             -#  Typedef, including those declared by alias declaration
///             -#  Variable, including static data member
///             -#  Non-static data member
///             -#  Function
///             -#  Enumeration
///             -#  Enumerator
///
///             If the compiler issues warnings on unused entities, that warning is suppressed for any entity declared
///             `[[maybe_unused]]`.
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef Z4GE_MAYBE_UNUSED
#    if Z4GE_HAS_MAYBE_UNUSED_ATTRIBUTE
#        define Z4GE_MAYBE_UNUSED [[maybe_unused]]
#    else
#        define Z4GE_MAYBE_UNUSED
#    endif
#endif

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @brief      Compiler / Language standard independent CXX 17 [[nodicard]] attribute
/// @details    This macro expands to a compiler / language standard independent [[nodicard]] attribute that can be used to
///             denote that the value returned by the function denoted should not be discarded. This encourages the compiler
///             to optimise for that scenario and issue a warning if not followed.
///
/// @par        [[nodicard]]
///             This attribute issuses a warning if,
///
///             -#  A function declared nodiscard is called, or
///             -#  A function returning an enumeration or class declared nodiscard by value is called, or
///             -#  A constructor declared nodiscard is called by explicit type conversion or static_cast, or
///             -#  An object of an enumeration or class type declared nodiscard is initialized by explicit type conversion or
///                 static_cast.
///
///             If the compiler issues warnings on unused entities, that warning is suppressed for any entity declared
///             `[[maybe_unused]]`.
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef Z4GE_NODISCARD
#    if Z4GE_HAS_NODISCARD_ATTRIBUTE
#        define Z4GE_NODISCARD [[nodiscard]]
#    else
#        define Z4GE_NODISCARD
#    endif
#endif

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @brief      Compiler / Language standard independent `noexcept` specifier
/// @details    This macro expands to a compiler / language standard independent [[nodicard]] attribute that can be used to
///             denote that the value returned by the function denoted should not be discarded. This encourages the compiler
///             to optimise for that scenario and issue a warning if not followed.
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef Z4GE_NOEXCEPT
#    if Z4GE_HAS_NOEXCEPT
#        define Z4GE_NOEXCEPT noexcept
#    else
#        define Z4GE_NOEXCEPT
#    endif
#endif

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @brief      Compiler / Language standard independent `noinline` hint
/// @details    This macro expands to a compiler / language standard independent `noinline` that hint that informs the compiler
///             not to inline a function. This is very useful if the developer knows that a particular function should never
///             be inlined and should strictly follow the same without issuing external flags or workarounds.
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef Z4GE_NOINLINE
#    if defined(Z4GE_FORCE_INLINE)
#        if Z4GE_COMPILER & Z4GE_COMPILER_MSVC
#            define Z4GE_NOINLINE __declspec((noinline))
#        elif Z4GE_COMPILER & (Z4GE_COMPILER_APPLE_CLANG | Z4GE_COMPILER_LLVM_CLANG | Z4GE_COMPILER_GCC)
#            define Z4GE_NOINLINE __attribute__ ((__noinline__))
#        elif Z4GE_COMPILER & (Z4GE_COMPILER_NVCC)
#            define Z4GE_NOINLINE __noinline__
#        else
#            define Z4GE_NOINLINE
#        endif
#    else
#        define Z4GE_NOINLINE
#    endif
#endif

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @brief      Compiler / Language standard independent CXX 17 [[noreturn]] attribute
/// @details    This macro expands to a compiler / language standard independent [[noreturn]] attribute that can be used to
///             denote that the denoted function will never return.
///
/// @par        [[noreturn]]
///             This attribute applies to the name of the function being declared in function declarations only. The behavior
///             is undefined if the function with this attribute actually returns.
///
///             The first declaration of the function must specify this attribute if any declaration specifies it.
///             If a function is declared with [[noreturn]] in one translation unit, and the same function is declared without
///             [[noreturn]] in another translation unit, the program is ill-formed; no diagnostic required.
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef Z4GE_NORETURN
#    if Z4GE_COMPILER & Z4GE_COMPILER_MSVC && Z4GE_COMPILER_VERSION >= 130000000
#        define Z4GE_NORETURN __declspec(noreturn)
#    elif Z4GE_HAS_NORETURN
#        define Z4GE_NORETURN [[noreturn]]
#    else
#        define Z4GE_NORETURN
#    endif
#endif

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @brief      Compiler / Language standard independent `override` specifier.
/// @details    This macro expands to the `override` member function specifier that is used to override the base classes'
///             virtual function declarations.
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef Z4GE_OVERRIDE
#    if Z4GE_HAS_OVERRIDE
#        define Z4GE_OVERRIDE override
#    else
#        define Z4GE_OVERRIDE
#    endif
#endif

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @brief      Compiler Hint for read-only memory usage
/// @details    The C99 standard defines a new keyword, restrict, which allows for the improvement of code generation regarding
///             memory usage. Compilers can generate significantly faster code when you are able to use restrict. This macro
///             provides a compiler independent implementation of the `restrict` or equivalent hint / keyword
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef Z4GE_RESTRICT
#    if Z4GE_COMPILER & Z4GE_COMPILER_MSVC && Z4GE_COMPILER_VERSION >= 140000000
#        define Z4GE_RESTRICT __restrict
#    elif Z4GE_COMPILER & (Z4GE_COMPILER_APPLE_CLANG | Z4GE_COMPILER_LLVM_CLANG | Z4GE_COMPILER_GCC)
#        define Z4GE_RESTRICT __restrict
#    elif defined(__STDC_VERSION__) && (__STDC_VERSION__ >= 199901L)
#        define Z4GE_RESTRICT restrict
#    else
#        define Z4GE_RESTRICT
#    endif
#endif

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @brief      Compiler / Language Standard independent `static_assert`
/// @details    The macro expands to a compiler / language standard independent `static_assert` that can be used to include
///             compile-time asserions in code.
/// @note       In case a suitable alternative is not found, the system fallbacks to standard assertions and therefore care must
///             be taken to use static assertions only within executable parts of code
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef Z4GE_STATIC_ASSERT
#    if Z4GE_HAS_STATIC_ASSERT
#        define Z4GE_STATIC_ASSERT(__ASSERTION__, __MESSAGE__) static_assert (__ASSERTION__, __MESSAGE__)
#    elif Z4GE_COMPILER & Z4GE_COMPILER_MSVC
#        define Z4GE_STATIC_ASSERT(__ASSERTION__, __MESSAGE__) typedef char __CASSERT__##__LINE__[(__ASSERTION__) ? 1 : - 1)]
#    else
#        define Z4GE_STATIC_ASSERT(__ASSERTION__, __MESSAGE__) assert (__ASSERTION__, __MESSAGE__)
#    endif
#endif

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @brief      Portable OffsetOf Implementation
/// @details    This macro provides a portable definition for the offsetof macro present in the standard library. The `offsetof`
///             expands to the offset of a member present within a struct or class in bytes. Unfortunately, there are several
///             compatibility and definition related issuses which should be addressed depending upon the toolchain made use of.
///
///             This macro provides a portable, warning free, drop in replacement for the `offsetof` functionality. It makes use
///             of the @ref Z4GE_VOLATILE_OFFSET_OF macro to implement the replacement.
///
/// @par        Bug Tackle - MSVC 1911
///             With respect to VS2017.3 (MSVC 1911), the offsetof macro is broken / incorrectly implemented and thus utilizes
///             the builtin function `__builtin_offsetof`. Apparently this due to the incorrect definition of
///             `_CRT_USE_BUILTIN_OFFSETOF` macro. This macro is an intrinsic definition and therefore cannot be undefined
///             prior to utilization. Therefore, the workaround @ref Z4GE_VOLATILE_OFFSET_OF macro is used to calculate the
///             required offset.
///
/// @par        Bug Tackle - GCC's __builtin_offsetof
///             In the case of GCC, the compiler issues a warning while using the `__builtin_offsetof` macro for determining the
///             offset of a non-PODs (Pointer to Data) even though the compiled library / executable is working as expected
///             without inducing any problems. This macro tackles this by switching to a workaround by constructing a
///             expression that results in the required result and is simple enough to cause neglibile compile-time / runtime
///             cost.
/// @see        Z4GE_VOLATILE_OFFSET_OF
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef Z4GE_OFFSET_OF
#    if Z4GE_COMPILER & Z4GE_COMPILER_GCC
#        define Z4GE_OFFSET_OF(__STRUCT__, __MEMBER__) Z4GE_VOLATILE_OFFSET_OF (__STRUCT__, __MEMBER__)
#    else
#        define Z4GE_OFFSET_OF(__STRUCT__, __MEMBER__) offsetof (__STRUCT__, __MEMBER__)
#    endif
#endif

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @brief      Specifies that a given struct / class has to be packed
/// @details    This macro expands to an GCC / Clang specific `packed` attribute that hints the compiler not to introduce any
///             padding to satify alignment.
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef Z4GE_PACKED
#    if Z4GE_COMPILER & (Z4GE_COMPILER_GCC | Z4GE_COMPILER_APPLE_CLANG | Z4GE_COMPILER_LLVM_CLANG)
#        define Z4GE_PACKED __attribute__ ((packed))
#    else
#        define Z4GE_PACKED
#    endif
#endif

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @brief      Convinience macro for defining a packed declaration
/// @details    This macro expands such the declaration that has given, is packed. This is done based on the compiler's builtin
///             feature.
/// @param[in, out] __DECLARATION__ The declaration that has to be packed
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef Z4GE_PACKED_DECLARATION
#    if Z4GE_COMPILER & (Z4GE_COMPILER_GCC | Z4GE_COMPILER_APPLE_CLANG | Z4GE_COMPILER_LLVM_CLANG)
#        define Z4GE_PACKED_DECLARATION(__DECLARATION__) __DECLARATION__ Z4GE_PACKED
#    elif Z4GE_COMPILER & (Z4GE_COMPILER_INTEL | Z4GE_COMPILER_MSVC)
#        define Z4GE_PACKED_DECLARATION(__DEClARATION__) Z4GE_PRAGMA (pack (push, 1)) __DECLARATION__ Z4GE_PRAGMA (pack (pop))
#    else
#        define Z4GE_PACKED_DECLARATION(__DECLARATION__) __DECLARATION__
#    endif
#endif

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @brief      Portable SizeOf Implementation
/// @details    This macro provides a portable definition for the sizeof macro present in the standard library. The `sizeof`
///             expands to the storage size of an expression / data type in terms of char - bytes. With the introduction of
///             "Extended SizeOf" CXX feature, it is able to determine the size of a member present in an struct / class.
///
///             This macro provides a portable, warning free, drop in replacement for the `sizeof` functionality. It tries to
///             make use of the "Extended SizeOf" ( @ref Z4GE_HAS_EXTENDED_SIZEOF ) CXX feature and provides a fallback
///             implementation in the scenario that the feature is not supported by the host compiler
/// @param[in]  __STRUCT__  The `struct` / `class` that has the @p __MEMBER__
/// @param[in]  __MEMBER__  The member of the @p __STRUCT__ whose size has to be determined
/// @see        Z4GE_HAS_EXTENDED_SIZEOF
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef Z4GE_SIZEOF_MEMBER
#    if Z4GE_HAS_EXTENDED_SIZEOF
#        define Z4GE_SIZEOF_MEMBER(__STRUCT__, __MEMBER__) (sizeof (__STRUCT__::__MEMBER__))
#    else
#        define Z4GE_SIZEOF_MEMBER(__STRUCT__, __MEMBER__) (sizeof ((__STRUCT__*)0)->__MEMBER__)
#    endif
#endif

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @brief      Compiler independent hint for branch prediction (unlikely)
/// @details    This macro expands to a compiler independent hint for branch prediction denoting that the branch is "unlikely"
///             to be executed.
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef Z4GE_UNLIKELY
#    if Z4GE_COMPILER & Z4GE_COMPILER_GCC && Z4GE_COMPILER_VERSION >= 30000
#        define Z4GE_UNLIKELY(__EXPRESSION__) __builtin_expect (!!(__EXPRESSION__), false)
#    elif Z4GE_COMPILER & (Z4GE_COMPILER_APPLE_CLANG | Z4GE_COMPILER_LLVM_CLANG) && Z4GE_HAS_BUILTIN(__builtin_expect)
#        define Z4GE_UNLIKELY(__EXPRESSION__) __builtin_expect (!!(__EXPRESSION__), false)
#    else
#        define Z4GE_UNLIKELY(__EXPRESSION__) (__EXPRESSION__)
#    endif
#endif

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @brief      Convinience macro to suppress warnings about unused variables
/// @details    This macro ensures that a variable that has been passed to a function is not reported as an unused variable
///             (-Wunused is enabled in pedantic error reporting).
/// @param[in]  __ARGUMENT__    The argument passed to the function that has not been used.
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef Z4GE_UNUSED
#    define Z4GE_UNUSED(__ARGUMENT__) ((void)__ARGUMENT__)
#endif

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @brief      OffsetOf Fallback Implementation
/// @details    This macro implements a expression that evaluates to the equivalent value of an element / member's offset in an
///             struct or class by using a workaround (by taking advantage of `volatile` memory). This implementation does not
///             throw warnings or cause errors however, this should be used only in the case that the libcxx implementation is
///             defective or does not satisfy the requirements (eg. MSVC 1911, GCC)
/// @see        Z4GE_OFFSET_OF
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef Z4GE_VOLATILE_OFFSET_OF
#    define Z4GE_VOLATILE_OFFSET_OF(__STRUCT__, __MEMBER__)                                                                    \
        ((size_t)(&reinterpret_cast<const volatile char&> (((__STRUCT__*)0)->__MEMBER__)))
#endif

/// @}
/// @}
/// @endcond

#endif