#include "Stopwatch.hpp"

using namespace cpptemplates::diagnostics;

Stopwatch::Stopwatch() {}
Stopwatch::~Stopwatch() {}

bool Stopwatch::IsRunning()
{
	return Running;
}

void Stopwatch::Start()
{
	if (!IsRunning())
	{
		Running = true;
		StartTimePoint = high_resolution_clock::now();
	}
}

void Stopwatch::Stop()
{
	if (IsRunning())
	{
		Running = false;
		EndTimePoint = high_resolution_clock::now();
	}
}

void Stopwatch::Reset()
{
	Running = false;
	StartTimePoint = time_point_cast<microseconds>(time_point<high_resolution_clock, microseconds>(microseconds(0)));
	EndTimePoint = time_point_cast<microseconds>(time_point<high_resolution_clock, microseconds>(microseconds(0)));
}

void Stopwatch::Restart()
{
	Reset();
	Start();
}