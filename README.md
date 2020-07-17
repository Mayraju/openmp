# openmp


openmp(open multi-processing) is a popular shared memory programming model.
Supported by popular production C (also Fortran) compilers: Clang, GNU Gcc, IBM
xlc, Intel icc

A directive based parallel programming model- OpenMp program is essentially a sequential program.
augmented with compiler directives to specify parallelism - Eases conversion of existing sequential programs.

Main concepts:
– Parallel regions: where parallel execution occurs via multiple concurrently executing threads.

– Each thread has its own program counter and executes one instruction at a time, similar to sequential program execution.

– Shared and private data: shared variables are the means of communicating data between threads.

– Synchronization: Fundamental means of coordinating execution of concurrent threads.

– Mechanism for automated work distribution across threads

OpenMP Core Syntax:

• Most of the constructs in OpenMP are compiler directives:

–                                                               #pragma omp construct [clause [clause]...]

Example
– #pragma omp parallel num_threads(4)

. Function prototypes and types in the file: #include <omp.h>

• Most OpenMP constructs apply to a “structured block”

• Structured block: a block of one or more statements surrounded by "{ } " , with one point of entry at the top and one point of exit at the bottom.


How to complie the openmp programing:

in ubnutu :    compilation : -->   gcc filename.c  -fopenmp
               run         : -->     ./a.out
               
       

openmp scheduling

https://docs.microsoft.com/en-us/cpp/parallel/openmp/d-using-the-schedule-clause?view=vs-2019

openmp simple document:

http://jakascorner.com/blog/2016/06/omp-for-scheduling.html

openmp dought 

https://stackoverflow.com/questions/42970700/openmp-dynamic-vs-guided-scheduling/43047074

reading article

https://www.openmp.org/spec-html/5.0/openmpsu37.html
https://michaellindon.github.io/lindonslog/programming/openmp/openmp-tutorial-firstprivate-and-lastprivate/


distributed computing
cloud computing
tightly coupled system

