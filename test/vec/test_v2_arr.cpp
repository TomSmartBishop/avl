#include "../../ext/catch/catch.hpp"

#include "../../inc/avl.h"

using namespace avl;

TEST_CASE( "Setters and getters for float(2)", "[float(2)]" ) {
	float var[2];
	const float set_to[2] = { 0.9f , 1.8f  };
	
	SECTION("set all components") {
		const float all = -2.5f;
		set_all( var, all);
		
		REQUIRE( var[0] == all );
		REQUIRE( var[1] == all );
	}
	
	SECTION("set all components via fixed array") {
		set_all( var, set_to);
		
		REQUIRE( var[0] == set_to[0] );
		REQUIRE( var[1] == set_to[1] );
	}
	
	SECTION("set all components via array") {
		set_all<2>(var, static_cast<const float*>(set_to));
		
		REQUIRE( var[0] == set_to[0] );
		REQUIRE( var[1] == set_to[1] );
	}
	
	SECTION("set all components individually") {
		set_all(var, set_to[0] ,set_to[1] );
		
		REQUIRE( var[0] == set_to[0] );
		REQUIRE( var[1] == set_to[1] );
	}
	
	SECTION("set/get component") {
		set(var, 0, set_to[0] );
		
		REQUIRE( var[0] == set_to[0] );
		REQUIRE( get(var, 0) == set_to[0] );
		set(var, 1, set_to[1] );
		
		REQUIRE( var[1] == set_to[1] );
		REQUIRE( get(var, 1) == set_to[1] );
	}
	
	SECTION("set/get component (static)") {
		set<0>(var, set_to[0] );
		
		REQUIRE( var[0] == set_to[0] );
		REQUIRE( get<0>(var) == set_to[0] );
		set<1>(var, set_to[1] );
		
		REQUIRE( var[1] == set_to[1] );
		REQUIRE( get<1>(var) == set_to[1] );
	}
}


TEST_CASE( "Add operation for float(2)", "[float(2)]" ) {
	float var_1[2] = { 0.9f , 1.8f  };
	float var_2[2] = { 9.0f , 8.1f  };
	//let the compiler evaluate the result
	const float expt_res_1[2] = { 0.9f + 9.0f , 1.8f + 8.1f  };
	
	const float scalar = 2.1f;
	const float expt_res_2[2] = { 0.9f + 2.1f , 1.8f + 2.1f  };
	
	const float expt_res_3[2] = { 0.9f + 9.0f + 2.1f , 1.8f + 8.1f + 2.1f  };
	
	
	SECTION("add set array") {
		add_set(var_1, var_2);
		
		REQUIRE( var_1[0] == Approx(expt_res_1[0]) );
		REQUIRE( var_1[1] == Approx(expt_res_1[1]) );
	}
	
	SECTION("add set scalar") {
		add_set(var_1, scalar);
		
		REQUIRE( var_1[0] == Approx(expt_res_2[0]) );
		REQUIRE( var_1[1] == Approx(expt_res_2[1]) );
	}
	
	SECTION("add (chained) array") {
		auto &ref_to_1 = add(var_1, var_2);
		
		REQUIRE( var_1[0] == Approx(expt_res_1[0]) );
		REQUIRE( var_1[0] == Approx(ref_to_1[0]) );
		REQUIRE( var_1[1] == Approx(expt_res_1[1]) );
		REQUIRE( var_1[1] == Approx(ref_to_1[1]) );
		
		//must be the same memory location
		REQUIRE( &ref_to_1 == &var_1 );
		//and different here
		REQUIRE( &ref_to_1 != &var_2 );
	}
	
	SECTION("add (chained) scalar") {
		auto &ref_to_1 = add(var_1, scalar);
		
		REQUIRE( var_1[0] == Approx(expt_res_2[0]) );
		REQUIRE( var_1[0] == Approx(ref_to_1[0]) );
		REQUIRE( var_1[1] == Approx(expt_res_2[1]) );
		REQUIRE( var_1[1] == Approx(ref_to_1[1]) );
		
		//must be the same memory location
		REQUIRE( &ref_to_1 == &var_1 );
	}
	
	SECTION("add (chained) array and scalar") {
		auto &ref_to_1 = add(add(var_1, var_2), scalar);
		
		REQUIRE( var_1[0] == Approx(expt_res_3[0]) );
		REQUIRE( var_1[1] == Approx(expt_res_3[1]) );
		
		//must be the same memory location
		REQUIRE( &ref_to_1 == &var_1 );
		//and different here
		REQUIRE( &ref_to_1 != &var_2 );
	}
}


