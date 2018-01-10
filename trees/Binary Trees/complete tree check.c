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

int countNodes(struct node *root)
{
	if(root == NULL)
		return 0;
	return (1+countNodes(root->left)+countNodes(root->right));
}

int isComplete(struct node *root, int index, int numberOfNodes)
{
	if(root == NULL)
		return 1;
	if(index >= numberOfNodes)
		return 0;
	return (isComplete(root->left, 2*index+1, numberOfNodes) && (isComplete(root->right, 2*index+2,numberOfNodes)));
}

int main()
{
	struct node *root = newNode(1);
	root->left        = newNode(12);
    root->right       = newNode(15);
    root->left->left  = newNode(25);
    root->left->right = newNode(30);
    root->right->right = newNode(36);
    
    int numberOfNodes = countNodes(root);
    int index = 0;
    printf("%d ",isComplete(root, index, numberOfNodes));
	return 0;
}