#ifndef AVL_TRAITS_H
#define AVL_TRAITS_H

#pragma once

/// avl: A Vector Library
/// \author Thomas Pollak

namespace avl {

	/// \defgroup Type Traits
	/// @{
    
    /// @name Shortcuts
	/// @{
        
    template<typename _Tp>
    using cmp_t = s::remove_extent_t<_Tp>;
    
    template<typename _Tp>
    using is_sc = typename s::is_arithmetic<_Tp>::value;
    
    using true_t = s::true_type;
    using false_t = s::false_type;
    
    template<typename _Tp>
    using true_t_if = s::enable_if_t< _Tp, true_t>;
	
    /// @}
    /// @name Is Euclidean Vector
	/// @{

	template<typename>
	struct is_eu_vec : public false_t { };

	template<typename _Tp, s::size_t _Size>
	struct is_eu_vec<_Tp[_Size]> : true_t_if< is_sc< cmp_t<_Tp> > > {};

	template<typename _Tp>
	struct is_eu_vec<_Tp[]> : true_t_if< is_sc< cmp_t<_Tp> > > {};

	/// @}
	/// @name Is 2D Euclidean Vector
	/// @{

	template<typename>
	struct is_eu_vec2 : public false_t {};

	template<typename _Tp, s::size_t _Size>
	struct is_eu_vec2<_Tp[_Size]> : public false_t {};

	template<typename _Tp>
	struct is_eu_vec2<_Tp[2]> : true_t_if< is_sc< cmp_t<_Tp> > > {};

	template<typename _Tp>
	struct is_eu_vec2<_Tp[]> : true_t_if< _Tp::dim==2 && is_sc< cmp_t<_Tp> > > {};

	/// @}
	/// @name Is 3D Euclidean Vector
	/// @{

	template<typename>
	struct is_eu_vec3 : public false_t {};

	template<typename _Tp, s::size_t _Size>
	struct is_eu_vec3<_Tp[_Size]> : public false_t {};

	template<typename _Tp>
	struct is_eu_vec3<_Tp[3]> : true_t_if< is_sc< cmp_t<_Tp> > > {};

	template<typename _Tp>
	struct is_eu_vec3<_Tp[]> : true_t_if< _Tp::dim==3 && is_sc< cmp_t<_Tp> > > {};

	/// @}
	/// @name Is 4D Euclidean Vector
	/// @{	template<typename>

	template<typename>
	struct is_eu_vec4 : public false_t {};

	template<typename _Tp, s::size_t _Size>
	struct is_eu_vec4<_Tp[_Size]> : public false_t {};

	template<typename _Tp>
	struct is_eu_vec4<_Tp[4]> : true_t_if< is_sc< cmp_t<_Tp> > > {};

	template<typename _Tp>
	struct is_eu_vec4<_Tp[]> : true_t_if< _Tp::dim==4 && is_sc< cmp_t<_Tp> > > {};

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

	template <typename _Tp>
	concept bool sc = is_sc<_Tp>;

	template <typename _Tp>
	concept bool v = is_eu_vec<_Tp>::value; //implicitly also checks s::is_array

	template <typename _Tp>
	concept bool v2 = is_eu_vec2<_Tp>::value; //implicitly also checks s::is_array

	template <typename _Tp>
	concept bool v3 = is_eu_vec3<_Tp>::value; //implicitly also checks s::is_array

	template <typename _Tp>
	concept bool v4 = is_eu_vec4<_Tp>::value; //implicitly also checks s::is_array

	/// Vector component type equals scalar type
	template <typename _Vec, typename _Sclr>
	struct vec_cmp_eq_s : s::is_same<s::add_const_t< cmp_t< s::remove_reference_t<_Vec> > >, _Sclr> {};

	/// @}
}

#endif // AVL_TRAITS_H