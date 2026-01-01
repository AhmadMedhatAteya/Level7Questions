#include <iostream>
#include <vector>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;
//Write a Program to fill a 3x3 matrix with random Numbers

int GenerateRandomNumber(int from, int to)
{
	return rand() % (to - from + 1) + from;
}
void Fill3x3SquareMatrixWithRandomNumbers(int sizeOfarray, int array[3][3])
{
	for (short i = 0; i < sizeOfarray; i++)
	{
		for (short j = 0; j < sizeOfarray; j++)
		{
			array[i][j] = GenerateRandomNumber(0, 100);
		}
	}
}
void printMatrixElements(int sizeOfMatrix, int array[3][3])
{
	for (int i = 0; i < sizeOfMatrix; i++)
	{
		for (int j = 0; j < sizeOfMatrix; j++)
		{
			cout << left << setw(4) << array[i][j] << " ";
		}
		cout << endl;
	}
}

int main()
{
	srand((unsigned)time(NULL));
	int MatrixWithRandomNumbers[3][3];
	Fill3x3SquareMatrixWithRandomNumbers(3, MatrixWithRandomNumbers);
	cout << "Matrix Elements : \n";
	printMatrixElements(3, MatrixWithRandomNumbers);


}