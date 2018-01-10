#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *left;
	struct node *right;
};

void inorder(struct node *root) //Morris Traversal
{
	struct node *current, *pre;
	current = root;
	while(current != NULL)
	{
		if(current ->left == NULL)
		{
			printf("%d ", current->data);
			current = current -> right;
		}
		else
		{
			pre = current -> left;
			while(pre->right != NULL && pre->right != current)
				pre = pre->right;
			if(pre->right == NULL)
			{
				pre->right = current;
				current = current -> left;
			}
			else
			{
				pre->right = NULL;
				printf("%d ", current->data);
				current = current->right;
			}
		}
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
	struct node *root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	inorder(root);
	return 0;
}