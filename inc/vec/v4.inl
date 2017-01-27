
#ifndef AVL_V4_INL
#define AVL_V4_INL

#pragma once

/// avl: A Vector Library
/// \author Thomas Pollak
namespace avl
{

	/// \defgroup Vector length operations
	/// \{
	
	/// Returns a new vector with the requested length
	template <int _Dim=4> avl_ainl_res constexpr auto setlen_mk(const v4& vec, const sc len_to_set) noexcept(ndebug||exuse)
	{
		static_assert(_Dim>=-4 && _dim!=0 && _Dim<=4 , "Provide a valid dimension parameter [4,4], excluding 0 or remove the template parameter");

		if constexpr( N==-1 )
			return rem_const_ref_t< decltype(vec) >	{ get<0>(vec), get<1>(vec), get<2>(vec), len_to_set };
		else if constexpr( N==1 )
			return rem_const_ref_t< decltype(vec) >	{ len_to_set, get<1>(vec), get<2>(vec), get<3>(vec) };

		const auto vec_len = len<_Dim>(vec);
		assert(vec_len!=cnst<decltype(vec_len)>::zero);
		return mul_mk<_Dim>(vec, len_to_set / vec_len);
	}
	
	/// Calculate the square length of the vector
	template <int _Dim=4> avl_ainl_res constexpr auto len_sqr(const v4& vec) noexcept -> decltype(cmp(vec))
	{
		static_assert(_Dim>=-4 && _dim!=0 && _Dim<=4 , "Provide a valid dimension parameter [4,4], excluding 0 or remove the template parameter");

		if constexpr(N==-3)
		    return get<-3>(vec)*get<-3>(vec) + get<-2>(vec)*get<-2>(vec) + get<-1>(vec)*get<-1>(vec);
		else if constexpr(N==-2)
		    return get<-2>(vec)*get<-2>(vec) + get<-1>(vec)*get<-1>(vec);
		else if constexpr(N==-1)
		    return get<-1>(vec)*get<-1>(vec);
		else if constexpr(N==1)
		    return get<0>(vec)*get<0>(vec);
		else if constexpr(N==2)
		    return get<0>(vec)*get<0>(vec) + get<1>(vec)*get<1>(vec);
		else if constexpr(N==3)
		    return get<0>(vec)*get<0>(vec) + get<1>(vec)*get<1>(vec) + get<2>(vec)*get<2>(vec);
		else
		    return get<0>(vec)*get<0>(vec) + get<1>(vec)*get<1>(vec) + get<2>(vec)*get<2>(vec) + get<3>(vec)*get<3>(vec);
	}
	
	/// \}
	/// \defgroup Spacial operations
	/// \{
	
	/// Calculate the area of the spawned triangle (restricted to 3 dimensions)
	avl_inl_res constexpr auto area3(v4 vec, const decltype(vec)& other) noexcept -> decltype(cmp(vec))
	{
		return cnst<decltype(cmp(vec))>::half * len( cross3(vec, other) );
	}
	
	/// Calculate the cross product (restricted to 3 dimensions)
	avl_ainl_res constexpr auto cross3_mk(const v4& vec, const v4& other) noexcept
	{
		return rem_const_ref_t<decltype(vec)> {
				get<1>(vec) * get<2>(other) - get<2>(vec) * get<1>(other),
				get<2>(vec) * get<0>(other) - get<0>(vec) * get<2>(other),
				get<0>(vec) * get<1>(other) - get<1>(vec) * get<0>(other),
				cnst<decltype(cmp(vec))>::zero
			};
	}
	
	/// Calculate the cross product (restricted to 3 dimensions)
	avl_ainl constexpr auto cross3_set(v4& vec, const v4& other) noexcept -> void
	{
		set_all( vec,
				get<1>(vec) * get<2>(other) - get<2>(vec) * get<1>(other),
				get<2>(vec) * get<0>(other) - get<0>(vec) * get<2>(other),
				get<0>(vec) * get<1>(other) - get<1>(vec) * get<0>(other),
				cnst<decltype(cmp(vec))>::zero
			);
	}
	
	/// Calculate the cross product (restricted to 3 dimensions)
	avl_ainl_res constexpr auto cross3(v4& vec, const v4& other) noexcept -> decltype(vec)
	{
		set_all( vec,
				get<1>(vec) * get<2>(other) - get<2>(vec) * get<1>(other),
				get<2>(vec) * get<0>(other) - get<0>(vec) * get<2>(other),
				get<0>(vec) * get<1>(other) - get<1>(vec) * get<0>(other),
				cnst<decltype(cmp(vec))>::zero
			);
		return vec;
	}
	
