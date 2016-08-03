#ifndef AVL_V_INL
#define AVL_V_INL

#pragma once

/// avl: A Vector Library
/// \author Thomas Pollak
namespace avl
{
	/// \defgroup Helper functions
	/// \{
	
	//Component type helper
	avl_ainl_res constexpr auto cmp(const v& vec) noexcept -> rem_const_ref_t<decltype(vec[0])>
	{
		return vec[0];
	}
	
	/// \}
	/// \defgroup Getters and setters for all vectors
	/// \{
	
	///Set a single component by index from 0 to dim-1
	avl_ainl constexpr auto set(v& vec, const s::size_t idx, const sc scalar) noexcept(ndebug||exuse) -> void
	{
		static_assert(eq< decltype( vec[idx] ), decltype( scalar ) >::value, "Supply a scalar of the vectors element type.");
		assert(idx < dim< rem_const_ref_t< decltype( vec ) > >::value);
		vec[idx] = scalar;
	}
	
	///Access the vector components as value by a range checked index from 0 to dim-1
	avl_ainl_res constexpr auto get(v& vec, const s::size_t idx) noexcept(ndebug||exuse) -> decltype(cmp(vec))
	{
		assert(idx < dim< rem_const_ref_t< decltype( vec ) > >::value);
		return vec[idx];
	}
	
	/// Set a single component by index from 0 to dim-3
	template<s::size_t _Idx> avl_ainl constexpr auto set(v& vec, const sc scalar) noexcept -> void
	{
		static_assert(eq< decltype( vec[_Idx] ), decltype( scalar ) >::value, "Supply a scalar of the vectors element type.");
		static_assert(_Idx < dim< rem_const_ref_t< decltype( vec ) > >::value, "Index is out of range");
		vec[_Idx] = scalar;
	}
	
	/// Access the vector components as value by a range checked index (assert) from 0 to dim-1
	template<s::size_t _Idx> avl_ainl_res constexpr auto get(const v& vec) noexcept -> decltype(cmp(vec))
	{
		static_assert(_Idx < dim< rem_const_ref_t< decltype( vec ) > >::value, "Index is out of range");
		return vec[_Idx];
	}
	
	/// \}
	/// \defgroup Dimension independent vector length operations
	/// \{
	
	/// Returns a new vector with the requested length
	avl_ainl_res constexpr auto len_mk(const v& vec, const sc new_len) noexcept(ndebug) {
		assert(new_len!=decltype(new_len){0});
		return mul_mk(vec, new_len / len(vec));
	}
	
	/// Set the length of the vector
	avl_ainl constexpr auto len_set(v& vec, const sc new_len) noexcept -> void {
		assert(new_len!=decltype(new_len){0});
		mul_set(vec, new_len / len(vec));
	}
	
	/// Calculate the length of the vector, prefere len_sqr when comparing distances (faster)
	avl_ainl_res constexpr auto len(const v& vec) noexcept -> decltype(cmp(vec)) {
		//len_sqr will never return any negativ values so we can gurantee noexcept
		return static_cast<decltype(cmp(vec))>( s::sqrt( len_sqr(vec) ) );
	}
	
	/// Returns a normalized vector
	avl_ainl_res constexpr auto norm_mk(const v& vec) noexcept(ndebug) {
		return div_mk(vec, len(vec)); //div might assert in debug
	}
	
	/// Returns a normalized vector
	avl_inl_res constexpr auto norm_mk(const v& vec, const v& vec_if_zero_len) noexcept(ndebug) {
		auto l = len(vec);
		if(l==decltype(l){0})
			return vec_if_zero_len;
		else
			return div_mk(vec, l); //div might assert in debug
	}
	
	/// Normalize the current vector
	avl_ainl constexpr auto norm_set(v& vec) noexcept(ndebug) -> void {
		div_set(vec, len(vec));
	}
	
	/// Normalize the current vector
	avl_inl constexpr auto norm_set(v& vec, const v& vec_if_zero_len) noexcept(ndebug) -> void {
		auto l = len(vec);
		if(l==decltype(l){0})
			set_all(vec, vec_if_zero_len);
		else
			div_set(vec, len(vec));
	}
	
