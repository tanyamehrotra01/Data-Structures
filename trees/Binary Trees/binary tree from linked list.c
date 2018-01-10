//Complete binary tree from linked list
//Linked list is level order traversal in sequential access form.

#include<stdio.h>
#include<stdlib.h>

struct ListNode
{
	int data;
	struct ListNode *next;
}*head;

struct BinaryTreeNode
{
	int data;
	struct BinaryTreeNode *left;
	struct BinaryTreeNode *right;
}*root;

//function to insert the node at the beginning of linked list

void addAtHead(struct ListNode **head, int data)
{
	struct ListNode *temp = malloc(sizeof(struct ListNode));
	temp -> data = data;
	temp -> next = *head;
	*head = temp;
}

//function to create BinaryTreeNode

struct BinaryTreeNode* newNode(int data)
{
	struct BinaryTreeNode *new = malloc(sizeof(struct BinaryTreeNode));
	new ->data = data;
	new ->left = NULL;
	new ->right = NULL;
	return new;
}

void convert(struct ListNode *head, struct BinaryTreeNode *root)
{
	struct ListNode *temp = head;
	while(head != NULL)
	{
		if(temp->next == NULL)
		{
			root -> data = temp->data;
			inorder(root);
			return;
		}
		else
		{
			head = temp->next;
			temp = head;
			root->left = newNode(head->data);
			if(temp->next == NULL)
				inorder(root);
			else
			{
				root->right = newNode(temp->next->data);
				temp = temp->next;
				head = temp;
			}
		}
	}
}

void inorder(struct BinaryTreeNode *root)
{
	if(root == NULL)
		return;
	inorder(root->left);
	printf("%d ", root->data);
	inorder(root->right);
}

int main()
{
	struct ListNode *head = NULL;
	addAtHead(&head, 36);
	addAtHead(&head, 30);
	addAtHead(&head, 25);
	addAtHead(&head, 15);
	addAtHead(&head, 12);
	addAtHead(&head, 10);
	
	struct BinaryTreeNode *root = newNode(10);
	
	convert(head, root);
	
	return 0;

}

