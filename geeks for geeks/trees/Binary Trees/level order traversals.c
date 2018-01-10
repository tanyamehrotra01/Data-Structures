//O(N^2) in worst case if tree is skewed.

#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *left;
	struct node *right;
};

void printGivenLevel(struct node *root, int level)
{
	if(root == NULL)
		return;
	if(level == 1)
		printf("%d ", root->data);
	else if (level > 1)
	{
		printGivenLevel(root->left, level-1);
		printGivenLevel(root->right, level-1);
	}
}

void printLevelorder(struct node *root)
{
	int h = height(root);
	int d;
	for(d = 1 ; d <= h ; d++)
	{
		printGivenLevel(root,d);
		printf("\n"); //to print line by line
	}
}

int height(struct node *root)
{
	if(root == NULL)
		return;
	int lheight = height(root->left);
	int rheight = height(root->right);
	if(lheight > rheight)
		return (1 + lheight);
	else
		return (1 + rheight);
}

struct node *newNode(int data)
{
	struct node *new = malloc(sizeof(struct node));
	new->left = NULL;
	new->right = NULL;
	new->data = data;
	return (new);
}

int main()
{
	struct node *root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	printf("Level Order:\n");
	printLevelorder(root);
	return 0;
}