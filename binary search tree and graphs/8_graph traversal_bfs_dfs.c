/*8.write a program for implemenmtation of graph traversals by applying 
1)breadth first search
2)depth first search */
#include<stdio.h>
int q[20],top=-1,front=-1,rear=-1,a[20][20],vis[20],stack[20];
int delete();
void add(int item);
void bfs(int s,int n);
void dfs(int s,int n);
void push(int item);
int pop();
void main()
{
	int n,i,s,ch,j;
	char c,dummy;
	printf("enter the number of vertices");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			printf("enter 1 if %d has a node with %d else 0 ",i,j);
			scanf("%d",&a[i][j]);
		}
	}
	printf("the adjacency matrix is:\n");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			printf("%d\t",a[i][j]);
		}
		printf("\n");
	}
	do
	{
		for(i=1;i<=n;i++)
		{
			vis[i]=0;
		}
		printf("\n menu");
		printf("\n1.bfs \n2.dfs \nenter your choice:");
		scanf("%d",&ch);
		printf("enter the source vertex");
		scanf("%d",&s);
		switch(ch)
		{
			case 1:bfs(s,n);
			break;
			case 2:dfs(s,n);
			break;
		}
		printf("\ndo you wanna continue(yes or no)?");
		scanf("%c",&dummy);
		scanf("%c",&c);
	}while((c=='y')||(c=='Y'));
}
void bfs(int s,int n)
{
	int p,i;
	add(s);
	vis[s]=1;
	p=delete();
	if(p!=0)
	printf("%d",p);
	while(p!=0)
	{
		for(i=1;i<=n;i++)
		{
			if((a[p][i])&&(vis[i]==0))
			{
				add(i);
				vis[i]=1;
			}
			p=delete();
			if(p!=0)
			printf("%d",p);
		}
	}
	for(i=1;i<=n;i++)
	if(vis[i]==0)
	bfs(i,n);
}
void add(int item)
{
	if(rear==19)
	printf("q is full!!!!");
	else
	{
		if(rear==-1)
		{
			q[++rear]=item;
			front++;
		}
		else
		{
			q[++rear]=item;
		}
	}
}
int delete()
{
	int k;
	if((front>rear)||(front==-1))
	return 0;
	else
	{
		k=q[front++];
		return k;
	}
}
void dfs(int s,int n)
{
	int k,i;
	push(s);
	vis[s]=1;
	k=pop();
	if(k!=0)
	printf("%d",k);
	while(k!=0)
	{
		for(i=1;i<=n;i++)
		if((a[k][i]!=0)&&(vis[i]==0))
		{
			push(i);
			vis[i]=1;
		}
		k=pop();
		if(k!=0)
		printf("%d",k);
		for(i=1;i<=n;i++)
		if(vis[i]==0)
		dfs(i,n);
	}
}
void push(int item)
{
	if(top==19)
	printf("stack overflow");
	else
	stack[++top]=item;
}
int pop()
{
	int k;
	if(top==-1)
	return 0;
	else
	k=stack[top--];
	return(k);
}
/*output:
enter the number  of vertices2
enter 1 if 1 has a node with 1 else 0 1
enter 1 if 1 has a node with 2 else 0 0
enter 1 if 2 has a node with 1 else 0 2
enter 1 if 2 has a node with 2 else 0 3
the adjacency matrix is:
1	0	
2	3	

 menu
1.bfs 
2.dfs 
enter your choice:1
enter the source vertex3
312
do you wanna continue(yes or no)?y

 menu
1.bfs 
2.dfs 
enter your choice:3
enter the source vertex2

do you wanna continue(yes or no)?no
*/

