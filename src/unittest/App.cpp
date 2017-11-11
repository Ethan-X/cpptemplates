#include <iostream>

#include <Windows.h>

#include "../MemoryUtilities.h"

#include "../ByteArray.hpp"
#include "unittest_stopwatch.hpp"
#include "unittest_spinlock.hpp"


int main(int argc, char** argv)
{
	unittest_stopwatch _unittest_stopwatch_;
	unittest_spinlock _unittest_spinlock_;
	system("pause");
	return 0;
}