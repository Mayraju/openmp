#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
int main()
{
	int num,tid; //Write a OpenMP program to illustrate Data Race condition

	printf("%d\n",omp_get_thread_num());
	#pragma omp parallel //private(tid)
	{
		 printf(" thread entering the shared %d\n", omp_get_thread_num());
		int j;
	    num = omp_get_num_threads();
	    tid = omp_get_thread_num();
		//for(j=0;j<1000000;j++);
		
		 printf(" thread entering the shared after wait  %d\n", omp_get_thread_num());	
		 #pragma omp barrier
	    printf(" thread is %d out of %d\n",tid,num);
	}
		
}