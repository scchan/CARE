//////////////////////////////////////////////////////////////////////////////////////
// Copyright 2020 Lawrence Livermore National Security, LLC and other CARE developers.
// See the top-level LICENSE file for details.
//
// SPDX-License-Identifier: BSD-3-Clause
//////////////////////////////////////////////////////////////////////////////////////

#ifndef _CARE_GPUMACROS_H_
#define _CARE_GPUMACROS_H_

#if defined(__CUDA_ARCH__) || defined(__HIP_DEVICE_COMPILE__)
#define CARE_DEVICE_COMPILE
#endif

// note: if we use the hipcc compiler wrapper, HIPCC gets defined at compile time.
// However, if we compile with a regular compiler and then include hip_runtime (as is done with chai), then 
// HIPCC won't be defined unless we have a #include <hip/hip_runtime.h> . Please beware if you change
// the way in which CARE is built.
#if defined(__CUDACC__) || defined(__HIPCC__)
#define CARE_GPUCC
#endif

#if defined(CARE_GPUCC)
#define CARE_HOST_DEVICE __host__ __device__
#define CARE_DEVICE __device__
#define CARE_HOST __host__
#define CARE_GLOBAL __global__
#else // defined(CARE_GPUCC)
#define CARE_HOST_DEVICE
#define CARE_DEVICE
#define CARE_HOST
#define CARE_GLOBAL
#endif // defined(CARE_GPUCC)

// set various aliases
#if defined(__CUDACC__)

#define gpuStream_t cudaStream_t
#define gpuHostAllocDefault cudaHostAllocDefault

#define gpuMemcpyKind cudaMemcpyKind
#define gpuMemcpyHostToHost cudaMemcpyHostToHost
#define gpuMemcpyHostToDevice cudaMemcpyHostToDevice
#define gpuMemcpyDeviceToHost cudaMemcpyDeviceToHost
#define gpuMemcpyDeviceToDevice cudaMemcpyDeviceToDevice
#define gpuMemcpyDefault cudaMemcpyDefault

#define gpuSuccess cudaSuccess

#elif defined(__HIPCC__)

#define gpuStream_t hipStream_t
#define gpuHostAllocDefault hipHostAllocDefault;

#define gpuMemcpyKind hipMemcpyKind
#define gpuMemcpyHostToHost hipMemcpyHostToHost
#define gpuMemcpyHostToDevice hipMemcpyHostToDevice
#define gpuMemcpyDeviceToHost hipMemcpyDeviceToHost
#define gpuMemcpyDeviceToDevice hipMemcpyDeviceToDevice
#define gpuMemcpyDefault hipMemcpyDefault

#define gpuSuccess hipSuccess

#endif // end __HIPCC__ case

#endif // !defined(_CARE_GPUMACROS_H_)

