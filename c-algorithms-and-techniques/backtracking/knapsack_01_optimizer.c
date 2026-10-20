#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct
{
	int kg;
	int val;
}obj;

obj rucsac[50];
int val_max = -1;
int solutie_optima[50];

int valid(int i, int* v, int n, int g)
{
	int ok = 1;
	int total = 0;
	for (int j = 0; j <= i; j++)
	{
		if (v[j] == 1) total += rucsac[j].kg;
	}
	if (total > g) ok = 0;
	return ok;
}

void back(int i, int* v, int n, int g)
{
	int j;
	if (i == n)
	{
		int valCur = 0;
		for (int k = 0; k < n; k++)
		{
			if (v[k] == 1)
				valCur += rucsac[k].val;
		}
		if (valCur > val_max)
		{
			val_max = valCur;
			for (int k = 0; k < n; k++)
				solutie_optima[k] = v[k];
		}
	}
	else
	{
		for (j = 0; j <= 1; j++)
		{
			v[i] = j;
			if (valid(i, v, n, g))
				back(i+1,v,n, g);
		}
	}
}

int main()
{
	int n = 4;        
	int g = 10;      
	int v[50];       

	rucsac[0].kg = 5; rucsac[0].val = 10;
	rucsac[1].kg = 4; rucsac[1].val = 40;
	rucsac[2].kg = 6; rucsac[2].val = 30;
	rucsac[3].kg = 3; rucsac[3].val = 50;

	back(0, v, n, g);

	if (val_max > 0)
	{
		printf("Valoarea maxima este: %d\n", val_max);
		printf("Am ales obiectele de pe pozitiile: ");
		for (int k = 0; k < n; k++)
		{
			if(solutie_optima[k] == 1)
					printf("%d ", k);
		}
		printf("\n");
	}
	else
		printf("Rucsacul este prea mic");
	return 0;
}
