#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void citire(int* m, int* n, int* p)
{
	printf("Introdu nr de linii pentru mat A: ");
	scanf("%d", m);
	printf("Introdu nr de coloane pentru mat A si linii pentru matricea B: ");
	scanf("%d", n);
	printf("Introdu nr de coloane pentru mat B: ");
	scanf("%d", p);
}

void citireMat(int m, int n, int p, int a[101][101], int b[101][101])
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
	printf("\n");
	printf("A = \n");
	for (i = 1; i <= m; i++)
	{
		for (j = 1; j <= n; j++)
		{
			if (i != 1 && j == 1) printf("    ");
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= p; j++)
		{
			printf("b[%d][%d] = ", i, j);
			scanf("%d", &b[i][j]);
		}
	}
	printf("\n");
	printf("B = \n");
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= p; j++)
		{
			if (i != 1 && j == 1) printf("    ");
			printf("%d ", b[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void rezolvare(int m, int n, int p, int a[101][101], int b[101][101])
{
	int i, j, k, c[101][101] = { 0 };
	for (i = 1; i <= m; i++)
	{
		for (j = 1; j <= p; j++)
		{
			for (k = 1; k <= n; k++)
			{
				c[i][j] += a[i][k] * b[k][j];
			}
		}
	}
	printf("Matricea rezultanta din inmultirea lui A si B este: \n");
	printf("C = \n");
	for (i = 1; i <= m; i++)
	{
		for (j = 1; j <= p; j++)
		{
			if (i != 1 && j == 1) printf("    ");
			printf("%d ", c[i][j]);
		}
		printf("\n");
	}
}

int main()
{
	int m, n, p, a[101][101], b[101][101];
	citire(&m, &n, &p);
	citireMat(m, n, p, a, b);
	rezolvare(m, n, p, a, b);
	return 0;
}