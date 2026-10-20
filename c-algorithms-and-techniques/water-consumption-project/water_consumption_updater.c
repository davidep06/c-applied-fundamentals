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

void afisTxt(const char* fisBin, const char* fisTxt)
{
	FILE* f, * g;
	apart x;
	g == NULL;
	f = fopen(fisBin, "rb");
	if (f == NULL)
	{
		printf("Nu am putut deschide fisierul binar");
		return;
	}
	g = fopen(fisTxt,"w");
	if (g == NULL)
	{
		printf("Nu am putut crea fisierul text");
		fclose(f);
		return;
	}
	fprintf(g, "Cod  Nume                Etaj  Camere  Consum (R/C): 1   2   3   4   5   6   7   8   9   10  11  12\n");
	fread(&x, sizeof(apart), 1, f);
	while (!feof(f))
	{
		if (x.is == 1)
		{
			fprintf(g, "%-4d %-20s %-5c %-7c %-13s", x.cod, x.nume, x.etaj, x.camere, " ");
			for (int i = 0; i < 12; i++)
			{
				fprintf(g, "%d/%d " , x.consum[i].r, x.consum[i].c);
			}
			fprintf(g, "\n");
		}
		fread(&x, sizeof(apart), 1, f);
	}
	fclose(g);
	fclose(f);
	printf("Fisierul a fost creat cu succes");
}

int main()
{
	FILE* f;
	apart x;
	char temp[3];
	f = fopen("apa.dat", "rb+");
	if (f == NULL)
	{
		printf("Nu am putut deschide fisierul binar");
		return;
	}
	else
	{
		printf("Introduceti codul apartamentului: ");
		scanf("%d", &x.cod);
		int etaj;
		fseek(f, x.cod * sizeof(apart), 0);
		fread(&x, sizeof(apart), 1, f);
		while (!feof(stdin))
		{
			if (x.is == 1)
			{
				printf("Introduceti noul numar de etaj: ");
				scanf("%d", &etaj);
				x.etaj = etaj;
				printf("Etajul a fost schimbat \n");
			}

			fread(&x, sizeof(apart), 1, f);
			fseek(f, x.cod * sizeof(apart), 0);
		}

		afisTxt("apa.dat", "apa.txt");
		return 0;
	}
}
