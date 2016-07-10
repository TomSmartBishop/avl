#include <stdio.h>
#include "inc/avl.h"

//#include  <cstdint>

int main(int /*argc*/, char ** /* argv */)
{
	//std::int64_t vec0;
    float vec1[2];
	float vec2[3];
	float vec3[4];
    __m128 vec4;
    //std::cout << typeid(std::remove_extent_t<vec1>);
	
	//avl::set(vec0, 4.0f);
    avl::set(vec1, 4.0f);
    avl::set(vec2, 3.0f);
    avl::set(vec3, 2.0f);
    avl::set(vec4, 1.0f);
	
	printf("hello world\n");
	return 0;
}
