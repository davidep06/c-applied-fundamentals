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

		printf("Matricea de costuri este: \n");
		for (int i = 0; i < *v; i++)
		{
			for (int j = 0; j < *v; j++)
			{
				printf("%5d ", mat[i][j]);
			}
			printf("\n\n");
		}

		printf("Introduceti varful de plecare: ");
		scanf("%d", n);

		int viz[20], dist[20];
		for (int i = 0; i < *v; i++)
			viz[i] = 0;
		for (int i = 0; i < *v; i++)
			dist[i] = INF;
		dist[*n - 1] = 0;

		for (int i = 0; i < *v; i++)
		{
			int distMin = INF;
			int imin = -1;
			for (int j = 0; j < *v; j++)
			{
				if (viz[j] == 0 && dist[j] < distMin)
				{
					distMin = dist[j];
					imin = j;
				}
			}
			if (imin == -1) break;
			viz[imin] = 1;
			for (int j = 0; j < *v; j++)
			{
				if (mat[imin][j] != INF && viz[j] == 0)
				{
					if(dist[imin] + mat[imin][j] < dist[j])
						dist[j] = dist[imin] + mat[imin][j];
				}
			}
		}
		
		if (dist[*v - 1] == INF)
			printf("Nu exista drum de la %d la ultimul varf\n", *n);
		else
			printf("Drumul de cost minim pana la ultimul varf este: %d\n", dist[*v - 1]);
	}
	fclose(f);
}

int main()
{
	int v, m, mat[20][20], n;
	graf(&v, &m, mat, &n);
	return 0;
}
