#include "structurenode.h"

#ifndef queue_struct
#define queue_struct

typedef struct queue
	{
	Snode *head;
	Snode *tail;
	}Q;	
#endif

Q *newQueue(Snode*);
void changeHead(Q *, Snode *);
void changeTail(Q *, Snode *);
void changeBoth(Q *, Snode *, Snode *);
void enque(Q *curr, Snode *);
Snode *deque(Q *);
	
