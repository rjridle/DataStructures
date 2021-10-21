#include <stdio.h>
#include <stdlib.h>
#include "../headers/LinkedList.h"

int main(int argc, char **argv) {
	//Print number of arguements
	printf("input args amt = %d\n", argc); 

	//Prints arguemnets
	printf("argv:\n");
	for (int i = 1; i<argc; i++) {
		printf("argv[%d] = %s\n", argc, argv[i]);
	}

	node_t *ll = llinit(42);
       

	//Add to Linked List
	for (int i =0; i < 20; i++) {
		lladd(ll, i*64);
	}

	//Print list after adding 20 nodes
	printf("List after adding 20 nodes\n");
	llprint(ll);

	//Insert node with value 4242 at position 2
	llinsert(ll, 4242, 2);
	
	//Print list after inserting node
	printf("List after inserting node at position 2\n");
	llprint(ll); 

	//Delete node that was just added at position 2
	lldelete(ll, 2);

	//Print list after deleting node
	printf("List after deleting node at position 2\n");
	llprint(ll);

	node_t *getNode = llgetnode(ll, 15);

	print("getNode->data = %d\n", getNode->data);

	return 0;

}
