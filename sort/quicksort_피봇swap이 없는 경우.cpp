//https://www.youtube.com/watch?v=7BDzle2n47c

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

void swap(int *array, int a, int b)
{
	int temp = array[a];
	array[a] = array[b];
	array[b] = temp;
}

int partition(int *array, int start, int end)
{
	int pivot = array[(start + end) / 2];
	while (start <= end)
	{
		while (array[start] < pivot) start++;
		while (array[end] > pivot) end--;
		if (start <= end)
		{
			swap(array, start, end);
			start++;
			end--;
		}
	}
	return (start);
}

void quicksort(int *array, int start, int end)
{
	int part2 = partition(array, start, end);
	if (start < part2 - 1)
	{
		quicksort(array, start, part2 - 1);
	}
	if (part2 < end)
	{
		quicksort(array, part2, end);
	}
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
