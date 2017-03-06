#include <stdlib.h>
#include <Win32/MinWin.h>


void* malloc(size_t size)
{
	if (size == 0)
	{
		// HeapAlloc() doesn't seem to return a null pointer if size is 0
		return NULL;
	}

	return HeapAlloc(GetProcessHeap(), 0, size);
}