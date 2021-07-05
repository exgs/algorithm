/* 통합 과정 */
#include "sort.hpp"
using namespace std;

void swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

void print_nums(int array[], size_t count)
{
	cout << "------------ print nums ------------" << endl;
	for (size_t i = 0; i < count; i++)
	{
		cout << array[i] << " ";
		if (i != 0 && i % 10 == 9)
			cout << endl;
	}
	cout << endl;
}

void bubblesort(int array[], size_t count)
{
	for (size_t i = count - 1; i > 0; i--)
	{
		for (size_t j = 0; j < i; j++)
		{
			if (array[j] > array[j + 1])
				swap(array[j], array[j + 1]);
		}
	}
	return ;
}

void selectsort(int *array, size_t count)
{
	if (count == 0 || count == 1)
		return ;
	for (size_t i = 0; i <= count - 2; i++)
	{
		for (size_t j = i + 1; j <= count - 1; j++)
		{
			if (array[i] > array[j])
				swap(array[i], array[j]);
		}
	}
}

void insertsort(int *array, size_t count)
{
	for (size_t i = 1; i < count; i++)
	{
		int key_index = i;
		int key_value = array[i];
		int j = i - 1;
		while (j >= 0 && array[j] > key_value)
		{
			array[j + 1] = array[j];
			j--;
		}
		array[j + 1] = key_value;
	}
}

void shell_insertsort(int *array, int start, int interval ,size_t count)
{
	for (size_t i = start + interval; i < count; i += interval)
	{
		int key_index = i;
		int key_value = array[i];
		int j = i - interval;
		while (j >= 0 && array[j] > key_value)
		{
			array[j + interval] = array[j];
			j -= interval;
		}
		array[j + interval] = key_value;
	}
}

void shellsort(int *array, size_t count)
{
	int interval = count / 2;
	while (interval != 0)
	{
		for (size_t i = 0; i <= interval - 1; i++)
		{
			shell_insertsort(array, i, interval, count);
		}
		interval /= 2;
	}
	
}

int *mergesort(int *array, s_data data)
{
	return (NULL);
}

void divid(int *lists, s_data data, int **temp1, int **temp2)
{

}

void setting_data(s_data &data, int count)
{

}

int *merge(int *temp1, int *temp2, s_data data)
{
	return (NULL);
}

int partition(int array[], int start, int end)
{
	return (0);
}

void quicksort(int array[], int start, int end)
{

}

int main()
{
	int lists[24] = {5,3,4,2,1,1,6,4,3,2,6,4,9,5,3,2,6,8,3,5,7,4,3,1};
	// int lists[2] = {100, 9};
	// int lists[1] = {100};
	// int lists[5] = {3, 2, 6, 4, 0};
	size_t count = sizeof(lists)/sizeof(lists[0]);

	print_nums(lists, count);
	// bubblesort(lists, count);
	// selectsort(lists, count);
	// insertsort(lists, count);
	shellsort(lists, count);

	print_nums(lists, count);

	return (0);
}
