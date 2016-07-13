#ifndef AVL_TRAITS_H
#define AVL_TRAITS_H

#pragma once

/// avl: A Vector Library
/// \author Thomas Pollak

namespace avl {


	//temp wrapper
	template<typename _Ty, s::size_t _Dim>
	struct vec_t {
		static constexpr s::size_t dim = _Dim;
		using cmp_t = _Ty;
		_Ty * val;

		avl_ainl_res auto operator[](const s::size_t idx) const noexcept -> const _Ty
		{
			return val[idx];
		}

		avl_ainl_res auto operator[](const s::size_t idx) noexcept -> _Ty &
		{
			return val[idx];
		}
	};

	template<typename _Ty>
	using vec2_t = vec_t<_Ty,2>;

	template<typename _Ty>
	using vec3_t = vec_t<_Ty,3>;

	template<typename _Ty>
	using vec4_t = vec_t<_Ty,4>;

	/// \defgroup Type Traits
	/// @{

	/// @name Shortcuts
	/// @{

	/// Get the component type of the vector (remove extent)
	template<typename _Tp>
	using cmp_t = s::remove_extent_t<_Tp>;

	/// Is scaler
	template<typename _Tp>
	using is_sc = typename s::is_arithmetic<_Tp>;

	/// True type
	using true_t = s::true_type;

	/// False type
	using false_t = s::false_type;

	/// True type if
	template<bool _Cond>
	using true_t_if = s::enable_if_t< _Cond, true_t>;

	template<bool _Cond>
	using true_false_t_if = s::conditional_t< _Cond, true_t, false_t>;

	/// @}
	/// @name Is Euclidean Vector
	/// @{

	template<typename>
	struct is_eu_vec : public false_t {};

	template<typename _Tp, s::size_t _Size>
	struct is_eu_vec<_Tp[_Size]> : true_t_if< is_sc< cmp_t<_Tp> >::value > {};

	template<typename _Tp>
	struct is_eu_vec<_Tp[]> : true_t_if< is_sc< cmp_t<_Tp> >::value > {};

	/// @}
	/// @name Helpers
	/// @{

    template <typename _Tp>
	using rem_const_ref_t = s::remove_const_t< s::remove_reference_t<_Tp> >;
    
	/// Vector component type equals scalar type
	template <typename _Cmp, typename _Sclr>
	struct eq : s::is_same< rem_const_ref_t<_Cmp> , rem_const_ref_t<_Sclr> > {};

	#include "../compiler/push"
	#include "../compiler/ignore_warning/ignored_attributes"
	template <typename _Tp>
	struct is_simd : eq<_Tp, __m128> {}; //this is still fuzzy
	#include "../compiler/pop"

	template <typename _Tp, typename _Sclr>
	struct is_m128f : true_false_t_if<is_simd<_Tp>::value &&  eq<_Sclr, float>::value> {};

	template<typename _Tp, s::size_t _Size>
	avl_inl constexpr auto dim(_Tp(&)[_Size]) noexcept -> s::size_t
	{
		return _Size;
	}

	template<typename _Tp>
	avl_inl constexpr auto dim(_Tp vec) noexcept -> s::size_t
	{
		return decltype(vec)::dim;
	}

	template<>
	avl_inl constexpr auto dim(__m128) noexcept -> s::size_t
	{
		return 4;
	}

	/// @}

	/// @}
	/// \defgroup Concepts
	/// @{

	/// Concept for scalar types
	template <typename _Tp>
	concept bool sc = is_sc<_Tp>::value;

	/// Concept for wrapped foreign or wrapped vectors.
	/// There needs to be a static member 'dim' of size_t, a type cmp_t for the vectors component type
	/// and the components need to be accessible via the operator[] (const & non-const).
	template <typename _Tp>
	concept bool wrapped_v = requires(_Tp v)
	{
		{ _Tp::dim } -> s::size_t;
		{ v[0] } -> typename _Tp::cmp_t;
		{ v[0] = v[1] }
	};

	/// Concept for vectors (no specific dimension requirement)
	template <typename _Tp>
	concept bool v = 	
		( is_eu_vec<_Tp>::value && s::extent<_Tp>::value>1) || //for plain arrays
		( wrapped_v<_Tp> && _Tp::dim>1) || //for anything wrapped
		is_simd<_Tp>::value;

	/// Concept for a 2D vector
	template <typename _Tp>
	concept bool v2 = 
		(is_eu_vec<_Tp>::value && s::extent<_Tp>::value==2) || //for plain arrays
		( wrapped_v<_Tp> && _Tp::dim==2 ); //for anything wrapped

	/// Concept for a 3D vector
	template <typename _Tp>
	concept bool v3 = 
		(is_eu_vec<_Tp>::value && s::extent<_Tp>::value==3) || //for plain arrays
		( wrapped_v<_Tp> && _Tp::dim==3 ); //for anything wrapped


	/// Concept for a 4D vector
	template <typename _Tp>
	concept bool v4 =
		(is_eu_vec<_Tp>::value && s::extent<_Tp>::value==4) || //for plain arrays
		( wrapped_v<_Tp> && _Tp::dim==4 ) || //for anything wrapped
		is_simd<_Tp>::value;

	/// @}
}

#endif // AVL_TRAITS_H