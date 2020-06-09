//doubly circular list
#include<stdio.h>
#include<stdlib.h>
struct stud
{
	int roll;
	char name[25];
	int age;
	struct stud *previous;
	struct stud *next;
};
typedef struct stud node;
node *create_list()
{
	int k,n;
	node *p,*head;
	printf("How many elements to enter? ");
	scanf("%d",&n);
	for(k=0;k<n;k++)
	{
		if(k==0)
		{
			head=(node *)malloc(sizeof(node));
			p=head;
			p->previous=head;
		}
		else
		{
			p->next=(node *)malloc(sizeof(node));
			p->next->previous=p;
			p=p->next;
		}
		printf("enter roll no,name,age for node %d:",k+1);
		scanf ("%d %s %d",&p->roll,p->name,&p->age);
	}
	p->next=head;
	head->previous=p;//me
	return(head);
}
void display(node *head)
{
	int count=1;
	node *p;
	p=head;
	do
	{
		printf("Node %d: %d %s %d\n",count,p->roll,p->name,p->age);
		count++;
		p=p->next;
	}while(p!=head );
//	printf("\n");
}
void insert(node **head)
{
	int rno,pos=1;
	node *p,*q,*new,*k,*last;
	new=(node *)malloc(sizeof(node));
	printf("Data to be inserted:");
	scanf("%d %s %d",&new->roll,new->name,&new->age);
	printf("Insert at the position :");
	scanf("%d",&rno);
	p=*head;
	k=*head;
	do
	{
		k=k->next;
	}while(k->next!=*head);
	last=k;
	if(rno==1) /* At the beginning */
	{
		new->previous=p->previous;
		new->next=p;
		last->next=new;
		*head=new;
	}
	else
	{
		while((p->next!=*head)&&(rno!=pos))
		{
			q=p;
			p=p->next;
			++pos;
		}
		if(p->next==*head) /* At the end *///if rollno not found it replaces qt the end
		{
			q->next=new;
			new->next=*head;
			new->previous=q;
		}
		else if(pos==rno)/* In the middle */
		{
			q->next=new;
			new->next=p;
			p->previous=new;
			new->previous=q;
		}
		else
		    printf("data cannot be inserted\n");//not showing
	}
}
void delete(node **head)
{
	int rno;
	node *p,*q;
	printf("Delete for roll :");
	scanf("%d",&rno);
	p=*head;
	if(p->roll==rno)/* Delete the first element *///something wrong here
	{
		*head=p->next;
		q=p->next;
	       //free(p);
		//q->previous=p->previous;
		p->previous->next=*head;
		q->previous=p->previous;
		free(p);
	}
	else
	{
		do
		{
			q=p;
			p=p->next;
		}while((p!=*head)&&(p->roll!=rno));
		if(p==*head) /* Element not found */
			printf("No match :: deletion failed\n");
		
		else if(p->roll==rno)/* Delete any other element */
		{
			q->next=p->next;
			p->next->previous=q;
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
[rayapatiramya@localhost ds]$ gcc doubly_circlar.c
[rayapatiramya@localhost ds]$ ./a.out
How many elements to enter? 3
enter roll no,name,age for node 1:1 ramya 18
enter roll no,name,age for node 2:2 sara 20 
enter roll no,name,age for node 3: 4 heol 29
1.insert	2.delete	3.display	4.exit
enter your choice:3
Node 1: 1 ramya 18
Node 2: 2 sara 20
Node 3: 4 heol 29
1.insert	2.delete	3.display	4.exit
enter your choice:1
Data to be inserted:3 dj 36
Insert at the position :3
1.insert	2.delete	3.display	4.exit
enter your choice:3
Node 1: 1 ramya 18
Node 2: 2 sara 20
Node 3: 3 dj 36
1.insert	2.delete	3.display	4.exit
enter your choice:1
Data to be inserted:1 jsdf 73
Insert at the position :1
1.insert	2.delete	3.display	4.exit
enter your choice:3
Node 1: 1 jsdf 73
Node 2: 1 ramya 18
Node 3: 2 sara 20
Node 4: 3 dj 36
1.insert	2.delete	3.display	4.exit
enter your choice:1
Data to be inserted:5 sgf 37
Insert at the position :5
1.insert	2.delete	3.display	4.exit
enter your choice:3
Node 1: 1 jsdf 73
Node 2: 1 ramya 18
Node 3: 2 sara 20
Node 4: 5 sgf 37
1.insert	2.delete	3.display	4.exit
enter your choice:2
Delete for roll :1
1.insert	2.delete	3.display	4.exit
enter your choice:3
Node 1: 1 ramya 18
Node 2: 2 sara 20
Node 3: 5 sgf 37
Node 4: 0  73
1.insert	2.delete	3.display	4.exit
enter your choice:4

*/
