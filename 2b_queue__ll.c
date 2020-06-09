/*Queue - Linked List implementation*/
#include<stdio.h>
#include<stdlib.h>
struct Node 
{
	int data;
	struct Node* next;
};
// Two glboal variables to store address of front and rear nodes. 
struct Node* front = NULL;
struct Node* rear = NULL;
void Enqueue(int x) 
{
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
	temp->data =x; 
	temp->next = NULL;
	if(front == NULL && rear == NULL)
	{
		front = rear = temp;
		printf("element inserted succesfully \n");
	}
	else
	{
		rear->next = temp;
		rear = temp;
		printf("element inserted succesfully \n");
	}
}
// To Dequeue an integer.
void Dequeue()
{
	int x;
	struct Node* temp = front;
	if(front == NULL) 
	{
		printf("Queue is Empty\n");
		return ;
	}
	if(front == rear) 
	{
		front = rear = NULL;
	}
	else 
	{
		front = front->next;
	}
	printf("element removed , removed element is %d\n",temp->data);
	free(temp);
	return ;
}

void Front() 
	{
	if(front == NULL) {
		printf("Queue is empty\n");
		return;
	}
	printf("front element is %d\n",front->data);
 
}

void Print() 
{
	struct Node* temp = front;
	while(temp != NULL) 
	{
		printf("%d ",temp->data);
		temp = temp->next;
	}
	printf("\n");
}

int main()
{	
	int ch;
	int x;
	printf("1.enqueue 2.dequeue 3.front element 4.print all elements 5.exit \n");
	while(1)
	{
		printf("enter your choice: ");
		scanf("%d",&ch);
		if(ch==1)
		{
			printf("enter an element :");
			scanf("%d",&x);
			Enqueue(x);
		}
		else if(ch==2)
			Dequeue();
		else if(ch==3)
			Front();	
		else if(ch==4)
			 Print();
		else exit(0);

	}
}
/*
output:
[rayapatiramya@localhost ds]$ ./a.out
1.enqueue 2.dequeue 3.front element 4.print all elements 5.exit 
enter your choice: 1
enter an element :11
element inserted succesfully 
enter your choice: 1
enter an element :2
element inserted succesfully 
enter your choice: 1
enter an element :3
element inserted succesfully 
enter your choice: 4
11 2 3 
enter your choice: 2
element removed , removed element is 11
enter your choice: 3
front element is 2
enter your choice: 4
2 3 
enter your choice: 5
*/

