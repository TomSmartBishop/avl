// NOTICE: This file is generated using the template file v.jinja
#ifndef AVL_V3_INL
#define AVL_V3_INL

#pragma once

/// avl: A Vector Library
/// \author Thomas Pollak
namespace avl
{

	/// \defgroup Vector length operations
	/// \{
	
	/// Returns a new vector with the requested length
	template <int DIM_N=3> avl_ainl_res constexpr auto setlen_mk(const v3& vec, const sc len_to_set) noexcept(ndebug||exuse)
	{
		static_assert((DIM_N>=-3 && DIM_N<=-2) || (DIM_N>=2 && DIM_N<=3) , "Provide a valid dimension parameter [3,3], excluding [-1,1] or remove the template parameter");
		const auto vec_len = len<DIM_N>(vec);
		assert(vec_len!=cnst<decltype(vec_len)>::zero);
		return mul_mk<DIM_N>(vec, len_to_set / vec_len);
	}
	
	/// Set the length of the vector
	template <int DIM_N=3> avl_ainl constexpr auto setlen_set(v3& vec, const sc len_to_set) noexcept(ndebug||exuse) -> void
	{
		static_assert((DIM_N>=-3 && DIM_N<=-2) || (DIM_N>=2 && DIM_N<=3) , "Provide a valid dimension parameter [3,3], excluding [-1,1] or remove the template parameter");
		const auto vec_len = len<DIM_N>(vec);
		assert(vec_len!=cnst<decltype(vec_len)>::zero);
		mul_set<DIM_N>(vec, len_to_set / vec_len);

	}
	
	/// Set the length of the vector and return the same vector (chained)
	template <int DIM_N=3> avl_ainl_res constexpr auto setlen(v3& vec, const sc len_to_set) noexcept(ndebug||exuse) -> decltype(vec)
	{
		static_assert((DIM_N>=-3 && DIM_N<=-2) || (DIM_N>=2 && DIM_N<=3) , "Provide a valid dimension parameter [3,3], excluding [-1,1] or remove the template parameter");
		const auto vec_len = len<DIM_N>(vec);
		assert(vec_len!=cnst<decltype(vec_len)>::zero);
		mul_set<DIM_N>(vec, len_to_set / vec_len);

		return vec;
	}
	
	/// Calculate the length of the vector, prefere len_sqr when comparing distances
	template <int DIM_N=3> avl_ainl_res constexpr auto len(const v3& vec) noexcept -> decltype(cmp(vec))
	{
		static_assert((DIM_N>=-3 && DIM_N<=-2) || (DIM_N>=2 && DIM_N<=3) , "Provide a valid dimension parameter [3,3], excluding [-1,1] or remove the template parameter");
		//len_sqr will never return any negativ values so we can gurantee noexcept
		const auto vec_square_len = len_sqr<DIM_N>(vec);
		return static_cast<decltype(cmp(vec))>( s::sqrt( vec_square_len ) );
	}
	
	/// Calculate the square length of the vector
	template <int DIM_N=3> avl_ainl_res constexpr auto len_sqr(const v3& vec) noexcept -> decltype(cmp(vec))
	{
		static_assert((DIM_N>=-3 && DIM_N<=-2) || (DIM_N>=2 && DIM_N<=3) , "Provide a valid dimension parameter [3,3], excluding [-1,1] or remove the template parameter");
		if constexpr(DIM_N==-2)
		   return get<1>(vec)*get<1>(vec) + get<2>(vec)*get<2>(vec);
		else if constexpr(DIM_N==2)
		   return get<0>(vec)*get<0>(vec) + get<1>(vec)*get<1>(vec);
		else
		   return get<0>(vec)*get<0>(vec) + get<1>(vec)*get<1>(vec) + get<2>(vec)*get<2>(vec);
	}
	
