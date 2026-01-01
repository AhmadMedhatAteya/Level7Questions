#include <iostream>
using namespace std;

int GenereateRandomNumber(int from, int to)
{
	return rand() % (to - from + 1) + from;
}
void FillMatrixWithRandomNumbers(int Matrix[3][3], short rows, short columns)
{
	for (short i = 0; i < rows; i++)
	{
		for (short j = 0; j < columns; j++)
		{
			Matrix[i][j] = GenereateRandomNumber(1, 100);
		}
	}
}
void printMatrixMatrixElements(int Matrix[3][3], short rows, short columns)
{
	cout << "Matrix Elements : \n";
	for (short i = 0; i < rows; i++)
	{
		for (short j = 0; j < columns; j++)
		{
			cout << Matrix[i][j] << "\t";
		}
		cout << endl;
	}
}
bool isTwoMatricesEqualsOrNot(int Matrix1[3][3], int Matrix2[3][3], short rows, short columns)
{
	for (short i = 0; i < rows; i++)
	{
		for (short j = 0; j < columns; j++)
		{
			if (Matrix1[i][j] != Matrix2[i][j])
				return false;
		}
	}
	return true;
}
int main()
{
	srand((unsigned)time(NULL));
	int Matrx1[3][3], Matrix2[3][3], Matrix[3][3] = {
		{1 ,2 ,3},
		{3,4,5} ,
		{5,7,1}
	};
	int Matrix4[3][3] = {
		{1 ,2 ,3},
		{3,4,5} ,
		{5,7,1}
	};
	FillMatrixWithRandomNumbers(Matrx1, 3, 3);
	FillMatrixWithRandomNumbers(Matrix2, 3, 3);

	printMatrixMatrixElements(Matrx1, 3, 3);
	printMatrixMatrixElements(Matrix2, 3, 3);

	if (isTwoMatricesEqualsOrNot(Matrx1, Matrix2, 3, 3))
	{
		cout << "Yes They Are Equals \n";
	}
	else
		cout << "No They Arent Equals \n";

	cout << endl;
	printMatrixMatrixElements(Matrix, 3, 3);
	printMatrixMatrixElements(Matrix4, 3, 3);
	if (isTwoMatricesEqualsOrNot(Matrix, Matrix4, 3, 3))
		cout << "Equals";
	else
		cout << "Not Equals";


}