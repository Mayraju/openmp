#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
int main()
{
	printf(" main thread %d\n",omp_get_thread_num());
  #pragma omp parallel
	printf("%d of %d\n",omp_get_thread_num(),omp_get_num_threads());
}