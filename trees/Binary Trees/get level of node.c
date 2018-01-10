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

int getLevel(struct node *root, int data, int level)
{
	if(root == NULL)
		return;
	if(root->data == data)
		return level;

	int newLevel = getLevel(root->left, data,level + 1);
	if(newLevel != 0)
		return newLevel;
	newLevel = getLevel(root->right, data, level + 1);
	return newLevel;
}

int main()
{
	struct node *root = newNode(3);
	root->left        = newNode(2);
    root->right       = newNode(5);
    root->left->left  = newNode(1);
    root->left->right = newNode(4);
    int x = 4;

    printf("%d", getLevel(root,x,1));
    
	return 0;
}