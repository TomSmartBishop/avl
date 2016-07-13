#include "../../ext/catch/catch.hpp"

#include "../../inc/avl.h"

TEST_CASE( "Vector3 Setters and Getters", "[vec3]" )
{
	float vec[3];
	const float set_to[] = {6.7f, -1.1f, 0.3f};
	
	SECTION("set all components")
	{
		const float all = 1.7f;
		avl::set_all(vec, all);
		
		REQUIRE( vec[0]==all );
		REQUIRE( vec[1]==all );
		REQUIRE( vec[2]==all );
	}
    
    SECTION("set all components via fixed array")
	{
		avl::set_all(vec, set_to);
		
		REQUIRE( vec[0]==set_to[0] );
		REQUIRE( vec[1]==set_to[1] );
        REQUIRE( vec[2]==set_to[2] );
	}
    
    SECTION("set all components via array")
	{
		avl::set_all<3>(vec, static_cast<const float*>(set_to));
		
		REQUIRE( vec[0]==set_to[0] );
		REQUIRE( vec[1]==set_to[1] );
        REQUIRE( vec[2]==set_to[2] );
	}
	
	SECTION("set all components individually")
	{
		avl::set_all(vec, set_to[0], set_to[1], set_to[2]);
		
		REQUIRE( vec[0] == set_to[0] );
		REQUIRE( vec[1] == set_to[1] );
		REQUIRE( vec[2] == set_to[2] );
	}
	
	SECTION("set/get component")
	{
		avl::set(vec, 0, set_to[0] );
		avl::set(vec, 1, set_to[1] );
		avl::set(vec, 2, set_to[2] );
		
		REQUIRE( vec[0] == set_to[0] );
		REQUIRE( vec[1] == set_to[1] );
		REQUIRE( vec[2] == set_to[2] );
		
		REQUIRE( avl::get(vec, 0) == set_to[0] );
		REQUIRE( avl::get(vec, 1) == set_to[1] );
		REQUIRE( avl::get(vec, 2) == set_to[2] );
	}
	
	SECTION("set/get component (static)")
	{
		avl::set<0>(vec, set_to[0]);
		avl::set<1>(vec, set_to[1]);
		avl::set<2>(vec, set_to[2]);
		
		REQUIRE( vec[0] == set_to[0] );
		REQUIRE( vec[1] == set_to[1] );
		REQUIRE( vec[2] == set_to[2] );
	}
}
