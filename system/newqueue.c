/* newqueue.c - newqueue */

#include <xinu.h>
#include <stdlib.h>

/**
 * Allocate and initialize a queue
 * @return pointer to queue structure
 */
struct queue *newqueue(void)
{
	// TODO - allocate memory for a new Queue structure (required to be on heap)
	struct queue *newQueue = (struct queue*) malloc(sizeof(struct queue));

	// TODO - initialize the structure
	newQueue->head = NULL;
	newQueue->tail = NULL;
	newQueue->size = 0;

	// TODO - return pointer
	return newQueue;
}
