#ifndef AVL_V4_SIMD_H
#define AVL_V4_SIMD_H

#pragma once

/// avl: A Vector Library
/// \author Thomas Pollak
namespace avl {

	/// \defgroup Free functions for 4 component SIMD vectors
	/// @{

	/// @name Getters and Setters
	/// @{

	avl_ainl auto set_all(__m128& simd_v, const float scalar) noexcept -> void {
		simd_v = _mm_set1_ps(scalar);
	}

    /// Set all vector components individually
	avl_ainl auto set_all(__m128& vec, const float x, const float y, const float z, const float w) noexcept -> void  {
		vec = _mm_set_ps(w, z, y, x);
	}
    
    /// Set all vector components individually
	avl_ainl auto set_all(__m128& vec, const float scalars[4]) noexcept -> void  {
		vec = _mm_load_ps(scalars);
	}
    
    /// Set all vector components individually
    template <s::size_t _Dim>
	avl_ainl constexpr auto set_all(__m128& vec, const float* scalars) noexcept -> void  {
        static_assert(_Dim>3, "Supply at least 4 scalars.");
		vec = _mm_load_ps(scalars);
	}
    
    
///the component access via _mm_store produce more code than [] accees... profiling needed
	
//	/// Access the simd vector components as value
//	avl_inl_res auto get(const __m128& simd_v, const s::size_t idx) noexcept -> float  {
//		assert(idx < 4);
//		float val[4];
//		_mm_store_ps(val, simd_v );
//		return val[idx];
//	}
//	
//	/// Access the simd vector components as value
//	template<s::size_t _Idx>
//	avl_inl_res auto get(const __m128& simd_v) noexcept -> float  {
//		assert(_Idx < 4);
//		float val[4];
//		_mm_store_ps(val, simd_v );
//		return val[_Idx];
//	}

	/// @}
	
	/// @}
}
#endif // AVL_V4_SIMD_H