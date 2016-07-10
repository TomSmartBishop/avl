#ifndef AVL_V_H
#define AVL_V_H

#pragma once

/// avl: A Vector Library
/// \author Thomas Pollak
namespace avl {

	/// \defgroup Free functions for arbitrary vectors
	/// @{

	/// @name Getters and Setters
	/// @{

	/// Set all vector components to the same scalar
	avl_inl constexpr auto set(v2& vec, const sc scalar) noexcept -> void  {
		static_assert(vec_cmp_eq_s<decltype(vec), decltype(scalar)>::value, "Supply a scalar of the vectors element type.");
		vec[0] = scalar;
		vec[1] = scalar;
	}

	avl_inl constexpr auto set(v3& vec, const sc scalar) noexcept -> void {
		static_assert(vec_cmp_eq_s<decltype(vec), decltype(scalar)>::value, "Supply a scalar of the vectors element type.");
		vec[0] = scalar;
		vec[1] = scalar;
		vec[2] = scalar;
	}

	avl_inl constexpr auto set(v4& vec, const sc scalar) noexcept -> void {
		static_assert(vec_cmp_eq_s<decltype(vec), decltype(scalar)>::value, "Supply a scalar of the vectors element type.");
		vec[0] = scalar;
		vec[1] = scalar;
		vec[2] = scalar;
		vec[3] = scalar;
	}

	avl_inl auto set(__m128& sse_v, const float scalar) noexcept -> void {
		sse_v = _mm_set1_ps(scalar);
	}

	/// @}

	/// @}
}
#endif // AVL_V_H