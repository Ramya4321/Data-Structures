/*****************************************
5. Write a program to implement
(a) Stack using two Queues
*****************************************/
#include<stdio.h>
#include<stdlib.h>
int queue1[20],queue2[20];
int front1=0,rear1=0,front2=0,rear2=0;
int *q1=queue1,*q2=queue2;
int *t,p;
void push(void)
{
	int data;
	printf("Enter element\n");
	scanf("%d",&data);
	q2[rear2++]=data;//q2 is main queue
}
void pop(void)
{
	if(rear1==0 && rear2==0)
	{
		printf("Stack is empty\n");
		return;
	}
	while(front2<(rear2-1))//rear2 will reducing
	{
		q1[rear1++]=q2[front2++];//use 2 whenever q2
	}
	printf("Popped element is %d\n",q2[front2]);
	front2=rear2=0;//for showing stack is empty
//	t=q1;
//	q1=q2;
//	q2=t;
	p=front1;
	front1=front2;
	front2=p;
	p=rear1;
	rear1=rear2;
	rear2=p;
}
int main()
{
	int ch;
	while(1)
	{
		printf("1.push \t 2.pop \t 3.Exit\n");
		printf("Enter your choice:\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1 : push();
			         break;
			case 2 : pop();
			         break;
			case 3 : exit(0);
			default : 
			           printf("Inavalid choice\n");		          
		}
	}
}
/*********************************************************
Output :
1.push   2.pop   3.Exit
Enter your choice:
1
Enter element
5
1.push   2.pop   3.Exit
Enter your choice:
1
Enter element
15
1.push   2.pop   3.Exit
Enter your choice:
2
Popped element is 15
1.push   2.pop   3.Exit
Enter your choice:
2
Popped element is 5
1.push   2.pop   3.Exit
Enter your choice:
2
Stack is empty
1.push   2.pop   3.Exit
Enter your choice:
3                           
************************************************************/
