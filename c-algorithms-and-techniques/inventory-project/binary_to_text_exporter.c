#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct
{
	int zi;
	char luna[15];
	int an;
}DATA;

typedef struct
{
	int nrInv;
	char numeObj[30];
	char tip[20];
	DATA data;
	float val;
	char numeGestionar[30];
	int is;
}OBIECT;

#define fwriteb(x,f) fwrite(&(x),sizeof(OBIECT),1,(f))
#define freadb(x,f) fread(&(x),sizeof(OBIECT),1,(f))

int main()
{
	FILE* f, * g;
	OBIECT x;
	char s1[20];
	printf("Scrie numele fisierului de citit: ");
	scanf("%s", s1); 
	f = fopen(s1, "rb");
	if (!f) printf("Nu am gasit niciun fisier");
	else
	{
		printf("Fisier text rezultant: <<factura.txt>>\n");
		g = fopen("factura.txt", "w");
		if (g == NULL) {
			printf("Eroare critica! Nu am putut crea fisierul!\n");
			fclose(f);
			return 1;
		}
		fprintf(g, "%-6s %-20s %-15s %-20s %-20s %-20s\n","NrInv", "Denumire", "Tip", "Data", "Valoare", "Gestionar");
		while (freadb(x, f) > 0) {
			if (x.is == 1) {
				fprintf(g, "%-6d %-20s %-15s %02d.%-08s.%10d %-20.2f %-30s\n",
					x.nrInv,
					x.numeObj,
					x.tip,
					x.data.zi, x.data.luna, x.data.an,
					x.val,
					x.numeGestionar);
			}
		}
		printf("Export finalizat cu succes!\n");

		fclose(g);
		fclose(f);
	}
	return 0;
}
