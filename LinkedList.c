#include <stdio.h>
#include <stdlib.h>


typedef struct node_t {
	struct node *next;
	struct node *prev;
	int data;
} node_t;

void add(node_t *head, int data) {
	node_t *temp = head;

	if (temp == NULL) {
		node_t newNode = {.next=NULL, .prev=temp, .data=data};
		temp->next = &newNode;
	} else {
		temp = temp->next;
		add(temp, data);
	}
}

void printList(node_t head) {
	node_t *temp = &head;

	while(temp != NULL) {
		printf("%d -> ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

int main(int argc, char **argv) {

	node_t ll = {.next=NULL, .prev=NULL, .data=7};
	add(&ll, 42);
	printList(ll);

	return 0;
}
