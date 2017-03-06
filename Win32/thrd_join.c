#include <threads.h>
#include <Win32/MinWin.h>


int	thrd_join(thrd_t thread, int* res)
{
	WaitForSingleObject(thread.ptr, INFINITE);
	return 0;
}