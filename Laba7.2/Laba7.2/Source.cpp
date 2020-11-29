#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;
int FindMinElement(int* row, const int colCount);

void Create(int** a, const int rowCount, const int colCount, const int Low, const int High)
{
	for (int i = 0; i < rowCount; i++)
		for (int j = 0; j < colCount; j++)
			a[i][j] = Low + rand() % (High - Low + 1);
}
void Print(int** a, const int rowCount, const int colCount)
{
	cout << endl;
	for (int i = 0; i < rowCount; i++)
	{
		for (int j = 0; j < colCount; j++)
			cout << setw(4) << a[i][j];
		cout << endl;
	}
	cout << endl;
}

int Sum(int** a, const int rowCount, const int colCount)
{
	int S = 0;
	for (int i = 0; i < rowCount; i++)
		S += FindMinElement(a[i], colCount);
	return S;
}int FindMinElement(int* row, const int colCount)
{
	int min = row[0];
	for (int i = 1; i < colCount; i++)
		if (row[i] < min)
			min = row[i];
	return min;
}int main()
{
	srand((unsigned)time(NULL));
	int Low = 7;
	int High = 65;
	
	int rowCount, colCount;
	cout << "Enter rows count: "; cin >> rowCount;
	cout << "Enter columns count: "; cin >> colCount;
	cout << endl;
	cout << "Generated matrix: " << endl;

	int** a = new int* [rowCount];
	for (int i = 0; i < rowCount; i++)
		a[i] = new int[colCount];
	for (int i = 0; i < rowCount; i++)

	Create(a, rowCount, colCount, Low, High);
	Print(a, rowCount, colCount);
	
	cout << "Sum of min = " << Sum(a, rowCount, colCount) << endl;

	for (int i = 0; i < 0; i++)

	delete[] a[i];
	delete[] a;
	return 0;
}