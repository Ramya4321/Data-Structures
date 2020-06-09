//stack
#include<stdio.h>
#include<stdlib.h>
struct lifo
{
	int value;
	struct lifo *next;
};
typedef struct lifo stack;
stack *top;
void create(stack **top)
{
	*top=NULL;
}
void push(stack **top,int element)
{
	stack *new;
	new=(stack *)malloc(sizeof(stack));
	if(new==NULL)
	{
		printf("\n Stack is full");
		exit(-1);
	}
	new->value=element;
	new->next=*top;
	*top=new;
}
int pop(stack **top)
{
	int t;
	stack *p;
	if(*top==NULL)
	{
		printf("\n Stack is empty");
		exit(-1);
	}
	else
	{
		t=(*top)->value;
		p=*top;
		*top=(*top)->next;
		free (p);
		return t;
	}
}
int isempty(stack *top)
{
	if(top==NULL)
		return 1;
	else
		return 0;
}
void main()
{
	stack *a;
	create(&a);
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
	if(isempty(a))
		printf("stack is empty\n");
}
/*output:
1.push
2.pop
3.exit
enter your choice:1
enter element to be pushed into the stack:10
1.push
2.pop
3.exit
enter your choice:1
enter element to be pushed into the stack:20
1.push
2.pop
3.exit
enter your choice:1
enter element to be pushed into the stack:30
1.push
2.pop
3.exit
enter your choice:2
the element deleted is:30
1.push
2.pop
3.exit
enter your choice:2
the element deleted is:20
1.push
2.pop
3.exit
enter your choice:2
the element deleted is:10
1.push
2.pop
3.exit
enter your choice:3
stack is empty
*/
