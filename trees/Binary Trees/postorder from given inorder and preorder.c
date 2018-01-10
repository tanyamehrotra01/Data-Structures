/*We can print postorder traversal without constructing the tree. The idea is, root is always the first item in preorder traversal and it must be the last item in postorder traversal. We first recursively print left subtree, then recursively print right subtree. Finally, print root. To find boundaries of left and right subtrees in pre[] and in[], we search root in in[], all elements before root in in[] are elements of left subtree and all elements after root are elements of right subtree. In pre[], all elements after index of root in in[] are elements of right subtree. And elements before index (including the element at index and excluding the first element) are elements of left subtree.*/

/*Example : 
Inorder = {4,2,5,1,3,6}
Preorder = {1,2,4,5,3,6}

Output: 
Postorder = {4,5,2,6,3,1}
*/

#include<stdio.h>
#include<stdlib.h>

int search(int a[], int x, int n)
{
	int i;
	for(i = 0 ; i < n ; i++)
	{
		if(a[i] == x)
			return i;
	}
	return -1;
}

void printPostOrder(int inorder[], int preorder[], int n)
{
	int root = search(inorder,preorder[0],n);
	if(root != 0) //left subtree exists
	{
		printPostOrder(inorder, preorder+1, root);
	}
	if(root != n-1)
	{
		printPostOrder(inorder+root+1, preorder+root+1, n-root-1);
	}
	printf("%d ", preorder[0]);
}

int main()
{
	int n = 6;
	int preorder[] = {1,2,4,5,3,6};
	int inorder[] = {4,2,5,1,3,6};
	printPostOrder(inorder,preorder,n);
	return 0;
}
