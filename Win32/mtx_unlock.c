#include <threads.h>
#include <Win32/MinWin.h>


int	mtx_unlock(mtx_t* mutex)
{
	LeaveCriticalSection(mutex->ptr);
	return thrd_success;
}