#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

const int n = 9;

void FillInc(int a[n])
{
	for (int i = 0; i < n; i++)
	{
		a[i] = i;
	}
}

void FillDec(int a[n])
{
	int k = n;
	for (int i = 0; i < n; i++)
		a[i] = k--;
}

void FillRand(int a[n])
{
	for (int i = 0; i < n; i++)
	{
		a[i] = rand() % 100;
	}
}

int CheckSum(int a[n])
{
	for (int i = 0; i < n; i++)
	{
		a[i] = rand() % 100;
	}
	int sum = 0;

	for (int i = 0; i < n; i++)
	{
		sum += a[i];

	}
	return sum;
}

int RunNumber(int a[n])
{
	int k = 1;

	for (int i = 0; i < n - 1; i++)
	{
		if (a[i] > a[i + 1])
			k++;

	}
	return k;
}

void PrintMas(int a[n]) //f
{
	for (int i = 0; i < n; i++)
		printf("%d ", a[i]);
}

int main()
{
	int a[n];

	FillInc(a); //a
	PrintMas(a);
	printf("\n\n\n");

	FillDec(a); //b
	PrintMas(a);
	printf("\n\n\n");

	srand(time(NULL)); //c
	FillRand(a);
	PrintMas(a);
	printf("\n\n\n");

	int sum = CheckSum(a); // d
	printf("sum : %d\n\n\n", sum);

	PrintMas(a);
	printf("\n\n\n");

	int k = RunNumber(a);

	
	printf("%d", k); //e

	float MedSum =(float) n / k;

	printf("\n\n\nMedium Sum: %0.1f", MedSum);

	_getch();
	return 0;
}