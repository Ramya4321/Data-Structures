#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
struct node *head =NULL;
void insert_beg()
{
	struct  node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	printf("enter the  data of type integer to insert at the beginning\t");
	scanf("%d",&temp->data);
	if(head==NULL)
	{
 		head=temp;
		temp->next=NULL;
	}
	else
	{
		temp->next=head;
		head=temp;	
	}
}
void insert_pos()
{
	struct node *p,*temp;
	int pos,i;
	temp=(struct node *)malloc(sizeof(struct node));
	printf("enter the data  to insert at the position \t");
	scanf("%d",&temp->data);
	if(head==NULL)
	{
		printf("list is empty ,your data is stored to display \n");
		temp->next=NULL;
		head=temp;
	}
	else
	{
		
		printf("enter the position at which the data to be inserted\t");
		scanf("%d",&pos);
		p=head;
		for(i=1;i<=pos-1;i++)
		{
			p=p->next;
			if(p==NULL)
			{
				printf("insertion not possible\n");
				return ;
			}			
		}
		temp->next=p->next;
		p->next=temp;
	}
}
void insert_end()
{
	struct node *p;
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	printf("enter the data of type integer to insert at the end \t");
	scanf("%d",&temp->data);
	if(head==NULL)
	{
		head=temp;
		temp->next=NULL;
				
	}
	else
	{
		p=head;
		while(p->next!=NULL)
		{
			p=p->next;			
		}
		p->next=temp;
		temp->next=NULL;	
	}
}	
void delete_beg()
{
	struct node *p;
	if(head==NULL)
	{
		printf("list empty\n");
		return;
	}
	else 
	{
		p=head;
		printf("deleted data is %d",p->data);
		head=head->next;
		free(p);
	}
}	
void delete_end(void)
{
	struct node *p,*q;
	if(head==NULL)
	{
		printf("list is empty\n");
		return;
	}	
	else if(head->next==NULL)
	{
		p=head;
		printf("deleted data %d\n",p->data);	
		free(head);
		head=NULL;
	}
	else
	{
		p=head;
		while(p->next!=NULL)
		{
			q=p;
			p=p->next;
		}
		q->next=NULL;
		printf("deleted element is %d\n",p->data);
		free(p);
	}
}
void delete_pos()
{
	int pos;
	struct node *p,*q;
	if(head==NULL)
	{
		printf("list empty\n");
		return;
	}
	printf("enter position ");
	scanf("%d",&pos);		
	p=head;
	for(int i=1;i<=pos-1;i++)
	{
		q=p;
		p=p->next;	
	}
		q->next=p->next;//q->next=q->next->next
		printf("deleted element is %d\n",p->data);
		free(p);
}
void display(void)
{
	struct node *p;
	p=head;
	while(p!=NULL)
	{
		printf("%d\n",p->data);
		p=p->next;
	}
	if(head==NULL)
	printf("empty list\n");
}
int main()
{	
	int x;
	printf("1.insert at beginning \n 2. insert at the end\n 3.insert at the position \n 4.delete at the beginning \n 5.delete at end \n 6. delete at a position \n 7.display \n 8.exit\n");
	while(1)
	{
	printf("enter your choice ");
	scanf("%d",&x);
	switch(x)
		{
		case 1: insert_beg();
			break;
		case 2: insert_end();
			break;
		case 3: insert_pos();
			break;
		case 4: delete_beg();
			break;
		case 5: delete_end();
			break;
		case 6: delete_pos();
			break;
		case 7: display();
			break;
		case 8: exit(0);
		}

	}
}
/*
output:
ubuntu@ubuntu:~/ramya$ gcc week1a.c
ubuntu@ubuntu:~/ramya$ ./a.out
1.insert at beginning 
 2. insert at the end
 3.insert at the position 
 4.delete at the beginning 
 5.delete at end 
 6. delete at a position 
 7.display 
 8.exit
enter your choice 1
enter the  data of type integer to insert at the beginning	23
enter your choice 1
enter the  data of type integer to insert at the beginning	235
enter your choice 2
enter the data of type integer to insert at the end 	4563
enter your choice 6
enter position 2
deleted element is 23
enter your choice 3
enter the data  to insert at the position 	2
enter the position at which the data to be inserted	2
enter your choice 7
235
4563
2
enter your choice 6
enter position 3
deleted element is 2
enter your choice 4
deleted data is 235enter your choice 5
deleted data 4563
enter your choice 7
empty list
enter your choice 8
ubuntu@ubuntu:~/ramya$ 

*/