	/// \}
	/// \defgroup Getter and setters for 4 component vectors
	/// \{
	
	/// Set all vector components to the same scalar
	avl_ainl constexpr auto set_all(v4& vec, const sc scalar) noexcept -> void
	{
		static_assert(eq<decltype(vec[0]), decltype(scalar)>::value, "Supply a scalar of the vectors element filetype.");
		vec[0] = scalar;
		vec[1] = scalar;
		vec[2] = scalar;
		vec[3] = scalar;
	}
	
	/// Set all vector components individually
	avl_ainl constexpr auto set_all(v4& vec, const sc x, const sc y, const sc z, const sc w) noexcept -> void
	{
		static_assert(eq<decltype(vec[ 0 ]), decltype(x)>::value, "Supply a scalar of the vectors element type for x.");
		static_assert(eq<decltype(vec[ 1 ]), decltype(y)>::value, "Supply a scalar of the vectors element type for y.");
		static_assert(eq<decltype(vec[ 2 ]), decltype(z)>::value, "Supply a scalar of the vectors element type for z.");
		static_assert(eq<decltype(vec[ 3 ]), decltype(w)>::value, "Supply a scalar of the vectors element type for w.");
		vec[0] = x;
		vec[1] = y;
		vec[2] = z;
		vec[3] = w;
	}
	
	/// Set all vector components individually by a fixed size array
	avl_ainl constexpr auto set_all(v4& vec, const sc scalars[ 4 ]) noexcept -> void
	{
		static_assert(eq<decltype(vec[ 0 ]), decltype(scalars[ 0 ])>::value, "Supply a scalar of the vectors element filetype.");
		static_assert(eq<decltype(vec[ 1 ]), decltype(scalars[ 1 ])>::value, "Supply a scalar of the vectors element filetype.");
		static_assert(eq<decltype(vec[ 2 ]), decltype(scalars[ 2 ])>::value, "Supply a scalar of the vectors element filetype.");
		static_assert(eq<decltype(vec[ 3 ]), decltype(scalars[ 3 ])>::value, "Supply a scalar of the vectors element filetype.");
		vec[0] = scalars[0];
		vec[1] = scalars[1];
		vec[2] = scalars[2];
		vec[3] = scalars[3];
	}
	
	/// Set all vector components individually by an array of specified size _Dim
	template <s::size_t _Dim> avl_ainl constexpr auto set_all(v4& vec, const sc* scalars) noexcept -> void
	{
		static_assert(_Dim>=4, "Supply at least 4 scalars.");
		static_assert(eq<decltype(vec[ 0 ]), decltype(scalars[ 0 ])>::value, "Supply a scalar of the vectors element type.");
		static_assert(eq<decltype(vec[ 1 ]), decltype(scalars[ 1 ])>::value, "Supply a scalar of the vectors element type.");
		static_assert(eq<decltype(vec[ 2 ]), decltype(scalars[ 2 ])>::value, "Supply a scalar of the vectors element type.");
		static_assert(eq<decltype(vec[ 3 ]), decltype(scalars[ 3 ])>::value, "Supply a scalar of the vectors element type.");
		vec[0] = scalars[0];
		vec[1] = scalars[1];
		vec[2] = scalars[2];
		vec[3] = scalars[3];
	}
	
	/// \}
	/// \defgroup Base math vector operations for 4 component vectors
	/// \{
	
	// add_mk
	avl_ainl_res constexpr auto add_mk(const v4& vec, const v4& other) noexcept
	{
		return rem_const_ref_t< decltype(vec) >
					{get<0>(vec) + get<0>(other), get<1>(vec) + get<1>(other), get<2>(vec) + get<2>(other), get<3>(vec) + get<3>(other) };
	}
	
	// add_mk (scalar)
	avl_ainl_res constexpr auto add_mk(const v4& vec, const sc scalar) noexcept
	{
		return rem_const_ref_t< decltype(vec) >
					{get<0>(vec) + scalar, get<1>(vec) + scalar, get<2>(vec) + scalar, get<3>(vec) + scalar };
	}
	
	// add_set
	avl_ainl constexpr auto add_set(v4& vec, const v4& other) noexcept -> void
	{
		set_all(vec, get<0>(vec) + get<0>(other), get<1>(vec) + get<1>(other), get<2>(vec) + get<2>(other), get<3>(vec) + get<3>(other) );
	}
	
