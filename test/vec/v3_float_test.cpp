#include "../../ext/catch/catch.hpp"
#include "../../inc/avl.h"

using namespace avl;

TEST_CASE( "Helper functions", "[vec3<float>(3)]" )
{
	SECTION( "Component type helper/1" )
	{
		const vec3 vec;
		static_assert(eq< decltype( vec[0] ), decltype( cmp(vec) ) >::value, "Supply a scalar of the vectors element type.");
	}
	
}
TEST_CASE( "Getters and setters for all vectors", "[vec3<float>(3)]" )
{
	SECTION( "Access the vector components by a range checked index from 0 to dim-1/1" )
	{
		const vec3 vec = { 0, 1, 2 };
		
		REQUIRE( get(vec, 0) == Approx( 0 ) );
		REQUIRE( get(vec, 1) == Approx( 1 ) );
		REQUIRE( get(vec, 2) == Approx( 2 ) );
	}
	
	SECTION( "Access the vector components by a static range checked index from 0 to dim-1/1" )
	{
		const vec3 vec = { 0, 1, 2 };
		
		REQUIRE( get<0>(vec) == Approx( 0 ) );
		REQUIRE( get<1>(vec) == Approx( 1 ) );
		REQUIRE( get<2>(vec) == Approx( 2 ) );
	}
	
	SECTION( "Set a single component by index from 0 to dim-1/1" )
	{
		vec3 vec;
		const float[] arr = { -39.516, 5.022, -55.346 };
		
		set(vec, 0, arr[0]);
		REQUIRE( get(vec, 0) == Approx( arr[0] ) );
		set(vec, 1, arr[1]);
		REQUIRE( get(vec, 1) == Approx( arr[1] ) );
		set(vec, 2, arr[2]);
		REQUIRE( get(vec, 2) == Approx( arr[2] ) );
	}
	
	SECTION( "Set a single component by static index from 0 to dim-1/1" )
	{
		vec3 vec = { 0, 1, 2 };
		const float[] arr = { 64.931, -71.991, 18.044 };
		
		set<0>(vec, arr[ 0 ]);
		REQUIRE( get<0>(vec) == Approx( arr[0] ) );
		set<1>(vec, arr[ 1 ]);
		REQUIRE( get<1>(vec) == Approx( arr[1] ) );
		set<2>(vec, arr[ 2 ]);
		REQUIRE( get<2>(vec) == Approx( arr[2] ) );
	}
	
}
TEST_CASE( "Vector length operations", "[vec3<float>(3)]" )
{
	SECTION( "Returns a new vector with the requested length/1" )
	{
		const vec3 vec = { 30.556, -30.752, 44.111 };
		const auto len_to_set = -87.757;
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
		vec3 vec = { 31.643, -20.870, 99.803 };
		const auto len_to_set = 15.063;
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
		vec3 vec = { 91.631, 95.936, 79.751 };
		const auto len_to_set = 32.164;
		const auto ret_vec = setlen(vec, len_to_set);
		const auto vec_len = len(vec);
		
		REQUIRE( vec_len == Approx(len_to_set) );
		
		REQUIRE( &vec == &ret_vec);
		//test edge case 0.0
		const auto ret_zero_vec = setlen(vec, cnst<float>::zero);
		
		REQUIRE( get<0>(vec) == Approx( cnst<float>::zero ) );
		REQUIRE( get<1>(vec) == Approx( cnst<float>::zero ) );
		REQUIRE( get<2>(vec) == Approx( cnst<float>::zero ) );
		REQUIRE( &vec == &ret_zero_vec);
	}
	
	SECTION( "Calculate the length of the vector, prefere len_sqr when comparing distances/1" )
	{
		const vec3 vec = { -98.242, -47.634, 11.530 };
		const auto vec_len = len(vec);
		const auto vec_square_len = get<0>(vec) * get<0>(vec) + get<1>(vec) * get<1>(vec) + get<2>(vec) * get<2>(vec);
		REQUIRE( vec_len == Approx( s::sqrt( vec_square_len ) ) );
		
		//test edge case 0.0
		const vec3 zero_vec = { 0, 0, 0 };
		const auto zero_vec_len = len(zero_vec);
		REQUIRE( zero_vec_len == Approx( cnst<float>::zero ) );
	}
	
	SECTION( "Calculate the square length of the vector/1" )
	{
		const vec3 vec = { -23.339, -20.869, -42.571 };
		const auto vec_len_sqr = len_sqr(vec);
		const auto vec_len_sqr_check = get<0>(vec) * get<0>(vec) + get<1>(vec) * get<1>(vec) + get<2>(vec) * get<2>(vec);
		REQUIRE( vec_len_sqr == Approx( vec_len_sqr_check ) );
		
		//test edge case 0.0
		const vec3 zero_vec = { 0, 0, 0 };
		const auto zero_vec_len_sqr = len_sqr(zero_vec);
		REQUIRE( zero_vec_len_sqr == Approx( cnst<float>::zero ) );
	}
	
	SECTION( "Returns a normalized vector/1" )
	{
		
		const vec3 vec = { -66.230, 96.213, 63.923 };
		const auto new_norm_vec = norm_mk(vec);
		const auto norm_len = len(new_norm_vec);
		REQUIRE( norm_len == Approx( cnst<float>::one ) );
	}
	
	SECTION( "Returns a normalized vector, use alternative vector if the current vector length is 0/1" )
	{
		const vec3 zero_vec = { 0, 0, 0 };
		const auto zero_len = len(zero_vec)
		REQUIRE( zero_len == Approx( cnst<float>::zero ) );
		
		vec3 unit_vec = { 0, 0, 0 };
		set<0>(unit_vec, cnst<float>::one);
		
		const auto new_unit_vec = norm_mk(zero_vec, unit_vec);
		const auto new_unit_vec_len = len(new_unit_vec);
		REQUIRE( new_unit_vec_len == Approx( cnst<float>::one ) );
		REQUIRE( get<0>(new_unit_vec) == Approx( cnst<float>::one ) );
	}
	
	SECTION( "Normalize the current vector/1" )
	{
		vec3 vec = { -29.223, 83.438, -89.235 };
		norm_set(vec);
		const auto len_to_set = len(vec);
		REQUIRE( len_to_set == Approx( cnst<float>::one ) );
	}
	
	SECTION( "Normalize the current vector, use alternative vector if the current vector length is 0/1" )
	{
		vec3 vec = { 0, 0, 0 };
		const auto zero_len = len(vec)
		REQUIRE( zero_len == Approx( cnst<float>::zero ) );
		
		vec3 unit_vec = { 0, 0, 0 };
		set<0>(unit_vec, cnst<float>::one);
		
		norm_set(vec, unit_vec);
		const auto vec_len = len(vec);
		REQUIRE( vec_len == Approx( cnst<float>::one ) );
		REQUIRE( get<0>(vec) == Approx( cnst<float>::one ) );
	}
	
	SECTION( "Normalize the current vector and return the same vector (chained)/1" )
	{
		vec3 vec = { 64.109, -5.500, -59.844 };
		auto ret_vec = norm(vec);
		const auto len_to_set = len(vec);
		REQUIRE( len_to_set == Approx( cnst<float>::one ) );
		REQUIRE( &vec == &ret_vec);
	}
	
	SECTION( "Normalize the current vector and return the same vector (chained), use alternative vector if the current vector length is 0/1" )
	{
		vec3 vec = { 0, 0, 0 };
		const auto zero_len = len(vec)
		REQUIRE( zero_len == Approx( cnst<float>::zero ) );
		
		vec3 unit_vec = { 0, 0, 0 };
		set<0>(unit_vec, cnst<float>::one);
		
		auto ret_vec = norm(vec, unit_vec);
		const auto vec_len = len(vec);
		REQUIRE( vec_len == Approx( cnst<float>::one ) );
		REQUIRE( get<0>(vec) == Approx( cnst<float>::one ) );
		REQUIRE( &vec == &ret_vec);
	}
	
}
TEST_CASE( "Spacial operations", "[vec3<float>(3)]" )
{
	SECTION( "Calculate the angle between two vectors in radian/1" )
	{
		const auto random_len1 = -71.993;
		const auto random_len2 = 35.807;
		const auto random_len3 = 23.679;
		const auto random_len4 = -44.516;
		
		vec3 vec_zero = { 0, 0, 0 };
		vec3 vec_10x = { 0, 0, 0 };
		set<0>(vec_10x, random_len1);
		vec3 vec_01x = { 0, 0, 0 };
		set<1>(vec_01x, random_len2);
		vec3 vec_m10x = { 0, 0, 0 };
		set<0>(vec_m10x, -random_len3);
		vec3 vec_11x = { 0, 0, 0 };
		set<0>(vec_11x, random_len4);
		set<1>(vec_11x, random_len4);
		
		const auto angle0 = angle_rd(vec_10x, vec_zero);
		REQUIRE( angle0 == Approx( cnst<float>::zero );
		
		const auto angle90 = angle_rd(vec_10x, vec_01x);
		REQUIRE( angle90 == Approx( 1.57079632679 );
		
		const auto angle45a = angle_rd(vec_10x, vec_11x);
		REQUIRE( angle45a == Approx( 0.785398163396 );
		const auto angle45b = angle_rd(vec_01x, vec_11x);
		REQUIRE( angle45b == Approx( 0.785398163396 );
		
		const auto angle135 = angle_rd(vec_m10x, vec_11x);
		REQUIRE( angle135 == Approx( 2.35619449019 );
		
		const auto angle180 = angle_rd(vec_10x, vec_m10x);
		REQUIRE( angle180 == Approx( 3.14159265358 );
	}
	
	SECTION( "Calculate the angle between two vectors in radian/2" )
	{
		const auto random_len1 = -17.864;
		const auto random_len2 = -55.271;
		const auto random_len3 = 54.458;
		const auto random_len4 = 53.365;
		
		vec3 vec_zero = { 0, 0, 0 };
		vec3 vec_010x = { 0, 0, 0 };
		set<1>(vec_010x, random_len1);
		vec3 vec_001x = { 0, 0, 0 };
		set<2>(vec_001x, random_len2);
		vec3 vec_0m10x = { 0, 0, 0 };
		set<1>(vec_0m10x, -random_len3);
		vec3 vec_011x = { 0, 0, 0 };
		set<1>(vec_011x, random_len4);
		set<2>(vec_011x, random_len4);
		
		const auto angle0 = angle_rd(vec_010x, vec_zero);
		REQUIRE( angle0 == Approx( cnst<float>::zero );
		
		const auto angle90 = angle_rd(vec_010x, vec_001x);
		REQUIRE( angle90 == Approx( 1.57079632679 );
		
		const auto angle45a = angle_rd(vec_010x, vec_011x);
		REQUIRE( angle45a == Approx( 0.785398163396 );
		const auto angle45b = angle_rd(vec_001x, vec_011x);
		REQUIRE( angle45b == Approx( 0.785398163396 );
		
		const auto angle135 = angle_rd(vec_0m10x, vec_011x);
		REQUIRE( angle135 == Approx( 2.35619449019 );
		
		const auto angle180 = angle_rd(vec_010x, vec_0m10x);
		REQUIRE( angle180 == Approx( 3.14159265358 );
	}
	
	SECTION( "Calculate the angle between two vectors in degree/1" )
	{
		const auto random_len1 = -77.151;
		const auto random_len2 = 9.297;
		const auto random_len3 = 68.259;
		const auto random_len4 = 31.885;
		
		vec3 vec_zero = { 0, 0, 0 };
		vec3 vec_10x = { 0, 0, 0 };
		set<0>(vec_10x, random_len1);
		vec3 vec_01x = { 0, 0, 0 };
		set<1>(vec_01x, random_len2);
		vec3 vec_m10x = { 0, 0, 0 };
		set<0>(vec_m10x, -random_len3);
		vec3 vec_11x = { 0, 0, 0 };
		set<0>(vec_11x, random_len4);
		set<1>(vec_11x, random_len4);
		
		const auto angle0 = angle_dg(vec_10x, vec_zero);
		REQUIRE( angle0 == Approx( cnst<float>::zero );
		
		const auto angle90 = angle_dg(vec_10x, vec_01x);
		REQUIRE( angle90 == Approx( 90 );
		
		const auto angle45a = angle_dg(vec_10x, vec_11x);
		REQUIRE( angle45a == Approx( 45 );
		const auto angle45b = angle_dg(vec_01x, vec_11x);
		REQUIRE( angle45b == Approx( 45 );
		
		const auto angle135 = angle_dg(vec_m10x, vec_11x);
		REQUIRE( angle135 == Approx( 135 );
		
		const auto angle180 = angle_dg(vec_10x, vec_m10x);
		REQUIRE( angle180 == Approx( 180 );
	}
	
	SECTION( "Calculate the angle between two vectors in degree/2" )
	{
		const auto random_len1 = 1.285;
		const auto random_len2 = -91.23;
		const auto random_len3 = -7.666;
		const auto random_len4 = 64.986;
		
		vec3 vec_zero = { 0, 0, 0 };
		vec3 vec_010x = { 0, 0, 0 };
		set<1>(vec_010x, random_len1);
		vec3 vec_001x = { 0, 0, 0 };
		set<2>(vec_001x, random_len2);
		vec3 vec_0m10x = { 0, 0, 0 };
		set<1>(vec_0m10x, -random_len3);
		vec3 vec_011x = { 0, 0, 0 };
		set<1>(vec_011x, random_len4);
		set<2>(vec_011x, random_len4);
		
		const auto angle0 = angle_dg(vec_010x, vec_zero);
		REQUIRE( angle0 == Approx( cnst<float>::zero );
		
		const auto angle90 = angle_dg(vec_010x, vec_001x);
		REQUIRE( angle90 == Approx( 90 );
		
		const auto angle45a = angle_dg(vec_010x, vec_011x);
		REQUIRE( angle45a == Approx( 45 );
		const auto angle45b = angle_dg(vec_001x, vec_011x);
		REQUIRE( angle45b == Approx( 45 );
		
		const auto angle135 = angle_dg(vec_0m10x, vec_011x);
		REQUIRE( angle135 == Approx( 135 );
		
		const auto angle180 = angle_dg(vec_010x, vec_0m10x);
		REQUIRE( angle180 == Approx( 180 );
	}
	
	SECTION( "Calculate the area of the spawned triangle/1" )
	{
		vec3 vec0;
		vec3 vec1;
		vec3 vec2;
		set<0>(vec0, 1);
		set<1>(vec1, 1);
		set<0>(vec2, -1);
		
		const auto a0 = area(vec0, vec1);
		REQUIRE( a0 == cnst<decltype(a0)::half );
		
		const auto a1 = area(vec0, vec0);
		REQUIRE( a1 == cnst<decltype(a1)::zero );
		
		const auto a2 = area(vec0, vec2);
		REQUIRE( a2 == cnst<decltype(a2)::zero );
	}
	
	SECTION( "Calculate the cross product/1" )
	{
		
	}
	
	SECTION( "Calculate the cross product/1" )
	{
		
	}
	
	SECTION( "Calculate the cross product/1" )
	{
		
	}
	
}
TEST_CASE( "Getter and setters for 3 component vectors", "[vec3<float>(3)]" )
{
	SECTION( "Set all vector components to the same scalar/1" )
	{
		vec3 vec = { 0, 0, 0 };
		
		const auto val = -43.384;
		set_all(vec, val);
		
		REQUIRE( get<0>(vec)==val );
		REQUIRE( get<1>(vec)==val );
		REQUIRE( get<2>(vec)==val );
	}
	
	SECTION( "Set all vector components individually/1" )
	{
		vec3 vec = { 0, 0, 0 };
		const float[] arr = { 74.225, 27.629, 69.916 };
		
		set_all(vec,arr[0], arr[1], arr[2]);
		
		REQUIRE( get<0>(vec)==arr[0] );
		REQUIRE( get<1>(vec)==arr[1] );
		REQUIRE( get<2>(vec)==arr[2] );
	}
	
	SECTION( "Set all vector components individually by a fixed size array/1" )
	{
		vec3 vec = { 0, 0, 0 };
		const float[] arr = { 65.982, -12.719, 13.388 };
		
		set_all(vec, arr);
		
		REQUIRE( get<0>(vec)==arr[0] );
		REQUIRE( get<1>(vec)==arr[1] );
		REQUIRE( get<2>(vec)==arr[2] );
	}
	
	SECTION( "Set all vector components individually by an array/1" )
	{
		vec3 vec = { 0, 0, 0 };
		const float[] arr = { 8.611, -44.171, 17.159 };
		const auto* ptr_to_arr = arr;
		
		set_all<3>(vec, ptr_to_arr);
		
		REQUIRE( get<0>(vec)==arr[0] );
		REQUIRE( get<1>(vec)==arr[1] );
		REQUIRE( get<2>(vec)==arr[2] );
	}
	
}
TEST_CASE( "General vector operations for 3 component vectors", "[vec3<float>(3)]" )
{
	vec3 add_var_1 = { -30.164, -58.525, -63.254 };
	vec3 add_var_2 = { -97.805, -2.498, -89.937 };
	float add_scalar = { 83.113 };
	
	const float[] add_vec_res =
		{ get<0>(add_var_1) + get<0>(add_var_2), get<1>(add_var_1) + get<1>(add_var_2), get<2>(add_var_1) + get<2>(add_var_2) };
	const float[] add_scalar_res =
		{ get<0>(add_var_1) + get<0>(add_scalar), get<1>(add_var_1) + get<1>(add_scalar), get<2>(add_var_1) + get<2>(add_scalar) };
	const float[] add_vec_scalar_res =
		{ get<0>(add_var_1) + get<0>(add_var_2) + get<0>(add_scalar), get<1>(add_var_1) + get<1>(add_var_2) + get<1>(add_scalar), get<2>(add_var_1) + get<2>(add_var_2) + get<2>(add_scalar) };
	
	vec3 sub_var_1 = { 76.661, 54.562, 89.966 };
	vec3 sub_var_2 = { 0.972, 79.548, 60.731 };
	float sub_scalar = { 84.25 };
	
	const float[] sub_vec_res =
		{ get<0>(sub_var_1) - get<0>(sub_var_2), get<1>(sub_var_1) - get<1>(sub_var_2), get<2>(sub_var_1) - get<2>(sub_var_2) };
	const float[] sub_scalar_res =
		{ get<0>(sub_var_1) - get<0>(sub_scalar), get<1>(sub_var_1) - get<1>(sub_scalar), get<2>(sub_var_1) - get<2>(sub_scalar) };
	const float[] sub_vec_scalar_res =
		{ get<0>(sub_var_1) - get<0>(sub_var_2) - get<0>(sub_scalar), get<1>(sub_var_1) - get<1>(sub_var_2) - get<1>(sub_scalar), get<2>(sub_var_1) - get<2>(sub_var_2) - get<2>(sub_scalar) };
	
	vec3 mul_var_1 = { 80.794, 15.910, -56.508 };
	vec3 mul_var_2 = { 42.835, 91.443, -80.435 };
	float mul_scalar = { 49.484 };
	
	const float[] mul_vec_res =
		{ get<0>(mul_var_1) * get<0>(mul_var_2), get<1>(mul_var_1) * get<1>(mul_var_2), get<2>(mul_var_1) * get<2>(mul_var_2) };
	const float[] mul_scalar_res =
		{ get<0>(mul_var_1) * get<0>(mul_scalar), get<1>(mul_var_1) * get<1>(mul_scalar), get<2>(mul_var_1) * get<2>(mul_scalar) };
	const float[] mul_vec_scalar_res =
		{ get<0>(mul_var_1) * get<0>(mul_var_2) * get<0>(mul_scalar), get<1>(mul_var_1) * get<1>(mul_var_2) * get<1>(mul_scalar), get<2>(mul_var_1) * get<2>(mul_var_2) * get<2>(mul_scalar) };
	
	vec3 div_var_1 = { -66.180, -81.802, -22.158 };
	vec3 div_var_2 = { -9.729, 77.540, 8.166 };
	float div_scalar = { 77.828 };
	
	const float[] div_vec_res =
		{ get<0>(div_var_1) / get<0>(div_var_2), get<1>(div_var_1) / get<1>(div_var_2), get<2>(div_var_1) / get<2>(div_var_2) };
	const float[] div_scalar_res =
		{ get<0>(div_var_1) / get<0>(div_scalar), get<1>(div_var_1) / get<1>(div_scalar), get<2>(div_var_1) / get<2>(div_scalar) };
	const float[] div_vec_scalar_res =
		{ get<0>(div_var_1) / get<0>(div_var_2) / get<0>(div_scalar), get<1>(div_var_1) / get<1>(div_var_2) / get<1>(div_scalar), get<2>(div_var_1) / get<2>(div_var_2) / get<2>(div_scalar) };
	
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
		REQUIRE( get<0>(res) == Approx(add_vec_res[0]) );
		REQUIRE( get<1>(res) == Approx(add_vec_res[1]) );
		REQUIRE( get<2>(res) == Approx(add_vec_res[2]) );
	}
	
	SECTION( "add_set (scalar)/1" )
	{
		add_set(add_var_1, add_scalar);
		REQUIRE( get<0>(res) == Approx(add_scalar_res[0]) );
		REQUIRE( get<1>(res) == Approx(add_scalar_res[1]) );
		REQUIRE( get<2>(res) == Approx(add_scalar_res[2]) );
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
		REQUIRE( get<0>(res2) == Approx(add_vec_sclar_res[0]) );
		REQUIRE( get<1>(res2) == Approx(add_vec_sclar_res[1]) );
		REQUIRE( get<2>(res2) == Approx(add_vec_sclar_res[2]) );
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
		REQUIRE( get<0>(res) == Approx(sub_vec_res[0]) );
		REQUIRE( get<1>(res) == Approx(sub_vec_res[1]) );
		REQUIRE( get<2>(res) == Approx(sub_vec_res[2]) );
	}
	
	SECTION( "sub_set (scalar)/1" )
	{
		sub_set(sub_var_1, sub_scalar);
		REQUIRE( get<0>(res) == Approx(sub_scalar_res[0]) );
		REQUIRE( get<1>(res) == Approx(sub_scalar_res[1]) );
		REQUIRE( get<2>(res) == Approx(sub_scalar_res[2]) );
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
		REQUIRE( get<0>(res2) == Approx(sub_vec_sclar_res[0]) );
		REQUIRE( get<1>(res2) == Approx(sub_vec_sclar_res[1]) );
		REQUIRE( get<2>(res2) == Approx(sub_vec_sclar_res[2]) );
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
		REQUIRE( get<0>(res) == Approx(mul_vec_res[0]) );
		REQUIRE( get<1>(res) == Approx(mul_vec_res[1]) );
		REQUIRE( get<2>(res) == Approx(mul_vec_res[2]) );
	}
	
	SECTION( "mul_set (scalar)/1" )
	{
		mul_set(mul_var_1, mul_scalar);
		REQUIRE( get<0>(res) == Approx(mul_scalar_res[0]) );
		REQUIRE( get<1>(res) == Approx(mul_scalar_res[1]) );
		REQUIRE( get<2>(res) == Approx(mul_scalar_res[2]) );
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
		REQUIRE( get<0>(res2) == Approx(mul_vec_sclar_res[0]) );
		REQUIRE( get<1>(res2) == Approx(mul_vec_sclar_res[1]) );
		REQUIRE( get<2>(res2) == Approx(mul_vec_sclar_res[2]) );
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
		REQUIRE( get<0>(res) == Approx(div_vec_res[0]) );
		REQUIRE( get<1>(res) == Approx(div_vec_res[1]) );
		REQUIRE( get<2>(res) == Approx(div_vec_res[2]) );
	}
	
	SECTION( "div_set (scalar)/1" )
	{
		div_set(div_var_1, div_scalar);
		REQUIRE( get<0>(res) == Approx(div_scalar_res[0]) );
		REQUIRE( get<1>(res) == Approx(div_scalar_res[1]) );
		REQUIRE( get<2>(res) == Approx(div_scalar_res[2]) );
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
		REQUIRE( get<0>(res2) == Approx(div_vec_sclar_res[0]) );
		REQUIRE( get<1>(res2) == Approx(div_vec_sclar_res[1]) );
		REQUIRE( get<2>(res2) == Approx(div_vec_sclar_res[2]) );
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
