/**
* The program of calculation of numbers Smith
* @autor Mikhail Koshelev
* @version 1.2 Microsoft Visual Studio 2015
*
*/
#include <iostream>
using namespace std;

/**
* prototype function calculates the sum of the number of digits
* @see summ_number#summ_numbert(int)
*/
int  summ_number(int x);

/**
* prototype function definition of a simple number
* @see prime_number#prime_number(int)
*/
bool prime_number(int number);

/**
* function prototype summation of simple multipliers
* @see amount_multipliers#amount_multipliers(int, bool)
*/
int amount_multipliers(int number, bool show);

/**
* function prototype of calculation of numbers Smith
* @see multi_smit#multi_smit(int, int)
*/
void multi_smit(int begin, int end);

/**
* function prototype of calculation of numbers Smith
* greater than a predetermined number
* @see multi_smits#multi_smits(int)
*/
void multi_smits(int begin);

/**
* MAIN FUNCTION
*/
int main(int argc, char **argv)
{
	multi_smit(1, 100);		// call search function set (interval) Smith numbers
	multi_smits(4937770);	// the smallest number of Smith's search function
							// greater than a predetermined number
	return 0;
}

/**
* function calculates the sum of the number of digits
* @param number
*/
int  summ_number(int x)
{
	int sums;
	for (sums = 0; x; x /= 10)
		sums += x % 10;	//the sum of the number of digits
	return sums;
}

/**
* summing function of simple multipliers
* @param number, show - subvariable
*/
int amount_multipliers(int a, bool show)
{
	int sum = 0;	// sum of digits of its simple multipliers
	int i = 2;
	if (show) cout << "multipliers: ";
	while (i <= a)
	{
		if (a % i == 0)
		{
			if (show) cout << i << " ";
			sum += summ_number(i);
			a = a / i;
		}
		else
		{
			i++;
		}
	}
	return sum;
}

/**
* detection function of a simple number
* @param number
*/
bool prime_number(int number)
{
	bool result = false;
	int k = 0;
	for (int i = 1; i <= number; i++)
	{
		if (number%i == 0) { ++k; }
	}
	if (k == 2) { result = true; }
	return result;
}

/**
* search function is set (interval) Smith numbers
* @param begin - begin interval, end - end interval
*/
void multi_smit(int begin, int end)
{
	for (int i = begin; i <= end; i++)
	{
		if (!prime_number(i) && i != 1) // if the number is not simple
		{
			if (amount_multipliers(i, false) == summ_number(i))
			{
				cout << "number Smith: " << i << endl;
				// sum of the multipliers of numbers
				cout << "\nsum of the multipliers of numbers: " << amount_multipliers(i, true) << endl;
				// sum of digits of the number
				cout << "sum of digits of the number: " << summ_number(i) << endl;
				cout << endl;
			}
		}

	}
	cout << endl;
}

/**
* function of calculation of numbers Smith
* greater than a predetermined number
* @param begin - number of the task: 4937775
*/
void multi_smits(int begin)
{
	int i = begin;
	while (1)
	{
		if (!prime_number(i) && i != 1) // if the number is not simple
		{
			if (amount_multipliers(i, false) == summ_number(i))
			{
				cout << "number Smith: " << i << endl;
				// sum of the multipliers of numbers
				cout << "\nsum of the multipliers of numbers: " << amount_multipliers(i, true) << endl;
				// sum of digits of the number
				cout << "sum of digits of the number: " << summ_number(i) << endl;
				cout << endl;
				break;
			}
		}
		i++;
	}
	cout << endl;
}