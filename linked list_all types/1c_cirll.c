//circular linked list
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
	p->next=head;
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
	}while(p!=head);
	
}
void insert(node **head)
{
	int rno,pos=1;
	node *p,*q,*new,*last,*k;
	new=(node *)malloc(sizeof(node));
	printf("Data to be inserted:roll no,name, age: ");
	scanf("%d %s %d",&new->roll,new->name,&new->age);
	//printf("\nInsert before roll (-ve for end):");
	printf("insert at the position: ");	
	scanf("%d",&rno);
	p=*head;
	k=*head;
	do
	{
		k=k->next;
	}while(k->next!=*head);
	last=k;
	//if(p->roll==rno) /*inserts At the beginning */
	if(rno==1)
	{
		new->next=p;
		*head=new;
		last->next=*head;
	}
	else
	{
		do
		{
			q=p;
			p=p->next;
			++pos;
		}while(p->next!=*head && pos!=rno);
		//while((p!=*head)&&(p->roll!=rno));
		if(p->next==*head) /* insert At the end *///it inserts even if pos is greater than nodes
		{
			p->next=new;
			new->next=*head;
		}
		//else if(p->roll==rno)/*insert In the middle */
		else if(pos==rno)
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
	printf("\nDelete for roll :");
	scanf("%d",&rno);
	p=*head;
	if(p->roll==rno)/* Delete the first element */
	{
		*head=p->next;
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
			printf("\nNo match :: deletion failed");
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
[rayapatiramya@localhost ds]$ gcc circular.c
[rayapatiramya@localhost ds]$ ./a.out
How many elements to enter?3
enter roll no,name,age for node 1:1 ramya 18
enter roll no,name,age for node 2:2 sara 19
enter roll no,name,age for node 3:4 fak 39
1.insert	2.delete	3.display	4.exit
enter your choice:1
Data to be inserted:roll no,name, age: 3 uir 86
insert at the position: 3
1.insert	2.delete	3.display	4.exit
enter your choice:3
Node 1: 1 ramya 18
Node 2: 2 sara 19
Node 3: 4 fak 39
Node 4: 3 uir 86
1.insert	2.delete	3.display	4.exit
enter your choice:1
Data to be inserted:roll no,name, age: 5 fdj 376
insert at the position: 5
1.insert	2.delete	3.display	4.exit
enter your choice:3
Node 1: 1 ramya 18
Node 2: 2 sara 19
Node 3: 4 fak 39
Node 4: 3 uir 86
Node 5: 5 fdj 376
1.insert	2.delete	3.display	4.exit
enter your choice:2

Delete for roll :1
1.insert	2.delete	3.display	4.exit
enter your choice:2

Delete for roll :3
1.insert	2.delete	3.display	4.exit
enter your choice:2

Delete for roll :1

No match :: deletion failed1.insert	2.delete	3.display	4.exit
enter your choice:3
Node 1: 2 sara 19
Node 2: 4 fak 39
Node 3: 5 fdj 376
Node 4: 0  18
1.insert	2.delete	3.display	4.exit
enter your choice:4

*/