	/// Returns a normalized vector
	template <int DIM_N=3> avl_ainl_res constexpr auto norm_mk(const v3& vec ) noexcept(ndebug||exuse)
	{
		static_assert((DIM_N>=-3 && DIM_N<=-2) || (DIM_N>=2 && DIM_N<=3) , "Provide a valid dimension parameter [3,3], excluding [-1,1] or remove the template parameter");
		const auto vec_len = len<DIM_N>(vec);
		return div_mk<DIM_N>(vec, vec_len); //div might assert in debug
	}
	
	/// Returns a normalized vector, use alternative vector if the current vector length is 0
	template <int DIM_N=3> avl_ainl_res constexpr auto norm_mk(const v3& vec , const v3& vec_if_zero_len) noexcept
	{
		static_assert((DIM_N>=-3 && DIM_N<=-2) || (DIM_N>=2 && DIM_N<=3) , "Provide a valid dimension parameter [3,3], excluding [-1,1] or remove the template parameter");
		const auto vec_len = len<DIM_N>(vec);
		if(vec_len==cnst<decltype(vec_len)>::zero)
			return vec_if_zero_len;
		return div_mk<DIM_N>(vec, vec_len); //div might assert in debug
	}
	
	/// Normalize the current vector
	template <int DIM_N=3> avl_ainl constexpr auto norm_set(v3& vec ) noexcept -> void
	{
		static_assert((DIM_N>=-3 && DIM_N<=-2) || (DIM_N>=2 && DIM_N<=3) , "Provide a valid dimension parameter [3,3], excluding [-1,1] or remove the template parameter");
		const auto vec_len = len<DIM_N>(vec);
		div_set<DIM_N>(vec, vec_len); //div might assert in debug
	}
	
	/// Normalize the current vector, use alternative vector if the current vector length is 0
	template <int DIM_N=3> avl_ainl constexpr auto norm_set(v3& vec , const v3& vec_if_zero_len) noexcept -> void
	{
		static_assert((DIM_N>=-3 && DIM_N<=-2) || (DIM_N>=2 && DIM_N<=3) , "Provide a valid dimension parameter [3,3], excluding [-1,1] or remove the template parameter");
		const auto vec_len = len<DIM_N>(vec);
		if(vec_len==cnst<decltype(vec_len)>::zero)
		{
			vec = vec_if_zero_len;
			return;
		}
		div_set<DIM_N>(vec, vec_len); //div might assert in debug
	}
	
	/// Normalize the current vector and return the same vector (chained)
	template <int DIM_N=3> avl_ainl_res constexpr auto norm(v3& vec ) noexcept -> decltype(vec)
	{
		static_assert((DIM_N>=-3 && DIM_N<=-2) || (DIM_N>=2 && DIM_N<=3) , "Provide a valid dimension parameter [3,3], excluding [-1,1] or remove the template parameter");
		const auto vec_len = len<DIM_N>(vec);
		div_set<DIM_N>(vec, vec_len); //div might assert in debug
		return vec;
	}
	
	/// Normalize the current vector and return the same vector (chained), use alternative vector if the current vector length is 0
	template <int DIM_N=3> avl_ainl_res constexpr auto norm(v3& vec , const v3& vec_if_zero_len) noexcept -> decltype(vec)
	{
		static_assert((DIM_N>=-3 && DIM_N<=-2) || (DIM_N>=2 && DIM_N<=3) , "Provide a valid dimension parameter [3,3], excluding [-1,1] or remove the template parameter");
		const auto vec_len = len<DIM_N>(vec);
		if(vec_len==cnst<decltype(vec_len)>::zero)
		{
			vec = vec_if_zero_len;
			return vec;
		}
		div_set<DIM_N>(vec, vec_len); //div might assert in debug
		return vec;
	}
	
	/// \}
	/// \defgroup Spacial operations
	/// \{
	
