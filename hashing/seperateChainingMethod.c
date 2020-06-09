/*PROGRAM TO IMPLEMENT HASHING USING SEPERATE CHAINING METHOD*/
#include<stdio.h>
#include<stdlib.h>
#define TABLE_SIZE 10
struct node
{
	int data;
	struct node *next;
};
struct node *head[TABLE_SIZE]={NULL},*c;
void insert()
{
	int i,key;
	printf("\nenter a value to insert into hash table\n");
	scanf("%d",&key);
	i=key%TABLE_SIZE;
	struct node *newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=key;
	newnode->next=NULL;
	if(head[i]==NULL)
		head[i]=newnode;
	else
	{
		c=head[i];
		while(c->next!=NULL)
		{
			c=c->next;
		}
		c->next=newnode;
	}
}
void search()
{
	int key,index;
	printf("\nenter the element to be searched\n");
	scanf("%d",&key);
	index=key%TABLE_SIZE;
	if(head[index]==NULL)
		printf("\nsearch element not found\n");
	else
	{
		for(c=head[index];c!=NULL;c=c->next)
		{
			if(c->data==key)
			{
				printf("search element found\n");
				break;
			}
		}
		if(c==NULL)
			printf("\n search element not found\n");
	}
}
void display()
{
	int i;
	for(i=0;i<TABLE_SIZE;i++)
	{
		printf("\n entries at index%d\n",i);
		if(head[i]==NULL)
		{
			printf("no hash entry\n");
			return;
		}
		else
		{
			for(c=head[i];c!=NULL;c=c->next)
			printf("%d->",c->data);
		}
	}
}
int main()
{
	int opt,key,i;
	while(1)
	{
		printf("\nenter 1.insert\t2.display\t3.search\t4.exit\n");
		scanf("%d",&opt);
		switch(opt)
		{
			case 1:insert();
				   break;
			case 2:display();
				   break;
			case 3:search();
				   break;
			case 4:exit(0);
		}
	}
}
/*OUTPUT:
enter 1.insert  2.display       3.search        4.exit
1

enter a value to insert into hash table
10

enter 1.insert  2.display       3.search        4.exit
1

enter a value to insert into hash table
20

enter 1.insert  2.display       3.search        4.exit
1

enter a value to insert into hash table
30

enter 1.insert  2.display       3.search        4.exit
2

 entries at index0
10->20->30->
 entries at index1
no hash entry

enter 1.insert  2.display       3.search        4.exit
3

enter the element to be searched
15

search element not found

enter 1.insert  2.display       3.search        4.exit
3

enter the element to be searched
10
search element found

enter 1.insert  2.display       3.search        4.exit
4*/			
