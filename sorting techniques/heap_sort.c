/*aim:Implement the HEAP sort algorithm*///min heap
#include<stdio.h>
#include<stdlib.h>
void heap (int a[],int);
void main()
{
	int i,temp,n;
	//fflush(stdin);
	int a[20];
	printf("heap sort\n");
	printf("enter the no of elements\n");
	scanf("%d",&n);
	printf("enter the elements\n");
	for (i=0;i<n;i++)
	{
	//	fflush(stdin);
		scanf("%d",&a[i]);
	}
	heap(a,n);
	for (i=n-1;i>=0;i--)
	{
		temp=a[i];
		a[i]=a[0];
		a[0]=temp;
		heap(a,i-1);//last element is bigger sorted
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
		if( ((a[(2*i)+1])<(a[(2*i)+2]))&&(((2*i)+1)<n)&&(((2*i)+2)<n))
		//comparing two childrens of a[i]
		{
			temp=a[(2*i)+1];
			a[(2*i)+1]=a[i];
			a[i]=temp;
		}
		if( ((a[(2*i)+1])>(a[(2*i)+2]))&&(((2*i)+1)<n)&&(((2*i)+2)<n) )
		{
			temp=a[(2*i)+2];
			a[(2*i)+2]=a[i];
			a[i]=temp;
		}
	}
}

/*
Output:
heap sort
enter the no of elements
10
enter the elements
5 9 2 1 22 63 8 50 25 3
resulting array:
1       2       3       5       8       9       22      25      50      63

*/