	/// Calculate the area of the spawned triangle
	avl_inl_res constexpr auto area(v3 vec, const decltype(vec)& other) noexcept -> decltype(cmp(vec))
	{
		return cnst<decltype(cmp(vec))>::half * len( cross(vec, other) );
	}
	
	/// Calculate the cross product
	avl_ainl_res constexpr auto cross_mk(const v3& vec, const v3& other) noexcept
	{
		return rem_const_ref_t<decltype(vec)> {
				get<1>(vec) * get<2>(other) - get<2>(vec) * get<1>(other),
				get<2>(vec) * get<0>(other) - get<0>(vec) * get<2>(other),
				get<0>(vec) * get<1>(other) - get<1>(vec) * get<0>(other)			};
	}
	
	/// Calculate the cross product
	avl_ainl constexpr auto cross_set(v3& vec, const v3& other) noexcept -> void
	{
		set_all( vec,
				get<1>(vec) * get<2>(other) - get<2>(vec) * get<1>(other),
				get<2>(vec) * get<0>(other) - get<0>(vec) * get<2>(other),
				get<0>(vec) * get<1>(other) - get<1>(vec) * get<0>(other)			);
	}
	
	/// Calculate the cross product
	avl_ainl_res constexpr auto cross(v3& vec, const v3& other) noexcept -> decltype(vec)
	{
		set_all( vec,
				get<1>(vec) * get<2>(other) - get<2>(vec) * get<1>(other),
				get<2>(vec) * get<0>(other) - get<0>(vec) * get<2>(other),
				get<0>(vec) * get<1>(other) - get<1>(vec) * get<0>(other)			);
		return vec;
	}
	
	/// \}
	/// \defgroup Getter and setters for 3 component vectors
	/// \{
	
	/// Set all vector components to the same scalar
	template <int DIM_N=3> avl_ainl constexpr auto set_all(v3& vec, const sc scalar) noexcept -> void
	{
		static_assert((DIM_N>=-3 && DIM_N<=-2) || (DIM_N>=2 && DIM_N<=3) , "Provide a valid dimension parameter [3,3], excluding [-1,1] or remove the template parameter");
		static_assert(eq<decltype(vec[0]), decltype(scalar)>::value, "Supply a scalar of the vectors element filetype.");

		if constexpr(DIM_N==-2)
		   { vec[1] = scalar; vec[2] = scalar; }
		else if constexpr(DIM_N==2)
		   { vec[0] = scalar; vec[1] = scalar; }
		else
		   { vec[0] = scalar; vec[1] = scalar; vec[2] = scalar; }
	}
	
	/// Set all vector components individually
	template <int DIM_N=3> avl_ainl constexpr auto set_all(v3& vec, const sc x, const sc y, const sc z) noexcept -> void
	{
		static_assert((DIM_N>=-3 && DIM_N<=-2) || (DIM_N>=2 && DIM_N<=3) , "Provide a valid dimension parameter [3,3], excluding [-1,1] or remove the template parameter");
		static_assert(eq<decltype(vec[ 0 ]), decltype(x)>::value, "Supply a scalar of the vectors element type for x.");
		static_assert(eq<decltype(vec[ 1 ]), decltype(y)>::value, "Supply a scalar of the vectors element type for y.");
		static_assert(eq<decltype(vec[ 2 ]), decltype(z)>::value, "Supply a scalar of the vectors element type for z.");
   		if constexpr(DIM_N==-2)
		   { vec[1] = y; vec[2] = z; }
		else if constexpr(DIM_N==2)
		   { vec[0] = x; vec[1] = y; }
		else
		   { vec[0] = x; vec[1] = y; vec[2] = z; }
	}
	
