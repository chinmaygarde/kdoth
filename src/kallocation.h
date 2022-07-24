#pragma once

#include "kmacros.h"
#include "kobject.h"
#include "ktypes.h"

K_EXTERN_C_BEGIN

//------------------------------------------------------------------------------
/// Represents a contiguous allocation.
///
K_DEF_OBJECT(KAllocation);

KAllocationRef KAllocationNew();

bool KAllocationTruncate(KAllocationRef allocation, size_t size);

size_t KAllocationGetSize(KAllocationRef allocation);

void* KAllocationGetBuffer(KAllocationRef allocation);

uint32_t KAllocationNextPowerOfTwoSize(uint32_t size);

K_EXTERN_C_END
