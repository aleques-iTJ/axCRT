#include <threads.h>
#include <Win32/MinWin.h>


int	cnd_signal(cnd_t* cond)
{
	WakeConditionVariable(cond->ptr);
	return thrd_success;
}