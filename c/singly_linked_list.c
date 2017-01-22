#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;

struct Node {
	int value;
	Node* next;
};

Node* prepend_value(Node* head, int value) {
	Node* new_node = (Node*)malloc(sizeof(Node));
	if(head != 0) {
		new_node->value = value;
		new_node->next = head;
	}
	return new_node;
}

Node* append_value(Node* head, int value) {
	Node* first = head;
	Node* current = head;
	Node* new_node = (Node*)malloc(sizeof(Node));
	if(current == 0) {
		current = new_node;
		current->value = value;
		current->next = 0;
		return current;
	}
	else {
		while(current->next != 0) {
			current = current->next;
		}
		current->next = new_node;
		current->next->value = value;
		current->next->next = 0;
		return first;
	}
}

Node* remove_value(Node* head, int value) {
	Node* first = head;
	Node* current = head;
	Node* previous = 0;
	while(current != 0) {
		if(current->value == value) {
			if(previous != 0) {
				previous->next = current->next;
			}
			else {
				first = current->next;
			}
			Node* old = current;
			current = current->next;
			free(old);
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
	printf("%s", "Creating empty node...\n");
	Node* a = 0;
	printf("%s", "Inserting values...\n");
	int i = 4;
	while(i < 10) {
		a = append_value(a, i);
		i++;
	}
	a = append_value(a, 6);
	print_list(a);
	printf("Length of List is: %d\n", get_length(a));
	printf("%s", "Removing value 5...\n");
	a = remove_value(a, 5);
	print_list(a);
	printf("%s", "Removing value 4...\n");
	a = remove_value(a, 4);
	print_list(a);
	printf("%s", "Removing value 6...\n");
	a = remove_value(a, 6);
	print_list(a);
	printf("%s", "Prepending new value 10...\n");
	a = prepend_value(a, 10);
	print_list(a);

	return 0;
}
