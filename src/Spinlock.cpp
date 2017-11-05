#include <atomic>
#include <chrono>
#include <thread>

#include "Spinlock.hpp"

using namespace std;
using namespace std::chrono;

Spinlock::Spinlock() {}

Spinlock::~Spinlock()
{
	LeaveLock();
}

void Spinlock::EnterLock()
{
	while (LockFlag.test_and_set(memory_order_acquire))
		this_thread::sleep_for(milliseconds(1));
}

void Spinlock::LeaveLock()
{
	LockFlag.clear(memory_order_release);
}

SpinlockGuard::SpinlockGuard(Spinlock& TargetObject) : Lock(TargetObject)
{
	Lock.EnterLock();
}

SpinlockGuard::~SpinlockGuard()
{
	Lock.LeaveLock();
}