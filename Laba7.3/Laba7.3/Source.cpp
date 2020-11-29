#include <iostream>
#include <iomanip>
using namespace std;

void Create(int** a, const int rowCount, const int colCount, const int Low,
	const int High)
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
bool IsZeroElementInColumn(int** matrix, const int rowCount, const int colIndex)
{
	for (int i = 0; i < rowCount; i++)
		if (matrix[i][colIndex] == 0)
			return true;
	return false;
}int ÑountColumnsWithZero(int** matrix, const int rowCount, const int colCount)
{
	int Result = 0;
	for (int i = 0; i < colCount; i++)
		if (IsZeroElementInColumn(matrix, rowCount, i))  {
			++Result;
		}
	return Result;
}int MaxSeria(int* arr, int size){
	int count = 0, max[2] = { 0 };
	for (int i = 0; i < size; i++) {
		for (int j = i; j < size - 1; j++) {
			if (arr[j] == arr[j + 1])
			{
				count++;
				while (arr[j] == arr[j + 1]) {
					j++;
					count++;

					if (max[1] < count) {
						max[0] = arr[j];
						max[1] = count;
					}
				}
				count = 0;
			}
			
		}
	}
	return max[1];
}void FindRowWithLongestSeriaOfElements(int** a, int rowCount, int colCount) {	int Number = 0;	int LongestSeria = 1;	for (int i = 0; i < rowCount; i++) {		int buf = MaxSeria(a[i], colCount);		if (LongestSeria < buf) {			LongestSeria = buf;			Number = i;		}	}	Number++; 	cout << Number << endl;}int main()
{
	srand((unsigned)time(NULL));

	int Low = -2;
	int High = 2;

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
	
	cout << "Longest seria in row: ";
	FindRowWithLongestSeriaOfElements(a, rowCount, colCount);
	cout << endl;

	cout << "Number of columns with at least one zero element = " << ÑountColumnsWithZero(a, rowCount, colCount) << endl;

	for (int i = 0; i < 0; i++)

	delete[] a[i];
	delete[] a;
	return 0;
}