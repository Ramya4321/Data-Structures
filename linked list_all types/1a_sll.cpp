/*
1. Write program to implement the following data structures:
(a) Single Linked List
(b) Double Linked List
(c) Circular Linked List
*/

//single linked list
#include<stdio.h>
#include<stdlib.h>
struct stud
{
	int roll;
	char name[25];
	int age;
	struct stud *next;
};
typedef struct stud node;
node *create_list()
{
	int k,n;
	node *p,*head;
	printf("How many elements to enter?");
	scanf("%d",&n);
	for(k=0;k<n;k++)
	{
		if(k==0)
		{
			head=(node *)malloc(sizeof(node));
			p=head;
		}
		else
		{
			p->next=(node *)malloc(sizeof(node));
			p=p->next;
		}
		printf("enter roll no,name,age for node %d:",k+1);
		scanf("%d %s %d",&p->roll,p->name,&p->age);
	}
	p->next=NULL;
	return(head);
}
void display(node *head)
{
	int count=1;
	node *p;
	p=head;
	while(p!=NULL)
	{
		printf("\nNode %d: %d %s %d",count,p->roll,p->name,p->age);
		count++;
		p=p->next;
	}
	printf("\n");
}
void insert(node **head)
{
	int k=0,rno;
	node *p,*q,*new;
	new=(node *)malloc(sizeof(node));
	printf("Data to be inserted:");
	scanf("%d %s %d",&new->roll,new->name,&new->age);
	printf("Insert before roll (-ve for end):");//position ,if equal to roll it goes to first
	scanf("%d",&rno);//here roll no is an index number ,from this we can change the values of name and rollno at index
	p=*head;
	if(p->roll==rno) /* At the beginning */
	{
		new->next=p;
		*head=new;
	}
	else
	{
		while((p!=NULL)&&(p->roll!=rno))//moving p to the last
		{
			q=p;
			p=p->next;
		}
		if(p==NULL) /* At the end */
		{
			q->next=new;
			new->next=NULL;
		}
		else if(p->roll==rno)/* In the middle */
		{
			q->next=new;
			new->next=p;
		}
	}
}
void delete(node **head)
{
	int rno;
	node *p,*q;
	printf("Delete for roll :");
	scanf("%d",&rno);
	p=*head;
	if(p->roll==rno)/* Delete the first element */
	{
		*head=p->next;
		free(p);
	}
	else
	{
		while((p!=NULL)&&(p->roll!=rno))
		{
			q=p;
			p=p->next;
		}
		if(p==NULL) /* Element not found */
			printf("No match :: deletion failed\n");
		else if(p->roll==rno)/* Delete any other element */
		{
			q->next=p->next;
			free(p);
		}
	}
}
int main()
{
	int ch;
	node *head;
	head=create_list();
	while(1)
	{
		printf("1.insert\t2.delete\t3.display\t4.exit\n");
		printf("enter your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:insert(&head);
				break;
			case 2:delete(&head);
				break;
			case 3:display(head);
				break;
			case 4:exit(0);
			default:printf("INALID choice!!!\n");
		}
	}
	return 0;
}
/*
[rayapatiramya@localhost ds]$ gcc single_linked.c
[rayapatiramya@localhost ds]$ ./a.out
How many elements to enter?3
enter roll no,name,age for node 1:1 ramya 19
enter roll no,name,age for node 2:2 sara 18
enter roll no,name,age for node 3:4 hey 73
1.insert	2.delete	3.display	4.exit
enter your choice:1
Data to be inserted:3 h 3
Insert before roll (-ve for end):3
1.insert	2.delete	3.display	4.exit
enter your choice:1
Data to be inserted:34 retg 4  
Insert before roll (-ve for end):2
1.insert	2.delete	3.display	4.exit
enter your choice:3

Node 1: 1 ramya 19
Node 2: 34 retg 4
Node 3: 2 sara 18
Node 4: 4 hey 73
Node 5: 3 h 3
1.insert	2.delete	3.display	4.exit
enter your choice:2
Delete for roll :1
1.insert	2.delete	3.display	4.exit
enter your choice:2
Delete for roll :34
1.insert	2.delete	3.display	4.exit
enter your choice:3

Node 1: 2 sara 18
Node 2: 4 hey 73
Node 3: 3 h 3
1.insert	2.delete	3.display	4.exit
enter your choice:4
[rayapatiramya@localhost ds]$ 

*/
