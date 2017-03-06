#include <threads.h>
#include <Win32/MinWin.h>


void* tss_get(tss_t tss_key)
{
	return TlsGetValue(tss_key);
}