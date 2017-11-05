#pragma once

#include "../Singleton.hpp"
#include "../Spinlock.hpp"

class App : public Singleton<App>, private ClassTypeSpinlock<App>
{
public:
	App();
	~App();

	void UnitTest_Singleton();
	void UnitTest_Spinlock();

	void PrintThreadId();
};