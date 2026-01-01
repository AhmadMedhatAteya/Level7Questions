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
int MaximumNumberInMatrix(int Matrix1[3][3], short rows, short columns)
{
	int Max = Matrix1[0][0];
	for (short i = 0; i < rows; i++)
	{
		for (short j = 0; j < columns; j++)
		{
			if (Matrix1[i][j] > Max)
				Max = Matrix1[i][j];
		}
	}
	return Max;
}
int MinNumberInMatrix(int Matrix1[3][3], short rows, short columns)
{
	int Min = Matrix1[0][0];
	for (short i = 0; i < rows; i++)
	{
		for (short j = 0; j < columns; j++)
		{
			if (Matrix1[i][j] < Min)
				Min = Matrix1[i][j];
		}
	}
	return Min;
}



int main()
{
	int Matrix1[3][3] = {
		{2 , 1 ,12 },
		{ 1, 4 , 0},
		{6 , 0 ,9 }
	};


	cout << "Matrix1 : \n";
	printMatrixMatrixElements(Matrix1, 3, 3);
	cout << endl;

	cout << "Min Number : " << MinNumberInMatrix(Matrix1, 3, 3) << endl;
	cout << "Max Number : " << MaximumNumberInMatrix(Matrix1, 3, 3) << endl;




}