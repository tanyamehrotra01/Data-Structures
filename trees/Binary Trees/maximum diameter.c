/*The diameter of a tree T is the largest of the following quantities:

* the diameter of T’s left subtree
* the diameter of T’s right subtree
(The above does not go through the root)
* the longest path between leaves that goes through the root of T (this can be computed from the heights of the subtrees of T) 
*/

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

int diameter(struct node *root)
{
	if(root == NULL)
		return 0;

	int lh = height(root->left);
	int rh = height(root->right);

	int ldia = diameter(root->left);
	int rdia = diameter(root->right);

	return max((lh + rh + 1), max(ldia,rdia));
}

int main()
{
	struct node *root = newNode(1);
	root->left        = newNode(2);
    root->right       = newNode(3);
    root->left->left  = newNode(4);
    root->left->right = newNode(5);
    
    printf("Diameter : %d",diameter(root));
    
	return 0;
}