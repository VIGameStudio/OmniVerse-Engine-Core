#pragma once

#include <ove/core/util/types.hpp>
#include <vector>

namespace ove
{
	namespace core
	{
		struct tree_node_base_t
		{
		};

		template<typename TUserData>
		struct tree_node_t : public tree_node_base_t
		{
		};

		struct tree_t
		{
		};
	}
}