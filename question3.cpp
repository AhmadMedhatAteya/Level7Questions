#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;
// Write Program to fill 3x3 matrix with random numbers
//then sum each row in seprate array and print the Results 

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
void printMatrixElements(short rows, short columns, int Matrix[3][3])
{
	cout << "The Following is a 3x3 random Matrix : \n";
	for (short i = 0; i < rows; i++)
	{
		for (short j = 0; j < columns; j++)
		{
			cout << left << setw(5) << Matrix[i][j];
		}
		cout << endl;
	}
}
void ArrayOfSumOfEachRowInMatrix(short rows, short columns, int Matrix[3][3], int sumArray[])
{

	for (short row = 0; row < rows; row++)
	{
		int tempSumRow = 0;
		for (short column = 0; column < columns; column++)
		{
			tempSumRow += Matrix[row][column];
		}
		sumArray[row] = tempSumRow;
	}
}
void printSumArrayElements(short sizeOfArray, int array[])
{
	cout << "The following are the sum of each row in the matrix : \n";
	for (short i = 0; i < sizeOfArray; i++)
	{
		cout << "Row " << (i + 1) << " Sum = " << array[i] << endl;

	}
}
int main()
{
	srand((unsigned)time(NULL));
	int Matrix[3][3];
	fill3x3MatrixWithRandomNumbers(3, 3, Matrix);
	printMatrixElements(3, 3, Matrix);

	int sumArr[3];
	ArrayOfSumOfEachRowInMatrix(3, 3, Matrix, sumArr);
	printSumArrayElements(3, sumArr);
}