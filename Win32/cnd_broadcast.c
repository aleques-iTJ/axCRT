#include <threads.h>
#include <Win32/MinWin.h>


int	cnd_broadcast(cnd_t* cond)
{
	WakeAllConditionVariable(cond->ptr);
	return thrd_success;
}