#include "../../ext/catch/catch.hpp"

#include "../../inc/avl.h"

using namespace avl;

TEST_CASE( "Vector2 setters and getters for vec2", "[vec2]" )
{
	vec2<float> vec;
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

TEST_CASE( "Vector2 base math for vec2", "[vec2]" )
{
		  vec2<float> v1          = {-1.2f, 5.7f};
		  vec2<float> v2          = { 9.2f, 0.3f};
	const float expt_vec_res[]    = { 8.0f, 6.0f};

	const float scalar            =   5.1f;
	const float expt_sc_res[]     = {14.3f, 5.4f};

	const float expt_vec_sc_res[] = {13.1f,11.1f};

	SECTION("add make vector")
	{
		auto res = add_mk(v1, v2);

		REQUIRE( res[0] == Approx(expt_vec_res[0]) );
		REQUIRE( res[1] == Approx(expt_vec_res[1]) );

		//we don't wont to point accidentally to the same memory location
		REQUIRE( &res != &v1 );
	}

	SECTION("add make scalar")
	{
		auto res = add_mk(v2, scalar);

		REQUIRE( res[0] == Approx(expt_sc_res[0]) );
		REQUIRE( res[1] == Approx(expt_sc_res[1]) );

		//we don't wont to point accidentally to the same memory location
		REQUIRE( &res != &v2 );
	}

	SECTION("add set vector")
	{
		add_set(v1, v2);

		REQUIRE( v1[0] == Approx(expt_vec_res[0]) );
		REQUIRE( v1[1] == Approx(expt_vec_res[1]) );
	}

	SECTION("add set scalar")
	{
		add_set(v2, scalar);

		REQUIRE( v2[0] == Approx(expt_sc_res[0]) );
		REQUIRE( v2[1] == Approx(expt_sc_res[1]) );
	}

	SECTION("add (chained) vector")
	{
		auto &ref_to_v1 = add(v1, v2);

		REQUIRE( v1[0] == Approx(expt_vec_res[0]) );
		REQUIRE( v1[1] == Approx(expt_vec_res[1]) );

		REQUIRE( v1[0] == Approx(ref_to_v1[0]) );
		REQUIRE( v1[1] == Approx(ref_to_v1[1]) );

		//must be the same memory location
		REQUIRE( &ref_to_v1 == &v1 );
	}

	SECTION("add (chained) scalar")
	{
		auto &ref_to_v2 = add(v2, scalar);

		REQUIRE( v2[0] == Approx(expt_sc_res[0]) );
		REQUIRE( v2[1] == Approx(expt_sc_res[1]) );

		REQUIRE( v2[0] == Approx(ref_to_v2[0]) );
		REQUIRE( v2[1] == Approx(ref_to_v2[1]) );

		//must be the same memory location
		REQUIRE( &ref_to_v2 == &v2 );
	}

	SECTION("add (chained) vector and scalar")
	{
		auto &ref_to_v1 = add(add(v1, v2), scalar);

		REQUIRE( v1[0] == Approx(expt_vec_sc_res[0]) );
		REQUIRE( v1[1] == Approx(expt_vec_sc_res[1]) );

		//must be the same memory location
		REQUIRE( &ref_to_v1 == &v1 );
	}
}
