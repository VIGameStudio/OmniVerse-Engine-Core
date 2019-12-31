#pragma once

#define DEBUG_ASSERT 1

#if DEBUG_ASSERT

#if defined (_MSC_VER)
#define ASSERT(expr) \
			if (!(expr))     \
				__debugbreak();

#elif defined (__GNUC__)
#include <signal.h>
#define ASSERT(expr) \
			if (!(expr))     \
				raise(SIGTRAP);

#else
#error "Unknown compiler"
#endif

#else
#define ASSERT(expr)
#endif