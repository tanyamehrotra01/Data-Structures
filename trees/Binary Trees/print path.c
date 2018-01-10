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

void display(int pathArray[], int pathLength)
{
	int i;
	for(i = 0 ; i < pathLength ; i++)
		printf("%d ",pathArray[i]);
	printf("\n");
}

void path(struct node *root, int pathArray[], int pathLength)
{
	if(root == NULL)
		return;

	pathArray[pathLength++] = root->data;

	if(root->left == NULL && root->right == NULL)
		display(pathArray,pathLength);

	path(root->left, pathArray, pathLength);
	path(root->right, pathArray, pathLength);
}

int main()
{
	int pathArray[1000];
	int pathLength = 0;
	struct node *root = newNode(10);
  	root->left        = newNode(8);
  	root->right       = newNode(2);
  	root->left->left  = newNode(3);
  	root->left->right = newNode(5);
  	root->right->left = newNode(2);

  	path(root,pathArray,pathLength);
    
	return 0;
}