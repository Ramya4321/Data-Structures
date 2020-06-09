/*
5. Write a program to implement
(a) Stack using two Queues
*/
#include<stdio.h>
#include<stdlib.h>
typedef struct Node 
{
	int data;
	struct Node* next;
}que;

typedef struct fifo 
{
	que *front;
	que *rear;	
}queue;

typedef struct lifo
{
	 queue *q1,*q2;
}stack;
int isempty(que *r)
{
	if(r==NULL)
		return 1;
	else
		return 0;
}
void enqueue(que **r,int x) 
{
	que *rear=*r;
	if((rear)== NULL)
	{
		rear=(que *)malloc(sizeof(que));
		rear->data=x;
		rear->next=NULL;
	}
	else
	{
		rear->next=(que *)malloc(sizeof(que));
		rear=rear->next;
		rear->data=x;
		rear->next=NULL;
	}
}
int dequeue(que **f)
{
	int x;
	que *front = *f;
	x=front->data;
	(*f) = (*f)->next;
	free(front);
	return (x);
}
void push (stack **s,int element)
{
	
	if(isempty((*s)->q1->front))
	{
		enqueue(&((*s)->q1->rear),element);
	}
	else
	{
		while(!isempty(((*s)->q1->front)))
			enqueue(&((*s)->q2->rear),element),dequeue(&((*s)->q1->front));
		enqueue(&((*s)->q1->rear),element);
		while(!isempty((*s)->q2->front))
			enqueue(&((*s)->q1->rear),element),dequeue(&((*s)->q2->front));
	}
}
int pop(stack **s)
{
	int t;
	if((*s)->q1==NULL)
	{
		printf("\n Stack is empty");
		exit(-1);
	}
	else
	{
		t=dequeue(&((*s)->q1->front));
		return t;
	}
}
int main()
{
	stack *a;
	a->q1->front=a->q1->rear=NULL;
	a->q2->front=a->q2->rear=NULL;
	int x,c;
	while(1)
	{
		printf("1.push\n2.pop\n3.exit\n");
		printf("enter your choice:");
		scanf("%d",&c);
		if(c==1)
		{
			printf("enter element to be pushed into the stack:");
			scanf("%d",&x);
			push(&a,x);
		}
		else if(c==2)
		{
			printf("the element deleted is:%d\n",pop(&a));
		}
		else if(c==3)
			break;
		else
			printf("invalid choice\n");
	}

}
