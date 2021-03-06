#pragma once

#include <ove/core/util/types.hpp>
#include <ove/core/util/assert.hpp>

#include <vector>

namespace ove
{
	namespace core
	{
		struct pool_base_t
		{
			virtual ~pool_base_t() {}
			virtual void clear() = 0;
		};

		template <typename T>
		struct pool_t : public pool_base_t
		{
		public:
			pool_t(u32 size = 100) { resize(size); }
			virtual ~pool_t() {}

			inline bool empty() const { return m_data.empty(); }

			inline u32 size() const { return m_data.size(); }

			inline void resize(u32 n)
			{
				const size_t dataSize = size();
				m_data.resize(n);

				if (size() > dataSize) {
					for (auto it = m_data.begin() + dataSize; it != m_data.end(); ++it) {
						it->first = false;
					}
				}
			}

			inline void clear() { m_data.clear(); }

			inline void remove(const T& object)
			{
				m_data.erase(std::remove(m_data.begin(), m_data.end(), object),
					m_data.end());
			}

			inline void remove(u32 index) { m_data.erase(m_data.begin() + index); }

			inline bool set(u32 index, const T& object)
			{
				ASSERT(index < size());
				m_data[index].first = true;
				m_data[index].second = object;
				return true;
			}

			inline T& get(u32 index)
			{
				ASSERT(index < size());
				return static_cast<T&>(m_data[index].second);
			}

			inline T& recycle()
			{
				for (auto& e : m_data)
				{
					if (!e.first) {
						e.first = true;
						return static_cast<T&>(e.second);
					}
				}

				resize(size() * 2);
				return recycle();
			}

			inline void add(const T& object)
			{
				auto& obj = recycle();
				obj = object;
			}

			inline T& operator[](u32 index) { return m_data[index].second; }

			inline const T& operator[](u32 index) const { return m_data[index].second; }

			inline std::vector<std::pair<bool, T>>& data() { return m_data; }

		private:
			std::vector<std::pair<bool, T>> m_data;
		};
	}
}