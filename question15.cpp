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
bool isSpraceMatrixOrNot(int Matrix[3][3], short rows, short columns)
{
	int NumberOfZeros = countNumberInMatrix(0); 

	for (short i = 0; i < rows; i++)
	{
		for (short j = 0; j < columns; j++)
		{
			if(countNumberInMatrix(Matrix[i][j] > NumberOfZeros)
				return false; 
		}
	}
	return true ; 
}
int main()
{
	int Matrix[3][3] = {
		{9 , 1 ,12 },
		{ 0, 9 , 0},
		{0 , 9 ,9 }
	};

	cout << "Matrix1 : \n";
	printMatrixMatrixElements(Matrix, 3, 3);
	if (isSpraceMatrixOrNot(Matrix, 3, 3))
		cout << "Sprace " << endl ;
	else
		cout << "Not Sprace " << endl; 


}