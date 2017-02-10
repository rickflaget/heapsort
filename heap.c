#include "heap.h"

Heap *makeHeap(Stack *s,int dec) //Takes input stack and turns into unordered heap
	{			 //Then calls heapify function to create ordered heap
	Snode *x = pop(s);
	Snode *rvrs = newSnode(x->tnode);	
	Stack *reverse = newStack(rvrs);
	Snode *l = NULL;
	Snode *r = NULL;
	Heap *h = malloc(sizeof(Heap));
	h->root = x->tnode;
	Q *q = newQueue(x);
	while (s->head != NULL)		//Connects 2 popped and 1 dequed node
		{
		x = deque(q);
		l = pop(s);
		rvrs = newSnode(l->tnode);
		push(reverse,rvrs);//Making reverse stack to be used for ordering
		enque(q,l); //Puts popped node on queue
		x->tnode->left = l->tnode;
		l->tnode->parent = x->tnode;
		if (s->head == NULL)
			{
			break;
			}
		r = pop(s);
		rvrs = newSnode(r->tnode);
		push(reverse,rvrs);
		x->tnode->right = r->tnode;
		r->tnode->parent = x->tnode;
		enque(q,r); //Puts popped node on queue		
		}
	//Snode *g = reverse->head;
	heapify(h,reverse,dec);
	return h;
	}
void heapify(Heap *h,Stack *g,int dec) //Heapifyhelp loop
	{
	Snode *sn = NULL;
	Tnode *x = NULL;
	while(g->head != NULL)
		{
		sn = pop(g);
		x = sn->tnode;
		heapifyhelp(x,dec);
		}
	}
int compare(int a, int b,int c) //C 1 or 0 depending on command line options
	{
	if (c == 1)
		{
		if (a > b)
			{
			return 1;
			}
		else
			{
			return 0;
			}
		}
	else
		{
		if (a < b)
			{
			return 1;
			}
		else
			{
			return 0;
			}
		}
	}

void heapifyhelp(Tnode *x,int dec) //Creates heap order
	{
	int temp = 0;
	if (x->left != NULL && x->right != NULL)
		{
		if (compare(x->left->value,x->value,dec) || compare(x->right->value,x->value,dec)) //Is there a node > or < than x 
			{
			if (compare(x->right->value , x->left->value,dec)) //Which option is > or <
				{
				temp = x->value;
				x->value = x->right->value;
				x->right->value = temp;
				x = x->right;
				heapifyhelp(x,dec);
				}
			 
			else
				{
				temp = x->value;
				x->value = x->left->value;
				x->left->value = temp;
				x = x->left;
				heapifyhelp(x,dec);
				}
			}
		}
	else if (x->left != NULL && x->right == NULL) 
		{
		if (compare(x->left->value,x->value,dec)) //x->right is NULL
			{
			temp = x->value;
			x->value = x->left->value;
			x->left->value = temp;
			x = x->left;
			heapifyhelp(x,dec);
			}
		}
	}
void extract(Heap *h,int total,int dec) //Flips lowest right node (value) with root
	{				//calls heapify help to return Heap order
	int currnode = total;
	Tnode *x = h->root;
	Tnode *leaf = x;
	Stack *s = nuStack();
	Snode *n = NULL;
	while (total > 0)
		{
		leaf = h->root;
		if (total == 1)
			{
			printf("%d ",x->value);
			break;
			}
		while (currnode > 1)
			{
			if (currnode % 2 == 1)//right child 
				{
				n = nSnode();	
				n->left = 0;
				push(s,n);
				}
			else
				{
				n = nSnode();//left child
				n->left = 1;
				push(s,n);
				}
			currnode = currnode / 2;
			}
		while (s->head != NULL)
			{
			n = pop(s);
			if (n->left == 0)
				{
				leaf = leaf->right;
				}
			else
				{
				leaf = leaf->left;
				}
			}
		
		if (leaf->parent->right != NULL && leaf->parent->right == leaf)
			{
			leaf->parent->right = NULL;
			}
		else
			{
			leaf->parent->left = NULL;
			}
		leaf->parent = NULL;
		printf("%d ",x->value);
		x->value = leaf->value;
		heapifyhelp(x,dec);
		total = total -1;
		currnode = total;
		}
	}
			
