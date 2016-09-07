#ifndef AVL_V_H
#define AVL_V_H

#pragma once

/// avl: A Vector Library
/// \author Thomas Pollak
namespace avl
{
	/// \defgroup Helper functions
	/// \{
	
	//Component type helper
	avl_ainl_res constexpr auto cmp(const v& vec) noexcept -> rem_const_ref_t<decltype(vec[0])>;
	
	/// \}
	/// \defgroup Getters and setters for all vectors
	/// \{
	
	/// Access the vector components by a range checked index from 0 to dim-1
	avl_ainl_res constexpr auto get(const v& vec, const s::size_t idx) noexcept(ndebug||exuse) -> decltype(cmp(vec));
	
	/// Access the vector components by a static range checked index from 0 to dim-1
	template<s::size_t _Idx> avl_ainl_res constexpr auto get(const v& vec) noexcept -> decltype(cmp(vec));
	
	/// Set a single component by index from 0 to dim-1
	avl_ainl constexpr auto set(v& vec, const s::size_t idx, const sc scalar) noexcept(ndebug||exuse) -> void;
	
	/// Set a single component by static index from 0 to dim-1
	template<s::size_t _Idx> avl_ainl constexpr auto set(v& vec, const sc scalar) noexcept -> void;
	
	/// \}
	/// \defgroup Vector length operations
	/// \{
	
	/// Returns a new vector with the requested length
	avl_ainl_res constexpr auto setlen_mk(const v& vec, const sc len_to_set) noexcept(ndebug||exuse);
	
	/// Set the length of the vector
	avl_ainl constexpr auto setlen_set(v& vec, const sc len_to_set) noexcept(ndebug||exuse) -> void;
	
	/// Set the length of the vector and return the same vector (chained)
	avl_ainl_res constexpr auto setlen(v& vec, const sc len_to_set) noexcept(ndebug||exuse) -> decltype(vec);
	
	/// Calculate the length of the vector, prefere len_sqr when comparing distances
	avl_ainl_res constexpr auto len(const v& vec) noexcept -> decltype(cmp(vec));
	
	/// Returns a normalized vector
	avl_ainl_res constexpr auto norm_mk(const v& vec ) noexcept(ndebug||exuse);
	
	/// Returns a normalized vector, use alternative vector if the current vector length is 0
	avl_ainl_res constexpr auto norm_mk(const v& vec , const v& vec_if_zero_len) noexcept;
	
	/// Normalize the current vector
	avl_ainl constexpr auto norm_set(v& vec ) noexcept -> void;
	
	/// Normalize the current vector, use alternative vector if the current vector length is 0
	avl_ainl constexpr auto norm_set(v& vec , const v& vec_if_zero_len) noexcept -> void;
	
	/// Normalize the current vector and return the same vector (chained)
	avl_ainl_res constexpr auto norm(v& vec ) noexcept -> decltype(vec);
	
	/// Normalize the current vector and return the same vector (chained), use alternative vector if the current vector length is 0
	avl_ainl_res constexpr auto norm(v& vec , const v& vec_if_zero_len) noexcept -> decltype(vec);
	
	/// \}
	/// \defgroup Spacial operations
	/// \{
	
	/// Calculate the angle between two vectors in radian
	avl_ainl_res constexpr auto angle_rd(const v& vec, const decltype(vec) other) noexcept -> decltype(cmp(vec));
	
	/// Calculate the angle between two vectors in degree
	avl_ainl_res constexpr auto angle_dg(const v& vec, const decltype(vec) other) noexcept -> decltype(cmp(vec));
	
	/// \}
}
#endif // AVL_V_H