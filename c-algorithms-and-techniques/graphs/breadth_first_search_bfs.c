#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void graf(int* v, int* m, int mat[][20], int* n)
{
	FILE* f = fopen("p02.txt", "r");
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

		printf("Introduceti varful de plecare: ");
		scanf("%d", n);

		int viz[20], coada[20], st = 0, dr = 0;

		for (int i = 0; i < *v; i++)
			viz[i] = 0;

		viz[*n-1] = 1;
		coada[0] = *n - 1;
		while (st <= dr)
		{
			int curent = coada[st];
			st++;
			for (int vecin = 0; vecin < *v; vecin++)
			{
				if (mat[curent][vecin] == 1 && viz[vecin] == 0)
				{
					dr++;
					coada[dr] = vecin;
					viz[vecin] = 1;
				}
			}
		}
		
		int ok = 1;
		for (int i = 0; i < *v; i++)
		{
			if (viz[i] == 0) ok = 0;
		}

		printf("Parcurgerea in latime (BF), plecand de la %d este: ", *n);
		for (int i = 0; i <= dr; i++)
		{
			printf("%d ", coada[i]+1);
		}

		if (ok == 1)
		{
			printf("\nDa, e conex");
		}
		else printf("\nNu, nu e conex");

	}
	fclose(f);
}

int main()
{
	int mat[20][20], v, m, n;
	graf(&v, &m, mat, &n);
	return 0;
}
