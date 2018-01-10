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
		return 1;
	int lh = height(root->left);
	int rh = height(root->right);
	return (max(lh,rh) + 1);
}

int getWidth(struct node *root, int level)
{
	if(root == NULL)
		return 0;
	if(level == 1)
		return 1;
	else if(level > 1)
	{
		return (getWidth(root->left,level-1) + getWidth(root->right,level-1));
	}
}

int getMaxWidth(struct node *root)
{
	int maxWdth = 0, i;
	int h = height(root);
	for(i = 1 ; i <= h ; i++)
	{
		int width = getWidth(root,i);
		if(width > maxWdth)
			maxWdth = width;
	}
	return maxWdth;
}

int main()
{
	struct node *root = newNode(1);
  	root->left        = newNode(2);
  	root->right       = newNode(3);
  	root->left->left  = newNode(4);
  	root->left->right = newNode(5);
  	root->right->right = newNode(8);    
  	root->right->right->left  = newNode(6);    
  	root->right->right->right  = newNode(7); 
    
    printf("%d", getMaxWidth(root));
	return 0;
}