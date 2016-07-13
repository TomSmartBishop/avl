#include "../ext/catch/catch.hpp"

#include "../inc/avl.h"

TEST_CASE( "Basics", "Vector Setters and Getters" ){
    
	//std::int64_t vec0;
    float vec1[2];
	float *vec11 = vec1;
	avl::vec_t<float, 2> v{ vec11 };
	float vec2[3];
	float vec3[4];
    __m128 vec4;
    float vec5[5];
	
    //std::cout << typeid(std::remove_extent_t<vec1>);
	
	//avl::set(vec0, 4.0f);
    avl::set(vec1, 4.0f);
	//avl::set(vec11, 5.0f); //fails because there is no dimension info
	//avl::set(vec5, 5.0f);
    avl::set(v, 5.0f);
    avl::set(vec2, 3.0f);
    avl::set(vec3, 2.0f);
    avl::set(vec4, 1.0f);
	
	avl::set(vec1, 0, 1.0f);
	auto vec1_cmp1 = avl::get(vec1, 1);
	
	avl::set<2>(vec2, 2.0f);
	auto vec3_cmp1 = avl::get<1>(vec3);

	REQUIRE( vec1_cmp1 == 5.0f );
    REQUIRE( vec3_cmp1 == 2.0f );
}
