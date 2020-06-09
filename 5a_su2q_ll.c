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
int isempty(queue *r)
{
	if(r==NULL)
		return 1;
	else
		return 0;
}
void enqueue(queue **q,int x) 
{	
	if((*q)->rear== NULL && (*q)->front==NULL)
	{
		(*q)->rear=(que *)malloc(sizeof(que));
		(*q)->rear->data=x;
		(*q)->rear->next=NULL;
		(*q)->front->data=(*q)->rear->data;
	}
	else
	{
		(*q)->rear->next=(que *)malloc(sizeof(que));
		(*q)->rear=(*q)->rear->next;
		(*q)->rear->data=x;
		(*q)->rear->next=NULL;
	}
}
int dequeue(queue **q)
{
	int x;
	que *f = (*q)->front;
	x=(*q)->front->data;
	(*q)->front = (*q)->front->next;
	free(f);
	return (x);
}
void push (stack **s,int element)
{
	
	if(isempty((*s)->q1))
	{
		enqueue(&((*s)->q1),element);
	}
	else
	{
		while(!(isempty((*s)->q1)))
			enqueue(&((*s)->q2),dequeue(&((*s)->q1)));
		enqueue(&((*s)->q1),element);
		while(!(isempty((*s)->q2)))
			enqueue(&((*s)->q1),dequeue(&((*s)->q2)));
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
		t=dequeue(&((*s)->q1));
		return t;
	}
}
int main()
{
	stack *a;
	a->q1->front=NULL;
	a->q1->rear=NULL;
	a->q2->front=NULL;
	a->q2->rear=NULL;
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
			exit(0);
		else
			printf("invalid choice\n");
	}

}
