#include <stdlib.h>
#include <Win32/MinWin.h>


void free(void* ptr)
{
	if (ptr != NULL)
	{
		HeapFree(GetProcessHeap(), 0, ptr);
	}	
}