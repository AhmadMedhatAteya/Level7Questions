#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

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
void print3x3MatrixElements(short rows, short columns, int Matrix[3][3], string Message)
{
	cout << Message << endl;
	for (short i = 0; i < rows; i++)
	{
		for (short j = 0; j < columns; j++)
		{
			cout << left << setw(5) << Matrix[i][j];
		}
		cout << endl;
	}
}
void printMiddleRow(short rows, short columns, int Matrix[3][3])
{
	short MiddleRow = rows / 2;
	for (short j = 0; j < columns; j++)
	{
		printf(" %0*d ", 2, Matrix[MiddleRow][j]);
	}
	cout << "\n";
}
void printMiddleCol(short rows, short columns, int Matrix[3][3])
{
	short MiddleCol = columns / 2;
	for (short j = 0; j < rows; j++)
	{
		printf(" %0*d ", 2, Matrix[j][MiddleCol]);
	}
	cout << "\n";
}
int main()
{

	srand((unsigned)time(NULL));
	int Matrix1[3][3];
	fill3x3MatrixWithRandomNumbers(3, 3, Matrix1);
	print3x3MatrixElements(3, 3, Matrix1, "Matrix1:");

	cout << "Middle Column : \n";
	printMiddleCol(3, 3, Matrix1);

	cout << "Middle Row : \n";
	printMiddleRow(3, 3, Matrix1);



}