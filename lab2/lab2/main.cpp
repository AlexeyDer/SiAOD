#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include "MyLib.h"
using namespace std;

#define N 9

void comparison(int M, int C, int M_2) // сравнение 
{
	cout << "Practice M = " << M << "\nPractice C = " << C << endl;

	M = 3 * (N - 1);
	C = (N*N - 1) / 2;

	cout << "\nTheory M = " << M << "\nTheory C = " << C << endl;
	cout << "\n" << "M with fixed swap: " << M_2;
}

int a[N];

void SelectSort(int a[], int n)
{
	int key;
	int M = 0, C = 0, M_2 = 0;

	for (int i = 0; i < n - 1; i++)
	{
		key = i;
		for (int j = i + 1; j < n; j++)
		{
			++C;
			if (a[j] < a[key])
			{
				key = j;
				
			}
		}
		if (a[i] != a[key]) // фиктивная перестановка
		{
			int t = a[i];
			a[i] = a[key];
			a[key] = t;
			++M;
		}
		++M_2;

	}
	comparison(M, C, M_2);
}

int main()
{
	size_t c;

		while (1)
		{
			cout << "Write a number:\n1.Inc Arr\n2.Dec Arr.\n3.Rand Arr\n4.Exit" << endl;
			cin >> c;
			switch (c)
			{
			case 1:
				system("cls");
				FillInc(a, N);
				SelectSort(a, N);
				cout << "\nSum: " << CheckSum(a, N) << endl;
				cout << "RunNumber: " << RunNumber(a, N) << endl;
				_getch();
				break;
			case 2:
				system("cls");
				FillDec(a, N);
				SelectSort(a, N);
				cout << "\nSum: " << CheckSum(a, N) << endl;
				cout << "RunNumber: " << RunNumber(a, N) << endl;
				_getch();
				break;
			case 3:
				system("cls");
				FillRand(a, N);
				SelectSort(a, N);
				cout << "\nSum: " << CheckSum(a, N) << endl;
				cout << "RunNumber: " << RunNumber(a, N) << endl;
				_getch();
				break;
			case 4: return 0;
			}
			system("cls");
		}
}