	/// Set all vector components individually by a fixed size array
	template <int DIM_N=3> avl_ainl constexpr auto set_all(v3& vec, const sc scalars[ 3 ]) noexcept -> void
	{
		static_assert((DIM_N>=-3 && DIM_N<=-2) || (DIM_N>=2 && DIM_N<=3) , "Provide a valid dimension parameter [3,3], excluding [-1,1] or remove the template parameter");
		static_assert(eq<decltype(vec[ 0 ]), decltype(scalars[ 0 ])>::value, "Supply a scalar of the vectors element filetype.");
		static_assert(eq<decltype(vec[ 1 ]), decltype(scalars[ 1 ])>::value, "Supply a scalar of the vectors element filetype.");
		static_assert(eq<decltype(vec[ 2 ]), decltype(scalars[ 2 ])>::value, "Supply a scalar of the vectors element filetype.");
		if constexpr(DIM_N==-2)
		   { vec[1] = scalars[1]; vec[2] = scalars[2]; }
		else if constexpr(DIM_N==2)
		   { vec[0] = scalars[0]; vec[1] = scalars[1]; }
		else
		   { vec[0] = scalars[0]; vec[1] = scalars[1]; vec[2] = scalars[2]; }
	}
	
	/// \}
	/// \defgroup Base math vector operations for 3 component vectors
	/// \{
	
	// add_mk
	template <int DIM_N=3> avl_ainl_res constexpr auto add_mk(const v3& vec, const v3& other) noexcept
	{
		if constexpr(DIM_N==-2)
		   return rem_const_ref_t< decltype(vec) >{cnst<decltype(cmp(other))>::zero, get<1>(vec) + get<1>(other), get<2>(vec) + get<2>(other)};
		else if constexpr(DIM_N==2)
		   return rem_const_ref_t< decltype(vec) >{get<0>(vec) + get<0>(other), get<1>(vec) + get<1>(other), cnst<decltype(cmp(other))>::zero};
		else
		   return rem_const_ref_t< decltype(vec) >{get<0>(vec) + get<0>(other), get<1>(vec) + get<1>(other), get<2>(vec) + get<2>(other)};
	}
	
	// add_mk (scalar)
	template <int DIM_N=3> avl_ainl_res constexpr auto add_mk(const v3& vec, const sc scalar) noexcept
	{
		if constexpr(DIM_N==-2)
		   return rem_const_ref_t< decltype(vec) >{cnst<decltype(scalar)>::zero, get<1>(vec) + scalar, get<2>(vec) + scalar};
		else if constexpr(DIM_N==2)
		   return rem_const_ref_t< decltype(vec) >{get<0>(vec) + scalar, get<1>(vec) + scalar, cnst<decltype(scalar)>::zero};
		else
		   return rem_const_ref_t< decltype(vec) >{get<0>(vec) + scalar, get<1>(vec) + scalar, get<2>(vec) + scalar};
	}
	
	// add_set
	template <int DIM_N=3> avl_ainl constexpr auto add_set(v3& vec, const v3& other) noexcept -> void
	{
		if constexpr(DIM_N==-2)
		   set_all<3>(vec, get<1>(vec) + get<1>(other), get<2>(vec) + get<2>(other));
		else if constexpr(DIM_N==2)
		   set_all<3>(vec, get<0>(vec) + get<0>(other), get<1>(vec) + get<1>(other));
		else
		   set_all<3>(vec, get<0>(vec) + get<0>(other), get<1>(vec) + get<1>(other), get<2>(vec) + get<2>(other));
	}
	
	// add_set (scalar)
	template <int DIM_N=3> avl_ainl constexpr auto add_set(v3& vec, const sc scalar) noexcept -> void
	{
		if constexpr(DIM_N==-2)
		   set_all<3>(vec, get<1>(vec) + scalar, get<2>(vec) + scalar);
		else if constexpr(DIM_N==2)
		   set_all<3>(vec, get<0>(vec) + scalar, get<1>(vec) + scalar);
		else
		   set_all<3>(vec, get<0>(vec) + scalar, get<1>(vec) + scalar, get<2>(vec) + scalar);
	}
	
