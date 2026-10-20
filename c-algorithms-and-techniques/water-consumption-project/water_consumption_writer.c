#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct
{
	char r;
	char c;
}apa;

typedef struct
{
	char is;
	int cod;
	char nume[30];
	char etaj;
	char camere;
	apa consum[12];
}apart;

int nrArticole(FILE* f)
{
	long nr = ftell(f);
	fseek(f, 0, 2);
	int n = ftell(f) / sizeof(apart);
	fseek(f, nr, 0);
	return n;
}

int main()
{
	FILE* f;
	apart x;
	char temp[3];
	f = fopen("apa.dat", "wb+");
	if (f == NULL)
	{
		printf("Nu am putut deschide fisierul binar");
		return;
	}
	else
	{
		printf("Introduceti codul apartamentului: ");
		scanf("%d", &x.cod);
		int n = nrArticole(f);
		if (n < x.cod)
		{
			x.is = 0;
			fseek(f, 0, 2);
			for (int i = n; i <= x.cod; i++)
			{
				fwrite(&x, sizeof(apart), 1, f);
			}
		}
		fseek(f,x.cod*sizeof(apart),0);
		fread(&x, sizeof(apart), 1, f);
		if (x.is == 1) printf("Loc deja ocupat");
		else
		{
			while (!feof(stdin))
			{
				x.is = 1;
				printf("Introduceti numele si prenumele: ");
				gets(temp);
				gets(x.nume);
				printf("Introduceti etajul: ");
				scanf(" %c", &x.etaj);
				printf("Introduceti numarul de camere: ");
				scanf(" %c", &x.camere);
				printf("Introduceti consmul de apa: ");
				for (int i = 0; i < 12; i++)
				{
					printf("Apartamentul %d: \n", i + 1);
					printf("Rece: ");
					scanf("%hhd", &x.consum[i].r);
					printf("Calda: ");
					scanf("%hhd", &x.consum[i].c);
				}

				fseek(f, x.cod * sizeof(apart), 0);
				fwrite(&x, sizeof(apart), 1, f);

				printf("Introduceti codul apartamentului: ");
				scanf("%d", &x.cod);
			}
		}
	}