TEST_CASE( "Sub operation for float(2)", "[float(2)]" ) {
	float var_1[2] = { 0.9f , 1.8f  };
	float var_2[2] = { 9.0f , 8.1f  };
	//let the compiler evaluate the result
	const float expt_res_1[2] = { 0.9f - 9.0f , 1.8f - 8.1f  };
	
	const float scalar = 2.1f;
	const float expt_res_2[2] = { 0.9f - 2.1f , 1.8f - 2.1f  };
	
	const float expt_res_3[2] = { 0.9f - 9.0f - 2.1f , 1.8f - 8.1f - 2.1f  };
	
	
	SECTION("sub set array") {
		sub_set(var_1, var_2);
		
		REQUIRE( var_1[0] == Approx(expt_res_1[0]) );
		REQUIRE( var_1[1] == Approx(expt_res_1[1]) );
	}
	
	SECTION("sub set scalar") {
		sub_set(var_1, scalar);
		
		REQUIRE( var_1[0] == Approx(expt_res_2[0]) );
		REQUIRE( var_1[1] == Approx(expt_res_2[1]) );
	}
	
	SECTION("sub (chained) array") {
		auto &ref_to_1 = sub(var_1, var_2);
		
		REQUIRE( var_1[0] == Approx(expt_res_1[0]) );
		REQUIRE( var_1[0] == Approx(ref_to_1[0]) );
		REQUIRE( var_1[1] == Approx(expt_res_1[1]) );
		REQUIRE( var_1[1] == Approx(ref_to_1[1]) );
		
		//must be the same memory location
		REQUIRE( &ref_to_1 == &var_1 );
		//and different here
		REQUIRE( &ref_to_1 != &var_2 );
	}
	
	SECTION("sub (chained) scalar") {
		auto &ref_to_1 = sub(var_1, scalar);
		
		REQUIRE( var_1[0] == Approx(expt_res_2[0]) );
		REQUIRE( var_1[0] == Approx(ref_to_1[0]) );
		REQUIRE( var_1[1] == Approx(expt_res_2[1]) );
		REQUIRE( var_1[1] == Approx(ref_to_1[1]) );
		
		//must be the same memory location
		REQUIRE( &ref_to_1 == &var_1 );
	}
	
	SECTION("sub (chained) array and scalar") {
		auto &ref_to_1 = sub(sub(var_1, var_2), scalar);
		
		REQUIRE( var_1[0] == Approx(expt_res_3[0]) );
		REQUIRE( var_1[1] == Approx(expt_res_3[1]) );
		
		//must be the same memory location
		REQUIRE( &ref_to_1 == &var_1 );
		//and different here
		REQUIRE( &ref_to_1 != &var_2 );
	}
}


TEST_CASE( "Mul operation for float(2)", "[float(2)]" ) {
	float var_1[2] = { 0.9f , 1.8f  };
	float var_2[2] = { 9.0f , 8.1f  };
	//let the compiler evaluate the result
	const float expt_res_1[2] = { 0.9f * 9.0f , 1.8f * 8.1f  };
	
	const float scalar = 2.1f;
	const float expt_res_2[2] = { 0.9f * 2.1f , 1.8f * 2.1f  };
	
	const float expt_res_3[2] = { 0.9f * 9.0f * 2.1f , 1.8f * 8.1f * 2.1f  };
	
	
	SECTION("mul set array") {
		mul_set(var_1, var_2);
		
		REQUIRE( var_1[0] == Approx(expt_res_1[0]) );
		REQUIRE( var_1[1] == Approx(expt_res_1[1]) );
	}
	
	SECTION("mul set scalar") {
		mul_set(var_1, scalar);
		
		REQUIRE( var_1[0] == Approx(expt_res_2[0]) );
		REQUIRE( var_1[1] == Approx(expt_res_2[1]) );
	}
	
	SECTION("mul (chained) array") {
		auto &ref_to_1 = mul(var_1, var_2);
		
		REQUIRE( var_1[0] == Approx(expt_res_1[0]) );
		REQUIRE( var_1[0] == Approx(ref_to_1[0]) );
		REQUIRE( var_1[1] == Approx(expt_res_1[1]) );
		REQUIRE( var_1[1] == Approx(ref_to_1[1]) );
		
		//must be the same memory location
		REQUIRE( &ref_to_1 == &var_1 );
		//and different here
		REQUIRE( &ref_to_1 != &var_2 );
	}
	
	SECTION("mul (chained) scalar") {
		auto &ref_to_1 = mul(var_1, scalar);
		
		REQUIRE( var_1[0] == Approx(expt_res_2[0]) );
		REQUIRE( var_1[0] == Approx(ref_to_1[0]) );
		REQUIRE( var_1[1] == Approx(expt_res_2[1]) );
		REQUIRE( var_1[1] == Approx(ref_to_1[1]) );
		
		//must be the same memory location
		REQUIRE( &ref_to_1 == &var_1 );
	}
	
	SECTION("mul (chained) array and scalar") {
		auto &ref_to_1 = mul(mul(var_1, var_2), scalar);
		
		REQUIRE( var_1[0] == Approx(expt_res_3[0]) );
		REQUIRE( var_1[1] == Approx(expt_res_3[1]) );
		
		//must be the same memory location
		REQUIRE( &ref_to_1 == &var_1 );
		//and different here
		REQUIRE( &ref_to_1 != &var_2 );
	}
}


