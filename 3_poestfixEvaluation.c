/*
3. Write a program to evaluate a given postfix expression using
 Stack.*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct lifo
{
       int	value;
	struct lifo *next;
};
typedef struct lifo stack;
stack *s;


int isoperator(char c)
{
	switch(c)
	{
		case '*':
		case '+':
		case '-':
		case '/':
		case '%':
			return 1;
		default :
			return 0;
	}
}



void create (stack **top)
{
	*top = NULL;
}
void push (stack **top, int element)
{
	stack *new;
	new = (stack *) malloc(sizeof(stack));
	if (new == NULL)
	{
		printf ("\n Stack is full");
		exit(-1);
	}
	new->value = element;
	new->next = *top;
	*top = new;
}

int pop (stack **top)
{
	int t;
	stack *p;
	if (*top == NULL)
	{
		printf ("\n Stack is empty");
		exit(-1);
	}
	else
	{
		t = (*top)->value;
		p = *top;
		*top = (*top)->next;
		free (p);
		return t;
	}
}

int isempty (stack *top)
{
	if (top == NULL)
		return (1);
	else
		return (0);
}

int s_top(stack **top)
{
	return (*top)->value;
}


int main()
{
	char postfix[100];
	printf("Enter postfix expression\n");
	scanf("%s",postfix);
	int i;
	char c;
	i =0;
	int a,b;
	int res;
	char temp1[2],temp2[2];
	//create(&s);
	while(postfix[i] != '\0')
	{
		c = postfix[i++];
		if(!isoperator(c))
		{
			temp1[0] = c;
			temp1[1] = '\0';
			a = atoi(temp1);
			push(&s,a);
		}
		else
		{
			a = pop(&s);
			b = pop(&s);
			switch(c)
			{
				case '+': res = a + b;
					  break;
				case '*': res = a * b;
					  break;
				case '-': res = a - b;
					  break;
				case '/': res = a / b;
					  break;
				case '%': res = a % b;
					  break;
			}
			push(&s,res);
		}
	}
	printf("The result is : %d",pop(&s));

}
/*
output:
Enter postfix expression
23+5*6-2^
The result is : 0
bash-4.3# ./a.out
Enter postfix expression
23+5*6-
The result is : -19
bash-4.3# 

*/