	// add
	template <int DIM_N=3> avl_ainl_res constexpr auto add(v3& vec, const v3& other) noexcept -> decltype(vec)
	{
		if constexpr(DIM_N==-2)
		   set_all<3>(vec, get<1>(vec) + get<1>(other), get<2>(vec) + get<2>(other));
		else if constexpr(DIM_N==2)
		   set_all<3>(vec, get<0>(vec) + get<0>(other), get<1>(vec) + get<1>(other));
		else
		   set_all<3>(vec, get<0>(vec) + get<0>(other), get<1>(vec) + get<1>(other), get<2>(vec) + get<2>(other));
		return vec;
	}
	
	// add (scalar)
	template <int DIM_N=3> avl_ainl_res constexpr auto add(v3& vec, const sc scalar) noexcept -> decltype(vec)
	{
		if constexpr(DIM_N==-2)
		   set_all<3>(vec, get<1>(vec) + scalar, get<2>(vec) + scalar);
		else if constexpr(DIM_N==2)
		   set_all<3>(vec, get<0>(vec) + scalar, get<1>(vec) + scalar);
		else
		   set_all<3>(vec, get<0>(vec) + scalar, get<1>(vec) + scalar, get<2>(vec) + scalar);
		return vec;
	}
	
	// sub_mk
	template <int DIM_N=3> avl_ainl_res constexpr auto sub_mk(const v3& vec, const v3& other) noexcept
	{
		if constexpr(DIM_N==-2)
		   return rem_const_ref_t< decltype(vec) >{cnst<decltype(cmp(other))>::zero, get<1>(vec) - get<1>(other), get<2>(vec) - get<2>(other)};
		else if constexpr(DIM_N==2)
		   return rem_const_ref_t< decltype(vec) >{get<0>(vec) - get<0>(other), get<1>(vec) - get<1>(other), cnst<decltype(cmp(other))>::zero};
		else
		   return rem_const_ref_t< decltype(vec) >{get<0>(vec) - get<0>(other), get<1>(vec) - get<1>(other), get<2>(vec) - get<2>(other)};
	}
	
	// sub_mk (scalar)
	template <int DIM_N=3> avl_ainl_res constexpr auto sub_mk(const v3& vec, const sc scalar) noexcept
	{
		if constexpr(DIM_N==-2)
		   return rem_const_ref_t< decltype(vec) >{cnst<decltype(scalar)>::zero, get<1>(vec) - scalar, get<2>(vec) - scalar};
		else if constexpr(DIM_N==2)
		   return rem_const_ref_t< decltype(vec) >{get<0>(vec) - scalar, get<1>(vec) - scalar, cnst<decltype(scalar)>::zero};
		else
		   return rem_const_ref_t< decltype(vec) >{get<0>(vec) - scalar, get<1>(vec) - scalar, get<2>(vec) - scalar};
	}
	
	// sub_set
	template <int DIM_N=3> avl_ainl constexpr auto sub_set(v3& vec, const v3& other) noexcept -> void
	{
		if constexpr(DIM_N==-2)
		   set_all<3>(vec, get<1>(vec) - get<1>(other), get<2>(vec) - get<2>(other));
		else if constexpr(DIM_N==2)
		   set_all<3>(vec, get<0>(vec) - get<0>(other), get<1>(vec) - get<1>(other));
		else
		   set_all<3>(vec, get<0>(vec) - get<0>(other), get<1>(vec) - get<1>(other), get<2>(vec) - get<2>(other));
	}
	
	// sub_set (scalar)
	template <int DIM_N=3> avl_ainl constexpr auto sub_set(v3& vec, const sc scalar) noexcept -> void
	{
		if constexpr(DIM_N==-2)
		   set_all<3>(vec, get<1>(vec) - scalar, get<2>(vec) - scalar);
		else if constexpr(DIM_N==2)
		   set_all<3>(vec, get<0>(vec) - scalar, get<1>(vec) - scalar);
		else
		   set_all<3>(vec, get<0>(vec) - scalar, get<1>(vec) - scalar, get<2>(vec) - scalar);
	}
	
