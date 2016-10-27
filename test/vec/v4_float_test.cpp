#include "../../ext/catch/catch.hpp"
#include "../../inc/avl.h"

using namespace avl;

TEST_CASE( "Helper functions/4", "[vec4<float>(4)]" )
{
	SECTION( "Component type helper/1" )
	{
		const vec4<float> vec = { 0, 0, 0, 0 };
		static_assert(eq< decltype( vec[0] ), decltype( cmp(vec) ) >::value, "Supply a scalar of the vectors element type.");
	}
	
}
TEST_CASE( "Getters and setters for all vectors/4", "[vec4<float>(4)]" )
{
	SECTION( "Access the vector components by a range checked index from 0 to dim-1/1" )
	{
		const vec4<float> vec = { 0, 1, 2, 3 };
		
		REQUIRE( get(vec, 0) == Approx( 0 ) );
		REQUIRE( get(vec, 1) == Approx( 1 ) );
		REQUIRE( get(vec, 2) == Approx( 2 ) );
		REQUIRE( get(vec, 3) == Approx( 3 ) );
	}
	
	SECTION( "Access the vector components by a static range checked index from 0 to dim-1/1" )
	{
		const vec4<float> vec = { 0, 1, 2, 3 };
		
		REQUIRE( get<0>(vec) == Approx( 0 ) );
		REQUIRE( get<1>(vec) == Approx( 1 ) );
		REQUIRE( get<2>(vec) == Approx( 2 ) );
		REQUIRE( get<3>(vec) == Approx( 3 ) );
	}
	
	SECTION( "Set a single component by index from 0 to dim-1/1" )
	{
		vec4<float> vec = { 0, 0, 0, 0 };
		const float arr [] = { 1.285, -91.230, -7.666, 64.986 };
		
		set(vec, 0, arr[0]);
		REQUIRE( get(vec, 0) == Approx( arr[0] ) );
		set(vec, 1, arr[1]);
		REQUIRE( get(vec, 1) == Approx( arr[1] ) );
		set(vec, 2, arr[2]);
		REQUIRE( get(vec, 2) == Approx( arr[2] ) );
		set(vec, 3, arr[3]);
		REQUIRE( get(vec, 3) == Approx( arr[3] ) );
	}
	
	SECTION( "Set a single component by static index from 0 to dim-1/1" )
	{
		vec4<float> vec = { 0, 1, 2, 3 };
		const float arr [] = { -43.384, 74.225, 27.629, 69.916 };
		
		set<0>(vec, arr[ 0 ]);
		REQUIRE( get<0>(vec) == Approx( arr[0] ) );
		set<1>(vec, arr[ 1 ]);
		REQUIRE( get<1>(vec) == Approx( arr[1] ) );
		set<2>(vec, arr[ 2 ]);
		REQUIRE( get<2>(vec) == Approx( arr[2] ) );
		set<3>(vec, arr[ 3 ]);
		REQUIRE( get<3>(vec) == Approx( arr[3] ) );
	}
	
}
TEST_CASE( "Vector length operations/4", "[vec4<float>(4)]" )
{
	SECTION( "Returns a new vector with the requested length/1" )
	{
		const vec4<float> vec = { 65.982, -12.719, 13.388, 8.611 };
		const float len_to_set = { 44.171 };
		const auto new_vec = setlen_mk(vec, len_to_set);
		const auto len_new_vec = len(new_vec);
		
		REQUIRE( len_new_vec == Approx(len_to_set) );
		
		//test edge case 0.0
		const auto zero_len_vec = setlen_mk(vec, cnst<float>::zero);
		REQUIRE( get<0>(zero_len_vec) == Approx( cnst<float>::zero ) );
		REQUIRE( get<1>(zero_len_vec) == Approx( cnst<float>::zero ) );
		REQUIRE( get<2>(zero_len_vec) == Approx( cnst<float>::zero ) );
		REQUIRE( get<3>(zero_len_vec) == Approx( cnst<float>::zero ) );
	}
	
	SECTION( "Set the length of the vector/1" )
	{
		vec4<float> vec = { 17.159, -30.164, -58.525, -63.254 };
		const float len_to_set = { 97.805 };
		setlen_set(vec, len_to_set);
		const auto vec_len = len(vec);
		
		REQUIRE( vec_len == Approx(len_to_set) );
		
		//test edge case 0.0
		setlen_set(vec, cnst<float>::zero);
		
		REQUIRE( get<0>(vec) == Approx( cnst<float>::zero ) );
		REQUIRE( get<1>(vec) == Approx( cnst<float>::zero ) );
		REQUIRE( get<2>(vec) == Approx( cnst<float>::zero ) );
		REQUIRE( get<3>(vec) == Approx( cnst<float>::zero ) );
	}
	
	SECTION( "Set the length of the vector and return the same vector (chained)/1" )
	{
		vec4<float> vec = { -2.498, -89.937, 83.113, 76.661 };
		const float len_to_set = { 54.562 };
		const auto &ret_vec = setlen(vec, len_to_set);
		const auto vec_len = len(vec);
		
		REQUIRE( vec_len == Approx(len_to_set) );
		
		REQUIRE( &vec == &ret_vec);
		//test edge case 0.0
		const auto &ret_zero_vec = setlen(vec, cnst<float>::zero);
		
		REQUIRE( get<0>(vec) == Approx( cnst<float>::zero ) );
		REQUIRE( get<1>(vec) == Approx( cnst<float>::zero ) );
		REQUIRE( get<2>(vec) == Approx( cnst<float>::zero ) );
		REQUIRE( get<3>(vec) == Approx( cnst<float>::zero ) );
		REQUIRE( &vec == &ret_zero_vec);
	}
	
	SECTION( "Calculate the length of the vector, prefere len_sqr when comparing distances/1" )
	{
		const vec4<float> vec = { 89.966, 0.972, 79.548, 60.731 };
		const auto vec_len = len(vec);
		const auto vec_square_len = get<0>(vec) * get<0>(vec) + get<1>(vec) * get<1>(vec) + get<2>(vec) * get<2>(vec) + get<3>(vec) * get<3>(vec);
		REQUIRE( vec_len == Approx( s::sqrt( vec_square_len ) ) );
		
		//test edge case 0.0
		const vec4<float> zero_vec = { 0, 0, 0, 0 };
		const auto zero_vec_len = len(zero_vec);
		REQUIRE( zero_vec_len == Approx( cnst<float>::zero ) );
	}
	
	SECTION( "Calculate the square length of the vector/1" )
	{
		const vec4<float> vec = { 84.250, 80.794, 15.910, -56.508 };
		const auto vec_len_sqr = len_sqr(vec);
		const auto vec_len_sqr_check = get<0>(vec) * get<0>(vec) + get<1>(vec) * get<1>(vec) + get<2>(vec) * get<2>(vec) + get<3>(vec) * get<3>(vec);
		REQUIRE( vec_len_sqr == Approx( vec_len_sqr_check ) );
		
		//test edge case 0.0
		const vec4<float> zero_vec = { 0, 0, 0, 0 };
		const auto zero_vec_len_sqr = len_sqr(zero_vec);
		REQUIRE( zero_vec_len_sqr == Approx( cnst<float>::zero ) );
	}
	
	SECTION( "Returns a normalized vector/1" )
	{
		
		const vec4<float> vec = { 42.835, 91.443, -80.435, 49.484 };
		const auto new_norm_vec = norm_mk(vec);
		const auto norm_len = len(new_norm_vec);
		REQUIRE( norm_len == Approx( cnst<float>::one ) );
	}
	
	SECTION( "Returns a normalized vector, use alternative vector if the current vector length is 0/1" )
	{
		const vec4<float> zero_vec = { 0, 0, 0, 0 };
		const auto zero_len = len(zero_vec);
		REQUIRE( zero_len == Approx( cnst<float>::zero ) );
		
		vec4<float> unit_vec = { 0, 0, 0, 0 };
		set<0>(unit_vec, cnst<float>::one);
		
		const auto new_unit_vec = norm_mk(zero_vec, unit_vec);
		const auto new_unit_vec_len = len(new_unit_vec);
		REQUIRE( new_unit_vec_len == Approx( cnst<float>::one ) );
		REQUIRE( get<0>(new_unit_vec) == Approx( cnst<float>::one ) );
	}
	
	SECTION( "Normalize the current vector/1" )
	{
		vec4<float> vec = { -66.180, -81.802, -22.158, -9.729 };
		norm_set(vec);
		const auto len_of_norm_vec = len(vec);
		REQUIRE( len_of_norm_vec == Approx( cnst<float>::one ) );
	}
	
	SECTION( "Normalize the current vector, use alternative vector if the current vector length is 0/1" )
	{
		vec4<float> vec = { 0, 0, 0, 0 };
		const auto zero_len = len(vec);
		REQUIRE( zero_len == Approx( cnst<float>::zero ) );
		
		vec4<float> unit_vec = { 0, 0, 0, 0 };
		set<0>(unit_vec, cnst<float>::one);
		
		norm_set(vec, unit_vec);
		const auto vec_len = len(vec);
		REQUIRE( vec_len == Approx( cnst<float>::one ) );
		REQUIRE( get<0>(vec) == Approx( cnst<float>::one ) );
	}
	
	SECTION( "Normalize the current vector and return the same vector (chained)/1" )
	{
		vec4<float> vec = { 77.540, 8.166, 77.828, -17.454 };
		const auto &ret_vec = norm(vec);
		const auto len_of_norm_vec = len(vec);
		REQUIRE( len_of_norm_vec == Approx( cnst<float>::one ) );
		REQUIRE( &vec == &ret_vec);
	}
	
	SECTION( "Normalize the current vector and return the same vector (chained), use alternative vector if the current vector length is 0/1" )
	{
		vec4<float> vec = { 0, 0, 0, 0 };
		const auto zero_len = len(vec);
		REQUIRE( zero_len == Approx( cnst<float>::zero ) );
		
		vec4<float> unit_vec = { 0, 0, 0, 0 };
		set<0>(unit_vec, cnst<float>::one);
		
		const auto &ret_vec = norm(vec, unit_vec);
		const auto vec_len = len(vec);
		REQUIRE( vec_len == Approx( cnst<float>::one ) );
		REQUIRE( get<0>(vec) == Approx( cnst<float>::one ) );
		REQUIRE( &vec == &ret_vec);
	}
	
}
TEST_CASE( "Spacial operations/4", "[vec4<float>(4)]" )
{
	SECTION( "Calculate the angle between two vectors in radian/1" )
	{
		const float random_len1 = { 86.022 };
		const float random_len2 = { 2.399 };
		const float random_len3 = { 83.996 };
		const float random_len4 = { 5.982 };
		
		vec4<float> vec_zero = { 0, 0, 0, 0 };
		vec4<float> vec_10x = { 0, 0, 0, 0 };
		set<0>(vec_10x, random_len1);
		vec4<float> vec_01x = { 0, 0, 0, 0 };
		set<1>(vec_01x, random_len2);
		vec4<float> vec_m10x = { 0, 0, 0, 0 };
		set<0>(vec_m10x, -random_len3);
		vec4<float> vec_11x = { 0, 0, 0, 0 };
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
		const float random_len1 = { 14.506 };
		const float random_len2 = { 64.685 };
		const float random_len3 = { 97.796 };
		const float random_len4 = { 83.889 };
		
		vec4<float> vec_zero = { 0, 0, 0, 0 };
		vec4<float> vec_010x = { 0, 0, 0, 0 };
		set<1>(vec_010x, random_len1);
		vec4<float> vec_001x = { 0, 0, 0, 0 };
		set<2>(vec_001x, random_len2);
		vec4<float> vec_0m10x = { 0, 0, 0, 0 };
		set<1>(vec_0m10x, -random_len3);
		vec4<float> vec_011x = { 0, 0, 0, 0 };
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
	
	SECTION( "Calculate the angle between two vectors in radian/3" )
	{
		const float random_len1 = { 76.174 };
		const float random_len2 = { 87.059 };
		const float random_len3 = { 91.527 };
		const float random_len4 = { 46.72 };
		
		vec4<float> vec_zero = { 0, 0, 0, 0 };
		vec4<float> vec_0010 = { 0, 0, 0, 0 };
		set<2>(vec_0010, random_len1);
		vec4<float> vec_0001 = { 0, 0, 0, 0 };
		set<3>(vec_0001, random_len2);
		vec4<float> vec_00m10 = { 0, 0, 0, 0 };
		set<2>(vec_00m10, -random_len3);
		vec4<float> vec_0011 = { 0, 0, 0, 0 };
		set<2>(vec_0011, random_len4);
		set<3>(vec_0011, random_len4);
		
		const auto angle0 = angle_rd(vec_0010, vec_0010);
		REQUIRE( angle0 == Approx( cnst<float>::zero ) );
		
		const auto angle90 = angle_rd(vec_0010, vec_0001);
		REQUIRE( angle90 == Approx( 1.57079632679 ) );
		
		const auto angle45a = angle_rd(vec_0010, vec_0011);
		REQUIRE( angle45a == Approx( 0.785398163396 ) );
		const auto angle45b = angle_rd(vec_0001, vec_0011);
		REQUIRE( angle45b == Approx( 0.785398163396 ) );
		
		const auto angle135 = angle_rd(vec_00m10, vec_0011);
		REQUIRE( angle135 == Approx( 2.35619449019 ) );
		
		const auto angle180 = angle_rd(vec_0010, vec_00m10);
		REQUIRE( angle180 == Approx( 3.14159265358 ) );
	}
	
	SECTION( "Calculate the angle between two vectors in degree/1" )
	{
		const float random_len1 = { 39.516 };
		const float random_len2 = { 5.022 };
		const float random_len3 = { 55.346 };
		const float random_len4 = { 64.931 };
		
		vec4<float> vec_zero = { 0, 0, 0, 0 };
		vec4<float> vec_10x = { 0, 0, 0, 0 };
		set<0>(vec_10x, random_len1);
		vec4<float> vec_01x = { 0, 0, 0, 0 };
		set<1>(vec_01x, random_len2);
		vec4<float> vec_m10x = { 0, 0, 0, 0 };
		set<0>(vec_m10x, -random_len3);
		vec4<float> vec_11x = { 0, 0, 0, 0 };
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
		const float random_len1 = { 71.991 };
		const float random_len2 = { 18.044 };
		const float random_len3 = { 30.556 };
		const float random_len4 = { 30.752 };
		
		vec4<float> vec_zero = { 0, 0, 0, 0 };
		vec4<float> vec_010x = { 0, 0, 0, 0 };
		set<1>(vec_010x, random_len1);
		vec4<float> vec_001x = { 0, 0, 0, 0 };
		set<2>(vec_001x, random_len2);
		vec4<float> vec_0m10x = { 0, 0, 0, 0 };
		set<1>(vec_0m10x, -random_len3);
		vec4<float> vec_011x = { 0, 0, 0, 0 };
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
	
	SECTION( "Calculate the angle between two vectors in degree/3" )
	{
		const float random_len1 = { 44.111 };
		const float random_len2 = { 87.757 };
		const float random_len3 = { 31.643 };
		const float random_len4 = { 20.87 };
		
		vec4<float> vec_zero = { 0, 0, 0, 0 };
		vec4<float> vec_0010 = { 0, 0, 0, 0 };
		set<2>(vec_0010, random_len1);
		vec4<float> vec_0001 = { 0, 0, 0, 0 };
		set<3>(vec_0001, random_len2);
		vec4<float> vec_00m10 = { 0, 0, 0, 0 };
		set<2>(vec_00m10, -random_len3);
		vec4<float> vec_0011 = { 0, 0, 0, 0 };
		set<2>(vec_0011, random_len4);
		set<3>(vec_0011, random_len4);
		
		const auto angle0 = angle_dg(vec_0010, vec_0010);
		REQUIRE( angle0 == Approx( cnst<float>::zero ) );
		
		const auto angle90 = angle_dg(vec_0010, vec_0001);
		REQUIRE( angle90 == Approx( 90 ) );
		
		const auto angle45a = angle_dg(vec_0010, vec_0011);
		REQUIRE( angle45a == Approx( 45 ) );
		const auto angle45b = angle_dg(vec_0001, vec_0011);
		REQUIRE( angle45b == Approx( 45 ) );
		
		const auto angle135 = angle_dg(vec_00m10, vec_0011);
		REQUIRE( angle135 == Approx( 135 ) );
		
		const auto angle180 = angle_dg(vec_0010, vec_00m10);
		REQUIRE( angle180 == Approx( 180 ) );
	}
	
	SECTION( "Calculate the area of the spawned triangle (restricted to 3 dimensions)/1" )
	{
		vec4<float> vec_0 = { 0, 0, 0, 0 };
		vec4<float> vec_1 = { 0, 0, 0, 0 };
		vec4<float> vec_2 = { 0, 0, 0, 0 };
		set<0>(vec_0, cnst<float>::one);
		set<1>(vec_1, cnst<float>::one);
		set<0>(vec_2, cnst<float>::minus_one);
		
		const auto a0 = area3(vec_0, vec_1);
		REQUIRE( a0 == cnst<float>::half );
		
		const auto a1 = area3(vec_0, vec_0);
		REQUIRE( a1 == cnst<float>::zero );
		
		const auto a2 = area3(vec_0, vec_2);
		REQUIRE( a2 == cnst<float>::zero );
	}
	
	SECTION( "Calculate the cross product (restricted to 3 dimensions)/1" )
	{
		vec4<float> vec_100x = { 0, 0, 0, 0 };
		vec4<float> vec_100x_dup = { 0, 0, 0, 0 };
		vec4<float> vec_010x = { 0, 0, 0, 0 };
		vec4<float> expected_res1 = { 0, 0, 0, 0 };
		vec4<float> expected_res2 = { 0, 0, 0, 0 };
		set<0>(vec_100x, cnst<float>::one);
		set<0>(vec_100x_dup, cnst<float>::one);
		set<1>(vec_010x, cnst<float>::one);
		set<2>(expected_res1, cnst<float>::one);
		set<2>(expected_res2, cnst<float>::minus_one);
		
		auto result1 = cross3_mk(vec_100x, vec_010x);
		auto result2 = cross3_mk(vec_010x, vec_100x_dup);
		REQUIRE( get<0>(result1) == Approx( get<0>(expected_res1) ) );
		REQUIRE( get<1>(result1) == Approx( get<1>(expected_res1) ) );
		REQUIRE( get<2>(result1) == Approx( get<2>(expected_res1) ) );
		REQUIRE( get<3>(result1) == Approx( get<3>(expected_res1) ) );
		REQUIRE( get<0>(result2) == Approx( get<0>(expected_res2) ) );
		REQUIRE( get<1>(result2) == Approx( get<1>(expected_res2) ) );
		REQUIRE( get<2>(result2) == Approx( get<2>(expected_res2) ) );
		REQUIRE( get<3>(result2) == Approx( get<3>(expected_res2) ) );
	}
	
	SECTION( "Calculate the cross product (restricted to 3 dimensions)/1" )
	{
		vec4<float> vec_100x = { 0, 0, 0, 0 };
		vec4<float> vec_100x_dup = { 0, 0, 0, 0 };
		vec4<float> vec_010x = { 0, 0, 0, 0 };
		vec4<float> expected_res1 = { 0, 0, 0, 0 };
		vec4<float> expected_res2 = { 0, 0, 0, 0 };
		set<0>(vec_100x, cnst<float>::one);
		set<0>(vec_100x_dup, cnst<float>::one);
		set<1>(vec_010x, cnst<float>::one);
		set<2>(expected_res1, cnst<float>::one);
		set<2>(expected_res2, cnst<float>::minus_one);
		
		cross3_set(vec_100x, vec_010x);
		cross3_set(vec_010x, vec_100x_dup);
		REQUIRE( get<0>(vec_100x) == Approx( get<0>(expected_res1) ) );
		REQUIRE( get<1>(vec_100x) == Approx( get<1>(expected_res1) ) );
		REQUIRE( get<2>(vec_100x) == Approx( get<2>(expected_res1) ) );
		REQUIRE( get<3>(vec_100x) == Approx( get<3>(expected_res1) ) );
		REQUIRE( get<0>(vec_010x) == Approx( get<0>(expected_res2) ) );
		REQUIRE( get<1>(vec_010x) == Approx( get<1>(expected_res2) ) );
		REQUIRE( get<2>(vec_010x) == Approx( get<2>(expected_res2) ) );
		REQUIRE( get<3>(vec_010x) == Approx( get<3>(expected_res2) ) );
	}
	
	SECTION( "Calculate the cross product (restricted to 3 dimensions)/1" )
	{
		vec4<float> vec_100x = { 0, 0, 0, 0 };
		vec4<float> vec_100x_dup = { 0, 0, 0, 0 };
		vec4<float> vec_010x = { 0, 0, 0, 0 };
		vec4<float> expected_res1 = { 0, 0, 0, 0 };
		vec4<float> expected_res2 = { 0, 0, 0, 0 };
		set<0>(vec_100x, cnst<float>::one);
		set<0>(vec_100x_dup, cnst<float>::one);
		set<1>(vec_010x, cnst<float>::one);
		set<2>(expected_res1, cnst<float>::one);
		set<2>(expected_res2, cnst<float>::minus_one);
		
		auto &result1 = cross3(vec_100x, vec_010x);
		auto &result2 = cross3(vec_010x, vec_100x_dup);
		REQUIRE( get<0>(result1) == Approx( get<0>(expected_res1) ) );
		REQUIRE( get<1>(result1) == Approx( get<1>(expected_res1) ) );
		REQUIRE( get<2>(result1) == Approx( get<2>(expected_res1) ) );
		REQUIRE( get<3>(result1) == Approx( get<3>(expected_res1) ) );
		REQUIRE( get<0>(result2) == Approx( get<0>(expected_res2) ) );
		REQUIRE( get<1>(result2) == Approx( get<1>(expected_res2) ) );
		REQUIRE( get<2>(result2) == Approx( get<2>(expected_res2) ) );
		REQUIRE( get<3>(result2) == Approx( get<3>(expected_res2) ) );
	}
	
}
TEST_CASE( "Getter and setters for 4 component vectors/4", "[vec4<float>(4)]" )
{
	SECTION( "Set all vector components to the same scalar/1" )
	{
		vec4<float> vec = { 0, 0, 0, 0 };
		
		const float val = { 99.803 };
		
		set_all(vec, val);
		
		REQUIRE( get<0>(vec)==val );
		REQUIRE( get<1>(vec)==val );
		REQUIRE( get<2>(vec)==val );
		REQUIRE( get<3>(vec)==val );
	}
	
	SECTION( "Set all vector components individually/1" )
	{
		vec4<float> vec = { 0, 0, 0, 0 };
		const float arr [] = { 15.063, 91.631, 95.936, 79.751 };
		
		set_all(vec,arr[0], arr[1], arr[2], arr[3]);
		
		REQUIRE( get<0>(vec)==arr[0] );
		REQUIRE( get<1>(vec)==arr[1] );
		REQUIRE( get<2>(vec)==arr[2] );
		REQUIRE( get<3>(vec)==arr[3] );
	}
	
	SECTION( "Set all vector components individually by a fixed size array/1" )
	{
		vec4<float> vec = { 0, 0, 0, 0 };
		const float arr [] = { 32.164, -98.242, -47.634, 11.530 };
		
		set_all(vec, arr);
		
		REQUIRE( get<0>(vec)==arr[0] );
		REQUIRE( get<1>(vec)==arr[1] );
		REQUIRE( get<2>(vec)==arr[2] );
		REQUIRE( get<3>(vec)==arr[3] );
	}
	
	SECTION( "Set all vector components individually by an array/1" )
	{
		vec4<float> vec = { 0, 0, 0, 0 };
		const float arr [] = { -23.339, -20.869, -42.571, -66.230 };
		const auto* ptr_to_arr = arr;
		
		set_all<4>(vec, ptr_to_arr);
		
		REQUIRE( get<0>(vec)==arr[0] );
		REQUIRE( get<1>(vec)==arr[1] );
		REQUIRE( get<2>(vec)==arr[2] );
		REQUIRE( get<3>(vec)==arr[3] );
	}
	
}
TEST_CASE( "General vector operations for 4 component vectors/4", "[vec4<float>(4)]" )
{
	vec4<float> add_var_1 = { 96.213, 63.923, -29.223, 83.438 };
	vec4<float> add_var_2 = { -89.235, 64.109, -5.500, -59.844 };
	const float add_scalar = { -71.993 };
	
	const float add_vec_res [] =
		{ get<0>(add_var_1) + get<0>(add_var_2), get<1>(add_var_1) + get<1>(add_var_2), get<2>(add_var_1) + get<2>(add_var_2), get<3>(add_var_1) + get<3>(add_var_2) };
	const float add_scalar_res [] =
		{ get<0>(add_var_1) + add_scalar, get<1>(add_var_1) + add_scalar, get<2>(add_var_1) + add_scalar, get<3>(add_var_1) + add_scalar };
	const float add_vec_scalar_res [] =
		{ get<0>(add_var_1) + get<0>(add_var_2) + add_scalar, get<1>(add_var_1) + get<1>(add_var_2) + add_scalar, get<2>(add_var_1) + get<2>(add_var_2) + add_scalar, get<3>(add_var_1) + get<3>(add_var_2) + add_scalar };
	
	vec4<float> sub_var_1 = { 35.807, 23.679, -44.516, -17.864 };
	vec4<float> sub_var_2 = { -55.271, 54.458, 53.365, -77.151 };
	const float sub_scalar = { 9.297 };
	
	const float sub_vec_res [] =
		{ get<0>(sub_var_1) - get<0>(sub_var_2), get<1>(sub_var_1) - get<1>(sub_var_2), get<2>(sub_var_1) - get<2>(sub_var_2), get<3>(sub_var_1) - get<3>(sub_var_2) };
	const float sub_scalar_res [] =
		{ get<0>(sub_var_1) - sub_scalar, get<1>(sub_var_1) - sub_scalar, get<2>(sub_var_1) - sub_scalar, get<3>(sub_var_1) - sub_scalar };
	const float sub_vec_scalar_res [] =
		{ get<0>(sub_var_1) - get<0>(sub_var_2) - sub_scalar, get<1>(sub_var_1) - get<1>(sub_var_2) - sub_scalar, get<2>(sub_var_1) - get<2>(sub_var_2) - sub_scalar, get<3>(sub_var_1) - get<3>(sub_var_2) - sub_scalar };
	
	vec4<float> mul_var_1 = { 68.259, 31.885, 1.285, -91.230 };
	vec4<float> mul_var_2 = { -7.666, 64.986, -43.384, 74.225 };
	const float mul_scalar = { 27.629 };
	
	const float mul_vec_res [] =
		{ get<0>(mul_var_1) * get<0>(mul_var_2), get<1>(mul_var_1) * get<1>(mul_var_2), get<2>(mul_var_1) * get<2>(mul_var_2), get<3>(mul_var_1) * get<3>(mul_var_2) };
	const float mul_scalar_res [] =
		{ get<0>(mul_var_1) * mul_scalar, get<1>(mul_var_1) * mul_scalar, get<2>(mul_var_1) * mul_scalar, get<3>(mul_var_1) * mul_scalar };
	const float mul_vec_scalar_res [] =
		{ get<0>(mul_var_1) * get<0>(mul_var_2) * mul_scalar, get<1>(mul_var_1) * get<1>(mul_var_2) * mul_scalar, get<2>(mul_var_1) * get<2>(mul_var_2) * mul_scalar, get<3>(mul_var_1) * get<3>(mul_var_2) * mul_scalar };
	
	vec4<float> div_var_1 = { 69.916, 65.982, -12.719, 13.388 };
	vec4<float> div_var_2 = { 8.611, -44.171, 17.159, -30.164 };
	const float div_scalar = { -58.525 };
	
	const float div_vec_res [] =
		{ get<0>(div_var_1) / get<0>(div_var_2), get<1>(div_var_1) / get<1>(div_var_2), get<2>(div_var_1) / get<2>(div_var_2), get<3>(div_var_1) / get<3>(div_var_2) };
	const float div_scalar_res [] =
		{ get<0>(div_var_1) / div_scalar, get<1>(div_var_1) / div_scalar, get<2>(div_var_1) / div_scalar, get<3>(div_var_1) / div_scalar };
	const float div_vec_scalar_res [] =
		{ get<0>(div_var_1) / get<0>(div_var_2) / div_scalar, get<1>(div_var_1) / get<1>(div_var_2) / div_scalar, get<2>(div_var_1) / get<2>(div_var_2) / div_scalar, get<3>(div_var_1) / get<3>(div_var_2) / div_scalar };
	
	SECTION( "add_mk/1" )
	{
		auto res = add_mk(add_var_1, add_var_2);
		REQUIRE( get<0>(res) == Approx(add_vec_res[0]) );
		REQUIRE( get<1>(res) == Approx(add_vec_res[1]) );
		REQUIRE( get<2>(res) == Approx(add_vec_res[2]) );
		REQUIRE( get<3>(res) == Approx(add_vec_res[3]) );
		REQUIRE( &res != &add_var_1 ); //result must be a new resource
		REQUIRE( &res != &add_var_2 ); //also different to add_var_2
	}
	
	SECTION( "add_mk (scalar)/1" )
	{
		auto res = add_mk(add_var_1, add_scalar);
		REQUIRE( get<0>(res) == Approx(add_scalar_res[0]) );
		REQUIRE( get<1>(res) == Approx(add_scalar_res[1]) );
		REQUIRE( get<2>(res) == Approx(add_scalar_res[2]) );
		REQUIRE( get<3>(res) == Approx(add_scalar_res[3]) );
		REQUIRE( &res != &add_var_1 ); //result must be a new resource
	}
	
	SECTION( "add_set/1" )
	{
		add_set(add_var_1, add_var_2);
		REQUIRE( get<0>(add_var_1) == Approx(add_vec_res[0]) );
		REQUIRE( get<1>(add_var_1) == Approx(add_vec_res[1]) );
		REQUIRE( get<2>(add_var_1) == Approx(add_vec_res[2]) );
		REQUIRE( get<3>(add_var_1) == Approx(add_vec_res[3]) );
	}
	
	SECTION( "add_set (scalar)/1" )
	{
		add_set(add_var_1, add_scalar);
		REQUIRE( get<0>(add_var_1) == Approx(add_scalar_res[0]) );
		REQUIRE( get<1>(add_var_1) == Approx(add_scalar_res[1]) );
		REQUIRE( get<2>(add_var_1) == Approx(add_scalar_res[2]) );
		REQUIRE( get<3>(add_var_1) == Approx(add_scalar_res[3]) );
	}
	
	SECTION( "add/1" )
	{
		auto &res = add(add_var_1, add_var_2);
		REQUIRE( get<0>(res) == Approx(add_vec_res[0]) );
		REQUIRE( get<1>(res) == Approx(add_vec_res[1]) );
		REQUIRE( get<2>(res) == Approx(add_vec_res[2]) );
		REQUIRE( get<3>(res) == Approx(add_vec_res[3]) );
		REQUIRE( &res == &add_var_1 );//result must be add_var_1
		REQUIRE( &res != &add_var_2 );//but not add_var_2
		auto &res2 = add(res, add_scalar);
		REQUIRE( get<0>(res2) == Approx(add_vec_scalar_res[0]) );
		REQUIRE( get<1>(res2) == Approx(add_vec_scalar_res[1]) );
		REQUIRE( get<2>(res2) == Approx(add_vec_scalar_res[2]) );
		REQUIRE( get<3>(res2) == Approx(add_vec_scalar_res[3]) );
		REQUIRE( &res2 == &add_var_1 );//result must be add_var_1
	}
	
	SECTION( "add (scalar)/1" )
	{
		auto &res = add(add_var_1, add_scalar);
		REQUIRE( get<0>(res) == Approx(add_scalar_res[0]) );
		REQUIRE( get<1>(res) == Approx(add_scalar_res[1]) );
		REQUIRE( get<2>(res) == Approx(add_scalar_res[2]) );
		REQUIRE( get<3>(res) == Approx(add_scalar_res[3]) );
		REQUIRE( &res == &add_var_1 );//result must be add_var_1
		auto &res2 = add(res, add_var_2);
		REQUIRE( get<0>(res2) == Approx(add_vec_scalar_res[0]) );
		REQUIRE( get<1>(res2) == Approx(add_vec_scalar_res[1]) );
		REQUIRE( get<2>(res2) == Approx(add_vec_scalar_res[2]) );
		REQUIRE( get<3>(res2) == Approx(add_vec_scalar_res[3]) );
		REQUIRE( &res2 == &add_var_1 );//result must be add_var_1
	}
	
	SECTION( "sub_mk/1" )
	{
		auto res = sub_mk(sub_var_1, sub_var_2);
		REQUIRE( get<0>(res) == Approx(sub_vec_res[0]) );
		REQUIRE( get<1>(res) == Approx(sub_vec_res[1]) );
		REQUIRE( get<2>(res) == Approx(sub_vec_res[2]) );
		REQUIRE( get<3>(res) == Approx(sub_vec_res[3]) );
		REQUIRE( &res != &sub_var_1 ); //result must be a new resource
		REQUIRE( &res != &sub_var_2 ); //also different to sub_var_2
	}
	
	SECTION( "sub_mk (scalar)/1" )
	{
		auto res = sub_mk(sub_var_1, sub_scalar);
		REQUIRE( get<0>(res) == Approx(sub_scalar_res[0]) );
		REQUIRE( get<1>(res) == Approx(sub_scalar_res[1]) );
		REQUIRE( get<2>(res) == Approx(sub_scalar_res[2]) );
		REQUIRE( get<3>(res) == Approx(sub_scalar_res[3]) );
		REQUIRE( &res != &sub_var_1 ); //result must be a new resource
	}
	
	SECTION( "sub_set/1" )
	{
		sub_set(sub_var_1, sub_var_2);
		REQUIRE( get<0>(sub_var_1) == Approx(sub_vec_res[0]) );
		REQUIRE( get<1>(sub_var_1) == Approx(sub_vec_res[1]) );
		REQUIRE( get<2>(sub_var_1) == Approx(sub_vec_res[2]) );
		REQUIRE( get<3>(sub_var_1) == Approx(sub_vec_res[3]) );
	}
	
	SECTION( "sub_set (scalar)/1" )
	{
		sub_set(sub_var_1, sub_scalar);
		REQUIRE( get<0>(sub_var_1) == Approx(sub_scalar_res[0]) );
		REQUIRE( get<1>(sub_var_1) == Approx(sub_scalar_res[1]) );
		REQUIRE( get<2>(sub_var_1) == Approx(sub_scalar_res[2]) );
		REQUIRE( get<3>(sub_var_1) == Approx(sub_scalar_res[3]) );
	}
	
	SECTION( "sub/1" )
	{
		auto &res = sub(sub_var_1, sub_var_2);
		REQUIRE( get<0>(res) == Approx(sub_vec_res[0]) );
		REQUIRE( get<1>(res) == Approx(sub_vec_res[1]) );
		REQUIRE( get<2>(res) == Approx(sub_vec_res[2]) );
		REQUIRE( get<3>(res) == Approx(sub_vec_res[3]) );
		REQUIRE( &res == &sub_var_1 );//result must be sub_var_1
		REQUIRE( &res != &sub_var_2 );//but not sub_var_2
		auto &res2 = sub(res, sub_scalar);
		REQUIRE( get<0>(res2) == Approx(sub_vec_scalar_res[0]) );
		REQUIRE( get<1>(res2) == Approx(sub_vec_scalar_res[1]) );
		REQUIRE( get<2>(res2) == Approx(sub_vec_scalar_res[2]) );
		REQUIRE( get<3>(res2) == Approx(sub_vec_scalar_res[3]) );
		REQUIRE( &res2 == &sub_var_1 );//result must be sub_var_1
	}
	
	SECTION( "sub (scalar)/1" )
	{
		auto &res = sub(sub_var_1, sub_scalar);
		REQUIRE( get<0>(res) == Approx(sub_scalar_res[0]) );
		REQUIRE( get<1>(res) == Approx(sub_scalar_res[1]) );
		REQUIRE( get<2>(res) == Approx(sub_scalar_res[2]) );
		REQUIRE( get<3>(res) == Approx(sub_scalar_res[3]) );
		REQUIRE( &res == &sub_var_1 );//result must be sub_var_1
		auto &res2 = sub(res, sub_var_2);
		REQUIRE( get<0>(res2) == Approx(sub_vec_scalar_res[0]) );
		REQUIRE( get<1>(res2) == Approx(sub_vec_scalar_res[1]) );
		REQUIRE( get<2>(res2) == Approx(sub_vec_scalar_res[2]) );
		REQUIRE( get<3>(res2) == Approx(sub_vec_scalar_res[3]) );
		REQUIRE( &res2 == &sub_var_1 );//result must be sub_var_1
	}
	
	SECTION( "mul_mk/1" )
	{
		auto res = mul_mk(mul_var_1, mul_var_2);
		REQUIRE( get<0>(res) == Approx(mul_vec_res[0]) );
		REQUIRE( get<1>(res) == Approx(mul_vec_res[1]) );
		REQUIRE( get<2>(res) == Approx(mul_vec_res[2]) );
		REQUIRE( get<3>(res) == Approx(mul_vec_res[3]) );
		REQUIRE( &res != &mul_var_1 ); //result must be a new resource
		REQUIRE( &res != &mul_var_2 ); //also different to mul_var_2
	}
	
	SECTION( "mul_mk (scalar)/1" )
	{
		auto res = mul_mk(mul_var_1, mul_scalar);
		REQUIRE( get<0>(res) == Approx(mul_scalar_res[0]) );
		REQUIRE( get<1>(res) == Approx(mul_scalar_res[1]) );
		REQUIRE( get<2>(res) == Approx(mul_scalar_res[2]) );
		REQUIRE( get<3>(res) == Approx(mul_scalar_res[3]) );
		REQUIRE( &res != &mul_var_1 ); //result must be a new resource
	}
	
	SECTION( "mul_set/1" )
	{
		mul_set(mul_var_1, mul_var_2);
		REQUIRE( get<0>(mul_var_1) == Approx(mul_vec_res[0]) );
		REQUIRE( get<1>(mul_var_1) == Approx(mul_vec_res[1]) );
		REQUIRE( get<2>(mul_var_1) == Approx(mul_vec_res[2]) );
		REQUIRE( get<3>(mul_var_1) == Approx(mul_vec_res[3]) );
	}
	
	SECTION( "mul_set (scalar)/1" )
	{
		mul_set(mul_var_1, mul_scalar);
		REQUIRE( get<0>(mul_var_1) == Approx(mul_scalar_res[0]) );
		REQUIRE( get<1>(mul_var_1) == Approx(mul_scalar_res[1]) );
		REQUIRE( get<2>(mul_var_1) == Approx(mul_scalar_res[2]) );
		REQUIRE( get<3>(mul_var_1) == Approx(mul_scalar_res[3]) );
	}
	
	SECTION( "mul/1" )
	{
		auto &res = mul(mul_var_1, mul_var_2);
		REQUIRE( get<0>(res) == Approx(mul_vec_res[0]) );
		REQUIRE( get<1>(res) == Approx(mul_vec_res[1]) );
		REQUIRE( get<2>(res) == Approx(mul_vec_res[2]) );
		REQUIRE( get<3>(res) == Approx(mul_vec_res[3]) );
		REQUIRE( &res == &mul_var_1 );//result must be mul_var_1
		REQUIRE( &res != &mul_var_2 );//but not mul_var_2
		auto &res2 = mul(res, mul_scalar);
		REQUIRE( get<0>(res2) == Approx(mul_vec_scalar_res[0]) );
		REQUIRE( get<1>(res2) == Approx(mul_vec_scalar_res[1]) );
		REQUIRE( get<2>(res2) == Approx(mul_vec_scalar_res[2]) );
		REQUIRE( get<3>(res2) == Approx(mul_vec_scalar_res[3]) );
		REQUIRE( &res2 == &mul_var_1 );//result must be mul_var_1
	}
	
	SECTION( "mul (scalar)/1" )
	{
		auto &res = mul(mul_var_1, mul_scalar);
		REQUIRE( get<0>(res) == Approx(mul_scalar_res[0]) );
		REQUIRE( get<1>(res) == Approx(mul_scalar_res[1]) );
		REQUIRE( get<2>(res) == Approx(mul_scalar_res[2]) );
		REQUIRE( get<3>(res) == Approx(mul_scalar_res[3]) );
		REQUIRE( &res == &mul_var_1 );//result must be mul_var_1
		auto &res2 = mul(res, mul_var_2);
		REQUIRE( get<0>(res2) == Approx(mul_vec_scalar_res[0]) );
		REQUIRE( get<1>(res2) == Approx(mul_vec_scalar_res[1]) );
		REQUIRE( get<2>(res2) == Approx(mul_vec_scalar_res[2]) );
		REQUIRE( get<3>(res2) == Approx(mul_vec_scalar_res[3]) );
		REQUIRE( &res2 == &mul_var_1 );//result must be mul_var_1
	}
	
	SECTION( "div_mk/1" )
	{
		auto res = div_mk(div_var_1, div_var_2);
		REQUIRE( get<0>(res) == Approx(div_vec_res[0]) );
		REQUIRE( get<1>(res) == Approx(div_vec_res[1]) );
		REQUIRE( get<2>(res) == Approx(div_vec_res[2]) );
		REQUIRE( get<3>(res) == Approx(div_vec_res[3]) );
		REQUIRE( &res != &div_var_1 ); //result must be a new resource
		REQUIRE( &res != &div_var_2 ); //also different to div_var_2
	}
	
	SECTION( "div_mk (scalar)/1" )
	{
		auto res = div_mk(div_var_1, div_scalar);
		REQUIRE( get<0>(res) == Approx(div_scalar_res[0]) );
		REQUIRE( get<1>(res) == Approx(div_scalar_res[1]) );
		REQUIRE( get<2>(res) == Approx(div_scalar_res[2]) );
		REQUIRE( get<3>(res) == Approx(div_scalar_res[3]) );
		REQUIRE( &res != &div_var_1 ); //result must be a new resource
	}
	
	SECTION( "div_set/1" )
	{
		div_set(div_var_1, div_var_2);
		REQUIRE( get<0>(div_var_1) == Approx(div_vec_res[0]) );
		REQUIRE( get<1>(div_var_1) == Approx(div_vec_res[1]) );
		REQUIRE( get<2>(div_var_1) == Approx(div_vec_res[2]) );
		REQUIRE( get<3>(div_var_1) == Approx(div_vec_res[3]) );
	}
	
	SECTION( "div_set (scalar)/1" )
	{
		div_set(div_var_1, div_scalar);
		REQUIRE( get<0>(div_var_1) == Approx(div_scalar_res[0]) );
		REQUIRE( get<1>(div_var_1) == Approx(div_scalar_res[1]) );
		REQUIRE( get<2>(div_var_1) == Approx(div_scalar_res[2]) );
		REQUIRE( get<3>(div_var_1) == Approx(div_scalar_res[3]) );
	}
	
	SECTION( "div/1" )
	{
		auto &res = div(div_var_1, div_var_2);
		REQUIRE( get<0>(res) == Approx(div_vec_res[0]) );
		REQUIRE( get<1>(res) == Approx(div_vec_res[1]) );
		REQUIRE( get<2>(res) == Approx(div_vec_res[2]) );
		REQUIRE( get<3>(res) == Approx(div_vec_res[3]) );
		REQUIRE( &res == &div_var_1 );//result must be div_var_1
		REQUIRE( &res != &div_var_2 );//but not div_var_2
		auto &res2 = div(res, div_scalar);
		REQUIRE( get<0>(res2) == Approx(div_vec_scalar_res[0]) );
		REQUIRE( get<1>(res2) == Approx(div_vec_scalar_res[1]) );
		REQUIRE( get<2>(res2) == Approx(div_vec_scalar_res[2]) );
		REQUIRE( get<3>(res2) == Approx(div_vec_scalar_res[3]) );
		REQUIRE( &res2 == &div_var_1 );//result must be div_var_1
	}
	
	SECTION( "div (scalar)/1" )
	{
		auto &res = div(div_var_1, div_scalar);
		REQUIRE( get<0>(res) == Approx(div_scalar_res[0]) );
		REQUIRE( get<1>(res) == Approx(div_scalar_res[1]) );
		REQUIRE( get<2>(res) == Approx(div_scalar_res[2]) );
		REQUIRE( get<3>(res) == Approx(div_scalar_res[3]) );
		REQUIRE( &res == &div_var_1 );//result must be div_var_1
		auto &res2 = div(res, div_var_2);
		REQUIRE( get<0>(res2) == Approx(div_vec_scalar_res[0]) );
		REQUIRE( get<1>(res2) == Approx(div_vec_scalar_res[1]) );
		REQUIRE( get<2>(res2) == Approx(div_vec_scalar_res[2]) );
		REQUIRE( get<3>(res2) == Approx(div_vec_scalar_res[3]) );
		REQUIRE( &res2 == &div_var_1 );//result must be div_var_1
	}
	
}
TEST_CASE( "General purpos functions for 4 component vectors/4", "[vec4<float>(4)]" )
{
	SECTION( "Dot product/1" )
	{
		
	}
	
	SECTION( "Dot product ignoring the w component/1" )
	{
		
	}
	
}
