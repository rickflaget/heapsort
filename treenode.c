#include <stdlib.h>
#include <stdio.h>
#include "treenode.h"

Tnode *newTnode(int x)
	{
	Tnode *n = malloc(sizeof(Tnode));
	n->value = x;
	n->parent = NULL;
	n->left= NULL;
	n->right = NULL;
	return n;
	}

void changeTnode(Tnode *curr, Tnode *p, Tnode *l,Tnode *r)
	{
	curr->parent = p;
	curr->left = l;
	curr->right = r;
	} 

