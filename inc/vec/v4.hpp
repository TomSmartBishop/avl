// NOTICE: This file is generated using the template file v.jinja
#ifndef AVL_V4_HPP
#define AVL_V4_HPP

#pragma once

/// avl: A Vector Library
/// \author Thomas Pollak
namespace avl
{

	/// \defgroup Vector length operations
	/// \{
	
	/// Returns a new vector with the requested length
	template <int DIM_N=4> avl_ainl_res constexpr auto setlen_mk(const v4& vec, const sc len_to_set) noexcept(ndebug||exuse);
	
	/// Set the length of the vector
	template <int DIM_N=4> avl_ainl constexpr auto setlen_set(v4& vec, const sc len_to_set) noexcept(ndebug||exuse) -> void;
	
	/// Set the length of the vector and return the same vector (chained)
	template <int DIM_N=4> avl_ainl_res constexpr auto setlen(v4& vec, const sc len_to_set) noexcept(ndebug||exuse) -> decltype(vec);
	
	/// Calculate the length of the vector, prefere len_sqr when comparing distances
	template <int DIM_N=4> avl_ainl_res constexpr auto len(const v4& vec) noexcept -> decltype(cmp(vec));
	
	/// Calculate the square length of the vector
	template <int DIM_N=4> avl_ainl_res constexpr auto len_sqr(const v4& vec) noexcept -> decltype(cmp(vec));
	
	/// Returns a normalized vector
	template <int DIM_N=4> avl_ainl_res constexpr auto norm_mk(const v4& vec ) noexcept(ndebug||exuse);
	
	/// Returns a normalized vector, use alternative vector if the current vector length is 0
	template <int DIM_N=4> avl_ainl_res constexpr auto norm_mk(const v4& vec , const v4& vec_if_zero_len) noexcept;
	
	/// Normalize the current vector
	template <int DIM_N=4> avl_ainl constexpr auto norm_set(v4& vec ) noexcept -> void;
	
	/// Normalize the current vector, use alternative vector if the current vector length is 0
	template <int DIM_N=4> avl_ainl constexpr auto norm_set(v4& vec , const v4& vec_if_zero_len) noexcept -> void;
	
	/// Normalize the current vector and return the same vector (chained)
	template <int DIM_N=4> avl_ainl_res constexpr auto norm(v4& vec ) noexcept -> decltype(vec);
	
	/// Normalize the current vector and return the same vector (chained), use alternative vector if the current vector length is 0
	template <int DIM_N=4> avl_ainl_res constexpr auto norm(v4& vec , const v4& vec_if_zero_len) noexcept -> decltype(vec);
	
	/// \}
	/// \defgroup Spacial operations
	/// \{
	
	/// Calculate the area of the spawned triangle (restricted to 3 dimensions)
	avl_inl_res constexpr auto area3(v4 vec, const decltype(vec)& other) noexcept -> decltype(cmp(vec));
	
	/// Calculate the cross product (restricted to 3 dimensions)
	avl_ainl_res constexpr auto cross3_mk(const v4& vec, const v4& other) noexcept;
	
	/// Calculate the cross product (restricted to 3 dimensions)
	avl_ainl constexpr auto cross3_set(v4& vec, const v4& other) noexcept -> void;
	
	/// Calculate the cross product (restricted to 3 dimensions)
	avl_ainl_res constexpr auto cross3(v4& vec, const v4& other) noexcept -> decltype(vec);
	
	/// \}
	/// \defgroup Getter and setters for 4 component vectors
	/// \{
	
	/// Set all vector components to the same scalar
	template <int DIM_N=4> avl_ainl constexpr auto set_all(v4& vec, const sc scalar) noexcept -> void;
	
	/// Set all vector components individually
	template <int DIM_N=4> avl_ainl constexpr auto set_all(v4& vec, const sc x, const sc y, const sc z, const sc w) noexcept -> void;
	
	/// Set all vector components individually by a fixed size array
	template <int DIM_N=4> avl_ainl constexpr auto set_all(v4& vec, const sc scalars[ 4 ]) noexcept -> void;
	
	/// \}
	/// \defgroup Base math vector operations for 4 component vectors
	/// \{
	
