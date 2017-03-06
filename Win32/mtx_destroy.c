#include <threads.h>
#include <Win32/MinWin.h>


void mtx_destroy(mtx_t* mutex)
{
	DeleteCriticalSection(mutex->ptr);
}