#include <stdio.h>
#include <math.h>
#include <malloc.h>
#define N  10000000
#define M_PI		3.14159265358979323846

int main()
{
	
	double* sins = (double*)calloc(N,sizeof(double)) ;
	for (size_t i = 0; i < N; ++i)
		sins[i] = sin((2 * M_PI) / N * i);
	double summ = 0;
#pragma data copyin(sins) copyout(summ)
	{
#pragma acc kernels
		{
			
			for (size_t i = 0; i < N; ++i)
				summ = summ + sins[i];
		
		}
	}
	printf("%e", summ);
	return 0;
}
