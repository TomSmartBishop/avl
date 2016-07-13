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

	avl_ainl_res constexpr auto add_get(const v2& vec, const v2& other) noexcept -> rem_const_ref_t<decltype(vec)> {
		return rem_const_ref_t<decltype(vec)>{ get<0>(vec) + get<0>(other), get<1>(vec) + get<1>(other) };
	}

	avl_ainl_res constexpr auto add_get(const v2& vec, const sc scalar) noexcept -> rem_const_ref_t<decltype(vec)> {
		return rem_const_ref_t<decltype(vec)>{ get<0>(vec) + scalar, get<1>(vec) + scalar };
	}

	avl_ainl constexpr auto add_set(v2& vec, const v2& other) noexcept -> void {
		set(vec, get<0>(vec) + get<0>(other), get<1>(vec) + get<1>(other) );
	}

	avl_ainl constexpr auto add_set(v2& vec, const sc scalar) noexcept -> void {
		set(vec, get<0>(vec) + scalar, get<1>(vec) + scalar );
	}

	avl_ainl_res constexpr auto add(v2& vec, const v2& other) noexcept -> decltype(vec) {
		set(vec, get<0>(vec) + get<0>(other), get<1>(vec) + get<1>(other) );
		return vec;
	}

	avl_ainl_res constexpr auto add(v2& vec, const sc scalar) noexcept -> decltype(vec) {
		set(vec, get<0>(vec) + scalar, get<1>(vec) + scalar );
		return vec;
	}

	//sub

	avl_ainl_res constexpr auto sub_get(const v2& vec, const v2& other) noexcept -> rem_const_ref_t<decltype(vec)> {
		return rem_const_ref_t<decltype(vec)>{ get<0>(vec) - get<0>(other), get<1>(vec) - get<1>(other) };
	}

	avl_ainl_res constexpr auto sub_get(const v2& vec, const sc scalar) noexcept -> rem_const_ref_t<decltype(vec)> {
		return rem_const_ref_t<decltype(vec)>{ get<0>(vec) - scalar, get<1>(vec) - scalar };
	}

	avl_ainl constexpr auto sub_set(v2& vec, const v2& other) noexcept -> void {
		set(vec, get<0>(vec) - get<0>(other), get<1>(vec) - get<1>(other) );
	}

	avl_ainl constexpr auto sub_set(v2& vec, const sc scalar) noexcept -> void {
		set(vec, get<0>(vec) - scalar, get<1>(vec) - scalar );
	}

	avl_ainl_res constexpr auto sub(v2& vec, const v2& other) noexcept -> decltype(vec) {
		set(vec, get<0>(vec) - get<0>(other), get<1>(vec) - get<1>(other) );
		return vec;
	}

	avl_ainl_res constexpr auto sub(v2& vec, const sc scalar) noexcept -> decltype(vec) {
		set(vec, get<0>(vec) - scalar, get<1>(vec) - scalar );
		return vec;
	}

	// mul

	avl_ainl_res constexpr auto mul_get(const v2& vec, const v2& other) noexcept -> rem_const_ref_t<decltype(vec)> {
		return rem_const_ref_t<decltype(vec)>{ get<0>(vec) * get<0>(other), get<1>(vec) * get<1>(other) };
	}

	avl_ainl_res constexpr auto mul_get(const v2& vec, const sc scalar) noexcept -> rem_const_ref_t<decltype(vec)> {
		return rem_const_ref_t<decltype(vec)>{ get<0>(vec) * scalar, get<1>(vec) * scalar };
	}

	avl_ainl constexpr auto mul_set(v2& vec, const v2& other) noexcept -> void {
		set(vec, get<0>(vec) * get<0>(other), get<1>(vec) * get<1>(other) );
	}

	avl_ainl constexpr auto mul_set(v2& vec, const sc scalar) noexcept {
		set(vec, get<0>(vec) * scalar, get<1>(vec) * scalar );
	}

	avl_ainl_res constexpr auto mul(v2& vec, const v2& other) noexcept -> decltype(vec) {
		set(vec, get<0>(vec) * get<0>(other), get<1>(vec) * get<1>(other) );
		return vec;
	}

	avl_ainl_res constexpr auto mul(v2& vec, const sc scalar) noexcept -> decltype(vec) {
		set(vec, get<0>(vec) * scalar, get<1>(vec) * scalar );
		return vec;
	}

	//div

	avl_ainl_res constexpr auto div_get(const v2& vec, const v2& other) noexcept(ndebug) -> rem_const_ref_t<decltype(vec)> {
		assert(get<0>(other)!=decltype(other[0]){0});
		assert(get<1>(other)!=decltype(other[1]){0});
		return rem_const_ref_t<decltype(vec)>{ get<0>(vec) / get<0>(other), get<1>(vec) / get<1>(other) };
	}

	avl_ainl_res constexpr auto div_get(const v2& vec, const sc scalar) noexcept(ndebug) -> rem_const_ref_t<decltype(vec)>  {
		assert(scalar!=decltype(scalar){0});
		return rem_const_ref_t<decltype(vec)>{ get<0>(vec) / scalar, get<1>(vec) / scalar };
	}

	avl_ainl constexpr auto div_set(v2& vec, const v2& other) noexcept(ndebug) -> void {
		assert(get<0>(other)!=decltype(other[0]){0});
		assert(get<1>(other)!=decltype(other[0]){0});
		set(vec, get<0>(vec) / get<0>(other), get<1>(vec) / get<1>(other) );
	}

	avl_ainl constexpr auto div_set(v2& vec, const sc scalar) noexcept(ndebug) -> void {
		assert(scalar!=decltype(scalar){0});
		set(vec, get<0>(vec) / scalar, get<1>(vec) / scalar );
	}

	avl_ainl_res constexpr auto div(v2& vec, const v2& other) noexcept(ndebug) -> decltype(vec) {
		assert(get<0>(other)!=decltype(other[0]){0});
		assert(get<1>(other)!=decltype(other[0]){0});
		set(vec, get<0>(vec) / get<0>(other), get<1>(vec) / get<1>(other) );
		return vec;
	}

	avl_ainl_res constexpr auto div(v2& vec, const sc scalar) noexcept(ndebug) -> decltype(vec) {
		assert(scalar!=decltype(scalar){0});
		set(vec, get<0>(vec) / scalar, get<1>(vec) / scalar );
		return vec;
	}

