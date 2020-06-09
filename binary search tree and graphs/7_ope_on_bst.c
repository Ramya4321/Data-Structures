/*
7. Write a program to perform operations on a Binary Search
 Tree (BST).
*/
#include <stdio.h>
#include <stdlib.h>
struct treeNode 
{
        int data;
        struct treeNode *left, *right;
};
struct treeNode *root = NULL;
struct treeNode* createNode(int data) 
{
        struct treeNode *newNode;
        newNode = (struct treeNode *) malloc(sizeof (struct treeNode));
        newNode->data = data;
        newNode->left = NULL;
        newNode->right = NULL;
        return(newNode);
}
void insertion(struct treeNode **node, int data) 
{
        if (*node == NULL) 
		{
                *node = createNode(data);
        } else if (data < (*node)->data) 
		{
                insertion(&(*node)->left, data);
        } else if (data > (*node)->data) 
		{
                insertion(&(*node)->right, data);
        }
}
void deletion(struct treeNode **node, struct treeNode **parent, int data) 
{
        struct treeNode *tempNode, *tempParent;
        if (*node == NULL)
                return;
        if ((*node)->data == data) 
		{
                if (!(*node)->left && !(*node)->right) 
				{
                        if (parent) 
						{
                                if ((*parent)->left == *node)
                                        (*parent)->left = NULL;
                                else
                                        (*parent)->right = NULL;
                                free(*node);
                        } else 
						{
                                free(*node);
                        }
                } else if (!(*node)->right && (*node)->left) 
				{
                        tempNode = *node;
                        (*parent)->right = (*node)->left;
                        free(tempNode);
                        *node = (*parent)->right;
                } else if ((*node)->right && !(*node)->left) 
				{
                        tempNode = *node;
                        (*parent)->left = (*node)->right;
                        free(tempNode);
                        (*node) = (*parent)->left;
                } 
				else if (!(*node)->right->left) 
				{
                        tempNode = *node;

                        (*node)->right->left = (*node)->left;

                        (*parent)->left = (*node)->right;
                        free(tempNode);
                        *node = (*parent)->left;
                } else 
				{
                        tempNode = (*node)->right;
                        while (tempNode->left) 
						{
                                tempParent = tempNode;
                                tempNode = tempNode->left;
                        }
                        tempParent->left = tempNode->right;
                        tempNode->left = (*node)->left;
                        tempNode->right =(*node)->right;
                        free(*node);
                        *node = tempNode;
                }
        } 
		else if (data < (*node)->data) 
		{
                deletion(&(*node)->left, node, data);
        } else if (data > (*node)->data) 
		{
                deletion(&(*node)->right, node, data);
        }
}
void findElement(struct treeNode *node, int data) 
{
        if (!node)
                return;
        else if (data < node->data) 
		{
                findElement(node->left, data);
        } else if (data > node->data) 
		{
                findElement(node->right, data);
        } else
                printf("data found: %d\n", node->data);
        return;
}
void traverse(struct treeNode *node) 
{
        if (node != NULL) 
		{
                traverse(node->left);
                printf("%3d", node->data);
                traverse(node->right);
        }
        return;
}
int main() 
{
        int data, ch;
        while (1) 
		{
                printf("1. Insertion in Binary Search Tree\n");
                printf("2. Deletion in Binary Search Tree\n");
                printf("3. Search Element in Binary Search Tree\n");
                printf("4. Inorder traversal\n5. Exit\n");
                printf("Enter your choice:");
                scanf("%d", &ch);
                switch (ch) 
				{
                        case 1:
                                while (1) 
								{
                                printf("Enter your data:");
                                scanf("%d", &data);
                                insertion(&root, data);
                                printf("Continue Insertion(0/1):");
                                scanf("%d", &ch);
                                if (!ch)
                                        break;
                                }
                                break;
                        case 2:
                                printf("Enter your data:");
                                scanf("%d", &data);
                                deletion(&root, NULL, data);
                                break;
                        case 3:
                                printf("Enter value for data:");
                                scanf("%d", &data);
                                findElement(root, data);
                                break;
                        case 4:
                                printf("Inorder Traversal:\n");
                                traverse(root);
                                printf("\n");
                                break;
                        case 5:
                                exit(0);
                        default:
                                printf("u've entered wrong option\n");
                                break;
                }
        }
        return 0;

}
/*output:
1. Insertion in Binary Search Tree
2. Deletion in Binary Search Tree
3. Search Element in Binary Search Tree
4. Inorder traversal
5. Exit
Enter your choice:1
Enter your data:1
Continue Insertion(0/1):1
Enter your data:12
Continue Insertion(0/1):1
Enter your data:9
Continue Insertion(0/1):1
Enter your data:5
Continue Insertion(0/1):1
Enter your data:6
Continue Insertion(0/1):0
1. Insertion in Binary Search Tree
2. Deletion in Binary Search Tree
3. Search Element in Binary Search Tree
4. Inorder traversal
5. Exit
Enter your choice:4
Inorder Traversal:
  1  5  6  9 12
1. Insertion in Binary Search Tree
2. Deletion in Binary Search Tree
3. Search Element in Binary Search Tree
4. Inorder traversal
5. Exit
Enter your choice:2
Enter your data:6
1. Insertion in Binary Search Tree
2. Deletion in Binary Search Tree
3. Search Element in Binary Search Tree
4. Inorder traversal
5. Exit
Enter your choice:2
Enter your data:5
1. Insertion in Binary Search Tree
2. Deletion in Binary Search Tree
3. Search Element in Binary Search Tree
4. Inorder traversal
5. Exit
Enter your choice:4
Inorder Traversal:
  1  9 12
1. Insertion in Binary Search Tree
2. Deletion in Binary Search Tree
3. Search Element in Binary Search Tree
4. Inorder traversal
5. Exit
Enter your choice:3
Enter value for data:1
data found: 1
1. Insertion in Binary Search Tree
2. Deletion in Binary Search Tree
3. Search Element in Binary Search Tree
4. Inorder traversal
5. Exit
Enter your choice:5*/
