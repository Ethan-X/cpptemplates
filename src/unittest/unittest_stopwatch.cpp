#include "unittest_stopwatch.hpp"

unittest_stopwatch::unittest_stopwatch()
{
	wcout << "Case: diagnostics.Stopwatch" << endl << endl;
	wcout << "Sleep: 1000ms" << endl << endl;

	LocalStopwatch.Start();
	this_thread::sleep_for(milliseconds(1000));
	LocalStopwatch.Stop();
	
	wcout << "--------------- Results ---------------" << endl;
	wcout << "Nanoseconds: " << LocalStopwatch.ToClock<nanoseconds>().count() << endl;
	wcout << "Microseconds: " << LocalStopwatch.ToClock<microseconds>().count() << endl;
	wcout << "Milliseconds: " << LocalStopwatch.ToClock<milliseconds>() .count() << endl;
	wcout << "Seconds: " << LocalStopwatch.ToClock<seconds>().count() << endl << endl;
}

unittest_stopwatch::~unittest_stopwatch() {}