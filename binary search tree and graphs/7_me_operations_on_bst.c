/*
7. Write a program to perform operations on a Binary Search
 Tree (BST).
*/
#include<stdio.h>
#include<stdlib.h>
 
typedef struct BST
{
	int data;
	struct BST *left;
	struct BST *right;
}node;
node *create()
{
	node *temp;
	printf("nEnter data:");
	temp=(node*)malloc(sizeof(node));
	scanf("%d",&temp->data);
	temp->left=temp->right=NULL;
	return temp;
}
int find(node *root ,int data)
{
	if(root==data)
	{
		return 1;		
	}
	while(root->left!=NULL)
	find(root->left,data);
	while(root->right!=NULL)
	find(root->right,data);
	return 0;
}
void insert(node *root,node *temp)
{
	if(find(root->data)==0)
	{
		if(temp->data<root->data)
		{	
			if(root->left!=NULL)
				insert(root->left,temp);
			else
				root->left=temp;
		}	
		if(temp->data>root->data)
		{
			if(root->right!=NULL)
				insert(root->right,temp);
			else	
				root->right=temp;
		}	
	}
}
void preorder(node *root)
{
	if(root!=NULL)
	{
		printf("%d ",root->data);
		preorder(root->left);
		preorder(root->right);
	}
}
void inorder(node *t)
{
  if(t!=NULL)
  {
    inorder(t->left);
    printf("  %d",t->data);
    inorder(t->right);
  }
}
void postorder(node *t)
{
  if(t!=NULL)
  {
    postorder(t->left);
    postorder(t->right);
    printf("  %d",t->data);
  }
}
 
int main()
{
	char ch;
	int x;
	int data;
	node *root=NULL,*temp;
	while(1)
	{
		printf("1.insert\n 2.delete\n 3.find\n 4.inorder \n5.preorder \n6.postorder\n 7. exit\n");
		printf("enter your choice:");
		scanf("%d",&x);
		switch(x)
		{
			case 1:
				temp=create();
				if(root==NULL)
					root=temp;
				else	
					insert(root,temp);
			case 2:
				printf("enter element:");
				scanf("%d",data);
				delete(root,data);
			case 3:
				printf("enter element to be found :");
				scanf("%d",&data);
				data=find(root,data);
				if(data==1)
				printf("element foundn\n");
			case 4:
					inorder(root);
			case 5:
					preorder(root);
			case 6:
					postorder(root);
			case 7:
				exit(0);
		}
	}
	return 0;
}