	// add_set (scalar)
	avl_ainl constexpr auto add_set(v4& vec, const sc scalar) noexcept -> void
	{
		set_all(vec, get<0>(vec) + scalar, get<1>(vec) + scalar, get<2>(vec) + scalar, get<3>(vec) + scalar );
	}
	
	// add
	avl_ainl_res constexpr auto add(v4& vec, const v4& other) noexcept -> decltype(vec)
	{
		set_all(vec, get<0>(vec) + get<0>(other), get<1>(vec) + get<1>(other), get<2>(vec) + get<2>(other), get<3>(vec) + get<3>(other) );
		return vec;
	}
	
	// add (scalar)
	avl_ainl_res constexpr auto add(v4& vec, const sc scalar) noexcept -> decltype(vec)
	{
		set_all(vec, get<0>(vec) + scalar, get<1>(vec) + scalar, get<2>(vec) + scalar, get<3>(vec) + scalar );
		return vec;
	}
	
	// sub_mk
	avl_ainl_res constexpr auto sub_mk(const v4& vec, const v4& other) noexcept
	{
		return rem_const_ref_t< decltype(vec) >
					{get<0>(vec) - get<0>(other), get<1>(vec) - get<1>(other), get<2>(vec) - get<2>(other), get<3>(vec) - get<3>(other) };
	}
	
	// sub_mk (scalar)
	avl_ainl_res constexpr auto sub_mk(const v4& vec, const sc scalar) noexcept
	{
		return rem_const_ref_t< decltype(vec) >
					{get<0>(vec) - scalar, get<1>(vec) - scalar, get<2>(vec) - scalar, get<3>(vec) - scalar };
	}
	
	// sub_set
	avl_ainl constexpr auto sub_set(v4& vec, const v4& other) noexcept -> void
	{
		set_all(vec, get<0>(vec) - get<0>(other), get<1>(vec) - get<1>(other), get<2>(vec) - get<2>(other), get<3>(vec) - get<3>(other) );
	}
	
	// sub_set (scalar)
	avl_ainl constexpr auto sub_set(v4& vec, const sc scalar) noexcept -> void
	{
		set_all(vec, get<0>(vec) - scalar, get<1>(vec) - scalar, get<2>(vec) - scalar, get<3>(vec) - scalar );
	}
	
	// sub
	avl_ainl_res constexpr auto sub(v4& vec, const v4& other) noexcept -> decltype(vec)
	{
		set_all(vec, get<0>(vec) - get<0>(other), get<1>(vec) - get<1>(other), get<2>(vec) - get<2>(other), get<3>(vec) - get<3>(other) );
		return vec;
	}
	
	// sub (scalar)
	avl_ainl_res constexpr auto sub(v4& vec, const sc scalar) noexcept -> decltype(vec)
	{
		set_all(vec, get<0>(vec) - scalar, get<1>(vec) - scalar, get<2>(vec) - scalar, get<3>(vec) - scalar );
		return vec;
	}
	
	// mul_mk
	avl_ainl_res constexpr auto mul_mk(const v4& vec, const v4& other) noexcept
	{
		return rem_const_ref_t< decltype(vec) >
					{get<0>(vec) * get<0>(other), get<1>(vec) * get<1>(other), get<2>(vec) * get<2>(other), get<3>(vec) * get<3>(other) };
	}
	
	// mul_mk (scalar)
	avl_ainl_res constexpr auto mul_mk(const v4& vec, const sc scalar) noexcept
	{
		return rem_const_ref_t< decltype(vec) >
					{get<0>(vec) * scalar, get<1>(vec) * scalar, get<2>(vec) * scalar, get<3>(vec) * scalar };
	}
	
	// mul_set
	avl_ainl constexpr auto mul_set(v4& vec, const v4& other) noexcept -> void
	{
		set_all(vec, get<0>(vec) * get<0>(other), get<1>(vec) * get<1>(other), get<2>(vec) * get<2>(other), get<3>(vec) * get<3>(other) );
	}
	
	// mul_set (scalar)
	avl_ainl constexpr auto mul_set(v4& vec, const sc scalar) noexcept -> void
	{
		set_all(vec, get<0>(vec) * scalar, get<1>(vec) * scalar, get<2>(vec) * scalar, get<3>(vec) * scalar );
	}
	
