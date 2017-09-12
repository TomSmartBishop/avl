// NOTICE: This file is generated using the template file v.jinja
#ifndef AVL_V_HPP
#define AVL_V_HPP

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
	template<s::size_t INDEX> avl_ainl_res constexpr auto get(const v& vec) noexcept -> decltype(cmp(vec));
	
	/// Set a single component by index from 0 to dim-1
	avl_ainl constexpr auto set(v& vec, const s::size_t idx, const sc scalar) noexcept(ndebug||exuse) -> void;
	
	/// Set a single component by static index from 0 to dim-1
	template<s::size_t INDEX> avl_ainl constexpr auto set(v& vec, const sc scalar) noexcept -> void;
	
	/// \}
/// \defgroup Vector length operations
/// \{

/// \}
	/// \defgroup Spacial operations
	/// \{
	
	/// Calculate the angle between two vectors in radian
	avl_ainl_res constexpr auto angle_rd(const v& vec, const decltype(vec) other) noexcept -> decltype(cmp(vec));
	
	/// Calculate the angle between two vectors in degree
	avl_ainl_res constexpr auto angle_dg(const v& vec, const decltype(vec) other) noexcept -> decltype(cmp(vec));
	
	/// Get the direction relative to another point excluding colinear and opposite-but-colinear (faster than get_dir_col)
	avl_ainl_res constexpr auto get_dir(const v& vec, const v& other) noexcept -> dir;
	
	/// Get the direction relative to another point excluding colinear and opposite-but-colinear (faster than get_dir_col)
	avl_ainl_res constexpr auto get_dir(const v& vec, const v& other, const sc epsilon) noexcept -> dir;
	
	/// \}
}
#endif // AVL_V_HPP