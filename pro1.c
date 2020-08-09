#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
int main()
{
	int a[80] ={1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
	            1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
	int b[80] ={2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
	 			2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2};
	int sum=0;
	int sum2=0;
	int sum3=0;
	float start,end;
	int i;
	//start = omp_get_wtime();
	//printf("%f\n",start);
	#pragma omp parallel 
	{
		#pragma omp for schedule(static,10)
			for(i=0;i<80;i++)
			{
				printf("start is thread %d of %d and index %d\n",omp_get_thread_num(),omp_get_num_threads(),i);

				sum += (a[i]*b[i]);
			}
	}
	printf("%d\n",sum);
	printf("dynamic\n");
	#pragma omp parallel 
	{
		#pragma omp for schedule(dynamic,4)
			
			for(i=0;i<80;i++)
			{
				printf("start is thread %d of %d and index %d\n",omp_get_thread_num(),omp_get_num_threads(),i);
				sum2 += (a[i]*b[i]);
			}
	}
	printf("%d\n",sum2);
	printf("guided \n");
	#pragma omp parallel 
	{
		#pragma omp for schedule(guided,4)
			
			for(i=0;i<80;i++)
			{
				printf("start is thread %d of %d and index %d\n",omp_get_thread_num(),omp_get_num_threads(),i);
				sum3 += (a[i]*b[i]);
			}
			// end = omp_get_wtime();
		 //printf("end time %f\n",end);
	}
	printf("%d\n",sum3);
}