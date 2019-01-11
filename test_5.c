#include <stdio.h>
#include <assert.h>
#include "aux.h"
#include "umix.h"


//This test will try switching to a process after it has been killed.
void Main ()
{
	int pid;
	int ppid;
	ppid = Getpid();
	if((pid = Fork()) == 0) {
		DPrintf("This is the child process! ID: %d\n", Getpid());
		Exit();
	}
	DPrintf("Process %d is yielding to child process %d\n", ppid, pid);
	Yield(pid);
	DPrintf("Process %d is back!.\n", ppid);
	DPrintf("We try to yield to child process %d after it has been killed.\n", pid);
	Yield(pid);
	
}

