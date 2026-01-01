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
bool isTheMatrixisIdentitityOrNot(int Matrix[3][3], short rows, short columns)
{
	for (short i = 0; i < rows; i++)
	{
		for (short j = 0; j < columns; j++)
		{
			if (i == j)
			{
				if (Matrix[i][j] != 1)
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
	if (isTheMatrixisIdentitityOrNot(Matrix, 3, 3))
		cout << "Yes The Matrix is Identity ";
	else
	{
		cout << "No Matrix is Not Identity";
	}
}