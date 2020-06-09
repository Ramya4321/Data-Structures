/*
4. 4. Write a program to convert a given infix expression to postfix
 form using Stack.

Priority 2:* /
Priority 1:+ -
Priority 0:(
*/
#include<stdio.h>
#include<stdlib.h>
struct lifo
{
	char value;
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
int priority(char c)
{
	switch(c)
	{
		case '^':
			return 3;
		case '*':
		case '/':
		case '%':
			return 2;
		case '+':
		case '-':
			return 1;
		default : return 0;
	}
}
void create (stack **top)
{
	*top = NULL;
}
void push (stack **top, char element)
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
char pop (stack **top)
{
	char t;
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
char top(stack **top)
{
	return (*top)->value;
}
int main()
{
	//char *infix="a+b*c-d";//array
	char postfix[100];
	char infix[100];
	printf("enter infix expression:");
	scanf("%s",infix);
	create(&s);
	char c,c2;
	int i=0;
	int j=0;
	while(infix[i] != '\0')
	{
		c = infix[i++];
		if(c == '(')
			push(&s,c);//push to the stack
		else
		{
			if (c == ')')
			{
				c2 = pop(&s);
				while(c2 != '(')
				{
				
					postfix[j++] = c2;
					c2 = pop(&s);
				}
			}
			else if(isoperator(c))
			{
				while(!isempty(s) && priority(c)<=priority(c2=top(&s)))
					{
						pop(&s);
						postfix[j++] = c2;
					}//when checking priyority completed push c to the stack
				push(&s,c);
			}
			else 
				postfix[j++] = c;//then it is an alphabet, adding alphabets to the postfix 
		}

	}
	while(!isempty(s))
	{
		c =  pop(&s);
		postfix[j++] = c;
	}
	postfix[j] = '\0';
	printf("The equivalent Postfix expression is :%s\n",postfix);
}
/*
output:
[rayapatiramya@localhost ds]$ gcc in_to_po.c
[rayapatiramya@localhost ds]$ ./a.out
enter infix expression:a+(b*c-(d/e^f)*g)*h         
The equivalent Postfix expression is :abc*de^f/g*-h*+

*/
