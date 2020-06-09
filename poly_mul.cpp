//multiplying a polynomial
#include<stdio.h>
#include<stdlib.h>
typedef struct link 
{
	int coeff;
	int pow;
	struct link *next;
}polynomial;
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
void mul_poly(polynomial **r,polynomial *p, polynomial *q) 
{
	polynomial *result,*qhead;
	(result)= (polynomial *) malloc(sizeof(polynomial));
	*r=result;//r stores newly created memory address
	qhead=q;//storing head to the main q
	// (result)->next = NULL;

	while(p!=NULL)	
	{
		while(q!=NULL)
		{	
			(result)->coeff = p->coeff*q->coeff;
			(result)->pow = p->pow+q->pow;
				q=q->next;
				if(q!=NULL)
				{
					(result)->next= (polynomial *) malloc(sizeof(polynomial));
					result=result->next;
				}
				
		}
		q=qhead;
		p=p->next;	
	}
	result->next=NULL;
}
void remove_duplicates(polynomial **rhead)
{
	polynomial *p1,*p2;
	p1 = (polynomial *) malloc(sizeof(polynomial)); 
	p2 = (polynomial *) malloc(sizeof(polynomial)); 
	p1=*rhead;
	
	while(p1!=NULL)
	{
		p2=p1->next;
		while(p2!=NULL)
		{
			if(p1->pow==p2->pow)
			{
				p1->coeff=p1->coeff+p2->coeff;
				p1->next=p2->next;
			}
			p2=p2->next;
		}
		p1=p1->next;
	
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
		mul_poly(&result, p1, p2);
		printf("\nresult of the polynomial\n");
		show_poly(result);//passing head of result
	//	printf("\nafter removing duplicates \n");
	//	remove_duplicates(&result);
	//	show_poly(result);
		printf("\nmultiply two more expressions? (Y = 1/N = 0): ");
		scanf("%d", &ch);
	} while (ch);
	return 0;
}

/*

*/
