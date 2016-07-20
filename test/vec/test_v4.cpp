#include "../../ext/catch/catch.hpp"

#include "../../inc/avl.h"

using namespace avl;

TEST_CASE( "Vector4 setters and getters for vec4", "[vec4]" )
{
	vec4<float> vec;
	const float set_to[] = {-1.5f, 4.1f, 5.3f, 6.9f};
	
	SECTION("set all components")
	{
		const float all = 7.2f;
		set_all(vec, all);
		
		REQUIRE( vec[0]==all );
		REQUIRE( vec[1]==all );
		REQUIRE( vec[2]==all );
		REQUIRE( vec[3]==all );
	}
	
	SECTION("set all components via fixed array")
	{
		set_all(vec, set_to);
		
		REQUIRE( vec[0]==set_to[0] );
		REQUIRE( vec[1]==set_to[1] );
		REQUIRE( vec[2]==set_to[2] );
		REQUIRE( vec[3]==set_to[3] );
	}
	
	SECTION("set all components via array")
	{
		const float *arr = set_to;
		set_all<4>(vec, arr);
		
		REQUIRE( vec[0]==set_to[0] );
		REQUIRE( vec[1]==set_to[1] );
		REQUIRE( vec[2]==set_to[2] );
		REQUIRE( vec[3]==set_to[3] );
	}

	SECTION("set all components individually")
	{
		set_all(vec, set_to[0], set_to[1], set_to[2], set_to[3]);
		
		REQUIRE( vec[0] == set_to[0] );
		REQUIRE( vec[1] == set_to[1] );
		REQUIRE( vec[2] == set_to[2] );
		REQUIRE( vec[3] == set_to[3] );
	}
	
	SECTION("set/get component")
	{
		set(vec, 0, set_to[0] );
		set(vec, 1, set_to[1] );
		set(vec, 2, set_to[2] );
		set(vec, 3, set_to[3] );
		
		REQUIRE( vec[0] == set_to[0] );
		REQUIRE( vec[1] == set_to[1] );
		REQUIRE( vec[2] == set_to[2] );
		REQUIRE( vec[3] == set_to[3] );
		
		REQUIRE( get(vec, 0) == set_to[0] );
		REQUIRE( get(vec, 1) == set_to[1] );
		REQUIRE( get(vec, 2) == set_to[2] );
		REQUIRE( get(vec, 3) == set_to[3] );
	}
	
	SECTION("set component (static)")
	{
		set<0>(vec, set_to[0]);
		set<1>(vec, set_to[1]);
		set<2>(vec, set_to[2]);
		set<3>(vec, set_to[3]);
		
		REQUIRE( vec[0] == set_to[0] );
		REQUIRE( vec[1] == set_to[1] );
		REQUIRE( vec[2] == set_to[2] );
		REQUIRE( vec[3] == set_to[3] );
	}
}
