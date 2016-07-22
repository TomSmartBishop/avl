#ifndef AVL_AVL_H
#define AVL_AVL_H

#pragma once

/// avl: A Vector Library
/// \author Thomas Pollak

/// \defgroup Macros Macros
/// @{

//compiler independent macros
#define avl_a_if_pow2_or_b(a, b) (!((a) & ((a) - 1)) ? (a) : (b))

/// \def avl_inl_res
/// Cobination of avl_noinl and avl_res
#define avl_noinl_res avl_noinl avl_res

/// \def avl_inl_res
/// Cobination of avl_inl and avl_res
#define avl_inl_res avl_inl avl_res

/// \def avl_inl_res
/// Cobination of avl_ainl and avl_res
#define avl_ainl_res avl_ainl avl_res

/// \def avl_noinl
/// Empty define to indicate an interntionally not inlined method/function
#define avl_noinl

/// \def avl_inl
/// Suggest inlining, but leave it up to the compiler
#define avl_inl inline

//compiler dependent macros
#if defined(__clang__)
    #if defined(NDEBUG)
        #define avl_ainl inline __attribute__((always_inline))
    #else
        #define avl_ainl inline
    #endif
	#define avl_res __attribute__ ((warn_unused_result))
	#define avl_unused(x) x __attribute__((__unused__))
	#define avl_nameless
	#define avl_asm_marker(m)
#elif defined(__GNUC__) || defined(__GNUG__)
    #if defined(NDEBUG)
        #define avl_ainl inline __attribute__((always_inline))
    #else
        #define avl_ainl inline
    #endif
	#define avl_res __attribute__ ((warn_unused_result))
	#define avl_unused(x) x __attribute__((__unused__))
	#define avl_nameless
	#define avl_asm_marker(m)  asm("#" m)
#elif defined(_MSC_VER)
    #if defined(NDEBUG)
        #define avl_ainl inline __forceinline
    #else
        #define avl_ainl inline
    #endif
	#define avl_res _Check_return_
	#define avl_unused(x) __pragma(warning(suppress:4100)) x
	#define avl_nameless __pragma(warning(suppress:4201))
	#define avl_asm_marker(m)
#elif defined(DOXYGEN)
	/// \def avl_inl
	/// Force method/funtion inlining
	#define avl_ainl gcc,clang: inline __attribute__((always_inline)) - msvc: inline __forceinline

	/// \def avl_res
	/// Let the compiler check if the return value was really used
	#define avl_res gcc,clang: __attribute__ ((warn_unused_result)) - msvc: _Check_return_

	/// \def avl_unused
	/// Mark an intentionally unused parameter (the signature will therefore differentiate the functionalities)
	#define avl_unused(x) gcc,clang: x __attribute__((__unused__)) - msvc: __pragma(warning(suppress:4100)) x

	/// \def avl_nameless
	/// Nameless strcut in unions can be quite useful, but we need to surpress a compiler warning for that
	#define avl_nameless msvc: __pragma(warning(suppress:4201)) - gcc, clang: no warning generated (emtpy)

	/// \def avl_constexpr_void
	/// Inserts an assembler comment to investigate the generated code
	#define avl_asm_marker gcc: asm("#" m) - clang, msvc: not supported (empty)
#endif

namespace avl {
    #if defined(NDEBUG)
        static constexpr bool ndebug = true;
    #else
        static constexpr bool ndebug = false;
    #endif
}

#include <cassert>
#include <type_traits>
#include <cstdint>


#include "cfg/cfg.h"
#include "traits/traits.h"
#include "vec/v.h"
#include "vec/v2.h"
#include "vec/v3.h"
#include "vec/v4.h"
#include "vec/v4_simd.h"

#include "vec/v.inl"
#include "vec/v2.inl"
#include "vec/v3.inl"
#include "vec/v4.inl"

//clean up again
#undef avl_a_if_pow2_or_b
#undef avl_noinl_res
#undef avl_inl_res
#undef avl_ainl_res
#undef avl_noinl
#undef avl_inl
#undef avl_ainl
#undef avl_res
#undef avl_unused
#undef avl_nameless
#undef avl_asm_marker

#endif // AVL_AVL_H
