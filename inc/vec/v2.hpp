// NOTICE: This file is generated using the template file v.jinja
#ifndef AVL_V2_HPP
#define AVL_V2_HPP

#pragma once

/// avl: A Vector Library
/// \author Thomas Pollak
namespace avl
{

	/// \defgroup Vector length operations
	/// \{
	
	/// Returns a new vector with the requested length
	avl_ainl_res constexpr auto setlen_mk(const v2& vec, const sc len_to_set) noexcept(ndebug||exuse);
	
	/// Set the length of the vector
	avl_ainl constexpr auto setlen_set(v2& vec, const sc len_to_set) noexcept(ndebug||exuse) -> void;
	
	/// Set the length of the vector and return the same vector (chained)
	avl_ainl_res constexpr auto setlen(v2& vec, const sc len_to_set) noexcept(ndebug||exuse) -> decltype(vec);
	
	/// Calculate the length of the vector, prefere len_sqr when comparing distances
	avl_ainl_res constexpr auto len(const v2& vec) noexcept -> decltype(cmp(vec));
	
	/// Calculate the square length of the vector
	avl_ainl_res constexpr auto len_sqr(const v2& vec) noexcept -> decltype(cmp(vec));
	
	/// Returns a normalized vector
	avl_ainl_res constexpr auto norm_mk(const v2& vec ) noexcept(ndebug||exuse);
	
	/// Returns a normalized vector, use alternative vector if the current vector length is 0
	avl_ainl_res constexpr auto norm_mk(const v2& vec , const v2& vec_if_zero_len) noexcept;
	
	/// Normalize the current vector
	avl_ainl constexpr auto norm_set(v2& vec ) noexcept -> void;
	
	/// Normalize the current vector, use alternative vector if the current vector length is 0
	avl_ainl constexpr auto norm_set(v2& vec , const v2& vec_if_zero_len) noexcept -> void;
	
	/// Normalize the current vector and return the same vector (chained)
	avl_ainl_res constexpr auto norm(v2& vec ) noexcept -> decltype(vec);
	
	/// Normalize the current vector and return the same vector (chained), use alternative vector if the current vector length is 0
	avl_ainl_res constexpr auto norm(v2& vec , const v2& vec_if_zero_len) noexcept -> decltype(vec);
	
	/// \}
	/// \defgroup Spacial operations
	/// \{
	
	/// Calculate the area of the spawned triangle
	avl_inl_res constexpr auto area(const v2& vec, const decltype(vec)& other) noexcept -> decltype(cmp(vec));
	
	/// \}
	/// \defgroup Getter and setters for 2 component vectors
	/// \{
	
	/// Set all vector components to the same scalar
	avl_ainl constexpr auto set_all(v2& vec, const sc scalar) noexcept -> void;
	
	/// Set all vector components individually
	avl_ainl constexpr auto set_all(v2& vec, const sc x, const sc y) noexcept -> void;
	
	/// Set all vector components individually by a fixed size array
	avl_ainl constexpr auto set_all(v2& vec, const sc scalars[ 2 ]) noexcept -> void;
	
	/// \}
	/// \defgroup Base math vector operations for 2 component vectors
	/// \{
	
	// add_mk
	avl_ainl_res constexpr auto add_mk(const v2& vec, const v2& other) noexcept;
	
	// add_mk (scalar)
	avl_ainl_res constexpr auto add_mk(const v2& vec, const sc scalar) noexcept;
	
	// add_set
	avl_ainl constexpr auto add_set(v2& vec, const v2& other) noexcept -> void;
	
	// add_set (scalar)
	avl_ainl constexpr auto add_set(v2& vec, const sc scalar) noexcept -> void;
	
	// add
	avl_ainl_res constexpr auto add(v2& vec, const v2& other) noexcept -> decltype(vec);
	
	// add (scalar)
	avl_ainl_res constexpr auto add(v2& vec, const sc scalar) noexcept -> decltype(vec);
	
	// sub_mk
	avl_ainl_res constexpr auto sub_mk(const v2& vec, const v2& other) noexcept;
	
	// sub_mk (scalar)
	avl_ainl_res constexpr auto sub_mk(const v2& vec, const sc scalar) noexcept;
	
	// sub_set
	avl_ainl constexpr auto sub_set(v2& vec, const v2& other) noexcept -> void;
	
	// sub_set (scalar)
	avl_ainl constexpr auto sub_set(v2& vec, const sc scalar) noexcept -> void;
	
	// sub
	avl_ainl_res constexpr auto sub(v2& vec, const v2& other) noexcept -> decltype(vec);
	
	// sub (scalar)
	avl_ainl_res constexpr auto sub(v2& vec, const sc scalar) noexcept -> decltype(vec);
	
	// mul_mk
	avl_ainl_res constexpr auto mul_mk(const v2& vec, const v2& other) noexcept;
	
	// mul_mk (scalar)
	avl_ainl_res constexpr auto mul_mk(const v2& vec, const sc scalar) noexcept;
	
	// mul_set
	avl_ainl constexpr auto mul_set(v2& vec, const v2& other) noexcept -> void;
	
	// mul_set (scalar)
	avl_ainl constexpr auto mul_set(v2& vec, const sc scalar) noexcept -> void;
	
	// mul
	avl_ainl_res constexpr auto mul(v2& vec, const v2& other) noexcept -> decltype(vec);
	
	// mul (scalar)
	avl_ainl_res constexpr auto mul(v2& vec, const sc scalar) noexcept -> decltype(vec);
	
	// div_mk
	avl_ainl_res constexpr auto div_mk(const v2& vec, const v2& other) noexcept(ndebug||exuse);
	
	// div_mk (scalar)
	avl_ainl_res constexpr auto div_mk(const v2& vec, const sc scalar) noexcept(ndebug||exuse);
	
	// div_set
	avl_ainl constexpr auto div_set(v2& vec, const v2& other) noexcept(ndebug||exuse) -> void;
	
	// div_set (scalar)
	avl_ainl constexpr auto div_set(v2& vec, const sc scalar) noexcept(ndebug||exuse) -> void;
	
	// div
	avl_ainl_res constexpr auto div(v2& vec, const v2& other) noexcept(ndebug||exuse) -> decltype(vec);
	
	// div (scalar)
	avl_ainl_res constexpr auto div(v2& vec, const sc scalar) noexcept(ndebug||exuse) -> decltype(vec);
	
	/// \}
	/// \defgroup General purpos functions for 2 component vectors
	/// \{
	
	/// Dot product
	avl_ainl constexpr auto dot(const v2& vec, const v2& other) noexcept -> decltype(cmp(vec));
	
	/// \}
}
#endif // AVL_V2_HPP