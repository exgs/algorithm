//https://www.youtube.com/watch?v=cWH49IKDIiI&t=282s

#include <iostream>
using namespace std;

void print_nums(int nums[], size_t count)
{
	cout << "------------ print nums ------------" << endl;
	for (size_t i = 0; i < count; i++)
	{
		cout << nums[i] << " " << endl;
		if (i != 0 && i % 10 == 9)
			cout << endl;
	}
	cout << endl;
}

void swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

int partition(int *array, int start, int end)
{
	int pivot = array[end];
	int i = start - 1;
	for (int j = start; j <= end - 1; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			swap(array[i], array[j]);
		}
	}
	swap(array[i + 1], array[end]);
	return (i + 1);
}

void quicksort(int *array, int start, int end)
{
	if (start >= end)
		return ;
	int pivot_index = partition(array, start, end);
	quicksort(array, start, pivot_index - 1);
	quicksort(array, pivot_index + 1, end);
}

int main()
{
	int lists[24] = {5,3,4,2,1,1,6,4,3,2,6,4,9,5,3,2,6,8,3,5,7,4,3,1};
	int count = 24;
	// int lists[3] = {3, 2, 0};
	// int count = 3;
	// int lists[2] = {2, 1};
	// int count = 2;
	// int lists[4] = {3, 2, 1, 0};
	// int count = 4;
	// int lists[5] = {3, 2, 6, 4, 0};
	// int count = 5;
	print_nums(lists, count);
	quicksort(lists, 0, count - 1);
	print_nums(lists, count);
	return (1);
}
