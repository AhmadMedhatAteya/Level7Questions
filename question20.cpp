#include <iostream>
using namespace std;



void printFibonacciSeriesFrom1ToNumber(int Number)
{
	for (int i = 1; i < Number; i++)
	{
		for (int j = 0; j < i; j++)
		{
			cout << i + j << " "; 
		}
	}
}


int main()
{
	printFibonacciSeriesFrom1ToNumber(10);
}