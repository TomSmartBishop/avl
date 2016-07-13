#include "../../ext/catch/catch.hpp"

#include "../../inc/avl.h"

TEST_CASE( "Vector2 Setters and Getters", "[vec2]" )
{
	float vec[2];
	const float set_to[] = {3.5f, -2.1f};
	
	SECTION("set all components")
	{
		const float all = 1.1f;
		avl::set_all(vec, all);
		
		REQUIRE( vec[0]==all );
		REQUIRE( vec[1]==all );
	}
    
    SECTION("set all components via fixed array")
	{
		avl::set_all(vec, set_to);
		
		REQUIRE( vec[0]==set_to[0] );
		REQUIRE( vec[1]==set_to[1] );
	}
    
    SECTION("set all components via array")
	{
		avl::set_all<2>(vec, static_cast<const float*>(set_to));
		
		REQUIRE( vec[0]==set_to[0] );
		REQUIRE( vec[1]==set_to[1] );
	}
	
	SECTION("set all components individually")
	{
		avl::set_all(vec, set_to[0], set_to[1]);
		
		REQUIRE( vec[0] == set_to[0] );
		REQUIRE( vec[1] == set_to[1] );
	}
	
	SECTION("set/get component")
	{
		avl::set(vec, 0, set_to[0] );
		avl::set(vec, 1, set_to[1] );
		
		REQUIRE( vec[0] == set_to[0] );
		REQUIRE( vec[1] == set_to[1] );
		
		REQUIRE( avl::get(vec, 0) == set_to[0] );
		REQUIRE( avl::get(vec, 1) == set_to[1] );
	}
	
	SECTION("set/get component (static)")
	{
		avl::set<0>(vec, set_to[0] );
		avl::set<1>(vec, set_to[1] );
		
		REQUIRE( vec[0] == set_to[0] );
		REQUIRE( vec[1] == set_to[1] );
		
		REQUIRE( avl::get<0>(vec) == set_to[0] );
		REQUIRE( avl::get<1>(vec) == set_to[1] );
	}
}
