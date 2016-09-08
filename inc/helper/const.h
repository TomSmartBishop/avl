#ifndef AVL_CONST_H
#define AVL_CONST_H

#include <cmath>

/// avl: A Vector Library
/// \author Thomas Pollak
namespace avl
{
	/// Frequently used constants in floating point precision of <P>
	// actually these constexpr do not require a struct according to c++14, but through compiler limitations (msvc) we stick to this format
	template<typename P>
	struct cnst
	{
		static constexpr P  pi			{ M_PI };
		static constexpr P  pi_2		{ M_PI_2 };
		static constexpr P  pi_4		{ M_PI_4 };
		static constexpr P  pi_inv		{ M_1_PI };
		
		static constexpr P  to_deg		{ 180.0 * pi_inv };
		static constexpr P  to_rad		{ pi / 180.0 };
		
		static constexpr P  sqrt2		{ M_SQRT2 };
		static constexpr P  sqrt2_inv	{ M_SQRT1_2 };
		
		static constexpr P  one			{  1   };
		static constexpr P  minus_one	{ -1   };
		static constexpr P  zero		{  0   };
		static constexpr P  half		{  0.5 };
		
		static constexpr P  sml_epsln	{ 0.000001 };
		static constexpr P  big_epsln	{ 0.001 };
		
	};
	
	template<typename P> constexpr P cnst<P>::pi;
	template<typename P> constexpr P cnst<P>::pi_2;
	template<typename P> constexpr P cnst<P>::pi_4;
	template<typename P> constexpr P cnst<P>::pi_inv;
	
	template<typename P> constexpr P cnst<P>::to_deg;
	template<typename P> constexpr P cnst<P>::to_rad;
	
	template<typename P> constexpr P cnst<P>::sqrt2;
	template<typename P> constexpr P cnst<P>::sqrt2_inv;
	
	template<typename P> constexpr P cnst<P>::one;
	template<typename P> constexpr P cnst<P>::minus_one;
	template<typename P> constexpr P cnst<P>::zero;
	template<typename P> constexpr P cnst<P>::half;
	
	template<typename P> constexpr P cnst<P>::sml_epsln;
	template<typename P> constexpr P cnst<P>::big_epsln;
	
}

#endif // AVL_CONST_H