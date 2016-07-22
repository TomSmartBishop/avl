#ifndef AVL_V4_H
#define AVL_V4_H

#pragma once

/// avl: A Vector Library
/// \author Thomas Pollak
namespace avl {
	
	/// \defgroup Free functions for 4 component vectors
	/// @{
	
	/// @name Getters and Setters
	/// @{
	
	/// Set all vector components to the same scalar
	avl_ainl constexpr auto set_all(v4& vec, const sc scalar) noexcept -> void;
	
	/// Set all vector components individually
	avl_ainl constexpr auto set_all(v4& vec, const sc x, const sc y, const sc z, const sc w) noexcept -> void;
	
	/// Set all vector components individually
	avl_ainl constexpr auto set_all(v4& vec, const sc scalars[4]) noexcept -> void;
	
	/// Set all vector components individually
	template <s::size_t _Dim>
	avl_ainl constexpr auto set_all(v4& vec, const sc* scalars) noexcept -> void;
	
	/// @}
	/// @name General Vector Operations
	/// @{
	
	// add make
	
	avl_ainl_res constexpr auto add_mk(const v4& vec, const v4& other) noexcept;
	
	avl_ainl_res constexpr auto add_mk(const v4& vec, const sc scalar) noexcept;
	
	// add set
	
	avl_ainl constexpr auto add_set(v4& vec, const v4& other) noexcept -> void;
	
	avl_ainl constexpr auto add_set(v4& vec, const sc scalar) noexcept -> void;
	
	// add (chaining)
	
	avl_ainl_res constexpr auto add(v4& vec, const v4& other) noexcept -> decltype(vec);
	
	avl_ainl_res constexpr auto add(v4& vec, const sc scalar) noexcept -> decltype(vec);
	
	// sub make
	
	avl_ainl_res constexpr auto sub_mk(const v4& vec, const v4& other) noexcept;
	
	avl_ainl_res constexpr auto sub_mk(const v4& vec, const sc scalar) noexcept;
	
	// sub set
	
	avl_ainl constexpr auto sub_set(v4& vec, const v4& other) noexcept -> void;
	
	avl_ainl constexpr auto sub_set(v4& vec, const sc scalar) noexcept -> void;
	
	// sub (chaining)
	
	avl_ainl_res constexpr auto sub(v4& vec, const v4& other) noexcept -> decltype(vec);
	
	avl_ainl_res constexpr auto sub(v4& vec, const sc scalar) noexcept -> decltype(vec);
	
	// mul make
	
	avl_ainl_res constexpr auto mul_mk(const v4& vec, const v4& other) noexcept;
	
	avl_ainl_res constexpr auto mul_mk(const v4& vec, const sc scalar) noexcept;
	
	// mul set
	
	avl_ainl constexpr auto mul_set(v4& vec, const v4& other) noexcept -> void;
	
	avl_ainl constexpr auto mul_set(v4& vec, const sc scalar) noexcept -> void;
	
	// mul (chaining)
	
	avl_ainl_res constexpr auto mul(v4& vec, const v4& other) noexcept -> decltype(vec);
	
	avl_ainl_res constexpr auto mul(v4& vec, const sc scalar) noexcept -> decltype(vec);
	
	// div make
	
	avl_ainl_res constexpr auto div_mk(const v4& vec, const v4& other) noexcept;
	
	avl_ainl_res constexpr auto div_mk(const v4& vec, const sc scalar) noexcept;
	
	// div set
	
	avl_ainl constexpr auto div_set(v4& vec, const v4& other) noexcept -> void;
	
	avl_ainl constexpr auto div_set(v4& vec, const sc scalar) noexcept -> void;
	
	// div (chaining)
	
	avl_ainl_res constexpr auto div(v4& vec, const v4& other) noexcept -> decltype(vec);
	
	avl_ainl_res constexpr auto div(v4& vec, const sc scalar) noexcept -> decltype(vec);
	
	/// Calculate the cross product for x,y,z, setting w to 0
	avl_ainl_res constexpr auto cross3_mk(const v4& vec, const v4& other) noexcept;
	
	/// Calculate the cross product for x,y,z, setting w to 0 and assign it to the current vector
	avl_ainl constexpr auto cross3_set(v4& vec, const v4& other) noexcept -> void;
	
	/// Calculate the cross product for x,y,z, setting w to 0 and assign it to the current vector
	avl_ainl_res constexpr auto cross3(v4& vec, const v4& other) noexcept -> decltype(vec);
	
	/// Calculate the area of the spawned triangle (using the cross product 0.5*|(a x b)|)
	avl_ainl_res constexpr auto area3(v4 vec, const v4& other) noexcept -> decltype(cmp(vec));
	
	/// @}
	/// @name Vector Length Operations
	/// @{
	
	/// Calculate the square length of the vector
	avl_ainl_res constexpr auto len_sqr(const v4& vec) noexcept -> decltype(cmp(vec));
	
	/// @}
	/// @name Vector Operations With Scalar Results
	/// @{
	
	avl_ainl_res constexpr auto dot(const v4& vec, const v4& other) noexcept -> decltype(cmp(vec));
	
	/// @}
	
	/// @}
}
#endif // AVL_V4_H