CFLAGS=-Wall -Wextra -ggdb
LIBS=src/*.c
SRC_FILE=test/testLinkList.c

linkedlist: $(SRC_FILE) src/LinkedList.c 
	$(CC) $(CFLAGS) $(LIBS) $(SRC_FILE) -o test/TestLinkedList
