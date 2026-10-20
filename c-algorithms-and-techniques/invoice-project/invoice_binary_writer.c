#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct
{
	int zi;
	int luna;
	int an;
}DATA;

typedef struct
{
	int nrFactura;
	char numeClient[30];
	int nrProd;
	float valProd[50];
	char is;
	DATA data;
}FACTURA;

int nrArticole(FILE* f)
{
	long poz = ftell(f);
	fseek(f, 0, 2);
	int n = ftell(f) / sizeof(FACTURA);
	fseek(f, poz, 0);
	return n;
}

int main()
{
	FILE* f;
	FACTURA x;
	f = fopen("factura.dat", "wb+");
	printf("Introduceti numarul facturii sau CTRL/Z: ");
	scanf("%d", &x.nrFactura);
	while (!feof(stdin))
	{
		int nr = nrArticole(f);
		if (nr < x.nrFactura)
		{
			x.is = 0;
			fseek(f, 0, 2);
			for (int i = nr; i <= x.nrFactura; i++)
			{
				fwrite(&x, sizeof(FACTURA), 1, f);
			}
		}
		fseek(f, x.nrFactura * sizeof(FACTURA), 0);
		fread(&x, sizeof(FACTURA), 1, f);
		if (x.is == 1) printf("Factura deja completata!");
		else
		{
			x.is = 1;
			printf("Nume client: ");
			scanf("%s", x.numeClient);
			printf("Data facturii:\n");
			printf("Ziua: ");
			scanf("%d", &x.data.zi);
			printf("Luna: ");
			scanf("%d", &x.data.luna);
			printf("Anul: ");
			scanf("%d", &x.data.an);
			printf("Numar de produse: ");
			scanf("%d", &x.nrProd);
			printf("Valoare produse: ");
			for (int i = 0; i < x.nrProd; i++)
			{
				printf("Produsul %d:", i+1);
				scanf("%f", &x.valProd[i]);
			}
			fseek(f, x.nrFactura * sizeof(FACTURA), 0);
			fwrite(&x, sizeof(FACTURA), 1, f);
		}
		printf("Introduceti numarul facturii sau CTRL/Z: ");
		scanf("%d", &x.nrFactura);
	}
	fclose(f);
	return 0;
}
