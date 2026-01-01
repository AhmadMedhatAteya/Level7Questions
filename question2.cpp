#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;
// Write Program to fill 3x3 Matrix with random numbers then print each row sum

int GenerateRandomNumber(int from, int to)
{
	return rand() % (to - from + 1) + from;
}
void printMatrix3x3Elements(short rows, short columns, int Matrix[3][3])
{
	cout << "The Following is a 3x3 Random Matrix : \n";
	for (short row = 0; row < rows; row++)
	{
		for (short column = 0; column < columns; column++)
		{
			cout << left << setw(4) << Matrix[row][column] << "\t";
		}
		cout << endl;
	}
}
void fill3x3MatrixWithRandomNumbers(short rows, short columns, int Matrix[3][3])
{
	for (short row = 0; row < rows; row++)
	{
		for (short column = 0; column < columns; column++)
		{
			Matrix[row][column] = GenerateRandomNumber(0, 100);
		}
	}
}
void PrintTheSumOfEachRowIn3x3Matrix(short rows, short columns, int Matrix[3][3])
{
	cout << "The Following are the sum of each row in the matirx : \n";
	for (short row = 0; row < rows; row++)
	{
		int sum = 0;
		for (short column = 0; column < columns; column++)
		{
			sum += Matrix[row][column];
		}
		cout << "Row Number " << (row + 1) << " Elements Sum = " << sum << endl;
	}
}
int main()
{
	srand((unsigned)time(NULL));
	int Matrix[3][3];
	fill3x3MatrixWithRandomNumbers(3, 3, Matrix);
	printMatrix3x3Elements(3, 3, Matrix);
	PrintTheSumOfEachRowIn3x3Matrix(3, 3, Matrix);

}