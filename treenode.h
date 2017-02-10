#include <stdlib.h>
#include <stdio.h>

#ifndef treenode_struct
#define treenode_struct

typedef struct treenode
	{
	struct treenode *parent;
	struct treenode *left;
	struct treenode *right;
	int value;
	} Tnode;

#endif

Tnode *newTnode(int);
void changeTnode(Tnode*, Tnode*, Tnode *, Tnode *);
