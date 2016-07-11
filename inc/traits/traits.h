#ifndef AVL_TRAITS_H
#define AVL_TRAITS_H

#pragma once

/// avl: A Vector Library
/// \author Thomas Pollak

namespace avl {

	/// \defgroup Type Traits
	/// @{
    
    template<typename _Tp>
    using cmp_t = s::remove_extent_t<_Tp>;
    
    template<typename _Tp>
    using is_sc = typename s::is_arithmetic<_Tp>::value;
	
    /// @name Is Euclidean Vector
	/// @{

	template<typename>
	struct is_eu_vec : public s::false_type { };

	template<typename _Tp, s::size_t _Size>
	struct is_eu_vec<_Tp[_Size]> : s::enable_if_t< is_sc< cmp_t<_Tp> >, s::true_type > {};

	template<typename _Tp>
	struct is_eu_vec<_Tp[]> : s::enable_if_t< is_sc< cmp_t<_Tp> >, s::true_type > {};

	/// @}
	/// @name Is 2D Euclidean Vector
	/// @{

	template<typename>
	struct is_eu_vec2 : public s::false_type {};

	template<typename _Tp, s::size_t _Size>
	struct is_eu_vec2<_Tp[_Size]> : public s::false_type {};

	template<typename _Tp>
	struct is_eu_vec2<_Tp[2]> : s::enable_if_t< is_sc< cmp_t<_Tp> >, s::true_type > {};

	template<typename _Tp>
	struct is_eu_vec2<_Tp[]> : s::enable_if_t< _Tp::dim==2 && is_sc< cmp_t<_Tp> >, s::true_type > {};

	/// @}
	/// @name Is 3D Euclidean Vector
	/// @{

	template<typename>
	struct is_eu_vec3 : public s::false_type {};

	template<typename _Tp, s::size_t _Size>
	struct is_eu_vec3<_Tp[_Size]> : public s::false_type {};

	template<typename _Tp>
	struct is_eu_vec3<_Tp[3]> : s::enable_if_t< is_sc< cmp_t<_Tp> >, s::true_type > {};

	template<typename _Tp>
	struct is_eu_vec3<_Tp[]> : s::enable_if_t< _Tp::dim==3 && is_sc< cmp_t<_Tp> >, s::true_type > {};

	/// @}
	/// @name Is 4D Euclidean Vector
	/// @{	template<typename>

	template<typename>
	struct is_eu_vec4 : public s::false_type {};

	template<typename _Tp, s::size_t _Size>
	struct is_eu_vec4<_Tp[_Size]> : public s::false_type {};

	template<typename _Tp>
	struct is_eu_vec4<_Tp[4]> : s::enable_if_t< is_sc< cmp_t<_Tp> >, s::true_type > {};

	template<typename _Tp>
	struct is_eu_vec4<_Tp[]> : s::enable_if_t< _Tp::dim==4 && is_sc< cmp_t<_Tp> >, s::true_type > {};

	/// @}


    template<typename>
    struct info { static constexpr s::size_t dim = 0; };
    
    template<typename _Tp>
    struct info<_Tp[2]> { static constexpr s::size_t dim = 2; };
    
    template<typename _Tp>
    struct info<_Tp[3]> { static constexpr s::size_t dim = 3; };
    
    template<typename _Tp>
    struct info<_Tp[4]> { static constexpr s::size_t dim = 4; };
    
    template<typename _Tp>
    struct info<_Tp[]> { static constexpr s::size_t dim = _Tp::dim; };
    
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
	struct vec_cmp_eq_s : s::is_same<s::add_const_t< cmp_t< s::remove_reference_t<V> > >, S> {};

	/// @}
}

#endif // AVL_TRAITS_H