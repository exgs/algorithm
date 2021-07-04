#include <iostream>
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

void quicksort(int *array, size_t start, size_t end)
{
	if ((int)end <= (int)start)
		return ;
	int pivot_value = array[(start + end) / 2];
	size_t left = start;
	size_t right = end;
	while (left <= right)
	{
		while (array[left] < pivot_value)
			left++;
		while (array[right] > pivot_value)
			right--;
		if (left <= right)
		{
			swap(array[left], array[right]);
			left++; right--;
		}
	}
	quicksort(array, start, right);
	quicksort(array, left, end);
}


int main()
{
	int lists[24] = {5,3,4,2,1,1,6,4,3,2,6,4,9,5,3,2,6,8,3,5,7,4,3,1};
	// int lists[3] = {3, 2, 0};
	// int lists[4] = {3, 2, 1, 0};
	// int lists[2] = {3, 2};
	// int lists[5] = {3, 2, 6, 4, 0};
	size_t count = sizeof(lists)/sizeof(lists[0]);

	print_nums(lists, count);
	quicksort(lists, 0, count - 1);
	print_nums(lists, count);
	return (0);
}
