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

int max(int a, int b)
{
	return (a >= b) ? a : b;
}

int height(struct node *root)
{
	if(root == NULL)
		return;
	return (1+max(height(root->left),height(root->right)));
}

int check(struct node *root)
{
	if(root == NULL)
		return 1;
	int lh = height(root->left);
	int rh = height(root->right);
	if(abs(lh-rh)<=1 && check(root->left) && check(root->right))
		return 1;
	return 0;
}

int main()
{
	struct node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->left->left->left = newNode(8);
 
    if(check(root))
      printf("Tree is balanced");
    else
      printf("Tree is not balanced");    
 
    
	return 0;
}