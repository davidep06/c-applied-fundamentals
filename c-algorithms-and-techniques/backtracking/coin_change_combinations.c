#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct
{
	int val;
	int cant;
}bancnote;

bancnote banc[20];
int nr = 0;

int valid(int i, int* v, int n, int s)
{
	int ok = 1;
	int tot = 0;
	for (int j = 0; j <= i; j++)
	{
		tot += banc[j].val * v[j];
	}
	if (tot > s) ok = 0;
	return ok;
}

void afis(int* v, int n)
{
	int sumCur = 0;
	printf("Solutia numarul %d este: \n", nr);
	for (int k = 0; k < n; k++)
	{
		int prod = banc[k].val * v[k];
		sumCur += banc[k].val * v[k];
		printf("%d * %d = %d, suma = %d\n", banc[k].val, v[k], prod, sumCur);
	}
	printf("\n");
}

void back(int i, int* v, int n, int s)
{
	int j;
	if (i == n)
	{
		int totFinal = 0;
		for (int k = 0; k < n; k++) totFinal += banc[k].val * v[k];
		if (totFinal == s)
		{
			nr++;
			afis(v, n);
		}
	}
	else
	{
		for (j = 0; j <= banc[i].cant; j++)
		{
			v[i] = j;
			if (valid(i, v, n, s))
				back(i + 1, v, n, s);
		}
	}
}

int main()
{
	int n, v[10], s;

	printf("Introduceti numarul de bancnote: ");
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		printf("val[%d] = ", i + 1);
		scanf("%d", &banc[i].val);
		printf("cant[%d] = ", i + 1);
		scanf("%d", &banc[i].cant);
	}
	printf("\n");
	printf("Introduceti suma de plata: ");
	scanf("%d", &s);

	back(0, v, n, s);

	printf("Numarul de solutii totale este: %d", nr);
	return 0;
}
