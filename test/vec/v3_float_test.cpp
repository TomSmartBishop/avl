#include "../../ext/catch/catch.hpp"
#include "../../inc/avl.h"

using namespace avl;

TEST_CASE( "3 | Helper functions", "[vec3<float>(3)]" )
{
	SECTION( "Component type helper/1" )
	{
		const vec3<float> vec = { 0, 0, 0 };
		static_assert(eq< decltype( vec[0] ), decltype( cmp(vec) ) >::value, "Supply a scalar of the vectors element type.");
	}
	
}
TEST_CASE( "3 | Getters and setters for all vectors", "[vec3<float>(3)]" )
{
	SECTION( "Access the vector components by a range checked index from 0 to dim-1/1" )
	{
		const vec3<float> vec = { 0, 1, 2 };
		
		REQUIRE( get(vec, 0) == Approx( 0 ) );
		REQUIRE( get(vec, 1) == Approx( 1 ) );
		REQUIRE( get(vec, 2) == Approx( 2 ) );
	}
	
	SECTION( "Access the vector components by a static range checked index from 0 to dim-1/1" )
	{
		const vec3<float> vec = { 0, 1, 2 };
		
		REQUIRE( get<0>(vec) == Approx( 0 ) );
		REQUIRE( get<1>(vec) == Approx( 1 ) );
		REQUIRE( get<2>(vec) == Approx( 2 ) );
	}
	
	SECTION( "Set a single component by index from 0 to dim-1/1" )
	{
		vec3<float> vec = { 0, 0, 0 };
		const float arr [] = { 17.159, -30.164, -58.525 };
		
		set(vec, 0, arr[0]);
		REQUIRE( get(vec, 0) == Approx( arr[0] ) );
		set(vec, 1, arr[1]);
		REQUIRE( get(vec, 1) == Approx( arr[1] ) );
		set(vec, 2, arr[2]);
		REQUIRE( get(vec, 2) == Approx( arr[2] ) );
	}
	
	SECTION( "Set a single component by static index from 0 to dim-1/1" )
	{
		vec3<float> vec = { 0, 1, 2 };
		const float arr [] = { -63.254, -97.805, -2.498 };
		
		set<0>(vec, arr[ 0 ]);
		REQUIRE( get<0>(vec) == Approx( arr[0] ) );
		set<1>(vec, arr[ 1 ]);
		REQUIRE( get<1>(vec) == Approx( arr[1] ) );
		set<2>(vec, arr[ 2 ]);
		REQUIRE( get<2>(vec) == Approx( arr[2] ) );
	}
	
}
TEST_CASE( "3 | Vector length operations", "[vec3<float>(3)]" )
{
	SECTION( "Returns a new vector with the requested length/1" )
	{
		const vec3<float> vec = { -89.937, 83.113, 76.661 };
		const float len_to_set = { 54.562 };
		const auto new_vec = setlen_mk(vec, len_to_set);
		const auto len_new_vec = len(new_vec);
		
		REQUIRE( len_new_vec == Approx(len_to_set) );
		
		//test edge case 0.0
		const auto zero_len_vec = setlen_mk(vec, cnst<float>::zero);
		REQUIRE( get<0>(zero_len_vec) == Approx( cnst<float>::zero ) );
		REQUIRE( get<1>(zero_len_vec) == Approx( cnst<float>::zero ) );
		REQUIRE( get<2>(zero_len_vec) == Approx( cnst<float>::zero ) );
	}
	
	SECTION( "Set the length of the vector/1" )
	{
		vec3<float> vec = { 89.966, 0.972, 79.548 };
		const float len_to_set = { 60.731 };
		setlen_set(vec, len_to_set);
		const auto vec_len = len(vec);
		
		REQUIRE( vec_len == Approx(len_to_set) );
		
		//test edge case 0.0
		setlen_set(vec, cnst<float>::zero);
		
		REQUIRE( get<0>(vec) == Approx( cnst<float>::zero ) );
		REQUIRE( get<1>(vec) == Approx( cnst<float>::zero ) );
		REQUIRE( get<2>(vec) == Approx( cnst<float>::zero ) );
	}
	
	SECTION( "Set the length of the vector and return the same vector (chained)/1" )
	{
		vec3<float> vec = { 84.250, 80.794, 15.910 };
		const float len_to_set = { 56.508 };
		const auto &ret_vec = setlen(vec, len_to_set);
		const auto vec_len = len(vec);
		
		REQUIRE( vec_len == Approx(len_to_set) );
		
		REQUIRE( &vec == &ret_vec);
		//test edge case 0.0
		const auto &ret_zero_vec = setlen(vec, cnst<float>::zero);
		
		REQUIRE( get<0>(vec) == Approx( cnst<float>::zero ) );
		REQUIRE( get<1>(vec) == Approx( cnst<float>::zero ) );
		REQUIRE( get<2>(vec) == Approx( cnst<float>::zero ) );
		REQUIRE( &vec == &ret_zero_vec);
	}
	
	SECTION( "Calculate the length of the vector, prefere len_sqr when comparing distances/1" )
	{
		const vec3<float> vec = { 42.835, 91.443, -80.435 };
		const auto vec_len = len(vec);
		const auto vec_square_len = get<0>(vec) * get<0>(vec) + get<1>(vec) * get<1>(vec) + get<2>(vec) * get<2>(vec);
		REQUIRE( vec_len == Approx( s::sqrt( vec_square_len ) ) );
		
		//test edge case 0.0
		const vec3<float> zero_vec = { 0, 0, 0 };
		const auto zero_vec_len = len(zero_vec);
		REQUIRE( zero_vec_len == Approx( cnst<float>::zero ) );
	}
	
	SECTION( "Calculate the square length of the vector/1" )
	{
		const vec3<float> vec = { 49.484, -66.180, -81.802 };
		const auto vec_len_sqr = len_sqr(vec);
		const auto vec_len_sqr_check = get<0>(vec) * get<0>(vec) + get<1>(vec) * get<1>(vec) + get<2>(vec) * get<2>(vec);
		REQUIRE( vec_len_sqr == Approx( vec_len_sqr_check ) );
		
		//test edge case 0.0
		const vec3<float> zero_vec = { 0, 0, 0 };
		const auto zero_vec_len_sqr = len_sqr(zero_vec);
		REQUIRE( zero_vec_len_sqr == Approx( cnst<float>::zero ) );
	}
	
	SECTION( "Returns a normalized vector/1" )
	{
		
		const vec3<float> vec = { -22.158, -9.729, 77.540 };
		const auto new_norm_vec = norm_mk(vec);
		const auto norm_len = len(new_norm_vec);
		REQUIRE( norm_len == Approx( cnst<float>::one ) );
	}
	
	SECTION( "Returns a normalized vector, use alternative vector if the current vector length is 0/1" )
	{
		const vec3<float> zero_vec = { 0, 0, 0 };
		const auto zero_len = len(zero_vec);
		REQUIRE( zero_len == Approx( cnst<float>::zero ) );
		
		vec3<float> unit_vec = { 0, 0, 0 };
		set<0>(unit_vec, cnst<float>::one);
		
		const auto new_unit_vec = norm_mk(zero_vec, unit_vec);
		const auto new_unit_vec_len = len(new_unit_vec);
		REQUIRE( new_unit_vec_len == Approx( cnst<float>::one ) );
		REQUIRE( get<0>(new_unit_vec) == Approx( cnst<float>::one ) );
	}
	
	SECTION( "Normalize the current vector/1" )
	{
		vec3<float> vec = { 8.166, 77.828, -17.454 };
		norm_set(vec);
		const auto len_of_norm_vec = len(vec);
		REQUIRE( len_of_norm_vec == Approx( cnst<float>::one ) );
	}
	
	SECTION( "Normalize the current vector, use alternative vector if the current vector length is 0/1" )
	{
		vec3<float> vec = { 0, 0, 0 };
		const auto zero_len = len(vec);
		REQUIRE( zero_len == Approx( cnst<float>::zero ) );
		
		vec3<float> unit_vec = { 0, 0, 0 };
		set<0>(unit_vec, cnst<float>::one);
		
		norm_set(vec, unit_vec);
		const auto vec_len = len(vec);
		REQUIRE( vec_len == Approx( cnst<float>::one ) );
		REQUIRE( get<0>(vec) == Approx( cnst<float>::one ) );
	}
	
	SECTION( "Normalize the current vector and return the same vector (chained)/1" )
	{
		vec3<float> vec = { 86.022, 2.399, -83.996 };
		const auto &ret_vec = norm(vec);
		const auto len_of_norm_vec = len(vec);
		REQUIRE( len_of_norm_vec == Approx( cnst<float>::one ) );
		REQUIRE( &vec == &ret_vec);
	}
	
	SECTION( "Normalize the current vector and return the same vector (chained), use alternative vector if the current vector length is 0/1" )
	{
		vec3<float> vec = { 0, 0, 0 };
		const auto zero_len = len(vec);
		REQUIRE( zero_len == Approx( cnst<float>::zero ) );
		
		vec3<float> unit_vec = { 0, 0, 0 };
		set<0>(unit_vec, cnst<float>::one);
		
		const auto &ret_vec = norm(vec, unit_vec);
		const auto vec_len = len(vec);
		REQUIRE( vec_len == Approx( cnst<float>::one ) );
		REQUIRE( get<0>(vec) == Approx( cnst<float>::one ) );
		REQUIRE( &vec == &ret_vec);
	}
	
}
TEST_CASE( "3 | Spacial operations", "[vec3<float>(3)]" )
{
	SECTION( "Calculate the angle between two vectors in radian/1" )
	{
		const float random_len1 = { 5.982 };
		const float random_len2 = { 14.506 };
		const float random_len3 = { 64.685 };
		const float random_len4 = { 97.796 };
		
		vec3<float> vec_zero = { 0, 0, 0 };
		vec3<float> vec_10x = { 0, 0, 0 };
		set<0>(vec_10x, random_len1);
		vec3<float> vec_01x = { 0, 0, 0 };
		set<1>(vec_01x, random_len2);
		vec3<float> vec_m10x = { 0, 0, 0 };
		set<0>(vec_m10x, -random_len3);
		vec3<float> vec_11x = { 0, 0, 0 };
		set<0>(vec_11x, random_len4);
		set<1>(vec_11x, random_len4);
		
		//TODO: add case for edge case with zero vec
		
		const auto angle0 = angle_rd(vec_10x, vec_10x);
		REQUIRE( angle0 == Approx( cnst<float>::zero ) );
		
		const auto angle90 = angle_rd(vec_10x, vec_01x);
		REQUIRE( angle90 == Approx( 1.57079632679 ) );
		
		const auto angle45a = angle_rd(vec_10x, vec_11x);
		REQUIRE( angle45a == Approx( 0.785398163396 ) );
		const auto angle45b = angle_rd(vec_01x, vec_11x);
		REQUIRE( angle45b == Approx( 0.785398163396 ) );
		
		const auto angle135 = angle_rd(vec_m10x, vec_11x);
		REQUIRE( angle135 == Approx( 2.35619449019 ) );
		
		const auto angle180 = angle_rd(vec_10x, vec_m10x);
		REQUIRE( angle180 == Approx( 3.14159265358 ) );
	}
	
	SECTION( "Calculate the angle between two vectors in radian/2" )
	{
		const float random_len1 = { 83.889 };
		const float random_len2 = { 76.174 };
		const float random_len3 = { 87.059 };
		const float random_len4 = { 91.527 };
		
		vec3<float> vec_zero = { 0, 0, 0 };
		vec3<float> vec_010x = { 0, 0, 0 };
		set<1>(vec_010x, random_len1);
		vec3<float> vec_001x = { 0, 0, 0 };
		set<2>(vec_001x, random_len2);
		vec3<float> vec_0m10x = { 0, 0, 0 };
		set<1>(vec_0m10x, -random_len3);
		vec3<float> vec_011x = { 0, 0, 0 };
		set<1>(vec_011x, random_len4);
		set<2>(vec_011x, random_len4);
		
		const auto angle0 = angle_rd(vec_010x, vec_010x);
		REQUIRE( angle0 == Approx( cnst<float>::zero ) );
		
		const auto angle90 = angle_rd(vec_010x, vec_001x);
		REQUIRE( angle90 == Approx( 1.57079632679 ) );
		
		const auto angle45a = angle_rd(vec_010x, vec_011x);
		REQUIRE( angle45a == Approx( 0.785398163396 ) );
		const auto angle45b = angle_rd(vec_001x, vec_011x);
		REQUIRE( angle45b == Approx( 0.785398163396 ) );
		
		const auto angle135 = angle_rd(vec_0m10x, vec_011x);
		REQUIRE( angle135 == Approx( 2.35619449019 ) );
		
		const auto angle180 = angle_rd(vec_010x, vec_0m10x);
		REQUIRE( angle180 == Approx( 3.14159265358 ) );
	}
	
	SECTION( "Calculate the angle between two vectors in degree/1" )
	{
		const float random_len1 = { 46.72 };
		const float random_len2 = { 39.516 };
		const float random_len3 = { 5.022 };
		const float random_len4 = { 55.346 };
		
		vec3<float> vec_zero = { 0, 0, 0 };
		vec3<float> vec_10x = { 0, 0, 0 };
		set<0>(vec_10x, random_len1);
		vec3<float> vec_01x = { 0, 0, 0 };
		set<1>(vec_01x, random_len2);
		vec3<float> vec_m10x = { 0, 0, 0 };
		set<0>(vec_m10x, -random_len3);
		vec3<float> vec_11x = { 0, 0, 0 };
		set<0>(vec_11x, random_len4);
		set<1>(vec_11x, random_len4);
		
		//TODO: add case for edge case with zero vec
		
		const auto angle0 = angle_dg(vec_10x, vec_10x);
		REQUIRE( angle0 == Approx( cnst<float>::zero ) );
		
		const auto angle90 = angle_dg(vec_10x, vec_01x);
		REQUIRE( angle90 == Approx( 90 ) );
		
		const auto angle45a = angle_dg(vec_10x, vec_11x);
		REQUIRE( angle45a == Approx( 45 ) );
		const auto angle45b = angle_dg(vec_01x, vec_11x);
		REQUIRE( angle45b == Approx( 45 ) );
		
		const auto angle135 = angle_dg(vec_m10x, vec_11x);
		REQUIRE( angle135 == Approx( 135 ) );
		
		const auto angle180 = angle_dg(vec_10x, vec_m10x);
		REQUIRE( angle180 == Approx( 180 ) );
	}
	
	SECTION( "Calculate the angle between two vectors in degree/2" )
	{
		const float random_len1 = { 64.931 };
		const float random_len2 = { 71.991 };
		const float random_len3 = { 18.044 };
		const float random_len4 = { 30.556 };
		
		vec3<float> vec_zero = { 0, 0, 0 };
		vec3<float> vec_010x = { 0, 0, 0 };
		set<1>(vec_010x, random_len1);
		vec3<float> vec_001x = { 0, 0, 0 };
		set<2>(vec_001x, random_len2);
		vec3<float> vec_0m10x = { 0, 0, 0 };
		set<1>(vec_0m10x, -random_len3);
		vec3<float> vec_011x = { 0, 0, 0 };
		set<1>(vec_011x, random_len4);
		set<2>(vec_011x, random_len4);
		
		const auto angle0 = angle_dg(vec_010x, vec_010x);
		REQUIRE( angle0 == Approx( cnst<float>::zero ) );
		
		const auto angle90 = angle_dg(vec_010x, vec_001x);
		REQUIRE( angle90 == Approx( 90 ) );
		
		const auto angle45a = angle_dg(vec_010x, vec_011x);
		REQUIRE( angle45a == Approx( 45 ) );
		const auto angle45b = angle_dg(vec_001x, vec_011x);
		REQUIRE( angle45b == Approx( 45 ) );
		
		const auto angle135 = angle_dg(vec_0m10x, vec_011x);
		REQUIRE( angle135 == Approx( 135 ) );
		
		const auto angle180 = angle_dg(vec_010x, vec_0m10x);
		REQUIRE( angle180 == Approx( 180 ) );
	}
	
	SECTION( "Calculate the area of the spawned triangle/1" )
	{
		vec3<float> vec_0 = { 0, 0, 0 };
		vec3<float> vec_1 = { 0, 0, 0 };
		vec3<float> vec_2 = { 0, 0, 0 };
		set<0>(vec_0, cnst<float>::one);
		set<1>(vec_1, cnst<float>::one);
		set<0>(vec_2, cnst<float>::minus_one);
		
		const auto a0 = area(vec_0, vec_1);
		REQUIRE( a0 == cnst<float>::half );
		
		const auto a1 = area(vec_0, vec_0);
		REQUIRE( a1 == cnst<float>::zero );
		
		const auto a2 = area(vec_0, vec_2);
		REQUIRE( a2 == cnst<float>::zero );
	}
	
	SECTION( "Calculate the cross product/1" )
	{
		vec3<float> vec_100x = { 0, 0, 0 };
		vec3<float> vec_100x_dup = { 0, 0, 0 };
		vec3<float> vec_010x = { 0, 0, 0 };
		vec3<float> expected_res1 = { 0, 0, 0 };
		vec3<float> expected_res2 = { 0, 0, 0 };
		set<0>(vec_100x, cnst<float>::one);
		set<0>(vec_100x_dup, cnst<float>::one);
		set<1>(vec_010x, cnst<float>::one);
		set<2>(expected_res1, cnst<float>::one);
		set<2>(expected_res2, cnst<float>::minus_one);
		
		auto result1 = cross_mk(vec_100x, vec_010x);
		auto result2 = cross_mk(vec_010x, vec_100x);
		REQUIRE( get<0>(result1) == Approx( get<0>(expected_res1) ) );
		REQUIRE( get<1>(result1) == Approx( get<1>(expected_res1) ) );
		REQUIRE( get<2>(result1) == Approx( get<2>(expected_res1) ) );
		REQUIRE( get<0>(result2) == Approx( get<0>(expected_res2) ) );
		REQUIRE( get<1>(result2) == Approx( get<1>(expected_res2) ) );
		REQUIRE( get<2>(result2) == Approx( get<2>(expected_res2) ) );
	}
	
	SECTION( "Calculate the cross product/1" )
	{
		vec3<float> vec_100x = { 0, 0, 0 };
		vec3<float> vec_100x_dup = { 0, 0, 0 };
		vec3<float> vec_010x = { 0, 0, 0 };
		vec3<float> expected_res1 = { 0, 0, 0 };
		vec3<float> expected_res2 = { 0, 0, 0 };
		set<0>(vec_100x, cnst<float>::one);
		set<0>(vec_100x_dup, cnst<float>::one);
		set<1>(vec_010x, cnst<float>::one);
		set<2>(expected_res1, cnst<float>::one);
		set<2>(expected_res2, cnst<float>::minus_one);
		
		cross_set(vec_100x, vec_010x);
		cross_set(vec_010x, vec_100x_dup);
		REQUIRE( get<0>(vec_100x) == Approx( get<0>(expected_res1) ) );
		REQUIRE( get<1>(vec_100x) == Approx( get<1>(expected_res1) ) );
		REQUIRE( get<2>(vec_100x) == Approx( get<2>(expected_res1) ) );
		REQUIRE( get<0>(vec_010x) == Approx( get<0>(expected_res2) ) );
		REQUIRE( get<1>(vec_010x) == Approx( get<1>(expected_res2) ) );
		REQUIRE( get<2>(vec_010x) == Approx( get<2>(expected_res2) ) );
	}
	
	SECTION( "Calculate the cross product/1" )
	{
		vec3<float> vec_100x = { 0, 0, 0 };
		vec3<float> vec_100x_dup = { 0, 0, 0 };
		vec3<float> vec_010x = { 0, 0, 0 };
		vec3<float> expected_res1 = { 0, 0, 0 };
		vec3<float> expected_res2 = { 0, 0, 0 };
		set<0>(vec_100x, cnst<float>::one);
		set<0>(vec_100x_dup, cnst<float>::one);
		set<1>(vec_010x, cnst<float>::one);
		set<2>(expected_res1, cnst<float>::one);
		set<2>(expected_res2, cnst<float>::minus_one);
		
		auto &result1 = cross(vec_100x, vec_010x);
		auto &result2 = cross(vec_010x, vec_100x);
		REQUIRE( get<0>(result1) == Approx( get<0>(expected_res1) ) );
		REQUIRE( get<1>(result1) == Approx( get<1>(expected_res1) ) );
		REQUIRE( get<2>(result1) == Approx( get<2>(expected_res1) ) );
		REQUIRE( get<0>(result2) == Approx( get<0>(expected_res2) ) );
		REQUIRE( get<1>(result2) == Approx( get<1>(expected_res2) ) );
		REQUIRE( get<2>(result2) == Approx( get<2>(expected_res2) ) );
	}
	
}
TEST_CASE( "3 | Getter and setters for 3 component vectors", "[vec3<float>(3)]" )
{
	SECTION( "Set all vector components to the same scalar/1" )
	{
		vec3<float> vec = { 0, 0, 0 };
		
		const float val = { -30.752 };
		
		set_all(vec, val);
		
		REQUIRE( get<0>(vec)==val );
		REQUIRE( get<1>(vec)==val );
		REQUIRE( get<2>(vec)==val );
	}
	
	SECTION( "Set all vector components individually/1" )
	{
		vec3<float> vec = { 0, 0, 0 };
		const float arr [] = { 44.111, -87.757, 31.643 };
		
		set_all(vec,arr[0], arr[1], arr[2]);
		
		REQUIRE( get<0>(vec)==arr[0] );
		REQUIRE( get<1>(vec)==arr[1] );
		REQUIRE( get<2>(vec)==arr[2] );
	}
	
	SECTION( "Set all vector components individually by a fixed size array/1" )
	{
		vec3<float> vec = { 0, 0, 0 };
		const float arr [] = { -20.870, 99.803, 15.063 };
		
		set_all(vec, arr);
		
		REQUIRE( get<0>(vec)==arr[0] );
		REQUIRE( get<1>(vec)==arr[1] );
		REQUIRE( get<2>(vec)==arr[2] );
	}
	
	SECTION( "Set all vector components individually by an array/1" )
	{
		vec3<float> vec = { 0, 0, 0 };
		const float arr [] = { 91.631, 95.936, 79.751 };
		const auto* ptr_to_arr = arr;
		
		set_all<3>(vec, ptr_to_arr);
		
		REQUIRE( get<0>(vec)==arr[0] );
		REQUIRE( get<1>(vec)==arr[1] );
		REQUIRE( get<2>(vec)==arr[2] );
	}
	
}
TEST_CASE( "3 | General vector operations for 3 component vectors", "[vec3<float>(3)]" )
{
	vec3<float> add_var_1 = { 32.164, -98.242, -47.634 };
	vec3<float> add_var_2 = { 11.530, -23.339, -20.869 };
	const float add_scalar = { -42.571 };
	
	const float add_vec_res [] =
		{ get<0>(add_var_1) + get<0>(add_var_2), get<1>(add_var_1) + get<1>(add_var_2), get<2>(add_var_1) + get<2>(add_var_2) };
	const float add_scalar_res [] =
		{ get<0>(add_var_1) + add_scalar, get<1>(add_var_1) + add_scalar, get<2>(add_var_1) + add_scalar };
	const float add_vec_scalar_res [] =
		{ get<0>(add_var_1) + get<0>(add_var_2) + add_scalar, get<1>(add_var_1) + get<1>(add_var_2) + add_scalar, get<2>(add_var_1) + get<2>(add_var_2) + add_scalar };
	
	vec3<float> sub_var_1 = { -66.230, 96.213, 63.923 };
	vec3<float> sub_var_2 = { -29.223, 83.438, -89.235 };
	const float sub_scalar = { 64.109 };
	
	const float sub_vec_res [] =
		{ get<0>(sub_var_1) - get<0>(sub_var_2), get<1>(sub_var_1) - get<1>(sub_var_2), get<2>(sub_var_1) - get<2>(sub_var_2) };
	const float sub_scalar_res [] =
		{ get<0>(sub_var_1) - sub_scalar, get<1>(sub_var_1) - sub_scalar, get<2>(sub_var_1) - sub_scalar };
	const float sub_vec_scalar_res [] =
		{ get<0>(sub_var_1) - get<0>(sub_var_2) - sub_scalar, get<1>(sub_var_1) - get<1>(sub_var_2) - sub_scalar, get<2>(sub_var_1) - get<2>(sub_var_2) - sub_scalar };
	
	vec3<float> mul_var_1 = { -5.500, -59.844, -71.993 };
	vec3<float> mul_var_2 = { 35.807, 23.679, -44.516 };
	const float mul_scalar = { -17.864 };
	
	const float mul_vec_res [] =
		{ get<0>(mul_var_1) * get<0>(mul_var_2), get<1>(mul_var_1) * get<1>(mul_var_2), get<2>(mul_var_1) * get<2>(mul_var_2) };
	const float mul_scalar_res [] =
		{ get<0>(mul_var_1) * mul_scalar, get<1>(mul_var_1) * mul_scalar, get<2>(mul_var_1) * mul_scalar };
	const float mul_vec_scalar_res [] =
		{ get<0>(mul_var_1) * get<0>(mul_var_2) * mul_scalar, get<1>(mul_var_1) * get<1>(mul_var_2) * mul_scalar, get<2>(mul_var_1) * get<2>(mul_var_2) * mul_scalar };
	
	vec3<float> div_var_1 = { -55.271, 54.458, 53.365 };
	vec3<float> div_var_2 = { -77.151, 9.297, 68.259 };
	const float div_scalar = { 31.885 };
	
	const float div_vec_res [] =
		{ get<0>(div_var_1) / get<0>(div_var_2), get<1>(div_var_1) / get<1>(div_var_2), get<2>(div_var_1) / get<2>(div_var_2) };
	const float div_scalar_res [] =
		{ get<0>(div_var_1) / div_scalar, get<1>(div_var_1) / div_scalar, get<2>(div_var_1) / div_scalar };
	const float div_vec_scalar_res [] =
		{ get<0>(div_var_1) / get<0>(div_var_2) / div_scalar, get<1>(div_var_1) / get<1>(div_var_2) / div_scalar, get<2>(div_var_1) / get<2>(div_var_2) / div_scalar };
	
	SECTION( "add_mk/1" )
	{
		auto res = add_mk(add_var_1, add_var_2);
		REQUIRE( get<0>(res) == Approx(add_vec_res[0]) );
		REQUIRE( get<1>(res) == Approx(add_vec_res[1]) );
		REQUIRE( get<2>(res) == Approx(add_vec_res[2]) );
		REQUIRE( &res != &add_var_1 ); //result must be a new resource
		REQUIRE( &res != &add_var_2 ); //also different to add_var_2
	}
	
	SECTION( "add_mk (scalar)/1" )
	{
		auto res = add_mk(add_var_1, add_scalar);
		REQUIRE( get<0>(res) == Approx(add_scalar_res[0]) );
		REQUIRE( get<1>(res) == Approx(add_scalar_res[1]) );
		REQUIRE( get<2>(res) == Approx(add_scalar_res[2]) );
		REQUIRE( &res != &add_var_1 ); //result must be a new resource
	}
	
	SECTION( "add_set/1" )
	{
		add_set(add_var_1, add_var_2);
		REQUIRE( get<0>(add_var_1) == Approx(add_vec_res[0]) );
		REQUIRE( get<1>(add_var_1) == Approx(add_vec_res[1]) );
		REQUIRE( get<2>(add_var_1) == Approx(add_vec_res[2]) );
	}
	
	SECTION( "add_set (scalar)/1" )
	{
		add_set(add_var_1, add_scalar);
		REQUIRE( get<0>(add_var_1) == Approx(add_scalar_res[0]) );
		REQUIRE( get<1>(add_var_1) == Approx(add_scalar_res[1]) );
		REQUIRE( get<2>(add_var_1) == Approx(add_scalar_res[2]) );
	}
	
	SECTION( "add/1" )
	{
		auto &res = add(add_var_1, add_var_2);
		REQUIRE( get<0>(res) == Approx(add_vec_res[0]) );
		REQUIRE( get<1>(res) == Approx(add_vec_res[1]) );
		REQUIRE( get<2>(res) == Approx(add_vec_res[2]) );
		REQUIRE( &res == &add_var_1 );//result must be add_var_1
		REQUIRE( &res != &add_var_2 );//but not add_var_2
		auto &res2 = add(res, add_scalar);
		REQUIRE( get<0>(res2) == Approx(add_vec_scalar_res[0]) );
		REQUIRE( get<1>(res2) == Approx(add_vec_scalar_res[1]) );
		REQUIRE( get<2>(res2) == Approx(add_vec_scalar_res[2]) );
		REQUIRE( &res2 == &add_var_1 );//result must be add_var_1
	}
	
	SECTION( "add (scalar)/1" )
	{
		auto &res = add(add_var_1, add_scalar);
		REQUIRE( get<0>(res) == Approx(add_scalar_res[0]) );
		REQUIRE( get<1>(res) == Approx(add_scalar_res[1]) );
		REQUIRE( get<2>(res) == Approx(add_scalar_res[2]) );
		REQUIRE( &res == &add_var_1 );//result must be add_var_1
		auto &res2 = add(res, add_var_2);
		REQUIRE( get<0>(res2) == Approx(add_vec_scalar_res[0]) );
		REQUIRE( get<1>(res2) == Approx(add_vec_scalar_res[1]) );
		REQUIRE( get<2>(res2) == Approx(add_vec_scalar_res[2]) );
		REQUIRE( &res2 == &add_var_1 );//result must be add_var_1
	}
	
	SECTION( "sub_mk/1" )
	{
		auto res = sub_mk(sub_var_1, sub_var_2);
		REQUIRE( get<0>(res) == Approx(sub_vec_res[0]) );
		REQUIRE( get<1>(res) == Approx(sub_vec_res[1]) );
		REQUIRE( get<2>(res) == Approx(sub_vec_res[2]) );
		REQUIRE( &res != &sub_var_1 ); //result must be a new resource
		REQUIRE( &res != &sub_var_2 ); //also different to sub_var_2
	}
	
	SECTION( "sub_mk (scalar)/1" )
	{
		auto res = sub_mk(sub_var_1, sub_scalar);
		REQUIRE( get<0>(res) == Approx(sub_scalar_res[0]) );
		REQUIRE( get<1>(res) == Approx(sub_scalar_res[1]) );
		REQUIRE( get<2>(res) == Approx(sub_scalar_res[2]) );
		REQUIRE( &res != &sub_var_1 ); //result must be a new resource
	}
	
	SECTION( "sub_set/1" )
	{
		sub_set(sub_var_1, sub_var_2);
		REQUIRE( get<0>(sub_var_1) == Approx(sub_vec_res[0]) );
		REQUIRE( get<1>(sub_var_1) == Approx(sub_vec_res[1]) );
		REQUIRE( get<2>(sub_var_1) == Approx(sub_vec_res[2]) );
	}
	
	SECTION( "sub_set (scalar)/1" )
	{
		sub_set(sub_var_1, sub_scalar);
		REQUIRE( get<0>(sub_var_1) == Approx(sub_scalar_res[0]) );
		REQUIRE( get<1>(sub_var_1) == Approx(sub_scalar_res[1]) );
		REQUIRE( get<2>(sub_var_1) == Approx(sub_scalar_res[2]) );
	}
	
	SECTION( "sub/1" )
	{
		auto &res = sub(sub_var_1, sub_var_2);
		REQUIRE( get<0>(res) == Approx(sub_vec_res[0]) );
		REQUIRE( get<1>(res) == Approx(sub_vec_res[1]) );
		REQUIRE( get<2>(res) == Approx(sub_vec_res[2]) );
		REQUIRE( &res == &sub_var_1 );//result must be sub_var_1
		REQUIRE( &res != &sub_var_2 );//but not sub_var_2
		auto &res2 = sub(res, sub_scalar);
		REQUIRE( get<0>(res2) == Approx(sub_vec_scalar_res[0]) );
		REQUIRE( get<1>(res2) == Approx(sub_vec_scalar_res[1]) );
		REQUIRE( get<2>(res2) == Approx(sub_vec_scalar_res[2]) );
		REQUIRE( &res2 == &sub_var_1 );//result must be sub_var_1
	}
	
	SECTION( "sub (scalar)/1" )
	{
		auto &res = sub(sub_var_1, sub_scalar);
		REQUIRE( get<0>(res) == Approx(sub_scalar_res[0]) );
		REQUIRE( get<1>(res) == Approx(sub_scalar_res[1]) );
		REQUIRE( get<2>(res) == Approx(sub_scalar_res[2]) );
		REQUIRE( &res == &sub_var_1 );//result must be sub_var_1
		auto &res2 = sub(res, sub_var_2);
		REQUIRE( get<0>(res2) == Approx(sub_vec_scalar_res[0]) );
		REQUIRE( get<1>(res2) == Approx(sub_vec_scalar_res[1]) );
		REQUIRE( get<2>(res2) == Approx(sub_vec_scalar_res[2]) );
		REQUIRE( &res2 == &sub_var_1 );//result must be sub_var_1
	}
	
	SECTION( "mul_mk/1" )
	{
		auto res = mul_mk(mul_var_1, mul_var_2);
		REQUIRE( get<0>(res) == Approx(mul_vec_res[0]) );
		REQUIRE( get<1>(res) == Approx(mul_vec_res[1]) );
		REQUIRE( get<2>(res) == Approx(mul_vec_res[2]) );
		REQUIRE( &res != &mul_var_1 ); //result must be a new resource
		REQUIRE( &res != &mul_var_2 ); //also different to mul_var_2
	}
	
	SECTION( "mul_mk (scalar)/1" )
	{
		auto res = mul_mk(mul_var_1, mul_scalar);
		REQUIRE( get<0>(res) == Approx(mul_scalar_res[0]) );
		REQUIRE( get<1>(res) == Approx(mul_scalar_res[1]) );
		REQUIRE( get<2>(res) == Approx(mul_scalar_res[2]) );
		REQUIRE( &res != &mul_var_1 ); //result must be a new resource
	}
	
	SECTION( "mul_set/1" )
	{
		mul_set(mul_var_1, mul_var_2);
		REQUIRE( get<0>(mul_var_1) == Approx(mul_vec_res[0]) );
		REQUIRE( get<1>(mul_var_1) == Approx(mul_vec_res[1]) );
		REQUIRE( get<2>(mul_var_1) == Approx(mul_vec_res[2]) );
	}
	
	SECTION( "mul_set (scalar)/1" )
	{
		mul_set(mul_var_1, mul_scalar);
		REQUIRE( get<0>(mul_var_1) == Approx(mul_scalar_res[0]) );
		REQUIRE( get<1>(mul_var_1) == Approx(mul_scalar_res[1]) );
		REQUIRE( get<2>(mul_var_1) == Approx(mul_scalar_res[2]) );
	}
	
	SECTION( "mul/1" )
	{
		auto &res = mul(mul_var_1, mul_var_2);
		REQUIRE( get<0>(res) == Approx(mul_vec_res[0]) );
		REQUIRE( get<1>(res) == Approx(mul_vec_res[1]) );
		REQUIRE( get<2>(res) == Approx(mul_vec_res[2]) );
		REQUIRE( &res == &mul_var_1 );//result must be mul_var_1
		REQUIRE( &res != &mul_var_2 );//but not mul_var_2
		auto &res2 = mul(res, mul_scalar);
		REQUIRE( get<0>(res2) == Approx(mul_vec_scalar_res[0]) );
		REQUIRE( get<1>(res2) == Approx(mul_vec_scalar_res[1]) );
		REQUIRE( get<2>(res2) == Approx(mul_vec_scalar_res[2]) );
		REQUIRE( &res2 == &mul_var_1 );//result must be mul_var_1
	}
	
	SECTION( "mul (scalar)/1" )
	{
		auto &res = mul(mul_var_1, mul_scalar);
		REQUIRE( get<0>(res) == Approx(mul_scalar_res[0]) );
		REQUIRE( get<1>(res) == Approx(mul_scalar_res[1]) );
		REQUIRE( get<2>(res) == Approx(mul_scalar_res[2]) );
		REQUIRE( &res == &mul_var_1 );//result must be mul_var_1
		auto &res2 = mul(res, mul_var_2);
		REQUIRE( get<0>(res2) == Approx(mul_vec_scalar_res[0]) );
		REQUIRE( get<1>(res2) == Approx(mul_vec_scalar_res[1]) );
		REQUIRE( get<2>(res2) == Approx(mul_vec_scalar_res[2]) );
		REQUIRE( &res2 == &mul_var_1 );//result must be mul_var_1
	}
	
	SECTION( "div_mk/1" )
	{
		auto res = div_mk(div_var_1, div_var_2);
		REQUIRE( get<0>(res) == Approx(div_vec_res[0]) );
		REQUIRE( get<1>(res) == Approx(div_vec_res[1]) );
		REQUIRE( get<2>(res) == Approx(div_vec_res[2]) );
		REQUIRE( &res != &div_var_1 ); //result must be a new resource
		REQUIRE( &res != &div_var_2 ); //also different to div_var_2
	}
	
	SECTION( "div_mk (scalar)/1" )
	{
		auto res = div_mk(div_var_1, div_scalar);
		REQUIRE( get<0>(res) == Approx(div_scalar_res[0]) );
		REQUIRE( get<1>(res) == Approx(div_scalar_res[1]) );
		REQUIRE( get<2>(res) == Approx(div_scalar_res[2]) );
		REQUIRE( &res != &div_var_1 ); //result must be a new resource
	}
	
	SECTION( "div_set/1" )
	{
		div_set(div_var_1, div_var_2);
		REQUIRE( get<0>(div_var_1) == Approx(div_vec_res[0]) );
		REQUIRE( get<1>(div_var_1) == Approx(div_vec_res[1]) );
		REQUIRE( get<2>(div_var_1) == Approx(div_vec_res[2]) );
	}
	
	SECTION( "div_set (scalar)/1" )
	{
		div_set(div_var_1, div_scalar);
		REQUIRE( get<0>(div_var_1) == Approx(div_scalar_res[0]) );
		REQUIRE( get<1>(div_var_1) == Approx(div_scalar_res[1]) );
		REQUIRE( get<2>(div_var_1) == Approx(div_scalar_res[2]) );
	}
	
	SECTION( "div/1" )
	{
		auto &res = div(div_var_1, div_var_2);
		REQUIRE( get<0>(res) == Approx(div_vec_res[0]) );
		REQUIRE( get<1>(res) == Approx(div_vec_res[1]) );
		REQUIRE( get<2>(res) == Approx(div_vec_res[2]) );
		REQUIRE( &res == &div_var_1 );//result must be div_var_1
		REQUIRE( &res != &div_var_2 );//but not div_var_2
		auto &res2 = div(res, div_scalar);
		REQUIRE( get<0>(res2) == Approx(div_vec_scalar_res[0]) );
		REQUIRE( get<1>(res2) == Approx(div_vec_scalar_res[1]) );
		REQUIRE( get<2>(res2) == Approx(div_vec_scalar_res[2]) );
		REQUIRE( &res2 == &div_var_1 );//result must be div_var_1
	}
	
	SECTION( "div (scalar)/1" )
	{
		auto &res = div(div_var_1, div_scalar);
		REQUIRE( get<0>(res) == Approx(div_scalar_res[0]) );
		REQUIRE( get<1>(res) == Approx(div_scalar_res[1]) );
		REQUIRE( get<2>(res) == Approx(div_scalar_res[2]) );
		REQUIRE( &res == &div_var_1 );//result must be div_var_1
		auto &res2 = div(res, div_var_2);
		REQUIRE( get<0>(res2) == Approx(div_vec_scalar_res[0]) );
		REQUIRE( get<1>(res2) == Approx(div_vec_scalar_res[1]) );
		REQUIRE( get<2>(res2) == Approx(div_vec_scalar_res[2]) );
		REQUIRE( &res2 == &div_var_1 );//result must be div_var_1
	}
	
}
TEST_CASE( "3 | General purpos functions for 3 component vectors", "[vec3<float>(3)]" )
{
	SECTION( "Dot product/1" )
	{
		
	}
	
}
