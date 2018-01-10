/* Follow postorder */
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

void deleteNode(struct node *root)
{
	if(root == NULL)
		return;
	deleteNode(root->left);
	deleteNode(root->right);
	printf("deleting %d : ", root->data);
	free(root);
}

int main()
{
	struct node *root = newNode(1);
	root->left        = newNode(12);
    root->right       = newNode(15);
    root->left->left  = newNode(25);
    root->left->right = newNode(30);
    root->right->left = newNode(36);
    
    deleteNode(root);
	return 0;
}