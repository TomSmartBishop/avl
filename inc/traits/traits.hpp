#ifndef AVL_TRAITS_HPP
#define AVL_TRAITS_HPP

#pragma once

/// avl: A Vector Library
/// \author Thomas Pollak

namespace avl {


	//temp vec
	template<typename TYPE, s::size_t DIM_N>
	struct vec {
		static constexpr s::size_t dim = DIM_N;
		using cmp_t = TYPE;
		TYPE val[DIM_N];

		avl_ainl_res auto operator[](const s::size_t idx) const noexcept -> const TYPE
		{
			return val[idx];
		}

		avl_ainl_res auto operator[](const s::size_t idx) noexcept -> TYPE &
		{
			return val[idx];
		}
	};
	
	template<typename TYPE>
	using vec2 = vec<TYPE,2>;

	template<typename TYPE>
	using vec3 = vec<TYPE,3>;

	template<typename TYPE>
	using vec4 = vec<TYPE,4>;
	
	//temp wrapper
	template<typename TYPE, s::size_t DIM_N>
	struct vec_w {
		static constexpr s::size_t dim = DIM_N;
		using cmp_t = TYPE;
		TYPE * val;

		avl_ainl_res auto operator[](const s::size_t idx) const noexcept -> const TYPE
		{
			return val[idx];
		}

		avl_ainl_res auto operator[](const s::size_t idx) noexcept -> TYPE &
		{
			return val[idx];
		}
	};

	template<typename TYPE>
	using vec2_w = vec_w<TYPE,2>;

	template<typename TYPE>
	using vec3_w = vec_w<TYPE,3>;

	template<typename TYPE>
	using vec4_w = vec_w<TYPE,4>;

	/// \defgroup Type Traits
	/// @{

	/// @name Shortcuts
	/// @{

			/// Get the component type of the vector	
//  	template<typename TYPE>
//  	struct cmp_ret { decltype(s::declval<TYPE>()[0]) type; };
	
//  	//template<>
//  	//struct cmp_ret<__m128> { float type; };
	
// 	template<typename TYPE>
// 	using cmp_ret_t = typename cmp_ret<TYPE>::type;
	
	/// Get the component type of the vector (remove extent)
	template<typename TYPE>
	using cmp_t = s::remove_extent_t<TYPE>;

	/// Is scaler
	template<typename TYPE>
	using is_sc = typename s::is_arithmetic<TYPE>;

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

	template<typename TYPE, s::size_t _Size>
	struct is_eu_vec<TYPE[_Size]> : true_t_if< is_sc< cmp_t<TYPE> >::value > {};

	template<typename TYPE>
	struct is_eu_vec<TYPE[]> : true_t_if< is_sc< cmp_t<TYPE> >::value > {};

	/// @}
	/// @name Helpers
	/// @{

    template <typename TYPE>
	using rem_const_ref_t = s::remove_const_t< s::remove_reference_t<TYPE> >;
    
	/// Vector component type equals scalar type
	template <typename COMPONENT, typename SCALAR>
	struct eq : s::is_same< rem_const_ref_t<COMPONENT> , rem_const_ref_t<SCALAR> > {};

	#include "../compiler/push"
	#include "../compiler/ignore_warning/ignored_attributes"
	template <typename TYPE>
	struct is_simd : eq<TYPE, __m128> {}; //this is still fuzzy
	#include "../compiler/pop"

	template <typename TYPE, typename SCALAR>
	struct is_m128f : true_false_t_if<is_simd<TYPE>::value &&  eq<SCALAR, float>::value> {};

// 	template<typename TYPE, s::size_t _Size>
// 	avl_inl constexpr auto dim(TYPE(&)[_Size]) noexcept -> s::size_t
// 	{
// 		return _Size;
// 	}

// 	template<typename TYPE>
// 	avl_inl constexpr auto dim() noexcept -> s::size_t
// 	{
// 		return decltype(vec)::dim;
// 	}

// 	template<>
// 	avl_inl constexpr auto dim(__m128) noexcept -> s::size_t
// 	{
// 		return 4;
// 	}


	
	template<typename T>   // primary template
	struct dim
	{
		static constexpr s::size_t value = T::dim;
	};
	
		template<typename TYPE, s::size_t _Size>   // array
	struct dim<TYPE[_Size]>
	{
		static constexpr s::size_t value = _Size;
	};
	
	#include "../compiler/push"
	#include "../compiler/ignore_warning/ignored_attributes"
	template<>
	struct dim<__m128>
	{
		static constexpr s::size_t value = 4;
	};
	#include "../compiler/pop"
	
// 		template<>
// 	struct dim<__m128&>
// 	{
// 		static constexpr s::size_t value = 4;
// 	};
	
	/// @}

	/// @}
	/// \defgroup Concepts
	/// @{

	/// Concept for scalar types
	template <typename TYPE>
	concept bool sc = is_sc<TYPE>::value;

	/// Concept for wrapped foreign or wrapped vectors.
	/// There needs to be a static member 'dim' of size_t, a type cmp_t for the vectors component type
	/// and the components need to be accessible via the operator[] (const & non-const).
	template <typename TYPE>
	concept bool wrapped_v = requires(TYPE v)
	{
		{ TYPE::dim } -> s::size_t;
		{ v[0] } -> typename TYPE::cmp_t;
		{ v[0] = v[1] }
	};

	/// Concept for vectors (no specific dimension requirement)
	template <typename TYPE>
	concept bool v = 	
		( is_eu_vec<TYPE>::value && s::extent<TYPE>::value>1) || //for plain arrays
		( wrapped_v<TYPE> ) || //for anything wrapped
		is_simd<TYPE>::value;

	/// Concept for a 2D vector
	template <typename TYPE>
	concept bool v2 = 
		(is_eu_vec<TYPE>::value && s::extent<TYPE>::value==2) || //for plain arrays
		( wrapped_v<TYPE> && TYPE::dim==2 ); //for anything wrapped

	/// Concept for a 3D vector
	template <typename TYPE>
	concept bool v3 = 
		(is_eu_vec<TYPE>::value && s::extent<TYPE>::value==3) || //for plain arrays
		( wrapped_v<TYPE> && TYPE::dim==3 ); //for anything wrapped


	/// Concept for a 4D vector
	template <typename TYPE>
	concept bool v4 =
		(is_eu_vec<TYPE>::value && s::extent<TYPE>::value==4) || //for plain arrays
		( wrapped_v<TYPE> && TYPE::dim==4 ) || //for anything wrapped
		is_simd<TYPE>::value;

	/// @}
}

#endif // AVL_TRAITS_HPP