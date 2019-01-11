#include <stdio.h>
#include <assert.h>
#include "aux.h"
#include "umix.h"

// Tries to yield to a process that doesn't quite exist...
void Main ()
{
	int ppid;
	ppid = Getpid();
	DPrintf("Trying to yield to process 2, which shouldn't exist.\n");
	Yield(2);
	DPrintf("Don't really know what will happen here.");
}
