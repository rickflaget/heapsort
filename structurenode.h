#include <stdlib.h>
#include <stdio.h>
#include "treenode.h"

#ifndef snode_struct
#define snode_struct

typedef struct structurenode 
	{
	Tnode *tnode;
	struct structurenode *next;
	struct structurenode *prev;
	int left;
	}Snode;
#endif 

Snode *newSnode(Tnode*);
Snode *nSnode(void);
void changeSnode(Snode*, Snode*, Snode*);
