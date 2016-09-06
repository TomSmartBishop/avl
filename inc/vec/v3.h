#ifndef AVL_V3_H
#define AVL_V3_H

#pragma once

#include "../helper/const.h"

/// avl: A Vector Library
/// \author Thomas Pollak
namespace avl
{
	/// \defgroup Vector length operations
	/// \{
	
	/// Calculate the square length of the vector
	avl_ainl_res constexpr auto len_sqr(const v3& vec) noexcept -> decltype(cmp(vec));
	
	/// \}
	/// \defgroup Spacial operations
	/// \{
	
	/// Calculate the area of the spawned triangle
	avl_inl_res constexpr auto area(const v3& vec, const v3& other) noexcept -> decltype(cmp(vec));
	
	/// Calculate the cross product
	avl_ainl_res constexpr auto cross_mk(const v3& vec, const v3& other) noexcept;
	
	/// Calculate the cross product
	avl_ainl constexpr auto cross_set(const v3& vec, const v3& other) noexcept -> void;
	
	/// Calculate the cross product
	avl_ainl_res constexpr auto cross(const v3& vec, const v3& other) noexcept -> decltype(vec);
	
	/// \}
	/// \defgroup Getter and setters for 3 component vectors
	/// \{
	
	/// Set all vector components to the same scalar
	avl_ainl constexpr auto set_all(v3& vec, const sc scalar) noexcept -> void;
	
	/// Set all vector components individually
	avl_ainl constexpr auto set_all(v3& vec, const sc x, const sc y, const sc z) noexcept -> void;
	
	/// Set all vector components individually by a fixed size array
	avl_ainl constexpr auto set_all(v3& vec, const sc scalars[ 3 ]) noexcept -> void;
	
	/// Set all vector components individually by an array
	template <s::size_t _Dim> avl_ainl constexpr auto set_all(v3& vec, const sc* scalars) noexcept -> void;
	
	/// \}
	/// \defgroup General vector operations for 3 component vectors
	/// \{
	
	// add_mk
	avl_ainl_res constexpr auto add_mk(const v3& vec, const v3& other) noexcept;
	
	// add_mk (scalar)
	avl_ainl_res constexpr auto add_mk(const v3& vec, const sc scalar) noexcept;
	
	// add_set
	avl_ainl constexpr auto add_set(const v3& vec, const v3& other) noexcept -> void;
	
	// add_set (scalar)
	avl_ainl_res constexpr auto add_set(const v3& vec, const sc scalar) noexcept -> void;
	
	// add
	avl_ainl_res constexpr auto add(const v3& vec, const v3& other) noexcept -> decltype(vec);
	
	// add (scalar)
	avl_ainl_res constexpr auto add(const v3& vec, const sc scalar) noexcept -> decltype(vec);
	
	// sub_mk
	avl_ainl_res constexpr auto sub_mk(const v3& vec, const v3& other) noexcept;
	
	// sub_mk (scalar)
	avl_ainl_res constexpr auto sub_mk(const v3& vec, const sc scalar) noexcept;
	
	// sub_set
	avl_ainl constexpr auto sub_set(const v3& vec, const v3& other) noexcept -> void;
	
	// sub_set (scalar)
	avl_ainl_res constexpr auto sub_set(const v3& vec, const sc scalar) noexcept -> void;
	
	// sub
	avl_ainl_res constexpr auto sub(const v3& vec, const v3& other) noexcept -> decltype(vec);
	
	// sub (scalar)
	avl_ainl_res constexpr auto sub(const v3& vec, const sc scalar) noexcept -> decltype(vec);
	
	// mul_mk
	avl_ainl_res constexpr auto mul_mk(const v3& vec, const v3& other) noexcept;
	
	// mul_mk (scalar)
	avl_ainl_res constexpr auto mul_mk(const v3& vec, const sc scalar) noexcept;
	
	// mul_set
	avl_ainl constexpr auto mul_set(const v3& vec, const v3& other) noexcept -> void;
	
	// mul_set (scalar)
	avl_ainl_res constexpr auto mul_set(const v3& vec, const sc scalar) noexcept -> void;
	
	// mul
	avl_ainl_res constexpr auto mul(const v3& vec, const v3& other) noexcept -> decltype(vec);
	
	// mul (scalar)
	avl_ainl_res constexpr auto mul(const v3& vec, const sc scalar) noexcept -> decltype(vec);
	
	// div_mk
	avl_ainl_res constexpr auto div_mk(const v3& vec, const v3& other) noexcept(ndebug||exuse);
	
	// div_mk (scalar)
	avl_ainl_res constexpr auto div_mk(const v3& vec, const sc scalar) noexcept(ndebug||exuse);
	
	// div_set
	avl_ainl constexpr auto div_set(const v3& vec, const v3& other) noexcept(ndebug||exuse) -> void;
	
	// div_set (scalar)
	avl_ainl_res constexpr auto div_set(const v3& vec, const sc scalar) noexcept(ndebug||exuse) -> void;
	
	// div
	avl_ainl_res constexpr auto div(const v3& vec, const v3& other) noexcept(ndebug||exuse) -> decltype(vec);
	
	// div (scalar)
	avl_ainl_res constexpr auto div(const v3& vec, const sc scalar) noexcept(ndebug||exuse) -> decltype(vec);
	
	/// \}
}
#endif // AVL_V3_H