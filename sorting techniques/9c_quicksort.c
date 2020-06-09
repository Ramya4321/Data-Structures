/*aim:Implement the QUICK sort algorithm */
#include<stdio.h>
#include<stdlib.h>
void q_sort(int a[],int lb,int ub);
void main()
{
	int a[20],i,n;
	printf("quick sort\n");
	printf("enter the size of an array :");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("enter the %d element :",i+1);
		scanf("%d",&a[i]);
	}
	q_sort(a,0,n-1);
	printf("elements after sorting:");
	for(i=0;i<n;i++)
	{
		printf("%d\t",a[i]);
	}
	printf("\n");
}  
void q_sort(int a[],int lb,int ub)
{
	int i,j,pivot,t,temp;
	if(lb<ub)
	{
		i=lb;
		j=ub;
		pivot=lb;
		while(i<j)
		{
			while((a[i]<=a[pivot])&&(i<ub))//find element greater than pivot
			{
				i++;
			}
			while(a[j]>a[pivot])//find element lesser than pivot
			{
				j--;
			}
			if(i<j)
			{
				t=a[i];
				a[i]=a[j];
				a[j]=t;
			}
		}
		temp=a[pivot];
		a[pivot]=a[j];
		a[j]=temp;
		//now the element we took is at the correct position 
		//item to the left are smaller
		//item to the right are larger
		q_sort(a,lb,j-1);//to the left sorting
		q_sort(a,j+1,ub);//to the right sorting
	}
}
/*
output:
quick sort
enter the size of an array :6    
enter the 1 element :8
enter the 2 element :2
enter the 3 element :5
enter the 4 element :1
enter the 5 element :0
enter the 6 element :16
elements after sorting:0	1	2	5	8	16	
*/
//https://youtu.be/Hoixgm4-P4M
//vedio in the link youtube
