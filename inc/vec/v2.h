#ifndef AVL_V2_H
#define AVL_V2_H

#pragma once

/// avl: A Vector Library
/// \author Thomas Pollak
namespace avl {
	
	/// \defgroup Free functions for 2 component vectors
	/// @{
	
	/// @name Getters and Setters
	/// @{
	
	/// Set all vector components to the same scalar
	avl_ainl constexpr auto set_all(v2& vec, const sc scalar) noexcept -> void;
	
	/// Set all vector components individually
	avl_ainl constexpr auto set_all(v2& vec, const sc x, const sc y) noexcept -> void;
	
	/// Set all vector components individually
	avl_ainl constexpr auto set_all(v2& vec, const sc scalars[2]) noexcept -> void;
	
	/// Set all vector components individually
	template <s::size_t _Dim>
	avl_ainl constexpr auto set_all(v2& vec, const sc* scalars) noexcept -> void;
	
	/// @}
	/// @name General Vector Operations
	/// @{
	
	// add make
	
	avl_ainl_res constexpr auto add_mk(const v2& vec, const v2& other) noexcept;
	
	avl_ainl_res constexpr auto add_mk(const v2& vec, const sc scalar) noexcept;
	
	// add set
	
	avl_ainl constexpr auto add_set(v2& vec, const v2& other) noexcept -> void;
	
	avl_ainl constexpr auto add_set(v2& vec, const sc scalar) noexcept -> void;
	
	// add (chaining)
	
	avl_ainl_res constexpr auto add(v2& vec, const v2& other) noexcept -> decltype(vec);
	
	avl_ainl_res constexpr auto add(v2& vec, const sc scalar) noexcept -> decltype(vec);
	
	// sub make
	
	avl_ainl_res constexpr auto sub_mk(const v2& vec, const v2& other) noexcept;
	
	avl_ainl_res constexpr auto sub_mk(const v2& vec, const sc scalar) noexcept;
	
	// sub set
	
	avl_ainl constexpr auto sub_set(v2& vec, const v2& other) noexcept -> void;
	
	avl_ainl constexpr auto sub_set(v2& vec, const sc scalar) noexcept -> void;
	
	// sub (chaining)
	
	avl_ainl_res constexpr auto sub(v2& vec, const v2& other) noexcept -> decltype(vec);
	
	avl_ainl_res constexpr auto sub(v2& vec, const sc scalar) noexcept -> decltype(vec);
	
	// mul make
	
	avl_ainl_res constexpr auto mul_mk(const v2& vec, const v2& other) noexcept;
	
	avl_ainl_res constexpr auto mul_mk(const v2& vec, const sc scalar) noexcept;
	
	// mul set
	
	avl_ainl constexpr auto mul_set(v2& vec, const v2& other) noexcept -> void;
	
	avl_ainl constexpr auto mul_set(v2& vec, const sc scalar) noexcept -> void;
	
	// mul (chaining)
	
	avl_ainl_res constexpr auto mul(v2& vec, const v2& other) noexcept -> decltype(vec);
	
	avl_ainl_res constexpr auto mul(v2& vec, const sc scalar) noexcept -> decltype(vec);
	
	// div make
	
	avl_ainl_res constexpr auto div_mk(const v2& vec, const v2& other) noexcept;
	
	avl_ainl_res constexpr auto div_mk(const v2& vec, const sc scalar) noexcept;
	
	// div set
	
	avl_ainl constexpr auto div_set(v2& vec, const v2& other) noexcept -> void;
	
	avl_ainl constexpr auto div_set(v2& vec, const sc scalar) noexcept -> void;
	
	// div (chaining)
	
	avl_ainl_res constexpr auto div(v2& vec, const v2& other) noexcept -> decltype(vec);
	
	avl_ainl_res constexpr auto div(v2& vec, const sc scalar) noexcept -> decltype(vec);
	
	//no cross product in 2D space
	
	/// Calculate the area of the spawned triangel
	avl_inl_res constexpr auto area(const v2& vec, const v2& other) noexcept -> decltype(cmp(vec));
	
	/// @}
	/// @name Vector Length Operations
	/// @{
	
	/// Calculate the square length of the vector
	avl_ainl_res constexpr auto len_sqr(const v2& vec) noexcept -> decltype(cmp(vec));
	
	/// @}
	/// @name Vector Operations With Scalar Results
	/// @{
	
	avl_ainl_res constexpr auto dot(const v2& vec, const v2& other) noexcept -> decltype(cmp(vec));
	
	/// @}
	
	/// @}
}
#endif // AVL_V2_H