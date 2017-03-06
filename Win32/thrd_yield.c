#include <threads.h>
#include <Win32/MinWin.h>


void thrd_yield()
{
	YieldProcessor();
	Sleep(0);
}