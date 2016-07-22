#ifndef AVL_V3_H
#define AVL_V3_H

#pragma once

/// avl: A Vector Library
/// \author Thomas Pollak
namespace avl {
	
	/// \defgroup Free functions for 3 component vectors
	/// @{
	
	/// @name Getters and Setters
	/// @{
	
	/// Set all vector components to the same scalar
	avl_ainl constexpr auto set_all(v3& vec, const sc scalar) noexcept -> void {
		static_assert(eq<decltype(vec[0]), decltype(scalar)>::value, "Supply a scalar of the vectors element type.");
		vec[0] = scalar;
		vec[1] = scalar;
		vec[2] = scalar;
	}
	
	/// Set all vector components individually
	avl_ainl constexpr auto set_all(v3& vec, const sc x, const sc y, const sc z) noexcept -> void {
		static_assert(eq<decltype(vec[0]), decltype(x)>::value, "Supply a scalar of the vectors element type for x.");
		static_assert(eq<decltype(vec[1]), decltype(y)>::value, "Supply a scalar of the vectors element type for y.");
		static_assert(eq<decltype(vec[2]), decltype(z)>::value, "Supply a scalar of the vectors element type for z.");
		vec[0] = x;
		vec[1] = y;
		vec[2] = z;
	}
	
	/// Set all vector components individually
	avl_ainl constexpr auto set_all(v3& vec, const sc scalars[3]) noexcept -> void {
		static_assert(eq<decltype(vec[0]), decltype(scalars[0])>::value, "Supply a scalar of the vectors element type.");
		static_assert(eq<decltype(vec[1]), decltype(scalars[1])>::value, "Supply a scalar of the vectors element type.");
		static_assert(eq<decltype(vec[2]), decltype(scalars[2])>::value, "Supply a scalar of the vectors element type.");
		vec[0] = scalars[0];
		vec[1] = scalars[1];
		vec[2] = scalars[2];
	}
	
	/// Set all vector components individually
	template <s::size_t _Dim>
	avl_ainl constexpr auto set_all(v3& vec, const sc* scalars) noexcept -> void {
		static_assert(_Dim>=3, "Supply at least 3 scalars.");
		static_assert(eq<decltype(vec[0]), decltype(scalars[0])>::value, "Supply a scalar of the vectors element type.");
		static_assert(eq<decltype(vec[1]), decltype(scalars[1])>::value, "Supply a scalar of the vectors element type.");
		static_assert(eq<decltype(vec[2]), decltype(scalars[2])>::value, "Supply a scalar of the vectors element type.");
		vec[0] = scalars[0];
		vec[1] = scalars[1];
		vec[2] = scalars[2];
	}
	
	/// @}
	/// @name General Vector Operations
	/// @{
	
	// add make
	
	avl_ainl_res constexpr auto add_mk(const v3& vec, const v3& other) noexcept {//-> rem_const_ref_t<decltype(vec)> { // -> v3 {
		return rem_const_ref_t< decltype(vec) > { get<0>(vec) + get<0>(other), get<1>(vec) + get<1>(other), get<2>(vec) + get<2>(other) };
	}
	
	avl_ainl_res constexpr auto add_mk(const v3& vec, const sc scalar) noexcept {//-> rem_const_ref_t<decltype(vec)> { // -> v3 {
		return rem_const_ref_t< decltype(vec) > { get<0>(vec) + scalar, get<1>(vec) + scalar, get<2>(vec) + scalar };
	}
	
	// add set
	
	avl_ainl constexpr auto add_set(v3& vec, const v3& other) noexcept -> void {
		set_all(vec, get<0>(vec) + get<0>(other), get<1>(vec) + get<1>(other), get<2>(vec) + get<2>(other) );
	}
	
	avl_ainl constexpr auto add_set(v3& vec, const sc scalar) noexcept -> void {
		set_all(vec, get<0>(vec) + scalar, get<1>(vec) + scalar, get<2>(vec) + scalar );
	}
	
	// add (chaining)
	
	avl_ainl_res constexpr auto add(v3& vec, const v3& other) noexcept -> decltype(vec) {
		set_all(vec, get<0>(vec) + get<0>(other), get<1>(vec) + get<1>(other), get<2>(vec) + get<2>(other) );
		return vec;
	}
	
	avl_ainl_res constexpr auto add(v3& vec, const sc scalar) noexcept -> decltype(vec) {
		set_all(vec, get<0>(vec) + scalar, get<1>(vec) + scalar, get<2>(vec) + scalar );
		return vec;
	}
	
