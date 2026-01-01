#include <iostream>
#include <iomanip>
using namespace std;

void fill3x3MatrixWithOrderedNumbers(int rows, int columns, int Matrix[3][3])
{
	int counter = 0;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			counter++;
			Matrix[i][j] = counter;
		}
	}
}
void print3x3Matrix(int rows, int columns, int Matrix[3][3], string Message)
{
	cout << Message;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			cout << left << setw(5) << Matrix[i][j];
		}
		cout << endl;
	}
}
void transposeMatrix(int rows, int columns, int Matrix[3][3], int TransposedMatrix[3][3])
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			TransposedMatrix[i][j] = Matrix[j][i];
		}
	}
}
int main()
{
	int Matrix[3][3], transposedMatrix[3][3];
	fill3x3MatrixWithOrderedNumbers(3, 3, Matrix);
	print3x3Matrix(3, 3, Matrix, "The Following is a 3x3 ordered matrix : \n");

	transposeMatrix(3, 3, Matrix, transposedMatrix);
	print3x3Matrix(3, 3, transposedMatrix, "The Following is tranpose matrix : \n");


}