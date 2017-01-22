#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;

struct Node {
	int value;
	Node *next;
};

Node* append_node(Node *head, int value) {
	Node *first = head;
	Node *current = head;
	if(current == 0) {
		current =(Node*)malloc(sizeof(Node));
		current->value = value;
		current->next = 0;
		return current;
	}
	else {
		while(current->next != 0) {
			current = current->next;
		}
		current->next =(Node*)malloc(sizeof(Node));
		current->next->value = value;
		current->next->next = 0;
		return first;
	}
}

Node* remove_node(Node *head, int value) {
	Node *first = head;
	Node *current = head;
	Node *previous = 0;
	while(current != 0) {
		if(current->value == value) {
			if(previous != 0) {
				previous->next = current->next;
			}
			else {
				first = current->next;
			}
			Node *old = current;
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

void print_list(Node *head) {
	Node *current = head;
	while(current != 0) {
		printf("%d\n", current->value);	
		current = current->next;
	}
}	

int get_length(Node *head) {
	Node *current = head;
	int count = 0;
	while(current != 0) {
		current = current->next;
		count++;
	}
	return count;
}

int main() {
	printf("%s", "Creating node...\n");
	Node *a = 0;
	printf("%s", "Inserting elements...\n");
	int i = 4;
	while(i < 10) {
		a = append_node(a, i);
		i++;
	}
	a = append_node(a, 6);
	print_list(a);
	printf("Length of List is: %d\n", get_length(a));
	printf("%s", "Removing elements...\n");
	a = remove_node(a, 5);
	print_list(a);
	printf("%s", "Removing elements...\n");
	a = remove_node(a, 4);
	print_list(a);
	printf("%s", "Removing elements...\n");
	a = remove_node(a, 6);
	print_list(a);
	return 0;
}