// NOTICE: This file is generated using the template file v.jinja
#include "../../ext/catch/catch.hpp"
#include "../../inc/avl.hpp"

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
		const float arr [] = { -47.634, 11.530, -23.339, -20.869 };
		
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
		const float arr [] = { -42.571, -66.230, 96.213, 63.923 };
		
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
		{
			const vec4<float> vec = { -29.223, 83.438, -89.235, 64.109 };
			const float len_to_set = { 5.5 };
			const auto new_vec = setlen_mk<-3>(vec, len_to_set);
			const auto len_new_vec = len<-3>(new_vec);
			
			REQUIRE( len_new_vec == Approx(len_to_set) );
			
			//test edge case 0.0
			const auto zero_len_vec = setlen_mk<-3>(vec, cnst<float>::zero);
  			REQUIRE( get<1>(zero_len_vec) == Approx( cnst<float>::zero ) );
			REQUIRE( get<2>(zero_len_vec) == Approx( cnst<float>::zero ) );
			REQUIRE( get<3>(zero_len_vec) == Approx( cnst<float>::zero ) );
		}
		{
			const vec4<float> vec = { -59.844, -71.993, 35.807, 23.679 };
			const float len_to_set = { 44.516 };
			const auto new_vec = setlen_mk<-2>(vec, len_to_set);
			const auto len_new_vec = len<-2>(new_vec);
			
			REQUIRE( len_new_vec == Approx(len_to_set) );
			
			//test edge case 0.0
			const auto zero_len_vec = setlen_mk<-2>(vec, cnst<float>::zero);
  			REQUIRE( get<2>(zero_len_vec) == Approx( cnst<float>::zero ) );
			REQUIRE( get<3>(zero_len_vec) == Approx( cnst<float>::zero ) );
		}
		{
			const vec4<float> vec = { -17.864, -55.271, 54.458, 53.365 };
			const float len_to_set = { 77.151 };
			const auto new_vec = setlen_mk<2>(vec, len_to_set);
			const auto len_new_vec = len<2>(new_vec);
			
			REQUIRE( len_new_vec == Approx(len_to_set) );
			
			//test edge case 0.0
			const auto zero_len_vec = setlen_mk<2>(vec, cnst<float>::zero);
			REQUIRE( get<0>(zero_len_vec) == Approx( cnst<float>::zero ) );
			REQUIRE( get<1>(zero_len_vec) == Approx( cnst<float>::zero ) );
		}
		{
			const vec4<float> vec = { 9.297, 68.259, 31.885, 1.285 };
			const float len_to_set = { 91.23 };
			const auto new_vec = setlen_mk<3>(vec, len_to_set);
			const auto len_new_vec = len<3>(new_vec);
			
			REQUIRE( len_new_vec == Approx(len_to_set) );
			
			//test edge case 0.0
			const auto zero_len_vec = setlen_mk<3>(vec, cnst<float>::zero);
			REQUIRE( get<0>(zero_len_vec) == Approx( cnst<float>::zero ) );
			REQUIRE( get<1>(zero_len_vec) == Approx( cnst<float>::zero ) );
			REQUIRE( get<2>(zero_len_vec) == Approx( cnst<float>::zero ) );
		}
		{
			const vec4<float> vec = { -7.666, 64.986, -43.384, 74.225 };
			const float len_to_set = { 27.629 };
			const auto new_vec = setlen_mk<4>(vec, len_to_set);
			const auto len_new_vec = len<4>(new_vec);
			
			REQUIRE( len_new_vec == Approx(len_to_set) );
			
			//test edge case 0.0
			const auto zero_len_vec = setlen_mk<4>(vec, cnst<float>::zero);
			REQUIRE( get<0>(zero_len_vec) == Approx( cnst<float>::zero ) );
			REQUIRE( get<1>(zero_len_vec) == Approx( cnst<float>::zero ) );
			REQUIRE( get<2>(zero_len_vec) == Approx( cnst<float>::zero ) );
			REQUIRE( get<3>(zero_len_vec) == Approx( cnst<float>::zero ) );
		}
	}
	
	SECTION( "Set the length of the vector/1" )
	{
		{
			vec4<float> vec = { 69.916, 65.982, -12.719, 13.388 };
			const float len_to_set = { 8.611 };
			setlen_set(vec, len_to_set);
			const auto vec_len = len<-3>(vec);
			
			REQUIRE( vec_len == Approx(len_to_set) );
			
			//test edge case 0.0
			setlen_set<-3>(vec, cnst<float>::zero);
			
  			REQUIRE( get<1>(vec) == Approx( cnst<float>::zero ) );
			REQUIRE( get<2>(vec) == Approx( cnst<float>::zero ) );
			REQUIRE( get<3>(vec) == Approx( cnst<float>::zero ) );
		}
		{
			vec4<float> vec = { -44.171, 17.159, -30.164, -58.525 };
			const float len_to_set = { 63.254 };
			setlen_set(vec, len_to_set);
			const auto vec_len = len<-2>(vec);
			
			REQUIRE( vec_len == Approx(len_to_set) );
			
			//test edge case 0.0
			setlen_set<-2>(vec, cnst<float>::zero);
			
  			REQUIRE( get<2>(vec) == Approx( cnst<float>::zero ) );
			REQUIRE( get<3>(vec) == Approx( cnst<float>::zero ) );
		}
		{
			vec4<float> vec = { -97.805, -2.498, -89.937, 83.113 };
			const float len_to_set = { 76.661 };
			setlen_set(vec, len_to_set);
			const auto vec_len = len<2>(vec);
			
			REQUIRE( vec_len == Approx(len_to_set) );
			
			//test edge case 0.0
			setlen_set<2>(vec, cnst<float>::zero);
			
			REQUIRE( get<0>(vec) == Approx( cnst<float>::zero ) );
			REQUIRE( get<1>(vec) == Approx( cnst<float>::zero ) );
		}
		{
			vec4<float> vec = { 54.562, 89.966, 0.972, 79.548 };
			const float len_to_set = { 60.731 };
			setlen_set(vec, len_to_set);
			const auto vec_len = len<3>(vec);
			
			REQUIRE( vec_len == Approx(len_to_set) );
			
			//test edge case 0.0
			setlen_set<3>(vec, cnst<float>::zero);
			
			REQUIRE( get<0>(vec) == Approx( cnst<float>::zero ) );
			REQUIRE( get<1>(vec) == Approx( cnst<float>::zero ) );
			REQUIRE( get<2>(vec) == Approx( cnst<float>::zero ) );
		}
		{
			vec4<float> vec = { 84.250, 80.794, 15.910, -56.508 };
			const float len_to_set = { 42.835 };
			setlen_set(vec, len_to_set);
			const auto vec_len = len<4>(vec);
			
			REQUIRE( vec_len == Approx(len_to_set) );
			
			//test edge case 0.0
			setlen_set<4>(vec, cnst<float>::zero);
			
			REQUIRE( get<0>(vec) == Approx( cnst<float>::zero ) );
			REQUIRE( get<1>(vec) == Approx( cnst<float>::zero ) );
			REQUIRE( get<2>(vec) == Approx( cnst<float>::zero ) );
			REQUIRE( get<3>(vec) == Approx( cnst<float>::zero ) );
		}
	}
	
	SECTION( "Set the length of the vector and return the same vector (chained)/1" )
	{
		{
			vec4<float> vec = { 91.443, -80.435, 49.484, -66.180 };
			const float len_to_set = { 81.802 };
			const auto &ret_vec = setlen(vec, len_to_set);
			const auto vec_len = len<-3>(vec);
			
			REQUIRE( vec_len == Approx(len_to_set) );
			
			REQUIRE( &vec == &ret_vec);
			//test edge case 0.0
			const auto &ret_zero_vec = setlen<-3>(vec, cnst<float>::zero);
			
  			REQUIRE( get<1>(vec) == Approx( cnst<float>::zero ) );
			REQUIRE( get<2>(vec) == Approx( cnst<float>::zero ) );
			REQUIRE( get<3>(vec) == Approx( cnst<float>::zero ) );
			REQUIRE( &vec == &ret_zero_vec);
		}
		{
			vec4<float> vec = { -22.158, -9.729, 77.540, 8.166 };
			const float len_to_set = { 77.828 };
			const auto &ret_vec = setlen(vec, len_to_set);
			const auto vec_len = len<-2>(vec);
			
			REQUIRE( vec_len == Approx(len_to_set) );
			
			REQUIRE( &vec == &ret_vec);
			//test edge case 0.0
			const auto &ret_zero_vec = setlen<-2>(vec, cnst<float>::zero);
			
  			REQUIRE( get<2>(vec) == Approx( cnst<float>::zero ) );
			REQUIRE( get<3>(vec) == Approx( cnst<float>::zero ) );
			REQUIRE( &vec == &ret_zero_vec);
		}
		{
			vec4<float> vec = { -17.454, 86.022, 2.399, -83.996 };
			const float len_to_set = { 5.982 };
			const auto &ret_vec = setlen(vec, len_to_set);
			const auto vec_len = len<2>(vec);
			
			REQUIRE( vec_len == Approx(len_to_set) );
			
			REQUIRE( &vec == &ret_vec);
			//test edge case 0.0
			const auto &ret_zero_vec = setlen<2>(vec, cnst<float>::zero);
			
			REQUIRE( get<0>(vec) == Approx( cnst<float>::zero ) );
			REQUIRE( get<1>(vec) == Approx( cnst<float>::zero ) );
			REQUIRE( &vec == &ret_zero_vec);
		}
		{
			vec4<float> vec = { -14.506, -64.685, -97.796, -83.889 };
			const float len_to_set = { 76.174 };
			const auto &ret_vec = setlen(vec, len_to_set);
			const auto vec_len = len<3>(vec);
			
			REQUIRE( vec_len == Approx(len_to_set) );
			
			REQUIRE( &vec == &ret_vec);
			//test edge case 0.0
			const auto &ret_zero_vec = setlen<3>(vec, cnst<float>::zero);
			
			REQUIRE( get<0>(vec) == Approx( cnst<float>::zero ) );
			REQUIRE( get<1>(vec) == Approx( cnst<float>::zero ) );
			REQUIRE( get<2>(vec) == Approx( cnst<float>::zero ) );
			REQUIRE( &vec == &ret_zero_vec);
		}
		{
			vec4<float> vec = { -87.059, 91.527, 46.720, -39.516 };
			const float len_to_set = { 5.022 };
			const auto &ret_vec = setlen(vec, len_to_set);
			const auto vec_len = len<4>(vec);
			
			REQUIRE( vec_len == Approx(len_to_set) );
			
			REQUIRE( &vec == &ret_vec);
			//test edge case 0.0
			const auto &ret_zero_vec = setlen<4>(vec, cnst<float>::zero);
			
			REQUIRE( get<0>(vec) == Approx( cnst<float>::zero ) );
			REQUIRE( get<1>(vec) == Approx( cnst<float>::zero ) );
			REQUIRE( get<2>(vec) == Approx( cnst<float>::zero ) );
			REQUIRE( get<3>(vec) == Approx( cnst<float>::zero ) );
			REQUIRE( &vec == &ret_zero_vec);
		}
	}
	
	SECTION( "Calculate the length of the vector, prefere len_sqr when comparing distances/1" )
	{
		{
			const vec4<float> vec = { -55.346, 64.931, -71.991, 18.044 };
			const auto vec_len = len<-3>(vec);
			const auto vec_square_len = get<-3>(vec) * get<-3>(vec) + get<-2>(vec) * get<-2>(vec) + get<-1>(vec) * get<-1>(vec);
			REQUIRE( vec_len == Approx( s::sqrt( vec_square_len ) ) );
			
			//test edge case 0.0
			const vec4<float> zero_vec = { 0, 0, 0, 0 };
			const auto zero_vec_len = len<-3>(zero_vec);
			REQUIRE( zero_vec_len == Approx( cnst<float>::zero ) );
		}
		{
			const vec4<float> vec = { 30.556, -30.752, 44.111, -87.757 };
			const auto vec_len = len<-2>(vec);
			const auto vec_square_len = get<-2>(vec) * get<-2>(vec) + get<-1>(vec) * get<-1>(vec);
			REQUIRE( vec_len == Approx( s::sqrt( vec_square_len ) ) );
			
			//test edge case 0.0
			const vec4<float> zero_vec = { 0, 0, 0, 0 };
			const auto zero_vec_len = len<-2>(zero_vec);
			REQUIRE( zero_vec_len == Approx( cnst<float>::zero ) );
		}
		{
			const vec4<float> vec = { 31.643, -20.870, 99.803, 15.063 };
			const auto vec_len = len<2>(vec);
			const auto vec_square_len = get<0>(vec) * get<0>(vec) + get<1>(vec) * get<1>(vec);
			REQUIRE( vec_len == Approx( s::sqrt( vec_square_len ) ) );
			
			//test edge case 0.0
			const vec4<float> zero_vec = { 0, 0, 0, 0 };
			const auto zero_vec_len = len<2>(zero_vec);
			REQUIRE( zero_vec_len == Approx( cnst<float>::zero ) );
		}
		{
			const vec4<float> vec = { 91.631, 95.936, 79.751, 32.164 };
			const auto vec_len = len<3>(vec);
			const auto vec_square_len = get<0>(vec) * get<0>(vec) + get<1>(vec) * get<1>(vec) + get<2>(vec) * get<2>(vec);
			REQUIRE( vec_len == Approx( s::sqrt( vec_square_len ) ) );
			
			//test edge case 0.0
			const vec4<float> zero_vec = { 0, 0, 0, 0 };
			const auto zero_vec_len = len<3>(zero_vec);
			REQUIRE( zero_vec_len == Approx( cnst<float>::zero ) );
		}
		{
			const vec4<float> vec = { -98.242, -47.634, 11.530, -23.339 };
			const auto vec_len = len<4>(vec);
			const auto vec_square_len = get<0>(vec) * get<0>(vec) + get<1>(vec) * get<1>(vec) + get<2>(vec) * get<2>(vec) + get<3>(vec) * get<3>(vec);
			REQUIRE( vec_len == Approx( s::sqrt( vec_square_len ) ) );
			
			//test edge case 0.0
			const vec4<float> zero_vec = { 0, 0, 0, 0 };
			const auto zero_vec_len = len<4>(zero_vec);
			REQUIRE( zero_vec_len == Approx( cnst<float>::zero ) );
		}
	}
	
	SECTION( "Calculate the square length of the vector/1" )
	{
		{
			const vec4<float> vec = { -20.869, -42.571, -66.230, 96.213 };
			const auto vec_len_sqr = len_sqr<-3>(vec);
			const auto vec_len_sqr_check = get<-3>(vec) * get<-3>(vec) + get<-2>(vec) * get<-2>(vec) + get<-1>(vec) * get<-1>(vec);
			REQUIRE( vec_len_sqr == Approx( vec_len_sqr_check ) );
			
			//test edge case 0.0
			const vec4<float> zero_vec = { 0, 0, 0, 0 };
			const auto zero_vec_len_sqr = len_sqr<-3>(zero_vec);
			REQUIRE( zero_vec_len_sqr == Approx( cnst<float>::zero ) );
		}
		{
			const vec4<float> vec = { 63.923, -29.223, 83.438, -89.235 };
			const auto vec_len_sqr = len_sqr<-2>(vec);
			const auto vec_len_sqr_check = get<-2>(vec) * get<-2>(vec) + get<-1>(vec) * get<-1>(vec);
			REQUIRE( vec_len_sqr == Approx( vec_len_sqr_check ) );
			
			//test edge case 0.0
			const vec4<float> zero_vec = { 0, 0, 0, 0 };
			const auto zero_vec_len_sqr = len_sqr<-2>(zero_vec);
			REQUIRE( zero_vec_len_sqr == Approx( cnst<float>::zero ) );
		}
		{
			const vec4<float> vec = { 64.109, -5.500, -59.844, -71.993 };
			const auto vec_len_sqr = len_sqr<2>(vec);
			const auto vec_len_sqr_check = get<0>(vec) * get<0>(vec) + get<1>(vec) * get<1>(vec);
			REQUIRE( vec_len_sqr == Approx( vec_len_sqr_check ) );
			
			//test edge case 0.0
			const vec4<float> zero_vec = { 0, 0, 0, 0 };
			const auto zero_vec_len_sqr = len_sqr<2>(zero_vec);
			REQUIRE( zero_vec_len_sqr == Approx( cnst<float>::zero ) );
		}
		{
			const vec4<float> vec = { 35.807, 23.679, -44.516, -17.864 };
			const auto vec_len_sqr = len_sqr<3>(vec);
			const auto vec_len_sqr_check = get<0>(vec) * get<0>(vec) + get<1>(vec) * get<1>(vec) + get<2>(vec) * get<2>(vec);
			REQUIRE( vec_len_sqr == Approx( vec_len_sqr_check ) );
			
			//test edge case 0.0
			const vec4<float> zero_vec = { 0, 0, 0, 0 };
			const auto zero_vec_len_sqr = len_sqr<3>(zero_vec);
			REQUIRE( zero_vec_len_sqr == Approx( cnst<float>::zero ) );
		}
		{
			const vec4<float> vec = { -55.271, 54.458, 53.365, -77.151 };
			const auto vec_len_sqr = len_sqr<4>(vec);
			const auto vec_len_sqr_check = get<0>(vec) * get<0>(vec) + get<1>(vec) * get<1>(vec) + get<2>(vec) * get<2>(vec) + get<3>(vec) * get<3>(vec);
			REQUIRE( vec_len_sqr == Approx( vec_len_sqr_check ) );
			
			//test edge case 0.0
			const vec4<float> zero_vec = { 0, 0, 0, 0 };
			const auto zero_vec_len_sqr = len_sqr<4>(zero_vec);
			REQUIRE( zero_vec_len_sqr == Approx( cnst<float>::zero ) );
		}
	}
	
	SECTION( "Returns a normalized vector/1" )
	{
		const vec4<float> vec = { 9.297, 68.259, 31.885, 1.285 };
		const auto new_norm_vec = norm_mk<-3>(vec);
		const auto norm_len = len<-3>(new_norm_vec);
		REQUIRE( norm_len == Approx( cnst<float>::one ) );
		const vec4<float> vec = { -91.230, -7.666, 64.986, -43.384 };
		const auto new_norm_vec = norm_mk<-2>(vec);
		const auto norm_len = len<-2>(new_norm_vec);
		REQUIRE( norm_len == Approx( cnst<float>::one ) );
		const vec4<float> vec = { 74.225, 27.629, 69.916, 65.982 };
		const auto new_norm_vec = norm_mk<2>(vec);
		const auto norm_len = len<2>(new_norm_vec);
		REQUIRE( norm_len == Approx( cnst<float>::one ) );
		const vec4<float> vec = { -12.719, 13.388, 8.611, -44.171 };
		const auto new_norm_vec = norm_mk<3>(vec);
		const auto norm_len = len<3>(new_norm_vec);
		REQUIRE( norm_len == Approx( cnst<float>::one ) );
		const vec4<float> vec = { 17.159, -30.164, -58.525, -63.254 };
		const auto new_norm_vec = norm_mk<4>(vec);
		const auto norm_len = len<4>(new_norm_vec);
		REQUIRE( norm_len == Approx( cnst<float>::one ) );
	}
	
	SECTION( "Returns a normalized vector, use alternative vector if the current vector length is 0/1" )
	{
		const vec4<float> zero_vec = { 0, 0, 0, 0 };
		const auto zero_len = len<-3>(zero_vec);
		REQUIRE( zero_len == Approx( cnst<float>::zero ) );
		
		vec4<float> unit_vec = { 0, 0, 0, 0 };
		set<0>(unit_vec, cnst<float>::one);
		
		const auto new_unit_vec = norm_mk<-3>(zero_vec, unit_vec);
		const auto new_unit_vec_len = len<-3>(new_unit_vec);
		REQUIRE( new_unit_vec_len == Approx( cnst<float>::one ) );
		REQUIRE( get<0>(new_unit_vec) == Approx( cnst<float>::one ) );
		const vec4<float> zero_vec = { 0, 0, 0, 0 };
		const auto zero_len = len<-2>(zero_vec);
		REQUIRE( zero_len == Approx( cnst<float>::zero ) );
		
		vec4<float> unit_vec = { 0, 0, 0, 0 };
		set<0>(unit_vec, cnst<float>::one);
		
		const auto new_unit_vec = norm_mk<-2>(zero_vec, unit_vec);
		const auto new_unit_vec_len = len<-2>(new_unit_vec);
		REQUIRE( new_unit_vec_len == Approx( cnst<float>::one ) );
		REQUIRE( get<0>(new_unit_vec) == Approx( cnst<float>::one ) );
		const vec4<float> zero_vec = { 0, 0, 0, 0 };
		const auto zero_len = len<2>(zero_vec);
		REQUIRE( zero_len == Approx( cnst<float>::zero ) );
		
		vec4<float> unit_vec = { 0, 0, 0, 0 };
		set<0>(unit_vec, cnst<float>::one);
		
		const auto new_unit_vec = norm_mk<2>(zero_vec, unit_vec);
		const auto new_unit_vec_len = len<2>(new_unit_vec);
		REQUIRE( new_unit_vec_len == Approx( cnst<float>::one ) );
		REQUIRE( get<0>(new_unit_vec) == Approx( cnst<float>::one ) );
		const vec4<float> zero_vec = { 0, 0, 0, 0 };
		const auto zero_len = len<3>(zero_vec);
		REQUIRE( zero_len == Approx( cnst<float>::zero ) );
		
		vec4<float> unit_vec = { 0, 0, 0, 0 };
		set<0>(unit_vec, cnst<float>::one);
		
		const auto new_unit_vec = norm_mk<3>(zero_vec, unit_vec);
		const auto new_unit_vec_len = len<3>(new_unit_vec);
		REQUIRE( new_unit_vec_len == Approx( cnst<float>::one ) );
		REQUIRE( get<0>(new_unit_vec) == Approx( cnst<float>::one ) );
		const vec4<float> zero_vec = { 0, 0, 0, 0 };
		const auto zero_len = len<4>(zero_vec);
		REQUIRE( zero_len == Approx( cnst<float>::zero ) );
		
		vec4<float> unit_vec = { 0, 0, 0, 0 };
		set<0>(unit_vec, cnst<float>::one);
		
		const auto new_unit_vec = norm_mk<4>(zero_vec, unit_vec);
		const auto new_unit_vec_len = len<4>(new_unit_vec);
		REQUIRE( new_unit_vec_len == Approx( cnst<float>::one ) );
		REQUIRE( get<0>(new_unit_vec) == Approx( cnst<float>::one ) );
	}
	
	SECTION( "Normalize the current vector/1" )
	{
		vec4<float> vec = { -97.805, -2.498, -89.937, 83.113 };
		norm_set<-3>(vec);
		const auto len_of_norm_vec = len<-3>(vec);
		REQUIRE( len_of_norm_vec == Approx( cnst<float>::one ) );
		vec4<float> vec = { 76.661, 54.562, 89.966, 0.972 };
		norm_set<-2>(vec);
		const auto len_of_norm_vec = len<-2>(vec);
		REQUIRE( len_of_norm_vec == Approx( cnst<float>::one ) );
		vec4<float> vec = { 79.548, 60.731, 84.250, 80.794 };
		norm_set<2>(vec);
		const auto len_of_norm_vec = len<2>(vec);
		REQUIRE( len_of_norm_vec == Approx( cnst<float>::one ) );
		vec4<float> vec = { 15.910, -56.508, 42.835, 91.443 };
		norm_set<3>(vec);
		const auto len_of_norm_vec = len<3>(vec);
		REQUIRE( len_of_norm_vec == Approx( cnst<float>::one ) );
		vec4<float> vec = { -80.435, 49.484, -66.180, -81.802 };
		norm_set<4>(vec);
		const auto len_of_norm_vec = len<4>(vec);
		REQUIRE( len_of_norm_vec == Approx( cnst<float>::one ) );
	}
	
	SECTION( "Normalize the current vector, use alternative vector if the current vector length is 0/1" )
	{
		vec4<float> vec = { 0, 0, 0, 0 };
		const auto zero_len = len<-3>(vec);
		REQUIRE( zero_len == Approx( cnst<float>::zero ) );
		
		vec4<float> unit_vec = { 0, 0, 0, 0 };
		set<0>(unit_vec, cnst<float>::one);
		
		norm_set<-3>(vec, unit_vec);
		const auto vec_len = len<-3>(vec);
		REQUIRE( vec_len == Approx( cnst<float>::one ) );
		REQUIRE( get<0>(vec) == Approx( cnst<float>::one ) );
		vec4<float> vec = { 0, 0, 0, 0 };
		const auto zero_len = len<-2>(vec);
		REQUIRE( zero_len == Approx( cnst<float>::zero ) );
		
		vec4<float> unit_vec = { 0, 0, 0, 0 };
		set<0>(unit_vec, cnst<float>::one);
		
		norm_set<-2>(vec, unit_vec);
		const auto vec_len = len<-2>(vec);
		REQUIRE( vec_len == Approx( cnst<float>::one ) );
		REQUIRE( get<0>(vec) == Approx( cnst<float>::one ) );
		vec4<float> vec = { 0, 0, 0, 0 };
		const auto zero_len = len<2>(vec);
		REQUIRE( zero_len == Approx( cnst<float>::zero ) );
		
		vec4<float> unit_vec = { 0, 0, 0, 0 };
		set<0>(unit_vec, cnst<float>::one);
		
		norm_set<2>(vec, unit_vec);
		const auto vec_len = len<2>(vec);
		REQUIRE( vec_len == Approx( cnst<float>::one ) );
		REQUIRE( get<0>(vec) == Approx( cnst<float>::one ) );
		vec4<float> vec = { 0, 0, 0, 0 };
		const auto zero_len = len<3>(vec);
		REQUIRE( zero_len == Approx( cnst<float>::zero ) );
		
		vec4<float> unit_vec = { 0, 0, 0, 0 };
		set<0>(unit_vec, cnst<float>::one);
		
		norm_set<3>(vec, unit_vec);
		const auto vec_len = len<3>(vec);
		REQUIRE( vec_len == Approx( cnst<float>::one ) );
		REQUIRE( get<0>(vec) == Approx( cnst<float>::one ) );
		vec4<float> vec = { 0, 0, 0, 0 };
		const auto zero_len = len<4>(vec);
		REQUIRE( zero_len == Approx( cnst<float>::zero ) );
		
		vec4<float> unit_vec = { 0, 0, 0, 0 };
		set<0>(unit_vec, cnst<float>::one);
		
		norm_set<4>(vec, unit_vec);
		const auto vec_len = len<4>(vec);
		REQUIRE( vec_len == Approx( cnst<float>::one ) );
		REQUIRE( get<0>(vec) == Approx( cnst<float>::one ) );
	}
	
	SECTION( "Normalize the current vector and return the same vector (chained)/1" )
	{
		vec4<float> vec = { -22.158, -9.729, 77.540, 8.166 };
		const auto &ret_vec = norm<-3>(vec);
		const auto len_of_norm_vec = len<-3>(vec);
		REQUIRE( len_of_norm_vec == Approx( cnst<float>::one ) );
		REQUIRE( &vec == &ret_vec);
		vec4<float> vec = { 77.828, -17.454, 86.022, 2.399 };
		const auto &ret_vec = norm<-2>(vec);
		const auto len_of_norm_vec = len<-2>(vec);
		REQUIRE( len_of_norm_vec == Approx( cnst<float>::one ) );
		REQUIRE( &vec == &ret_vec);
		vec4<float> vec = { -83.996, 5.982, -14.506, -64.685 };
		const auto &ret_vec = norm<2>(vec);
		const auto len_of_norm_vec = len<2>(vec);
		REQUIRE( len_of_norm_vec == Approx( cnst<float>::one ) );
		REQUIRE( &vec == &ret_vec);
		vec4<float> vec = { -97.796, -83.889, -76.174, -87.059 };
		const auto &ret_vec = norm<3>(vec);
		const auto len_of_norm_vec = len<3>(vec);
		REQUIRE( len_of_norm_vec == Approx( cnst<float>::one ) );
		REQUIRE( &vec == &ret_vec);
		vec4<float> vec = { 91.527, 46.720, -39.516, 5.022 };
		const auto &ret_vec = norm<4>(vec);
		const auto len_of_norm_vec = len<4>(vec);
		REQUIRE( len_of_norm_vec == Approx( cnst<float>::one ) );
		REQUIRE( &vec == &ret_vec);
	}
	
	SECTION( "Normalize the current vector and return the same vector (chained), use alternative vector if the current vector length is 0/1" )
	{
		vec4<float> vec = { 0, 0, 0, 0 };
		const auto zero_len = len<-3>(vec);
		REQUIRE( zero_len == Approx( cnst<float>::zero ) );
		
		vec4<float> unit_vec = { 0, 0, 0, 0 };
		set<0>(unit_vec, cnst<float>::one);
		
		const auto &ret_vec = norm<-3>(vec, unit_vec);
		const auto vec_len = len<-3>(vec);
		REQUIRE( vec_len == Approx( cnst<float>::one ) );
		REQUIRE( get<0>(vec) == Approx( cnst<float>::one ) );
		REQUIRE( &vec == &ret_vec);
		vec4<float> vec = { 0, 0, 0, 0 };
		const auto zero_len = len<-2>(vec);
		REQUIRE( zero_len == Approx( cnst<float>::zero ) );
		
		vec4<float> unit_vec = { 0, 0, 0, 0 };
		set<0>(unit_vec, cnst<float>::one);
		
		const auto &ret_vec = norm<-2>(vec, unit_vec);
		const auto vec_len = len<-2>(vec);
		REQUIRE( vec_len == Approx( cnst<float>::one ) );
		REQUIRE( get<0>(vec) == Approx( cnst<float>::one ) );
		REQUIRE( &vec == &ret_vec);
		vec4<float> vec = { 0, 0, 0, 0 };
		const auto zero_len = len<2>(vec);
		REQUIRE( zero_len == Approx( cnst<float>::zero ) );
		
		vec4<float> unit_vec = { 0, 0, 0, 0 };
		set<0>(unit_vec, cnst<float>::one);
		
		const auto &ret_vec = norm<2>(vec, unit_vec);
		const auto vec_len = len<2>(vec);
		REQUIRE( vec_len == Approx( cnst<float>::one ) );
		REQUIRE( get<0>(vec) == Approx( cnst<float>::one ) );
		REQUIRE( &vec == &ret_vec);
		vec4<float> vec = { 0, 0, 0, 0 };
		const auto zero_len = len<3>(vec);
		REQUIRE( zero_len == Approx( cnst<float>::zero ) );
		
		vec4<float> unit_vec = { 0, 0, 0, 0 };
		set<0>(unit_vec, cnst<float>::one);
		
		const auto &ret_vec = norm<3>(vec, unit_vec);
		const auto vec_len = len<3>(vec);
		REQUIRE( vec_len == Approx( cnst<float>::one ) );
		REQUIRE( get<0>(vec) == Approx( cnst<float>::one ) );
		REQUIRE( &vec == &ret_vec);
		vec4<float> vec = { 0, 0, 0, 0 };
		const auto zero_len = len<4>(vec);
		REQUIRE( zero_len == Approx( cnst<float>::zero ) );
		
		vec4<float> unit_vec = { 0, 0, 0, 0 };
		set<0>(unit_vec, cnst<float>::one);
		
		const auto &ret_vec = norm<4>(vec, unit_vec);
		const auto vec_len = len<4>(vec);
		REQUIRE( vec_len == Approx( cnst<float>::one ) );
		REQUIRE( get<0>(vec) == Approx( cnst<float>::one ) );
		REQUIRE( &vec == &ret_vec);
	}
	
}
TEST_CASE( "Spacial operations/4", "[vec4<float>(4)]" )
{
	SECTION( "Calculate the angle between two vectors in radian/1" )
	{
		const float random_len1 = { 55.346 };
		const float random_len2 = { 64.931 };
		const float random_len3 = { 71.991 };
		const float random_len4 = { 18.044 };
		
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
		const float random_len1 = { 30.556 };
		const float random_len2 = { 30.752 };
		const float random_len3 = { 44.111 };
		const float random_len4 = { 87.757 };
		
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
		const float random_len1 = { 31.643 };
		const float random_len2 = { 20.87 };
		const float random_len3 = { 99.803 };
		const float random_len4 = { 15.063 };
		
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
		const float random_len1 = { 91.631 };
		const float random_len2 = { 95.936 };
		const float random_len3 = { 79.751 };
		const float random_len4 = { 32.164 };
		
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
		const float random_len1 = { 98.242 };
		const float random_len2 = { 47.634 };
		const float random_len3 = { 11.53 };
		const float random_len4 = { 23.339 };
		
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
		const float random_len1 = { 20.869 };
		const float random_len2 = { 42.571 };
		const float random_len3 = { 66.23 };
		const float random_len4 = { 96.213 };
		
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
		{
			vec4<float> vec = { 0, 0, 0, 0 };
			
			const float val = { 63.923 };
			
			set_all<-3>(vec, val);
  			REQUIRE( get<1>(vec)==val );
			REQUIRE( get<2>(vec)==val );
			REQUIRE( get<3>(vec)==val );
		}
		{
			vec4<float> vec = { 0, 0, 0, 0 };
			
			const float val = { -29.223 };
			
			set_all<-2>(vec, val);
  			REQUIRE( get<2>(vec)==val );
			REQUIRE( get<3>(vec)==val );
		}
		{
			vec4<float> vec = { 0, 0, 0, 0 };
			
			const float val = { 83.438 };
			
			set_all<2>(vec, val);
			REQUIRE( get<0>(vec)==val );
			REQUIRE( get<1>(vec)==val );
		}
		{
			vec4<float> vec = { 0, 0, 0, 0 };
			
			const float val = { -89.235 };
			
			set_all<3>(vec, val);
			REQUIRE( get<0>(vec)==val );
			REQUIRE( get<1>(vec)==val );
			REQUIRE( get<2>(vec)==val );
		}
		{
			vec4<float> vec = { 0, 0, 0, 0 };
			
			const float val = { 64.109 };
			
			set_all<4>(vec, val);
			REQUIRE( get<0>(vec)==val );
			REQUIRE( get<1>(vec)==val );
			REQUIRE( get<2>(vec)==val );
			REQUIRE( get<3>(vec)==val );
		}
	}
	
	SECTION( "Set all vector components individually/1" )
	{
		{
			vec4<float> vec = { 0, 0, 0, 0 };
			const float arr [] = { -5.500, -59.844, -71.993, 35.807 };
			
			set_all<-3>(vec,arr[0], arr[1], arr[2], arr[3]);
			
  			REQUIRE( get<1>(vec)==arr[1] );
			REQUIRE( get<2>(vec)==arr[2] );
			REQUIRE( get<3>(vec)==arr[3] );
		}
		{
			vec4<float> vec = { 0, 0, 0, 0 };
			const float arr [] = { 23.679, -44.516, -17.864, -55.271 };
			
			set_all<-2>(vec,arr[0], arr[1], arr[2], arr[3]);
			
  			REQUIRE( get<2>(vec)==arr[2] );
			REQUIRE( get<3>(vec)==arr[3] );
		}
		{
			vec4<float> vec = { 0, 0, 0, 0 };
			const float arr [] = { 54.458, 53.365, -77.151, 9.297 };
			
			set_all<2>(vec,arr[0], arr[1], arr[2], arr[3]);
			
			REQUIRE( get<0>(vec)==arr[0] );
			REQUIRE( get<1>(vec)==arr[1] );
		}
		{
			vec4<float> vec = { 0, 0, 0, 0 };
			const float arr [] = { 68.259, 31.885, 1.285, -91.230 };
			
			set_all<3>(vec,arr[0], arr[1], arr[2], arr[3]);
			
			REQUIRE( get<0>(vec)==arr[0] );
			REQUIRE( get<1>(vec)==arr[1] );
			REQUIRE( get<2>(vec)==arr[2] );
		}
		{
			vec4<float> vec = { 0, 0, 0, 0 };
			const float arr [] = { -7.666, 64.986, -43.384, 74.225 };
			
			set_all<4>(vec,arr[0], arr[1], arr[2], arr[3]);
			
			REQUIRE( get<0>(vec)==arr[0] );
			REQUIRE( get<1>(vec)==arr[1] );
			REQUIRE( get<2>(vec)==arr[2] );
			REQUIRE( get<3>(vec)==arr[3] );
		}
	}
	
	SECTION( "Set all vector components individually by a fixed size array/1" )
	{
		{
			vec4<float> vec = { 0, 0, 0, 0 };
			const float arr [] = { 27.629, 69.916, 65.982, -12.719 };
			
			set_all<-3>(vec, arr);
			
  			REQUIRE( get<1>(vec)==arr[1] );
			REQUIRE( get<2>(vec)==arr[2] );
			REQUIRE( get<3>(vec)==arr[3] );
		}
		{
			vec4<float> vec = { 0, 0, 0, 0 };
			const float arr [] = { 13.388, 8.611, -44.171, 17.159 };
			
			set_all<-2>(vec, arr);
			
  			REQUIRE( get<2>(vec)==arr[2] );
			REQUIRE( get<3>(vec)==arr[3] );
		}
		{
			vec4<float> vec = { 0, 0, 0, 0 };
			const float arr [] = { -30.164, -58.525, -63.254, -97.805 };
			
			set_all<2>(vec, arr);
			
			REQUIRE( get<0>(vec)==arr[0] );
			REQUIRE( get<1>(vec)==arr[1] );
		}
		{
			vec4<float> vec = { 0, 0, 0, 0 };
			const float arr [] = { -2.498, -89.937, 83.113, 76.661 };
			
			set_all<3>(vec, arr);
			
			REQUIRE( get<0>(vec)==arr[0] );
			REQUIRE( get<1>(vec)==arr[1] );
			REQUIRE( get<2>(vec)==arr[2] );
		}
		{
			vec4<float> vec = { 0, 0, 0, 0 };
			const float arr [] = { 54.562, 89.966, 0.972, 79.548 };
			
			set_all<4>(vec, arr);
			
			REQUIRE( get<0>(vec)==arr[0] );
			REQUIRE( get<1>(vec)==arr[1] );
			REQUIRE( get<2>(vec)==arr[2] );
			REQUIRE( get<3>(vec)==arr[3] );
		}
	}
	
}
TEST_CASE( "Base math vector operations for 4 component vectors/4", "[vec4<float>(4)]" )
{
	vec4<float> add_var_1 = { 60.731, 84.250, 80.794, 15.910 };
	vec4<float> add_var_2 = { -56.508, 42.835, 91.443, -80.435 };
	const float add_scalar = { 49.484 };
	
	const float add_vec_res [] =
		{ get<0>(add_var_1) + get<0>(add_var_2), get<1>(add_var_1) + get<1>(add_var_2), get<2>(add_var_1) + get<2>(add_var_2), get<3>(add_var_1) + get<3>(add_var_2) };
	const float add_scalar_res [] =
		{ get<0>(add_var_1) + add_scalar, get<1>(add_var_1) + add_scalar, get<2>(add_var_1) + add_scalar, get<3>(add_var_1) + add_scalar };
	const float add_vec_scalar_res [] =
		{ get<0>(add_var_1) + get<0>(add_var_2) + add_scalar, get<1>(add_var_1) + get<1>(add_var_2) + add_scalar, get<2>(add_var_1) + get<2>(add_var_2) + add_scalar, get<3>(add_var_1) + get<3>(add_var_2) + add_scalar };
	
	vec4<float> sub_var_1 = { -66.180, -81.802, -22.158, -9.729 };
	vec4<float> sub_var_2 = { 77.540, 8.166, 77.828, -17.454 };
	const float sub_scalar = { 86.022 };
	
	const float sub_vec_res [] =
		{ get<0>(sub_var_1) - get<0>(sub_var_2), get<1>(sub_var_1) - get<1>(sub_var_2), get<2>(sub_var_1) - get<2>(sub_var_2), get<3>(sub_var_1) - get<3>(sub_var_2) };
	const float sub_scalar_res [] =
		{ get<0>(sub_var_1) - sub_scalar, get<1>(sub_var_1) - sub_scalar, get<2>(sub_var_1) - sub_scalar, get<3>(sub_var_1) - sub_scalar };
	const float sub_vec_scalar_res [] =
		{ get<0>(sub_var_1) - get<0>(sub_var_2) - sub_scalar, get<1>(sub_var_1) - get<1>(sub_var_2) - sub_scalar, get<2>(sub_var_1) - get<2>(sub_var_2) - sub_scalar, get<3>(sub_var_1) - get<3>(sub_var_2) - sub_scalar };
	
	vec4<float> mul_var_1 = { 2.399, -83.996, 5.982, -14.506 };
	vec4<float> mul_var_2 = { -64.685, -97.796, -83.889, -76.174 };
	const float mul_scalar = { -87.059 };
	
	const float mul_vec_res [] =
		{ get<0>(mul_var_1) * get<0>(mul_var_2), get<1>(mul_var_1) * get<1>(mul_var_2), get<2>(mul_var_1) * get<2>(mul_var_2), get<3>(mul_var_1) * get<3>(mul_var_2) };
	const float mul_scalar_res [] =
		{ get<0>(mul_var_1) * mul_scalar, get<1>(mul_var_1) * mul_scalar, get<2>(mul_var_1) * mul_scalar, get<3>(mul_var_1) * mul_scalar };
	const float mul_vec_scalar_res [] =
		{ get<0>(mul_var_1) * get<0>(mul_var_2) * mul_scalar, get<1>(mul_var_1) * get<1>(mul_var_2) * mul_scalar, get<2>(mul_var_1) * get<2>(mul_var_2) * mul_scalar, get<3>(mul_var_1) * get<3>(mul_var_2) * mul_scalar };
	
	vec4<float> div_var_1 = { 91.527, 46.720, -39.516, 5.022 };
	vec4<float> div_var_2 = { -55.346, 64.931, -71.991, 18.044 };
	const float div_scalar = { 30.556 };
	
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
		const int idx[] = { 1, 0, 2, 3 };
		const int signs1[] = { 1,-1, 1, 1 };
		const int signs2[] = {-1, 1, 1, 1 };

		{
  
			const vec4<float> test_vec1 = { -30.752, 44.111, -87.757, 31.643 };
			const vec4<float> test_vec2 = {-get<0>(test_vec1), -get<1>(test_vec1), -get<2>(test_vec1), -get<3>(test_vec1)};
			const vec4<float> perpendicular1 = { get<idx[1]>(test_vec1)*signs1[0], get<idx[2]>(test_vec1)*signs1[0], get<idx[3]>(test_vec1)*signs1[0] };
			const vec4<float> perpendicular2 = { get<idx[1]>(test_vec1)*signs2[0], get<idx[2]>(test_vec1)*signs2[0], get<idx[3]>(test_vec1)*signs2[0] };
			const auto test_vec1_len = len(test_vec1);
			const auto test_vec2_len = len(test_vec2);

			REQUIRE( test_vec1_len == Approx(test_vec2_len) );

			const auto dot_prod_colinear_opposite = dot<-3>(test_vec1, test_vec2);
			REQUIRE( dot_prod_colinear_opposite == Approx(-test_vec1_len * test_vec2_len) );

			const auto dot_prod_colinear = dot<-3>(test_vec1, test_vec1);
			REQUIRE( dot_prod_colinear == Approx(test_vec1_len * test_vec1_len) );

			const auto dot_prod_perp1 = dot<-3>(test_vec1, perpendicular1);
			REQUIRE( dot_prod_perp1 == Approx( get<1>(test_vec1) * get<1>(perpendicular1) + get<2>(test_vec1) * get<2>(perpendicular1) + get<3>(test_vec1) * get<3>(perpendicular1) ) );
			const auto dot_prod_perp2 = dot<-3>(test_vec1, perpendicular2);
			REQUIRE( dot_prod_perp2 == Approx( get<1>(test_vec1) * get<1>(perpendicular2) + get<2>(test_vec1) * get<2>(perpendicular2) + get<3>(test_vec1) * get<3>(perpendicular2) ) );
		}
		{
  
			const vec4<float> test_vec1 = { -20.870, 99.803, 15.063, 91.631 };
			const vec4<float> test_vec2 = {-get<0>(test_vec1), -get<1>(test_vec1), -get<2>(test_vec1), -get<3>(test_vec1)};
			const vec4<float> perpendicular1 = { get<idx[2]>(test_vec1)*signs1[1], get<idx[3]>(test_vec1)*signs1[1] };
			const vec4<float> perpendicular2 = { get<idx[2]>(test_vec1)*signs2[1], get<idx[3]>(test_vec1)*signs2[1] };
			const auto test_vec1_len = len(test_vec1);
			const auto test_vec2_len = len(test_vec2);

			REQUIRE( test_vec1_len == Approx(test_vec2_len) );

			const auto dot_prod_colinear_opposite = dot<-2>(test_vec1, test_vec2);
			REQUIRE( dot_prod_colinear_opposite == Approx(-test_vec1_len * test_vec2_len) );

			const auto dot_prod_colinear = dot<-2>(test_vec1, test_vec1);
			REQUIRE( dot_prod_colinear == Approx(test_vec1_len * test_vec1_len) );

			const auto dot_prod_perp1 = dot<-2>(test_vec1, perpendicular1);
			REQUIRE( dot_prod_perp1 == Approx( get<2>(test_vec1) * get<2>(perpendicular1) + get<3>(test_vec1) * get<3>(perpendicular1) ) );
			const auto dot_prod_perp2 = dot<-2>(test_vec1, perpendicular2);
			REQUIRE( dot_prod_perp2 == Approx( get<2>(test_vec1) * get<2>(perpendicular2) + get<3>(test_vec1) * get<3>(perpendicular2) ) );
		}
		{

			const vec4<float> test_vec1 = { 95.936, 79.751, 32.164, -98.242 };
			const vec4<float> test_vec2 = {-get<0>(test_vec1), -get<1>(test_vec1), -get<2>(test_vec1), -get<3>(test_vec1)};
			const vec4<float> perpendicular1 = { get<idx[0]>(test_vec1)*signs1[5], get<idx[1]>(test_vec1)*signs1[5] };
			const vec4<float> perpendicular2 = { get<idx[0]>(test_vec1)*signs2[5], get<idx[1]>(test_vec1)*signs2[5] };
			const auto test_vec1_len = len(test_vec1);
			const auto test_vec2_len = len(test_vec2);

			REQUIRE( test_vec1_len == Approx(test_vec2_len) );

			const auto dot_prod_colinear_opposite = dot<2>(test_vec1, test_vec2);
			REQUIRE( dot_prod_colinear_opposite == Approx(-test_vec1_len * test_vec2_len) );

			const auto dot_prod_colinear = dot<2>(test_vec1, test_vec1);
			REQUIRE( dot_prod_colinear == Approx(test_vec1_len * test_vec1_len) );

			const auto dot_prod_perp1 = dot<2>(test_vec1, perpendicular1);
			REQUIRE( dot_prod_perp1 == Approx( get<0>(test_vec1) * get<0>(perpendicular1) + get<1>(test_vec1) * get<1>(perpendicular1) ) );
			const auto dot_prod_perp2 = dot<2>(test_vec1, perpendicular2);
			REQUIRE( dot_prod_perp2 == Approx( get<0>(test_vec1) * get<0>(perpendicular2) + get<1>(test_vec1) * get<1>(perpendicular2) ) );
		}
		{

			const vec4<float> test_vec1 = { -47.634, 11.530, -23.339, -20.869 };
			const vec4<float> test_vec2 = {-get<0>(test_vec1), -get<1>(test_vec1), -get<2>(test_vec1), -get<3>(test_vec1)};
			const vec4<float> perpendicular1 = { get<idx[0]>(test_vec1)*signs1[6], get<idx[1]>(test_vec1)*signs1[6], get<idx[2]>(test_vec1)*signs1[6] };
			const vec4<float> perpendicular2 = { get<idx[0]>(test_vec1)*signs2[6], get<idx[1]>(test_vec1)*signs2[6], get<idx[2]>(test_vec1)*signs2[6] };
			const auto test_vec1_len = len(test_vec1);
			const auto test_vec2_len = len(test_vec2);

			REQUIRE( test_vec1_len == Approx(test_vec2_len) );

			const auto dot_prod_colinear_opposite = dot<3>(test_vec1, test_vec2);
			REQUIRE( dot_prod_colinear_opposite == Approx(-test_vec1_len * test_vec2_len) );

			const auto dot_prod_colinear = dot<3>(test_vec1, test_vec1);
			REQUIRE( dot_prod_colinear == Approx(test_vec1_len * test_vec1_len) );

			const auto dot_prod_perp1 = dot<3>(test_vec1, perpendicular1);
			REQUIRE( dot_prod_perp1 == Approx( get<0>(test_vec1) * get<0>(perpendicular1) + get<1>(test_vec1) * get<1>(perpendicular1) + get<2>(test_vec1) * get<2>(perpendicular1) ) );
			const auto dot_prod_perp2 = dot<3>(test_vec1, perpendicular2);
			REQUIRE( dot_prod_perp2 == Approx( get<0>(test_vec1) * get<0>(perpendicular2) + get<1>(test_vec1) * get<1>(perpendicular2) + get<2>(test_vec1) * get<2>(perpendicular2) ) );
		}
		{

			const vec4<float> test_vec1 = { -42.571, -66.230, 96.213, 63.923 };
			const vec4<float> test_vec2 = {-get<0>(test_vec1), -get<1>(test_vec1), -get<2>(test_vec1), -get<3>(test_vec1)};
			const vec4<float> perpendicular1 = { get<idx[0]>(test_vec1)*signs1[7], get<idx[1]>(test_vec1)*signs1[7], get<idx[2]>(test_vec1)*signs1[7], get<idx[3]>(test_vec1)*signs1[7] };
			const vec4<float> perpendicular2 = { get<idx[0]>(test_vec1)*signs2[7], get<idx[1]>(test_vec1)*signs2[7], get<idx[2]>(test_vec1)*signs2[7], get<idx[3]>(test_vec1)*signs2[7] };
			const auto test_vec1_len = len(test_vec1);
			const auto test_vec2_len = len(test_vec2);

			REQUIRE( test_vec1_len == Approx(test_vec2_len) );

			const auto dot_prod_colinear_opposite = dot<4>(test_vec1, test_vec2);
			REQUIRE( dot_prod_colinear_opposite == Approx(-test_vec1_len * test_vec2_len) );

			const auto dot_prod_colinear = dot<4>(test_vec1, test_vec1);
			REQUIRE( dot_prod_colinear == Approx(test_vec1_len * test_vec1_len) );

			const auto dot_prod_perp1 = dot<4>(test_vec1, perpendicular1);
			REQUIRE( dot_prod_perp1 == Approx( get<0>(test_vec1) * get<0>(perpendicular1) + get<1>(test_vec1) * get<1>(perpendicular1) + get<2>(test_vec1) * get<2>(perpendicular1) + get<3>(test_vec1) * get<3>(perpendicular1) ) );
			const auto dot_prod_perp2 = dot<4>(test_vec1, perpendicular2);
			REQUIRE( dot_prod_perp2 == Approx( get<0>(test_vec1) * get<0>(perpendicular2) + get<1>(test_vec1) * get<1>(perpendicular2) + get<2>(test_vec1) * get<2>(perpendicular2) + get<3>(test_vec1) * get<3>(perpendicular2) ) );
		}
	}
	
}
