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

Stack* make_stack() {
	Stack *new_stack = (Stack*)malloc(sizeof(Stack));
	new_stack->head = 0;
	return new_stack;
}

void push(Stack *stack, int value) {
	Node *new_node = (Node*)malloc(sizeof(Node));
	new_node->value = value;
	new_node->next = stack->head;
	stack->head = new_node;
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
		push(stack, i);
		i++;
	}
	printf("Popping items...\n");
	while(stack->head != 0) {
		printf("%d\n", pop(stack)->value);
	}

	
}