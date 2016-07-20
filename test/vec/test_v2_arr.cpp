#include "../../ext/catch/catch.hpp"

#include "../../inc/avl.h"

using namespace avl;

TEST_CASE( "Vector2 setters and getters for arrays", "[vec2][array]" )
{
	float arr[2];
	const float set_to[] = {3.5f, -2.1f};

	SECTION("set all components")
	{
		const float all = 1.1f;
		set_all(arr, all);

		REQUIRE( arr[0]==all );
		REQUIRE( arr[1]==all );
	}

	SECTION("set all components via fixed array")
	{
		set_all(arr, set_to);

		REQUIRE( arr[0]==set_to[0] );
		REQUIRE( arr[1]==set_to[1] );
	}

	SECTION("set all components via array")
	{
		set_all<2>(arr, static_cast<const float*>(set_to));

		REQUIRE( arr[0]==set_to[0] );
		REQUIRE( arr[1]==set_to[1] );
	}

	SECTION("set all components individually")
	{
		set_all(arr, set_to[0], set_to[1]);

		REQUIRE( arr[0] == set_to[0] );
		REQUIRE( arr[1] == set_to[1] );
	}

	SECTION("set/get component")
	{
		set(arr, 0, set_to[0] );
		set(arr, 1, set_to[1] );

		REQUIRE( arr[0] == set_to[0] );
		REQUIRE( arr[1] == set_to[1] );

		REQUIRE( get(arr, 0) == set_to[0] );
		REQUIRE( get(arr, 1) == set_to[1] );
	}

	SECTION("set/get component (static)")
	{
		set<0>(arr, set_to[0] );
		set<1>(arr, set_to[1] );

		REQUIRE( arr[0] == set_to[0] );
		REQUIRE( arr[1] == set_to[1] );

		REQUIRE( get<0>(arr) == set_to[0] );
		REQUIRE( get<1>(arr) == set_to[1] );
	}
}

TEST_CASE( "Vector2 base math for arrays", "[vec2]" )
{
		  float arr1[]            = {-1.2f, 5.7f};
		  float arr2[]            = { 9.2f, 0.3f};
	const float expt_vec_res[]    = { 8.0f, 6.0f};

	const float scalar            =   5.1f;
	const float expt_sc_res[]     = {14.3f, 5.4f};

	const float expt_vec_sc_res[] = {13.1f,11.1f};

//not for arrays
//	SECTION("Add Make Vector")
//	{
//	}
//	SECTION("Add Make Scalar")
//	{
//	}

	SECTION("add set vector")
	{
		add_set(arr1, arr2);

		REQUIRE( arr1[0] == Approx(expt_vec_res[0]) );
		REQUIRE( arr1[1] == Approx(expt_vec_res[1]) );
	}

	SECTION("add set scalar")
	{
		add_set(arr2, scalar);

		REQUIRE( arr2[0] == Approx(expt_sc_res[0]) );
		REQUIRE( arr2[1] == Approx(expt_sc_res[1]) );
	}

	SECTION("add (chained) vector")
	{
		auto ref_to_arr1 = add(arr1, arr2);

		REQUIRE( arr1[0] == Approx(expt_vec_res[0]) );
		REQUIRE( arr1[1] == Approx(expt_vec_res[1]) );

		REQUIRE( arr1[0] == Approx(ref_to_arr1[0]) );
		REQUIRE( arr1[1] == Approx(ref_to_arr1[1]) );

		//must be the same memory location
		REQUIRE( &ref_to_arr1[0] == &arr1[0] );
	}

	SECTION("add (chained) scalar")
	{
		auto ref_to_arr2 = add(arr2, scalar);

		REQUIRE( arr2[0] == Approx(expt_sc_res[0]) );
		REQUIRE( arr2[1] == Approx(expt_sc_res[1]) );

		REQUIRE( arr2[0] == Approx(ref_to_arr2[0]) );
		REQUIRE( arr2[1] == Approx(ref_to_arr2[1]) );

		//must be the same memory location
		REQUIRE( &ref_to_arr2[0] == &arr2[0] );
	}

	SECTION("add (chained) vector and scalar")
	{
		auto &ref_to_arr1 = add(add(arr1, arr2), scalar);

		REQUIRE( arr1[0] == Approx(expt_vec_sc_res[0]) );
		REQUIRE( arr1[1] == Approx(expt_vec_sc_res[1]) );

		//must be the same memory location
		REQUIRE( &ref_to_arr1[0] == &arr1[0] );
	}
}
