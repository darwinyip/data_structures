#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;
typedef struct Queue Queue;

struct Node {
	int value;
	Node* next;
};

struct Queue {
	Node* first;
	Node* last;
};

Node* make_node(int value) {
	Node* node = (Node*)malloc(sizeof(Node));
	node->value = value;
	node->next = 0;
	return node;
}

Queue* make_queue() {
	Queue* queue = (Queue*)malloc(sizeof(Queue));
	queue->first = 0;
	queue->last = 0;
}

void enqueue(Queue* queue, Node* node) {
	if(queue->first == 0) {
		queue->first = node;
	}
	else {
		queue->last->next = node;
	}
		queue->last = node;
}

Node* dequeue(Queue* queue) {
	Node* node = queue->first;
	if(queue->first != 0) {
		queue->first = queue->first->next;
		node->next = 0;
		return node;
	}
	else {
		return 0;	//check done by callee
	}

}

int main() {
	printf("Creating queue...\n");
	Queue* queue = make_queue();
	printf("Enqueuing items...\n");
	int i = 0;
	while(i<10) {
		printf("%d\n", i);
		enqueue(queue, make_node(i));
		i++;
	}
	printf("First item %d\n", queue->first->value);
	printf("Last item %d\n", queue->last->value);
	printf("Dequeuing items...\n");
	while(queue->first != 0) {
		printf("%d\n", dequeue(queue)->value);
	}


	return 0;
}