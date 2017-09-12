// NOTICE: This file is generated using the template file v.jinja
#ifndef AVL_V2_INL
#define AVL_V2_INL

#pragma once

/// avl: A Vector Library
/// \author Thomas Pollak
namespace avl
{

	/// \defgroup Vector length operations
	/// \{
	
	/// Returns a new vector with the requested length
	avl_ainl_res constexpr auto setlen_mk(const v2& vec, const sc len_to_set) noexcept(ndebug||exuse)
	{
		const auto vec_len = len(vec);
		assert(vec_len!=cnst<decltype(vec_len)>::zero);
		return mul_mk(vec, len_to_set / vec_len);
	}
	
	/// Set the length of the vector
	avl_ainl constexpr auto setlen_set(v2& vec, const sc len_to_set) noexcept(ndebug||exuse) -> void
	{
		const auto vec_len = len(vec);
		assert(vec_len!=cnst<decltype(vec_len)>::zero);
		mul_set(vec, len_to_set / vec_len);

	}
	
	/// Set the length of the vector and return the same vector (chained)
	avl_ainl_res constexpr auto setlen(v2& vec, const sc len_to_set) noexcept(ndebug||exuse) -> decltype(vec)
	{
		const auto vec_len = len(vec);
		assert(vec_len!=cnst<decltype(vec_len)>::zero);
		mul_set(vec, len_to_set / vec_len);

		return vec;
	}
	
	/// Calculate the length of the vector, prefere len_sqr when comparing distances
	avl_ainl_res constexpr auto len(const v2& vec) noexcept -> decltype(cmp(vec))
	{
		//len_sqr will never return any negativ values so we can gurantee noexcept
		const auto vec_square_len = len_sqr(vec);
		return static_cast<decltype(cmp(vec))>( s::sqrt( vec_square_len ) );
	}
	
	/// Calculate the square length of the vector
	avl_ainl_res constexpr auto len_sqr(const v2& vec) noexcept -> decltype(cmp(vec))
	{
		return get<0>(vec)*get<0>(vec) + get<1>(vec)*get<1>(vec);
	}
	
	/// Returns a normalized vector
	avl_ainl_res constexpr auto norm_mk(const v2& vec ) noexcept(ndebug||exuse)
	{
		const auto vec_len = len(vec);
		return div_mk(vec, vec_len); //div might assert in debug
	}
	
	/// Returns a normalized vector, use alternative vector if the current vector length is 0
	avl_ainl_res constexpr auto norm_mk(const v2& vec , const v2& vec_if_zero_len) noexcept
	{
		const auto vec_len = len(vec);
		if(vec_len==cnst<decltype(vec_len)>::zero)
			return vec_if_zero_len;
		return div_mk(vec, vec_len); //div might assert in debug
	}
	
	/// Normalize the current vector
	avl_ainl constexpr auto norm_set(v2& vec ) noexcept -> void
	{
		const auto vec_len = len(vec);
		div_set(vec, vec_len); //div might assert in debug
	}
	
	/// Normalize the current vector, use alternative vector if the current vector length is 0
	avl_ainl constexpr auto norm_set(v2& vec , const v2& vec_if_zero_len) noexcept -> void
	{
		const auto vec_len = len(vec);
		if(vec_len==cnst<decltype(vec_len)>::zero)
		{
			vec = vec_if_zero_len;
			return;
		}
		div_set(vec, vec_len); //div might assert in debug
	}
	
	/// Normalize the current vector and return the same vector (chained)
	avl_ainl_res constexpr auto norm(v2& vec ) noexcept -> decltype(vec)
	{
		const auto vec_len = len(vec);
		div_set(vec, vec_len); //div might assert in debug
		return vec;
	}
	
	/// Normalize the current vector and return the same vector (chained), use alternative vector if the current vector length is 0
	avl_ainl_res constexpr auto norm(v2& vec , const v2& vec_if_zero_len) noexcept -> decltype(vec)
	{
		const auto vec_len = len(vec);
		if(vec_len==cnst<decltype(vec_len)>::zero)
		{
			vec = vec_if_zero_len;
			return vec;
		}
		div_set(vec, vec_len); //div might assert in debug
		return vec;
	}
	
	/// \}
	/// \defgroup Spacial operations
	/// \{
	
	/// Calculate the area of the spawned triangle
	avl_inl_res constexpr auto area(const v2& vec, const decltype(vec)& other) noexcept -> decltype(cmp(vec))
	{
		using scalar = decltype(cmp(vec));
		const auto area = cnst<scalar>::half*(get<0>(vec) * get<1>(other) - get<1>(vec) * get<0>(other));
		return area < cnst<scalar>::zero
			? -area
			: area;
	}
	
