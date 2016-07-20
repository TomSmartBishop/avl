#include "../../ext/catch/catch.hpp"

#include "../../inc/avl.h"

using namespace avl;

TEST_CASE( "Test type traits", "[traits]" )
{
	float arr2[] = { 1.1f, -0.9f};
	float arr3[] = { 2.2f, -3.3f,  8.4f};
	float arr4[] = {-3.1f,  2.3f, -0.1f,  7.3f};

	vec2<float> vc2{ 1.1f, -0.9f};
	vec3<float> vc3{ 2.2f, -3.3f,  8.4f};
	vec4<float> vc4{-3.1f,  2.3f, -0.1f,  7.3f};

	SECTION("get array dimension")
	{
		constexpr auto dim2 = dim<decltype(arr2)>::value;
		constexpr auto dim3 = dim<decltype(arr3)>::value;
		constexpr auto dim4 = dim<decltype(arr4)>::value;
		REQUIRE( dim2 == 2 );
		REQUIRE( dim3 == 3 );
		REQUIRE( dim4 == 4 );
	}

	SECTION("get vec dimension")
	{
		constexpr auto dim2 = dim<decltype(vc2)>::value;
		constexpr auto dim3 = dim<decltype(vc3)>::value;
		constexpr auto dim4 = dim<decltype(vc4)>::value;
		REQUIRE( dim2 == 2 );
		REQUIRE( dim3 == 3 );
		REQUIRE( dim4 == 4 );
	}
}
