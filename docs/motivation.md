#Motivation

A few words before we start: All comments and constructive critics are very welcome. Just let me know your point and I'm happy to discuss about it.

---

##Why another vector library?

For me personally it is about learning, existing libraries are for sure mature, usable and well performing, but I want to make my own experience, especially with all the new additions to the C++ language which cannot be found in most of today's libraries.

---

Looking at existing 3D vector libraries we can see the following limitations I try to overcome:

* [Unreal Math](https://github.com/EpicGames/UnrealEngine/blob/release/Engine/Source/Runtime/Core/Public/Math/) : Fixed to float, code duplication in vector 2~4 (couldn't see any SIMD support).

* [Eigen](https://bitbucket.org/eigen/eigen) : Difficult to read and explore the code because it uses template meta programming quite extensively (good or bad depending on your point of view - I personally find it difficult to dig into the code)

* [MSFT DirectXMath](https://github.com/Microsoft/DirectXMath): Difficult to use, mostly constrained to float and int32.

* [CML](https://github.com/demianmnave/CML/) : API usage looks quite nice, but no SIMD support. Internally also makes havy use of template code (which again is either good or bad).

Apart from the points mentioned no library has been written with modern C&plus;&plus; in mind(eg. using constexpr, noexcept, concepts, ...) - but that might change any time soon.

I'm not sure if all my goal are achievable, so this is also part of my private reseach... let's see.

---

#Goals

*"Perhaps when we find ourselves wanting everything, it is because we are dangerously close to wanting nothing."*
-- Sylvia Plath

---

## Goals Part I
Apart from learning...

* No code duplication

* Simple and clean interfaces (usually template based libraries and some point get in trouble with this point)

* Can be used with arbitrary floating point type (and maybe also ints)

* Supports 2 to 4 dimensions for vectors, matrices and quaternions

* Support SIMD formats like `__m128`

* Configurable to either use asserts or exceptions
* Minimum runtime costs: Don't pay for something you don't use (eg. no virtual inheritance)

---

## Goals Part II

* Check and calculate as much as possible during compile time (also support constexpr where possible).
* Compatible to arbitrary vector and matrix formats, only requirements are:
 + Component accessor a la `[]` (as a backup this can be always forced with something like `static_cast<float *>(&vector_instance)[idx]`)
 + also plain 2~4 element arrays should work for ad-hoc calculations (for all possible cases, eg, returning an array is not possible in C&plus;&plus;, not sure if 'structured binding' will change anything about that).

* Provide default vector formats compatible to OpenGL, DirectX.

* If a 3rd party vector format does not match the specifications a template wrapper can be used to encapsulate (so the byte size of the vector stays the same)

* Supports all basic vector operations you might expect from a 3D vector library (dot, cross, angle_between, ...)

---

#Design Decisions

* Use trailing return types everywhere.
  When using templates or concepts there are a lot of cases where we need trailing return types. And mixing the 'old style' and trailing return types is quite ugly. Of course since C&plus;&plus;14 we could just entirely skip the return type and just write "auto", but I find that confusing for the API user if you cannot see the return type from the function signature. Also it feels quite natural to first specify the input and then the output.
  ```[C++]
  //first two float inputs and then the float output
  auto func1(float in1, float in2) -> float;
  ```
  VS
  ```[C++]
  //first the float output and then the two float inputs
  float func2(float in1, float in2);
  ```

---

* To avoid code duplication and also allow `constexpr` I rely on the "Uniform Call Syntax" proposal:
  http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0301r1.html
  ```[C++]
  add_set(v1,v2);
  //will be the same as
  v1.add_set(v2);
  ```
  Since this is not supported yet by any compiler I have to stick to the add(v1,v2) syntax style for now. This change has been proposed for C&plus;&plus;17 but unfortunately didn't make it into the standard, so we might see it maybe in C&plus;&plus;20 at the earliest (maybe as TS). That's also the reason why the library got the subtitel "for C&plus;&plus;20... maybe".

---

* Operations should offer a way to modify the actual vector or create a new vector.
  ```[C++]
  //result will create (make) a new vector
  auto v3 = add_mk(v1,v2);
  ```
  Comment: I didn't want to use `add_new` since `new` has another meaning in C++
  ```[C++]
  //result will be applied to the vector
  add_set(v1,v2);
  ```

* And also allow operator chaining:
  ```[C++]
  vec_a.add(vec_b).mul(scalar_x).sub(vec_c).div_set(scalar_y);
  ```
  >Note that the last operation uses div_set instead of div, since div would return the 'this' reference again and therefore produce a warning (unused return value).

---

* Simple interfaces **really simple!** Headers should look clean.
  This would ideally look somewhat like this
  ```[C++]
  void add_set(v2& vec, const v2& other);
  ```
 But I already explained about the trailing return types and we also want to take advantage of other C&plus;&plus; features like `noexcept` and `constexpr`, so let's refine the minimum:
  ```[C++]
  constexpr auto add_set(v2& vec, const v2& other) noexcept -> void;
  ```

---

* (Simple interfaces cont.) And I still want to control wheater the compiler should inline a function and also warn the user about unused return types and therefore need one more additional token, sp that my current interface looks like:
 ```[C++]
 //             Trailing return
 //  Inline and     type                          Won't trough an exception
 //return options     |                                neither asserts
 //    |              |                                       |
 //    V              V                                       V
 avl_ainl constexpr auto add_set(v2& vec, const v2& other) noexcept -> void;
 //           ^                   ^              ^                       ^
 //           |                   `--------------'                       |
 // As mentioned, constexpr               |                              |
 //     whenever possible        In: Accepts 2 vector2             Out: nothing
 ```

---

* No operator overloading apart from `[]` for the component access (and maybe equals).
  The reason for this is that I try to be explicit as much as possible, operator overloading is sometimes confusing with operator priorities and also can cause temporary variables when not using expression templates.

* Issue a warning if there is an unused return value or an uninted usage.

* Use const whenever possible.

* No read/write access to class members inside loops, better use local to calculate and then assign to the member:
  https://www.youtube.com/watch?v=qYN6eduU06s
  (CppCon 2014: Nicolas Fleury "C++ in Huge AAA Games")

---

* Enable high warning level by default and disable temporary around code blocks if needed.
  `-Wall -Wextra -Weffc++ -pedantic -Wshadow -Wsign-compare -Wunused-function -Wunused-label  -Wunused-parameter -Wunused-value  -Wunused-variable`
  I found an elegant way to disable warnings for only specific files... [TODO]

---

* To achieve max compatiblity while still being explicit about all used types &plus; the desire to get simple interfaces I initially decided to use C&plus;&plus; concepts (currently only supported by GCC-6 with the -fconcepts switch).
  Instead of complicated function signatues like this:
  ```[C++]
  template<typename T, std::enable_if<std::is_same<T, MyVec>>>
  constexpr auto add(T& v1, const T& v2) -> T;
  ```
  Concepts allow us to shorten the same to:
  ```[C++]
  constexpr auto add(MyVec& v1, const MyVec& v2) -> MyVec; //MyVec is a concept
  ```
  However there is another factor about that made me rethink that approach.

---

* Eliminate "copy &amp; paste &plus; modify" code. This unfortunately happens frequently when creating similar classes (but not the same).
  A short sample:
  ```[C++]
  avl_ainl_res constexpr auto add(v2& vec, const v2& other) noexcept -> decltype(vec) {
    set_all(vec, get<0>(vec) + get<0>(other), get<1>(vec) + get<1>(other) );
    return vec;
  }
  ```
  ```[C++]
  avl_ainl_res constexpr auto sub(v2& vec, const v2& other) noexcept -> decltype(vec) {
    set_all(vec, get<0>(vec) - get<0>(other), get<1>(vec) - get<1>(other) );
    return vec;
  }
  ```
  And there are even tricker versions...

---
* (Eliminate "copy &amp; paste &plus; modify" cont. 1) The difference between v2 and v3  (and v4) is often only one parameter following a pettern.

  ```[C++]
  avl_ainl_res constexpr auto add(v2& vec, const v2& other) noexcept -> decltype(vec) {
    set_all(vec, get<0>(vec) + get<0>(other), get<1>(vec) + get<1>(other) );
    return vec;
  }
  ```
  ```[C++]
  avl_ainl_res constexpr auto add(v3& vec, const v3& other) noexcept -> decltype(vec) {
	set_all(vec, get<0>(vec) + get<0>(other), get<1>(vec) + get<1>(other), get<2>(vec) + get<2>(other) );
	return vec;
  }
  ```
  So for add, sub, mul and div we end up writing individual versions without significant difference. Changing the interface at a later time is horrible and error prone.

---

* (Eliminate "copy &amp; paste &plus; modify" cont. 2) All these functions could be expressed like this:
  ```[C++]
  avl_ainl_res constexpr auto __OP_NAME__(VEC_T& vec, const VEC_T& other) noexcept -> decltype(vec) {
	set_all(vec, __FOR__(__DIM__){ get<__IDX__>(vec) __OP__ get<__IDX__>(other)) } );
	return vec;
  }
  ```
  So I first started into looking at existing template engines. After some research I found that Jinja could be a fit for this: http://jinja.pocoo.org/ It is a python based template engine API (also used by Mozilla, Instagram, Google, ...) and there is also a stand-alone version (if you don't want to work directly with the API): https://github.com/filwaitman/jinja2-standalone-compiler

---
* (Eliminate "copy &amp; paste &plus; modify" cont. 3) Writing this in Jinja looks like this:
  ```[C++]
  avl_ainl_res constexpr auto {{op_name}}({{vec_type}}& vec, const {{vec_type}}& other) noexcept -> decltype(vec) {
    set_all(vec, {{ helper.cmp_wise_op("get<?>(vec) @ get<?>(other)", op, ", ", dim) }} );
    return vec;
  }
  ```
  With Jinja I can loop over this template for eg. add, sub, mul and div for every vector type and output the result into a source file - so all vector types and operations are always in sync, also when changing the interface. Seemed good at the beginning but unfortunately we are not done yet.

---
* (Eliminate "copy &amp; paste &plus; modify" cont. 4) At some point it is not possible any to implment everything in the header (cyclic depndencies) so I have to seperate header and inline files and also handle asserts/exceptions, so the intial template changes a bit:
  ```[C++]
  avl_ainl_res constexpr auto {{op_name}}({{vec_type}}& vec, const {{vec_type}}& other) noexcept -> decltype(vec){% if type=='h' %};
	{% else %} {
        {% if op_name=="div" %}
		{% for idx in range(dim) %}
		assert(get<{{idx}}>(other)!=decltype(other[{{idx}}]){0});
		{% endfor %}
		{% endif %}
		set_all(vec, {{ helper.cmp_wise_op("get<?>(vec) @ get<?>(other)", op, ", ", dim) }} );
		return vec;
	}
    {% endif %}
  ```
  Ok... now it's getting a bit more complicated. This is hard to read and maintain.
---
* (Eliminate "copy &amp; paste &plus; modify" cont. 5) But when forgetting a second about the complexity I could additionally append a test block to every function and generate testcases like it is possible in dlang:
  ```[C++]
    ...
    return vec;
  }
  {% else type=='test' %}
  SECTION("Testcase for {{op_name}} operation") {
    {{help.create_vec("vec1")}};
    {{help.create_vec("vec2")}};

    ...
  }
  {% endcall %}
  ```
  Yeah, would be nice but it is already really complicated and I actually wanted to keep it simple. Additionally the syntax is quite alienating C&plus;&plus; programmers.

---
* (Eliminate "copy &amp; paste &plus; modify" cont. 6) So I'm currently contemplating how to get a nice, native syntax and still achieve the same. Maybe I can use the C&plus;&plus; macro expansion to achieve the same or use clang's libTooling to preprocess the source code. Anyway the syntax I want to achieve looks like this:
  ```[C++]
  _repeat(_op, {"add","+"}, {"sub", "-"}, {"mul","*"}, {"div", "/"}) {
		avl_ainl_res constexpr auto _op[0]##_mk(const _vec_t& vec, const _scalar_t& other) noexcept {
			return _vec_ret_t(vec) { _for(_idx, _dim, ", ") {get<_idx>(vec) _op[1] get<_idx>(other) } };
		} test {
			_test_scalar_t var1[_dim] = { random_seq(_dim) };
			_test_scalar_t var2[_dim] = { random_seq(_dim) };
			_test_scalar_t result[_dim] = { _for(_idx, _dim, ", ") {var1[_idx] _op[1] var2[_idx]} };
			auto res = _op[0]##_mk(var_1, var_2);
			_for(_idx, _dim) {
				REQUIRE( res[_idx] == Approx(result[_idx]) );
			}
		}
	}
  ```

---

## Drawbacks
 * Small errors sometimes cause a lot and very confusing error messages (with concepts).
 * Concepts syntax might change in the future.
 * No sample material for concepts.
 > So far I failed applying concepts to return parameters.
 * Involves a lot of template code (not exposed to the user API because of concepts) which sometimes is difficult to understand.

---

# Other Things...

## 3rd Party dependencies

* Catch: As test framework. That unfortunately increased compile time by 8(!) sec, but it is easy to use and there is no library needed.

* As mentioned: Currently I'm alsoo using Jinja (+Python) for my stencils but I plan to move to clang's libTooling.

---

## Testing
 * Apart from my own philosophy, concepts (templates) also reuqire a 100% coverage in the test cases since otherwise the template code is never instantiated (compiled).

---

## Current Status

Currently the code is in a very early experimental stage. I just need to put my code somewhere :)
