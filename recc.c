#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
/* Main Program */
int main()
{
    double  **InputMatrix, **CheckMatrix;
    int  j, i, N,Noofthreads,total_threads;
    printf("\n\t\t Enter the size of the Matrix\n");
    scanf("%d", &N);
    /* Dynamic Memory Allocation */
    InputMatrix = (double **) malloc(sizeof(double *) * N);
    CheckMatrix = (double **) malloc(sizeof(double *) * N);
    /* Initializing The Matrix Elements */
    for (i = 0; i < N; i++) {
        InputMatrix[i] = (double *) malloc(sizeof(double) * N);
        for (j = 0 ; j < N; j++)
            InputMatrix[i][j] = i + j;
    }
 
    /* CheckMatrix Is Also Same As Input Matrix */
    for (i =0; i < N; i++) {
        CheckMatrix[i] = (double *) malloc(sizeof(double) * N);
        for (j = 0; j < N; j++)
            CheckMatrix[i][j] = InputMatrix[i][j];
    }
    for (j = 1; j < N; j++)
    #pragma omp parallel for
    for (i = 1; i < N; i++)
                {
                       if ( (omp_get_thread_num()) == 0)
                        {
                            total_threads=omp_get_num_threads();
                         }
            InputMatrix[i][j] = InputMatrix[i][j] + InputMatrix[i][j - 1];
              }/* End of the parallel region */
    /* For Validity Of Output */
    /* Serial Calculation */
    for (j = 1; j < N; j++)
        for (i = 1; i < N; i++)
            CheckMatrix[i][j] = CheckMatrix[i][j] + CheckMatrix[i][j - 1];
    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++)
            if (CheckMatrix[i][j] == InputMatrix[i][j]) {
                continue;
            } else {
                exit(1);
            }
  printf("\n The Output Matrix After Loop Nest Containing a Recurrence \n");
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++)
            printf("%lf\t", InputMatrix[i][j]);
        printf("\n");
    }
    /* Freeing Of Allocated Memory */
    free(InputMatrix);

    free(CheckMatrix);
}