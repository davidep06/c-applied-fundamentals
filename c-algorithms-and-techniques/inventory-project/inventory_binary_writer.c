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

void marcare(FILE* f, int p, int nra)
{
	OBIECT x;
	x.is = 0;
	fseek(f, 0, SEEK_END);
	for (int i = p; i < nra; i++) fwrite(&x, sizeof(x), 1, f);
}

int nrArticole(FILE* f)
{
	long pozCur = ftell(f);
	fseek(f, 0, SEEK_END);
	int n = ftell(f) / sizeof(OBIECT);
	fseek(f, pozCur, SEEK_SET);
	return n;
}

int main()
{
	FILE* f;
	OBIECT x;
	int i, n, opt, ac;
	char temp[3];

	printf("Apasa 1 daca vrei sa creezi fisier nou, orice alt numar pentru a citi un fisier deja existent: ");
	scanf("%d", &opt);
	if (opt == 1)
	{
		f = fopen("obiect.dat", "wb+");
		marcare(f, 0, 99);
	}
	else
	{
		f = fopen("obiect.dat", "rb+");
		if (f == NULL)
		{
			printf("Fisierul nu poate fi deschis! Va fi creat unul nou\n");
			f = fopen("obiect.dat", "wb+");
			marcare(f, 0, 99);
		}
	}
	printf("Numar inventar sau CTRL/Z:");
	scanf("%d", &ac);

	while (!feof(stdin))
	{
		n = nrArticole(f);
		if (n < ac) marcare(f, n, ac);
		fseek(f, ac * sizeof(OBIECT), SEEK_SET);
		fread(&x, sizeof(x), 1, f);
		fseek(f, 0, SEEK_CUR);

		if (x.is == 1) printf("Articol existent, suprascrierea nu e permisa!");
		else
		{
			x.nrInv = ac;
			x.is = 1;

			printf("Nume obiect: ");
			gets(temp);
			gets(x.numeObj);
			printf("Tip obiect: ");
			gets(x.tip);
			printf("Data achizitiei: \n");
			printf("Zi: ");
			scanf("%d", &x.data.zi);
			printf("Luna: ");
			gets(temp);
			gets(x.data.luna);
			printf("An: ");
			scanf("%d", &x.data.an);
			printf("Valoare: ");
			scanf("%f", &x.val);
			printf("Nume gestionar: ");
			gets(temp);
			gets(x.numeGestionar);

			fseek(f, ac * sizeof(OBIECT), SEEK_SET);
			fwrite(&x, sizeof(x), 1, f);
			fseek(f, 0, SEEK_CUR);
		}
		printf("Numar inventar sau CRTL/Z: ");
		scanf("%d", &ac);
	}
	fclose(f);
	return 0;
}
