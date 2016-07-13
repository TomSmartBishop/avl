#ifndef AVL_V2_H
#define AVL_V2_H

#pragma once

/// avl: A Vector Library
/// \author Thomas Pollak
namespace avl {

	/// \defgroup Free functions for 2 component vectors
	/// @{

	/// @name Getters and Setters
	/// @{

	/// Set all vector components to the same scalar
	avl_ainl constexpr auto set_all(v2& vec, const sc scalar) noexcept -> void  {
		static_assert(eq<decltype(vec[0]), decltype(scalar)>::value, "Supply a scalar of the vectors element type.");
		vec[0] = scalar;
		vec[1] = scalar;
	}

	/// Set all vector components individually
	avl_ainl constexpr auto set_all(v2& vec, const sc x, const sc y) noexcept -> void  {
		static_assert(eq<decltype(vec[0]), decltype(x)>::value, "Supply a scalar of the vectors element type.");
        static_assert(eq<decltype(vec[1]), decltype(y)>::value, "Supply a scalar of the vectors element type.");
		vec[0] = x;
		vec[1] = y;
	}
    
    /// Set all vector components individually
	avl_ainl constexpr auto set_all(v2& vec, const sc scalars[2]) noexcept -> void  {
		static_assert(eq<decltype(vec[0]), decltype(scalars[0])>::value, "Supply a scalar of the vectors element type.");
        static_assert(eq<decltype(vec[1]), decltype(scalars[1])>::value, "Supply a scalar of the vectors element type.");
		vec[0] = scalars[0];
		vec[1] = scalars[1];
	}
    
    /// Set all vector components individually
    template <s::size_t _Dim>
	avl_ainl constexpr auto set_all(v2& vec, const sc* scalars) noexcept -> void  {
        static_assert(_Dim>1, "Supply at least 2 scalars.");
		static_assert(eq<decltype(vec[0]), decltype(scalars[0])>::value, "Supply a scalar of the vectors element type.");
        static_assert(eq<decltype(vec[1]), decltype(scalars[1])>::value, "Supply a scalar of the vectors element type.");
		vec[0] = scalars[0];
		vec[1] = scalars[1];
	}
    
	/// @}
	
	/// @}
}
#endif // AVL_V2_H