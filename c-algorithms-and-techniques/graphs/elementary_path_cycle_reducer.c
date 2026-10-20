#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define INF 9999

void graf(int* v, int* m, int mat[][20], int* n)
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
				mat[i][j] = INF;
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

		printf("Matricea de adiacenta este: \n");
		for (int i = 0; i < *v; i++)
		{
			for (int j = 0; j < *v; j++)
			{
				printf("%5d ", mat[i][j]);
			}
			printf("\n\n");
		}
	}

	int drum[20], cost = 0, k = 0, viz[20];
	printf("Introduceti numarul de varfuri din drum: ");
	scanf("%d", n);
	printf("Introduceti varfurile cautate: \n");
	for (int i = 0; i < *n; i++)
	{
		printf("Varful %d = ", i + 1);
		scanf("%d", &drum[i]);
	}

	for (int i = 0; i < *n; i++)
	{
		for (int j = 0; j < k; j++)
		{
			if (drum[i] == viz[j])
			{
				k = j;
				break;
			}
		}
		viz[k] = drum[i];
		k++;
	}
	
	for (int i = 0; i < k - 1; i++)
	{
		cost += mat[viz[i] - 1][viz[i + 1] - 1];
	}

	printf("Drumul elementar este: \n");
	for (int i = 0; i < k; i++)
	{
		printf("%d ", viz[i]);
	}
	printf("\nCostul drumului este: %d\n", cost);

	fclose(f);
}

int main()
{
	int v, m, mat[20][20], n;
	graf(&v, &m, mat, &n);
	return 0;
}
