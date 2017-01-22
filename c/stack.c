#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;
typedef struct Stack Stack;

struct Node {
	int value;
	Node *next;
};

struct Stack {
	Node* head;
};

Node* make_node(int value) {
	Node* node = (Node*)malloc(sizeof(Node));
	node->value = value;
	node->next = 0;
	return node;
}

Stack* make_stack() {
	Stack *new_stack = (Stack*)malloc(sizeof(Stack));
	new_stack->head = 0;
	return new_stack;
}

void push(Stack *stack, Node* node) {
	node->next = stack->head;
	stack->head = node;
}

Node* pop(Stack *stack) {
	Node* node = stack->head;
	if(stack->head != 0) {
		stack->head = stack->head->next;
		node->next = 0;
		return node;
	}
	else {
		return 0;	//check done by callee
	}
}

int main() {
	Stack *stack = make_stack();
	int i = 0;
	printf("Pushing items...\n");
	while(i < 10) {
		printf("%d\n", i);
		push(stack, make_node(i));
		i++;
	}
	printf("Popping items...\n");
	while(stack->head != 0) {
		printf("%d\n", pop(stack)->value);
	}
}
