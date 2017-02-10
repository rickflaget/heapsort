#include "stack.h"

Stack *newStack(Snode *p)
	{
	Stack *n = malloc(sizeof(Stack));
	n->head = p;
	n->tail = p;
	return n;
	}
Stack *nuStack(void)
	{
	Stack *n = malloc(sizeof(Stack));
	n->head = NULL;
	n->tail = NULL;
	return n;
	}	
void SchangeHead(Stack *curr, Snode *p)
	{
	curr->head = p;
	}
void SchangeTail(Stack *curr, Snode *p)
	{
	curr->tail= p;
	}
void SchangeBoth(Stack *curr, Snode *p, Snode *k)
	{
	curr->head = p;
	curr->tail = k;
	}

void push(Stack *curr, Snode *p)
	{
	p->next = curr->head;
	curr->head = p;
	}
Snode *pop(Stack *curr)
	{
	Snode *d;
	d = curr->head;
	curr->head = d->next;
	if (curr->head != NULL)
		{
		curr->head->prev = NULL;
		}
	d->next = NULL;	
	return d;
	}  
