/********************************************
Implement the Merge Sort algorithm
**********************************************/
#include<stdio.h>
#include<stdlib.h>
void main()
{ int a[10],b[10],c[10],i,j,k,p,m,n;
   printf("\nEnter the size of a\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
      printf("enter %d element: ",i+1);
	  scanf("%d",&a[i]);
	}
	 printf("\nEnter size of b");
	 scanf("%d",&m);
	 for(j=0;j<m;j++)
	 { 
	 	 printf("enter %d element: ",i+1);
	   scanf("%d",&b[j]);
	 }
	 i=0,j=0,k=0;
	 while(i<n&&j<m)
	  { 
	  	if(a[i]<b[j])
	    { 
			c[k]=a[i];
	       i++;
	        k++;
		 }
		 else
		  { 
		  	c[k]=b[j];
		   	j++;
		    k++;
		  }
	  }
	  if(i<n)
	  { 
	  	for(p=i;p<n;p++)
	    { 
			c[k]=a[p];
	        k++;
		}
	  }
	  if(j<m)
	  { 
		for(p=j;p<m;p++)
	    { 
			c[k]=b[p];
	        k++;
		}
	  }
	  printf("\nElements are: ");
	  for(k=0;k<(m+n);k++)
	  { 
	  	printf("%d\t",c[k]);
	  }
}
/****************************************
output:
Enter the size of a
2
Enter 1 element
6
Enter 2 element
9
Enter size of b
2
Enter 1 element
3
Enter 2 element
10
Elements are 3   6       9       10
*******************************************/

