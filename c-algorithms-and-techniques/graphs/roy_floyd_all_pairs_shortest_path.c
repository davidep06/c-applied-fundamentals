#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define INF 9999

void graf(int* v, int* m, int mat[][20])
{
	FILE* f = fopen("ponderat.txt", "r");
	if (f == NULL)
	{
		printf("Nu am gasit fisierul");
		return;
	}
	else
	{
		fscanf(f, "%d", v);
		printf("Numarul de varfuri este %d\n", *v);
		fscanf(f, "%d", m);
		printf("Numarul de muchii este %d\n\n", *m);

		for (int i = 0; i < *v; i++)
		{
			for (int j = 0; j < *v; j++)
			{
				if (i == j) mat[i][j] = 0;
				else mat[i][j] = INF;
			}
		}

		int x, y, pondere;
		for (int i = 0; i < *m; i++)
		{
			fscanf(f, "%d", &x);
			fscanf(f, "%d", &y);
			fscanf(f, "%d", &pondere);
			mat[x - 1][y - 1] = pondere;
			mat[y - 1][x - 1] = pondere;
		}

		printf("Matricea initiala de costuri este: \n");
		for (int i = 0; i < *v; i++)
		{
			for (int j = 0; j < *v; j++)
			{
				printf("%5d ", mat[i][j]);
			}
			printf("\n\n");
		}

		for (int k = 0; k < *v; k++)
		{
			for (int i = 0; i < *v; i++)
			{
				for (int j = 0; j < *v; j++)
				{
					if (mat[i][k] != INF && mat[k][j] != INF)
					{
						if (mat[i][k] + mat[k][j] < mat[i][j])
							mat[i][j] = mat[i][k] + mat[k][j];
					}
				}
			}
		}

		int plecare, sosire;
		printf("Introduceti varful de plecare: ");
		scanf("%d", &plecare);
		printf("Introduceti varful de sosire: ");
		scanf("%d", &sosire);

		if (mat[plecare - 1][sosire - 1] == INF)
			printf("Nu exista drum intre %d si %d\n", plecare, sosire);
		else
			printf("Costul drumului minim este: %d\n", mat[plecare - 1][sosire - 1]);
	}
	fclose(f);
}

int main()
{
	int v, m, mat[20][20];
	graf(&v, &m, mat);
	return 0;
}
