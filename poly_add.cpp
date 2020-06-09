//adding a polynomial
#include<stdio.h>
#include<stdlib.h>
typedef struct link 
{
	int coeff;
	int pow;
	struct link *next;
}polynomial;

/*void create_poly(polynomial **p) 
{
	int flag; //A flag to control the menu
	int coeff, pow;
	polynomial *temp;
	temp = (polynomial *) malloc(sizeof(polynomial)); 
	*p=temp;
	do 
	{
		printf("Enter Coeff: ");
		scanf("%d", &coeff);
		(temp)->coeff = coeff;
		printf("Enter Pow: ");
		scanf("%d", &pow);
		(temp)->pow = pow;
		printf("Continue adding more terms to the polynomial list?(Yes = 1/No = 0): ");
		scanf("%d", &flag);
		if(flag)
		{
			(temp)->next = (polynomial *) malloc(sizeof(polynomial)); //Grow the list
			(temp) = (temp)->next;
		}
	} while (flag);
	(temp)->next = NULL;
}*/
void create_poly(polynomial **poly) 
{
	int flag; //A flag to control the menu
	int coeff, pow;
	int i=1;
	polynomial *temp;//send head to temp
	temp = (polynomial *) malloc(sizeof(polynomial)); 
	*poly=temp;	
	printf("enter number of terms:");
	scanf("%d",&flag);
	while(flag>0) 
	{

		printf("Enter Coeff of %d:",i);
		scanf("%d", &coeff);
		(temp)->coeff = coeff;
		printf("Enter Pow of %d:",i++);
		scanf("%d", &pow);
		(temp)->pow = pow;
		flag--;
		if(flag==0)
			(temp)->next = NULL;
		else
		{
			(temp)->next = (polynomial *) malloc(sizeof(polynomial));
			temp = (temp)->next;
		}
	}
}
void show_poly(polynomial *temp)
{
	printf("The polynomial expression is: ");
	while(temp!= NULL) 
	{
		printf("(%d)^%d ", temp->coeff, temp->pow);
		temp = temp->next;
		if(temp != NULL)
			printf(" + ");
	}
}
void add_poly(polynomial **r,polynomial *p, polynomial *q) 
{
	polynomial *result;
	(result)= (polynomial *) malloc(sizeof(polynomial));
	*r=result;//storing head to the main r
	 (result)->next = NULL;
	//Loop while both of the linked lists have value
	while(p && q)	
	{
		if (p->pow > q->pow) 
		{
			(result)->pow = p->pow;//use brackets for result not even space
			(result)->coeff = p->coeff;
			p = p->next;
		}
		else if (p->pow < q->pow)
		{
			(result) ->pow = q->pow;
			(result)->coeff = q->coeff;
			q = q->next;
		}
		else 
		{
			(result) ->pow = p->pow;
			(result)->coeff = p->coeff + q->coeff;
			p= p->next;
			q = q->next;
		}
		if(p && q) 
		{
			(result) ->next = (polynomial *) malloc(sizeof(polynomial));
			result = (result)->next;
			(result) ->next = NULL;
		}
	}

	while(p || q) 
	{
	
		(result) ->next = (polynomial *) malloc(sizeof(polynomial));
		(result) = (result)->next;
		(result )->next = NULL;

		if(p) 
		{
			(result) ->pow = p->pow;
			(result) ->coeff = p->coeff;
			p = p->next;
		}
		if(q) 
		{
			(result) ->pow = q->pow;
			(result) ->coeff = q->coeff;
			q = q->next;
		}
	}
}

int main()
{
	int ch;
	do 
	{
		polynomial *p1,*p2,*result;//heads
		printf("enter 1st expression\n");
		create_poly(&p1);
		printf("Stored the 1st expression\n");
		show_poly(p1);
		printf("\nenter 2nd expression\n");
		create_poly(&p2);
		printf("Stored the 2nd expression\n");
		show_poly(p2);
		add_poly(&result, p1, p2);
		printf("\nresult of the polynomial\n");
		show_poly(result);//passing head of result
		printf("\nAdd two more expressions? (Y = 1/N = 0): ");
		scanf("%d", &ch);
	} while (ch);
	return 0;
}

/*
[rayapatiramya@localhost ds]$ ./a.out
enter 1st expression
enter number of terms:10
Enter Coeff of 1:3
Enter Pow of 1:^C
[rayapatiramya@localhost ds]$ gcc poly_add.c
[rayapatiramya@localhost ds]$ ./a.out
enter 1st expression
enter number of terms:4
Enter Coeff of 1:10
Enter Pow of 1:3
Enter Coeff of 2:20
Enter Pow of 2:1
Enter Coeff of 3:6 
Enter Pow of 3:2
Enter Coeff of 4:4
Enter Pow of 4:0
Stored the 1st expression
The polynomial expression is: (10)^3  + (20)^1  + (6)^2  + (4)^0 
enter 2nd expression
enter number of terms:3
Enter Coeff of 1:5
Enter Pow of 1:3
Enter Coeff of 2:6
Enter Pow of 2:2
Enter Coeff of 3:5
Enter Pow of 3:1
Stored the 2nd expression
The polynomial expression is: (5)^3  + (6)^2  + (5)^1 
result of the polynomial
The polynomial expression is: (15)^3  + (6)^2  + (25)^1  + (6)^2  + (4)^0 
Add two more expressions? (Y = 1/N = 0): 1
enter 1st expression
enter number of terms:4
Enter Coeff of 1:9
Enter Pow of 1:3
Enter Coeff of 2:8
Enter Pow of 2:2
Enter Coeff of 3:7
Enter Pow of 3:1
Enter Coeff of 4:6
Enter Pow of 4:0
Stored the 1st expression
The polynomial expression is: (9)^3  + (8)^2  + (7)^1  + (6)^0 
enter 2nd expression
enter number of terms:3
Enter Coeff of 1:7
Enter Pow of 1:3
Enter Coeff of 2:8
Enter Pow of 2:2
Enter Coeff of 3:6
Enter Pow of 3:0
Stored the 2nd expression
The polynomial expression is: (7)^3  + (8)^2  + (6)^0 
result of the polynomial
The polynomial expression is: (16)^3  + (16)^2  + (7)^1  + (12)^0 
Add two more expressions? (Y = 1/N = 0): 0

*/
