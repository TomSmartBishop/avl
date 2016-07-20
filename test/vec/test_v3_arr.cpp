#include "../../ext/catch/catch.hpp"

#include "../../inc/avl.h"

using namespace avl;

TEST_CASE( "Vector3 setters and getters for arrays", "[vec3][array]" )
{
	float arr[3];
	const float set_to[] = {6.7f, -1.1f, 0.3f};
	
	SECTION("set all components")
	{
		const float all = 1.7f;
		set_all(arr, all);
		
		REQUIRE( arr[0]==all );
		REQUIRE( arr[1]==all );
		REQUIRE( arr[2]==all );
	}
	
	SECTION("set all components via fixed array")
	{
		set_all(arr, set_to);
		
		REQUIRE( arr[0]==set_to[0] );
		REQUIRE( arr[1]==set_to[1] );
		REQUIRE( arr[2]==set_to[2] );
	}
	
	SECTION("set all components via array")
	{
		set_all<3>(arr, static_cast<const float*>(set_to));
		
		REQUIRE( arr[0]==set_to[0] );
		REQUIRE( arr[1]==set_to[1] );
		REQUIRE( arr[2]==set_to[2] );
	}
	
	SECTION("set all components individually")
	{
		set_all(arr, set_to[0], set_to[1], set_to[2]);
		
		REQUIRE( arr[0] == set_to[0] );
		REQUIRE( arr[1] == set_to[1] );
		REQUIRE( arr[2] == set_to[2] );
	}
	
	SECTION("set/get component")
	{
		set(arr, 0, set_to[0] );
		set(arr, 1, set_to[1] );
		set(arr, 2, set_to[2] );
		
		REQUIRE( arr[0] == set_to[0] );
		REQUIRE( arr[1] == set_to[1] );
		REQUIRE( arr[2] == set_to[2] );
		
		REQUIRE( get(arr, 0) == set_to[0] );
		REQUIRE( get(arr, 1) == set_to[1] );
		REQUIRE( get(arr, 2) == set_to[2] );
	}
	
	SECTION("set/get component (static)")
	{
		set<0>(arr, set_to[0]);
		set<1>(arr, set_to[1]);
		set<2>(arr, set_to[2]);
		
		REQUIRE( arr[0] == set_to[0] );
		REQUIRE( arr[1] == set_to[1] );
		REQUIRE( arr[2] == set_to[2] );
	}
}
