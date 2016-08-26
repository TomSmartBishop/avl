#ifndef AVL_CONST_H
#define AVL_CONST_H

/// avl: A Vector Library
/// \author Thomas Pollak
namespace avl
{
	/// Frequently used constants in floating point precision of <P>
	template<typename P>
	struct cnst {
		//actually these constexpr do not require a struct according to c++14, but through compiler limitations (msvc) we stick to this format
		static constexpr P pi		{ M_PI };
		static constexpr P piH		{ M_PI_2 };
		static constexpr P piQ		{ M_PI_4 };
		static constexpr P piInv	{ M_1_PI };
		
		static constexpr P toDeg	{ 180.0 * piInv };
		static constexpr P toRad	{ pi / 180.0 };
		
		static constexpr P sqrt2	{ M_SQRT2 };
		static constexpr P sqrt2Inv	{ M_SQRT1_2 };
		
		static constexpr P one		{  1 };
		static constexpr P minus_one{ -1 };
		static constexpr P zero		{  0 };
		
		static constexpr P smlEpsln	{ 0.000001 };
		static constexpr P bigEpsln	{ 0.001 };
	};
	
#endif // AVL_CONST_H
