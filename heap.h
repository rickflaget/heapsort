#include <stdlib.h>
#include <math.h>
#include "queue.h"
#include "stack.h"
#ifndef heap_struct
#define heap_struct

typedef struct heap
	{
	Tnode *root;
	} Heap;
#endif

Heap *makeHeap(Stack *,int dec);
void heapify(Heap*,Stack *,int dec);
int compare(int,int,int);
void heapifyhelp(Tnode*,int);
void extract(Heap *,int,int);
