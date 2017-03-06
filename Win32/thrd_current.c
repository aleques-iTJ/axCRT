#include <threads.h>
#include <Win32/MinWin.h>


thrd_t thrd_current()
{
	thrd_t temp;
	temp.ptr = GetCurrentThread();

	return temp;
}