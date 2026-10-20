#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct
{
	int cost;
	int autonomie;
	int viz;
}avion;

float autoMax = -1.0;
int sol[3];
avion tip[3];

void verificare(int n, int* x)
{
	int total = x[0] + x[1] + x[2];
	if (total == 0) return;
	float vizMedie = (float)(tip[0].viz * x[0] + tip[1].viz * x[1] + tip[2].viz * x[2]) / total;
	if (vizMedie > 2000)
	{
		float autoMedie = (float)(tip[0].autonomie * x[0] + tip[1].autonomie * x[1] + tip[2].autonomie * x[2]) / total;
		if (autoMedie > autoMax)
		{
			autoMax = autoMedie;
			sol[0] = x[0];
			sol[1] = x[1];
			sol[2] = x[2];
		}
	}
}

void back(int i, int* x, int n, int buget)
{
	int j;
	if (i == n) verificare(n, x);
	else
	{
		int limita = buget / tip[i].cost;
		for (j = 0; j <= limita; j++)
		{
			x[i] = j;
			back(i + 1, x, n, buget - (j *tip[i].cost));
			
		}
	}
}

int main()
{
	int x[3];
	tip[0].cost = 100; tip[0].autonomie = 6000; tip[0].viz = 1500;
	tip[1].cost = 60;  tip[1].autonomie = 4200; tip[1].viz = 2400;
	tip[2].cost = 50;  tip[2].autonomie = 5800; tip[2].viz = 1600;

	back(0, x, 3, 5000);
	if (autoMax > 0) {
		printf("SOLUTIE OPTIMA GASITA\n");
		printf("Numar avioane Tip I: %d\n", sol[0]);
		printf("Numar avioane Tip II: %d\n", sol[1]);
		printf("Numar avioane Tip III: %d\n", sol[2]);
		printf("Autonomie medie maxima: %.2f km\n", autoMax);
	}
	else {
		printf("Nu s-a gasit nicio configuratie.\n");
	}

	return 0;
}
