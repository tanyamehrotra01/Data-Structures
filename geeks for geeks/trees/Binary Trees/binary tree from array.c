/*Given an array that represents a tree in such a way that array indexes are values in tree nodes and array values give the parent node of that particular index (or node). The value of the root node index would always be -1 as there is no parent for root. Construct the standard linked representation of given Binary Tree from this given representation.*/

/*Example:
Input: parent[] = {1, 5, 5, 2, 2, -1, 3}
Explanation: 
Index of -1 is 5.  So 5 is root.  
5 is present at indexes 1 and 2.  So 1 and 2 are
children of 5.  
1 is present at index 0, so 0 is child of 1.
2 is present at indexes 3 and 4.  So 3 and 4 are
children of 2.  
3 is present at index 6, so 6 is child of 3.
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

//Creates a node with key as 'i'. If i is root, it changes root. 
//If parent of i is not created, it creates parent first.

void createNode (int parent[], int i, struct node *created[], struct node **root)
{
	if(created[i] != NULL)
		return;

	//create a new node and set created[i]
	created[i] = newNode(i);

	//If i is root,change the root pointer
	if(parent[i] == -1)
	{
		*root = created[i];
		return;
	}

	//If parent is not created, create parent first
	if(created[parent[i]] == NULL)
		createNode(parent,parent[i], created, &root);

	//Find parent pointer
	struct node *p = created[parent[i]];

	if(p->left == NULL)
		p->left = created[i];
	else
		p->right = created[i];
}

struct node *createTree(int parent[], int n)
{
	//create an array created[] to keep track
	//of created nodes, initialize all entires as NULL
	struct node *created[n];
	int i;
	for(i = 0 ; i < n ; i++)
	{
		created[i] = NULL;
	}

	struct node *root = NULL;
	for(i = 0 ; i < n ; i++)
	{
		createNode(parent, i ,created, &root);
	}

	return root;
}

void inorder(struct node *root)
{
	if(root == NULL)
		return;
	inorder(root->left);
	printf("%d ",root->data);
	inorder(root->right);
}
int main()
{
	int parent[] = {-1,0,0,1,1,3,5};
	int n = 7;
	struct node *root = createTree(parent,n);
	inorder(root);
	return 0;
}
