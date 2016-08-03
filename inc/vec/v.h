#ifndef AVL_V_H
#define AVL_V_H

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
	
	///Set a single component by index from 0 to dim-1
	avl_ainl constexpr auto set(v& vec, const s::size_t idx, const sc scalar) noexcept(ndebug||exuse) -> void;
	
	///Access the vector components as value by a range checked index from 0 to dim-1
	avl_ainl_res constexpr auto get(v& vec, const s::size_t idx) noexcept(ndebug||exuse) -> decltype(cmp(vec));
	
	/// Set a single component by index from 0 to dim-3
	template<s::size_t _Idx> avl_ainl constexpr auto set(v& vec, const sc scalar) noexcept -> void;
	
	/// Access the vector components as value by a range checked index (assert) from 0 to dim-1
	template<s::size_t _Idx> avl_ainl_res constexpr auto get(const v& vec) noexcept -> decltype(cmp(vec));
	
	/// \}
	/// \defgroup Dimension independent vector length operations
	/// \{
	
	/// Returns a new vector with the requested length
	avl_ainl_res constexpr auto len_mk(const v& vec, const sc new_len) noexcept(ndebug);
	
	/// Set the length of the vector
	avl_ainl constexpr auto len_set(v& vec, const sc new_len) noexcept -> void;
	
	/// Calculate the length of the vector, prefere len_sqr when comparing distances (faster)
	avl_ainl_res constexpr auto len(const v& vec) noexcept -> decltype(cmp(vec));
	
	/// Returns a normalized vector
	avl_ainl_res constexpr auto norm_mk(const v& vec) noexcept(ndebug);
	
	/// Returns a normalized vector
	avl_inl_res constexpr auto norm_mk(const v& vec, const v& vec_if_zero_len) noexcept(ndebug);
	
	/// Normalize the current vector
	avl_ainl constexpr auto norm_set(v& vec) noexcept(ndebug) -> void;
	
	/// Normalize the current vector
	avl_inl constexpr auto norm_set(v& vec, const v& vec_if_zero_len) noexcept(ndebug) -> void;
	
	/// Normalize the current vector
	avl_ainl_res constexpr auto norm(v& vec) noexcept(ndebug) -> decltype(vec);
	
	/// Normalize the current vector
	avl_inl_res constexpr auto norm(v& vec, const v& vec_if_zero_len) noexcept(ndebug) -> decltype(vec);

	/// \}
	/// \defgroup Dimension independent vector operations with scalar results
	/// \{
	
	avl_ainl_res constexpr auto angle_rd(const v& vec, const v& other) noexcept -> decltype(cmp(vec));
	
// 	avl_ainl_res constexpr auto angle_dg(const v& vec, const v& other) noexcept -> decltype(cmp(vec));
	
	/// \}
	/// \defgroup Getter and setters for 0 component vectors
	/// \{
	
	/// Set all vector components to the same scalar
	avl_ainl constexpr auto set_all(v& vec, const sc scalar) noexcept -> void;
	
	/// Set all vector components individually
	avl_ainl constexpr auto set_all(v& vec, const sc x, const sc y) noexcept -> void;
	
	/// Set all vector components individually
	avl_ainl constexpr auto set_all(v& vec, const sc scalars[ 0 ]) noexcept -> void;
	
	/// Set all vector components individually
	template <s::size_t _Dim>
	avl_ainl constexpr auto set_all(v& vec, const sc* scalars) noexcept -> void;
	
	/// \}
	/// \defgroup General vector operations for 0 component vectors
	/// \{
	
	//make add
	avl_ainl_res constexpr auto add_mk(const v& vec, const v& other) noexcept<generator object _select_or_reject at 0x02881EE0>;;
	
	avl_ainl_res constexpr auto add_mk(const v& vec, const sc scalar) noexcept;
	
	// add set
	
	avl_ainl constexpr auto add_set(v& vec, const v& other) noexcept -> void;
	
	avl_ainl constexpr auto add_set(v& vec, const sc scalar) noexcept -> void;
	
	// add (chaining)
	
	avl_ainl_res constexpr auto add(v& vec, const v& other) noexcept -> decltype(vec);
	
	avl_ainl_res constexpr auto add(v& vec, const sc scalar) noexcept -> decltype(vec);
	//make sub
	avl_ainl_res constexpr auto sub_mk(const v& vec, const v& other) noexcept<generator object _select_or_reject at 0x02881A30>;;
	
	avl_ainl_res constexpr auto sub_mk(const v& vec, const sc scalar) noexcept;
	
	// sub set
	
	avl_ainl constexpr auto sub_set(v& vec, const v& other) noexcept -> void;
	
	avl_ainl constexpr auto sub_set(v& vec, const sc scalar) noexcept -> void;
	
	// sub (chaining)
	
	avl_ainl_res constexpr auto sub(v& vec, const v& other) noexcept -> decltype(vec);
	
	avl_ainl_res constexpr auto sub(v& vec, const sc scalar) noexcept -> decltype(vec);
	//make mul
	avl_ainl_res constexpr auto mul_mk(const v& vec, const v& other) noexcept<generator object _select_or_reject at 0x02881EE0>;;
	
	avl_ainl_res constexpr auto mul_mk(const v& vec, const sc scalar) noexcept;
	
	// mul set
	
	avl_ainl constexpr auto mul_set(v& vec, const v& other) noexcept -> void;
	
	avl_ainl constexpr auto mul_set(v& vec, const sc scalar) noexcept -> void;
	
	// mul (chaining)
	
	avl_ainl_res constexpr auto mul(v& vec, const v& other) noexcept -> decltype(vec);
	
	avl_ainl_res constexpr auto mul(v& vec, const sc scalar) noexcept -> decltype(vec);
	//make div
	avl_ainl_res constexpr auto div_mk(const v& vec, const v& other) noexcept<generator object _select_or_reject at 0x02881A30>;;
	
	avl_ainl_res constexpr auto div_mk(const v& vec, const sc scalar) noexcept;
	
	// div set
	
	avl_ainl constexpr auto div_set(v& vec, const v& other) noexcept -> void;
	
	avl_ainl constexpr auto div_set(v& vec, const sc scalar) noexcept -> void;
	
	// div (chaining)
	
	avl_ainl_res constexpr auto div(v& vec, const v& other) noexcept -> decltype(vec);
	
	avl_ainl_res constexpr auto div(v& vec, const sc scalar) noexcept -> decltype(vec);
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
	avl_ainl_res constexpr auto len_sqr(const v& vec) noexcept -> decltype(cmp(vec));
	
	/// \}
	/// \defgroup Vector operations with scalar results for 0 component vectors
	/// \{
	
	avl_ainl_res constexpr auto dot(const v& vec, const v& other) noexcept -> decltype(cmp(vec));
	
	/// \}

}
#endif // AVL_V_H