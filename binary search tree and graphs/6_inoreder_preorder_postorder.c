/*aim:inorder preorder postorder for binary search tree*/
#include<stdio.h>
#include<stdlib.h>
typedef struct slink
{
    struct slink *left,*right;
    int data;
}node;
node *head=NULL;
node *root=NULL;
node* getnode()
{
    node *new;
    new=(node*)malloc(sizeof(node));
    printf("enter data");
    scanf("%d",&new->data);
    new->left=new->right=NULL;
    return new;
}
void createlist(int n)
{
    int i;
    node *new,*ptr,*temp;
    for(i=0;i<n;i++)
    {
        if(head==NULL)
        {
            new=getnode();
            head=new;
        }
        else
        {
            new=getnode();
            ptr=head;
            while(ptr!=NULL)
            {
                if(new->data<ptr->data)
                {
                    temp=ptr;
                    ptr=ptr->left;
                }
                else if(new->data>ptr->data)
                {
                    temp=ptr;
                    ptr=ptr->right;
                }
            }
            if(ptr==NULL)
            {
                if(temp->data<=new->data)
                {
                    temp->right=new;
                }
                else if(temp->data>new->data)
                {
                    temp->left=new;
                }
            }
        }
    }
}
void preorder(node *root)
{
    if(root!=NULL)
    {
        printf("%d\t",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void inorder(node *root)
{
    if(root!=NULL)
    {
      inorder(root->left);
      printf("%d\t",root->data);
      inorder(root->right);
    }
}
void postorder(node *root)
{
    if(root!=NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d\t",root->data);
    }
}
void main()
{
    int n,ch;
    printf("1.create\n2.preorder\n3.inorder\n4.postorder\n5.exit\n");
    while(1)
    {
        printf("enter your choice\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:printf("enter n");
                    scanf("%d",&n);
                    createlist(n);
                    break;
            case 2:printf("preorder is:\n");
                    preorder(head);
                    break;
            case 3:printf("inorder is:\n");
                    inorder(head);
                    break;
            case 4:printf("postorder is:\n");
                    postorder(head);
                    break;
            case 5:printf("exit");
                   exit(0);
                 
        }
    }
   
}

/*output:
1.create
2.preorder
3.inorder
4.postorder
5.exit
enter your choice
1
enter n5
enter data3
enter data5
enter data4
enter data2
enter data1
enter your choice
2
preorder is:
3	2	1	5	4	enter your choice
3
inorder is:
1	2	3	4	5	enter your choice
4
postorder is:
1	2	4	5	3	enter your choice
5
exit*/
