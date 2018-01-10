#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *left;
	struct node *right;
};

struct node *newNode(int data)
{
	struct node *new = malloc(sizeof(struct node));
	new->left = NULL;
	new->right = NULL;
	new->data = data;
	return (new);
}

int sumTree(struct node *root)
{
	if(root == NULL)
		return;
	
	int originalValue = root->data;

	root->data = sumTree(root->left) + sumTree(root->right);

	return originalValue + root->data;
}

void printInorder(struct node* node)
{
    if (node == NULL)
        return;
    printInorder(node->left);
    printf("%d ", node->data);
    printInorder(node->right);
}

int main()
{
	struct node *root = newNode(10);
	root->left = newNode(-2);
  	root->right = newNode(6);
  	root->left->left = newNode(8);
  	root->left->right = newNode(-4);
  	root->right->left = newNode(7);
  	root->right->right = newNode(5);
 
  	sumTree(root);

  	printInorder(root);
    
	return 0;
}