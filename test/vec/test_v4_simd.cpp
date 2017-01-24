#include "../../ext/catch/catch.hpp"

#include "../../inc/avl.hpp"

TEST_CASE( "SimdVector4 Setters and Getters", "[vec4][simd]" )
{
	__m128 vec;
	const float set_to[] = {-1.5f, 4.1f, 5.3f, 6.9f};

	SECTION("set all components")
	{
		const float all = -3.2f;
		avl::set_all(vec, all);

		REQUIRE( vec[0]==all );
		REQUIRE( vec[1]==all );
		REQUIRE( vec[2]==all );
		REQUIRE( vec[3]==all );
	}
    
    SECTION("set all components via fixed array")
	{
		avl::set_all(vec, set_to);
		
		REQUIRE( vec[0]==set_to[0] );
		REQUIRE( vec[1]==set_to[1] );
        REQUIRE( vec[2]==set_to[2] );
        REQUIRE( vec[3]==set_to[3] );
	}
    
    SECTION("set all components via array")
	{
        const float* arr = set_to;
		avl::set_all<4>(vec, arr);
		
		REQUIRE( vec[0]==set_to[0] );
		REQUIRE( vec[1]==set_to[1] );
        REQUIRE( vec[2]==set_to[2] );
        REQUIRE( vec[3]==set_to[3] );
	}
    
    SECTION("set all components individually")
	{
		avl::set_all(vec, set_to[0], set_to[1], set_to[2], set_to[3]);
		
		REQUIRE( vec[0] == set_to[0] );
		REQUIRE( vec[1] == set_to[1] );
		REQUIRE( vec[2] == set_to[2] );
		REQUIRE( vec[3] == set_to[3] );
	}
	
	SECTION("set/get component")
	{
		avl::set(vec, 0, set_to[0] );
		avl::set(vec, 1, set_to[1] );
		avl::set(vec, 2, set_to[2] );
		avl::set(vec, 3, set_to[3] );
		
		REQUIRE( vec[0] == set_to[0] );
		REQUIRE( vec[1] == set_to[1] );
		REQUIRE( vec[2] == set_to[2] );
		REQUIRE( vec[3] == set_to[3] );
		
		REQUIRE( avl::get(vec, 0) == set_to[0] );
		REQUIRE( avl::get(vec, 1) == set_to[1] );
		REQUIRE( avl::get(vec, 2) == set_to[2] );
		REQUIRE( avl::get(vec, 3) == set_to[3] );
	}
	
	SECTION("set component (static)")
	{
		avl::set<0>(vec, set_to[0]);
		avl::set<1>(vec, set_to[1]);
		avl::set<2>(vec, set_to[2]);
		avl::set<3>(vec, set_to[3]);
		
		REQUIRE( vec[0] == set_to[0] );
		REQUIRE( vec[1] == set_to[1] );
		REQUIRE( vec[2] == set_to[2] );
		REQUIRE( vec[3] == set_to[3] );
	}
}
