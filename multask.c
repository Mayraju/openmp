#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
int main()
{
	int arr[600];
	int step_size = 100;
	int sum =0;
	for(int i=0;i<600;i++)
	{
		arr[i] = 1;
	}
	#pragma omp parallel shared(sum)
	{
		#pragma omp for
			for(int i=0;i< 600;i+=step_size)
			{
				int j,start = i,end=i+step_size-1;
				printf("computing sum(%d,%d) from %d of %d\n",start,end,omp_get_thread_num(),omp_get_num_threads());
				#pragma omp task
				{
			 		int psum=0;
					printf("task computing sum(%d,%d) from %d of %d \n",start,end,omp_get_thread_num(),omp_get_num_threads());
					for(j=start;j<=end;j++)
					{
						psum +=arr[j];
					}
					#pragma omp critical
					    sum += psum;
				}
			}
		}
			printf("sum is %d",sum);
			
	//printf("sum is %d",sum);

}