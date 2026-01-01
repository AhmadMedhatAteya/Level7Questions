#include <iostream>
#include <iomanip>

using namespace std;
int GenerateRandomNumber(int from, int to)
{
	return rand() % (to - from + 1) + from;
}
void fill3x3MatrixWithRandomNumbers(short rows, short columns, int Matrix[3][3])
{
	for (short i = 0; i < rows; i++)
	{
		for (short j = 0; j < columns; j++)
		{
			Matrix[i][j] = GenerateRandomNumber(1, 100);
		}
	}
}
void print3x3MatrixElements(short rows, short columns, int Matrix[3][3])
{
	cout << "The Following is 3x3 random matrix : \n";
	for (short i = 0; i < rows; i++)
	{
		for (short j = 0; j < columns; j++)
		{
			cout << left << setw(5) << Matrix[i][j];
		}
		cout << endl;
	}
}
int ColumnSumInMatrix(short column, short rows, int Matrix[3][3])
{
	int sum = 0;
	for (short row = 0; row < rows; row++)
	{
		sum += Matrix[row][column];
	}
	return sum;
}
void sumEachColToAnotherArray(short columns, short rows, int Matrix[3][3], int SumArr[])
{
	for (short column = 0; column < columns; column++)
	{
		SumArr[column] = ColumnSumInMatrix(column, rows, Matrix);
	}
}
void printSumArrayElements(short sizeOfArray, int Arr[])
{
	cout << "The Following are the sum of each col in the matrix : \n";
	for (short i = 0; i < sizeOfArray; i++)
	{
		cout << "Col " << (i + 1) << " Sum = " << Arr[i];
		cout << endl;
	}
}
int main()
{
	srand((unsigned)time(NULL));
	int Matrix[3][3];
	fill3x3MatrixWithRandomNumbers(3, 3, Matrix);
	print3x3MatrixElements(3, 3, Matrix);

	int SumArr[3];
	sumEachColToAnotherArray(3, 3, Matrix, SumArr);
	printSumArrayElements(3, SumArr);

}