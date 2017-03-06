#include <threads.h>
#include <Win32/MinWin.h>


void tss_delete(tss_t tss_id)
{
	TlsFree(tss_id);
}