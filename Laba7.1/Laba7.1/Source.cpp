#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;
void Change(int** T, const int row1, const int row2, const int colCount);

void Create(int** T, const int rowCount, const int colCount, const int Low,
	const int High)
{
	for (int i = 0; i < rowCount; i++)
		for (int j = 0; j < colCount; j++)
			T[i][j] = Low + rand() % (High - Low + 1);
}
void Print(int** T, const int rowCount, const int colCount)
{
	cout << endl;
	for (int i = 0; i < rowCount; i++)
	{
		for (int j = 0; j < colCount; j++)
			cout << setw(4) << T[i][j];
		cout << endl;
	}
	cout << endl;
}

void Sort(int** T, const int rowCount, const int colCount)
{
	for (int i0 = 0; i0 < rowCount - 1; i0++)
		for (int i1 = 0; i1 < rowCount - i0 - 1; i1++)
			if ((T[i1][0] < T[i1 + 1][0])
				||
				(T[i1][0] == T[i1 + 1][0] &&
					T[i1][1] < T[i1 + 1][1])
				||
				(T[i1][0] == T[i1 + 1][0] &&
					T[i1][1] == T[i1 + 1][1] &&
					T[i1][2] > T[i1 + 1][2]))
				Change(T, i1, i1 + 1, colCount);
}
void Change(int** T, const int row1, const int row2, const int colCount)
{
	int tmp;
	for (int j = 0; j < colCount; j++)
	{
		tmp = T[row1][j];
		T[row1][j] = T[row2][j];
		T[row2][j] = tmp;
	}
}
void CalculateZero(int** T, const int rowCount, const int colCount, int& S, int& k)
{
	S = 0;
	k = 0;
	for (int i = 0; i < rowCount; i++)
		for (int j = 0; j < colCount; j++)
			if (T[i][j] % 5 == 0 && T[i][j] > 0)
			{
				S += T[i][j];
				k++;
				T[i][j] = 0;
			}
}int main()
{
	srand((unsigned)time(NULL));
	int Low = -42;
	int High = 51;

	int rowCount = 7;
	int colCount = 6;

	int** T = new int* [rowCount];
	for (int i = 0; i < rowCount; i++)
		T[i] = new int[colCount];

	cout << "Generated matrix: " << endl;
	Create(T, rowCount, colCount, Low, High);
	Print(T, rowCount, colCount);
	cout << "Sorted matrix: " << endl;
	Sort(T, rowCount, colCount);
	Print(T, rowCount, colCount);

	int S = 0;
	int k = 0;
	CalculateZero(T, rowCount, colCount, S, k);
	cout << "Sum of values = " << S << endl;
	cout << "Number of values = " << k << endl;
	Print(T, rowCount, colCount);
	for (int i = 0; i < rowCount; i++)

	delete[] T[i];
	delete[] T;
	return 0;
}