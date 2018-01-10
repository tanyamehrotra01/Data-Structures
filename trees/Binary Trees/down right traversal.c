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

void convert(struct node *root)
{
	if(root == NULL)
		return;

	convert(root->left);
	convert(root->right);

	if(root->left == NULL)
		root->left = root->right;
	else
		root->left->right = root->right;
	root->right = NULL;
}

void downRightTraversal(struct node *root)
{
	if(root == NULL)
		return;
	printf("%d ", root->data);
	downRightTraversal(root->right);
	downRightTraversal(root->left);
}

int main()
{
	/*struct node *root = newNode(1);
	root->left        = newNode(2);
    root->right       = newNode(3);
    root->left->left  = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->right->right->right = newNode(8);*/

    struct node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->right->left = newNode(4);
    root->right->right = newNode(5);
    root->right->left->left = newNode(6);
    root->right->right->left = newNode(7);
    root->right->right->right = newNode(8);
    
    convert(root);
    downRightTraversal(root);
	return 0;
}