	// sub make
	
	avl_ainl_res constexpr auto sub_mk(const v3& vec, const v3& other) noexcept {//-> rem_const_ref_t<decltype(vec)> { // -> v3 {
		return rem_const_ref_t< decltype(vec) > { get<0>(vec) - get<0>(other), get<1>(vec) - get<1>(other), get<2>(vec) - get<2>(other) };
	}
	
	avl_ainl_res constexpr auto sub_mk(const v3& vec, const sc scalar) noexcept {//-> rem_const_ref_t<decltype(vec)> { // -> v3 {
		return rem_const_ref_t< decltype(vec) > { get<0>(vec) - scalar, get<1>(vec) - scalar, get<2>(vec) - scalar };
	}
	
	// sub set
	
	avl_ainl constexpr auto sub_set(v3& vec, const v3& other) noexcept -> void {
		set_all(vec, get<0>(vec) - get<0>(other), get<1>(vec) - get<1>(other), get<2>(vec) - get<2>(other) );
	}
	
	avl_ainl constexpr auto sub_set(v3& vec, const sc scalar) noexcept -> void {
		set_all(vec, get<0>(vec) - scalar, get<1>(vec) - scalar, get<2>(vec) - scalar );
	}
	
	// sub (chaining)
	
	avl_ainl_res constexpr auto sub(v3& vec, const v3& other) noexcept -> decltype(vec) {
		set_all(vec, get<0>(vec) - get<0>(other), get<1>(vec) - get<1>(other), get<2>(vec) - get<2>(other) );
		return vec;
	}
	
	avl_ainl_res constexpr auto sub(v3& vec, const sc scalar) noexcept -> decltype(vec) {
		set_all(vec, get<0>(vec) - scalar, get<1>(vec) - scalar, get<2>(vec) - scalar );
		return vec;
	}
	
	// mul make
	
	avl_ainl_res constexpr auto mul_mk(const v3& vec, const v3& other) noexcept {//-> rem_const_ref_t<decltype(vec)> { // -> v3 {
		return rem_const_ref_t< decltype(vec) > { get<0>(vec) * get<0>(other), get<1>(vec) * get<1>(other), get<2>(vec) * get<2>(other) };
	}
	
	avl_ainl_res constexpr auto mul_mk(const v3& vec, const sc scalar) noexcept {//-> rem_const_ref_t<decltype(vec)> { // -> v3 {
		return rem_const_ref_t< decltype(vec) > { get<0>(vec) * scalar, get<1>(vec) * scalar, get<2>(vec) * scalar };
	}
	
	// mul set
	
	avl_ainl constexpr auto mul_set(v3& vec, const v3& other) noexcept -> void {
		set_all(vec, get<0>(vec) * get<0>(other), get<1>(vec) * get<1>(other), get<2>(vec) * get<2>(other) );
	}
	
	avl_ainl constexpr auto mul_set(v3& vec, const sc scalar) noexcept -> void {
		set_all(vec, get<0>(vec) * scalar, get<1>(vec) * scalar, get<2>(vec) * scalar );
	}
	
	// mul (chaining)
	
	avl_ainl_res constexpr auto mul(v3& vec, const v3& other) noexcept -> decltype(vec) {
		set_all(vec, get<0>(vec) * get<0>(other), get<1>(vec) * get<1>(other), get<2>(vec) * get<2>(other) );
		return vec;
	}
	
	avl_ainl_res constexpr auto mul(v3& vec, const sc scalar) noexcept -> decltype(vec) {
		set_all(vec, get<0>(vec) * scalar, get<1>(vec) * scalar, get<2>(vec) * scalar );
		return vec;
	}
	
	// div make
	
	avl_ainl_res constexpr auto div_mk(const v3& vec, const v3& other) noexcept {//-> rem_const_ref_t<decltype(vec)> { // -> v3 {
		assert(get<0>(other)!=decltype(other[0]){0});
		assert(get<1>(other)!=decltype(other[1]){0});
		assert(get<2>(other)!=decltype(other[2]){0});
		return rem_const_ref_t< decltype(vec) > { get<0>(vec) / get<0>(other), get<1>(vec) / get<1>(other), get<2>(vec) / get<2>(other) };
	}
	
	avl_ainl_res constexpr auto div_mk(const v3& vec, const sc scalar) noexcept {//-> rem_const_ref_t<decltype(vec)> { // -> v3 {
		assert(scalar!=decltype(scalar){0});
		return rem_const_ref_t< decltype(vec) > { get<0>(vec) / scalar, get<1>(vec) / scalar, get<2>(vec) / scalar };
	}
	
