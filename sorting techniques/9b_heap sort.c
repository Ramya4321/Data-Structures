/*aim:Implement the HEAP sort algorithm*/
#include<stdio.h>
#include<stdlib.h>
void heap (int a[],int);
int a[20];
void main()
{
	int i,temp,n;
	fflush(stdin);
	printf("heap sort\n");
	printf("enter the no of elements\n");
	scanf("%d",&n);
	printf("enter the elements\n");
	for (i=0;i<n;i++)
	{
		fflush(stdin);
		scanf("%d",&a[i]);
	}
	heap(a,n);
	for (i=n-1;i>=0;i--)
	{
		temp=a[i];
		a[i]=a[0];
		a[0]=temp;
		heap(a,i-1);
	}
	printf("resulting array:\n");
	for (i=0;i<n;i++)
	{
		printf("%d\t",a[i]);
	}
	printf("\n");
}

void heap(int a[],int n)
{
	int i,temp;
	for (i=n/2;i>=0;i--)
	{
		if( ((a[(2*i)+1])<(a[(2*i)+2]))&&(((2*i)+1)<=n)&&(((2*i)+2)<=n) )
		{
			temp=a[(2*i)+1];
			a[(2*i)+1]=a[(2*i)+2];
			a[(2*i)+2]=temp;
		}
		if( (a[(2*i)+1]>a[i])&&((2*i)+1<=n)&&(i<=n) )
		{
			temp=a[(2*i)+1];
			a[(2*i)+1]=a[i];
			a[i]=temp;
		}
	}
}

/*
Output:
heap sort
enter the no of elements
8
enter the elements
3
1
8
9
2
4
7
11
resulting array:
1	2	3	4	7	8	9	11	
*/
