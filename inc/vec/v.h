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
		static_assert(vec_cmp_eq_s<decltype(vec[0]), decltype(scalar)>::value, "Supply a scalar of the vectors element type.");
		vec[0] = scalar;
		vec[1] = scalar;
	}

	avl_inl constexpr auto set(v3& vec, const sc scalar) noexcept -> void {
		static_assert(vec_cmp_eq_s<decltype(vec[0]), decltype(scalar)>::value, "Supply a scalar of the vectors element type.");
		vec[0] = scalar;
		vec[1] = scalar;
		vec[2] = scalar;
	}

	avl_inl constexpr auto set(v4& vec, const sc scalar) noexcept -> void {
		static_assert(vec_cmp_eq_s<decltype(vec[0]), decltype(scalar)>::value, "Supply a scalar of the vectors element type.");
		vec[0] = scalar;
		vec[1] = scalar;
		vec[2] = scalar;
		vec[3] = scalar;
	}

	avl_inl auto set(__m128& sse_v, const float scalar) noexcept -> void {
		sse_v = _mm_set1_ps(scalar);
	}

	/// Set a single component by index from 0 to dim-1
	avl_inl constexpr auto set(v& vec, const s::size_t idx, const sc scalar) noexcept(ndebug) -> void {
		static_assert(vec_cmp_eq_s<decltype(vec[0]), decltype(scalar)>::value, "Supply a scalar of the vectors element type.");
		assert(idx < info<decltype(vec)>::dim);
		vec[idx] = scalar;
	}

	/// Access the vector components as value by a range checked index (assert) from 0 to dim-1
	avl_inl_res constexpr auto get(const v& vec, const s::size_t idx) noexcept(ndebug) -> decltype(vec[idx])  {
		assert(idx < vec.dim);
		return vec[idx];
	}
	
	/// Set a single component by index from 0 to dim-1
	template<s::size_t _Idx>
	avl_inl constexpr auto set(v& vec, const sc scalar) noexcept -> void {
		static_assert(vec_cmp_eq_s<decltype(vec[0]), decltype(scalar)>::value, "Supply a scalar of the vectors element type.");
		static_assert(_Idx < dim(vec), "Index out of range");
		vec[_Idx] = scalar;
	}

	/// Access the vector components as value by a range checked index (assert) from 0 to dim-1
	template<s::size_t _Idx>
	avl_inl_res constexpr auto get(const v& vec) noexcept -> decltype(vec[_Idx])  {
		static_assert(_Idx < dim(vec), "Index out of range");
		return vec[_Idx];
	}

	/// @}
	
	/// @}
}
#endif // AVL_V_H