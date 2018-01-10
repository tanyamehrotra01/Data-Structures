#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *left;
	struct node *right;
};

void convertTree(struct node *node)
{
	int left_data = 0 , right_data = 0 , diff;

	if(node == NULL || (node->left == NULL && node->right == NULL))
		return;
	else
	{
		convertTree(node->left);
		convertTree(node->right);

		if(node->left != NULL)
			left_data = node->left->data;
		if(node->right != NULL)
			right_data = node->right->data;

		diff = right_data + left_data - node->data;

		if(diff > 0)
			node->data = node->data + diff;

		if(diff < 0)
			increment(node, -diff);

	}

}

void increment(struct node *node, int diff)
{
	if(node->left != NULL)
	{
		node->left->data = node->left->data + diff;
		increment(node->left, diff);
	}
	else if(node->right != NULL)
	{
		node->right->data = node->right->data + diff;
		increment(node->right, diff);
	}
}

void inorder(struct node *root)
{
	if(root == NULL)
		return;
	else
	{
		inorder(root->left);
		printf("%d ", root->data);
		inorder(root->right);
	}
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
	struct node *root = newNode(50);
	root->left        = newNode(7);
    root->right       = newNode(2);
    root->left->left  = newNode(3);
    root->left->right = newNode(5);
    root->right->left = newNode(1);
    root->right->right = newNode(30);
    inorder(root);
    convertTree(root);
    inorder(root);

    return 0;
}