#ifndef LINKEDLIST_H
#define LINKEDLIST_H

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
#endif
