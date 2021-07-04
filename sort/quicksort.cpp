//https://www.youtube.com/watch?v=cWH49IKDIiI&t=282s
#include <iostream>
using namespace std;

void print_nums(int array[], size_t count)
{
	cout << "--------- print_nums ---------" << endl;
	for (size_t i = 0; i < count; i++)
	{
		cout << array[i] << " ";
		if (i != 0 && i % 10 == 0)
			cout << endl;
	}
	cout << endl;
}

int partition(int array[], int start, int end)
{
	int pivot_value = array[end];
	int where_pivot = start - 1;
	for (size_t i = start; i <= end - 1; i++)
	{
		if (pivot_value >= array[i])
		{
			where_pivot++;
			if (where_pivot != i)
				swap(array[i], array[where_pivot]);
		}
	}
	swap(array[end], array[where_pivot + 1]);
	return (where_pivot + 1);
}

void quicksort(int array[], int start, int end)
{
	if (start >= end)
		return ;
	int pivot_index = partition(array, start, end);
	quicksort(array, start, pivot_index - 1);
	quicksort(array, pivot_index + 1, end);
}


int main()
{
	// int lists[24] = {5,3,4,2,1,1,6,4,3,2,6,4,9,5,3,2,6,8,3,5,7,4,3,1};
	int lists[3] = {3, 2, 0};
	// int lists[3] = {0, 1, 2};
	// int lists[4] = {3, 2, 1, 0};
	// int lists[2] = {3, 2};
	// int lists[5] = {3, 2, 6, 4, 0};
	size_t count = sizeof(lists)/sizeof(lists[0]);

	print_nums(lists, count);
	quicksort(lists, 0, count - 1);
	print_nums(lists, count);
	return (1);
}