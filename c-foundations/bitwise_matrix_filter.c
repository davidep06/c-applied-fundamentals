#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int verificareBit(char c)
{
	int k = 0, maxZero = 0;
	unsigned char uc = (unsigned char)c;
	for (int i = 1; i <= 8; i++)
	{
		if (((uc >> (i - 1)) & 1) == 0)
		{
			k++;
			if (k > maxZero)
				maxZero = k;
		}
		else
		{
			k = 0;
		}
	}
	if (maxZero >= 4) return 1;
	return 0;
}

void citireMatrice(int m, int n, char a[101][101])
{
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			printf("a[%d][%d] = ", i, j);
			scanf(" %c", &a[i][j]);
		}
	}
	printf("\n");
}

void rezolvare(int m, int n, char a[101][101], int lin[101], int col[101])
{
	int i, j;
	for (i = 1; i <= m; i++) lin[i] = 0;
	for (j = 1; j <= n; j++) col[j] = 0;

	for (i = 1; i <= m; i++)
	{
		for (j = 1; j <= n; j++)
		{
			if (verificareBit(a[i][j]) == 1)
			{
				lin[i] = 1;
				col[j] = 1;
			}
		}
	}
}

void afisare(int m, int n, int lin[101], int col[101])
{
	printf("Liniile care contin produse cu defecte (>= 4 biti de 0 consecutivi): ");
	for (int i = 1; i <= m; i++) {
		if (lin[i] == 1) printf("%d ", i);
	}
	printf("\n");

	printf("Zilele (coloanele) in care s-au gasit produse cu defecte: ");
	for (int j = 1; j <= n; j++) {
		if (col[j] == 1) printf("%d ", j);
	}
	printf("\n");
}

int main()
{
	int m, n; 
	char a[101][101];
	int lin[101], col[101];

	printf("Introduceti numarul de zile (linii m): ");
	scanf("%d", &m);
	printf("Introduceti numarul de produse (coloane n): ");
	scanf("%d", &n);

	citireMatrice(m, n, a);
	rezolvare(m, n, a, lin, col);
	afisare(m, n, lin, col);

	return 0;
}
