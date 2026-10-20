#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>

void min_max(int *v, int n, int *min, int *max)
{
	int i;
	*min = v[0];
	*max = v[0];
	for (i = 0; i < n; i++)
	{
		if (*min > v[i]) *min = v[i];
		else
			if (*max < v[i]) *max = v[i];
	}
}

int main()
{
	int n, *x;
	printf("Introduceti numarul de elemente: ");
	scanf("%d", &n);
	int i;
	x = (int*)malloc(n * sizeof(int));
	if (x == NULL)
		printf("Nu se poate aloca");
	else
	{
		for (i = 0; i < n; i++)
		{
			printf("x[%d] = ", i + 1);
			scanf("%d", &x[i]);
		}
		int min, max;
		min_max(x, n, &min, &max);
		printf("Elementul minim este: %d \n Cel maxim este: %d", min, max);
		free(x);
		return 0;
	}
}
