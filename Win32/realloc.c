#include <stdlib.h>
#include <Win32/MinWin.h>


void* realloc(void* ptr, size_t size)
{
	if (ptr == NULL)
	{
		return HeapAlloc(GetProcessHeap(), 0, size);
	}

	return HeapReAlloc(GetProcessHeap(), 0, ptr, size);
}