#pragma once

#include <thread>

#include <ove/core/util/time.hpp>

namespace ove
{
	namespace core
	{
		namespace thread
		{
			template <class R, class P>
			void sleep(const ctime_t<R, P>& duration)
			{
				std::this_thread::sleep_for(duration);
			}
		}
	}
}