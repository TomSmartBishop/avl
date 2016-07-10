#ifndef AVL_CFG_H
#define AVL_CFG_H

#pragma once

#define AVL_ALLOW_SIMD

#ifdef AVL_ALLOW_SIMD

#  if defined(_MSC_VER)
#    include <intrin.h>
#  elif defined(__GNUC__) && ( defined(__x86_64__) || defined(__i386__) )
#    include <x86intrin.h>
#  elif defined(__GNUC__) && defined(__ARM_NEON__)
#    include <arm_neon.h>
#  elif defined(__GNUC__) && defined(__IWMMXT__)
#    include <mmintrin.h> //WMMX on ARM
#  elif ( defined(__GNUC__) || defined(__xlC__) ) && ( defined(__VEC__) || defined(__ALTIVEC__) )
#    include <altivec.h>
#  elif defined(__GNUC__) && defined(__SPE__)
#    include <spe.h> //PowerPC with SPE
#  endif

#  undef AVL_ALLOW_SIMD

#endif

//#define avl_stl_alias(s)
namespace s = std;

#endif // AVL_CFG_H