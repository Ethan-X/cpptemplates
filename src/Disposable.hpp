#pragma once

class Disposable
{
public:
	virtual bool IsDisposed()
	{
		return Disposed;
	}

	virtual void Dispose() = 0;
	virtual void Dispose(bool Disposing) = 0;

protected:
	virtual ~Disposable() {};

	bool Disposed = false;

};