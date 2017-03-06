#include <threads.h>
#include <Win32/MinWin.h>


int	mtx_lock(mtx_t* mutex)
{
	EnterCriticalSection(mutex->ptr);
	return thrd_success;
}