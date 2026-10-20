#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

typedef struct {
	char cheie[15];
	char nume[30];
	int varsta;
	int tratament;
	int sters;
} pacient;

typedef struct {
	char cheie[15];
	int poz; 
} index_art;

void creare() {
	FILE* fd = fopen("pacient.dat", "ab+");
	FILE* fi = fopen("index.dat", "ab+");
	char temp[10];
	pacient p;
	p.sters = 0;

	gets(temp);

	printf("Cheie: ");
	gets(p.cheie);

	printf("Nume: ");
	gets(p.nume);

	printf("Varsta: ");
	scanf("%d", &p.varsta);

	printf("Tratament (1-5): ");
	scanf("%d", &p.tratament);

	fseek(fd, 0, 2);
	int pozitie = ftell(fd) / sizeof(pacient);

	fwrite(&p, sizeof(pacient), 1, fd);
	fclose(fd);

	index_art idx;
	strcpy(idx.cheie, p.cheie);
	idx.poz = pozitie;
	fwrite(&idx, sizeof(index_art), 1, fi);
	fclose(fi);

	fi = fopen("index.dat", "rb+");
	fseek(fi, 0, 2);
	int n = ftell(fi) / sizeof(index_art);

	index_art xi, xj;
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			fseek(fi, i * sizeof(index_art), 0);
			fread(&xi, sizeof(index_art), 1, fi);

			fseek(fi, j * sizeof(index_art), 0);
			fread(&xj, sizeof(index_art), 1, fi);

			if (strcmp(xi.cheie, xj.cheie) > 0) {
				fseek(fi, i * sizeof(index_art), 0);
				fwrite(&xj, sizeof(index_art), 1, fi);

				fseek(fi, j * sizeof(index_art), 0);
				fwrite(&xi, sizeof(index_art), 1, fi);
			}
		}
	}
	fclose(fi);
	printf("Pacient adaugat!\n");
}

void modif_stergere() {
	char cheieCautata[15];
	char temp[10];

	gets(temp);

	printf("Cheie cautata: ");
	gets(cheieCautata);

	FILE* fi = fopen("index.dat", "rb");
	if (fi == NULL) return;

	index_art idx;
	int pozGasita = -1;

	fseek(fi, 0, SEEK_END);
	int numar_inregistrari = ftell(fi) / sizeof(index_art);

	int stanga = 0;
	int dreapta = numar_inregistrari - 1;

	while (stanga <= dreapta) {
		int mijloc = stanga + (dreapta - stanga) / 2;

		fseek(fi, mijloc * sizeof(index_art), SEEK_SET);
		fread(&idx, sizeof(index_art), 1, fi);

		int comparatie = strcmp(idx.cheie, cheieCautata);

		if (comparatie == 0) {
			pozGasita = idx.poz; 
			break;
		}
		else if (comparatie < 0) {
			stanga = mijloc + 1;
		}
		else {
			dreapta = mijloc - 1; 
		}
	}
	fclose(fi);

	if (pozGasita == -1) {
		printf("Cheia nu a fost gasita!\n");
		return;
	}

	FILE* fd = fopen("pacient.dat", "rb+");
	pacient p;
	fseek(fd, pozGasita * sizeof(pacient), 0);
	fread(&p, sizeof(pacient), 1, fd);

	if (p.sters == 1) {
		printf("Pacientul este deja sters!\n");
		fclose(fd);
		return;
	}

	int opt;
	printf("1. Modificare, 2. Stergere: ");
	scanf("%d", &opt);

	gets(temp);

	if (opt == 1) {
		printf("Nume nou: ");
		gets(p.nume);

		printf("Varsta noua: ");
		scanf("%d", &p.varsta);

		fseek(fd, pozGasita * sizeof(pacient), 0);
		fwrite(&p, sizeof(pacient), 1, fd);
		printf("Modificat!\n");
	}
	else if (opt == 2) {
		p.sters = 1;
		fseek(fd, pozGasita * sizeof(pacient), 0);
		fwrite(&p, sizeof(pacient), 1, fd);
		printf("Sters logic!\n");
	}
	fclose(fd);
}

void afisTxt() {
	FILE* f, * g;
	pacient x;

	f = fopen("pacient.dat", "rb");
	if (f == NULL) {
		printf("Fisierul binar nu a putut fi deschis!\n");
		return;
	}

	g = fopen("pacient.txt", "w");
	if (g == NULL) {
		printf("Fisierul text nu a putut fi creat!\n");
		fclose(f);
		return;
	}

	fprintf(g, "%-15s %-30s %-10s %-15s\n", "Cheie", "Nume si prenume", "Varsta", "Tratament");

	while (fread(&x, sizeof(pacient), 1, f)) {
		if (x.sters == 0) {
			fprintf(g, "%-15s %-30s %-10d %-15d\n", x.cheie, x.nume, x.varsta, x.tratament);
		}
	}

	fclose(g);
	fclose(f);
	printf("Fisierul pacient.txt a fost actualizat!\n");
}

int main() {
	int opt = -1;

	while (opt != 0) {
		printf("1. Creare\n2. Modificare / Stergere\n3. Salvare in fisier text\n0. Iesire\nOptiune: ");
		scanf("%d", &opt);

		if (opt == 1) creare();
		if (opt == 2) modif_stergere();
		if (opt == 3) afisTxt();
	}

	return 0;
}
