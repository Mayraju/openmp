#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,i,k;
    int temp=0;
    scanf("%d",&n);
    #pragma omp parallel for
        for(i=2;i<=n;i++)
         {
            int count = 0;
            //printf("hello");
            for(k=1;k<=i;k++)
            {
                if(i%k == 0)
                {
                    count++;
                }
            }
            if(count == 2)
            {
                printf("%d  ",i);
                temp++;
            }
        }
         printf(" total %d",temp);
         return 0;

    }

