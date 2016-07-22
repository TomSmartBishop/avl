#ifndef AVL_V_INL
#define AVL_V_INL

#pragma once

/// avl: A Vector Library
/// \author Thomas Pollak
namespace avl {
	
	/// \defgroup Free functions for arbitrary vectors
	/// @{
	
	//component type helper
	avl_ainl_res constexpr auto cmp(const v& vec) noexcept -> rem_const_ref_t<decltype(vec[0])> {
		return vec[0];
	}
	
	/// @name Getters and Setters
	/// @{
	
	/// Set a single component by index from 0 to dim-1
	avl_ainl constexpr auto set(v& vec, const s::size_t idx, const sc scalar) noexcept(ndebug) -> void {
		static_assert(eq<decltype(vec[0]), decltype(scalar)>::value, "Supply a scalar of the vectors element type.");
		assert(idx < dim< rem_const_ref_t< decltype(vec) > >::value);
		vec[idx] = scalar;
	}
	
	/// Access the vector components as value by a range checked index (assert) from 0 to dim-1
	avl_ainl_res constexpr auto get(const v& vec, const s::size_t idx) noexcept(ndebug) ->decltype(cmp(vec)) {
		//decltype(cmp(vec)) { //causes the compiler to crash
		assert(idx < dim< rem_const_ref_t< decltype(vec) > >::value);
		return vec[idx];
	}
	
	/// Set a single component by index from 0 to dim-3
	template<s::size_t _Idx>
	avl_ainl constexpr auto set(v& vec, const sc scalar) noexcept -> void {
		static_assert(eq<decltype(vec[_Idx]), decltype(scalar)>::value, "Supply a scalar of the vectors element type.");
		static_assert(/*is_simd<decltype(vec)>::value ||*/ _Idx < dim< rem_const_ref_t< decltype(vec) > >::value, "Index out of range");
		vec[_Idx] = scalar;
	}
	
	/// Access the vector components as value by a range checked index (assert) from 0 to dim-1
	template<s::size_t _Idx>
	avl_ainl_res constexpr auto get(const v& vec) noexcept -> decltype(cmp(vec)) {
		//decltype(cmp(vec))  { //also yields a compiler problem (but not a segfault)
		static_assert(/*is_simd<decltype(vec)>::value ||*/ _Idx < dim< rem_const_ref_t< decltype(vec) > >::value, "Index out of range");
		return vec[_Idx];
	}
	
	/// @}
	/// @name Vector Length Operations
	/// @{
	
	/// Returns a new vector with the requested length
	avl_ainl_res constexpr auto len_mk(const v& vec, const sc new_len) noexcept(ndebug) {
		assert(new_len!=decltype(new_len){0});
		return mul_mk(vec, new_len / len(vec));
	}
	
	/// Set the length of the vector
	avl_ainl constexpr auto len_set(v& vec, const sc new_len) noexcept -> void {
		assert(new_len!=decltype(new_len){0});
		mul_set(vec, new_len / len(vec));
	}
	
	/// Calculate the length of the vector, prefere len_sqr when comparing distances (faster)
	avl_ainl_res constexpr auto len(const v& vec) noexcept -> decltype(cmp(vec)) {
		//len_sqr will never return any negativ values so we can gurantee noexcept
		return static_cast<decltype(cmp(vec))>( s::sqrt( len_sqr(vec) ) );
	}
	
	/// Returns a normalized vector
	avl_ainl_res constexpr auto norm_mk(const v& vec) noexcept(ndebug) {
		return div_mk(vec, len(vec)); //div might assert in debug
	}
	
	/// Returns a normalized vector
	avl_inl_res constexpr auto norm_mk(const v& vec, const v& vec_if_zero_len) noexcept(ndebug) {
		auto l = len(vec);
		if(l==decltype(l){0})
			return vec_if_zero_len;
		else
			return div_mk(vec, l); //div might assert in debug
	}
	
	/// Normalize the current vector
	avl_ainl constexpr auto norm_set(v& vec) noexcept(ndebug) -> void {
		div_set(vec, len(vec));
	}
	
	/// Normalize the current vector
	avl_inl constexpr auto norm_set(v& vec, const v& vec_if_zero_len) noexcept(ndebug) -> void {
		auto l = len(vec);
		if(l==decltype(l){0})
			set_all(vec, vec_if_zero_len);
		else
			div_set(vec, len(vec));
	}
	
	/// Normalize the current vector
	avl_ainl_res constexpr auto norm(v& vec) noexcept(ndebug) -> decltype(vec) {
		div_set(vec, len(vec));
		return vec;
	}
	
	/// Normalize the current vector
	avl_inl_res constexpr auto norm(v& vec, const v& vec_if_zero_len) noexcept(ndebug) -> decltype(vec) {
		auto l = len(vec);
		if(l==decltype(l){0})
			set_all(vec, vec_if_zero_len);
		else
			div_set(vec, len(vec));
		return vec;
	}
	
	/// @}
	/// @name Vector Operations With Scalar Results
	/// @{
	
	avl_ainl_res constexpr auto angle_rd(const v& vec, const v& other) noexcept -> decltype(cmp(vec)) {
		return s::acos( dot(vec, other) / (len(vec) * len(other)) );
	}
	
// 	avl_ainl_res constexpr auto angle_dg(const v& vec, const v& other) noexcept -> decltype(cmp(vec)) {
// 		return s::acos( dot(vec, other) / (len(vec) * len(other)) ) * cnst<cmp>::to_deg;
// 	}
	
	/// @}
	
	/// @}
}
#endif // AVL_V_INL