#include <threads.h>
#include <Win32/MinWin.h>


int mtx_init(mtx_t* mutex, int type)
{
	mutex->ptr = mutex->pf_Storage;

	if (mutex)
	{
		InitializeCriticalSection(mutex->ptr);
		return thrd_success;
	}

	return thrd_error;
}