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
		int min_index = i;
		for (size_t j = i + 1; j <= count - 1; j++)
		{
			if (array[min_index] > array[j])
				min_index = j;
		}
		swap(array[i], array[min_index]);
	}
}

void insertsort(int *array, size_t count)
{
	if (count == 0 || count == 1)
		return ;
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
	if (count == 0 || count == 1)
		return ;
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

void setting_data(s_data *data, int count)
{
	data->size = count;
	data->front_size = count / 2; // 홀수이면, 뒷 데이터보다 하나 적음
	data->back_size = data->size - data->front_size;
}

int *mergesort(int *array, s_data mergedata)
{
	if (array == NULL)
		return (NULL);
	int *temp1 = NULL; int *temp2= NULL; int *temp3 = NULL;
	divid(array, mergedata, &temp1, &temp2);
	temp3 = merge(temp1, temp2, mergedata);
	return temp3;
}

void divid(int *lists, s_data mergedata, int **temp1, int **temp2)
{
	if (mergedata.size == 1)
	{
		*temp2 = new int[mergedata.back_size];
		(*temp2)[0] = lists[0];
		return ;
	}
	*temp1 = new int[mergedata.front_size];
	*temp2 = new int[mergedata.back_size];
	int i = 0;
	while (i < mergedata.front_size)
	{
		(*temp1)[i] = lists[i];
		i++;
	}
	int j = 0;
	while (j < mergedata.back_size)
	{
		(*temp2)[j] = lists[i + j];
		j++;
	}
	s_data mergedata1;
	setting_data(&mergedata1, mergedata.front_size);
	s_data mergedata2;
	setting_data(&mergedata2, mergedata.back_size);

	int *before_temp1 = *temp1; int *before_temp2 = *temp2;
	*temp1 = mergesort(before_temp1, mergedata1);
	*temp2 = mergesort(before_temp2, mergedata2);
	delete []before_temp1; delete []before_temp2;
}

int *merge(int *temp1, int *temp2, s_data mergedata)
{
	int *temp3 = new int[mergedata.size];
	int i = 0; int j = 0; int z = 0;
	while (z < mergedata.size)
	{
		if (i == mergedata.front_size)
		{
			temp3[z++] = temp2[j++];
		}
		else if (j == mergedata.back_size)
		{
			temp3[z++] = temp1[i++];
		}
		else if (temp1[i] <= temp2[j])
		{
			temp3[z++] = temp1[i++];
		}
		else if (temp1[i] > temp2[j])
		{
			temp3[z++] = temp2[j++];
		}
	}
	delete []temp1; delete []temp2;
	return (temp3);
}

int partition(int array[], int start, int end)
{
	int pivot_value = array[end];
	int input_pivot = start - 1;
	int i = start;
	while (i <= end - 1)
	{
		if (array[i] < pivot_value)
		{
			input_pivot++;
			if (input_pivot != i)
				swap(array[i], array[input_pivot]);
		}
		i++;
	}
	swap(array[end], array[input_pivot + 1]);
	return (input_pivot + 1);
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
	int lists[24] = {5,3,4,2,1,1,6,4,3,2,6,4,9,5,3,2,6,8,3,5,7,4,3,1};
	// int lists[2] = {100, 9};
	// int lists[1] = {100};
	// int lists[5] = {3, 2, 6, 4, 0};
	size_t count = sizeof(lists)/sizeof(lists[0]);
	s_data merge_data;
	print_nums(lists, count);

	// bubblesort(lists, count);
	// selectsort(lists, count);
	// insertsort(lists, count);
	// shellsort(lists, count);
	quicksort(lists, 0, count - 1);

	/* mergesort는 반환값이 있어서 특별함 */
	// setting_data(&merge_data, count);
	// int *temp = mergesort(lists, merge_data);
	// print_nums(temp, count);
	print_nums(lists, count);

	system("leaks a.out | grep leaks | grep bytes");
	return (0);
}
