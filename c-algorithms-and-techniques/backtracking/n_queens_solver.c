#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int nr = 0;

int valid(int i, int* v)
{
	int ok = 1;
	for (int j=0;j<i;j++)
	{
		if (v[j] == v[i] || abs(i - j) == abs(v[i] - v[j]))
			ok = 0;
	}
	return ok;
}

void back(int i, int* v, int n)
{
	int j, k;
	if (i == n)
	{
		nr++;
		for (int linie = 0; linie < n; linie++)
		{
			for (int coloana = 0; coloana < n; coloana++)
			{
				if (v[linie] == coloana) printf("R ");
				else printf("x ");
			}
			printf("\n");
		}
		printf("\n");
	}
	else
	{
		for (j = 0; j < n; j++)
		{
			v[i] = j;
			if (valid(i, v))
			{
				back(i + 1, v, n);
			}
		}
	}
}

int main()
{
	int n, v[10];
	printf("Introduceti numarul de regine: ");
	scanf("%d", &n);

	printf("Solutiile genereate sunt: \n\n");
	back(0, v, n);
	
	printf("Numarul solutiile genereate este: %d\n", nr);

	return 0;
}
