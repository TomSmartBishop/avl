#ifndef AVL_AVL_H
#define AVL_AVL_H

#pragma once

/// avl: A Vector Library
/// \author Thomas Pollak

/// \defgroup Macros Macros
/// @{

//compiler independent macros
#define avl_a_if_pow2_or_b(a, b) (!((a) & ((a) - 1)) ? (a) : (b))

/// \def avl_no_inl
/// Empty define to indicate an interntionally not inlined method/function
#define avl_no_inl

/// \def avl_m_inl
/// Suggest inlining, but leave it up to the compiler
#define avl_m_inl inline

//compiler dependent macros
#if defined(__clang__)
#if defined(NDEBUG)
	#define avl_inl inline __attribute__((always_inline))
#else
	#define avl_inl inline
#endif
	#define avl_check_result __attribute__ ((warn_unused_result))
	#define avl_unused_param(x) x __attribute__((__unused__))
	#define avl_surpress_namless_struct
	#define avl_asm_marker(m)
#elif defined(__GNUC__) || defined(__GNUG__)
#if defined(NDEBUG)
	#define avl_inl inline __attribute__((always_inline))
#else
	#define avl_inl inline
#endif
	#define avl_check_result __attribute__ ((warn_unused_result))
	#define avl_unused_param(x) x __attribute__((__unused__))
	#define avl_surpress_namless_struct
	#define avl_asm_marker(m)  asm("#" m)
#elif defined(_MSC_VER)
#if defined(NDEBUG)
	#define avl_inl inline __forceinline
#else
	#define avl_inl inline
#endif
	#define avl_check_result _Check_return_
	#define avl_unused_param(x) __pragma(warning(suppress:4100)) x
	#define avl_surpress_namless_struct __pragma(warning(suppress:4201))
	#define avl_asm_marker(m)
#elif defined(DOXYGEN)
	/// \def avl_inl
	/// Force method/funtion inlining
	#define avl_inl gcc,clang: inline __attribute__((always_inline)) - msvc: inline __forceinline

	/// \def avl_check_result
	/// Let the compiler check if the return value was really used
	#define avl_check_result gcc,clang: __attribute__ ((warn_unused_result)) - msvc: _Check_return_

	/// \def avl_unused_param
	/// Mark an intentionally unused parameter (the signature will therefore differentiate the functionalities)
	#define avl_unused_param(x) gcc,clang: x __attribute__((__unused__)) - msvc: __pragma(warning(suppress:4100)) x

	/// \def avl_surpress_namless_struct
	/// Nameless strcut in unions can be quite useful, but we need to surpress a compiler warning for that
	#define avl_surpress_namless_struct msvc: __pragma(warning(suppress:4201)) - gcc, clang: no warning generated (emtpy)

	/// \def avl_constexpr_void
	/// Inserts an assembler comment to investigate the generated code
	#define avl_asm_marker gcc: asm("#" m) - clang, msvc: not supported (empty)
#endif

//#include <cfg.h>

#include <type_traits>
#include "cfg/cfg.h"
#include "traits/traits.h"
#include "vec/v.h"

//clean up again
#undef avl_check_result
#undef avl_unused_param
#undef avl_surpress_namless_struct
#undef avl_constexpr_void
#undef avl_asm_marker

#endif //#define AVL_AVL_H