	/// Normalize the current vector
	avl_ainl_res constexpr auto norm(v& vec) noexcept(ndebug) -> decltype(vec) {
		div_set(vec, len(vec));
		return vec;
	}
	
	/// Normalize the current vector
	avl_inl_res constexpr auto norm(v& vec, const v& vec_if_zero_len) noexcept(ndebug) -> decltype(vec) {
		auto l = len(vec);
		if(l==decltype(l){0})
			set_all(vec, vec_if_zero_len);
		else
			div_set(vec, len(vec));
		return vec;
	}

	/// \}
	/// \defgroup Dimension independent vector operations with scalar results
	/// \{
	
	avl_ainl_res constexpr auto angle_rd(const v& vec, const v& other) noexcept -> decltype(cmp(vec)) {
		return s::acos( dot(vec, other) / (len(vec) * len(other)) );
	}
	
// 	avl_ainl_res constexpr auto angle_dg(const v& vec, const v& other) noexcept -> decltype(cmp(vec)) {
// 		return s::acos( dot(vec, other) / (len(vec) * len(other)) ) * cnst<cmp>::to_deg;
// 	}
	
	/// \}
	/// \defgroup Getter and setters for 0 component vectors
	/// \{
	
	/// Set all vector components to the same scalar
	avl_ainl constexpr auto set_all(v& vec, const sc scalar) noexcept -> void {
		static_assert(eq<decltype(vec[0]), decltype(scalar)>::value, "Supply a scalar of the vectors element type.");
	} 	
	/// Set all vector components individually
	avl_ainl constexpr auto set_all(v& vec, const sc x, const sc y) noexcept -> void {
	}
	
	/// Set all vector components individually
	avl_ainl constexpr auto set_all(v& vec, const sc scalars[ 0 ]) noexcept -> void {
	}
	
	/// Set all vector components individually
	template <s::size_t _Dim>
	avl_ainl constexpr auto set_all(v& vec, const sc* scalars) noexcept -> void {
		static_assert(_Dim>=0, "Supply at least 0 scalars.");
	}
	
	/// \}
	/// \defgroup General vector operations for 0 component vectors
	/// \{
	
	avl_ainl_res constexpr auto add_mk(const v& vec, const sc scalar) noexcept {
		return rem_const_ref_t< decltype(vec) > {  };
	}
	
	// add set
	
	avl_ainl constexpr auto add_set(v& vec, const v& other) noexcept -> void {
		set_all(vec,  );
	}
	
	avl_ainl constexpr auto add_set(v& vec, const sc scalar) noexcept -> void {
		set_all(vec,  );
	}
	
	// add (chaining)
	
	avl_ainl_res constexpr auto add(v& vec, const v& other) noexcept -> decltype(vec) {
		set_all(vec,  );
		return vec;
	}
	
	avl_ainl_res constexpr auto add(v& vec, const sc scalar) noexcept -> decltype(vec) {
		set_all(vec,  );
		return vec;
	}
	avl_ainl_res constexpr auto sub_mk(const v& vec, const sc scalar) noexcept {
		return rem_const_ref_t< decltype(vec) > {  };
	}
	
	// sub set
	
	avl_ainl constexpr auto sub_set(v& vec, const v& other) noexcept -> void {
		set_all(vec,  );
	}
	
	avl_ainl constexpr auto sub_set(v& vec, const sc scalar) noexcept -> void {
		set_all(vec,  );
	}
	
	// sub (chaining)
	
	avl_ainl_res constexpr auto sub(v& vec, const v& other) noexcept -> decltype(vec) {
		set_all(vec,  );
		return vec;
	}
	
	avl_ainl_res constexpr auto sub(v& vec, const sc scalar) noexcept -> decltype(vec) {
		set_all(vec,  );
		return vec;
	}
	avl_ainl_res constexpr auto mul_mk(const v& vec, const sc scalar) noexcept {
		return rem_const_ref_t< decltype(vec) > {  };
	}
	
	// mul set
	
	avl_ainl constexpr auto mul_set(v& vec, const v& other) noexcept -> void {
		set_all(vec,  );
	}
	
