#ifndef AVL_{{name.upper()}}_H
#define AVL_{{name.upper()}}_H

#pragma once
{% import 'helpers.jin' as h %}

/// avl: A Vector Library
/// \author Thomas Pollak
namespace avl {
	
	/// \defgroup Free functions for {{dim}} component vectors
	/// @{
	
	/// @name Getters and Setters
	/// @{
	
	/// Set all vector components to the same scalar
	avl_ainl constexpr auto set_all({{name}}& vec, const sc scalar) noexcept -> void {
		static_assert(eq<decltype(vec[0]), decltype(scalar)>::value, "Supply a scalar of the vectors element type.");
		{% for idx in range(dim) %}
		vec[{{idx}}] = scalar;
		{% endfor %}
	}
	
	/// Set all vector components individually
	avl_ainl constexpr auto set_all({{name}}& vec{% for cmp in param %}, const sc {{cmp}}{% endfor %}) noexcept -> void {
		{% for idx in range(dim) %}
		static_assert(eq<decltype(vec[{{idx}}]), decltype({{param[idx]}})>::value, "Supply a scalar of the vectors element type for {{param[idx]}}.");
		{% endfor %}
		{% for idx in range(dim) %}
		vec[{{idx}}] = {{param[idx]}};
		{% endfor %}
	}
	
	/// Set all vector components individually
	avl_ainl constexpr auto set_all({{name}}& vec, const sc scalars[{{dim}}]) noexcept -> void {
		{% for idx in range(dim) %}
		static_assert(eq<decltype(vec[{{idx}}]), decltype(scalars[{{idx}}])>::value, "Supply a scalar of the vectors element type.");
		{% endfor %}
		{% for idx in range(dim) %}
		vec[{{idx}}] = scalars[{{idx}}];
		{% endfor %}
	}
	
	/// Set all vector components individually
	template <s::size_t _Dim>
	avl_ainl constexpr auto set_all({{name}}& vec, const sc* scalars) noexcept -> void {
		static_assert(_Dim>={{dim}}, "Supply at least {{dim}} scalars.");
		{% for idx in range(dim) %}
		static_assert(eq<decltype(vec[{{idx}}]), decltype(scalars[{{idx}}])>::value, "Supply a scalar of the vectors element type.");
		{% endfor %}
		{% for idx in range(dim) %}
		vec[{{idx}}] = scalars[{{idx}}];
		{% endfor %}
	}
	
	/// @}
	/// @name General Vector Operations
	/// @{
	{% for op_name, op in [("add", "+"), ("sub", "-"), ("mul", "*"), ("div", "/")] %}
	
	// {{op_name}} make
	
	avl_ainl_res constexpr auto {{op_name}}_mk(const {{name}}& vec, const {{name}}& other) noexcept {//-> rem_const_ref_t<decltype(vec)> { // -> {{name}} {
		{% if op_name=="div" %}
		{% for idx in range(dim) %}
		assert(get<{{idx}}>(other)!=decltype(other[{{idx}}]){0});
		{% endfor %}
		{% endif %}
		return rem_const_ref_t< decltype(vec) > { {{ h.cmp_wise_op("get<?>(vec) @ get<?>(other)", op, ", ", dim) }} };
	}
	
	avl_ainl_res constexpr auto {{op_name}}_mk(const {{name}}& vec, const sc scalar) noexcept {//-> rem_const_ref_t<decltype(vec)> { // -> {{name}} {
		{% if op_name=="div" %}
		assert(scalar!=decltype(scalar){0});
		{% endif %}
		return rem_const_ref_t< decltype(vec) > { {{ h.cmp_wise_op("get<?>(vec) @ scalar", op, ", ", dim) }} };
	}
	
	// {{op_name}} set
	
	avl_ainl constexpr auto {{op_name}}_set({{name}}& vec, const {{name}}& other) noexcept -> void {
		{% if op_name=="div" %}
		{% for idx in range(dim) %}
		assert(get<{{idx}}>(other)!=decltype(other[{{idx}}]){0});
		{% endfor %}
		{% endif %}
		set_all(vec, {{ h.cmp_wise_op("get<?>(vec) @ get<?>(other)", op, ", ", dim) }} );
	}
	
	avl_ainl constexpr auto {{op_name}}_set({{name}}& vec, const sc scalar) noexcept -> void {
		{% if op_name=="div" %}
		assert(scalar!=decltype(scalar){0});
		{% endif %}
		set_all(vec, {{ h.cmp_wise_op("get<?>(vec) @ scalar", op, ", ", dim) }} );
	}
	
	// {{op_name}} (chaining)
	
	avl_ainl_res constexpr auto {{op_name}}({{name}}& vec, const {{name}}& other) noexcept -> decltype(vec) {
		{% if op_name=="div" %}
		{% for idx in range(dim) %}
		assert(get<{{idx}}>(other)!=decltype(other[{{idx}}]){0});
		{% endfor %}
		{% endif %}
		set_all(vec, {{ h.cmp_wise_op("get<?>(vec) @ get<?>(other)", op, ", ", dim) }} );
		return vec;
	}
	
	avl_ainl_res constexpr auto {{op_name}}({{name}}& vec, const sc scalar) noexcept -> decltype(vec) {
		{% if op_name=="div" %}
		assert(scalar!=decltype(scalar){0});
		{% endif %}
		set_all(vec, {{ h.cmp_wise_op("get<?>(vec) @ scalar", op, ", ", dim) }} );
		return vec;
	}
	{% endfor %}
	
	{% if dim==2 %}
	{% include 'v2.jin' %}
	{% elif dim==3 %}
	{% include 'v3.jin' %}
	{% else%}
	{% include 'v4.jin' %}
	{% endif %}
	
	/// @}
	/// @name Vector Length Operations
	/// @{
	
	/// Calculate the square length of the vector
	avl_ainl_res constexpr auto len_sqr(const {{name}}& vec) noexcept -> cmp_t<{{name}}> {
		{% for idx in range(dim) %}
		const auto comp{{idx}} = get<{{idx}}>(vec);
		{% endfor %}
		return {{ h.cmp_wise_op("comp? @ comp?", "*", " + ", dim) }};
	}
	
	/// @}
	/// @name Vector Operations With Scalar Results
	/// @{
	
	avl_ainl_res constexpr auto dot(const {{name}}& vec, const {{name}}& other) noexcept -> cmp_t<{{name}}> {
		return {{ h.cmp_wise_op("get<?>(vec) @ get<?>(other)", "*", " + ", dim) }};
	}
	
	/*
	avl_ainl_res constexpr auto dot(const {{name}}& vec{% for cmp in param %}, const sc {{cmp}}{% endfor %}) noexcept -> cmp_t<{{name}}> {
		return {% for cmp in param %}{% if not loop.first %} + {% endif %}get<{{loop.index0}}>(vec) * {{cmp}}{% endfor %};
	}
	*/
	
	/// @}
	
	/// @}
}
#endif // AVL_{{name.upper()}}_H