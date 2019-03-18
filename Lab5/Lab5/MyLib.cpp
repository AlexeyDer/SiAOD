#include <stdio.h>
#include <stdlib.h>
#include "MyLib.h"

void FillInc(int a[], int N)
{
	for (int i = 0; i < N; i++)
	{
		a[i] = i;
	}
}

void FillDec(int a[], int N)
{
	int k = N;
	for (int i = 0; i < N; i++)
		a[i] = k--;
}

void FillRand(int a[], int N)
{
	for (int i = 0; i < N; i++)
		a[i] = rand() % 100;
}

int CheckSum(int a[], int N)
{
	int sum = 0;

	for (int i = 0; i < N; i++)
	{
		sum += a[i];

	}
	return sum;
}

int RunNumber(int a[], int N) // Для подсчета серий в массиве
{
	int k = 1;

	for (int i = 0; i < N - 1; i++)
	{
		if (a[i] > a[i + 1])
			k++;
	}
	return k;
}

void PrintMas(int a[], int N)
{
	for (int i = 0; i < N; i++)
		printf("%d ", a[i]);
}