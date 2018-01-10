#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *left;
	struct node *right;
};

int search(int a[], int start, int end,int x)
{
	int i;
	for(i = start ; i < end ; i++)
	{
		if(a[i] == x)
			return i;
	}
	return -1;
}

struct node *newNode(int data)
{
	struct node *new = malloc(sizeof(struct node));
	new->left = NULL;
	new->right = NULL;
	new->data = data;
	return (new);
}

struct node* buildTree(int inorder[], int preorder[], int start, int end)
{
	static int preIndex = 0;
	if(start > end)
		return NULL;
	struct node *new = newNode(preorder[preIndex++]);
	if(start == end)
		return new;

	int inIndex = search(inorder, start, end, new->data);
	new->left = buildTree(inorder, preorder, start, inIndex-1);
	new->right = buildTree(inorder,preorder, inIndex+1, end);

	return new;
}

void printInorder(struct node *root)
{
	if(root == NULL)
		return;
	printInorder(root->left);
	printf("%d ", root->data);
	printInorder(root->right);
}

int main()
{
	int n = 6;
	int preorder[] = {1,2,4,5,3,6};
	int inorder[] = {4,2,5,1,3,6};
	struct node *root = buildTree(inorder, preorder, 0 , 5);
	printInorder(root);
	return 0;
}