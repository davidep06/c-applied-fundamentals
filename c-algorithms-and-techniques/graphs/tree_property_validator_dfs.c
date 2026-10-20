#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void df(int plecare, int* v, int mat[][20], int *viz)
{
	viz[plecare] = 1;
	for (int vecin = 0; vecin < *v; vecin++)
	{
		if (mat[plecare][vecin] == 1 && viz[vecin] == 0)
		{
			df(vecin, v, mat, viz);
		}
	}
}

void graf(int* v, int* m, int mat[][20], int* n)
{
	FILE* f = fopen("arbore.txt", "r");
	int x, y;
	int drum[20];
	if (f == NULL)
	{
		printf("Nu am putut deschide fisierul");
		return;
	}
	else
	{
		fscanf(f, "%d", v);
		printf("Numarul de varfuri este: %d\n", *v);
		fscanf(f, "%d", m);
		printf("Numarul de muchii este: %d\n", *m);

		for (int i = 0; i < *v; i++)
		{
			for (int j = 0; j < *v; j++)
			{
				mat[i][j] = 0;
			}
		}

		for (int i = 0; i < *m; i++)
		{
			fscanf(f, "%d", &x);
			fscanf(f, "%d", &y);
			mat[x - 1][y - 1] = 1;
			mat[y - 1][x - 1] = 1;
		}

		printf("\nMatricea de adiacenta este: \n\n");

		for (int i = 0; i < *v; i++)
		{
			for (int j = 0; j < *v; j++)
			{
				printf("%d ", mat[i][j]);
			}
			printf("\n");
		}
		printf("\n");

		if (*m != *v - 1)
		{
			printf("NU e arbore");
			return;
		}

		printf("Introduceti varful de plecare: ");
		scanf("%d", n);

		int plecare = *n - 1;
		int ok = 1;
		int viz[20];

		for (int i = 0; i < *v; i++)
			viz[i] = 0;

		df(plecare, v, mat, viz);

		for (int i = 0; i < *v; i++)
			if (viz[i] == 0) ok = 0;

		if (ok == 1) printf("DA e arbore");
		else printf("NU e arbore");

	}
	fclose(f);
}

int main()
{
	int mat[20][20], v, m, n;
	graf(&v, &m, mat, &n);
	return 0;
}