TEST_CASE( "Div operation for float(2)", "[float(2)]" ) {
	float var_1[2] = { 0.9f , 1.8f  };
	float var_2[2] = { 9.0f , 8.1f  };
	//let the compiler evaluate the result
	const float expt_res_1[2] = { 0.9f / 9.0f , 1.8f / 8.1f  };
	
	const float scalar = 2.1f;
	const float expt_res_2[2] = { 0.9f / 2.1f , 1.8f / 2.1f  };
	
	const float expt_res_3[2] = { 0.9f / 9.0f / 2.1f , 1.8f / 8.1f / 2.1f  };
	
	
	SECTION("div set array") {
		div_set(var_1, var_2);
		
		REQUIRE( var_1[0] == Approx(expt_res_1[0]) );
		REQUIRE( var_1[1] == Approx(expt_res_1[1]) );
	}
	
	SECTION("div set scalar") {
		div_set(var_1, scalar);
		
		REQUIRE( var_1[0] == Approx(expt_res_2[0]) );
		REQUIRE( var_1[1] == Approx(expt_res_2[1]) );
	}
	
	SECTION("div (chained) array") {
		auto &ref_to_1 = div(var_1, var_2);
		
		REQUIRE( var_1[0] == Approx(expt_res_1[0]) );
		REQUIRE( var_1[0] == Approx(ref_to_1[0]) );
		REQUIRE( var_1[1] == Approx(expt_res_1[1]) );
		REQUIRE( var_1[1] == Approx(ref_to_1[1]) );
		
		//must be the same memory location
		REQUIRE( &ref_to_1 == &var_1 );
		//and different here
		REQUIRE( &ref_to_1 != &var_2 );
	}
	
	SECTION("div (chained) scalar") {
		auto &ref_to_1 = div(var_1, scalar);
		
		REQUIRE( var_1[0] == Approx(expt_res_2[0]) );
		REQUIRE( var_1[0] == Approx(ref_to_1[0]) );
		REQUIRE( var_1[1] == Approx(expt_res_2[1]) );
		REQUIRE( var_1[1] == Approx(ref_to_1[1]) );
		
		//must be the same memory location
		REQUIRE( &ref_to_1 == &var_1 );
	}
	
	SECTION("div (chained) array and scalar") {
		auto &ref_to_1 = div(div(var_1, var_2), scalar);
		
		REQUIRE( var_1[0] == Approx(expt_res_3[0]) );
		REQUIRE( var_1[1] == Approx(expt_res_3[1]) );
		
		//must be the same memory location
		REQUIRE( &ref_to_1 == &var_1 );
		//and different here
		REQUIRE( &ref_to_1 != &var_2 );
	}
}


TEST_CASE( "Length operations for float(2)", "[float(2)]" ) {
	float var[2] = { 0.9f , 1.8f  };
	const float sqr = (0.9f * 0.9f) + (1.8f * 1.8f);
	
	SECTION("get length") {
		auto res = len(var);
		
		REQUIRE( res*res == Approx(sqr) );
	}
	
	SECTION("get square length") {
		auto res = len_sqr(var);
		
		REQUIRE( res == Approx(sqr) );
	}
	
	
	SECTION("set length") {
		len_set(var, 6.5f);
		auto res = len(var);
		
		REQUIRE( res == Approx(6.5f) );
	}
}