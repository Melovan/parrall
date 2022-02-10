#include <stdio.h>
#include <math.h>
#include <malloc.h>
#define N  10000000
#define M_PI		3.14159265358979323846

int main()
{

	float* sins = (float*)calloc(N, sizeof(float));
	for (size_t i = 0; i < N; ++i)
		sins[i] = sinf((2 * M_PI) / N * i);
	float summ = 0;
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