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

void modified_insertsort(int *array, int start, int interval ,size_t count)
{
	if (count == 0 || count == 1)
		return ;
	for (size_t i = start; i < count; i+= interval)
	{
		size_t pivot_index = i;
		int pivot_value = array[i];
		int j = pivot_index - interval;
		while (j >= 0)
		{
			if (array[j] > pivot_value)
			{
				array[j + interval] = array[j];
				j -= interval;
			}
			else
				break ;
		}
		array[j + interval] = pivot_value;
	}
}

void shellsort(int *array, size_t count)
{
	size_t interval = count / 2;
	while (interval != 0)
	{
		for (size_t i = 0; i < interval; i++) // 생성되는 sublist의 갯수
		{
			// i가 의미하는 것은 나머지가 된다. (0 ~ interval - 1)
			modified_insertsort(array, i, interval, count);
		}
		interval /= 2;
	}
	
}


int main()
{
	// int lists[24] = {5,3,4,2,1,1,6,4,3,2,6,4,9,5,3,2,6,8,3,5,7,4,3,1};
	// int lists[3] = {3, 2, 0};
	// int lists[2] = {3, 2};
	int lists[4] = {3, 2, 1, 0};
	// int lists[5] = {3, 2, 6, 4, 0};
	size_t count = sizeof(lists)/sizeof(lists[0]);

	print_nums(lists, count);
	shellsort(lists, count);
	print_nums(lists, count);
	return (0);
}
