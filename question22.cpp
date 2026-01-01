#include <iostream>
using namespace std;

void printFiboNumbers(int number, int Prev1, int Prev2)
{
	int FiboNumber = 0;
	if (number > 0)
	{
		FiboNumber = Prev1 + Prev2;
		Prev2 = Prev1;
		Prev1 = FiboNumber;
		cout << FiboNumber << "    ";
		printFiboNumbers(number - 1, Prev1, Prev2);
	}

}

int main()
{
	printFiboNumbers(10, 0, 1);
}