	/// \}
	/// \defgroup Getter and setters for 2 component vectors
	/// \{
	
	/// Set all vector components to the same scalar
	avl_ainl constexpr auto set_all(v2& vec, const sc scalar) noexcept -> void
	{
		static_assert(eq<decltype(vec[0]), decltype(scalar)>::value, "Supply a scalar of the vectors element filetype.");

		{ vec[0] = scalar; vec[1] = scalar; }
	}
	
	/// Set all vector components individually
	avl_ainl constexpr auto set_all(v2& vec, const sc x, const sc y) noexcept -> void
	{
		static_assert(eq<decltype(vec[ 0 ]), decltype(x)>::value, "Supply a scalar of the vectors element type for x.");
		static_assert(eq<decltype(vec[ 1 ]), decltype(y)>::value, "Supply a scalar of the vectors element type for y.");
 		{ vec[0] = x; vec[1] = y; }
	}
	
	/// Set all vector components individually by a fixed size array
	avl_ainl constexpr auto set_all(v2& vec, const sc scalars[ 2 ]) noexcept -> void
	{
		static_assert(eq<decltype(vec[ 0 ]), decltype(scalars[ 0 ])>::value, "Supply a scalar of the vectors element filetype.");
		static_assert(eq<decltype(vec[ 1 ]), decltype(scalars[ 1 ])>::value, "Supply a scalar of the vectors element filetype.");
		{ vec[0] = scalars[0]; vec[1] = scalars[1]; }
	}
	
	/// \}
	/// \defgroup Base math vector operations for 2 component vectors
	/// \{
	
	// add_mk
	avl_ainl_res constexpr auto add_mk(const v2& vec, const v2& other) noexcept
	{
		return rem_const_ref_t< decltype(vec) >
					{get<0>(vec) + get<0>(other), get<1>(vec) + get<1>(other) };
	}
	
	// add_mk (scalar)
	avl_ainl_res constexpr auto add_mk(const v2& vec, const sc scalar) noexcept
	{
		return rem_const_ref_t< decltype(vec) >
					{get<0>(vec) + scalar, get<1>(vec) + scalar };
	}
	
	// add_set
	avl_ainl constexpr auto add_set(v2& vec, const v2& other) noexcept -> void
	{
		set_all(vec, get<0>(vec) + get<0>(other), get<1>(vec) + get<1>(other) );
	}
	
	// add_set (scalar)
	avl_ainl constexpr auto add_set(v2& vec, const sc scalar) noexcept -> void
	{
		set_all(vec, get<0>(vec) + scalar, get<1>(vec) + scalar );
	}
	
	// add
	avl_ainl_res constexpr auto add(v2& vec, const v2& other) noexcept -> decltype(vec)
	{
		set_all(vec, get<0>(vec) + get<0>(other), get<1>(vec) + get<1>(other) );
		return vec;
	}
	
	// add (scalar)
	avl_ainl_res constexpr auto add(v2& vec, const sc scalar) noexcept -> decltype(vec)
	{
		set_all(vec, get<0>(vec) + scalar, get<1>(vec) + scalar );
		return vec;
	}
	
	// sub_mk
	avl_ainl_res constexpr auto sub_mk(const v2& vec, const v2& other) noexcept
	{
		return rem_const_ref_t< decltype(vec) >
					{get<0>(vec) - get<0>(other), get<1>(vec) - get<1>(other) };
	}
	
	// sub_mk (scalar)
	avl_ainl_res constexpr auto sub_mk(const v2& vec, const sc scalar) noexcept
	{
		return rem_const_ref_t< decltype(vec) >
					{get<0>(vec) - scalar, get<1>(vec) - scalar };
	}
	
	// sub_set
	avl_ainl constexpr auto sub_set(v2& vec, const v2& other) noexcept -> void
	{
		set_all(vec, get<0>(vec) - get<0>(other), get<1>(vec) - get<1>(other) );
	}
	
	// sub_set (scalar)
	avl_ainl constexpr auto sub_set(v2& vec, const sc scalar) noexcept -> void
	{
		set_all(vec, get<0>(vec) - scalar, get<1>(vec) - scalar );
	}
	
	// sub
	avl_ainl_res constexpr auto sub(v2& vec, const v2& other) noexcept -> decltype(vec)
	{
		set_all(vec, get<0>(vec) - get<0>(other), get<1>(vec) - get<1>(other) );
		return vec;
	}
	