	// sub
	template <int DIM_N=3> avl_ainl_res constexpr auto sub(v3& vec, const v3& other) noexcept -> decltype(vec)
	{
		if constexpr(DIM_N==-2)
		   set_all<3>(vec, get<1>(vec) - get<1>(other), get<2>(vec) - get<2>(other));
		else if constexpr(DIM_N==2)
		   set_all<3>(vec, get<0>(vec) - get<0>(other), get<1>(vec) - get<1>(other));
		else
		   set_all<3>(vec, get<0>(vec) - get<0>(other), get<1>(vec) - get<1>(other), get<2>(vec) - get<2>(other));
		return vec;
	}
	
	// sub (scalar)
	template <int DIM_N=3> avl_ainl_res constexpr auto sub(v3& vec, const sc scalar) noexcept -> decltype(vec)
	{
		if constexpr(DIM_N==-2)
		   set_all<3>(vec, get<1>(vec) - scalar, get<2>(vec) - scalar);
		else if constexpr(DIM_N==2)
		   set_all<3>(vec, get<0>(vec) - scalar, get<1>(vec) - scalar);
		else
		   set_all<3>(vec, get<0>(vec) - scalar, get<1>(vec) - scalar, get<2>(vec) - scalar);
		return vec;
	}
	
	// mul_mk
	template <int DIM_N=3> avl_ainl_res constexpr auto mul_mk(const v3& vec, const v3& other) noexcept
	{
		if constexpr(DIM_N==-2)
		   return rem_const_ref_t< decltype(vec) >{cnst<decltype(cmp(other))>::zero, get<1>(vec) * get<1>(other), get<2>(vec) * get<2>(other)};
		else if constexpr(DIM_N==2)
		   return rem_const_ref_t< decltype(vec) >{get<0>(vec) * get<0>(other), get<1>(vec) * get<1>(other), cnst<decltype(cmp(other))>::zero};
		else
		   return rem_const_ref_t< decltype(vec) >{get<0>(vec) * get<0>(other), get<1>(vec) * get<1>(other), get<2>(vec) * get<2>(other)};
	}
	
	// mul_mk (scalar)
	template <int DIM_N=3> avl_ainl_res constexpr auto mul_mk(const v3& vec, const sc scalar) noexcept
	{
		if constexpr(DIM_N==-2)
		   return rem_const_ref_t< decltype(vec) >{cnst<decltype(scalar)>::zero, get<1>(vec) * scalar, get<2>(vec) * scalar};
		else if constexpr(DIM_N==2)
		   return rem_const_ref_t< decltype(vec) >{get<0>(vec) * scalar, get<1>(vec) * scalar, cnst<decltype(scalar)>::zero};
		else
		   return rem_const_ref_t< decltype(vec) >{get<0>(vec) * scalar, get<1>(vec) * scalar, get<2>(vec) * scalar};
	}
	
	// mul_set
	template <int DIM_N=3> avl_ainl constexpr auto mul_set(v3& vec, const v3& other) noexcept -> void
	{
		if constexpr(DIM_N==-2)
		   set_all<3>(vec, get<1>(vec) * get<1>(other), get<2>(vec) * get<2>(other));
		else if constexpr(DIM_N==2)
		   set_all<3>(vec, get<0>(vec) * get<0>(other), get<1>(vec) * get<1>(other));
		else
		   set_all<3>(vec, get<0>(vec) * get<0>(other), get<1>(vec) * get<1>(other), get<2>(vec) * get<2>(other));
	}
	
