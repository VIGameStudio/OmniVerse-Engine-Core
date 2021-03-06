cmake_minimum_required(VERSION 3.2)

project(OVE_Core)
set(${PROJECT_NAME}_MAJOR_VERSION 0)
set(${PROJECT_NAME}_MINOR_VERSION 1)
set(${PROJECT_NAME}_REVISION_VERSION 1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
set(CMAKE_CXX_STANDARD 11)

include_directories(src)

option(OVE_CORE_BUILD_DEMO "Build demo application." ON)
option(OVE_CORE_BUILD_TEST "Build test targets." OFF)

set(OVE_CORE_SRCS
	# Memory
    src/ove/core/memory/alloc.cpp
    src/ove/core/memory/linear_alloc.cpp
    #src/ove/core/memory/stack_alloc.cpp
    #src/ove/core/memory/freelist_alloc.cpp
    #src/ove/core/memory/pool_alloc.cpp
    #src/ove/core/memory/proxy_alloc.cpp

    # Container

    # Util
)

set(OVE_CORE_HDRS
	# Memory
    src/ove/core/memory/new.hpp
    src/ove/core/memory/ptr_math.hpp
    src/ove/core/memory/alloc.hpp
    src/ove/core/memory/linear_alloc.hpp
    #src/ove/core/memory/stack_alloc.hpp
    #src/ove/core/memory/freelist_alloc.hpp
    #src/ove/core/memory/pool_alloc.hpp
    #src/ove/core/memory/proxy_alloc.hpp

    # Container
    src/ove/core/container/iterator.hpp
    #src/ove/core/container/array.hpp
    #src/ove/core/container/tree.hpp
    #src/ove/core/container/tuple.hpp
    src/ove/core/container/vector.hpp

    # Util
    src/ove/core/util/assert.hpp
    src/ove/core/util/event.hpp
    src/ove/core/util/guard.hpp
    src/ove/core/util/hash.hpp
    src/ove/core/util/meta.hpp
    src/ove/core/util/time.hpp
    src/ove/core/util/typeid.hpp
    src/ove/core/util/types.hpp
    src/ove/core/util/thread.hpp
)

if(MSVC)
    add_library(ove_core STATIC ${OVE_CORE_SRCS} ${OVE_CORE_HDRS})
else()
	add_library(ove_core SHARED ${OVE_CORE_SRCS} ${OVE_CORE_HDRS})
endif()

if(${OVE_CORE_BUILD_DEMO})
    add_executable(demo demo/main.cpp)
    target_link_libraries(demo ove_core)
endif()


if(${OVE_CORE_BUILD_TEST})
    enable_testing()

    add_executable(alloc_test test/alloc_test.cpp)
    add_test(Alloc_test alloc_test)
    target_link_libraries(alloc_test ove_core)

    add_executable(vector_test test/vector_test.cpp)
    add_test(Vector_test vector_test)
    target_link_libraries(vector_test ove_core)
endif()
