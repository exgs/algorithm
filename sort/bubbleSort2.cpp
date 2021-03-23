#include <iostream>
#include <string>

using namespace std;

struct s_data
{
	size_t size;
};

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

void swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

void bubblesort(int *array, s_data data);

int main()
{
	int lists[24] = {5,3,4,2,1,1,6,4,3,2,6,4,9,5,3,2,6,8,3,5,7,4,3,1};
	int count = 24;
	// int lists[3] = {3, 2, 0};
	// int count = 3;
	// int lists[4] = {3, 2, 1, 0};
	// int count = 4;
	// int lists[5] = {3, 2, 6, 4, 0};
	// int count = 5;
	s_data data;
	data.size = count;
	print_nums(lists, data.size);
	bubblesort(lists, data);
	print_nums(lists, data.size);
	return (0);
}


void bubblesort(int *array, s_data data) // 1. prototype 미리 설정하기
{
	int max;
	int count = data.size;
	size_t i = 0; size_t j = 0;
	while (i < count - 1) // 2. while문의 경우 indnx 값이 보존이된다.
	{
		j = 0;
		while (j < count - 1 - i)
		{
			if (array[j] > array[j+1])
				swap(array[j], array[j+1]);
				// 3. 계속 바꿔주는거면, 변수에 저장할 필요가 없음
				// 한번만 바꿔주는거라면 인덱스 번호를 저장해야함
			j++;
		}
		i++;
	}
}
