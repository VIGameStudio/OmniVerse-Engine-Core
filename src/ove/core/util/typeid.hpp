#pragma once

#include <ove/core/util/types.hpp>

namespace ove {
	namespace core {
		struct type_base_t {
			virtual size_t id() const = 0;

		protected:
			static size_t reg_id()
			{
				static size_t s_counter = 0;
				return s_counter++;
			}
		};

		template <typename T>
		struct type_t : type_base_t {
			virtual size_t id() const { return gid(); }

			static size_t gid()
			{
				static size_t s_id = reg_id();
				return s_id;
			}
		};
	}
}