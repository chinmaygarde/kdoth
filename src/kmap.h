#pragma once

#include "kmacros.h"
#include "kobject.h"

K_EXTERN_C_BEGIN

K_DEF_OBJECT(KMap);

typedef size_t (*KMapHash)(KObjectRef object);
typedef bool (*KMapEqual)(KObjectRef lhs, KObjectRef rhs);

KMapRef KMapNew(KMapHash hash, KMapEqual equal);

bool KMapSetValue(KMapRef map, KObjectRef key, KObjectRef value);

KObjectRef KMapGetValue(KMapRef map, KObjectRef key);

bool KMapRemoveValue(KMapRef map, KObjectRef key);

size_t KMapGetCount(KMapRef map);

double KMapGetLoadFactor(KMapRef map);

size_t KMapGetMaxBucketUtilization(KMapRef map);

K_EXTERN_C_END
