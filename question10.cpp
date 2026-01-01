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
int sumOfMatrixElements(short rows, short columns, int Matrix[3][3])
{
	int sum = 0;
	for (short i = 0; i < rows; i++)
	{
		for (short j = 0; j < columns; j++)
		{
			sum += Matrix[i][j];
		}
	}
	return sum;
}
int main()
{

	srand((unsigned)time(NULL));
	int Matrix1[3][3];
	fill3x3MatrixWithRandomNumbers(3, 3, Matrix1);
	print3x3MatrixElements(3, 3, Matrix1, "Matrix1:");

	cout << "\nSum Of Matrix1 is : " << sumOfMatrixElements(3, 3, Matrix1);


}