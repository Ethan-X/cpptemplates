#pragma once

#include <iostream>
#include <thread>

#include "../diagnostics/Stopwatch.hpp"

using namespace std;

using namespace cpptemplates::diagnostics;

class unittest_stopwatch
{
public:
	unittest_stopwatch();
	~unittest_stopwatch();

private:
	Stopwatch LocalStopwatch;
};
