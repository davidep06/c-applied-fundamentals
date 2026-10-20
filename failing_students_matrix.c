#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void citire(int *m, int *n)
{
	printf("Introdu nr de stud: ");
	scanf("%d", m);
	printf("Introdu nr de discipline: ");
	scanf("%d", n);
}

void citireMat(int m, int n, int a[101][101])
{
	int i, j;
	for (i = 1; i <= m; i++)
	{
		for (j = 1; j <= n; j++)
		{
			printf("a[%d][%d] = ", i, j);
			scanf("%d", &a[i][j]);
		}
	}
}

void rezolvare(int m, int n, int a[101][101])
{
	int i, j, max = -1, v[101], k=1;
	for (j = 1; j <= n; j++)
	{
		int nr = 0, ok=0;
		for (i = 1; i <= m; i++)
		{
			if (a[i][j] < 5) nr++;

		}
		if (nr > max) max = nr;
		v[k] = nr;
		k++;
	}
	printf("Disciplinele cu cei mai multi restantieri sunt: ");
	for (i = 1; i < k; i++)
	{
		if (v[i] == max) printf("%d ", i);
	}
}

int main()
{
	int m, n, a[101][101];
	citire(&m, &n);
	citireMat(m, n, a);
	rezolvare(m, n, a);
}