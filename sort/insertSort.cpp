#include <iostream>
#include <string>
using namespace std;

void swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

void print_nums(int nums[], size_t count)
{
	cout << "------------ print nums ------------" << endl;
	for (size_t i = 0; i < count; i++)
	{
		cout << nums[i] << " ";
		if (i != 0 && i % 10 == 9)
			cout << endl;
	}
	cout << endl;
}

void insertsort(int *array, size_t count)
{
	for (size_t i = 1; i < count; i++)
	{
		size_t pivot_index = i;
		int pivot_value = array[i];
		for (size_t j = pivot_index - 1; j >= 0; j--)
		{
			if (array[j] > pivot_value)
			{
				array[j + 1] = array[j];
			}
			else
			{
				array[j + 1] = pivot_value;
				break;
			}
		}
	}
}


int main()
{
	// int lists[24] = {5,3,4,2,1,1,6,4,3,2,6,4,9,5,3,2,6,8,3,5,7,4,3,1};
	// int lists[3] = {3, 2, 0};
	// int lists[4] = {3, 2, 1, 0};
	int lists[5] = {3, 2, 6, 4, 0};
	size_t count = sizeof(lists)/sizeof(lists[0]);

	print_nums(lists, count);
	insertsort(lists, count);
	print_nums(lists, count);
	return (0);
}
