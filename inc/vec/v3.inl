#ifndef AVL_V3_INL
#define AVL_V3_INL

#pragma once

#include "../helper/const.h"

/// avl: A Vector Library
/// \author Thomas Pollak
namespace avl
{
	/// \defgroup Vector length operations
	/// \{
	
	/// Calculate the square length of the vector
	avl_ainl_res constexpr auto len_sqr(const v3& vec) noexcept -> decltype(cmp(vec))
	{
		const auto cmp0 = get<0>(vec);
		const auto cmp1 = get<1>(vec);
		const auto cmp2 = get<2>(vec);
		return cmp0*cmp0 + cmp1*cmp1 + cmp2*cmp2;
	}
	
	/// \}
	/// \defgroup Spacial operations
	/// \{
	
	/// Calculate the area of the spawned triangle
	avl_inl_res constexpr auto area(const v3& vec, const v3& other) noexcept -> decltype(cmp(vec))
	{
		return cnst<decltype(cmp(vec))>::half * len( cross(vec, other) );
	}
	
	/// Calculate the cross product
	avl_ainl_res constexpr auto cross_mk(const v3& vec, const v3& other) noexcept
	{
		return rem_const_ref_t<decltype(vec)> {
				get<1>(vec) * get<2>(other) - get<2>(vec) * get<1>(other),
				get<2>(vec) * get<0>(other) - get<0>(vec) * get<2>(other),
				get<0>(vec) * get<1>(other) - get<1>(vec) * get<0>(other)
			};
	}
	
	/// Calculate the cross product
	avl_ainl constexpr auto cross_set(const v3& vec, const v3& other) noexcept -> void
	{
		set_all(
				get<1>(vec) * get<2>(other) - get<2>(vec) * get<1>(other),
				get<2>(vec) * get<0>(other) - get<0>(vec) * get<2>(other),
				get<0>(vec) * get<1>(other) - get<1>(vec) * get<0>(other)
			);
	}
	
	/// Calculate the cross product
	avl_ainl_res constexpr auto cross(const v3& vec, const v3& other) noexcept -> decltype(vec)
	{
		set_all(
				get<1>(vec) * get<2>(other) - get<2>(vec) * get<1>(other),
				get<2>(vec) * get<0>(other) - get<0>(vec) * get<2>(other),
				get<0>(vec) * get<1>(other) - get<1>(vec) * get<0>(other)
			);
		return vec;
	}
	
	/// \}
	/// \defgroup Getter and setters for 3 component vectors
	/// \{
	
	/// Set all vector components to the same scalar
	avl_ainl constexpr auto set_all(v3& vec, const sc scalar) noexcept -> void
	{
		static_assert(eq<decltype(vec[0]), decltype(scalar)>::value, "Supply a scalar of the vectors element filetype.");
		vec[0] = scalar;
		vec[1] = scalar;
		vec[2] = scalar;
	}
	
	/// Set all vector components individually
	avl_ainl constexpr auto set_all(v3& vecconst sc x, const sc y, const sc z) noexcept -> void;
	{
		static_assert(eq<decltype(vec[ 0 ]), decltype(x)>::value, "Supply a scalar of the vectors element type for x.");
		static_assert(eq<decltype(vec[ 1 ]), decltype(y)>::value, "Supply a scalar of the vectors element type for y.");
		static_assert(eq<decltype(vec[ 2 ]), decltype(z)>::value, "Supply a scalar of the vectors element type for z.");
		vec[0] = x;
		vec[1] = y;
		vec[2] = z;
	}
	
	/// Set all vector components individually by a fixed size array
	avl_ainl constexpr auto set_all(v3& vec, const sc scalars[ 3 ]) noexcept -> void
	{
		static_assert(eq<decltype(vec[ 0 ]), decltype(scalars[ 0 ])>::value, "Supply a scalar of the vectors element filetype.");
		static_assert(eq<decltype(vec[ 1 ]), decltype(scalars[ 1 ])>::value, "Supply a scalar of the vectors element filetype.");
		static_assert(eq<decltype(vec[ 2 ]), decltype(scalars[ 2 ])>::value, "Supply a scalar of the vectors element filetype.");
		vec[0] = scalars[0];
		vec[1] = scalars[1];
		vec[2] = scalars[2];
	}
	
