#include <iostream>
#include <cstdlib>
using namespace std;

int GetPositiveNumber(string msg)
{
	int Number;
	do
	{
		cout << msg << endl;
		cin >> Number;
	} while (Number <= 0);
	return Number;
}
int GetRandomNumber(int from, int to)
{
	int RandomNumber = rand() % (to - from + 1) + from;
	return RandomNumber;
}
void FillRandomArray(int RandomArray[100], int& ArrayLength)
{
	ArrayLength = GetPositiveNumber("Enter Array Length :\n");
	for (int i = 0; i < ArrayLength; i++)
	{
		RandomArray[i] = GetRandomNumber(1, 100);
	}
}
void PrintArray(int RandomArray[100], int ArrayLength)
{
	for (int i = 0; i < ArrayLength; i++)
	{
		cout << RandomArray[i] << " ";
	}
}
short SearchElement(int RandomArray[100], int ArrayLength, int& xNumber)
{
	xNumber = GetPositiveNumber("\nEnter a number to search for ? :\n");
	for (int i = 0; i < ArrayLength; i++)
	{
		if (xNumber == RandomArray[i])
		{
			return i;
			break;
		}
	}
	return -1;
}
bool CheckResult(int RandomArray[100], int ArrayLength, int& xNumber)
{
	return SearchElement(RandomArray, ArrayLength, xNumber) != -1;

}


void PrintResult(int RandomArray[100], int ArrayLength, int& xNumber)
{
	
	cout << "Number you are looking is :" << xNumber << endl;
	if (!CheckResult(RandomArray, ArrayLength, xNumber))
	{

		cout << "Sorry ! .The number is not found :-(\n";
	}
	else
	{
		cout << "Yeah ... The number is found :-) "<< endl;
	
	}
}
int main()
{
	srand((unsigned)time(NULL));
	int RandomArray[100], ArrayLength = 0, xNumber;
	FillRandomArray(RandomArray, ArrayLength);
	PrintArray(RandomArray, ArrayLength);

	PrintResult(RandomArray, ArrayLength, xNumber);

	return 0;
}