	// mul_set (scalar)
	template <int DIM_N=3> avl_ainl constexpr auto mul_set(v3& vec, const sc scalar) noexcept -> void
	{
		if constexpr(DIM_N==-2)
		   set_all<3>(vec, get<1>(vec) * scalar, get<2>(vec) * scalar);
		else if constexpr(DIM_N==2)
		   set_all<3>(vec, get<0>(vec) * scalar, get<1>(vec) * scalar);
		else
		   set_all<3>(vec, get<0>(vec) * scalar, get<1>(vec) * scalar, get<2>(vec) * scalar);
	}
	
	// mul
	template <int DIM_N=3> avl_ainl_res constexpr auto mul(v3& vec, const v3& other) noexcept -> decltype(vec)
	{
		if constexpr(DIM_N==-2)
		   set_all<3>(vec, get<1>(vec) * get<1>(other), get<2>(vec) * get<2>(other));
		else if constexpr(DIM_N==2)
		   set_all<3>(vec, get<0>(vec) * get<0>(other), get<1>(vec) * get<1>(other));
		else
		   set_all<3>(vec, get<0>(vec) * get<0>(other), get<1>(vec) * get<1>(other), get<2>(vec) * get<2>(other));
		return vec;
	}
	
	// mul (scalar)
	template <int DIM_N=3> avl_ainl_res constexpr auto mul(v3& vec, const sc scalar) noexcept -> decltype(vec)
	{
		if constexpr(DIM_N==-2)
		   set_all<3>(vec, get<1>(vec) * scalar, get<2>(vec) * scalar);
		else if constexpr(DIM_N==2)
		   set_all<3>(vec, get<0>(vec) * scalar, get<1>(vec) * scalar);
		else
		   set_all<3>(vec, get<0>(vec) * scalar, get<1>(vec) * scalar, get<2>(vec) * scalar);
		return vec;
	}
	
	// div_mk
	template <int DIM_N=3> avl_ainl_res constexpr auto div_mk(const v3& vec, const v3& other) noexcept(ndebug||exuse)
	{
		assert(get<0>(other)!=cnst<decltype(cmp(other))>::zero);
		assert(get<1>(other)!=cnst<decltype(cmp(other))>::zero);
		assert(get<2>(other)!=cnst<decltype(cmp(other))>::zero);
		if constexpr(DIM_N==-2)
		   return rem_const_ref_t< decltype(vec) >{cnst<decltype(cmp(other))>::zero, get<1>(vec) / get<1>(other), get<2>(vec) / get<2>(other)};
		else if constexpr(DIM_N==2)
		   return rem_const_ref_t< decltype(vec) >{get<0>(vec) / get<0>(other), get<1>(vec) / get<1>(other), cnst<decltype(cmp(other))>::zero};
		else
		   return rem_const_ref_t< decltype(vec) >{get<0>(vec) / get<0>(other), get<1>(vec) / get<1>(other), get<2>(vec) / get<2>(other)};
	}
	
	// div_mk (scalar)
	template <int DIM_N=3> avl_ainl_res constexpr auto div_mk(const v3& vec, const sc scalar) noexcept(ndebug||exuse)
	{
		assert(scalar!=cnst<decltype(scalar)>::zero);
		if constexpr(DIM_N==-2)
		   return rem_const_ref_t< decltype(vec) >{cnst<decltype(scalar)>::zero, get<1>(vec) / scalar, get<2>(vec) / scalar};
		else if constexpr(DIM_N==2)
		   return rem_const_ref_t< decltype(vec) >{get<0>(vec) / scalar, get<1>(vec) / scalar, cnst<decltype(scalar)>::zero};
		else
		   return rem_const_ref_t< decltype(vec) >{get<0>(vec) / scalar, get<1>(vec) / scalar, get<2>(vec) / scalar};
	}
	
