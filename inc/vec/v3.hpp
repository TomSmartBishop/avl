
#ifndef AVL_V3_HPP
#define AVL_V3_HPP

#pragma once

/// avl: A Vector Library
/// \author Thomas Pollak
namespace avl
{

	/// \defgroup Vector length operations
	/// \{
	
	/// Returns a new vector with the requested length
	template <int _Dim=3> avl_ainl_res constexpr auto setlen_mk(const v3& vec, const sc len_to_set) noexcept(ndebug||exuse);
	
	/// Set the length of the vector
	template <int _Dim=3> avl_ainl constexpr auto setlen_set(v3& vec, const sc len_to_set) noexcept(ndebug||exuse) -> void;
	
	/// Set the length of the vector and return the same vector (chained)
	template <int _Dim=3> avl_ainl_res constexpr auto setlen(v3& vec, const sc len_to_set) noexcept(ndebug||exuse) -> decltype(vec);
	
	/// Calculate the length of the vector, prefere len_sqr when comparing distances
	template <int _Dim=3> avl_ainl_res constexpr auto len(const v3& vec) noexcept -> decltype(cmp(vec));
	
	/// Calculate the square length of the vector
	template <int _Dim=3> avl_ainl_res constexpr auto len_sqr(const v3& vec) noexcept -> decltype(cmp(vec));
	
	/// Returns a normalized vector
	template <int _Dim=3> avl_ainl_res constexpr auto norm_mk(const v3& vec ) noexcept(ndebug||exuse);
	
	/// Returns a normalized vector, use alternative vector if the current vector length is 0
	template <int _Dim=3> avl_ainl_res constexpr auto norm_mk(const v3& vec , const v3& vec_if_zero_len) noexcept;
	
	/// Normalize the current vector
	template <int _Dim=3> avl_ainl constexpr auto norm_set(v3& vec ) noexcept -> void;
	
	/// Normalize the current vector, use alternative vector if the current vector length is 0
	template <int _Dim=3> avl_ainl constexpr auto norm_set(v3& vec , const v3& vec_if_zero_len) noexcept -> void;
	
	/// Normalize the current vector and return the same vector (chained)
	template <int _Dim=3> avl_ainl_res constexpr auto norm(v3& vec ) noexcept -> decltype(vec);
	
	/// Normalize the current vector and return the same vector (chained), use alternative vector if the current vector length is 0
	template <int _Dim=3> avl_ainl_res constexpr auto norm(v3& vec , const v3& vec_if_zero_len) noexcept -> decltype(vec);
	
	/// \}
	/// \defgroup Spacial operations
	/// \{
	
	/// Calculate the area of the spawned triangle
	avl_inl_res constexpr auto area(v3 vec, const decltype(vec)& other) noexcept -> decltype(cmp(vec));
	
	/// Calculate the cross product
	avl_ainl_res constexpr auto cross_mk(const v3& vec, const v3& other) noexcept;
	
	/// Calculate the cross product
	avl_ainl constexpr auto cross_set(v3& vec, const v3& other) noexcept -> void;
	
	/// Calculate the cross product
	avl_ainl_res constexpr auto cross(v3& vec, const v3& other) noexcept -> decltype(vec);
	
	/// \}
	/// \defgroup Getter and setters for 3 component vectors
	/// \{
	
	/// Set all vector components to the same scalar
	template <int _Dim=3> avl_ainl constexpr auto set_all(v3& vec, const sc scalar) noexcept -> void;
	
	/// Set all vector components individually
	template <int _Dim=3> avl_ainl constexpr auto set_all(v3& vec, const sc x, const sc y, const sc z) noexcept -> void;
	
	/// Set all vector components individually by a fixed size array
	template <int _Dim=3> avl_ainl constexpr auto set_all(v3& vec, const sc scalars[ 3 ]) noexcept -> void;
	
	/// \}
	/// \defgroup Base math vector operations for 3 component vectors
	/// \{
	
	// add_mk
	avl_ainl_res constexpr auto add_mk(const v3& vec, const v3& other) noexcept;
	
	// add_mk (scalar)
	avl_ainl_res constexpr auto add_mk(const v3& vec, const sc scalar) noexcept;
	
	// add_set
	avl_ainl constexpr auto add_set(v3& vec, const v3& other) noexcept -> void;
	
	// add_set (scalar)
	avl_ainl constexpr auto add_set(v3& vec, const sc scalar) noexcept -> void;
	
	// add
	avl_ainl_res constexpr auto add(v3& vec, const v3& other) noexcept -> decltype(vec);
	
	// add (scalar)
	avl_ainl_res constexpr auto add(v3& vec, const sc scalar) noexcept -> decltype(vec);
	
	// sub_mk
	avl_ainl_res constexpr auto sub_mk(const v3& vec, const v3& other) noexcept;
	
	// sub_mk (scalar)
	avl_ainl_res constexpr auto sub_mk(const v3& vec, const sc scalar) noexcept;
	
	// sub_set
	avl_ainl constexpr auto sub_set(v3& vec, const v3& other) noexcept -> void;
	
	// sub_set (scalar)
	avl_ainl constexpr auto sub_set(v3& vec, const sc scalar) noexcept -> void;
	
	// sub
	avl_ainl_res constexpr auto sub(v3& vec, const v3& other) noexcept -> decltype(vec);
	
	// sub (scalar)
	avl_ainl_res constexpr auto sub(v3& vec, const sc scalar) noexcept -> decltype(vec);
	
	// mul_mk
	avl_ainl_res constexpr auto mul_mk(const v3& vec, const v3& other) noexcept;
	
	// mul_mk (scalar)
	avl_ainl_res constexpr auto mul_mk(const v3& vec, const sc scalar) noexcept;
	
	// mul_set
	avl_ainl constexpr auto mul_set(v3& vec, const v3& other) noexcept -> void;
	
	// mul_set (scalar)
	avl_ainl constexpr auto mul_set(v3& vec, const sc scalar) noexcept -> void;
	
	// mul
	avl_ainl_res constexpr auto mul(v3& vec, const v3& other) noexcept -> decltype(vec);
	
	// mul (scalar)
	avl_ainl_res constexpr auto mul(v3& vec, const sc scalar) noexcept -> decltype(vec);
	
	// div_mk
	avl_ainl_res constexpr auto div_mk(const v3& vec, const v3& other) noexcept(ndebug||exuse);
	
	// div_mk (scalar)
	avl_ainl_res constexpr auto div_mk(const v3& vec, const sc scalar) noexcept(ndebug||exuse);
	
	// div_set
	avl_ainl constexpr auto div_set(v3& vec, const v3& other) noexcept(ndebug||exuse) -> void;
	
	// div_set (scalar)
	avl_ainl constexpr auto div_set(v3& vec, const sc scalar) noexcept(ndebug||exuse) -> void;
	
	// div
	avl_ainl_res constexpr auto div(v3& vec, const v3& other) noexcept(ndebug||exuse) -> decltype(vec);
	
	// div (scalar)
	avl_ainl_res constexpr auto div(v3& vec, const sc scalar) noexcept(ndebug||exuse) -> decltype(vec);
	
	/// \}
	/// \defgroup General purpos functions for 3 component vectors
	/// \{
	
	/// Dot product
	avl_ainl constexpr auto dot(const v3& vec, decltype(vec)& other) noexcept -> decltype(cmp(vec));
	
	/// \}
}
#endif // AVL_V3_HPP