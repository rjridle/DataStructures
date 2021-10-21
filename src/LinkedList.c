#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


typedef struct node_t {
	struct node_t *next;
	struct node_t *prev;
	int data;
} node_t;

node_t *llinit(int data);
void lladd(node_t *head, int data);
void llinsert(node_t *head, int data, int pos);
void lldelete(node_t *head, int pos);
node_t *llgetnode(node_t *head, int data);
void llprint(node_t *head);

node_t *llinit(int data){
	//Create new Linked List by creating HEAD node
	node_t *ll = malloc(sizeof(node_t));
	ll->data = data;
	ll->next = NULL;
	ll->prev = NULL;
	return ll;
}

void lladd(node_t *head, int data) {
	node_t *temp = head;

	if (temp->next == NULL) {
		node_t *newNode = malloc(sizeof(node_t));
		newNode->data = data;
		newNode->next = NULL;
		newNode->prev = temp;
		temp->next = newNode;
	} else {
		temp = temp->next;
		lladd(temp, data);
	}
}

void llinsert(node_t *head, int data, int pos) {
	
	pos -= 1;
	assert(head->next != NULL);

	if (pos < 0) {

		node_t *newNode = malloc(sizeof(node_t));
		newNode->data = head->data;

		//Set pointers for new node
		newNode->next = head->next;
		newNode->prev = head;

		//Set prev pointer for old 'next' node to new node
		(head->next)->prev = newNode;

		//Set next pointer for head node to new node
		head->next = newNode;
		head->data = data;
	} else if (pos == 0) {
		node_t *newNode = malloc(sizeof(node_t));
		newNode->data = data;

		//Set pointers for new node
		newNode->next = head->next;
		newNode->prev = head;

		//Set prev pointer for old 'next' node to new node
		(head->next)->prev = newNode;

		//Set next pointer for head node to new node
		head->next = newNode;
	} else {
		llinsert(head->next, data, pos);
	}
}

void lldelete(node_t *head, int pos) {

	assert(head != NULL);

	if (pos < 0) {
		printf("ERR: Cannot delete head node\n");
	} else if (pos == 0) {
	
		(head->prev)->next = head->next;
		(head->next)->prev = head->prev;

		free(head);
	} else {
		lldelete(head->next, --pos);
	}
}



void llprint(node_t *head) {
	node_t *temp = head;

	while(temp != NULL) {
		printf("%d <=> ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

node_t *llgetnode(node_t *head, int data) {
	node_t *temp = head;

	while(temp != NULL) {
		if (temp->data == data) {
			return temp;
		} else {
			temp = temp->next;
		}
	}
	return NULL;
}

/*
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

	return 0;
}
*/
