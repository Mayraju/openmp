#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
int main()
{
	int sum=0,i;
    #pragma omp parallel
     {
     	printf(" thread entering is %d\n",omp_get_thread_num());
     	for(i=0;i<100;i++)
     	{
     		printf("seeing which thread %d of %d and index %d\n excueting\n",omp_get_thread_num(),omp_get_num_threads(),i);
     		sum = sum+i;
     	}
     	printf(" value %d %d \n",sum,omp_get_thread_num());
     }
     printf("%d",sum);
}