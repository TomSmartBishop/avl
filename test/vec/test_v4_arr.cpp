#include "../../ext/catch/catch.hpp"

#include "../../inc/avl.h"

using namespace avl;

TEST_CASE( "Vector4 setters and getters for arrays", "[vec4][array]" )
{
	float arr[4];
	const float set_to[] = {-1.5f, 4.1f, 5.3f, 6.9f};
	
	SECTION("set all components")
	{
		const float all = 7.2f;
		set_all(arr, all);
		
		REQUIRE( arr[0]==all );
		REQUIRE( arr[1]==all );
		REQUIRE( arr[2]==all );
		REQUIRE( arr[3]==all );
	}
	
	SECTION("set all components via fixed array")
	{
		set_all(arr, set_to);
		
		REQUIRE( arr[0]==set_to[0] );
		REQUIRE( arr[1]==set_to[1] );
		REQUIRE( arr[2]==set_to[2] );
		REQUIRE( arr[3]==set_to[3] );
	}
	
	SECTION("set all components via array")
	{
		set_all<4>(arr, static_cast<const float*>(set_to));
		
		REQUIRE( arr[0]==set_to[0] );
		REQUIRE( arr[1]==set_to[1] );
		REQUIRE( arr[2]==set_to[2] );
		REQUIRE( arr[3]==set_to[3] );
	}

	SECTION("set all components individually")
	{
		set_all(arr, set_to[0], set_to[1], set_to[2], set_to[3]);
		
		REQUIRE( arr[0] == set_to[0] );
		REQUIRE( arr[1] == set_to[1] );
		REQUIRE( arr[2] == set_to[2] );
		REQUIRE( arr[3] == set_to[3] );
	}
	
	SECTION("set/get component")
	{
		set(arr, 0, set_to[0] );
		set(arr, 1, set_to[1] );
		set(arr, 2, set_to[2] );
		set(arr, 3, set_to[3] );
		
		REQUIRE( arr[0] == set_to[0] );
		REQUIRE( arr[1] == set_to[1] );
		REQUIRE( arr[2] == set_to[2] );
		REQUIRE( arr[3] == set_to[3] );
		
		REQUIRE( get(arr, 0) == set_to[0] );
		REQUIRE( get(arr, 1) == set_to[1] );
		REQUIRE( get(arr, 2) == set_to[2] );
		REQUIRE( get(arr, 3) == set_to[3] );
	}
	
	SECTION("set component (static)")
	{
		set<0>(arr, set_to[0]);
		set<1>(arr, set_to[1]);
		set<2>(arr, set_to[2]);
		set<3>(arr, set_to[3]);
		
		REQUIRE( arr[0] == set_to[0] );
		REQUIRE( arr[1] == set_to[1] );
		REQUIRE( arr[2] == set_to[2] );
		REQUIRE( arr[3] == set_to[3] );
	}
}
