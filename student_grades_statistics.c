#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void citire(int* m, int* n)
{
	printf("Introdu nr de stundenti: ");
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
	int i, j, v[101], w[101], k = 1, l = 1, p[101] = {0};
	for (i = 1; i <= m; i++)
	{
		int ok = 1;
		float med, sum = 0;
		for (j = 1; j <= n; j++)
		{
			if (a[i][j] < 5) ok = 0;
			sum = sum + a[i][j];
		}
		med = sum / n;
		if (ok == 1)
		{
			v[k] = i;
			p[i] = 1;
			k++;
		}
		if (ok == 1 && med >= 8.5)
		{
			w[l] = i;
			l++;
		}
	}
	printf("Stud integralisti sunt: ");
	for (i = 1; i < k; i++)
	{
		printf("%d", v[i]);
		if (i != k - 1) printf(", ");
	}
	printf("\n");
	printf("Stud bursieri sunt: ");
	for (i = 1; i < l; i++)
	{
		printf("%d", w[i]);
		if (i != l - 1) printf(", ");
	}
	printf("\n");


	int max = -1, x[101], nrInt=k-1;
	float medMaterii, y[101];
	for (j = 1; j <= n; j++)
	{
		float sumMaterii = 0;
		int nr = 0;
		for (i = 1; i <= m; i++)
		{
			if (a[i][j] < 5) nr++;
			if (p[i] == 1) sumMaterii += a[i][j];
		}
		medMaterii = sumMaterii / nrInt;
		y[j] = medMaterii;
		if (nr > max) max = nr;
		x[j] = nr;
	}
	printf("Disciplinele cu cei mai multi restantieri sunt: ");
	for (i = 1; i <= n; i++)
	{
		if (x[i] == max) printf("%d", i);
		if (i < n) printf(", ");
	}
	printf("\n");
	printf("Media disciplinelor este: ");
	for (i = 1; i <= n; i++)
	{
		printf("%.2f", y[i]);
		if (i < n) printf(", ");
	}
}

int main()
{
	int m, n, a[101][101];
	citire(&m, &n);
	citireMat(m, n, a);
	rezolvare(m, n, a);
	return 0;
}