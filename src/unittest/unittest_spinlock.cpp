#include <omp.h>
#include <future>
#include "unittest_spinlock.hpp"

unittest_spinlock::unittest_spinlock()
{
	wcout << "Case: parallel.Spinlock" << endl << endl;

	Test();
}

unittest_spinlock::~unittest_spinlock() {}

void unittest_spinlock::Test()
{
	wcout << "Test" << endl << endl;

	wcout << "Concurrency: False" << endl;

	__int64 A = 0, B = 0;
	Stopwatch LocalStopwatch;

	LocalStopwatch.Start();
#pragma omp parallel
	{
#pragma omp for
		for (__int64 i = 0; i < 100000000; ++i)
			++A;
	}
	LocalStopwatch.Stop();

	wcout << "A: " << A << endl;
	wcout << "Elapsed time: " << LocalStopwatch.ToClock<milliseconds>().count() << "ms" << endl;

	wcout << endl << "Concurrency: True." << endl;

	LocalStopwatch.Restart();
#pragma omp parallel
	{
#pragma omp for
		for (__int64 i = 0; i < 10000000; ++i)
		{
			SpinlockGuard CriticalSection(Lock);
			++B;
		}
	}
	LocalStopwatch.Stop();

	wcout << "B: " << B << endl;
	wcout << "Elapsed time: " << LocalStopwatch.ToClock<milliseconds>().count() << "ms" << endl << endl;
}