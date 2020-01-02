#pragma once

#include <chrono>

#include <ove/core/util/types.hpp>

namespace ove {
	namespace core {
		template <typename C>
		struct ctimer_t;

		using sys_timer_t = ctimer_t<std::chrono::system_clock>;
		using steady_timer_t = ctimer_t<std::chrono::steady_clock>;
		using hres_timer_t = ctimer_t<std::chrono::high_resolution_clock>;

		using nano_t = std::nano;
		using micro_t = std::micro;
		using milli_t = std::milli;
		using sec_t = std::ratio<1>;
		using min_t = std::ratio<60>;
		using hour_t = std::ratio<3600>;
		
		template <typename R, typename P>
		using ctime_t = std::chrono::duration<R, P>;

		using nano_time_t = ctime_t<double, nano_t>;
		using micro_time_t = ctime_t<double, micro_t>;
		using milli_time_t = ctime_t<double, milli_t>;
		using sec_time_t = ctime_t<double, sec_t>;
		using min_time_t = ctime_t<double, min_t>;
		using hour_time_t = ctime_t<double, hour_t>;

		template <typename C>
		using time_point_t = std::chrono::time_point<C>;

		template <typename C>
		struct ctimer_t {
			ctimer_t()
				: m_tpoint(C::now())
			{
			}

			inline void reset();

			inline double secs() const;
			inline double millis() const;
			inline double micros() const;

			template <typename Ratio>
			ctime_t<double, Ratio> inline elapsed() const;

		private:
			time_point_t<C> m_tpoint;
		};

		template <typename C>
		inline void ctimer_t<C>::reset() { m_tpoint = C::now(); }

		template <typename C>
		inline double ctimer_t<C>::secs() const
		{
			return sec_time_t(elapsed<sec_t>()).count();
		}

		template <typename C>
		inline double ctimer_t<C>::millis() const
		{
			return milli_time_t(elapsed<milli_t>()).count();
		}

		template <typename C>
		inline double ctimer_t<C>::micros() const
		{
			return micro_time_t(elapsed<micro_t>()).count();
		}

		template <typename C>
		template <typename Ratio>
		inline ctime_t<double, Ratio> ctimer_t<C>::elapsed() const
		{
			return C::now() - m_tpoint;
		}

		/*bool operator ==(Time left, Time right)
		{
			return left.asMicroseconds() == right.asMicroseconds();
		}

		bool operator !=(Time left, Time right)
		{
			return left.asMicroseconds() != right.asMicroseconds();
		}

		bool operator <(Time left, Time right)
		{
			return left.asMicroseconds() < right.asMicroseconds();
		}

		bool operator >(Time left, Time right)
		{
			return left.asMicroseconds() > right.asMicroseconds();
		}

		bool operator <=(Time left, Time right)
		{
			return left.asMicroseconds() <= right.asMicroseconds();
		}

		bool operator >=(Time left, Time right)
		{
			return left.asMicroseconds() >= right.asMicroseconds();
		}

		Time operator -(Time right)
		{
			return microseconds(-right.asMicroseconds());
		}

		Time operator +(Time left, Time right)
		{
			return microseconds(left.asMicroseconds() + right.asMicroseconds());
		}

		Time& operator +=(Time& left, Time right)
		{
			return left = left + right;
		}

		Time operator -(Time left, Time right)
		{
			return microseconds(left.asMicroseconds() - right.asMicroseconds());
		}

		Time& operator -=(Time& left, Time right)
		{
			return left = left - right;
		}

		Time operator *(Time left, float right)
		{
			return seconds(left.asSeconds() * right);
		}

		Time operator *(Time left, s64 right)
		{
			return microseconds(left.asMicroseconds() * right);
		}

		Time operator *(float left, Time right)
		{
			return right * left;
		}

		Time operator *(s64 left, Time right)
		{
			return right * left;
		}

		Time& operator *=(Time& left, float right)
		{
			return left = left * right;
		}

		Time& operator *=(Time& left, s64 right)
		{
			return left = left * right;
		}

		Time operator /(Time left, float right)
		{
			return seconds(left.asSeconds() / right);
		}

		Time operator /(Time left, s64 right)
		{
			return microseconds(left.asMicroseconds() / right);
		}

		Time& operator /=(Time& left, float right)
		{
			return left = left / right;
		}

		Time& operator /=(Time& left, s64 right)
		{
			return left = left / right;
		}

		float operator /(Time left, Time right)
		{
			return left.asSeconds() / right.asSeconds();
		}

		Time operator %(Time left, Time right)
		{
			return microseconds(left.asMicroseconds() % right.asMicroseconds());
		}

		Time& operator %=(Time& left, Time right)
		{
			return left = left % right;
		}*/

		/*bool operator ==(Time left, Time right);
		bool operator !=(Time left, Time right);
		bool operator <(Time left, Time right);
		bool operator >(Time left, Time right);
		bool operator <=(Time left, Time right);
		bool operator >=(Time left, Time right);
		Time operator -(Time right);
		Time operator +(Time left, Time right);
		Time& operator +=(Time& left, Time right);
		Time operator -(Time left, Time right);
		Time& operator -=(Time& left, Time right);
		Time operator *(Time left, float right);
		Time operator *(Time left, s64 right);
		Time operator *(float left, Time right);
		Time operator *(s64 left, Time right);
		Time& operator *=(Time& left, float right);
		Time& operator *=(Time& left, s64 right);
		Time operator /(Time left, float right);
		Time operator /(Time left, s64 right);
		Time& operator /=(Time& left, float right);
		Time& operator /=(Time& left, s64 right);
		float operator /(Time left, Time right);
		Time operator %(Time left, Time right);
		Time& operator %=(Time& left, Time right);*/
	}
}