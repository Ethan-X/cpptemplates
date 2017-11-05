#pragma once

#include <memory>

#include "Spinlock.hpp"

using namespace std;

template<typename T>
class Singleton
{
public:
	static T* GetInstance()
	{
		SpinlockGuard CriticalSection(Lock);

		if (Instance == nullptr)
			Instance.reset(new T);

		return Instance.get();
	}

private:
	static Spinlock Lock;
	static shared_ptr<T> Instance;
};

template<typename T>
Spinlock Singleton<T>::Lock;

template<typename T>
shared_ptr<T> Singleton<T>::Instance = NULL;