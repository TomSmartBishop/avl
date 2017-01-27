
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
	
	/// Access the vector components by a range checked index from 0 to dim-1
	avl_ainl_res constexpr auto get(const v& vec, const s::size_t idx) noexcept(ndebug||exuse) -> decltype(cmp(vec))
	{
		assert(idx < dim< rem_const_ref_t< decltype( vec ) > >::value);
		return vec[idx];
	}
	
	/// Access the vector components by a static range checked index from 0 to dim-1
	template<s::size_t _Idx> avl_ainl_res constexpr auto get(const v& vec) noexcept -> decltype(cmp(vec))
	{
		static_assert(_Idx < dim< rem_const_ref_t< decltype( vec ) > >::value, "Index is out of range");
		return vec[_Idx];
	}
	
	/// Set a single component by index from 0 to dim-1
	avl_ainl constexpr auto set(v& vec, const s::size_t idx, const sc scalar) noexcept(ndebug||exuse) -> void
	{
		static_assert(eq< decltype( vec[idx] ), decltype( scalar ) >::value, "Supply a scalar of the vectors element type.");
		assert(idx < dim< rem_const_ref_t< decltype( vec ) > >::value);
		vec[idx] = scalar;
	}
	
	/// Set a single component by static index from 0 to dim-1
	template<s::size_t _Idx> avl_ainl constexpr auto set(v& vec, const sc scalar) noexcept -> void
	{
		static_assert(eq< decltype( vec[_Idx] ), decltype( scalar ) >::value, "Supply a scalar of the vectors element type.");
		static_assert(_Idx < dim< rem_const_ref_t< decltype( vec ) > >::value, "Index is out of range");
		vec[_Idx] = scalar;
	}
	
	/// \}
	/// \defgroup Vector length operations
	/// \{
	
	/// Set the length of the vector
	template <int _Dim=0> avl_ainl constexpr auto setlen_set(v& vec, const sc len_to_set) noexcept(ndebug||exuse) -> void
	{
		static_assert(_Dim>=-0 && _dim!=0 && _Dim<=0 , "Provide a valid dimension parameter [0,0], excluding 0 or remove the template parameter");

		if constexpr( N==-1 || N==1 )
		{
			set<N>(vec, len_to_set);
		}	
		else
		{
			const auto vec_len = len<_Dim>(vec);
			assert(vec_len!=cnst<decltype(vec_len)>::zero);
			mul_set<_Dim>(vec, len_to_set / vec_len);
		}
	}
	
	/// Set the length of the vector and return the same vector (chained)
	template <int _Dim=0> avl_ainl_res constexpr auto setlen(v& vec, const sc len_to_set) noexcept(ndebug||exuse) -> decltype(vec)
	{
		static_assert(_Dim>=-0 && _dim!=0 && _Dim<=0 , "Provide a valid dimension parameter [0,0], excluding 0 or remove the template parameter");

		if constexpr( N==-1 || N==1 )
		{
			set<N>(vec, len_to_set);
		}	
		else
		{
			const auto vec_len = len<_Dim>(vec);
			assert(vec_len!=cnst<decltype(vec_len)>::zero);
			mul_set<_Dim>(vec, len_to_set / vec_len);
		}
		return vec;
	}
	
	/// Calculate the length of the vector, prefere len_sqr when comparing distances
	template <int _Dim=0> avl_ainl_res constexpr auto len(const v& vec) noexcept -> decltype(cmp(vec))
	{
		static_assert(_Dim>=-0 && _dim!=0 && _Dim<=0 , "Provide a valid dimension parameter [0,0], excluding 0 or remove the template parameter");

		if constexpr( N==-1 || N==1 )
			return get<N>( vec );
				
		//len_sqr will never return any negativ values so we can gurantee noexcept
		const auto vec_square_len = len_sqr<_Dim>(vec);
		return static_cast<decltype(cmp(vec))>( s::sqrt( vec_square_len ) );
	}
	
	/// Returns a normalized vector
	template <int _Dim=0> avl_ainl_res constexpr auto norm_mk(const v& vec ) noexcept(ndebug||exuse)
	{
		static_assert(_Dim>=-0 && _dim!=0 && _Dim<=0 , "Provide a valid dimension parameter [0,0], excluding 0 or remove the template parameter");

		const auto vec_len = len<_Dim>(vec);
		return div_mk<_Dim>(vec, vec_len); //div might assert in debug
	}
	
	/// Returns a normalized vector, use alternative vector if the current vector length is 0
	template <int _Dim=0> avl_ainl_res constexpr auto norm_mk(const v& vec , const v& vec_if_zero_len) noexcept
	{
		static_assert(_Dim>=-0 && _dim!=0 && _Dim<=0 , "Provide a valid dimension parameter [0,0], excluding 0 or remove the template parameter");

		const auto vec_len = len<_Dim>(vec);
		if(vec_len==cnst<decltype(vec_len)>::zero)
			return vec_if_zero_len;
		return div_mk<_Dim>(vec, vec_len); //div might assert in debug
	}
	
	/// Normalize the current vector
	template <int _Dim=0> avl_ainl constexpr auto norm_set(v& vec ) noexcept -> void
	{
		static_assert(_Dim>=-0 && _dim!=0 && _Dim<=0 , "Provide a valid dimension parameter [0,0], excluding 0 or remove the template parameter");

		const auto vec_len = len<_Dim>(vec);
		div_set<_Dim>(vec, vec_len); //div might assert in debug
	}
	
	/// Normalize the current vector, use alternative vector if the current vector length is 0
	template <int _Dim=0> avl_ainl constexpr auto norm_set(v& vec , const v& vec_if_zero_len) noexcept -> void
	{
		static_assert(_Dim>=-0 && _dim!=0 && _Dim<=0 , "Provide a valid dimension parameter [0,0], excluding 0 or remove the template parameter");

		const auto vec_len = len<_Dim>(vec);
		if(vec_len==cnst<decltype(vec_len)>::zero)
		{
			vec = vec_if_zero_len;
			return;
		}
		div_set<_Dim>(vec, vec_len); //div might assert in debug
	}
	
	/// Normalize the current vector and return the same vector (chained)
	template <int _Dim=0> avl_ainl_res constexpr auto norm(v& vec ) noexcept -> decltype(vec)
	{
		static_assert(_Dim>=-0 && _dim!=0 && _Dim<=0 , "Provide a valid dimension parameter [0,0], excluding 0 or remove the template parameter");

		const auto vec_len = len<_Dim>(vec);
		div_set<_Dim>(vec, vec_len); //div might assert in debug
		return vec;
	}
	
	/// Normalize the current vector and return the same vector (chained), use alternative vector if the current vector length is 0
	template <int _Dim=0> avl_ainl_res constexpr auto norm(v& vec , const v& vec_if_zero_len) noexcept -> decltype(vec)
	{
		static_assert(_Dim>=-0 && _dim!=0 && _Dim<=0 , "Provide a valid dimension parameter [0,0], excluding 0 or remove the template parameter");

		const auto vec_len = len<_Dim>(vec);
		if(vec_len==cnst<decltype(vec_len)>::zero)
		{
			vec = vec_if_zero_len;
			return vec;
		}
		div_set<_Dim>(vec, vec_len); //div might assert in debug
		return vec;
	}
	
	/// \}
	/// \defgroup Spacial operations
	/// \{
	
	/// Calculate the angle between two vectors in radian
	avl_ainl_res constexpr auto angle_rd(const v& vec, const decltype(vec) other) noexcept -> decltype(cmp(vec))
	{
		const auto vec_len		= len(vec);
		const auto other_len	= len(other);
		const auto dot_prod		= dot(vec, other);
		return s::acos( dot_prod / ( vec_len * other_len ) );
	}
	
	/// Calculate the angle between two vectors in degree
	avl_ainl_res constexpr auto angle_dg(const v& vec, const decltype(vec) other) noexcept -> decltype(cmp(vec))
	{
		const auto vec_len		= len(vec);
		const auto other_len	= len(other);
		const auto dot_prod		= dot(vec, other);
		return s::acos( dot_prod / ( vec_len * other_len ) ) * cnst<decltype(cmp(vec))>::to_deg;
	}
	
	/// Get the direction relative to another point excluding colinear and opposite-but-colinear (faster than get_dir_col)
	avl_ainl_res constexpr auto get_dir(const v& vec, const v& other) noexcept -> dir
	{
		const auto dotProduct = dot(vec, other);
		if( utl::eqls(dotProduct, decltype(dotProduct){0}, cnst<decltype(cmp(vec))>::big_epsln) ) {
			return dir::perpend;
		} else if( dotProduct > decltype(dotProduct){0}) {
			return dir::same;
		} else {
			return dir::opp;
		}
	}

	/// Get the direction relative to another point excluding colinear and opposite-but-colinear (faster than get_dir_col)
	avl_ainl_res constexpr auto get_dir(const v& vec, const v& other, const sc epsilon) noexcept -> dir
	{
		const auto dotProduct = dot(vec, other);
		if( utl::eqls(dotProduct, decltype(dotProduct){0}, epsilon) ) {
			return dir::perpend;
		} else if( dotProduct > decltype(dotProduct){0}) {
			return dir::same;
		} else {
			return dir::opp;
		}
	}

	/// \}
}
#endif // AVL_V_INL