	// div_set
	template <int DIM_N=3> avl_ainl constexpr auto div_set(v3& vec, const v3& other) noexcept(ndebug||exuse) -> void
	{
		assert(get<0>(other)!=cnst<decltype(cmp(other))>::zero);
		assert(get<1>(other)!=cnst<decltype(cmp(other))>::zero);
		assert(get<2>(other)!=cnst<decltype(cmp(other))>::zero);
		if constexpr(DIM_N==-2)
		   set_all<3>(vec, get<1>(vec) / get<1>(other), get<2>(vec) / get<2>(other));
		else if constexpr(DIM_N==2)
		   set_all<3>(vec, get<0>(vec) / get<0>(other), get<1>(vec) / get<1>(other));
		else
		   set_all<3>(vec, get<0>(vec) / get<0>(other), get<1>(vec) / get<1>(other), get<2>(vec) / get<2>(other));
	}
	
	// div_set (scalar)
	template <int DIM_N=3> avl_ainl constexpr auto div_set(v3& vec, const sc scalar) noexcept(ndebug||exuse) -> void
	{
		assert(scalar!=cnst<decltype(scalar)>::zero);
		if constexpr(DIM_N==-2)
		   set_all<3>(vec, get<1>(vec) / scalar, get<2>(vec) / scalar);
		else if constexpr(DIM_N==2)
		   set_all<3>(vec, get<0>(vec) / scalar, get<1>(vec) / scalar);
		else
		   set_all<3>(vec, get<0>(vec) / scalar, get<1>(vec) / scalar, get<2>(vec) / scalar);
	}
	
	// div
	template <int DIM_N=3> avl_ainl_res constexpr auto div(v3& vec, const v3& other) noexcept(ndebug||exuse) -> decltype(vec)
	{
		assert(get<0>(other)!=cnst<decltype(cmp(other))>::zero);
		assert(get<1>(other)!=cnst<decltype(cmp(other))>::zero);
		assert(get<2>(other)!=cnst<decltype(cmp(other))>::zero);
		if constexpr(DIM_N==-2)
		   set_all<3>(vec, get<1>(vec) / get<1>(other), get<2>(vec) / get<2>(other));
		else if constexpr(DIM_N==2)
		   set_all<3>(vec, get<0>(vec) / get<0>(other), get<1>(vec) / get<1>(other));
		else
		   set_all<3>(vec, get<0>(vec) / get<0>(other), get<1>(vec) / get<1>(other), get<2>(vec) / get<2>(other));
		return vec;
	}
	
	// div (scalar)
	template <int DIM_N=3> avl_ainl_res constexpr auto div(v3& vec, const sc scalar) noexcept(ndebug||exuse) -> decltype(vec)
	{
		assert(scalar!=cnst<decltype(scalar)>::zero);
		if constexpr(DIM_N==-2)
		   set_all<3>(vec, get<1>(vec) / scalar, get<2>(vec) / scalar);
		else if constexpr(DIM_N==2)
		   set_all<3>(vec, get<0>(vec) / scalar, get<1>(vec) / scalar);
		else
		   set_all<3>(vec, get<0>(vec) / scalar, get<1>(vec) / scalar, get<2>(vec) / scalar);
		return vec;
	}
	
	/// \}
	/// \defgroup General purpos functions for 3 component vectors
	/// \{
	
	/// Dot product
	template <int DIM_N=3> avl_ainl constexpr auto dot(const v3& vec, const v3& other) noexcept -> decltype(cmp(vec))
	{
		static_assert((DIM_N>=-3 && DIM_N<=-2) || (DIM_N>=2 && DIM_N<=3), "Provide a valid dimension parameter [3,3], excluding [-1,1] or remove the template parameter");
		if constexpr(DIM_N==-2)
		   return get<1>(vec)*get<1>(other) + get<2>(vec)*get<2>(other);
		else if constexpr(DIM_N==2)
		   return get<0>(vec)*get<0>(other) + get<1>(vec)*get<1>(other);
		else
		   return get<0>(vec)*get<0>(other) + get<1>(vec)*get<1>(other) + get<2>(vec)*get<2>(other);
	}
	
	/// \}
}
#endif // AVL_V3_INL