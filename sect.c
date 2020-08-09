#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
int main()
{
	int a,b,c,d,e,f,g;
	printf("enter the two values\n");
	scanf("%d %d",&a,&b);
	#pragma omp parallel shared(a,b)
	{
		//printf(" thread excuting   is %d\n",omp_get_thread_num());
		#pragma omp sections
		{
			
			#pragma omp section
			{
				printf(" thread executing first section is %d\n",omp_get_thread_num());
				c = a + b;
				printf(" addition of %d\n",c);

			}
			#pragma omp section
			{
				printf(" thread executing second section is %d\n",omp_get_thread_num());
				d = a - b;
				printf("subtraction of %d\n",d);
				
			}
			#pragma omp section
			{
				printf(" thread executing third section is %d\n",omp_get_thread_num());
				e = a * b;
				printf("multiplication of %d\n",e);
				
			}
			#pragma omp section
			{
				printf(" thread executing fourth section is %d\n",omp_get_thread_num());
				f = a/b;
				printf(" division of %d\n",f);
				
			}
			#pragma omp section
			{
				printf(" thread executing fifth section is %d\n",omp_get_thread_num());
				g = a^b;
				printf("XOR of a to b is %d\n",g);
				
			}
		}
	}
  }
