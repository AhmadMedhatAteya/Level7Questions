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
bool isTheMatrixScalarOrNot(int Matrix[3][3], short rows, short columns)
{
	int Number = Matrix[0][0];
	for (short i = 0; i < rows; i++)
	{
		for (short j = 0; j < columns; j++)
		{
			if (i == j)
			{
				if (Matrix[i][j] != Number)
					return false;
			}
			else
			{
				if (Matrix[i][j] != 0)
					return false;
			}
		}
	}
	return true;
}
int main()
{
	int Matrix[3][3] = {
		{1 , 0 ,0 },
		{ 0, 1 , 0},
		{0 , 0 ,1 }
	};

	cout << "Matrix1 : \n";
	printMatrixMatrixElements(Matrix, 3, 3);
	if (isTheMatrixScalarOrNot(Matrix, 3, 3))
		cout << "Yes The Matrix is Scalar";
	else
	{
		cout << "No Matrix is Not Scalar";
	}
}