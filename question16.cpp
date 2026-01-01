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
int readNumberFromUser(string Message)

{
	int Number = 0;
	cout << Message;
	cin >> Number;

	while (cin.fail())
	{
		cin.clear();
		cin.ignore(std::numeric_limits <std::streamsize> ::max(), '\n');

		cout << "You Entered a Wrong Value , Please Enter a Number : ";
		cin >> Number;

	}
	return Number;

}
int countNumberInMatrix(int Matrix[3][3], short rows, short columns, int Number)
{
	int counter = 0;
	for (short i = 0; i < rows; i++)
	{
		for (short j = 0; j < columns; j++)
		{
			if (Matrix[i][j] == Number)
				counter++;
		}
	}
	return counter;
}
bool isSparseMatrixOrNot(int Matrix[3][3], short rows, short columns)
{
	int zeroCount = 0;
	int totalElements = rows * columns;

	for (short i = 0; i < rows; i++)
	{
		for (short j = 0; j < columns; j++)
		{
			if (Matrix[i][j] == 0)
				zeroCount++;
		}
	}

	return (zeroCount > (totalElements - zeroCount));
}

int main()
{
	int Matrix[3][3] = {
		{0 , 1 ,12 },
		{ 0, 0 , 0},
		{0 , 0 ,9 }
	};

	cout << "Matrix1 : \n";
	printMatrixMatrixElements(Matrix, 3, 3);
	if (isSparseMatrixOrNot(Matrix, 3, 3))
		cout << "Sprace " << endl;
	else
		cout << "Not Sprace " << endl;


}