#ifndef AVL_V2_INL
#define AVL_V2_INL

#pragma once

/// avl: A Vector Library
/// \author Thomas Pollak
namespace avl {
	
	/// \defgroup Free functions for 2 component vectors
	/// @{
	
	/// @name Getters and Setters
	/// @{
	
	/// Set all vector components to the same scalar
	avl_ainl constexpr auto set_all(v2& vec, const sc scalar) noexcept -> void {
		static_assert(eq<decltype(vec[0]), decltype(scalar)>::value, "Supply a scalar of the vectors element type.");
		vec[0] = scalar;
		vec[1] = scalar;
	} 	
	/// Set all vector components individually
	avl_ainl constexpr auto set_all(v2& vec, const sc x, const sc y) noexcept -> void {
		static_assert(eq<decltype(vec[0]), decltype(x)>::value, "Supply a scalar of the vectors element type for x.");
		static_assert(eq<decltype(vec[1]), decltype(y)>::value, "Supply a scalar of the vectors element type for y.");
		vec[0] = x;
		vec[1] = y;
	}
	
	/// Set all vector components individually
	avl_ainl constexpr auto set_all(v2& vec, const sc scalars[2]) noexcept -> void {
		static_assert(eq<decltype(vec[0]), decltype(scalars[0])>::value, "Supply a scalar of the vectors element type.");
		static_assert(eq<decltype(vec[1]), decltype(scalars[1])>::value, "Supply a scalar of the vectors element type.");
		vec[0] = scalars[0];
		vec[1] = scalars[1];
	}
	
	/// Set all vector components individually
	template <s::size_t _Dim>
	avl_ainl constexpr auto set_all(v2& vec, const sc* scalars) noexcept -> void {
		static_assert(_Dim>=2, "Supply at least 2 scalars.");
		static_assert(eq<decltype(vec[0]), decltype(scalars[0])>::value, "Supply a scalar of the vectors element type.");
		static_assert(eq<decltype(vec[1]), decltype(scalars[1])>::value, "Supply a scalar of the vectors element type.");
		vec[0] = scalars[0];
		vec[1] = scalars[1];
	}
	
	/// @}
	/// @name General Vector Operations
	/// @{
	
	// add make
	
	avl_ainl_res constexpr auto add_mk(const v2& vec, const v2& other) noexcept {
		return rem_const_ref_t< decltype(vec) > { get<0>(vec) + get<0>(other), get<1>(vec) + get<1>(other) };
	}
	
	avl_ainl_res constexpr auto add_mk(const v2& vec, const sc scalar) noexcept {
		return rem_const_ref_t< decltype(vec) > { get<0>(vec) + scalar, get<1>(vec) + scalar };
	}
	
	// add set
	
	avl_ainl constexpr auto add_set(v2& vec, const v2& other) noexcept -> void {
		set_all(vec, get<0>(vec) + get<0>(other), get<1>(vec) + get<1>(other) );
	}
	
	avl_ainl constexpr auto add_set(v2& vec, const sc scalar) noexcept -> void {
		set_all(vec, get<0>(vec) + scalar, get<1>(vec) + scalar );
	}
	
	// add (chaining)
	
	avl_ainl_res constexpr auto add(v2& vec, const v2& other) noexcept -> decltype(vec) {
		set_all(vec, get<0>(vec) + get<0>(other), get<1>(vec) + get<1>(other) );
		return vec;
	}
	
	avl_ainl_res constexpr auto add(v2& vec, const sc scalar) noexcept -> decltype(vec) {
		set_all(vec, get<0>(vec) + scalar, get<1>(vec) + scalar );
		return vec;
	}
	
	// sub make
	
	avl_ainl_res constexpr auto sub_mk(const v2& vec, const v2& other) noexcept {
		return rem_const_ref_t< decltype(vec) > { get<0>(vec) - get<0>(other), get<1>(vec) - get<1>(other) };
	}
	
	avl_ainl_res constexpr auto sub_mk(const v2& vec, const sc scalar) noexcept {
		return rem_const_ref_t< decltype(vec) > { get<0>(vec) - scalar, get<1>(vec) - scalar };
	}
	
	// sub set
	
	avl_ainl constexpr auto sub_set(v2& vec, const v2& other) noexcept -> void {
		set_all(vec, get<0>(vec) - get<0>(other), get<1>(vec) - get<1>(other) );
	}
	
	avl_ainl constexpr auto sub_set(v2& vec, const sc scalar) noexcept -> void {
		set_all(vec, get<0>(vec) - scalar, get<1>(vec) - scalar );
	}
	
	// sub (chaining)
	
