#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
int main()
{
	int i,j;     //Illustrate a program for loop recurrence using OpenMP 
	//PARALLEL FOR directive
	int a[25]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25};
	int sum=0;
	printf("%d",omp_get_thread_num());
	printf("%d",sum);
	#pragma omp parallel
	 {
	 	#pragma omp for
	 	   for(i=0;i<25;i++)
	 	   {
	 	   		printf("start is thread %d of %d and index %d\n",omp_get_thread_num(),omp_get_num_threads(),i);
	 	   		sum += a[i];
	 	   		printf(" sum of %d sum is\n",sum);
	 	   }
	    }
	    printf(" sum is %d %d\n",sum,omp_get_thread_num());
 
}