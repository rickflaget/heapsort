#include "structurenode.h"

#ifndef stack_struct
#define stack_struct

typedef struct stack 
	{
	Snode *head;
	Snode *tail;
	} Stack;	
#endif

Stack *newStack(Snode*);
Stack *nuStack(void);
void SchangeHead(Stack *, Snode *);
void SchangeTail(Stack *, Snode *);
void SchangeBoth(Stack *, Snode *, Snode *);
void push(Stack *, Snode *);
Snode *pop(Stack *);

	
