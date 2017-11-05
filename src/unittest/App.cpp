#include <iostream>

#include "App.hpp"

using namespace std;

App::App()
{
	wcout << L"Generated \"App\" Class." << endl << endl;
}

App::~App() {}

void App::UnitTest_Singleton()
{
	wcout << "Called: [UnitTest_Singleton]" << endl << endl;;
}

void App::UnitTest_Spinlock()
{
	thread Thread_A(&App::PrintThreadId, this);
	thread Thread_B(&App::PrintThreadId, this);
	thread Thread_C(&App::PrintThreadId, this);

	Thread_A.join();
	Thread_B.join();
	Thread_C.join();
}

void App::PrintThreadId()
{
	LockGuard CriticalSection;

	for(int i = 0; i < 10; ++i)
		wcout << L"Thread Id: " << this_thread::get_id() << endl;

	wcout << endl;
}

int main(int argc, char** argv)
{
	App::GetInstance()->UnitTest_Singleton();
	App::GetInstance()->UnitTest_Spinlock();
	system("pause");
	return 0;
}