	avl_ainl constexpr auto mul_set(v& vec, const sc scalar) noexcept -> void {
		set_all(vec,  );
	}
	
	// mul (chaining)
	
	avl_ainl_res constexpr auto mul(v& vec, const v& other) noexcept -> decltype(vec) {
		set_all(vec,  );
		return vec;
	}
	
	avl_ainl_res constexpr auto mul(v& vec, const sc scalar) noexcept -> decltype(vec) {
		set_all(vec,  );
		return vec;
	}
	avl_ainl_res constexpr auto div_mk(const v& vec, const sc scalar) noexcept {
		assert(scalar!=decltype(scalar){0});
		return rem_const_ref_t< decltype(vec) > {  };
	}
	
	// div set
	
	avl_ainl constexpr auto div_set(v& vec, const v& other) noexcept -> void {
		set_all(vec,  );
	}
	
	avl_ainl constexpr auto div_set(v& vec, const sc scalar) noexcept -> void {
		assert(scalar!=decltype(scalar){0});
		set_all(vec,  );
	}
	
	// div (chaining)
	
	avl_ainl_res constexpr auto div(v& vec, const v& other) noexcept -> decltype(vec) {
		set_all(vec,  );
		return vec;
	}
	
	avl_ainl_res constexpr auto div(v& vec, const sc scalar) noexcept -> decltype(vec) {
		assert(scalar!=decltype(scalar){0});
		set_all(vec,  );
		return vec;
	}
	/// Calculate the cross product for x,y,z, setting w to 0
	avl_ainl_res constexpr auto cross3_mk(const v4& vec, const v4& other) noexcept{% if type=='h' %};
	{% else %} {
		return rem_const_ref_t<decltype(vec)> {
				get<1>(vec) * get<2>(other) - get<2>(vec) * get<1>(other),
				get<2>(vec) * get<0>(other) - get<0>(vec) * get<2>(other),
				get<0>(vec) * get<1>(other) - get<1>(vec) * get<0>(other),
				0
			};
	}
	{% endif %}
	
	/// Calculate the cross product for x,y,z, setting w to 0 and assign it to the current vector
	avl_ainl constexpr auto cross3_set(v4& vec, const v4& other) noexcept -> void{% if type=='h' %};
	{% else %} {
		set_all(get<1>(vec) * get<2>(other) - get<2>(vec) * get<1>(other),
				get<2>(vec) * get<0>(other) - get<0>(vec) * get<2>(other),
				get<0>(vec) * get<1>(other) - get<1>(vec) * get<0>(other),
				0);
	}
	{% endif %}
	
	/// Calculate the cross product for x,y,z, setting w to 0 and assign it to the current vector
	avl_ainl_res constexpr auto cross3(v4& vec, const v4& other) noexcept -> decltype(vec){% if type=='h' %};
	{% else %} {
		set_all(get<1>(vec) * get<2>(other) - get<2>(vec) * get<1>(other),
				get<2>(vec) * get<0>(other) - get<0>(vec) * get<2>(other),
				get<0>(vec) * get<1>(other) - get<1>(vec) * get<0>(other),
				0);
		return vec;
	}
	{% endif %}
	
	/// Calculate the area of the spawned triangle (using the cross product 0.5*|(a x b)|)
	avl_ainl_res constexpr auto area3(v4 vec, const v4& other) noexcept -> decltype(cmp(vec)){% if type=='h' %};
	{% else %} {
		return decltype(vec[0]){0.5}*len(cross3(vec, other));
	}
	{% endif %}	
	/// \}
	/// \defgroup Vector length operations for 0 component vectors
	/// \{
	
	/// Calculate the square length of the vector
	avl_ainl_res constexpr auto len_sqr(const v& vec) noexcept -> decltype(cmp(vec)) {
		return ;
	}
	
	/// \}
	/// \defgroup Vector operations with scalar results for 0 component vectors
	/// \{
	
	avl_ainl_res constexpr auto dot(const v& vec, const v& other) noexcept -> decltype(cmp(vec)) {
		return ;
	}
	
	/// \}

}
#endif // AVL_V_INL