#include <iostream>
#include <string>

using namespace std;

struct s_data
{
	size_t size;
	size_t front_size;
	size_t back_size;
};

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

int *mergesort(int *array, s_data data);
void divid(int *lists, s_data data, int **temp1, int **temp2);
void setting_data(s_data &data, int count);
int *merge(int *temp1, int *temp2, s_data data);

void setting_data(s_data &data, int count)
{
	data.size = count;
	data.front_size = count / 2;
	data.back_size = data.size - data.front_size;
}

int main()
{
	// int lists[24] = {5,3,4,2,1,1,6,4,3,2,6,4,9,5,3,2,6,8,3,5,7,4,3,1};
	// int count = 24;
	// int lists[3] = {3, 2, 0};
	// int count = 3;
	int lists[4] = {3, 2, 1, 0};
	int count = 4;
	// int lists[5] = {3, 2, 6, 4, 0};
	// int count = 5;
	int *result;
	s_data data;
	setting_data(data, count);
	print_nums(lists, data.size);
	result = mergesort(lists, data);
	print_nums(result, data.size);
	delete []result;
	return (0);
}

int *mergesort(int *lists, s_data data)
{
	if (data.size == 1)
		return (lists);
	// 나눠야되
	int *temp1; int *temp2; int *temp3;
	divid(lists, data, &temp1, &temp2); // divide했지만, 각각은 정렬되어있기를 바라과 있어
	// temp3 = merge(temp1, temp2, data);
	temp3 = merge(temp1, temp2, data);
	// print_nums(temp3, data.size);
	return (temp3);
}

void divid(int *lists, s_data data, int **temp1, int **temp2)
{
	*temp1 = new int[data.front_size];
	*temp2 = new int[data.back_size];
	for (size_t i = 0; i < data.front_size; i++)
	{
		(*temp1)[i] = lists[i];
	}
	print_nums(*temp1, data.front_size);

	for (size_t i = data.front_size; i < data.size; i++)
	{
		(*temp2)[i - data.front_size] = lists[i];
	}
	print_nums(*temp2, data.back_size);

	s_data data_input;
	setting_data(data_input, data.front_size);
	mergesort(*temp1, data_input);
	setting_data(data_input, data.back_size);
	mergesort(*temp2, data_input);
}

int *merge(int *temp1, int *temp2, s_data data)
{
	int *temp3 = new int[data.size];
	int a = 0; int b = 0;
	for (size_t i = 0; i < data.size; i++)
	{
		cout << "a : " << a << "b : " << b << endl;
		cout << "left : " << temp1[a] << "right : " << temp2[b]  << endl;
		if (a == data.front_size)
			temp3[i] = temp2[b++];
		else if (b == data.back_size)
			temp3[i] = temp1[a++];
		else if (temp1[a] <= temp2[b])
			temp3[i] = temp1[a++];
		else if (temp1[a] > temp2[b])
			temp3[i] = temp2[b++];
	}
	delete []temp1; delete []temp2;
	return (temp3);
}
