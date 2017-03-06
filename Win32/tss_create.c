#include <threads.h>
#include <Win32/MinWin.h>


int tss_create(tss_t* tss_key, tss_dtor_t destructor)
{
	*tss_key = TlsAlloc();

	if (*tss_key == TLS_OUT_OF_INDEXES)
	{
		return thrd_error;
	}

	return thrd_success;
}