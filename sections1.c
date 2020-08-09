#include <stdio.h>
#include <omp.h>
#include <stdlib.h>
int sum(int,int);
int main()
{
     int a=10,b=5,c=10;
	#pragma omp parallel shared(a,b,c) 
	{
		#pragma omp sections
		{
		   #pragma omp section
			{
				int n = sum(5,4);
				printf("sum value is %d and thread is %d\n",n,omp_get_thread_num());
			}
			#pragma omp section
			{
				for(int i=0 ; i< 10;i++)
				{
					if(i % 2 == 0)
					{
                       printf("even value is %d and thread is %d\n",i,omp_get_thread_num());
					}
				}
			}
			#pragma omp section
			{
                  
                  printf("swapping numbers\n");
                  int temp = a;
                  a = b;
                  b = temp;
                  printf("values after swap is %d %d and thread is %d\n",a,b,omp_get_thread_num());
			}
			#pragma omp section
			{
				printf("finding the reverse of a number\n");
				int n = 122;
				int rem,temp=0;
				while(n > 0)
				{
					rem=n%10;
					temp=temp*10 + rem;
					n=n/10;
				}
				printf("reversed value is %d and thread is %d\n",temp,omp_get_thread_num());
			}
		}
	}
}

int sum(int a,int b)
{
	return (a+b);
}