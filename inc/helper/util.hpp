#ifndef AVL_UTIL_HPP
#define AVL_UTIL_HPP

/// avl: A Vector Library
/// \author Thomas Pollak
namespace avl {
    
	/// Utility class
	struct utl
	{
		template<typename _Ty>
		avl_ainl_res constexpr auto eqls(const _Ty val1, const _Ty val2, const _Ty epsilon) noexcept -> bool
		{
			const _Ty diff = val1 - val2;
			return diff <= epsilon && diff>= -epsilon;
		}
	};
}

#endif // AVL_UTIL_HPP
