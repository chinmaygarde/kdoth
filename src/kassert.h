#pragma once

#include "klogging.h"
#include "kmacros.h"

#define K_ASSERT(x)                             \
  {                                             \
    if (!(x)) {                                 \
      K_LOG_ERROR("Assertion failed '" #x "'"); \
      KAbort();                                 \
    }                                           \
  }

#ifndef NDEBUG
#define K_DASSERT K_ASSERT
#else
#define K_DASSERT(...)
#endif

KEXTERN_C_BEGIN

K_NO_RETURN void KAbort();

KEXTERN_C_END
