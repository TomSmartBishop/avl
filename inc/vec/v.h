#ifndef AVL_V_H
#define AVL_V_H

#pragma once

/// avl: A Vector Library
/// \author Thomas Pollak
namespace avl {
	
	/// \defgroup Free functions for arbitrary vectors
	/// @{
	
	//component type helper
	avl_ainl_res constexpr auto cmp(const v& vec) noexcept -> rem_const_ref_t<decltype(vec[0])>;
	
	/// @name Getters and Setters
	/// @{
	
	/// Set a single component by index from 0 to dim-1
	avl_ainl constexpr auto set(v& vec, const s::size_t idx, const sc scalar) noexcept(ndebug) -> void;
	
	/// Access the vector components as value by a range checked index (assert) from 0 to dim-1
	avl_ainl_res constexpr auto get(const v& vec, const s::size_t idx) noexcept(ndebug) ->decltype(cmp(vec));
	
	/// Set a single component by index from 0 to dim-3
	template<s::size_t _Idx>
	avl_ainl constexpr auto set(v& vec, const sc scalar) noexcept -> void;
	
	/// Access the vector components as value by a range checked index (assert) from 0 to dim-1
	template<s::size_t _Idx>
	avl_ainl_res constexpr auto get(const v& vec) noexcept -> decltype(cmp(vec));
	
	/// @}
	/// @name Vector Length Operations
	/// @{
	
	/// Returns a new vector with the requested length
	avl_ainl_res constexpr auto len_mk(const v& vec, const sc new_len) noexcept(ndebug);
	
	/// Set the length of the vector
	avl_ainl constexpr auto len_set(v& vec, const sc new_len) noexcept -> void;
	
	/// Calculate the length of the vector, prefere len_sqr when comparing distances (faster)
	avl_ainl_res constexpr auto len(const v& vec) noexcept -> decltype(cmp(vec));
	
	/// Returns a normalized vector
	avl_ainl_res constexpr auto norm_mk(const v& vec) noexcept(ndebug);
	
	/// Returns a normalized vector
	avl_inl_res constexpr auto norm_mk(const v& vec, const v& vec_if_zero_len) noexcept(ndebug);
	
	/// Normalize the current vector
	avl_ainl constexpr auto norm_set(v& vec) noexcept(ndebug) -> void;
	
	/// Normalize the current vector
	avl_inl constexpr auto norm_set(v& vec, const v& vec_if_zero_len) noexcept(ndebug) -> void;
	
	/// Normalize the current vector
	avl_ainl_res constexpr auto norm(v& vec) noexcept(ndebug) -> decltype(vec);
	
	/// Normalize the current vector
	avl_inl_res constexpr auto norm(v& vec, const v& vec_if_zero_len) noexcept(ndebug) -> decltype(vec);
	
	/// @}
	/// @name Vector Operations With Scalar Results
	/// @{
	
	avl_ainl_res constexpr auto angle_rd(const v& vec, const v& other) noexcept -> decltype(cmp(vec));
	
// 	avl_ainl_res constexpr auto angle_dg(const v& vec, const v& other) noexcept -> decltype(cmp(vec));
	
	/// @}
	
	/// @}
}
#endif // AVL_V_H