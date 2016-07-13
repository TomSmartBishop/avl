#ifndef AVL_V4_H
#define AVL_V4_H

#pragma once

/// avl: A Vector Library
/// \author Thomas Pollak
namespace avl {

	/// \defgroup Free functions for 4 component vectors
	/// @{

	/// @name Getters and Setters
	/// @{

	avl_ainl constexpr auto set_all(v4& vec, const sc scalar) noexcept -> void {
		static_assert(eq<decltype(vec[0]), decltype(scalar)>::value, "Supply a scalar of the vectors element type.");
		vec[0] = scalar;
		vec[1] = scalar;
		vec[2] = scalar;
		vec[3] = scalar;
	}

    /// Set all vector components individually
	avl_ainl constexpr auto set_all(v4& vec, const sc x, const sc y, const sc z, const sc w) noexcept -> void  {
		static_assert(eq<decltype(vec[0]), decltype(x)>::value, "Supply a scalar of the vectors element type.");
        static_assert(eq<decltype(vec[1]), decltype(y)>::value, "Supply a scalar of the vectors element type.");
        static_assert(eq<decltype(vec[2]), decltype(z)>::value, "Supply a scalar of the vectors element type.");
        static_assert(eq<decltype(vec[3]), decltype(w)>::value, "Supply a scalar of the vectors element type.");
		vec[0] = x;
		vec[1] = y;
        vec[2] = z;
        vec[3] = w;
	}
    
    /// Set all vector components individually
	avl_ainl constexpr auto set_all(v4& vec, const sc scalars[3]) noexcept -> void  {
		static_assert(eq<decltype(vec[0]), decltype(scalars[0])>::value, "Supply a scalar of the vectors element type.");
        static_assert(eq<decltype(vec[1]), decltype(scalars[1])>::value, "Supply a scalar of the vectors element type.");
        static_assert(eq<decltype(vec[2]), decltype(scalars[2])>::value, "Supply a scalar of the vectors element type.");
        static_assert(eq<decltype(vec[3]), decltype(scalars[3])>::value, "Supply a scalar of the vectors element type.");
		vec[0] = scalars[0];
		vec[1] = scalars[1];
        vec[2] = scalars[2];
        vec[3] = scalars[3];
	}
    
    /// Set all vector components individually
    template <s::size_t _Dim>
	avl_ainl constexpr auto set_all(v4& vec, const sc* scalars) noexcept -> void  {
        static_assert(_Dim>3, "Supply at least 4 scalars.");
		static_assert(eq<decltype(vec[0]), decltype(scalars[0])>::value, "Supply a scalar of the vectors element type.");
        static_assert(eq<decltype(vec[1]), decltype(scalars[1])>::value, "Supply a scalar of the vectors element type.");
        static_assert(eq<decltype(vec[2]), decltype(scalars[2])>::value, "Supply a scalar of the vectors element type.");
		static_assert(eq<decltype(vec[3]), decltype(scalars[3])>::value, "Supply a scalar of the vectors element type.");
		vec[0] = scalars[0];
		vec[1] = scalars[1];
        vec[2] = scalars[2];
        vec[3] = scalars[3];
	}
    
	/// @}
	
	/// @}
}
#endif // AVL_V4_H