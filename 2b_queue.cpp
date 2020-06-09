#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node
{
	char name[30];
	struct node *next;
};
typedef struct node QNODE;
typedef struct {
			QNODE *queue_front, *queue_rear;
		} QUEUE;
QNODE *enqueue (QUEUE *q, char x[])
{
	QNODE *temp;
	temp= (QNODE *)malloc (sizeof(QNODE));
	if (temp==NULL)
	{
		printf("Bad allocation \n");
		return NULL;
	}
	strcpy(temp->name,x);
	temp->next=NULL;
	if(q->queue_rear==NULL)
	{
		q->queue_rear=temp;
		q->queue_front=q->queue_rear;
	}
	else
	{
		q->queue_rear->next=temp;
		q->queue_rear=temp;
	}
	return(q->queue_rear);
}
char *dequeue(QUEUE *q,char x[])
{
	QNODE *temp_pnt;
	if(q->queue_front==NULL)
	{
		q->queue_rear=NULL;
		printf("Queue is empty \n");
		return(NULL);
	}
	else
	{
		strcpy(x,q->queue_front->name);
		temp_pnt=q->queue_front;
		q->queue_front=
		q->queue_front->next;
		free(temp_pnt);
		if(q->queue_front==NULL)
			q->queue_rear=NULL;
		return(x);
	}
}
void init_queue(QUEUE *q)
{
	q->queue_front= q->queue_rear=NULL;
}
int isEmpty(QUEUE *q)
{
	if(q==NULL)
		 return 1;
	else
		return 0;
}
void main()
{
	int i,j;
	char command[5],val[30];
	QUEUE q;
	init_queue(&q);
	command[0]='\0';
	printf("For entering a name use 'enter <name>'\n");
	printf("For deleting use 'delete' \n");
	printf("To end the session use 'bye' \n");
	while(strcmp(command,"bye"))
	{
		printf("enter command:\n");
		scanf("%s",command);
		if(!strcmp(command,"enter"))
		{
			printf("enter name:");
			scanf("%s",val);
			if((enqueue(&q,val)==NULL))
				printf("No more pushing please \n");
			else
				printf("Name entered %s \n",val);
		}
		if(!strcmp(command,"delete"))
		{
			if(!isEmpty(&q))
				printf("%s \n",dequeue(&q,val));
			else
				printf("Name deleted %s \n",val);
		}
	}
	printf("End session \n");
}
/*output:
[rayapatiramya@localhost ds]$ gcc queue.c
[rayapatiramya@localhost ds]$ ./a.out
For entering a name use 'enter <name>'
For deleting use 'delete' 
To end the session use 'bye' 
enter command:
enter
enter name:ramya
Name entered ramya 
enter command:
enter
enter name:sara
Name entered sara 
enter command:
delete
ramya 
enter command:
enter
enter name:helo
Name entered helo 
enter command:
enter 
enter name:home
Name entered home 
enter command:
delete
sara 
enter command:
delete                               
helo 
enter command:
delete
home 
enter command:
delete
Queue is empty 
(null) 
enter command:
bye
End session 

 */
