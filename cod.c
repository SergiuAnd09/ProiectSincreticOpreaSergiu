#include <stdio.h>
#include <stdlib.h>

typedef struct node {

	int key;
	struct node* left;
	struct node* right;
}node;

// Inorder traversal
void inorderTraversal(node* root) {
	if (root == NULL) return;
	inorderTraversal(root->left);
	printf("%d ->", root->key);
	inorderTraversal(root->right);
}

// Preorder traversal
void preorderTraversal(node* root) {
	if (root == NULL) return;
	printf("%d ->", root->key);
	preorderTraversal(root->left);
	preorderTraversal(root->right);
}

// Postorder traversal
void postorderTraversal(node* root) {
	if (root == NULL) return;
	postorderTraversal(root->left);
	postorderTraversal(root->right);
	printf("%d ->", root->key);
}

void printCurrentLevel(node* root, int level);
int height(node* node);
node* newNode(int data);


/* Function to print level order traversal a tree*/
void printLevelOrder(struct node* root)
{
	int h = height(root);
	int i;
	for (i = 1; i <= h; i++)
		printCurrentLevel(root, i);
}

/* Print nodes at a current level */
void printCurrentLevel(struct node* root, int level)
{
	if (root == NULL)
		return;
	if (level == 1)
		printf("%d ", root->key);
	else if (level > 1) {
		printCurrentLevel(root->left, level - 1);
		printCurrentLevel(root->right, level - 1);
	}
}

/* Compute the "height" of a tree -- the number of
	nodes along the longest path from the root node
	down to the farthest leaf node.*/
int height(struct node* node)
{
	if (node == NULL)
		return 0;
	else {
		/* compute the height of each subtree */
		int lheight = height(node->left);
		int rheight = height(node->right);

		/* use the larger one */
		if (lheight > rheight)
			return (lheight + 1);
		else
			return (rheight + 1);
	}
}

// Create a new Node
node* createNode(value) {
	node* newNode = malloc(sizeof(struct node));
	newNode->key = value;
	newNode->left = NULL;
	newNode->right = NULL;

	return newNode;
}

// Insert on the left of the node
node* insertLeft(node* root, int value) {

	root->left = createNode(value);
	return root->left;
}

// Insert on the right of the node
node* insertRight(node* root, int value) {
	root->right = createNode(value);
	return root->right;
}

int main() {
	node* root = createNode(1);
	insertLeft(root, 2);
	insertRight(root, 3);
	insertLeft(root->left, 4);
	insertLeft(root->right, 5);
	//insertLeft(root->left->right, 6);

	printf("Inorder traversal \n");
	inorderTraversal(root);

	printf("\nPreorder traversal \n");
	preorderTraversal(root);

	printf("\nPostorder traversal \n");
	postorderTraversal(root);

	printf("\nLevel Order traversal of binary tree is \n");
	printLevelOrder(root);

	return 0;
}