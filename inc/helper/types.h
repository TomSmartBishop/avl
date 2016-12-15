#ifndef AVL_TYPES_H
#define AVL_TYPES_H

/// avl: A Vector Library
/// \author Thomas Pollak
namespace avl
{
	/// Scoped enum for direction information (same, opposite or perpendicular)
	enum class dir : int32_t {
		same,
		opp,
		perpend,
	};
	
	/// Scoped enum extending the base direction information with colinear and colinear+opposite
	enum class dirCol : int32_t {
		same,
		opp,
		perpend,
		colin,
		oppColin,
	};
}

#endif // AVL_TYPES_H
