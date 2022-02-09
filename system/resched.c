/* resched.c - resched */

#include <xinu.h>

/**
 * Reschedule processor to next ready process
 *
 */
void	resched(void)		// assumes interrupts are disabled
{
	struct procent *ptold;	// ptr to table entry for old process
	struct procent *ptnew;	// ptr to table entry for new process

	// If rescheduling is deferred, record attempt and return
	if (Defer.ndefers > 0) {
		Defer.attempt = TRUE;
		return;
	}

	// Point to process table entry for the current (old) process
// DC REMOVE

	ptold = &proctab[currpid];

        if (ptold->prstate == PR_CURR) {
                // Old process got preempted; place back on ready queue
                ptold->prstate = PR_READY;
                enqueue(currpid, readyqueue);
        }

        // Force context switch to next ready process
        currpid = dequeue(readyqueue);
        ptnew = &proctab[currpid];
        ptnew->prstate = PR_CURR;
// DC REMOVE END 
	// TODO - check ptold's state. If it's running, put it on the ready queue and change state to ready

	// TODO - dequeue next process off the ready queue and point ptnew to it

	// TODO - change its state to "current" (i.e., running)

	// TODO - set currpid to reflect new running process' PID

	// Context switch to next ready process
	ctxsw(&ptold->prstkptr, &ptnew->prstkptr);

	// Old process returns here when resumed
	return;
}