//	/// Returns the inverse of the vector
//	template<typename cmp, typename st>
//	avl_check_result
//	avl_may_inline constexpr v2<cmp, st> inv(const v2<cmp, st>& vec) noexcept {
//		return v2<cmp, st>{ -get<0>(vec), -get<1>(vec) };
//	}
//
//	/// Inverse the current vector
//	template<typename cmp, typename st>
//	avl_may_inline avl_constexpr_void invSet(v2<cmp, st>& vec) noexcept {
//		set(vec,  -get<0>(vec), -get<1>(vec) );
//	}
//
//	//no cross product in 2D space
//
//	/// Calculate the area of the spawned triangel
//	template<typename cmp, typename st>
//	avl_check_result
//	avl_may_inline constexpr cmp area(const v2<cmp, st>& vec, const v2<cmp, st>& other) noexcept {
//		const cmp area = cmp{0.5}*(get<0>(vec) * get<1>(other) - get<1>(vec) * get<0>(other));
//		return area < cmp{0}
//			? -area
//			: area;
//	}
//
//	/// @}
//	/// @name Vector Length Operations
//	/// @{
//
//	/// Calculate the square length of the vector
//	template<typename cmp, typename st>
//	avl_check_result
//	avl_may_inline constexpr cmp lenSqr(const v2<cmp, st>& vec) noexcept {
//		const cmp comp1 = get<0>(vec);
//		const cmp comp2 = get<1>(vec);
//		return comp1 * comp1 + comp2 * comp2;
//	}
//
//	/// Calculate the length of the vector, prefere lenSqr when comparing distances (faster)
//	template<typename cmp, typename st>
//	avl_check_result
//	avl_may_inline constexpr cmp len(const v2<cmp, st>& vec) avl_may_except {
//		return std::sqrt( lenSqr(vec) );
//	}
//
//	/// Returns a new vector with the requested length
//	template<typename cmp, typename st>
//	avl_check_result
//	avl_may_inline constexpr v2<cmp, st> lenVec(const v2<cmp, st>& vec, const cmp newLen) avl_may_except {
//		return mul(vec, len(vec));
//	}
//
//	/// Set the length of the vector
//	template<typename cmp, typename st>
//	avl_may_inline avl_constexpr_void lenSet(v2<cmp, st>& vec, const cmp newLen) avl_may_except {
//		mulSet(vec, newLen/len(vec));
//	}
//
//	/// Returns a normalized vector
//	template<typename cmp, typename st>
//	avl_check_result
//	avl_may_inline constexpr v2<cmp, st> norm(const v2<cmp, st>& vec) avl_may_except {
//		return div(vec, len(vec));
//	}
//
//	/// Normalize the current vector
//	template<typename cmp, typename st>
//	avl_may_inline avl_constexpr_void normSet(v2<cmp, st>& vec) avl_may_except {
//		divSet(vec, len(vec));
//	}
//
//	/// @}
//	/// @name Vector Operations With Scalar Results
//	/// @{
//
//	template<typename cmp, typename st, template<typename, typename> typename v>
//	avl_check_result
//	avl_no_inline constexpr cmp angleRd(const v<cmp, st>& vec, const v<cmp, st>& other) avl_may_except {
//		return std::acos( dot(vec, other) / (len(vec) * len(other)) );
//	}
//
//	template<typename cmp, typename st, template<typename, typename> typename v>
//	avl_check_result
//	avl_no_inline constexpr cmp angleDg(const v<cmp, st>& vec, const v<cmp, st>& other) avl_may_except {
//		return std::acos( dot(vec, other) / (len(vec) * len(other)) ) * cnst<cmp>::toDeg;
//	}
//
//	template<typename cmp, typename st>
//	avl_check_result
//	avl_may_inline constexpr cmp dot(const v2<cmp, st>& vec, const v2<cmp, st>& other) noexcept {
//		return get<0>(vec) * get<0>(other) + get<1>(vec) * get<1>(other);
//	}
//
//	template<typename cmp, typename st>
//	avl_check_result
//	avl_may_inline constexpr cmp dot(const v2<cmp, st>& vec, const cmp xVal, const cmp yVal) noexcept {
//		return get<0>(vec) * xVal + get<1>(vec) * yVal;
//	}
	/// @}

	/// @}
}
#endif // AVL_V2_H