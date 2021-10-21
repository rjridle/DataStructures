CFLAGS=-Wall -Wextra -ggdb
FILES=LinkedList.c

linkedlist: LinkedList.c
	$(CC) $(CFLAGS) -o LinkedList LinkedList.c
