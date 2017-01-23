#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;
typedef struct Binary_Search_Tree Binary_Search_Tree;

struct Node {
	int value;
	Node* left;
	Node* right;
};

struct Binary_Search_Tree {
	Node* root;
};

//TODO: Implement balance(). Maybe work on a self-balancing bst?

Node* make_node(int value) {
	Node* node = (Node*)malloc(sizeof(Node));
	node->value = value;
	node->left = 0;
	node->right = 0;
	return node;
}

Binary_Search_Tree* make_bst() {
	Binary_Search_Tree* bst = (Binary_Search_Tree*)malloc(sizeof(Binary_Search_Tree));
	bst->root = 0;
	return bst;
}

// Might be useful
int is_leaf(Node* node) {
	if(node->left == 0 && node->right == 0) {
		return 1;
	}
	else {
		return 0;
	}
}

// Assumes all values inserted are unique.
// Not like it matters, since it only affects how the tree ends up looking.
void insert(Binary_Search_Tree* tree, Node* node) {
	if(tree->root == 0) {
		tree->root = node;
	}
	else {
		Node* parent = tree->root;
		while(1) {
			if(parent->value > node->value) {
				if(parent->left != 0) {
					parent = parent->left;	
				}
				else {
					parent->left = node;
					return;
				}
			}
			else {
				if(parent->right != 0) {
					parent = parent->right;	
				}
				else {
					parent->right = node;
					return;
				}
			}
		}
	}
}

int search(Binary_Search_Tree* tree, int value) {
	if(tree->root == 0) {
		return 0;
	}
	Node* current = tree->root;
	while(1) {
		if(current == 0) {
			return 0;
		}
		if(current->value > value) {
			current = current->left;
		}
		else if(current->value < value) {
			current = current->right;
		}
		else if(current->value == value) {
			return 1;
		}
	}
}

void preorder_traversal(Node* root) {
	if(root == 0) {
		return;
	}
	Node* current = root;
	printf("%d\n", current->value);
	preorder_traversal(current->left);
	preorder_traversal(current->right);
}

void inorder_traversal(Node* root) {
	if(root == 0) {
		return;
	}
	Node* current = root;
	inorder_traversal(current->left);
	printf("%d\n", current->value);
	inorder_traversal(current->right);
}

void postorder_traversal(Node* root) {
	if(root == 0) {
		return;
	}
	Node* current = root;
	postorder_traversal(current->left);
	postorder_traversal(current->right);
	printf("%d\n", current->value);
}

int main() {
	Binary_Search_Tree* tree = make_bst();
	insert(tree, make_node(5));
	insert(tree, make_node(3));
	insert(tree, make_node(4));
	insert(tree, make_node(1));
	insert(tree, make_node(6));
	insert(tree, make_node(2));
	printf("Pre-order Traversal\n");
	preorder_traversal(tree->root);
	printf("In-order Traversal\n");
	inorder_traversal(tree->root);
	printf("Post-order Traversal\n");
	postorder_traversal(tree->root);
	printf("Check for 5...\n");
	printf("%d\n", search(tree, 5));
	printf("Check for 2...\n");
	printf("%d\n", search(tree, 2));
	printf("Check for 6...\n");
	printf("%d\n", search(tree, 6));
	printf("Check for 1...\n");
	printf("%d\n", search(tree, 1));
	printf("Check for 7...\n");
	printf("%d\n", search(tree, 7));

	return 0;
}
