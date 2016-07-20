#include "../../ext/catch/catch.hpp"

#include <iostream>
#include "../../inc/avl.h"

using namespace avl;

TEST_CASE( "Vector2 Setters and Getters", "[vec2]" )
{
	float vec[2];
	const float set_to[] = {3.5f, -2.1f};
	
	SECTION("set all components")
	{
		const float all = 1.1f;
		set_all(vec, all);
		
		REQUIRE( vec[0]==all );
		REQUIRE( vec[1]==all );
	}
    
    SECTION("set all components via fixed array")
	{
		set_all(vec, set_to);
		
		REQUIRE( vec[0]==set_to[0] );
		REQUIRE( vec[1]==set_to[1] );
	}
    
    SECTION("set all components via array")
	{
		set_all<2>(vec, static_cast<const float*>(set_to));
		
		REQUIRE( vec[0]==set_to[0] );
		REQUIRE( vec[1]==set_to[1] );
	}
	
	SECTION("set all components individually")
	{
		set_all(vec, set_to[0], set_to[1]);
		
		REQUIRE( vec[0] == set_to[0] );
		REQUIRE( vec[1] == set_to[1] );
	}
	
	SECTION("set/get component")
	{
		set(vec, 0, set_to[0] );
		set(vec, 1, set_to[1] );
		
		REQUIRE( vec[0] == set_to[0] );
		REQUIRE( vec[1] == set_to[1] );
		
		REQUIRE( get(vec, 0) == set_to[0] );
		REQUIRE( get(vec, 1) == set_to[1] );
	}
	
	SECTION("set/get component (static)")
	{
		set<0>(vec, set_to[0] );
		set<1>(vec, set_to[1] );
		
		REQUIRE( vec[0] == set_to[0] );
		REQUIRE( vec[1] == set_to[1] );
		
		REQUIRE( get<0>(vec) == set_to[0] );
		REQUIRE( get<1>(vec) == set_to[1] );
	}
}

TEST_CASE( "Vector2 Base Math", "[vec2]" )
{
	      float f1[]          = {-1.2f, 5.7f};
	      float f2[]          = { 9.2f, 0.3f};
	const float expt_res[]    = { 8.0f, 6.0f};

	const float scalar        =   5.1f;
	const float expt_sc_res[] = {14.3f, 5.4f};
	
	SECTION("Add Make Vector")
	{	
		auto v1 = vec2<float>{f1[0], f1[1]};
		auto v2 = vec2<float>{f2[0], f2[1]};
		constexpr auto d = dim<decltype(v2)>::value;

		auto res = add_mk(v1, v2);

		REQUIRE( res[0] == Approx(expt_res[0]) );
		REQUIRE( res[1] == Approx(expt_res[1]) );

		//we don't wont to point accidentally to the same memory location
		REQUIRE( &(res[0]) != &(v1[0]) );
		REQUIRE( &(res[1]) != &(v1[1]) );
	}
	SECTION("Add Make Scalar")
	{
		auto v2 = vec2<float>{f2[0], f2[1]};

		auto res = add_mk(v2, scalar);

		REQUIRE( res[0] == Approx(expt_sc_res[0]) );
		REQUIRE( res[1] == Approx(expt_sc_res[1]) );
	}
	
	SECTION("Add Set Vector")
	{
		add_set(f1, f2);

		REQUIRE( f1[0] == Approx(expt_res[0]) );
		REQUIRE( f1[1] == Approx(expt_res[1]) );
	}
	
	SECTION("Add Set Scalar")
	{
		add_set(f2, scalar);

		REQUIRE( f2[0] == Approx(expt_sc_res[0]) );
		REQUIRE( f2[1] == Approx(expt_sc_res[1]) );
	}
	
	SECTION("Add (Chained) Vector")
	{

			auto ref_to_f1 = add(f1, f2);

			REQUIRE( f1[0] == Approx(expt_res[0]) );
			REQUIRE( f1[1] == Approx(expt_res[1]) );
			
			REQUIRE( f1[0] == Approx(ref_to_f1[0]) );
			REQUIRE( f1[1] == Approx(ref_to_f1[1]) );
			
			//must be the same memory location
			REQUIRE( &(ref_to_f1[0]) == &(f1[0]) );
			REQUIRE( &(ref_to_f1[1]) == &(f1[1]) );
	}
	
	SECTION("Add (Chained) Scalar")
	{
			auto ref_to_f2 = add(f2, scalar);

			REQUIRE( f2[0] == Approx(expt_sc_res[0]) );
			REQUIRE( f2[1] == Approx(expt_sc_res[1]) );
		
			REQUIRE( f2[0] == Approx(ref_to_f2[0]) );
			REQUIRE( f2[1] == Approx(ref_to_f2[1]) );
		
			//must be the same memory location
			REQUIRE( &(ref_to_f2[0]) == &(f2[0]) );
			REQUIRE( &(ref_to_f2[1]) == &(f2[1]) );

	}
}
