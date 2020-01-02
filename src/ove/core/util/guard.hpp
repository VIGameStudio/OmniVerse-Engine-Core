#pragma once

namespace ove {
	namespace core {
		struct nocopy {
		protected:
			nocopy() = default;
			~nocopy() = default;

		private:
			nocopy(const nocopy&) = delete;
			nocopy& operator=(const nocopy&) = delete;
		};
	}
}