	/// Set all vector components individually by an array
	template <s::size_t _Dim> avl_ainl constexpr auto set_all(v3& vec, const sc* scalars) noexcept -> void
	{
		static_assert(_Dim>=3, "Supply at least 3 scalars.");
		static_assert(eq<decltype(vec[ 0 ]), decltype(scalars[ 0 ])>::value, "Supply a scalar of the vectors element type.");
		static_assert(eq<decltype(vec[ 1 ]), decltype(scalars[ 1 ])>::value, "Supply a scalar of the vectors element type.");
		static_assert(eq<decltype(vec[ 2 ]), decltype(scalars[ 2 ])>::value, "Supply a scalar of the vectors element type.");
		vec[0] = scalars[0];
		vec[1] = scalars[1];
		vec[2] = scalars[2];
	}
	
	/// \}
	/// \defgroup General vector operations for 3 component vectors
	/// \{
	
	// add_mk
	avl_ainl_res constexpr auto add_mk(const v3& vec, const v3& other) noexcept
	{
		return rem_const_ref_t< decltype(vec) >
					{get<0>(vec) + get<0>(other), get<1>(vec) + get<1>(other), get<2>(vec) + get<2>(other) };
	}
	
	// add_mk (scalar)
	avl_ainl_res constexpr auto add_mk(const v3& vec, const sc scalar) noexcept
	{
		return rem_const_ref_t< decltype(vec) >
					{get<0>(vec) + scalar, get<1>(vec) + scalar, get<2>(vec) + scalar };
	}
	
	// add_set
	avl_ainl constexpr auto add_set(const v3& vec, const v3& other) noexcept -> void
	{
		set_all(vec, get<0>(vec) + get<0>(other), get<1>(vec) + get<1>(other), get<2>(vec) + get<2>(other) );
	}
	
	// add_set (scalar)
	avl_ainl_res constexpr auto add_set(const v3& vec, const sc scalar) noexcept -> void
	{
		set_all(vec, get<0>(vec) + scalar, get<1>(vec) + scalar, get<2>(vec) + scalar );
	}
	
	// add
	avl_ainl_res constexpr auto add(const v3& vec, const v3& other) noexcept -> decltype(vec)
	{
		set_all(vec, get<0>(vec) + get<0>(other), get<1>(vec) + get<1>(other), get<2>(vec) + get<2>(other) );
		return vec;
	}
	
	// add (scalar)
	avl_ainl_res constexpr auto add(const v3& vec, const sc scalar) noexcept -> decltype(vec)
	{
		set_all(vec, get<0>(vec) + scalar, get<1>(vec) + scalar, get<2>(vec) + scalar );
		return vec;
	}
	
	// sub_mk
	avl_ainl_res constexpr auto sub_mk(const v3& vec, const v3& other) noexcept
	{
		return rem_const_ref_t< decltype(vec) >
					{get<0>(vec) - get<0>(other), get<1>(vec) - get<1>(other), get<2>(vec) - get<2>(other) };
	}
	
	// sub_mk (scalar)
	avl_ainl_res constexpr auto sub_mk(const v3& vec, const sc scalar) noexcept
	{
		return rem_const_ref_t< decltype(vec) >
					{get<0>(vec) - scalar, get<1>(vec) - scalar, get<2>(vec) - scalar };
	}
	
	// sub_set
	avl_ainl constexpr auto sub_set(const v3& vec, const v3& other) noexcept -> void
	{
		set_all(vec, get<0>(vec) - get<0>(other), get<1>(vec) - get<1>(other), get<2>(vec) - get<2>(other) );
	}
	
	// sub_set (scalar)
	avl_ainl_res constexpr auto sub_set(const v3& vec, const sc scalar) noexcept -> void
	{
		set_all(vec, get<0>(vec) - scalar, get<1>(vec) - scalar, get<2>(vec) - scalar );
	}
	
	// sub
	avl_ainl_res constexpr auto sub(const v3& vec, const v3& other) noexcept -> decltype(vec)
	{
		set_all(vec, get<0>(vec) - get<0>(other), get<1>(vec) - get<1>(other), get<2>(vec) - get<2>(other) );
		return vec;
	}
	
	// sub (scalar)
	avl_ainl_res constexpr auto sub(const v3& vec, const sc scalar) noexcept -> decltype(vec)
	{
		set_all(vec, get<0>(vec) - scalar, get<1>(vec) - scalar, get<2>(vec) - scalar );
		return vec;
	}
	
	// mul_mk
	avl_ainl_res constexpr auto mul_mk(const v3& vec, const v3& other) noexcept
	{
		return rem_const_ref_t< decltype(vec) >
					{get<0>(vec) * get<0>(other), get<1>(vec) * get<1>(other), get<2>(vec) * get<2>(other) };
	}
	
