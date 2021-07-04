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

void selectsort(int *array, size_t count)
{
	for (size_t i = 0; i < count; i++)
	{
		int min_index = i;
		for (size_t j = i; j < count; j++)
		{
			if (array[min_index] > array[j])
				min_index = j;
		}
		swap(array[i] ,array[min_index]);
	}
}


int main()
{
	int lists[24] = {5,3,4,2,1,1,6,4,3,2,6,4,9,5,3,2,6,8,3,5,7,4,3,1};
	// int lists[3] = {3, 2, 0};
	// int lists[4] = {3, 2, 1, 0};
	// int lists[5] = {3, 2, 6, 4, 0};
	size_t count = sizeof(lists)/sizeof(lists[0]);

	print_nums(lists, count);
	selectsort(lists, count);
	print_nums(lists, count);
	return (0);
}
