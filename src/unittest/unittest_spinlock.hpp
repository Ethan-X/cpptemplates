#pragma once

#include <iostream>

#include "../diagnostics/Stopwatch.hpp"
#include "../parallel/Spinlock.hpp"

using namespace std;

using namespace cpptemplates::diagnostics;

class unittest_spinlock
{
public:
	unittest_spinlock();
	~unittest_spinlock();

	void Test();

private:
	Spinlock Lock;
};