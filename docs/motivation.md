#Motivation

A few words before we start: All comments and constructive critics are very welcome. Just let me know you point and I'm happy to discuss about it.


##Why another vector library?

For me personally it is about learning, existing libraries are for sure mature, usable and well performing, but I want to make my own experience, especially with all the new additions to the C++ language which cannot be found in most of today's libraries.

Looking at existing 3D vector libraries we can see the following limitations I try to overcome:

* [Unreal Math](https://github.com/EpicGames/UnrealEngine/blob/release/Engine/Source/Runtime/Core/Public/Math/) : Fixed to float, code duplication in vector 2~4.

* [Eigen](https://bitbucket.org/eigen/eigen) : Difficult to read and explore the code because it uses template meta programming quite extensively

* [MSFT DirectXMath](https://github.com/Microsoft/DirectXMath): Difficult to use, mostly constrained to float and int32.

Apart from the points mentioned no library has been written with modern C&plus;&plus; in mind(eg. using constexpr, concepts, ...) - but that might change any time soon.

I'm not sure if all my goal are achievable, so this is also part of my private reseach... let's see.

#Goals

Apart from learning...

* Can be used with arbitrary floating point type.
* Supports 2 to 4 dimensions for vectors and matrices.
* Minimum runtime costs: Don't pay for something you don't use (eg. no virtual inheritance)
* Check and calculate as much as possible during compile time (also support constexpr where possible).
* No code duplication
* Compatible to arbitrary vector and matrix formats, only requirements are:
 + Component accessor a la "[]"
 + Ideally a static member "dim" for the dimension, otherwise the right function needs to be called (eg. add3 vs add).
 + also plain 2~4 element arrays should work (for all possible cases, eg, returning an array is not possible in C&plus;&plus;, not sure if 'structured binding' will change anything about that).
 + Compatible to OpenGL, DirectX formats.
 + Support SIMD formats like __m128.
 + If a 3rd party vector format does not match the specifications a template wrapper can be used to encapsulate (so the byte size of the vector stays the same)
* Configurable to either use asserts or exceptions
* Supports all basic vector operations you might expect from a 3D vector library (dot, cross, angle_between, ...)

##Design Decisions
* No operator overloading apart from "[]" for the component access (and maybe equals).
> The reason for this is that I try to be explicit as much as possible, operator overloading is sometimes confusing with operator priorities.

* To avoid code duplication and also allow constexpr I rely on the "Uniform Call Syntax" proposal: http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0301r1.html
>```[C++]
>add_set(v1,v2);
>//will be the same as
>v1.add_set(v2);
>```
>Since this is not supported yet by any compiler I have to stick to the add(v1,v2) syntax style for now. This change has been proposed for C&plus;&plus;17 but unfortunately didn't make it into the standard, so we might see it maybe in C&plus;&plus;20 at the earliest (maybe as TS). That's also the reason why the library got the subtitel "for C&plus;&plus;20... maybe".

* Issue a warning if there is an unused return value.

* Use const whenever possible.

* No read/write access to class members inside loops, better use local to calculate and then assign to the member: https://www.youtube.com/watch?v=qYN6eduU06s (CppCon 2014: Nicolas Fleury "C++ in Huge AAA Games")

* Simple interfaces, headers should looks clean.
>Sample:
>```[C++]
>//               Trailing return
>//  Inline and       type                           Won't trough an exception
>//return options       |                                 neither asserts
>//    |                |                                       |
>//    V                V                                       V
>   avl_ainl constexpr auto add_set(v2& vec, const v2& other) noexcept -> void;
>//             ^                   ^              ^                       ^
>//             |                   `--------------'                       |
>//   As mentioned, constexpr               |                              |
>//      whenever possible        In: Accepts 2 vector2              Out: nothing
>```

* Operations should offer to modify the actual vector or create a new vector
>```[C++]
>//result will create (make) a new vector
>auto v3 = add_mk(v1,v2);
>```
>Comment: I didn't want to use add_new since 'new' has another meaning in C++
>```[C++]
>//result will be applied to the vector
>add_set(v1,v2);
>```

* Allow operator chaining:
> ```[C++]
> vec_a.add(vec_b).mul(scalar_x).sub(vec_c).div_set(scalar_y);
>```
>Note that the last operation uses div_set instead of div, since div would return the 'this' reference again and therefore produce a warning (unused return value).

* Evaluate types of parameters
> No double precision arguments if the vector's components are of type single precision (be explicit, specify the type and don't let the compiler implicitly convert).

* Use trailing return types everywhere
> In a lot of cases I need trailing return types and mixing both styles is quite ugly. Of course since C&plus;&plus;14 we could just entirely skip the return type and just write "auto" Also it feels quite natural to first specify the input and then the output.
>```[C++]
>//first two float inputs and then the float output
>auto func1(float in1, float in2) -> float;
>```
>VS
>```[C++]
>//first the float output and then the two float inputs
>float func2(float in1, float in2);
>```

* To achieve max compatiblity while still being explicit about all used types + the desire to get simple interfaces I decided to use C++ concepts. (currently only supported by GCC-6 with the -fconcepts switch).
>```[C++]
>//instead of complicated function signatues like this:
>template<typename T, std::enable_if<std::is_same<T, MyVec>>>
>constexpr auto add(T& v1, const T& v2) -> T;
>```
>```[C++]
>//concepts allow us to shorten the same to:
>constexpr auto add(MyVec& v1, const MyVec& v2) -> MyVec; //MyVec is a concept
>```

* Enable high warning level by default and disable temporary around code blocks if needed.
> -Wall -Wextra -Weffc++ -pedantic -Wshadow -Wsign-compare -Wunused-function -Wunused-label  -Wunused-parameter -Wunused-value  -Wunused-variable

### 3rd Party dependencies

* Catch: As test framework. that unfortunately increased compile time by 8 sec, but it is easy to use and there is no library needed.


# Drawbacks
 * Small errors sometimes cause a lot and very confusing error messages.
 * Concepts syntax might change in the future.
 * No sample material for concepts.
 > So far I failed applying concepts to return parameters.
 * Ivolves a lot of template code (not exposed to the user API because of concepts) which sometimes is difficult to understand.

# Testing
 * Test cases need to cover 100% of the code. This is also an implicit requirement of the library architecture: Templates need to be instanciated so that the compiler can check if they work for the intended type.

# Current Status

Currently the code is in a very early experimental stage. I just need to put my code somewhere :)

