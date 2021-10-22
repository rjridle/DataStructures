#include <stdio.h>
#include <stdlib.h>

typedef struct node_t {
	struct node_t *rightChild;
	struct node_t *leftChild;
	int data;
}node_t;

node_t *trinit(int data);
void trinsert(node_t *node, int data);
void trprint(node_t *node, int space);


node_t *trinit(int data){
	node_t *root = malloc(sizeof(node_t));
	root->data = data;
	root->rightChild = NULL;
	root->leftChild = NULL;
	return root;
}

void trinsert(node_t *node, int data) {
	node_t *temp = node;

	if(data > temp->data) {
		if(temp->rightChild == NULL){
			node_t *newNode = malloc(sizeof(node_t));
			newNode->data = data;
			newNode->rightChild = NULL;
			newNode->leftChild = NULL;
			temp->rightChild = newNode;
		} else {
			trinsert(temp->rightChild, data);
		}
	}else {
		if(temp->leftChild == NULL){
			node_t *newNode = malloc(sizeof(node_t));
			newNode->data = data;
			newNode->rightChild = NULL;
			newNode->leftChild = NULL;
			temp->leftChild = newNode;
		} else {
			trinsert(temp->leftChild, data);
		}
	}
}

void trprint(node_t *node, int space){
	const int COUNT = 5;
	if(node == NULL) {
		return;
	}

	space += COUNT;

	trprint(node->rightChild, space);

	printf("\n");
	for (int i = COUNT; i<space; i++) {
		printf(" ");
	}
	printf("%d\n", node->data);

	trprint(node->leftChild, space);
}

int main(int argc, char **argv) {
	printf("Tree Data Structure\n");

	node_t *root = trinit(50);

	trinsert(root, 32);
	trinsert(root, 77);
	trinsert(root, 31);
	trinsert(root, 33);
	trinsert(root, 58);
	trinsert(root, 80);


	printf("Printing tree:\n");

	trprint(root, 0);
}
