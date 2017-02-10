#include "queue.h"

Q *newQueue(Snode *p)
	{
	Q *n = malloc(sizeof(Q));
	n->head = p;
 	n->tail = p;
	return n;
	}	
void changeHead(Q *curr, Snode *p)
	{
	curr->head = p;
	}
void changeTail(Q *curr, Snode *p)
	{
	curr->tail= p;
	}
void changeBoth(Q *curr, Snode *p, Snode *k)
	{
	curr->head = p;
	curr->tail = k;
	}

void enque(Q *curr, Snode *p)
	{
	p->next = curr->head;
	if (curr->head != NULL)
		{
		curr->head->prev = p;
		}
	else
		{
		changeTail(curr,p);
		}
	curr->head = p;
	}
Snode *deque(Q *curr)
	{
	Snode *d;
	d = curr->tail;
	if (curr->tail->prev != NULL)
		{
		curr->tail = d->prev;
		curr->tail->next = NULL;
		d->prev = NULL; 
		}
	else
		{
		curr->tail = NULL;
		curr->head = NULL;
		}
	return d;
	}  