	// div set
	
	avl_ainl constexpr auto div_set(v3& vec, const v3& other) noexcept -> void {
		assert(get<0>(other)!=decltype(other[0]){0});
		assert(get<1>(other)!=decltype(other[1]){0});
		assert(get<2>(other)!=decltype(other[2]){0});
		set_all(vec, get<0>(vec) / get<0>(other), get<1>(vec) / get<1>(other), get<2>(vec) / get<2>(other) );
	}
	
	avl_ainl constexpr auto div_set(v3& vec, const sc scalar) noexcept -> void {
		assert(scalar!=decltype(scalar){0});
		set_all(vec, get<0>(vec) / scalar, get<1>(vec) / scalar, get<2>(vec) / scalar );
	}
	
	// div (chaining)
	
	avl_ainl_res constexpr auto div(v3& vec, const v3& other) noexcept -> decltype(vec) {
		assert(get<0>(other)!=decltype(other[0]){0});
		assert(get<1>(other)!=decltype(other[1]){0});
		assert(get<2>(other)!=decltype(other[2]){0});
		set_all(vec, get<0>(vec) / get<0>(other), get<1>(vec) / get<1>(other), get<2>(vec) / get<2>(other) );
		return vec;
	}
	
	avl_ainl_res constexpr auto div(v3& vec, const sc scalar) noexcept -> decltype(vec) {
		assert(scalar!=decltype(scalar){0});
		set_all(vec, get<0>(vec) / scalar, get<1>(vec) / scalar, get<2>(vec) / scalar );
		return vec;
	}
	
	/// Calculate the cross product
	avl_ainl_res constexpr auto cross_mk(const v3& vec, const v3& other) noexcept {//-> rem_const_ref_t<decltype(vec)> { // -> v3 {
		return rem_const_ref_t<decltype(vec)> {
				get<1>(vec) * get<2>(other) - get<2>(vec) * get<1>(other),
				get<2>(vec) * get<0>(other) - get<0>(vec) * get<2>(other),
				get<0>(vec) * get<1>(other) - get<1>(vec) * get<0>(other)
			};
	}
	
	/// Calculate the cross product and assign it to the current vector
	avl_ainl constexpr auto cross_set(v3& vec, const v3& other) noexcept -> void {
		set_all(get<1>(vec) * get<2>(other) - get<2>(vec) * get<1>(other),
				get<2>(vec) * get<0>(other) - get<0>(vec) * get<2>(other),
				get<0>(vec) * get<1>(other) - get<1>(vec) * get<0>(other) );
	}
	
	/// Calculate the cross product and assign it to the current vector
	avl_ainl_res constexpr auto cross(v3& vec, const v3& other) noexcept -> decltype(vec) {
		set_all(get<1>(vec) * get<2>(other) - get<2>(vec) * get<1>(other),
				get<2>(vec) * get<0>(other) - get<0>(vec) * get<2>(other),
				get<0>(vec) * get<1>(other) - get<1>(vec) * get<0>(other) );
		return vec;
	}
	
	/// Calculate the area of the spawned triangle (using the cross product 0.5*|(a x b)|)
	avl_ainl_res constexpr auto area(v3 vec, const v3& other) noexcept -> cmp_t<v3> {
		return decltype(vec[0]){0.5}*len(cross(vec, other));
	}	
	/// @}
	/// @name Vector Length Operations
	/// @{
	
	/// Calculate the square length of the vector
	avl_ainl_res constexpr auto len_sqr(const v3& vec) noexcept -> cmp_t<v3> {
		const auto comp0 = get<0>(vec);
		const auto comp1 = get<1>(vec);
		const auto comp2 = get<2>(vec);
		return comp0 * comp0 + comp1 * comp1 + comp2 * comp2;
	}
	
	/// @}
	/// @name Vector Operations With Scalar Results
	/// @{
	
	avl_ainl_res constexpr auto dot(const v3& vec, const v3& other) noexcept -> cmp_t<v3> {
		return get<0>(vec) * get<0>(other) + get<1>(vec) * get<1>(other) + get<2>(vec) * get<2>(other);
	}
	
	/*
	avl_ainl_res constexpr auto dot(const v3& vec, const sc x, const sc y, const sc z) noexcept -> cmp_t<v3> {
		return get<0>(vec) * x + get<1>(vec) * y + get<2>(vec) * z;
	}
	*/
	
	/// @}
	
	/// @}
}
#endif // AVL_V3_H