	// mul
	avl_ainl_res constexpr auto mul(v4& vec, const v4& other) noexcept -> decltype(vec)
	{
		set_all(vec, get<0>(vec) * get<0>(other), get<1>(vec) * get<1>(other), get<2>(vec) * get<2>(other), get<3>(vec) * get<3>(other) );
		return vec;
	}
	
	// mul (scalar)
	avl_ainl_res constexpr auto mul(v4& vec, const sc scalar) noexcept -> decltype(vec)
	{
		set_all(vec, get<0>(vec) * scalar, get<1>(vec) * scalar, get<2>(vec) * scalar, get<3>(vec) * scalar );
		return vec;
	}
	
	// div_mk
	avl_ainl_res constexpr auto div_mk(const v4& vec, const v4& other) noexcept(ndebug||exuse)
	{
		assert(get<0>(other)!=cnst<decltype(cmp(other))>::zero);
		assert(get<1>(other)!=cnst<decltype(cmp(other))>::zero);
		assert(get<2>(other)!=cnst<decltype(cmp(other))>::zero);
		assert(get<3>(other)!=cnst<decltype(cmp(other))>::zero);
		return rem_const_ref_t< decltype(vec) >
					{get<0>(vec) / get<0>(other), get<1>(vec) / get<1>(other), get<2>(vec) / get<2>(other), get<3>(vec) / get<3>(other) };
	}
	
	// div_mk (scalar)
	avl_ainl_res constexpr auto div_mk(const v4& vec, const sc scalar) noexcept(ndebug||exuse)
	{
		assert(scalar!=cnst<decltype(scalar)>::zero);
		return rem_const_ref_t< decltype(vec) >
					{get<0>(vec) / scalar, get<1>(vec) / scalar, get<2>(vec) / scalar, get<3>(vec) / scalar };
	}
	
	// div_set
	avl_ainl constexpr auto div_set(v4& vec, const v4& other) noexcept(ndebug||exuse) -> void
	{
		assert(get<0>(other)!=cnst<decltype(cmp(other))>::zero);
		assert(get<1>(other)!=cnst<decltype(cmp(other))>::zero);
		assert(get<2>(other)!=cnst<decltype(cmp(other))>::zero);
		assert(get<3>(other)!=cnst<decltype(cmp(other))>::zero);
		set_all(vec, get<0>(vec) / get<0>(other), get<1>(vec) / get<1>(other), get<2>(vec) / get<2>(other), get<3>(vec) / get<3>(other) );
	}
	
	// div_set (scalar)
	avl_ainl constexpr auto div_set(v4& vec, const sc scalar) noexcept(ndebug||exuse) -> void
	{
		assert(scalar!=cnst<decltype(scalar)>::zero);
		set_all(vec, get<0>(vec) / scalar, get<1>(vec) / scalar, get<2>(vec) / scalar, get<3>(vec) / scalar );
	}
	
	// div
	avl_ainl_res constexpr auto div(v4& vec, const v4& other) noexcept(ndebug||exuse) -> decltype(vec)
	{
		assert(get<0>(other)!=cnst<decltype(cmp(other))>::zero);
		assert(get<1>(other)!=cnst<decltype(cmp(other))>::zero);
		assert(get<2>(other)!=cnst<decltype(cmp(other))>::zero);
		assert(get<3>(other)!=cnst<decltype(cmp(other))>::zero);
		set_all(vec, get<0>(vec) / get<0>(other), get<1>(vec) / get<1>(other), get<2>(vec) / get<2>(other), get<3>(vec) / get<3>(other) );
		return vec;
	}
	
	// div (scalar)
	avl_ainl_res constexpr auto div(v4& vec, const sc scalar) noexcept(ndebug||exuse) -> decltype(vec)
	{
		assert(scalar!=cnst<decltype(scalar)>::zero);
		set_all(vec, get<0>(vec) / scalar, get<1>(vec) / scalar, get<2>(vec) / scalar, get<3>(vec) / scalar );
		return vec;
	}
	
	/// \}
	/// \defgroup General purpos functions for 4 component vectors
	/// \{
	
	/// Dot product
	avl_ainl constexpr auto dot(const v4& vec, decltype(vec)& other) noexcept -> decltype(cmp(vec))
	{
		return get<0>(vec) * get<0>(other) + get<1>(vec) * get<1>(other) + get<2>(vec) * get<2>(other) + get<3>(vec) * get<3>(other);
	}
	
	/// \}
}
#endif // AVL_V4_INL