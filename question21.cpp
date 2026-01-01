#include <iostream>
using namespace std;



void printFibonacciSeriesFrom1ToNumber(int Number)
{

	int Prev1 = 1, Prev2 = 0, FeboNumber;
	cout << "1   ";
	for (int i = 2; i <= Number; i++)
	{
		FeboNumber = Prev1 + Prev2;
		cout << FeboNumber << "   ";
		Prev2 = Prev1;
		Prev1 = FeboNumber;
	}

}


int main()
{
	printFibonacciSeriesFrom1ToNumber(10);
}