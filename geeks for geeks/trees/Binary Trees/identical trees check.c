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

int identical(struct node *root1, struct node *root2)
{
	if(root1 == NULL && root2 == NULL)
		return 1;
	else if(root1 != NULL && root2 != NULL)
	{
		return(root1->data == root2->data && identical(root1->left,root2->left) && identical(root1->right,root2->right));
	}
	return 0;
}

int main()
{
	struct node *root1 = newNode(1);
	root1->left        = newNode(2);
    root1->right       = newNode(3);
    root1->left->left  = newNode(4);
    root1->left->right = newNode(5);

    struct node *root2 = newNode(1);
    root2->left        = newNode(2);
    root2->right       = newNode(3);
    root2->left->left  = newNode(4);
    root2->left->right = newNode(5);

    if(identical(root1,root2))
    	printf("Identical");
    else
    	printf("Non-Identical");
	return 0;
}