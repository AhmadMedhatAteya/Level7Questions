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
void printEachColumnSum(short rows, short columns, int Matrix[3][3])
{
	for (int column = 0; column < columns; column++)
	{
		cout << "Column " << (column + 1) << " Sum = ";
		cout << ColumnSumInMatrix(column, rows, Matrix) << endl;
	}
}
int main()
{
	srand((unsigned)time(NULL));
	int Matrix[3][3];
	fill3x3MatrixWithRandomNumbers(3, 3, Matrix);
	print3x3MatrixElements(3, 3, Matrix);
	printEachColumnSum(3, 3, Matrix);
}