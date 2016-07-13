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

	/// Set a single component by index from 0 to dim-1
	avl_ainl constexpr auto set(v& vec, const s::size_t idx, const sc scalar) noexcept(ndebug) -> void {
		static_assert(eq<decltype(vec[0]), decltype(scalar)>::value, "Supply a scalar of the vectors element type.");
		assert(idx < dim(vec));
		vec[idx] = scalar;
	}

	/// Access the vector components as value by a range checked index (assert) from 0 to dim-1
	avl_ainl_res constexpr auto get(const v& vec, const s::size_t idx) noexcept(ndebug) -> decltype(vec[idx])  {
		assert(idx < dim(vec));
		return vec[idx];
	}
	
	/// Set a single component by index from 0 to dim-3
	template<s::size_t _Idx>
	avl_ainl constexpr auto set(v& vec, const sc scalar) noexcept -> void {
		static_assert(eq<decltype(vec[0]), decltype(scalar)>::value, "Supply a scalar of the vectors element type.");
		static_assert(is_simd<decltype(vec)>::value || _Idx < dim(vec), "Index out of range");
		vec[_Idx] = scalar;
	}

	/// Access the vector components as value by a range checked index (assert) from 0 to dim-1
	template<s::size_t _Idx>
	avl_ainl_res constexpr auto get(const v& vec) noexcept -> decltype(vec[_Idx])  {
		static_assert(is_simd<decltype(vec)>::value || _Idx < dim(vec), "Index out of range");
		return vec[_Idx];
	}

	/// @}
	
	/// @}
}
#endif // AVL_V_H