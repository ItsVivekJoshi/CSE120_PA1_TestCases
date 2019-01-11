#include <stdio.h>
#include <assert.h>
#include "aux.h"
#include "umix.h"

// Testing Yielding to self.

void Main ()
{
	int pid = Getpid();
	int cpid;

	if((cpid = Fork()) == 0) {
		DPrintf("This is the child process. ID: %d\n", Getpid());
		DPrintf("We will yield back to the parent, ID: %d\n", pid);
		Yield(pid);
		DPrintf("And we're back to the child process.");
		Exit();
	}
	Yield(cpid);
	DPrintf("Trying to have the parent yield itself. ID: %d\n", Getpid());
	Yield(Getpid());
	DPrintf("If this prints, nothing catostrophically bad happened.");
	
}
