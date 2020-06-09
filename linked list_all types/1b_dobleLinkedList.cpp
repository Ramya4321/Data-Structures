//double linked list
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
	printf("How many elements to enter?");
	scanf("%d",&n);
	for(k=0;k<n;k++)
	{
		if(k==0)
		{
			head=(node *)malloc(sizeof(node));
			p=head;
			p->previous=NULL;
		}
		else
		{
			p->next=(node *)malloc(sizeof(node));
			p->next->previous=p;//previous will be set to as double linked list
			p=p->next;//comes to the newly created node 
		}
		printf("enter roll no,name,age for node %d:",k+1);
		scanf ("%d %s %d",&p->roll,p->name,&p->age);
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
void insert(node **head)//*head
{
	int k=0,rno;
	node *p,*q,*new;
	new=(node *)malloc(sizeof(node));
	printf("\nData to be inserted:");
	scanf("%d %s %d",&new->roll,new->name,&new->age);
	printf("\nInsert before roll (-ve for end):");
	scanf("%d",&rno);
	p=*head;//p=head
	if(p->roll==rno) /* At the beginning *///before the beginning
	{
		new->next=p;
		*head=new;//head=new
		new->previous=NULL;
	}
	else
	{
		while((p!=NULL)&&(p->roll!=rno))
		{
			q=p;
			p=p->next;
		}
		if(p==NULL) /* At the end *///it inserts at the end even if rno is greater than nodes
		{
			q->next=new;
			new->next=NULL;
			new->previous=q;
		}
		else if(p->roll==rno)/* In the middle */
		{
			q->next=new;
			new->next=p;
			p->previous=new;
			new->previous=q;
		}
	}
}
void delete(node **head)//*head
{
	int rno;
	node *p,*q;
	printf("Delete for roll :");
	scanf("%d",&rno);
	p=*head;//head
	if(p->roll==rno)/* Delete the first element */
	{
		*head=p->next;
	//	free(p);
		p->next->previous=NULL;//*head->previous=NULL
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
		else if(p->next==NULL && p->roll==rno)
		{
		       q->next=NULL;
		       free(p);
              }
		else if(p->roll==rno)/* Delete any other element */
		{
			q->next=p->next;
			p->next->previous=q;//me
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
output:
How many elements to enter?3
enter roll no,name,age for node 1:1 rMYa 8
enter roll no,name,age for node 2:2 ramya 18
enter roll no,name,age for node 3:3 asrs 19
1.insert        2.delete        3.display       4.exit
enter your choice:3

Node 1: 1 rMYa 8
Node 2: 2 ramya 18
Node 3: 3 asrs 19
1.insert        2.delete        3.display       4.exit
enter your choice:1

Data to be inserted:1 ddfh 376

Insert before roll (-ve for end):1
1.insert        2.delete        3.display       4.exit
enter your choice:3

Node 1: 1 ddfh 376
Node 2: 1 rMYa 8
Node 3: 2 ramya 18
Node 4: 3 asrs 19
1.insert        2.delete        3.display       4.exit
enter your choice:1

Data to be inserted:5 jfk 398

Insert before roll (-ve for end):6
1.insert        2.delete        3.display       4.exit
enter your choice:1

Data to be inserted:3 jdfa  362

Insert before roll (-ve for end):3
1.insert        2.delete        3.display       4.exit
enter your choice:3

Node 1: 1 ddfh 376
Node 2: 1 rMYa 8
Node 3: 2 ramya 18
Node 4: 3 jdfa 362
Node 5: 3 asrs 19
Node 6: 5 jfk 398
1.insert        2.delete        3.display       4.exit
enter your choice:2
Delete for roll :1
1.insert        2.delete        3.display       4.exit
enter your choice:2
Delete for roll :5
1.insert        2.delete        3.display       4.exit
enter your choice:2
Delete for roll :2
1.insert        2.delete        3.display       4.exit
enter your choice:3

Node 1: 1 rMYa 8
Node 2: 3 jdfa 362
Node 3: 3 asrs 19
1.insert        2.delete        3.display       4.exit
enter your choice:4
*/
