
#ifndef AVL_V4_HPP
#define AVL_V4_HPP

#pragma once

/// avl: A Vector Library
/// \author Thomas Pollak
namespace avl
{

	/// \defgroup Vector length operations
	/// \{
	
	/// Calculate the square length of the vector
	avl_ainl_res constexpr auto len_sqr(const v4& vec) noexcept -> decltype(cmp(vec));
	
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
	avl_ainl constexpr auto set_all(v4& vec, const sc scalar) noexcept -> void;
	
	/// Set all vector components individually
	avl_ainl constexpr auto set_all(v4& vec, const sc x, const sc y, const sc z, const sc w) noexcept -> void;
	
	/// Set all vector components individually by a fixed size array
	avl_ainl constexpr auto set_all(v4& vec, const sc scalars[ 4 ]) noexcept -> void;
	
	/// Set all vector components individually by an array of specified size _Dim
	template <s::size_t _Dim> avl_ainl constexpr auto set_all(v4& vec, const sc* scalars) noexcept -> void;
	
	/// \}
	/// \defgroup Base math vector operations for 4 component vectors
	/// \{
	
	// add_mk
	avl_ainl_res constexpr auto add_mk(const v4& vec, const v4& other) noexcept;
	
	// add_mk (scalar)
	avl_ainl_res constexpr auto add_mk(const v4& vec, const sc scalar) noexcept;
	
	// add_set
	avl_ainl constexpr auto add_set(v4& vec, const v4& other) noexcept -> void;
	
	// add_set (scalar)
	avl_ainl constexpr auto add_set(v4& vec, const sc scalar) noexcept -> void;
	
	// add
	avl_ainl_res constexpr auto add(v4& vec, const v4& other) noexcept -> decltype(vec);
	
	// add (scalar)
	avl_ainl_res constexpr auto add(v4& vec, const sc scalar) noexcept -> decltype(vec);
	
	// sub_mk
	avl_ainl_res constexpr auto sub_mk(const v4& vec, const v4& other) noexcept;
	
	// sub_mk (scalar)
	avl_ainl_res constexpr auto sub_mk(const v4& vec, const sc scalar) noexcept;
	
	// sub_set
	avl_ainl constexpr auto sub_set(v4& vec, const v4& other) noexcept -> void;
	
	// sub_set (scalar)
	avl_ainl constexpr auto sub_set(v4& vec, const sc scalar) noexcept -> void;
	
	// sub
	avl_ainl_res constexpr auto sub(v4& vec, const v4& other) noexcept -> decltype(vec);
	
	// sub (scalar)
	avl_ainl_res constexpr auto sub(v4& vec, const sc scalar) noexcept -> decltype(vec);
	
	// mul_mk
	avl_ainl_res constexpr auto mul_mk(const v4& vec, const v4& other) noexcept;
	
	// mul_mk (scalar)
	avl_ainl_res constexpr auto mul_mk(const v4& vec, const sc scalar) noexcept;
	
	// mul_set
	avl_ainl constexpr auto mul_set(v4& vec, const v4& other) noexcept -> void;
	
	// mul_set (scalar)
	avl_ainl constexpr auto mul_set(v4& vec, const sc scalar) noexcept -> void;
	
	// mul
	avl_ainl_res constexpr auto mul(v4& vec, const v4& other) noexcept -> decltype(vec);
	
	// mul (scalar)
	avl_ainl_res constexpr auto mul(v4& vec, const sc scalar) noexcept -> decltype(vec);
	
	// div_mk
	avl_ainl_res constexpr auto div_mk(const v4& vec, const v4& other) noexcept(ndebug||exuse);
	
	// div_mk (scalar)
	avl_ainl_res constexpr auto div_mk(const v4& vec, const sc scalar) noexcept(ndebug||exuse);
	
	// div_set
	avl_ainl constexpr auto div_set(v4& vec, const v4& other) noexcept(ndebug||exuse) -> void;
	
	// div_set (scalar)
	avl_ainl constexpr auto div_set(v4& vec, const sc scalar) noexcept(ndebug||exuse) -> void;
	
	// div
	avl_ainl_res constexpr auto div(v4& vec, const v4& other) noexcept(ndebug||exuse) -> decltype(vec);
	
	// div (scalar)
	avl_ainl_res constexpr auto div(v4& vec, const sc scalar) noexcept(ndebug||exuse) -> decltype(vec);
	
	/// \}
	/// \defgroup General purpos functions for 4 component vectors
	/// \{
	
	/// Dot product
	avl_ainl constexpr auto dot(const v4& vec, decltype(vec)& other) noexcept -> decltype(cmp(vec));
	
	/// Dot product ignoring the w component
	avl_ainl constexpr auto dot3(const v4& vec, decltype(vec)& other) noexcept -> decltype(cmp(vec));
	
	/// \}
}
#endif // AVL_V4_HPP