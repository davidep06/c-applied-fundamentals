#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int nr = 0;
FILE* f;

int valid(int i, int* v, int n, int mat[][10])
{
	int ok = 1;
	for (int j = 0; j < i; j++)
	{
		if (v[j] == v[i]) ok = 0;
	}
	if (i > 0) if (mat[v[i - 1]-1][v[i]-1] == 1) ok = 0;
	if (i == n - 1) if (mat[v[n - 1] - 1][v[0] - 1] == 1) ok = 0;

	return ok;
}

void afis(int* v, int n, FILE* f)
{
	int j;
	fprintf(f, "Solutia %d: ", nr);
	for (j = 0; j < n; j++)
	{
		fprintf(f, "%d ", v[j]);
	}
	fprintf(f, "\n");
}

void back(int i, int* v, int n, int mat[][10])
{
	int j;
	if (i == n)
	{
		nr++;
		afis(v, n, f);
	}
	else
	{
		for (j = 1; j <= n; j++)
		{
			v[i] = j;
			if (valid(i, v, n, mat))
				back(i + 1, v, n, mat);
		}
	}
}

int main()
{
	int n, v[10], mat[10][10];
	printf("Introduceti numarul de cavaleri: ");
	scanf("%d", &n);
	printf("Introduceti matricea adiacenta (0/1): \n");
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("mat[%d][%d] = ", i, j);
			scanf("%d", &mat[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	f = fopen("CAVALERI.txt", "w");
	if (f == NULL)
	{
		printf("Fisierul nu s-a putut deschide");
		return 0;
	}
	else
	{
		printf("\nFisierul a fost creat\n");
		fprintf(f, "Solutiile sunt: \n\n");
		v[0] = 1;
		back(1, v, n, mat);
		fprintf(f, "Numarul de solutii este: %d", nr);
	}
	fclose(f);
	return 0;
}
