#include "../../ext/catch/catch.hpp"

#include "../../inc/avl.h"

using namespace avl;

TEST_CASE( "Vector3 setters and getters for vec3", "[vec3]" )
{
	vec3<float> vec;
	const float set_to[] = {6.7f, -1.1f, 0.3f};
	
	SECTION("set all components")
	{
		const float all = 1.7f;
		set_all(vec, all);
		
		REQUIRE( vec[0]==all );
		REQUIRE( vec[1]==all );
		REQUIRE( vec[2]==all );
	}
	
	SECTION("set all components via fixed array")
	{
		set_all(vec, set_to);
		
		REQUIRE( vec[0]==set_to[0] );
		REQUIRE( vec[1]==set_to[1] );
		REQUIRE( vec[2]==set_to[2] );
	}
	
	SECTION("set all components via array")
	{
		set_all<3>(vec, static_cast<const float*>(set_to));
		
		REQUIRE( vec[0]==set_to[0] );
		REQUIRE( vec[1]==set_to[1] );
		REQUIRE( vec[2]==set_to[2] );
	}
	
	SECTION("set all components individually")
	{
		set_all(vec, set_to[0], set_to[1], set_to[2]);
		
		REQUIRE( vec[0] == set_to[0] );
		REQUIRE( vec[1] == set_to[1] );
		REQUIRE( vec[2] == set_to[2] );
	}
	
	SECTION("set/get component")
	{
		set(vec, 0, set_to[0] );
		set(vec, 1, set_to[1] );
		set(vec, 2, set_to[2] );
		
		REQUIRE( vec[0] == set_to[0] );
		REQUIRE( vec[1] == set_to[1] );
		REQUIRE( vec[2] == set_to[2] );
		
		REQUIRE( get(vec, 0) == set_to[0] );
		REQUIRE( get(vec, 1) == set_to[1] );
		REQUIRE( get(vec, 2) == set_to[2] );
	}
	
	SECTION("set/get component (static)")
	{
		set<0>(vec, set_to[0]);
		set<1>(vec, set_to[1]);
		set<2>(vec, set_to[2]);
		
		REQUIRE( vec[0] == set_to[0] );
		REQUIRE( vec[1] == set_to[1] );
		REQUIRE( vec[2] == set_to[2] );
	}
}
