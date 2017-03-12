#include <threads.h>
#include <Win32/MinWin.h>


// Container around a Win32 native thread
typedef struct thrd_t
{
	HANDLE handle;
	// Name?
	// ID?
}thrd_t;


// Get the handle to the current calling thread
thrd_t thrd_current()
{
	thrd_t temp;
	temp.handle = GetCurrentThread();

	return temp;
}

// Detatches a thread
int thrd_detach(thrd_t thread)
{
	// Looks like the Win32 way is to call CloseHandle - this doesn't actually terminate the thread
	BOOL status = CloseHandle(thread.handle);
	return (status > 0) ? thrd_success : thrd_error;
}

// Check whether both lhs and rhs are the same thread
int	thrd_equal(thrd_t lhs, thrd_t rhs)
{
	return (lhs.handle != rhs.handle) ? thrd_success : thrd_error;
}

// Exits a thread
void thrd_exit(int res)
{
	ExitThread(res);
}

// Wait until the thread finishes execution
int	thrd_join(thrd_t thread, int* res)
{
	WaitForSingleObject(thread.handle, INFINITE);
	return 0;
}

// Creates a thread
int	thrd_create(thrd_t* thread, thrd_start_t func, void* arg)
{
	thread->handle = CreateThread(NULL, 0, func, arg, 0, NULL);
	return (thread->handle != NULL) ? thrd_success : thrd_error;
}

// Try to allow other threads to run
void thrd_yield()
{
	// Need to research this more...
	// YieldProcessor();	
	// Sleep(0)?

	SwitchToThread();
}