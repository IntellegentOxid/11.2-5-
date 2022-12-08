#include <iostream>
#include <algorithm>
using namespace std;

const unsigned int ARRSIZE = 10;

int main()
{
	bool fail = false;
	float arr[ARRSIZE];
	for (int i = 0; i < ARRSIZE; i++)
	{
		do
		{
			fail = false;
			cout << "Enter a value for " << i + 1 << " array item: ";
			cin >> arr[i];
			if (cin.fail())
			{
				cout << "\nIncorrect valye has been entered!" << endl << endl;
				fail = true;
			}
			cin.clear();
			cin.ignore();
		} while (fail);
	}
	cout << "\nAn array has been obtained: ";
	for (int i = 0; i < ARRSIZE; i++)
	{
		cout << arr[i] << " ";
	}

	unsigned int counter = 0;
	for (int i = 0; i < ARRSIZE; i++)
	{
		if (arr[i] < 0)
			counter++;
	}
	if (counter == 0)
		cout << "\n\nThe are no negative elements in the array\n";
	else
		cout << "\n\nNumber of negative items in an array: " << counter << endl;

	float min_val = abs(arr[0]);
	unsigned int min_idx = 0;

	for (int i = 0; i < ARRSIZE; i++)
	{
		if (min_val > abs(arr[i]))
		{
			min_val = arr[i];
			min_idx = i;
		}
	}

	float abs_sum = 0;
	for (int i = 0; i < ARRSIZE; i++)
	{
		if (i > min_idx)
		{
			abs_sum += abs(arr[i]);
		}
	}
	if (min_idx == (ARRSIZE - 1))
		cout << "The minimum element by module is the last element of the array\n";
	else
		cout << "The sum of the modules of the array elements located after the minimum element by module is equal to " << abs_sum << endl;

	float sort_arr[ARRSIZE];
	for (int i = 0; i < ARRSIZE; i++)
	{
		if (arr[i] < 0)
			sort_arr[i] = pow(arr[i], 2);
		else
			sort_arr[i] = arr[i];
	}

	sort(sort_arr, sort_arr + ARRSIZE);
	cout << "\nSorted array: ";
	for (int i = 0; i < ARRSIZE; i++)
	{
		cout << sort_arr[i] << " ";
	}
	cout << endl;
}