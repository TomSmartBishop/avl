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
	avl_ainl constexpr auto set_all(v2& vec, const sc scalar) noexcept -> void  {
		static_assert(eq<decltype(vec[0]), decltype(scalar)>::value, "Supply a scalar of the vectors element type.");
		vec[0] = scalar;
		vec[1] = scalar;
	}

	/// Set all vector components individually
	avl_ainl constexpr auto set_all(v2& vec, const sc x, const sc y) noexcept -> void  {
		static_assert(eq<decltype(vec[0]), decltype(x)>::value, "Supply a scalar of the vectors element type.");
		static_assert(eq<decltype(vec[1]), decltype(y)>::value, "Supply a scalar of the vectors element type.");
		vec[0] = x;
		vec[1] = y;
	}

	/// Set all vector components individually
	avl_ainl constexpr auto set_all(v2& vec, const sc scalars[2]) noexcept -> void  {
		static_assert(eq<decltype(vec[0]), decltype(scalars[0])>::value, "Supply a scalar of the vectors element type.");
		static_assert(eq<decltype(vec[1]), decltype(scalars[1])>::value, "Supply a scalar of the vectors element type.");
		vec[0] = scalars[0];
		vec[1] = scalars[1];
	}

	/// Set all vector components individually
	template <s::size_t _Dim>
	avl_ainl constexpr auto set_all(v2& vec, const sc* scalars) noexcept -> void  {
		static_assert(_Dim>1, "Supply at least 2 scalars.");
		static_assert(eq<decltype(vec[0]), decltype(scalars[0])>::value, "Supply a scalar of the vectors element type.");
		static_assert(eq<decltype(vec[1]), decltype(scalars[1])>::value, "Supply a scalar of the vectors element type.");
		vec[0] = scalars[0];
		vec[1] = scalars[1];
	}

	/// @}
	/// @name General Vector Operations
	/// @{

	// add

	avl_ainl_res constexpr auto add_mk(const v2& vec, const v2& other) noexcept {//} -> v2 {
		return decltype(vec) { get<0>(vec) + get<0>(other), get<1>(vec) + get<1>(other) };
	}

	avl_ainl_res constexpr auto add_mk(const v2& vec, const sc scalar) noexcept {//-> v2 {
		return decltype(vec) { get<0>(vec) + scalar, get<1>(vec) + scalar };
	}

	avl_ainl constexpr auto add_set(v2& vec, const v2& other) noexcept -> void {
		set_all(vec, get<0>(vec) + get<0>(other), get<1>(vec) + get<1>(other) );
	}

	avl_ainl constexpr auto add_set(v2& vec, const sc scalar) noexcept -> void {
		set_all(vec, get<0>(vec) + scalar, get<1>(vec) + scalar );
	}

	avl_ainl_res constexpr auto add(v2& vec, const v2& other) noexcept -> v2& {
		set_all(vec, get<0>(vec) + get<0>(other), get<1>(vec) + get<1>(other) );
		return vec;
	}

	avl_ainl_res constexpr auto add(v2& vec, const sc scalar) noexcept -> v2& {
		set_all(vec, get<0>(vec) + scalar, get<1>(vec) + scalar );
		return vec;
	}

	//sub

	avl_ainl_res constexpr auto sub_mk(const v2& vec, const v2& other) noexcept -> v2 {
		return decltype(vec){ get<0>(vec) - get<0>(other), get<1>(vec) - get<1>(other) };
	}

	avl_ainl_res constexpr auto sub_mk(const v2& vec, const sc scalar) noexcept -> v2 {
		return decltype(vec){ get<0>(vec) - scalar, get<1>(vec) - scalar };
	}

	avl_ainl constexpr auto sub_set(v2& vec, const v2& other) noexcept -> void {
		set_all(vec, get<0>(vec) - get<0>(other), get<1>(vec) - get<1>(other) );
	}

	avl_ainl constexpr auto sub_set(v2& vec, const sc scalar) noexcept -> void {
		set_all(vec, get<0>(vec) - scalar, get<1>(vec) - scalar );
	}

	avl_ainl_res constexpr auto sub(v2& vec, const v2& other) noexcept -> v2 {
		set_all(vec, get<0>(vec) - get<0>(other), get<1>(vec) - get<1>(other) );
		return vec;
	}

	avl_ainl_res constexpr auto sub(v2& vec, const sc scalar) noexcept -> v2 {
		set_all(vec, get<0>(vec) - scalar, get<1>(vec) - scalar );
		return vec;
	}

	// mul

	avl_ainl_res constexpr auto mul_mk(const v2& vec, const v2& other) noexcept -> v2 {
		return decltype(vec){ get<0>(vec) * get<0>(other), get<1>(vec) * get<1>(other) };
	}

	avl_ainl_res constexpr auto mul_mk(const v2& vec, const sc scalar) noexcept -> v2 {
		return decltype(vec){ get<0>(vec) * scalar, get<1>(vec) * scalar };
	}

	avl_ainl constexpr auto mul_set(v2& vec, const v2& other) noexcept -> void {
		set_all(vec, get<0>(vec) * get<0>(other), get<1>(vec) * get<1>(other) );
	}

	avl_ainl constexpr auto mul_set(v2& vec, const sc scalar) noexcept {
		set_all(vec, get<0>(vec) * scalar, get<1>(vec) * scalar );
	}

	avl_ainl_res constexpr auto mul(v2& vec, const v2& other) noexcept -> v2 {
		set_all(vec, get<0>(vec) * get<0>(other), get<1>(vec) * get<1>(other) );
		return vec;
	}

	avl_ainl_res constexpr auto mul(v2& vec, const sc scalar) noexcept -> v2 {
		set_all(vec, get<0>(vec) * scalar, get<1>(vec) * scalar );
		return vec;
	}

	//div

	avl_ainl_res constexpr auto div_mk(const v2& vec, const v2& other) noexcept(ndebug) -> v2 {
		assert(get<0>(other)!=decltype(other[0]){0});
		assert(get<1>(other)!=decltype(other[1]){0});
		return decltype(vec){ get<0>(vec) / get<0>(other), get<1>(vec) / get<1>(other) };
	}

	avl_ainl_res constexpr auto div_mk(const v2& vec, const sc scalar) noexcept(ndebug) -> v2  {
		assert(scalar!=decltype(scalar){0});
		return decltype(vec){ get<0>(vec) / scalar, get<1>(vec) / scalar };
	}

	avl_ainl constexpr auto div_set(v2& vec, const v2& other) noexcept(ndebug) -> void {
		assert(get<0>(other)!=decltype(other[0]){0});
		assert(get<1>(other)!=decltype(other[0]){0});
		set_all(vec, get<0>(vec) / get<0>(other), get<1>(vec) / get<1>(other) );
	}

	avl_ainl constexpr auto div_set(v2& vec, const sc scalar) noexcept(ndebug) -> void {
		assert(scalar!=decltype(scalar){0});
		set_all(vec, get<0>(vec) / scalar, get<1>(vec) / scalar );
	}

	avl_ainl_res constexpr auto div(v2& vec, const v2& other) noexcept(ndebug) -> v2 {
		assert(get<0>(other)!=decltype(other[0]){0});
		assert(get<1>(other)!=decltype(other[0]){0});
		set_all(vec, get<0>(vec) / get<0>(other), get<1>(vec) / get<1>(other) );
		return vec;
	}

	avl_ainl_res constexpr auto div(v2& vec, const sc scalar) noexcept(ndebug) -> v2 {
		assert(scalar!=decltype(scalar){0});
		set_all(vec, get<0>(vec) / scalar, get<1>(vec) / scalar );
		return vec;
	}

	/// Returns the inverse of the vector
	avl_ainl_res constexpr auto inv_mk(const v2& vec) noexcept -> v2 {
		return decltype(vec){ -get<0>(vec), -get<1>(vec) };
	}

	/// Inverse the current vector
	avl_ainl constexpr auto inv_set(v2& vec) noexcept -> void {
		set_all(vec, -get<0>(vec), -get<1>(vec) );
	}
	
	/// Inverse the current vector
	avl_ainl_res constexpr auto inv(v2& vec) noexcept -> v2 {
		set_all(vec,  -get<0>(vec), -get<1>(vec) );
		return vec;
	}

	//no cross product in 2D space

	/// Calculate the area of the spawned triangel
	avl_inl_res constexpr auto area(const v2& vec, const v2& other) noexcept -> cmp_t<v2> {
		using scalar = decltype(get<0>(vec)); //not sure about this
		const auto area = scalar{0.5}*(get<0>(vec) * get<1>(other) - get<1>(vec) * get<0>(other));
		return area < scalar{0}
			? -area
			: area;
	}

	/// @}
	/// @name Vector Length Operations
	/// @{

	/// Calculate the square length of the vector
	avl_ainl_res constexpr auto len_sqr(const v2& vec) noexcept -> cmp_t<v2> {
		const auto comp1 = get<0>(vec);
		const auto comp2 = get<1>(vec);
		return comp1 * comp1 + comp2 * comp2;
	}

	/// @}
	/// @name Vector Operations With Scalar Results
	/// @{

	avl_ainl_res constexpr auto dot(const v2& vec, const v2& other) noexcept -> cmp_t<v2> {
		return get<0>(vec) * get<0>(other) + get<1>(vec) * get<1>(other);
	}

	avl_ainl_res constexpr auto dot(const v2& vec, const sc xVal, const sc yVal) noexcept -> cmp_t<v2> {
		return get<0>(vec) * xVal + get<1>(vec) * yVal;
	}
	
	/// @}

	/// @}
}
#endif // AVL_V2_H