	avl_ainl_res constexpr auto sub(v2& vec, const v2& other) noexcept -> decltype(vec) {
		set_all(vec, get<0>(vec) - get<0>(other), get<1>(vec) - get<1>(other) );
		return vec;
	}
	
	avl_ainl_res constexpr auto sub(v2& vec, const sc scalar) noexcept -> decltype(vec) {
		set_all(vec, get<0>(vec) - scalar, get<1>(vec) - scalar );
		return vec;
	}
	
	// mul make
	
	avl_ainl_res constexpr auto mul_mk(const v2& vec, const v2& other) noexcept {
		return rem_const_ref_t< decltype(vec) > { get<0>(vec) * get<0>(other), get<1>(vec) * get<1>(other) };
	}
	
	avl_ainl_res constexpr auto mul_mk(const v2& vec, const sc scalar) noexcept {
		return rem_const_ref_t< decltype(vec) > { get<0>(vec) * scalar, get<1>(vec) * scalar };
	}
	
	// mul set
	
	avl_ainl constexpr auto mul_set(v2& vec, const v2& other) noexcept -> void {
		set_all(vec, get<0>(vec) * get<0>(other), get<1>(vec) * get<1>(other) );
	}
	
	avl_ainl constexpr auto mul_set(v2& vec, const sc scalar) noexcept -> void {
		set_all(vec, get<0>(vec) * scalar, get<1>(vec) * scalar );
	}
	
	// mul (chaining)
	
	avl_ainl_res constexpr auto mul(v2& vec, const v2& other) noexcept -> decltype(vec) {
		set_all(vec, get<0>(vec) * get<0>(other), get<1>(vec) * get<1>(other) );
		return vec;
	}
	
	avl_ainl_res constexpr auto mul(v2& vec, const sc scalar) noexcept -> decltype(vec) {
		set_all(vec, get<0>(vec) * scalar, get<1>(vec) * scalar );
		return vec;
	}
	
	// div make
	
	avl_ainl_res constexpr auto div_mk(const v2& vec, const v2& other) noexcept {
		assert(get<0>(other)!=decltype(other[0]){0});
		assert(get<1>(other)!=decltype(other[1]){0});
		return rem_const_ref_t< decltype(vec) > { get<0>(vec) / get<0>(other), get<1>(vec) / get<1>(other) };
	}
	
	avl_ainl_res constexpr auto div_mk(const v2& vec, const sc scalar) noexcept {
		assert(scalar!=decltype(scalar){0});
		return rem_const_ref_t< decltype(vec) > { get<0>(vec) / scalar, get<1>(vec) / scalar };
	}
	
	// div set
	
	avl_ainl constexpr auto div_set(v2& vec, const v2& other) noexcept -> void {
		assert(get<0>(other)!=decltype(other[0]){0});
		assert(get<1>(other)!=decltype(other[1]){0});
		set_all(vec, get<0>(vec) / get<0>(other), get<1>(vec) / get<1>(other) );
	}
	
	avl_ainl constexpr auto div_set(v2& vec, const sc scalar) noexcept -> void {
		assert(scalar!=decltype(scalar){0});
		set_all(vec, get<0>(vec) / scalar, get<1>(vec) / scalar );
	}
	
	// div (chaining)
	
	avl_ainl_res constexpr auto div(v2& vec, const v2& other) noexcept -> decltype(vec) {
		assert(get<0>(other)!=decltype(other[0]){0});
		assert(get<1>(other)!=decltype(other[1]){0});
		set_all(vec, get<0>(vec) / get<0>(other), get<1>(vec) / get<1>(other) );
		return vec;
	}
	
	avl_ainl_res constexpr auto div(v2& vec, const sc scalar) noexcept -> decltype(vec) {
		assert(scalar!=decltype(scalar){0});
		set_all(vec, get<0>(vec) / scalar, get<1>(vec) / scalar );
		return vec;
	}
	
	//no cross product in 2D space
	
	/// Calculate the area of the spawned triangel
	avl_inl_res constexpr auto area(const v2& vec, const v2& other) noexcept -> decltype(cmp(vec)) {
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
	avl_ainl_res constexpr auto len_sqr(const v2& vec) noexcept -> decltype(cmp(vec)) {
		const auto cmp0 = get<0>(vec);
		const auto cmp1 = get<1>(vec);
		return cmp0 * cmp0 + cmp1 * cmp1;
	}
	
	/// @}
	/// @name Vector Operations With Scalar Results
	/// @{
	
	avl_ainl_res constexpr auto dot(const v2& vec, const v2& other) noexcept -> decltype(cmp(vec)) {
		return get<0>(vec) * get<0>(other) + get<1>(vec) * get<1>(other);
	}
	
	/// @}
	
	/// @}
}
#endif // AVL_V2_INL