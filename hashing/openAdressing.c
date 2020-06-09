/*wap to implement to implement open addressing method*/
#include<stdio.h>
main()
{ int n,value,a[30],hash,i,t;
   printf("enter n value");
   scanf("%d",&n);
   printf("enter elements");
   for(i=0;i<n;i++)
    { scanf("%d",&a[i]);
     }
   do
    { printf("enter hash value");
      scanf("%d",&value);
      hash=value%n;
      if(a[hash]==0)
        { a[hash]=value;
          printf("a[%d]the value%d is stored",hash,value);
        }
       else
         {for(hash++;hash<n;hash++)
           { if(a[hash]==0)
              { printf("space is allocated give other value");
                  a[hash]=value;
                printf("a[%d] the value %d is stored",hash,value);
                 goto menu;
              }
           }
           hash=0;
           for(hash;hash<n;hash++)
            { if(a[hash]==0)
               { printf("space is allocated give other value");
                  a[hash]=value;
                 printf("a[%d] the value %d is stored",hash,value);
                  goto menu;
                }
            }
           printf("error");
        printf("enter 0 and press enter key twice to exit");
       }
       menu:
         printf("do you want more");
         scanf("%d",&t);
     }while(t==1);
}
/*
output:
enter n value6
enter elements0 0 0 0 0 0
enter hash value20
a[2]the value20 is storeddo you want more1
enter hash value14
space is allocated give other valuea[3] the value 14 is storeddo you want more1
enter hash value37
a[1]the value37 is storeddo you want more1
enter hash value19
space is allocated give other valuea[4] the value 19 is storeddo you want more1
enter hash value25
space is allocated give other valuea[5] the value 25 is storeddo you want more1
enter hash value18
a[0]the value18 is storeddo you want more1
enter hash value16
errorenter 0 and press enter key twice to exitdo you want more0
*/