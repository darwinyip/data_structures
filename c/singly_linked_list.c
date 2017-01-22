#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;

struct Node {
	int value;
	Node* next;
};

Node* create_node(int value) {
	Node* node = (Node*)malloc(sizeof(Node));
	node->value = value;
	node->next = 0;
	return node;
}

Node* prepend_node(Node* head, Node* node) {
	if(head != 0) {
		node->next = head;
	}
	return node;
}

Node* append_node(Node* head, Node* node) {
	Node* first = head;
	Node* current = head;
	if(current == 0) {
		current = node;
		return current;
	}
	else {
		while(current->next != 0) {
			current = current->next;
		}
		current->next = node;
		return first;
	}
}

Node* remove_node(Node* head, Node* node) {
	Node* first = head;
	Node* current = head;
	Node* previous = 0;
	while(current != 0) {
		if(current == node) {
			if(previous != 0) {
				previous->next = current->next;
			}
			else {
				first = current->next;
			}
			current = current->next;
			free(node);
		}
		else {
			previous = current;
			current = current->next;
		}
	}
	return first;
}

void print_list(Node* head) {
	Node* current = head;
	while(current != 0) {
		printf("%d\n", current->value);	
		current = current->next;
	}
}	

int get_length(Node* head) {
	Node* current = head;
	int count = 0;
	while(current != 0) {
		current = current->next;
		count++;
	}
	return count;
}

int main() {
	printf("%s", "Creating node...\n");
	Node* b = create_node(1);
	Node* temp = b;
	printf("%s", "Prepending nodes...\n");
	int j = 0;
	while(j < 10) {
		b = prepend_node(b, create_node(j));
		j++;
	}
	print_list(b);
	printf("%s", "Appending node 6...\n");
	b = append_node(b, create_node(6));
	print_list(b);
	printf("Length of List is: %d\n", get_length(b));
	printf("%s", "Removing temp node 1...\n");
	b = remove_node(b, temp);
	print_list(b);

	return 0;
}
