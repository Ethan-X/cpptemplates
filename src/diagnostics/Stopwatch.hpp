#pragma once

#include <chrono>

using namespace std;
using namespace std::chrono;

namespace cpptemplates
{
	namespace diagnostics
	{
		class Stopwatch
		{
		public:
			Stopwatch();
			~Stopwatch();

			bool IsRunning();

			void Start();
			void Stop();
			void Reset();
			void Restart();

			template<typename Clock>
			Clock ToClock()
			{
				return duration_cast<Clock>(EndTimePoint - StartTimePoint);
			}

		private:
			bool Running = false;
			
			high_resolution_clock::time_point StartTimePoint, EndTimePoint;
		};
	}
}