/*Project Written by Rick Flaget
 * Tree based heapsort with the same theoretical time as array based heapsort
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "heap.h"
#include <time.h>
void printout(void);
int main(int argc,char **argv)
	{
	int dec = 0;
	FILE *FP = NULL;
	if (argc == 2)
		{
		if (strcmp(argv[1],"-v") == 0)		//Command Line options
			{
			printout();
			return 0;
			}
		FP = fopen(argv[1],"r");
		}
	else if (argc == 3)	
		{
		if (strcmp(argv[1],"-v") == 0 || strcmp(argv[2],"-v")==0)
			{
			printout();
			return 0;
			}
		else if (strcmp(argv[1],"-d") == 0)
			{
			dec = 1;
			FP = fopen(argv[2],"r");
			}
		else if (strcmp(argv[2],"-d") == 0)
			{
			dec = 1;
			FP = fopen(argv[1],"r");
			}
		else
			{
			printf("! Command not recognized !\n");
			return -1;
			}

		}
	if (FP == 0)
		{
 		printf("Error occured with input file!!\n");
		return 0;
		}
	int x = 0;
	int i = 0;		
	fscanf(FP, "%d", &x);
	++i;
	Tnode *a = newTnode(x);
	Snode *s = newSnode(a);
	Stack *input = newStack(s); 
	if (!feof(FP))
		{
		fscanf(FP,"%d",&x);
		}
	while (!feof(FP)) //putting input into stack
		{
		++i;
		a = newTnode(x);
		s = newSnode(a);
		push(input,s);
		fscanf(FP, "%d", &x);
		}
	Heap *h = makeHeap(input,dec); //creates unordered heap and then ordered heap
	extract(h,i,dec); //prints out order (descending or ascending)
	return 0;
	}

void printout(void)
	{
	printf("****This Program was written by Rick Flaget rnflaget@crimson.ua.edu****\nTo perform this sort in theta(nlogn) time, the unordered heap is\nbuilt in linear time through the use of a stack and then a queue\n(doubly linked with tail pointers).The parent node(dequed) is\nlinked to its children(pop 2 values), then repeated after the \nchildren are added to the queue. Next the undorded heap is put\ninto heap order with the help of another stack(reverse input \nstack) which finds the nodes in a flipped/reverse level order\nto compare with their children and heapify until heap order.\nThis takes linear time because not all of the heapify take logn\ntime as. nodes can only move (total levels - currlevel) downward.\nFinally the extract(min/max) function. This runs in nlogn time.\nUsing a stack to track left or right children based on if the \nnode is an odd or even.the process repeats until the rightmost \nleaf is found and replaces the root. Heapify is then used, and\nthis proccess is repeated n times until the heap is empty.The \nfull heapsort is: n + n + nlogn = theta(nlogn).");
	printf("\n\n\nn             |   time \n");
	printf("--------------+--------\n");
	printf("10000         |  0.015 \n");
	printf("100000        |  0.296 \n");
	printf("1000000       |  3.578 \n");
	printf("10000000      | 47.150 \n");
	};		
