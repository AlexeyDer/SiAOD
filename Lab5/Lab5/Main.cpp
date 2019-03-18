#include "MyLib.h"
#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#define n 10

using namespace std;

int M = 0, C = 0;
int M_Theory = 0, C_Theory = 0;

void ShakerSort(int *mas, int N){
	int L = 0, R = N - 1, key = N;

	while (L < R){
		for (int i = R; i > L; i--){
			if (mas[i] < mas[i - 1]){
				swap(mas[i], mas[i - 1]);
				M += 3;
				key = i;
			}
			C++;
		}
		L = key;
		for (int i = L; i < R; i++)	{
			if (mas[i] > mas[i + 1]){
				swap(mas[i], mas[i + 1]);
				M += 3;
				key = i;
			}
			C++;
		}
		R = key;
	}
}

void BubbleSort(int *a, int N){
	for (int i = N - 1; i >= 0; i--)
		for (int j = 0; j < i; j++){
			++C;
			if (a[j] > a[j + 1]){
				int t = a[j];
				a[j] = a[j + 1];
				a[j + 1] = t;
				M += 3;
			}
		}
}

void SelectSort(int *a, int N){
	int key;
	//M_2 = 0;

	for (int i = 0; i < N - 1; i++)	{
		key = i;
		for (int j = i + 1; j < N; j++){
			++C;
			if (a[j] < a[key])
			{
				key = j;
			}
		}
		if (a[i] != a[key]){	// фиктивная перестановка
			int t = a[i];
			a[i] = a[key];
			a[key] = t;
			M += 3;
		}
		//M_2 += 3;
	}
}

void InsertSort(int *a, int N){
	int i, key, j;
	for (i = 1; i < N; i++) {
		key = a[i];
		j = i - 1;
		M++; C++;
		while (j >= 0 && a[j] > key) {
			a[j + 1] = a[j];
			j = j - 1;
			M++;
			C++;
		}
		a[j + 1] = key;
		M++;
	}
}


int main(){
	size_t c;
	int a[n];
	while (1){
		srand(time(NULL));
		cout << "Write a number:\n1.InsertSort\n2.Table\n3.Exit" << endl;
		cin >> c;
		switch (c){
		case 1:
			system("cls");
			cout << "Write a number:\n1.Inc\n2.Dec\n3.Rand\n ";
			cin >> c;

			switch (c) {
			case 1:
				system("cls");
				cout << "Inc: \n";
				FillInc(a, n);
				InsertSort(a, n);
				break;
			case 2:
				system("cls");
				cout << "Dec: \n";
				FillDec(a, n);
				InsertSort(a, n);
				break;
			case 3:
				system("cls");
				cout << "Rand: \n";
				FillRand(a, n);
				InsertSort(a, n);
				break;
			}
			
				M_Theory = ((n*n - n) / 2) + 2 * n - 2;
				C_Theory = (n*n - n) / 2;

				cout << "Practice M: " << M << endl
					<< "Practice C: " << C << endl << endl
					<< "Theory M: " << M_Theory << endl
					<< "Theory C: " << C_Theory << endl;	
				M = 0; C = 0;
			_getch();
			break;
		case 2: 
			system("cls");
			cout << "n\tSelectSort\tBubble\tShaker\tInsert" << endl;

			for (int i = n * 10; i <= 400; i += 100) {
				srand(time(NULL));
				cout << i << "\t";

				FillRand(a, i);
				SelectSort(a, i);
				cout << M + C << "\t\t";
				M = 0; C = 0;

				FillRand(a, i);
				BubbleSort(a, i);
				cout << M + C << "\t";
				M = 0; C = 0;

				FillRand(a, i);
				ShakerSort(a, i);
				cout << M + C << "\t";
				M = 0; C = 0;

				FillRand(a, i);
				InsertSort(a, i);
				cout << M + C << "\n";
				M = 0; C = 0;
			}
			_getch();
			break;
		case 3:	return 0;
		}
		system("cls");
	//	M_Theory = 0; C_Theory = 0;
	}
	return 0;
}

