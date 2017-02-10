
heapsort: heapsort.o heap.o queue.o stack.o treenode.o structurenode.o
	gcc -Wall -g heapsort.o heap.o queue.o stack.o treenode.o structurenode.o -o heapsort
heap: heap.c heap.h ds1.h queue.h
	gcc -Wall -g -c heap.c
treenode: treenode.c treenode.h
	gcc -Wall -g -c treenode.c
structnode: structurenode.c structurenode.h treenode.h
	gcc -Wall -g -c structurenode.c
queue: queue.c queue.h structurenode.h
	gcc -Wall -g -c queue.c
stack: stack.c stack.h structurenode.h
	gcc -Wall -g -c stack.c
clean:
	rm -f *.o *.exe *exe.stackdump
runmax:
	./heapsort -d text.txt
runmin:
	./heapsort text.txt
