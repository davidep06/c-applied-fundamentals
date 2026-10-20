#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define INF 9999

int nr = 0;
int valMin = INF;
int solutie[20];

int valid(int i, int* v, int n, int mat[][20])
{
	int ok = 1;
	for (int j = 0; j < i; j++)
	{
		if (v[i] == v[j]) ok = 0;
	}
	if (i > 0 && mat[v[i - 1]][v[i]] == 0) ok = 0;
	return ok;
}

void afis(int n)
{
	FILE* f = fopen("voiajor.txt", "a");
	if (f == NULL) return;

	if (valMin == INF)
	{
		fprintf(f, "Nu exista un traseu\n");
		return;
	}
	fprintf(f, "Costul optim este: %d\n\n", valMin);
	fprintf(f, "Traseul optim este: \n");
	for (int k = 0; k < n; k++)
		fprintf(f, "%d ", solutie[k] + 1);
	fprintf(f, "%d", solutie[0] + 1);
	fprintf(f, "\n");
	fclose(f);
}

void back(int i, int* v, int n, int mat[][20])
{
	int j;
	if (i == n)
	{
		if (mat[v[n - 1]][v[0]] != 0)
		{
			int valCur = 0;
			for (int j = 0; j < n - 1; j++)
				valCur += mat[v[j]][v[j + 1]];
			valCur += mat[v[n - 1]][v[0]];
			if (valCur < valMin)
			{
				valMin = valCur;
				for (int k = 0; k < n; k++)
				{
					solutie[k] = v[k];
				}
			}
		}
	}
	else
	{
		for (j = 0; j < n; j++)
		{
			v[i] = j;
			if (valid(i, v, n, mat))
				back(i + 1, v, n, mat);
		}
	}
}

int main()
{
	int v[20], n, mat[20][20];
	FILE* f = fopen("voiajor.txt", "w");
	if (!f)
	{
		printf("Nu am putut deschide fisierul");
		fclose(f);
		return 0;
	}

	else
	{
		printf("Introduceti numarul locatii: \n");
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				printf("mat[%d][%d] = ", i + 1, j + 1);
				scanf("%d", &mat[i][j]);
			}
			printf("\n");
		}
		back(0, v, n, mat);
		afis(n);
		printf("Fisierul a fost creat");
		return 0;
	}
}