	// sub (scalar)
	avl_ainl_res constexpr auto sub(v2& vec, const sc scalar) noexcept -> decltype(vec)
	{
		set_all(vec, get<0>(vec) - scalar, get<1>(vec) - scalar );
		return vec;
	}
	
	// mul_mk
	avl_ainl_res constexpr auto mul_mk(const v2& vec, const v2& other) noexcept
	{
		return rem_const_ref_t< decltype(vec) >
					{get<0>(vec) * get<0>(other), get<1>(vec) * get<1>(other) };
	}
	
	// mul_mk (scalar)
	avl_ainl_res constexpr auto mul_mk(const v2& vec, const sc scalar) noexcept
	{
		return rem_const_ref_t< decltype(vec) >
					{get<0>(vec) * scalar, get<1>(vec) * scalar };
	}
	
	// mul_set
	avl_ainl constexpr auto mul_set(v2& vec, const v2& other) noexcept -> void
	{
		set_all(vec, get<0>(vec) * get<0>(other), get<1>(vec) * get<1>(other) );
	}
	
	// mul_set (scalar)
	avl_ainl constexpr auto mul_set(v2& vec, const sc scalar) noexcept -> void
	{
		set_all(vec, get<0>(vec) * scalar, get<1>(vec) * scalar );
	}
	
	// mul
	avl_ainl_res constexpr auto mul(v2& vec, const v2& other) noexcept -> decltype(vec)
	{
		set_all(vec, get<0>(vec) * get<0>(other), get<1>(vec) * get<1>(other) );
		return vec;
	}
	
	// mul (scalar)
	avl_ainl_res constexpr auto mul(v2& vec, const sc scalar) noexcept -> decltype(vec)
	{
		set_all(vec, get<0>(vec) * scalar, get<1>(vec) * scalar );
		return vec;
	}
	
	// div_mk
	avl_ainl_res constexpr auto div_mk(const v2& vec, const v2& other) noexcept(ndebug||exuse)
	{
		assert(get<0>(other)!=cnst<decltype(cmp(other))>::zero);
		assert(get<1>(other)!=cnst<decltype(cmp(other))>::zero);
		return rem_const_ref_t< decltype(vec) >
					{get<0>(vec) / get<0>(other), get<1>(vec) / get<1>(other) };
	}
	
	// div_mk (scalar)
	avl_ainl_res constexpr auto div_mk(const v2& vec, const sc scalar) noexcept(ndebug||exuse)
	{
		assert(scalar!=cnst<decltype(scalar)>::zero);
		return rem_const_ref_t< decltype(vec) >
					{get<0>(vec) / scalar, get<1>(vec) / scalar };
	}
	
	// div_set
	avl_ainl constexpr auto div_set(v2& vec, const v2& other) noexcept(ndebug||exuse) -> void
	{
		assert(get<0>(other)!=cnst<decltype(cmp(other))>::zero);
		assert(get<1>(other)!=cnst<decltype(cmp(other))>::zero);
		set_all(vec, get<0>(vec) / get<0>(other), get<1>(vec) / get<1>(other) );
	}
	
	// div_set (scalar)
	avl_ainl constexpr auto div_set(v2& vec, const sc scalar) noexcept(ndebug||exuse) -> void
	{
		assert(scalar!=cnst<decltype(scalar)>::zero);
		set_all(vec, get<0>(vec) / scalar, get<1>(vec) / scalar );
	}
	
	// div
	avl_ainl_res constexpr auto div(v2& vec, const v2& other) noexcept(ndebug||exuse) -> decltype(vec)
	{
		assert(get<0>(other)!=cnst<decltype(cmp(other))>::zero);
		assert(get<1>(other)!=cnst<decltype(cmp(other))>::zero);
		set_all(vec, get<0>(vec) / get<0>(other), get<1>(vec) / get<1>(other) );
		return vec;
	}
	
	// div (scalar)
	avl_ainl_res constexpr auto div(v2& vec, const sc scalar) noexcept(ndebug||exuse) -> decltype(vec)
	{
		assert(scalar!=cnst<decltype(scalar)>::zero);
		set_all(vec, get<0>(vec) / scalar, get<1>(vec) / scalar );
		return vec;
	}
	
	/// \}
	/// \defgroup General purpos functions for 2 component vectors
	/// \{
	
	/// Dot product
	avl_ainl constexpr auto dot(const v2& vec, const v2& other) noexcept -> decltype(cmp(vec))
	{
		return get<0>(vec)*get<0>(other) + get<1>(vec)*get<1>(other);
	}
	
	/// \}
}
#endif // AVL_V2_INL