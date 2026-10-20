#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct
{
	int zi;
	int luna;
	int an; 
} DATA;

typedef struct
{
	int nrFactura; 
	char numeClient[30];
	int nrProd;
	float valProd[50];
	char is;
	DATA data;
} FACTURA;

int main()
{
	FILE* f_binar;
	FILE* f_text;
	FACTURA x;

	f_binar = fopen("factura.dat", "rb");
	if (f_binar == NULL) {
		printf("Eroare: Nu gasesc factura.dat!\n");
		return 1;
	}

	f_text = fopen("factura.txt", "w");
	if (f_text == NULL) {
		printf("Eroare la crearea fisierului txt!\n");
		fclose(f_binar);
		return 1;
	}

	fprintf(f_text, "------------------------------------------------------------------------------------------\n");
	fprintf(f_text, "| %-20s | %-17s | %-12s | %-25s \n", "Nume client", "Data facturii", "Nr. produse", "Valoare produse");
	fprintf(f_text, "------------------------------------------------------------------------------------------\n");

	int facturi_gasite = 0;
	while (fread(&x, sizeof(FACTURA), 1, f_binar) == 1)
	{
		if (x.is == 1)
		{
			facturi_gasite++;

			fprintf(f_text, "| %-20s |  %02d | %02d | %04d |      %-7d | ",
				x.numeClient, x.data.zi, x.data.luna, x.data.an, x.nrProd);

			for (int i = 0; i < x.nrProd; i++)
			{
				fprintf(f_text, "%.2f", x.valProd[i]);
				if (i < x.nrProd - 1) {
					fprintf(f_text, " | "); 
				}
			}

			fprintf(f_text, "\n");
			fprintf(f_text, "------------------------------------------------------------------------------------------\n");
		}
	}

	fclose(f_binar);
	fclose(f_text);

	if (facturi_gasite > 0)
		printf("Tabelul a fost generat! Deschide 'factura.txt'.\n");
	else
		printf("Nu am gasit nicio factura valida in fisier.\n");

	return 0;
}
