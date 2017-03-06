#include <stdlib.h>
#include <Win32/MinWin.h>


void* calloc(size_t size)
{
	if (size == 0)
	{
		// HeapAlloc() doesn't seem to return a null pointer if size is 0
		return NULL;
	}

	return HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, size);
}