	// add_mk
	template <int DIM_N=4> avl_ainl_res constexpr auto add_mk(const v4& vec, const v4& other) noexcept;
	
	// add_mk (scalar)
	template <int DIM_N=4> avl_ainl_res constexpr auto add_mk(const v4& vec, const sc scalar) noexcept;
	
	// add_set
	template <int DIM_N=4> avl_ainl constexpr auto add_set(v4& vec, const v4& other) noexcept -> void;
	
	// add_set (scalar)
	template <int DIM_N=4> avl_ainl constexpr auto add_set(v4& vec, const sc scalar) noexcept -> void;
	
	// add
	template <int DIM_N=4> avl_ainl_res constexpr auto add(v4& vec, const v4& other) noexcept -> decltype(vec);
	
	// add (scalar)
	template <int DIM_N=4> avl_ainl_res constexpr auto add(v4& vec, const sc scalar) noexcept -> decltype(vec);
	
	// sub_mk
	template <int DIM_N=4> avl_ainl_res constexpr auto sub_mk(const v4& vec, const v4& other) noexcept;
	
	// sub_mk (scalar)
	template <int DIM_N=4> avl_ainl_res constexpr auto sub_mk(const v4& vec, const sc scalar) noexcept;
	
	// sub_set
	template <int DIM_N=4> avl_ainl constexpr auto sub_set(v4& vec, const v4& other) noexcept -> void;
	
	// sub_set (scalar)
	template <int DIM_N=4> avl_ainl constexpr auto sub_set(v4& vec, const sc scalar) noexcept -> void;
	
	// sub
	template <int DIM_N=4> avl_ainl_res constexpr auto sub(v4& vec, const v4& other) noexcept -> decltype(vec);
	
	// sub (scalar)
	template <int DIM_N=4> avl_ainl_res constexpr auto sub(v4& vec, const sc scalar) noexcept -> decltype(vec);
	
	// mul_mk
	template <int DIM_N=4> avl_ainl_res constexpr auto mul_mk(const v4& vec, const v4& other) noexcept;
	
	// mul_mk (scalar)
	template <int DIM_N=4> avl_ainl_res constexpr auto mul_mk(const v4& vec, const sc scalar) noexcept;
	
	// mul_set
	template <int DIM_N=4> avl_ainl constexpr auto mul_set(v4& vec, const v4& other) noexcept -> void;
	
	// mul_set (scalar)
	template <int DIM_N=4> avl_ainl constexpr auto mul_set(v4& vec, const sc scalar) noexcept -> void;
	
	// mul
	template <int DIM_N=4> avl_ainl_res constexpr auto mul(v4& vec, const v4& other) noexcept -> decltype(vec);
	
	// mul (scalar)
	template <int DIM_N=4> avl_ainl_res constexpr auto mul(v4& vec, const sc scalar) noexcept -> decltype(vec);
	
	// div_mk
	template <int DIM_N=4> avl_ainl_res constexpr auto div_mk(const v4& vec, const v4& other) noexcept(ndebug||exuse);
	
	// div_mk (scalar)
	template <int DIM_N=4> avl_ainl_res constexpr auto div_mk(const v4& vec, const sc scalar) noexcept(ndebug||exuse);
	
	// div_set
	template <int DIM_N=4> avl_ainl constexpr auto div_set(v4& vec, const v4& other) noexcept(ndebug||exuse) -> void;
	
	// div_set (scalar)
	template <int DIM_N=4> avl_ainl constexpr auto div_set(v4& vec, const sc scalar) noexcept(ndebug||exuse) -> void;
	
	// div
	template <int DIM_N=4> avl_ainl_res constexpr auto div(v4& vec, const v4& other) noexcept(ndebug||exuse) -> decltype(vec);
	
	// div (scalar)
	template <int DIM_N=4> avl_ainl_res constexpr auto div(v4& vec, const sc scalar) noexcept(ndebug||exuse) -> decltype(vec);
	
	/// \}
	/// \defgroup General purpos functions for 4 component vectors
	/// \{
	
	/// Dot product
	template <int DIM_N=4> avl_ainl constexpr auto dot(const v4& vec, const v4& other) noexcept -> decltype(cmp(vec));
	
	/// \}
}
#endif // AVL_V4_HPP