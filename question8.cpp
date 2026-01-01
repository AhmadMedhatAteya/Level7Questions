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
void MultiplyTwo3x3Matrices(short rows, short columns, int Matrix1[3][3], int Matrix2[3][3], int ResultMatrix[3][3])
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			ResultMatrix[i][j] = Matrix1[i][j] * Matrix2[i][j];
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
int main()
{

	srand((unsigned)time(NULL));
	int Matrix1[3][3], Matrix2[3][3], ResultMatrix[3][3];
	fill3x3MatrixWithRandomNumbers(3, 3, Matrix1); fill3x3MatrixWithRandomNumbers(3, 3, Matrix2);
	print3x3MatrixElements(3, 3, Matrix1, "Matrix1:");
	print3x3MatrixElements(3, 3, Matrix2, "Matrix2:");

	MultiplyTwo3x3Matrices(3, 3, Matrix1, Matrix2, ResultMatrix);
	print3x3MatrixElements(3, 3, ResultMatrix, "Result:");



}