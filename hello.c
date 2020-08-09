#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
int main()
{

	#pragma omp parallel
	   printf("hello world %d total %d\n",omp_get_thread_num(),omp_get_num_threads());
}