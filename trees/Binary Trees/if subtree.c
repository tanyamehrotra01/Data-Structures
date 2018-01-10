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

int areIdentical(struct node *root1, struct node *root2)
{
	if(root1 == NULL && root2 == NULL)
		return 1;
	if(root1 == NULL || root2 == NULL)
		return 0;
	return ((root1->data == root2->data) && areIdentical(root1->left,root2->left) && areIdentical(root1->right, root2->right));
}

int isSubtree(struct node *root1, struct node *root2)
{
	if(root1 == NULL) //T(main tree)
		return 0;
	if(root2 == NULL) //S (subtree)
		return 1;
	if(areIdentical(root1,root2))
		return 1;
	return (isSubtree(root1->left,root2) || isSubtree(root1->right,root2));
}

int main()
{
	struct node *T        = newNode(26);
    T->right              = newNode(3);
    T->right->right       = newNode(3);
    T->left               = newNode(10);
    T->left->left         = newNode(4);
    T->left->left->right  = newNode(30);
    T->left->right        = newNode(6);
    
    struct node *S    = newNode(10);
    S->right          = newNode(6);
    S->left           = newNode(4);
    S->left->right    = newNode(30);

    if(isSubtree(T,S))
    {
    	printf("Subtree exists");
    }
    else
    {
    	printf("Subtree doesn't exist");
    }
	return 0;
}
