#include <iostream>
using namespace std;



void printMatrixMatrixElements(int Matrix[3][3], short rows, short columns)
{
	for (short i = 0; i < rows; i++)
	{
		for (short j = 0; j < columns; j++)
		{
			cout << Matrix[i][j] << "\t";
		}
		cout << endl;
	}
}
void printIntersectedNumbersInTwoMatrices(int Matrix1[3][3], int Matrix2[3][3], short rows, short columns)
{
	cout << "Intersected Numbers Are : \n";
	for (short i = 0; i < rows; i++)
	{
		for (short j = 0; j < columns; j++)
		{
			if (Matrix1[i][j] == Matrix2[i][j])
				cout << Matrix1[i][j] << "\t";
		}
	}
}



int main()
{
	int Matrix1[3][3] = {
		{2 , 1 ,12 },
		{ 1, 4 , 0},
		{6 , 0 ,9 }
	};
	int Matrix2[3][3] = {
		{0 , 1 ,12 },
		{ 2, 4 , 0},
		{5 , 0 ,9 }
	};

	cout << "Matrix1 : \n";
	printMatrixMatrixElements(Matrix1, 3, 3);
	cout << "\nMatrix2 : \n";
	printMatrixMatrixElements(Matrix2, 3, 3);

	cout << endl;
	printIntersectedNumbersInTwoMatrices(Matrix1, Matrix2, 3, 3);



}