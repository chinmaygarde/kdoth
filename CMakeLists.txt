cmake_minimum_required(VERSION 3.16.3)

project(kdoth C CXX)

option(K_BUILD_TESTS "Build k.h unit-tests" OFF)

set(C_STANDARD 11)
set(CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if (NOT MSVC)
  add_compile_options(
    -Wall
    -Wextra
    -Werror
    -Wno-unused-parameter
  )
endif()

add_library(kdoth
  src/k.h
  src/kallocation.c
  src/kallocation.h
  src/karray.c
  src/karray.h
  src/kassert.c
  src/kassert.h
  src/kautorelease.c
  src/kautorelease.h
  src/kcondition_variable.c
  src/kcondition_variable.h
  src/kcountdown_latch.c
  src/kcountdown_latch.h
  src/kfile_handle.c
  src/kfile_handle.h
  src/kfile_path.c
  src/kfile_path.h
  src/khash.c
  src/khash.h
  src/klist.c
  src/klist.h
  src/klogging.c
  src/klogging.h
  src/kmacros.h
  src/kmap.c
  src/kmap.h
  src/kmapping.c
  src/kmapping.h
  src/kmutex.c
  src/kmutex.h
  src/kobject.c
  src/kobject.h
  src/kplatform.h
  src/ksemaphore.c
  src/ksemaphore.h
  src/kstring.c
  src/kstring.h
  src/kthread.c
  src/kthread.h
  src/ktime.c
  src/ktime.h
  src/ktypes.h
  src/kworker_pool.c
  src/kworker_pool.h
)

target_include_directories(kdoth
  PUBLIC
    src
)

if(K_BUILD_TESTS)
  enable_testing()

  include(GoogleTest)

  add_subdirectory(third_party/googletest)

  add_executable(kdoth_unittests
    tests/unittests.cc
    tests/cinclude.c
  )

  target_link_libraries(kdoth_unittests
    PRIVATE
      gtest_main
      gtest
      kdoth
  )

  gtest_discover_tests(kdoth_unittests)
endif()

