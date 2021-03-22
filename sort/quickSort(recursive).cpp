#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct s_data
{
	int *nums_;
	size_t size_;

	int start_;
	int end_; //index로 전해주자
};

void data_setting(s_data &data, int start, int end)
{
	data.start_ = start;
	data.end_ = end;
	data.size_ = end - start + 1;
}

s_data quick_sort(s_data data, int start, int end);

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

void swap(int *a, int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

int left_quicksort(s_data &data)
{
	int i = data.start_;
	while (i < data.end_ && data.nums_[i] > data.nums_[i+1])
	{
		swap(data.nums_[i], data.nums_[i+1]);
		i++;
	}
	if (i != data.end_)
		quick_sort(data, i + 1, data.end_);
	return (i);
}


//좌측이 먼저 실행되고, 우측이 쌓이는 구조
void right_quicksort(s_data &data)
{
	int i = data.start_;
	while (i < data.end_ && data.nums_[i] > data.nums_[i+1])
	{
		swap(data.nums_[i], data.nums_[i+1]);
		i++;
	}
	if (i != data.end_)
		quick_sort(data, i + 1, data.end_);
	return ;
}

s_data quick_sort(s_data data, int start, int end) // 하노이 탑처럼 함수의 기능을 하나로 고정시키면, quick_sort 함수는 정렬 기능을 가진 것으로 이해.
{
	if (data.size_ == 1)
		return data;
	int pivot;
	data_setting(data, start, end); // 0, 3

	/* 단위 사이클 */
	pivot = left_quicksort(data);
	data_setting(data, pivot, end);
	right_quicksort(data);

	// divid(data, left, right);
	// // ADD함수는 재귀 함수 뒤에 있기 때문에, 아래에 있는 행위들은 모두 나중에 실행됨.
	// ADD(data, left, right);
	return data;
}

int main()
{
	// int nums[24] = {0,3,4,2,1,1,6,4,3,2,6,4,9,5,3,2,6,8,3,5,7,4,3,1};
	// int count = 24;
	// int nums[3] = {3, 2, 0};
	// int count = 3;
	int nums[4] = {3, 2, 1, 0};
	int count = 4;
	// int nums[5] = {3, 2, 6, 4,0};
	// int count = 5;

	s_data data;
	data.nums_ = nums;
	print_nums(data.nums_, count);
	data = quick_sort(data, 0, count - 1);
	print_nums(data.nums_, count);

	return (1);
}