	// mul_mk (scalar)
	avl_ainl_res constexpr auto mul_mk(const v3& vec, const sc scalar) noexcept
	{
		return rem_const_ref_t< decltype(vec) >
					{get<0>(vec) * scalar, get<1>(vec) * scalar, get<2>(vec) * scalar };
	}
	
	// mul_set
	avl_ainl constexpr auto mul_set(const v3& vec, const v3& other) noexcept -> void
	{
		set_all(vec, get<0>(vec) * get<0>(other), get<1>(vec) * get<1>(other), get<2>(vec) * get<2>(other) );
	}
	
	// mul_set (scalar)
	avl_ainl_res constexpr auto mul_set(const v3& vec, const sc scalar) noexcept -> void
	{
		set_all(vec, get<0>(vec) * scalar, get<1>(vec) * scalar, get<2>(vec) * scalar );
	}
	
	// mul
	avl_ainl_res constexpr auto mul(const v3& vec, const v3& other) noexcept -> decltype(vec)
	{
		set_all(vec, get<0>(vec) * get<0>(other), get<1>(vec) * get<1>(other), get<2>(vec) * get<2>(other) );
		return vec;
	}
	
	// mul (scalar)
	avl_ainl_res constexpr auto mul(const v3& vec, const sc scalar) noexcept -> decltype(vec)
	{
		set_all(vec, get<0>(vec) * scalar, get<1>(vec) * scalar, get<2>(vec) * scalar );
		return vec;
	}
	
	// div_mk
	avl_ainl_res constexpr auto div_mk(const v3& vec, const v3& other) noexcept(ndebug|exude)
	{
		assert(get<0>(other)!=cnst<decltype(cmp(other))>::zero);
		assert(get<1>(other)!=cnst<decltype(cmp(other))>::zero);
		assert(get<2>(other)!=cnst<decltype(cmp(other))>::zero);
		return rem_const_ref_t< decltype(vec) >
					{get<0>(vec) / get<0>(other), get<1>(vec) / get<1>(other), get<2>(vec) / get<2>(other) };
	}
	
	// div_mk (scalar)
	avl_ainl_res constexpr auto div_mk(const v3& vec, const sc scalar) noexcept(ndebug|exude)
	{
		assert(scalar!=cnst<decltype(scalar)>::zero);
		return rem_const_ref_t< decltype(vec) >
					{get<0>(vec) / scalar, get<1>(vec) / scalar, get<2>(vec) / scalar };
	}
	
	// div_set
	avl_ainl constexpr auto div_set(const v3& vec, const v3& other) noexcept(ndebug|exude) -> void
	{
		assert(get<0>(other)!=cnst<decltype(cmp(other))>::zero);
		assert(get<1>(other)!=cnst<decltype(cmp(other))>::zero);
		assert(get<2>(other)!=cnst<decltype(cmp(other))>::zero);
		set_all(vec, get<0>(vec) / get<0>(other), get<1>(vec) / get<1>(other), get<2>(vec) / get<2>(other) );
	}
	
	// div_set (scalar)
	avl_ainl_res constexpr auto div_set(const v3& vec, const sc scalar) noexcept(ndebug|exude) -> void
	{
		assert(scalar!=cnst<decltype(scalar)>::zero);
		set_all(vec, get<0>(vec) / scalar, get<1>(vec) / scalar, get<2>(vec) / scalar );
	}
	
	// div
	avl_ainl_res constexpr auto div(const v3& vec, const v3& other) noexcept(ndebug|exude) -> decltype(vec)
	{
		assert(get<0>(other)!=cnst<decltype(cmp(other))>::zero);
		assert(get<1>(other)!=cnst<decltype(cmp(other))>::zero);
		assert(get<2>(other)!=cnst<decltype(cmp(other))>::zero);
		set_all(vec, get<0>(vec) / get<0>(other), get<1>(vec) / get<1>(other), get<2>(vec) / get<2>(other) );
		return vec;
	}
	
	// div (scalar)
	avl_ainl_res constexpr auto div(const v3& vec, const sc scalar) noexcept(ndebug|exude) -> decltype(vec)
	{
		assert(scalar!=cnst<decltype(scalar)>::zero);
		set_all(vec, get<0>(vec) / scalar, get<1>(vec) / scalar, get<2>(vec) / scalar );
		return vec;
	}
	
	/// \}
}
#endif // AVL_V3_INL