#ifndef AVL_TRAITS_H
#define AVL_TRAITS_H

#pragma once

/// avl: A Vector Library
/// \author Thomas Pollak

namespace avl {

	/// \defgroup Type Traits
	/// @{

	/// @name Is Euclidean Vector
	/// @{

	template<typename>
	struct is_eu_vec : public s::false_type { };

	template<typename _Tp, s::size_t _Size>
	struct is_eu_vec<_Tp[_Size]> : s::enable_if_t<s::is_arithmetic< s::remove_extent_t<_Tp> >::value, s::true_type > {};

	template<typename _Tp>
	struct is_eu_vec<_Tp[]> : s::enable_if_t<s::is_arithmetic< s::remove_extent_t<_Tp> >::value, s::true_type > {};

	/// @}
	/// @name Is 2D Euclidean Vector
	/// @{

	template<typename>
	struct is_eu_vec2 : public s::false_type {};

	template<typename _Tp, s::size_t _Size>
	struct is_eu_vec2<_Tp[_Size]> : public s::false_type {};

	template<typename _Tp>
	struct is_eu_vec2<_Tp[2]> : s::enable_if_t<s::is_arithmetic< s::remove_extent_t<_Tp> >::value, s::true_type > {};

	template<typename _Tp>
	struct is_eu_vec2<_Tp[]> : s::enable_if_t<_Tp::dim==2 && s::is_arithmetic< s::remove_extent_t<_Tp> >::value, s::true_type > {};

	/// @}
	/// @name Is 3D Euclidean Vector
	/// @{

	template<typename>
	struct is_eu_vec3 : public s::false_type {};

	template<typename _Tp, s::size_t _Size>
	struct is_eu_vec3<_Tp[_Size]> : public s::false_type {};

	template<typename _Tp>
	struct is_eu_vec3<_Tp[3]> : s::enable_if_t<s::is_arithmetic< s::remove_extent_t<_Tp> >::value, s::true_type > {};

	template<typename _Tp>
	struct is_eu_vec3<_Tp[]> : s::enable_if_t<_Tp::dim==3 && s::is_arithmetic< s::remove_extent_t<_Tp> >::value, s::true_type > {};

	/// @}
	/// @name Is 4D Euclidean Vector
	/// @{	template<typename>

	template<typename>
	struct is_eu_vec4 : public s::false_type {};

	template<typename _Tp, s::size_t _Size>
	struct is_eu_vec4<_Tp[_Size]> : public s::false_type {};

	template<typename _Tp>
	struct is_eu_vec4<_Tp[4]> : s::enable_if_t<s::is_arithmetic< s::remove_extent_t<_Tp> >::value, s::true_type > {};

	template<typename _Tp>
	struct is_eu_vec4<_Tp[]> : s::enable_if_t<_Tp::dim==4 && s::is_arithmetic< s::remove_extent_t<_Tp> >::value, s::true_type > {};

	/// @}

	/// @}
	/// \defgroup Concepts
	/// @{

	template <typename S>
	concept bool sc = s::is_arithmetic<S>::value;

	template <typename V>
	concept bool v = is_eu_vec<V>::value; //implicitly also checks s::is_array

	template <typename V>
	concept bool v2 = is_eu_vec2<V>::value; //implicitly also checks s::is_array

	template <typename V>
	concept bool v3 = is_eu_vec3<V>::value; //implicitly also checks s::is_array

	template <typename V>
	concept bool v4 = is_eu_vec4<V>::value; //implicitly also checks s::is_array

	/// Vector component type equals scalar type
	template <typename V, typename S>
	struct vec_cmp_eq_s : s::is_same<s::add_const_t< s::remove_extent_t< s::remove_reference_t<V> > >, S> {};

	/// @}
}

#endif // AVL_TRAITS_H