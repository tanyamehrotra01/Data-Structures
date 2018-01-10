#include<stdio.h>
#include<stdlib.h>
#define bool int

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

bool hasPathSum(struct node *root, int sum)
{
	if (root == NULL)
	{
		return (sum == 0);
	}
	else
	{
		bool ans = 0;

		int subSum = sum - root->data;
		if(subSum == 0 && root->left == NULL && root->right == NULL)
			return 1;
		if(root->left)
			ans = ans || hasPathSum(root->left,sum);
		if(root->right)
			ans = ans || hasPathSum(root->right,sum);
		return ans;
	}
	
}

int main()
{
	int sum = 21;
	struct node *root = newNode(10);
  	root->left        = newNode(8);
  	root->right       = newNode(2);
  	root->left->left  = newNode(3);
  	root->left->right = newNode(5);
  	root->right->left = newNode(2);

    if(hasPathSum(root,sum))
    	printf("Correct sum");
    else
    	printf("Incorrect sum");
	return 0;
}