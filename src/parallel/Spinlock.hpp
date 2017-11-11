#pragma once

#include <atomic>
#include <chrono>
#include <thread>

using namespace std;
using namespace std::chrono;

class Spinlock
{
public:
	Spinlock();
	~Spinlock();

	void EnterLock();
	void LeaveLock();

private:
	volatile atomic_flag LockFlag = ATOMIC_FLAG_INIT;

	Spinlock(const Spinlock& TargetObject);
	Spinlock& operator=(const Spinlock& TargetObject);
};

class SpinlockGuard
{
public:
	SpinlockGuard(Spinlock& TargetObject);
	~SpinlockGuard();

private:
	Spinlock& Lock;
};

template<class TargetClass>
class ClassTypeSpinlock
{
public:
	struct LockGuard
	{
		LockGuard()
		{
			Lock.EnterLock();
		}
		~LockGuard()
		{
			Lock.LeaveLock();
		}
	};

private:
	static Spinlock Lock;
};

template<class TargetClass>
Spinlock ClassTypeSpinlock<TargetClass>::Lock;