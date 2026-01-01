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
bool isNumberExistsInMatrix(int Matrix[3][3], short rows, short columns, int Number)
{

	for (short i = 0; i < rows; i++)
	{
		for (short j = 0; j < columns; j++)
		{
			if (Matrix[i][j] == Number)
				return true;
		}
	}
	return false;
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
	int Number = readNumberFromUser("Please Enter number to look in matrix ? : ");
	if (isNumberExistsInMatrix(Matrix, 3, 3, Number))
		cout << "Number is Exists " << endl;
	else
		cout << "Number is not Exists " << endl;


}